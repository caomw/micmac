/*Header-MicMac-eLiSe-25/06/2007

    MicMac : Multi Image Correspondances par Methodes Automatiques de Correlation
    eLiSe  : ELements of an Image Software Environnement

    www.micmac.ign.fr

   
    Copyright : Institut Geographique National
    Author : Marc Pierrot Deseilligny
    Contributors : Gregoire Maillet, Didier Boldo.

[1] M. Pierrot-Deseilligny, N. Paparoditis.
    "A multiresolution and optimization-based image matching approach:
    An application to surface reconstruction from SPOT5-HRS stereo imagery."
    In IAPRS vol XXXVI-1/W41 in ISPRS Workshop On Topographic Mapping From Space
    (With Special Emphasis on Small Satellites), Ankara, Turquie, 02-2006.

[2] M. Pierrot-Deseilligny, "MicMac, un lociel de mise en correspondance
    d'images, adapte au contexte geograhique" to appears in 
    Bulletin d'information de l'Institut Geographique National, 2007.

Francais :

   MicMac est un logiciel de mise en correspondance d'image adapte 
   au contexte de recherche en information geographique. Il s'appuie sur
   la bibliotheque de manipulation d'image eLiSe. Il est distibue sous la
   licences Cecill-B.  Voir en bas de fichier et  http://www.cecill.info.


English :

    MicMac is an open source software specialized in image matching
    for research in geographic information. MicMac is built on the
    eLiSe image library. MicMac is governed by the  "Cecill-B licence".
    See below and http://www.cecill.info.

Header-MicMac-eLiSe-25/06/2007*/


/*
    POUR MEMO : 
class   GTIm2D
{
     public :

          bool inside_bilin(const Pt2di & p);
          bool inside(const Pt2di & p);

          void assert_inside(const Pt2di & );
     protected :

          GTIm2D(int tx,int ty,int x0=0,int y0=0) ;
};
*/


#ifndef _ELISE_IM_TPL_GRAPHE_PIXEL
#define _ELISE_IM_TPL_GRAPHE_PIXEL

/*
    Pre-requis  pour etre un graphe de pixel

       - heriter publiquement  de GenTGrapheIm2D (de maniere directe ou indirecte);

       - definir les methode 
 
                 * som_in_graphe(const Pt2di & p);
                 * arc_in_graphe_ifs1in(const Pt2di & p,int k);
                 * arc_in_graphe(const Pt2di & p,int k); // doit etre equivalent a && des deux preced, 
                                                         // peut etre une optim de cela

       TGrapheSetIm2D correspond a un graphe pour lequel un sommet est dans le graphe
*/


class  GenTGrapheIm2D : public  GTIm2D
{
     protected :

          GenTGrapheIm2D(int tx,int ty,int x0=0,int y0=0)  : GTIm2D(tx,ty,x0,y0) {}
      
};


template  <class Type> class  TGrapheSetIm2D : public GenTGrapheIm2D
{
     private :

	  typedef Type                                  tValueElem;
	  typedef typename El_CTypeTraits<Type>::tBase  tBaseElem;


          TIm2D<tValueElem,tBaseElem> mIm;

     public :

          
          TGrapheIm2D (m2D<tValueElem,tBaseElem>); 

	  inline bool som_in_graphe(const Pt2di & p) 
          {
                return (mIm.get(p)!=0);
          }

          inline bool arc_in_graphe_ifs1in(const Pt2di & p,int k)
          {
                return som_in_graphe(p+TAB_8_NEIGH[k]);
          }

         
};


template  <class Type,class Type_Base> class  SafeTIm2D : public TIm2D<Type,Type_Base>
{
     private :
          Type_Base _def;
     public :

          SafeTIm2D(Im2D<Type,Type_Base> TheIm,Type_Base def = 0) :
              TIm2D<Type,Type_Base>(TheIm),
              _def(def)
          {}

	  inline Type_Base get(const Pt2di & p) 
          {
                return    inside(p)      ?
                          _d[p.y][p.x]   :
                          _def           ;
          }

	  inline void  oset(const Pt2di & p ,Type_Base val) 
          {
                 if (inside(p)) _d[p.y][p.x] = (Type) val;
          }
};


template  <const int NBB> class  TIm2DBits : public GTIm2D
{

          enum
          {
              nb_per_byte = Tabul_Bits<NBB,true>::nb_per_byte
          };
          U_int1 **                   _d;
          Im2D_Bits<NBB>              _the_im;


     public :


          typedef  int  OutputFonc;
          typedef  int  ValOut;
          
	  int  get(const Pt2di & p) 
          {
                assert_inside(p);
                return Tabul_Bits<NBB,true>::input_tab[_d[p.y][p.x/nb_per_byte]][p.x%nb_per_byte];
          }

	  void  oset(const Pt2di & p ,int  v) 
          {
                assert_inside(p);
                _d[p.y][p.x/nb_per_byte] = 
                        Tabul_Bits<NBB,true>::out_tab[_d[p.y][p.x/nb_per_byte]][v][p.x%nb_per_byte];
          }


          TIm2DBits(Im2D_Bits<NBB>  TheIm) :
              GTIm2D  (TheIm.tx(),TheIm.ty()),
              _d      (TheIm.data()),
              _the_im (TheIm)
          {
          }

         
     private :

};



