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



#ifndef _ELISE_GENERAL_USERS_OP_BUF  // general
#define _ELISE_GENERAL_USERS_OP_BUF


//================================================================================
//================================================================================

          //======================================
          //    Simple users unary operators
          //======================================


class   Arg_Comp_Simple_OP_UN
{
        public :

            int dim_in() const { return _dim_in;}
            int sz_buf() const { return _sz_buf;}
            int dim_out()  const { return _dim_out;}

            Arg_Comp_Simple_OP_UN
            (bool integer_fonc,int dim_in,int dim_out,int sz_buf);

        private :
            //const bool      _integer;
            const int        _dim_in;
            const int       _dim_out;
            const int       _sz_buf;

};


                          //======================================

template <class  Type> class Simple_OP_UN : public RC_Object
{
    public :
		// devrait etre 0; Warning Visual 6
        virtual void  calc_buf
                      (
                           Type ** output,
                           Type ** input,
                           int        nb,
                           const Arg_Comp_Simple_OP_UN  &
                      ) ;

         virtual  ~Simple_OP_UN();

         // def :  {return this;};
         virtual  Simple_OP_UN<Type> * 
                  dup_comp(const Arg_Comp_Simple_OP_UN &); 

    protected :
};


Fonc_Num  create_users_oper
          (
              Simple_OP_UN<int> *,
              Simple_OP_UN<double_t> *,
              Fonc_Num,
              int   dim_out
          );



           // some example

Fonc_Num ecart_circ(Fonc_Num f,double_t per = 2*PI);
Fonc_Num grad_bilin(Fonc_Num f,Im2D_U_int1 b);
Fonc_Num its_to_rgb(Fonc_Num f);
Fonc_Num rgb_to_its(Fonc_Num f);
Fonc_Num mpeg_rgb_to_yuv(Fonc_Num f);
Fonc_Num mpeg_yuv_to_rgb(Fonc_Num f);

// see also : Ori3D_Std::photo_et_z_to_terrain


typedef  void  (* Simple_OPUn_I_calc)
               (     int ** out_put,
                     int ** in_put,
                     int,
                     const Arg_Comp_Simple_OP_UN&
                );

typedef  void  (* Simple_OPUn_R_calc)
               (
                      double_t ** out_put,
                      double_t ** in_put,
                      int,
                      const Arg_Comp_Simple_OP_UN&
                );


Fonc_Num  create_users_oper
          (
              Simple_OPUn_I_calc,
              Simple_OPUn_R_calc,
              Fonc_Num,
              int   dim_out
          );

//================================================================================
//================================================================================

          //======================================
          //    Simple users binary operators
          //======================================

class   Arg_Comp_Simple_OP_BIN
{
        public :

            int dim_in1() const { return _dim_in1;}
            int dim_in2() const { return _dim_in2;}
            int dim_out()  const { return _dim_out;}
            int sz_buf() const { return _sz_buf;}

            Arg_Comp_Simple_OP_BIN
            (bool integer_fonc,int dim_in1,int dim_in2,int dim_out,int sz_buf);

        private :
            //const bool    _integer;
            const int     _dim_in1;
            const int     _dim_in2;
            const int     _dim_out;
            const int     _sz_buf;

};



          //======================================


template <class  Type> class Simple_OP_BIN : public RC_Object
{
    public :
		// A REDEFINIR IMPERATIVEMENT
		// devrait etre 0; mais Visual 6 ....
        virtual void  calc_buf
                      (
                           Type ** output,
                           Type ** in1,
                           Type ** in2,
                           int        nb,
                           const Arg_Comp_Simple_OP_BIN  &
                      );

         virtual  ~Simple_OP_BIN();

         // def :  {return this;};
         virtual  Simple_OP_BIN<Type> * 
                  dup_comp(const Arg_Comp_Simple_OP_BIN &); 

    protected :
};


Fonc_Num  create_users_oper
          (
              Simple_OP_BIN<int> *,
              Simple_OP_BIN<double_t> *,
              Fonc_Num f1,
              Fonc_Num f2,
              int   dim_out
          );

           // some example



typedef  void  (* Simple_OPBin_I_calc)
               (     int ** out_put,
                     int ** i1,
                     int ** i2,
                     int,
                     const Arg_Comp_Simple_OP_BIN&
                );

typedef  void  (* Simple_OPBin_R_calc)
               (
                      double_t ** out_put,
                      double_t ** i1,
                      double_t ** i2,
                      int,
                      const Arg_Comp_Simple_OP_BIN&
                );


