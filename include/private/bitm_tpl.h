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

#ifndef __BITM_TPL__
#define __BITM_TPL__

template <class Type,class TyBase>  class DataGenImType :
           public DataGenIm
{
   public :
      virtual void  *  data_lin_gen();
      DataGenImType(int sz_tot,bool to_init,TyBase v_init,const char * =0);
      void Initializer(int sz_tot,bool to_init,TyBase v_init,const char * =0);
      virtual void  out_rle(void *,int,const int*,int offs_0) const;
      virtual void  out_rle(void *,int,const double_t*,int offs_0) const;
      virtual void  out_rle(void *,int,const double_t16*,int offs_0) const;

      virtual void  input_rle(void *,int,const void*,int offs_0) const;
      virtual void  striped_input_rle(void *,int nb,int dim,const void*,int offs_0) const;
      virtual void  striped_output_rle(void *,int nb,int dim,const void*,int offs_0) const;
      virtual bool integral_type() const;


      void raz();

//      void lut_uc(Im1D<Type,TyBase>);
// modif DB
      bool       _to_free;
      int         _sz_tot;
      int         mSzMemory;  // est >=  a _sz_tot
      Type *      _data_lin; // for afficionados of manipulations
                             // like _data_lin[x+y*_tx] 
      virtual int sz_el() const;
      virtual int sz_base_el() const;
      virtual int sz_tot() const;


      // max and min integral values of the type: the convention
      // v_max == v_min is used when these values are useless:
      static const int v_min;
      static const int v_max;
      static GenIm::type_el     type_el_bitm;



      virtual GenIm::type_el type() const;
      virtual int vmax() const;
      virtual int vmin() const;

      static const bool  _integral_type;
      protected :
          virtual ~DataGenImType();
          void Resize(int tTot);
          void Desinitializer();
};


class DataIm2DGen
{
   public :

      int tx() const { return _txy[0];};
      int ty() const { return _txy[1];};

   protected :
      void Initializer(int aTx,int aTy);
      int           _txy[2];
	  int           mTx;
	  int           mTy;
          int           mTyMem;
      DataIm2DGen(int tx,int ty);
};


template <class Type,class TyBase> class DataIm2D : 
             public  DataGenImType<Type,TyBase> ,
             public  DataIm2DGen
{
    public :


      double Get(const Pt2dr & aP ,const cInterpolateurIm2D<Type> &,double aDef);

      virtual void out_pts_integer(Const_int_PP coord,int nb,const void *) ;
      virtual void input_pts_integer(void *,Const_int_PP coord,int nb) const;
      virtual void input_pts_reel(double_t *,Const_double_t_PP coord,int nb) const;

      virtual void  *   calc_adr_seg(int *);
      virtual ~DataIm2D();
	  void raz(Pt2di p0,Pt2di p1);

      Type **  data() const; 
      Type *  data_lin() const; 

      double_t  som_rect(Pt2dr p0,Pt2dr p1,double_t def =0.0) const;
      double_t  moy_rect(Pt2dr p0,Pt2dr p1,double_t def =0.0) const;          
	  void set_brd(Pt2di sz,Type val); 

      virtual int    dim() const;
      virtual const int  * p0()  const;
      virtual const int  * p1()  const;

      Type **     _data;
      bool        _to_free2;

      virtual void q_dilate
                   (  Std_Pack_Of_Pts<int> * set_dilated,
                      char **                is_neigh,
                      const Std_Pack_Of_Pts<int> * set_to_dilate,
                      int **,
                      int   nb_v,
                      Image_Lut_1D_Compile   func_selection,
                      Image_Lut_1D_Compile   func_update
                   );

      DataIm2D
      (
           int tx, 
           int ty,
           bool to_init,
           TyBase v_init,
           const char * =0,
           Type *      dlin = 0,
           Type **     d2 = 0,
           int         tx_phys = -1,
		   bool        NoDataLin = false
      );

      virtual void out_assoc
              (
                  void * out, // eventually 0
                  const OperAssocMixte &,
                  Const_int_PP coord,
                  int nb,
                  const void * values
              ) const;

          void Resize(Pt2di aSz);
};