template <class TypeFlx,class TypeFonc,class TypeOut>  
         void TElCopy(TypeFlx flx,TypeFonc fonc,TypeOut out)
{
     TypeFlx::OutFlux pt = flx.PtsInit();
    while(flx.next(pt))
         out.oset(pt,fonc.get(pt));
}

template <class Im1,class Im2>  void Tdup(Im1 im1,Im2 im2)
{
    Pt2di sz =  Inf(im1.sz(),im2.sz());
    for(int y =0; y<sz.y ; y++)
        for(int x =0; x<sz.x ; x++)
            im1.oset(Pt2di(x,y),im2.get(Pt2di(x,y)));
}



template <class Type,class Type_Base,const int b> class TImGet
{
	public :

	static Type_Base getb2(TIm2D<Type,Type_Base> & im,ElPFixed<b> pt)
	{
		int xo   = pt._x >> b;
		int yo   = pt._y >> b;
		int  px1 = pt._x - (xo<<b);
		int  py1 = pt._y - (yo<<b);
		int  px0 =  pt.Q -px1;
		int  py0 =  pt.Q -py1;
		Type * l0 = im._d[yo]+xo;
		Type * l1 = im._d[yo+1]+xo;

		return  
             (
                 px0 * py0 * l0[0]
               + px1 * py0 * l0[1]
               + px0 * py1 * l1[0]
               + px1 * py1 * l1[1]
             );
	}

	static double_t getr(TIm2D<Type,Type_Base> & im,ElPFixed<b> pt)
	{
       return getb2(im,pt) / (double_t) pt.Q2;
	}
	static int geti(TIm2D<Type,Type_Base> & im,ElPFixed<b> pt)
	{
       return getb2(im,pt) >>  ElPFixed<b>::b2;
	}

	static Type_Base getb2(TIm2D<Type,Type_Base> & im,ElPFixed<b> pt,Type_Base def)
	{
		int xo   = pt._x >> b;
		int yo   = pt._y >> b;
		if (! im.inside_bilin(Pt2di(xo,yo)))
		   return def;

		int  px1 = pt._x - (xo<<b);
		int  py1 = pt._y - (yo<<b);
		int  px0 =  pt.Q -px1;
		int  py0 =  pt.Q -py1;
		Type * l0 = im._d[yo]+xo;
		Type * l1 = im._d[yo+1]+xo;

		return  
             (
                 px0 * py0 * l0[0]
               + px1 * py0 * l0[1]
               + px0 * py1 * l1[0]
               + px1 * py1 * l1[1]
             );
	}

	static double_t getr(TIm2D<Type,Type_Base> & im,ElPFixed<b> pt,Type_Base def)
	{
       return getb2(im,pt,def) / (double_t) pt.Q2;
	}
	static int geti(TIm2D<Type,Type_Base> & im,ElPFixed<b> pt,Type_Base def)
	{
       return getb2(im,pt,def) >>  ElPFixed<b>::b2;
	}

};


/*
template <class Type,class Type_Base,const int b> 
         int getb2(TIm2D<Type,Type_Base> & im,ElPFixed<b> pt)
{
	return TImGet<Type,Type_Base,b>::getb2(im,pt);
}
*/
template <class Type,class Type_Base,class PFixed>
         int getb2(TIm2D<Type,Type_Base> & im,PFixed pt)
{
	return TImGet<Type,Type_Base,PFixed::b1>::getb2(im,pt);
}



/*

template <class Type,class Type_Base,const int b> 
         int getb2(TIm2D<Type,Type_Base> & im,ElPFixed<b> pt)
{
      int xo   = pt._x >> b;
      int yo   = pt._y >> b;
      int  px1 = pt._x - (xo<<b);
      int  py1 = pt._y - (yo<<b);
      int  px0 =  pt.Q -px1;
      int  py0 =  pt.Q -py1;
      Type * l0 = im._d[yo]+xo;
      Type * l1 = im._d[yo+1]+xo;

      return  
             (
                 px0 * py0 * l0[0]
               + px1 * py0 * l0[1]
               + px0 * py1 * l1[0]
               + px1 * py1 * l1[1]
             );
}

template <class Type,class Type_Base,const int b> 
         int geti(TIm2D<Type,Type_Base> & im,ElPFixed<b> pt)
{
     return getb2(im,pt) >> pt.b2;
}

template <class Type,class Type_Base,const int b> 
         double_t getr(TIm2D<Type,Type_Base> & im,ElPFixed<b> pt)
{
     return getb2(im,pt) / (double_t) pt.Q2;
}
*/