Fonc_Num  create_users_oper
          (
              Simple_OPBin_I_calc,
              Simple_OPBin_R_calc,
              Fonc_Num,
              Fonc_Num,
              int   dim_out
          );



   //================================================
   // CLASSES FOR SIMPLE USERS BUFFERED FILTERS
   //================================================
/*
class   Arg_Comp_Op_Buf1
{
        public :

            int dim_in() const { return _dim_in;}
            int x0() const { return _x0;}
            int x1() const { return _x1;}
            int dim_out()  const { return _dim_out;}
            Box2di box() const { return _box;}

            Arg_Comp_Op_Buf1
            (
                    bool    integer_fonc,
                    int     dim_in,
                    int     dim_out,
                    int     x0,
                    int     x1,
                    Box2di  box
            );

        private :
            const bool      _integer;
            const int        _dim_in;
            const int       _dim_out;
            const int       _x0;
            const int       _x1;
            Box2di          _box;

};
*/




          //======================================
          //======================================

template <class Tout,class Tin>  class Simple_Buffered_Op_Comp;

class Simple_OPBuf_Gen : public RC_Object
{
    public :

       friend class Simple_Buffered_Op_Comp<int,int>;
       friend class Simple_Buffered_Op_Comp<int,int1>;
       friend class Simple_Buffered_Op_Comp<int,U_int1>;
       friend class Simple_Buffered_Op_Comp<int,U_int2>;
       friend class Simple_Buffered_Op_Comp<double_t,double_t4>;
       friend class Simple_Buffered_Op_Comp<double_t,double_t>;


     //  caracteristique de la fonction :

         int      dim_in() const { return _dim_in;}
         int      dim_out()  const { return _dim_out;}
         bool     integral () const { return _integral;}

     // valeurs evolaunt avec y 

        // valeur liees au y absolu
           int  ycur ()      const  { return _ycur;}
           bool first_line()  const { return _first_line;}

        //  Certain filtres "sophistique", tel que le skel, on besoin
        //  de fonctionner par paquet de lignes afin d'etres efficaces
        // valeur liees au y dans un paquet

            int   y_in_pack ()  const       { return  _y_in_pack;}
            bool first_line_in_pack() const {  return  _y_in_pack == 0;}
            int   nb_pack_y ()  const { return   _nb_pack_y;}


      // rectangle sur lequel est renvoye  le filtre

       int  x0   ()  const   {return _x0;}
       int  x1   ()  const   {return _x1;}
       int  y0   ()  const   {return _y0;}
       int  y1   ()  const   {return _y1;}



       int  tx() { return _x1-_x0;}

     //  taille du voisinage 
       int  dx0 ()  const    {return _dx0;};
       int  dx1 ()  const    {return _dx1;};
       int  dy0 ()  const    {return _dy0;};
       int  dy1 ()  const    {return _dy1;};


    // rectangle sur lequel  la fonction en entree 
    // est definie 

       int  x0Buf ()  const  {return _x0Buf;}   ; // _x0 + _dx0
       int  x1Buf ()  const  {return _x1Buf;}   ; // _x1 + _dx1
       int  y0Buf ()  const  {return _y0Buf;}   ; //  _dy0
       int  y1Buf ()  const  {return _y1Buf;}   ; //  _dy1 +1

       int  SzXBuf ()  const  {return _x1Buf-_x0Buf;}  
       int  SzYBuf ()  const  {return _y1Buf-_y0Buf;}  


    // If you wish value to be clipped out of rectangle of use

       virtual Fonc_Num adapt_box(Fonc_Num f,Box2di);

    private :

       int     _x0;
       int     _x1;
       int     _dx0;
       int     _dx1;
       int     _dy0;
       int     _dy1;

       int     _y0;
       int     _y1;
       int     _ycur;


       int     _x0Buf; // _x0 + _dx0
       int     _x1Buf; // _x1 + _dx1
       int     _y0Buf; //  _dx0
       int     _y1Buf; //  _dy1 +1
       bool    _first_line;

       int     _nb_pack_y;
       int     _y_in_pack;

       int      _dim_in;
       int      _dim_out;
       bool     _integral;


    public :

	   // static const int   DefNbPackY  = 1;
	   //	   static const bool  DefOptNPY   = true;
	   // static const bool  DefCatInit  = false;
	   enum 
	   {
		    DefNbPackY =1,
			DefOptNPY=1,
			DefCatInit=0
	   };

};