template <class Type,class TyBase> class DataIm1D : 
            public DataGenImType<Type,TyBase>
{
    public :


      static const  DataIm1D<Type,TyBase> The_Bitm; 


      virtual void out_pts_integer(Const_int_PP coord,int nb,const void *) ;
      virtual void input_pts_integer(void *,Const_int_PP coord,int nb) const;
      virtual void input_pts_reel(double_t *,Const_double_t_PP coord,int nb) const;


      DataIm1D(int tx,void * data ,bool to_init ,TyBase v_init,const char * =0);

      virtual int    dim() const;
      virtual const int  * p0()  const;
      virtual const int  * p1()  const;

      virtual void  *   calc_adr_seg(int *);
      virtual ~DataIm1D();

      Type *  data() const;
      int tx() const ;

       int           _tx;
       Type *     _data;

       virtual void out_assoc
              (
                  void * out, // eventually 0
                  const OperAssocMixte &,
                  Const_int_PP coord,
                  int nb,
                  const void * values
              ) const;

       virtual void tiff_predictor(int nb_el,int nb_ch,int max_val,bool codage);

       void Resize(int aTx);
       void Initializer (int Tx,void * data);

     protected :

};


template <class Type,class TyBase> class DataIm3D : 
            public DataGenImType<Type,TyBase>
{
    public :




      virtual void out_pts_integer(Const_int_PP coord,int nb,const void *) ;
      virtual void input_pts_integer(void *,Const_int_PP coord,int nb) const;
      virtual void input_pts_reel(double_t *,Const_double_t_PP coord,int nb) const;


      DataIm3D(
                int tx,int ty,int tz,
                bool to_init,TyBase v_init,const char * =0,Type * DataLin  = 0
      );

      virtual int    dim() const;
      virtual const int  * p0()  const;
      virtual const int  * p1()  const;

      virtual void  *   calc_adr_seg(int *);
      virtual ~DataIm3D();

      Type ***  data() const;
      int tx() const ;
      int ty() const ;
      int tz() const ;

       int           _txyz[3];
       Type ***    _data;

       virtual void out_assoc
              (
                  void * out, // eventually 0
                  const OperAssocMixte &,
                  Const_int_PP coord,
                  int nb,
                  const void * values
              ) const;


     protected :

};



template <class Type> class Liste_Pts_in_Comp;

class Data_Liste_Pts_Gen;

class Data_Liste_Pts_Gen  : public RC_Object
{
     friend class Liste_Pts_Out_Comp;
     friend class Liste_Pts_Out_Not_Comp;
     friend class Liste_Pts_in_Comp<int>;
     friend class Liste_Pts_in_Comp<double_t>;
     friend class Liste_Pts_in_Not_Comp;

     public :
          bool      empty() const;
          int       card() const;
          int       dim() const;
          virtual ~Data_Liste_Pts_Gen();


     protected :
         Data_Liste_Pts_Gen(const DataGenIm  *,int dim);
         void free_el();


         class  el_liste_pts : public Mcheck
         {
             public :
                enum {Elise_SZ_buf_lpts = 48};
                class el_liste_pts * next;
                char * buf(){return reinterpret_cast<char *>(&_buf[0]);}
             private :
                // Assume that double has the maximum aligmnent constraint
                double _buf[(Elise_SZ_buf_lpts+sizeof(double)-1)/sizeof(double)];
         };



         const DataGenIm     *  _gi;
         int              _dim;
         int              _nb_last;
         int              _sz_el;
         int              _sz_base;
         int              _nb_by_el;
         bool             _free_for_out;
         el_liste_pts *   _first;
         el_liste_pts *   _last;
         bool _is_copie ; // when true, do not free in ~Data_Liste_Pts_Gen

         void cat_pts(char * * coord,int nb);
         int next_pts(char * * coord,int nb_max);

};


template  <class Type,class TyBase> class Data_Liste_Pts : 
                    public Data_Liste_Pts_Gen
{
    friend class Liste_Pts<Type,TyBase>;
    public :
        virtual ~Data_Liste_Pts();
    private :

        Data_Liste_Pts(int dim);

        Im2D<Type,TyBase>  image();
        void add_pt(Type *);
};

template <class TyBase>
         void verif_value_op_ass
              (
                  const OperAssocMixte & op,
                  const TyBase *         pre_out,
                  const TyBase *         values,
                  int                    nb0,
                  TyBase                 v_min,
                  TyBase                 v_max
              );

#endif

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