template <class Type,class Type_Base,class PFixed>
         int geti(TIm2D<Type,Type_Base> & im,PFixed pt)
{
     return getb2(im,pt) >> PFixed::b2;
}

template <class Type,class Type_Base,class PFixed>
         double_t getr(TIm2D<Type,Type_Base> & im,PFixed pt)
{
     return getb2(im,pt) / (double_t) PFixed::Q2;
}

// Calcul rapide mais approches (nombre fixed sur 8 bits)
template <class Type,class TypeBase> double_t FixedSomSegDr(TIm2D<Type,TypeBase>& Tim,Pt2dr p1,Pt2dr p2,int NBPts,double_t DefOut); 


/*
    Requirement :
      int Obj.tx()
      int Obj.ty()
      typedef CharIntDouble  tValueElem;
      tValueElem  Obj.adr_data(Pt2di)
*/
extern "C"
{
     typedef void * (* tyMemCopy) (void *, const void *, size_t);
};
                       
template <class Type>  void AutoTranslateData(Pt2di tr,Type & Obj)
{
 
 
    if ((tr.x==0) && (tr.y==0))
       return;
 
    tyMemCopy MCP = (tr.y==0) ? memmove : memcpy;
 
    int sx =ElMax(-tr.x,0);
    int sy =ElMax(-tr.y,0);
    int dx =ElMax(tr.x,0);
    int dy =ElMax(tr.y,0);
 
    int szx = Obj.tx()-ElAbs(tr.x);
    int szy = Obj.ty()-ElAbs(tr.y);
 
    if ((szx<=0) || (szy <=0))
       return;
 
    if ((tr.y>0) || ((tr.y==0) && (tr.x >0)))
    {
        for (int y=szy-1; y>=0; y--)
        {
            typename Type::tValueElem * is0 = Obj.adr_data(Pt2di(sx,sy+y));
            typename Type::tValueElem * is1 = Obj.adr_data(Pt2di(sx+szx,sy+y));
            typename Type::tValueElem * id0 = Obj.adr_data(Pt2di(dx,y+dy));
            MCP(id0,is0,(is1-is0)*sizeof(Type::tValueElem));
        }
    }
    else
    {
        for (int y=0; y<szy; y++)
        {
            typename Type::tValueElem * is0 = Obj.adr_data(Pt2di(sx,sy+y));
            typename Type::tValueElem * is1 = Obj.adr_data(Pt2di(sx+szx,sy+y));
            typename Type::tValueElem * id0 = Obj.adr_data(Pt2di(dx,y+dy));
            MCP(id0,is0,(is1-is0)*sizeof(Type::tValueElem));
        }
    }
}
 
                              

#endif  //  _ELISE_IM_TPL_GRAPHE_PIXEL











/*Footer-MicMac-eLiSe-25/06/2007

Ce logiciel est un programme informatique servant à la mise en
correspondances d'images pour la reconstruction du relief.

Ce logiciel est régi par la licence CeCILL-B soumise au droit français et
respectant les principes de diffusion des logiciels libres. Vous pouvez
utiliser, modifier et/ou redistribuer ce programme sous les conditions
de la licence CeCILL-B telle que diffusée par le CEA, le CNRS et l'INRIA 
sur le site "http://www.cecill.info".

En contrepartie de l'accessibilité au code source et des droits de copie,
de modification et de redistribution accordés par cette licence, il n'est
offert aux utilisateurs qu'une garantie limitée.  Pour les mêmes raisons,
seule une responsabilité restreinte pèse sur l'auteur du programme,  le
titulaire des droits patrimoniaux et les concédants successifs.

A cet égard  l'attention de l'utilisateur est attirée sur les risques
associés au chargement,  à l'utilisation,  à la modification et/ou au
développement et à la reproduction du logiciel par l'utilisateur étant 
donné sa spécificité de logiciel libre, qui peut le rendre complexe à 
manipuler et qui le réserve donc à des développeurs et des professionnels
avertis possédant  des  connaissances  informatiques approfondies.  Les
utilisateurs sont donc invités à charger  et  tester  l'adéquation  du
logiciel à leurs besoins dans des conditions permettant d'assurer la
sécurité de leurs systèmes et ou de leurs données et, plus généralement, 
à l'utiliser et l'exploiter dans les mêmes conditions de sécurité. 

Le fait que vous puissiez accéder à cet en-tête signifie que vous avez 
pris connaissance de la licence CeCILL-B, et que vous en avez accepté les
termes.
Footer-MicMac-eLiSe-25/06/2007*/
