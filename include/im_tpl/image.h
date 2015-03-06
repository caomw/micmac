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

#ifndef _ELISE_IM_TPL_IMAGE
#define _ELISE_IM_TPL_IMAGE

class TFlux_Pts {};
class TFonc_Num {};
class TOuput {};

class   GTIm2D : public cFoncI2D
{
     public :

             virtual ~GTIm2D() {}

	     int X0() {return _x0;}
	     int Y0() {return _y0;}
          bool inside_rab(const Pt2dr & p,int RAB) const
          {
                return
                         (p.x >=(_x0+RAB))
                    &&   (p.y >=(_y0+RAB))
                    &&   (p.x < (_tx-1-RAB))
                    &&   (p.y < (_ty-1-RAB));
          }
          bool inside_bilin(const Pt2di & p) const
          {
                return
                         (p.x >=_x0)
                    &&   (p.y >=_y0)
                    &&   (p.x < (_tx-1))
                    &&   (p.y < (_ty-1));
          }

          bool Rinside_bilin(const Pt2dr & p) const
          {
               return inside_bilin(round_down(p));
          }

          bool inside_bicub(const Pt2di & p) const
          {
                return
                         (p.x >=_x0+1)
                    &&   (p.y >=_y0+1)
                    &&   (p.x < (_tx-2))
                    &&   (p.y < (_ty-2));
          }


          bool inside_bilin(const int & anX,const int & anY) const
          {
                return
                         (anX >=_x0)
                    &&   (anY >=_y0)
                    &&   (anX < (_tx-1))
                    &&   (anY < (_ty-1));
          }

          bool inside(const Pt2di & p) const
          {
                return
                         (p.x >=_x0)
                    &&   (p.y >=_y0)
                    &&   (p.x < _tx)
                    &&   (p.y < _ty);
          }

#if (ELISE_ACTIVE_ASSERT)
          void assert_inside(const Pt2di & p) const
          {
               ELISE_ASSERT(inside(p),"TIm2D pts out");
          }
          void assert_inside_bilin(const Pt2di & p) const
          {
               ELISE_ASSERT(inside(p),"TIm2D pts out");
          }
#else
          void assert_inside(const Pt2di & ) const {}
          void assert_inside_bilin(const Pt2di & ) const {}
#endif

          TFlux_Rect2d  all_pts() { return TFlux_Rect2d(Pt2di(0,0),Pt2di(_tx,_ty));}
          Pt2di sz()const {return Pt2di(_tx,_ty);}
          Pt2di p0()const {return Pt2di(_x0,_y0);}
		  int tx() {return _tx;}
		  int ty() {return _ty;}


         Box2di BoxDef() const { return Box2di(p0(),p0()+sz()); }
     protected :

          GTIm2D(int tx,int ty,int x0=0,int y0=0) :
              _tx     (tx),
              _ty     (ty),
              _x0     (x0),
              _y0     (y0)
          {
          }

          int                        _tx;
          int                        _ty;
          int                        _x0;
          int                        _y0;
};