template <class  Tout,class Tin> class Simple_OPBuf1 : public Simple_OPBuf_Gen
{
    public :

		// Methode virtuelle pure en toute logique, on lui donne une
		// valeur pour contourner un Warning de Visual 6
       virtual void  calc_buf (Tout ** output,Tin *** input);

       // Necessaire si l'objet doit allouer des ressource temporaire dont la taille depend
       // du rectangle d'application (contexte compile). Par defaut renvoie this, ce qui
       // ne pose pas de pb de desallocation (verifie que l'objet est detruit une seule fois
       // si methode non definie et deux fois sinon, voir ex cOmbrageKL

       virtual Simple_OPBuf1<Tout,Tin> * dup_comp();
       virtual ~Simple_OPBuf1();

      // Well, redundant with args passed to calc, but still pass arg for compatibility

       Tout **   _out;
       Tin  ***  _in;

	// Fait "pointer' une image elise "Normale" (sans DataLin)
	   typedef typename El_CTypeTraits<Tin>::tBase  tBaseIn;
	   
	   void SetImageOnBufEntry(Im2D<Tin,tBaseIn>,Tin**);
	   // Images sans Data lin, faite pour etre mappee par SetImageOnBufEntry :
	   Im2D<Tin,tBaseIn>  AllocImageBufIn(); 


};


template  <class  Tout,class Tin> void Simple_OPBuf1<Tout,Tin>::SetImageOnBufEntry
(
 Im2D<Tin,typename  El_CTypeTraits<Tin>::tBase> anIm,
 Tin**                                         aData
 )
{
    Tin ** aDataIm = anIm.data();
    
    for (int y=0; y<SzYBuf() ; y++)
        aDataIm[y] = aData[y+y0Buf()]+x0Buf();
}



Fonc_Num  create_op_buf_simple_tpl
          (
                 Simple_OPBuf1<int,int> *,
                 Simple_OPBuf1<double_t,double_t> *,
                 Fonc_Num,
                 int                 dim_out,
                 Box2di              side,
                 int                 nb_pack_y =        Simple_OPBuf_Gen::DefNbPackY,
				 bool                OptimizeNbPackY =  Simple_OPBuf_Gen::DefOptNPY,
				 bool                aCatFoncInit =     Simple_OPBuf_Gen::DefCatInit
          );

Fonc_Num  create_op_buf_simple_tpl
          (
                 Simple_OPBuf1<int,U_int1> *,
                 Fonc_Num,
                 int                 dim_out,
                 Box2di              side,
                 int                 nb_pack_y =        Simple_OPBuf_Gen::DefNbPackY,
				 bool                OptimizeNbPackY =  Simple_OPBuf_Gen::DefOptNPY,
				 bool                aCatFoncInit =     Simple_OPBuf_Gen::DefCatInit
          );

Fonc_Num  create_op_buf_simple_tpl
          (
                 Simple_OPBuf1<int,U_int2> *,
                 Fonc_Num,
                 int                 dim_out,
                 Box2di              side,
                 int                 nb_pack_y =        Simple_OPBuf_Gen::DefNbPackY,
				 bool                OptimizeNbPackY =  Simple_OPBuf_Gen::DefOptNPY,
				 bool                aCatFoncInit =     Simple_OPBuf_Gen::DefCatInit
          );

Fonc_Num  create_op_buf_simple_tpl
          (
                 Simple_OPBuf1<int,int1> *,
                 Fonc_Num,
                 int                 dim_out,
                 Box2di              side,
                 int                 nb_pack_y =        Simple_OPBuf_Gen::DefNbPackY,
				 bool                OptimizeNbPackY =  Simple_OPBuf_Gen::DefOptNPY,
				 bool                aCatFoncInit =     Simple_OPBuf_Gen::DefCatInit
          );



Fonc_Num integr_grad (Fonc_Num f,int v_min,Im1D_int4 pond);

Fonc_Num reduc_binaire_gen (Fonc_Num f,bool aRedX,bool aRedY,int aDiv,bool HasValSpec, double_t aValSpec);
Fonc_Num reduc_binaire (Fonc_Num f);
Fonc_Num reduc_binaire_X (Fonc_Num f);
Fonc_Num reduc_binaire_Y (Fonc_Num f);

extern const Pt2di som_masq_Centered;

Fonc_Num som_masq 
         (
            Fonc_Num f,
            Im2D_double_t8 filtr,
            Pt2di dec = som_masq_Centered
          );

Fonc_Num rle_som_masq_binaire  
         (
             Fonc_Num f,
             Im2D_U_int1  filtr,
             double_t val_out,
             Pt2di dec = som_masq_Centered
         );






Fonc_Num label_maj (Fonc_Num label,int vmax,Box2di,Fonc_Num f = 1);
Fonc_Num dilate_label (Fonc_Num label,const Chamfer& chamf,int dmax);

// Permet de definir une fonction qui est egale a f, sauf en
// certain point ou les valeurs sont tabulees dans une liste
// (les deux premier coordonnes sont x et y, les autre la valeur associees)

Fonc_Num fonc_a_trou(Fonc_Num f,Liste_Pts<int,int> l);
Fonc_Num fonc_a_trou(Fonc_Num f,Liste_Pts<U_int2,int> l);
Fonc_Num fonc_a_trou(Fonc_Num f,Liste_Pts<int2,int> l);

// Soit une fonction f de dim 2 en sortie, soient (rho,teta) les valeur
//  renvoie 1 si rho est un maxima dans la dierction de teta 
//  (Typiquement rho et teta sont norme et direction du gradient)
//    
//    OuvAng : indique le cone angulaire sur lequel on exige le maximum
//    Si OrientedMaxLoc = false, on regarde dans les deux direction
//    RhoCalc => donne la distance au pixel pour evaluer les valeur voisines

#define MaxLocDir_Def_OrientedMaxLoc  false
#define MaxLocDir_Def_RhoCalc 1.0

Fonc_Num  MaxLocDir
          (
		          Fonc_Num f,
				  double_t OuvAng,
				  bool OrientedMaxLoc = MaxLocDir_Def_OrientedMaxLoc,
				  double_t RhoCalc =        MaxLocDir_Def_RhoCalc,
				  bool aCatInit =       Simple_OPBuf_Gen::DefCatInit 
		);
Fonc_Num  RMaxLocDir
          (
		          Fonc_Num f,
				  double_t OuvAng,
				  bool OrientedMaxLoc = MaxLocDir_Def_OrientedMaxLoc,
				  double_t RhoCalc =        MaxLocDir_Def_RhoCalc,
				  bool aCatInit =       Simple_OPBuf_Gen::DefCatInit 
		);





typedef  void  (* Simple_OPBuf1_I_calc) 
               (
                    int ** out_put,
                    int *** in_put,
                    const Simple_OPBuf_Gen &
               );

typedef  void  (* Simple_OPBuf1_R_calc)
               (
                    double_t ** out_put,
                    double_t *** in_put,
                    const Simple_OPBuf_Gen &
               );


Fonc_Num  create_op_buf_simple_tpl
          (
              Simple_OPBuf1_I_calc,
              Simple_OPBuf1_R_calc,
              Fonc_Num,
              int                 dim_out,
              Box2di              side,
			  bool                aCatFoncInit =     Simple_OPBuf_Gen::DefCatInit
          );


    // Changement d'echelle, une utilisation hors norme
    // des op-buf , Defaut -> Bicubique
    //  ISCAL[XY] = IOri[Direct(XY)]
    // double Direct(double aV)   const { return  aV*mSc + mTr; }
    // aPixIn = aHom.Direct(mPixOut)

    //  double Inverse(double aV)  const { return  (aV-mTr)/mSc ; }

Fonc_Num  StdFoncChScale(Fonc_Num aFonc,Pt2dr aTr,Pt2dr aSc,Pt2dr aDilate=Pt2dr(1,1));
Fonc_Num  StdFoncChScale_Bilin(Fonc_Num aFonc,Pt2dr aTr,Pt2dr aSc,Pt2dr aDilate=Pt2dr(1,1));

           // some derivative

Fonc_Num cdn(Fonc_Num f);

Fonc_Num Laplacien(Fonc_Num f);
Fonc_Num bobs_grad(Fonc_Num f);
Fonc_Num courb_tgt(Fonc_Num f);
Fonc_Num grad_crois(Fonc_Num f);
Fonc_Num sec_deriv(Fonc_Num f);
Fonc_Num flag_pente_crete(Fonc_Num f);
Fonc_Num filtre_pente_crete(Fonc_Num f);
Fonc_Num red_flag_som(Fonc_Num Fvals,Fonc_Num Fflags);
Fonc_Num Harris(Fonc_Num f,double aExp,double aSeuil);



#endif  /* !_ELISE_GENERAL_USERS_OP_BUF */







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