template  <class Type,class Type_Base> class  TIm2D : public GTIm2D 
{
     protected :
     public :
         void Resize(const Pt2di & aP)  
         {
              _the_im.Resize(aP);
              _tx = aP.x;
              _ty = aP.y;
              _d = _the_im.data();
         }

         typedef TIm2D<Type,Type_Base>  tTheType;

         double Val(const int & x,const int & y) const { return _d[y][x]; }


          std::string  NameType() {return El_CTypeTraits<Type>::Name();}

          Im2D<Type,Type_Base>    _the_im;
          Type **                     _d;

		  typedef Type tValueElem;
		  Type * adr_data(Pt2di p) {return _d[p.y]+p.x;}

          Type  VMax()
          {
             Type aRes = _d[0][0];
             for (int aY=0; aY<_ty ; aY++)
                 for (int aX=0; aX<_tx ; aX++)
                     ElSetMax(aRes,_d[aY][aX]);
             return aRes;
          }
     public :

          typedef  Type_Base   OutputFonc;
          typedef  Type_Base   ValOut;

          inline double_t getr( const cCubicInterpKernel & aKer,
                            const Pt2dr &  aPt,
                            const Type_Base & aDef,
                            const bool & svp) const
          {
                if (!inside_bicub(round_down(aPt)))
                {
                   if (svp) return aDef;
                   ELISE_ASSERT(false,"TIm2D pts out");
                }
                return BicubicInterpolVal(aKer,_d,aPt);
          }
          inline double_t getr( const cCubicInterpKernel & aKer,
                            const Pt2dr & aPt,
                            const Type_Base & aDef) const
          {
              return getr(aKer,aPt,aDef,true);
          }
          inline double_t getr( const cCubicInterpKernel & aKer,
                            const Pt2dr & aPt) const
          {
              return getr(aKer,aPt,0,false);
          }

	  inline double_t getr(Pt2dr aPt,Type_Base aDef,bool svp) const
	  {
		int xo   = (int) aPt.x ;
		int yo   = (int) aPt.y ;
                if (!inside_bilin(Pt2di(xo,yo)))
                {
                   if (svp) return aDef;
                   ELISE_ASSERT(false,"TIm2D pts out");
                }
		double_t  px1 = aPt.x - xo;
		double_t  py1 = aPt.y - yo;
		double_t  px0 =  1.0 -px1;
		double_t  py0 =  1.0 -py1;
		Type * l0 = _d[yo]+xo;
		Type * l1 = _d[yo+1]+xo;

		return
                (
                    px0 * py0 * l0[0]
                  + px1 * py0 * l0[1]
                  + px0 * py1 * l1[0]
                  + px1 * py1 * l1[1]
                );
	  }

	  inline Pt3dr getVandDer(Pt2dr aPt) const
	  {
		int xo   = (int) aPt.x ;
		int yo   = (int) aPt.y ;
                ELISE_ASSERT(inside_bilin(Pt2di(xo,yo)),"TIm2D pts out");
		double_t  px1 = aPt.x - xo;
		double_t  py1 = aPt.y - yo;
		double_t  px0 =  1.0 -px1;
		double_t  py0 =  1.0 -py1;
		Type * l0 = _d[yo]+xo;
		Type * l1 = _d[yo+1]+xo;

		return
                Pt3dr
                (
                     py0 * (l0[1]-l0[0])
                  +  py1 * (l1[1]-l1[0]),

                     px0 * (l1[0]-l0[0])
                  +  px1 * (l1[1]-l0[1]),

                     px0 * py0 * l0[0]
                  +  px1 * py0 * l0[1]
                  +  px0 * py1 * l1[0]
                  +  px1 * py1 * l1[1]
                );
	  }



	  inline double_t getr(Pt2dr aPt) const
          {
                return getr(aPt,Type_Base(0),false);
          }
	  inline double_t getr(Pt2dr aPt,Type_Base aDef) const
          {
                return getr(aPt,aDef,true);
          }
/*   NON TESTEES , A Bencher avant usage

	  inline double_t DerX(Pt2dr aPt)
          {
		int xo   = (int) pt._x ;
		int yo   = (int) pt._y ;
                assert_inside_bilin(Pt2di(xo,yo));
		double_t  py1 = pt._y - yo
		double_t  py0 =  1.0 -py1;

		Type * l0 = im._d[yo]+xo;
		Type * l1 = im._d[yo+1]+xo;

		return
                (
                     py0 * (l0[1]-l0[0])
                  +  py1 * (l1[1]-l1[0])
                );
          }
*/


	  inline Type_Base get(const Pt2di & p)  const
          {
                assert_inside(p);
                return _d[p.y][p.x];
          }
	  inline Type_Base getOk(const Pt2di & p)  const
          {
                return _d[p.y][p.x];
          }


	  inline Type_Base get(const Pt2di & p,Type_Base def)  const
          {
                return    inside(p)      ?
                          _d[p.y][p.x]   :
                          def            ;
          }

	  inline Type   getproj(const Pt2di & p)  const
          {
                return _d[ElMax(0,ElMin(_ty-1,p.y))][ElMax(0,ElMin(_tx-1,p.x))];
          }
	  inline Type & getproj(const Pt2di & p)
          {
                return _d[ElMax(0,ElMin(_ty-1,p.y))][ElMax(0,ElMin(_tx-1,p.x))];
          }


	  double_t  getprojR(Pt2dr aPt) const
	  {
		int xo   = (int) aPt.x ;
		int yo   = (int) aPt.y ;

		double_t  px1 = aPt.x - xo;
		double_t  py1 = aPt.y - yo;
		double_t  px0 =  1.0 -px1;
		double_t  py0 =  1.0 -py1;

		return   getproj(Pt2di(xo  ,yo  )) *  px0 * py0
		       + getproj(Pt2di(xo+1,yo  )) *  px1 * py0
		       + getproj(Pt2di(xo  ,yo+1)) *  px0 * py1
		       + getproj(Pt2di(xo+1,yo+1)) *  px1 * py1 ;
	  }

	  void  incr(Pt2di aPt,double_t aPds)
	  {
		getproj(aPt) += (Type)aPds;
	  }


	  void  incr(Pt2dr aPt,double_t aPds)
	  {
		int xo   = (int) aPt.x ;
		int yo   = (int) aPt.y ;

		double_t  px1 = aPt.x - xo;
		double_t  py1 = aPt.y - yo;
		double_t  px0 =  1.0 -px1;
		double_t  py0 =  1.0 -py1;

		getproj(Pt2di(xo  ,yo  )) += (Type)( px0 * py0  *aPds );
		getproj(Pt2di(xo+1,yo  )) += (Type)( px1 * py0 * aPds );
		getproj(Pt2di(xo  ,yo+1)) += (Type)( px0 * py1 * aPds );
		getproj(Pt2di(xo+1,yo+1)) += (Type)( px1 * py1 * aPds );
	  }




          // oset (et non set) car (bug STL ?) ce fait un clache avec
          // les set de la STL (internal compiler error sur certaine
          // version g++)
	  inline void  oset(const Pt2di & p ,Type_Base val)
          {
                 assert_inside(p);
                _d[p.y][p.x] = (Type) val;
          }
	  inline void  oset_svp(const Pt2di & p ,Type_Base val)
          {
                 if(inside(p))
                    _d[p.y][p.x] = (Type) val;
          }

	  inline void  add(const Pt2di & p ,Type_Base val)
          {
                 assert_inside(p);
                _d[p.y][p.x] += (Type) val;
          }

	  inline void  div(const Pt2di & p ,Type_Base val)
          {
                 assert_inside(p);
                _d[p.y][p.x] /= (Type) val;
          }



          TIm2D(Im2D<Type,Type_Base> TheIm) :
              GTIm2D  (TheIm.tx(),TheIm.ty()),
              _the_im (TheIm),
              _d      (TheIm.data())
          {
          }

          TIm2D(Pt2di aSz) :
              GTIm2D  (aSz.x,aSz.y),
              _the_im (aSz.x,aSz.y),
              _d      (_the_im.data())
          {
          }





		  TIm2D(Type ** Data,Pt2di P0,Pt2di P1) :
				  GTIm2D(P1.x,P1.y,P0.x,P0.y),
				  _the_im (1,1),
		                  _d    (Data)
		  {
		  }
	      void SetData(Type ** Data) { _d =Data;}

          void algo_dist_env_Klisp32_Sup();
          void algo_dist_env_Klisp_Sup(int aD4,int aD8);
          void algo_dist_32_neg();
          void algo_dist_32_neg(Pt2di p0,Pt2di p1);

          void border_algo_dist_32_neg();
          void border_algo_dist_32_neg(Pt2di p0,Pt2di p1);

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
                return    this->inside(p)      ?
                          this->_d[p.y][p.x]   :
                          _def           ;
          }

	  inline void  oset(const Pt2di & p ,Type_Base val)
          {
                 if (this->inside(p)) this->_d[p.y][p.x] = (Type) val;
          }
};


template  <const int NBB> class  TIm2DBits : public GTIm2D
{

          enum
          {
              nb_per_byte = Tabul_Bits<NBB,true>::nb_per_byte
          };
          U_int1 **                   _d;


     public :
          Im2D_Bits<NBB>              _the_im;

          virtual ~TIm2DBits(){};

          typedef  int  OutputFonc;
          typedef  int  ValOut;
          double Val(const int & x,const int & y) const { return getOK(Pt2di(x,y)); }

	  int  getOK(const Pt2di & p) const
          {
                return Tabul_Bits<NBB,true>::input_tab
		         [_d[p.y][p.x/nb_per_byte]] [p.x%nb_per_byte] ;
          }
	  int  get(const Pt2di & p,int aVDef)  const
          {
                return    inside(p)      ?
                          getOK(p)       :
                          aVDef;
          }

	  int  get(const Pt2di & p)  const
          {
                assert_inside(p);
                return getOK(p);
          }

	  void  oset(const Pt2di & p ,int  v)
          {
                assert_inside(p);
                _d[p.y][p.x/nb_per_byte] =
                        Tabul_Bits<NBB,true>::out_tab[_d[p.y][p.x/nb_per_byte]][v][p.x%nb_per_byte];
          }

	  void  oset_svp(const Pt2di & p ,int  v)
          {
                if (inside(p))
                   _d[p.y][p.x/nb_per_byte] =
                        Tabul_Bits<NBB,true>::out_tab[_d[p.y][p.x/nb_per_byte]][v][p.x%nb_per_byte];
          }



          TIm2DBits(Im2D_Bits<NBB>  TheIm) :
              GTIm2D  (TheIm.tx(),TheIm.ty()),
              _d      (TheIm.data()),
              _the_im (TheIm)
          {
          }
          Im2D_Bits<NBB> Im() const {return _the_im;}


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

        // Get grad+val
        static Pt3d<int> geti_gv(TIm2D<Type,Type_Base> & im,const ElPFixed<b> & pt)
        {
                int xo   = pt._x >> b;
                int yo   = pt._y >> b;
                int  px1 = pt._x - (xo<<b);
                int  py1 = pt._y - (yo<<b);
                int  px0 =  pt.Q -px1;
                int  py0 =  pt.Q -py1;
                Type * l0 = im._d[yo]+xo;
                Type * l1 = im._d[yo+1]+xo;

		int vP0Y00 =  py0 * l0[0];
		int vP0Y01 =  py0 * l0[1];
		int vP1Y10 = py1 * l1[0];
		int vP1Y11 = py1 * l1[1];
                return Pt3d<int>
                       (
			    (vP0Y01-vP0Y00+vP1Y11-vP1Y10) >> b,
                            (px0*(l1[0]-l0[0])+px1*(l1[1]-l0[1])) >> b ,
                            (
                                px0 * (vP0Y00+vP1Y10)
                              + px1 * (vP0Y01+vP1Y11)
                            )  >> ElPFixed<b>::b2
                       );
       }

	static Type_Base IptGet(TIm2D<Type,Type_Base> & im,const ElPFixed<b> & pt)
        {
             return im._d[pt._y>>b][pt._x>>b];
        }

	static Type_Base IptGet
               (TIm2D<Type,Type_Base> & im,const ElPFixed<b> & pt,Type_Base aDef)
        {
             return im.get(Pt2di(pt._x>>b,pt._y>>b),aDef);
        }


	static Type_Base getb2(TIm2D<Type,Type_Base> & im,const ElPFixed<b> & pt)
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


        static bool inside_bilin(TIm2D<Type,Type_Base> & im,const ElPFixed<b> & pt)
        {
            return im.inside_bilin(Pt2di(pt._x >> b,pt._y >> b));
        }

        static bool inside_bicub(TIm2D<Type,Type_Base> & im,const ElPFixed<b> & pt)
        {
            return im.inside_bicub(Pt2di(pt._x >> b,pt._y >> b));
        }

	static Type_Base getb2(TIm2D<Type,Type_Base> & im,ElPFixed<b> pt,Type_Base def)
	{
		int xo   = pt._x >> b;
		int yo   = pt._y >> b;
		if (! im.inside_bilin(Pt2di(xo,yo)))
                {
		   return def * pt.Q2;
                }

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

	static double_t getr(TIm2D<Type,Type_Base> & im,ElPFixed<b> pt,double_t def)
	{
            return getb2(im,pt,(int)(def* (double_t) pt.Q2)) / (double_t) pt.Q2;
	}
	static int geti(TIm2D<Type,Type_Base> & im,ElPFixed<b> pt,Type_Base def)
	{
            return getb2(im,pt,def) >>  ElPFixed<b>::b2;
	}


	static Type_Base SpecGetForCor
               (
                    TIm2D<Type,Type_Base> & im,
                    TIm2D<Type,Type_Base> & imOk,
                    const ElPFixed<b>  &    pt,
                    int &                   Ok
                )
	{
		int xo   = pt._x >> b;
		int yo   = pt._y >> b;
		if (! im.inside_bilin(xo,yo))
                {
                   Ok = 0;
		   return 0;
                }
                Ok =  imOk._d[yo][xo];

		int  px1 = pt._x - (xo<<b);
		int  py1 = pt._y - (yo<<b);
		int  px0 =  pt.Q -px1;
		int  py0 =  pt.Q -py1;
		Type * l0 = im._d[yo]+xo;
		Type * l1 = im._d[yo+1]+xo;

		return
                (
                       px0 * (py0 * l0[0] +  py1 * l1[0])
                     + px1 * (py0 * l0[1] +  py1 * l1[1])
                ) >> ElPFixed<b>::b2;
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
#if ELISE_windows
	typedef void * ( __cdecl* tyMemCopy)  (void *, const void *, size_t);
#else
	typedef void * (* tyMemCopy) (void *, const void *, size_t);
#endif
};

template <class Type>  void AutoTranslateData(Pt2di tr,Type & Obj)
{


    if ((tr.x==0) && (tr.y==0))
       return;

    //tyMemCopy MCP = (tr.y==0) ? memmove : memcpy;

	tyMemCopy MCP = memmove;
	if (tr.y!=0)
		MCP = memcpy;

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
            MCP(id0,is0,(is1-is0)*sizeof(typename Type::tValueElem));
        }
    }
    else
    {
        for (int y=0; y<szy; y++)
        {
            typename Type::tValueElem * is0 = Obj.adr_data(Pt2di(sx,sy+y));
            typename Type::tValueElem * is1 = Obj.adr_data(Pt2di(sx+szx,sy+y));
            typename Type::tValueElem * id0 = Obj.adr_data(Pt2di(dx,y+dy));
            MCP(id0,is0,(is1-is0)*sizeof(typename Type::tValueElem));
        }
    }
}



#endif  //  _ELISE_IM_TPL_IMAGE











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
