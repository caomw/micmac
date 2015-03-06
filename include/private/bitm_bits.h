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



#ifndef _ELISE_BITM_BITS_H
#define _ELISE_BITM_BITS_H

#include <private/bitm_def.h>
#include <private/bitm_tpl.h>
#include <general/error.h>
#include <general/smart_pointeur.h>

class Tabul_Bits_Gen
{
      public :
         virtual int   kieme_val      (int byte,int k) const  = 0;
         virtual int   set_kieme_val  (int old_byte,int val,int k) const = 0;

         static void  init_tabul_bits();
         virtual void  input(int * out,const U_int1 * in,int x0,int x1) const = 0;
         virtual void  output(U_int1 * out,const  int * in,int x0,int x1) const = 0;
         virtual void  output(U_int1 * out,const double_t * in,int x0,int x1) const = 0;

	 virtual ~Tabul_Bits_Gen() {}

         static const Tabul_Bits_Gen & tbb(int nbb,bool msbf);

         static void  unpack
                      (
                         U_int1 *          out,
                         const U_int1 *    in,
                         int               nb,
                         int               nbb,
                         bool              msbf
                      );

         static void  pack
                      (
                         U_int1 *          out,
                         const U_int1 *    in,
                         int               nb,
                         int               nbb,
                         bool              msbf
                      );


};

template <const int nbb>  class DataGenImBits;

template<const int nbb,const bool msbf> class Tabul_Bits : public Tabul_Bits_Gen
{
    friend class Tabul_Bits_Gen;
    friend class DataGenImBits<nbb>;

    public  :

        enum 
        {
              nb_per_byte = 8/nbb,
              nb_val      = 1<<nbb
        };

        static int sz_line(int nb_el);

        typedef U_int1  tLineInputTab[nb_per_byte];
        typedef U_int1  tLineOutputTab[nb_val][nb_per_byte];

        static  tLineInputTab *  input_tab;
        static  tLineOutputTab * out_tab;

        // static U_int1  input_tab[256][nb_per_byte];
        // static U_int1  out_tab[256][nb_val][nb_per_byte];


         void  input(int * out,const U_int1 * in,int x0,int x1) const;
         void  output(U_int1 * out,const  int * in,int x0,int x1) const ;
         void  output(U_int1 * out,const double_t * in,int x0,int x1) const ;

         virtual int   kieme_val      (int byte,int k) const;
         virtual int   set_kieme_val  (int old_byte,int val,int k) const;


        static  Tabul_Bits<nbb,msbf> The_Only_One;
    private:
        Tabul_Bits(int ArgBid);
        ~Tabul_Bits();
        static void init_tabul();
};


template <const int nbb>  class DataGenImBits : public DataGenIm
{
   public :

      DataGenImBits(int sz_0,int sz_tot,void * DataLin);  // sz_tot do not incopoarte first dim
      virtual void  input_rle(void *,int,const void*,int offs_0) const;


      virtual void  out_rle(void *,int,const int*,int offs_0) const;
      virtual void  out_rle(void *,int,const double_t*,int offs_0) const;
      virtual int sz_tot() const;



       void SetAll(int aVal);
      bool          mDataLinOwner;
      int           _sz_tot;
      int           _sz_line; 
      U_int1 *      _data_lin; // for afficionados of manipulations
                               // like _data_lin[x+y*_tx]
                               //  use is disrecommended with images

      virtual int vmax() const;
      virtual int vmin() const;
      virtual bool integral_type() const;
      virtual GenIm::type_el type() const;


      // max and min integral values of the type: the convention
      // v_max == v_min is used when these values are useless:

      protected :
          virtual ~DataGenImBits();


     // All these methods, generate fatal errors; there are defined for
     // compatibility with ``DataGenIm'', but, as far as I know, can never
     // be reached

      virtual void  striped_input_rle(void *,int nb,int dim,const void*,int offs_0) const;
      virtual void  striped_output_rle(void *,int nb,int dim,const void*,int offs_0) const;
      virtual int sz_el() const;
      virtual int sz_base_el() const;
      virtual void  *  data_lin_gen();

      static GenIm::type_el     type_el_bitm;
};



template <const int nbb> class DataIm2D_Bits :
             public  DataGenImBits<nbb> ,
             public  DataIm2DGen
{
    public :

        enum 
        {
              nb_per_byte = Tabul_Bits<nbb,true>::nb_per_byte,
              nb_val      = Tabul_Bits<nbb,true>::nb_val     

        };

       void SetAll(int aVal);

       inline int get(int x,int y) const;
       inline int get_def(int x,int y,int v) const;
       inline void set(int x,int y,int val) const
    {
        U_int1 * adr_x = _data[y] +  x / nb_per_byte;
        *adr_x =  Tabul_Bits<nbb,true>::out_tab[*adr_x][val][x%nb_per_byte];
    }

      virtual void out_pts_integer(Const_int_PP coord,int nb,const void *) ;
      virtual void input_pts_integer(void *,Const_int_PP coord,int nb) const;
      virtual void input_pts_reel(double_t *,Const_double_t_PP coord,int nb) const;

      virtual void  *   calc_adr_seg(int *);
      virtual ~DataIm2D_Bits();


      virtual int    dim() const;
      virtual const int  * p0()  const;
      virtual const int  * p1()  const;

      U_int1 **     _data;

      Im2D_U_int1  gray_im_red(int & zoom);


      DataIm2D_Bits(int tx, int ty,bool to_init,int v_init,void *);

      virtual void out_assoc
              (
                  void * out, // eventually 0
                  const OperAssocMixte &,
                  Const_int_PP coord,
                  int nb,
                  const void * values
              ) const;

      virtual void q_dilate
                   (  Std_Pack_Of_Pts<int> * set_dilated,
                      char **,
                      const Std_Pack_Of_Pts<int> * set_to_dilate,
                      int **,
                      int   nb_v,
                      Image_Lut_1D_Compile   func_selection,
                      Image_Lut_1D_Compile   func_update
                   );

};


template <const int nbb>  DataIm2D_Bits<nbb>::DataIm2D_Bits
(
 int Tx,
 int Ty,
 bool to_init ,
 int  v_init,
 void * aDataLin
 ) :
DataGenImBits<nbb>(Tx,Ty,aDataLin),
DataIm2DGen(Tx,Ty)
{
    _data =  STD_NEW_TAB_USER(ty(),U_int1 *);
    
    for (int y = 0 ; y<ty() ; y++)
        _data[y] = this->_data_lin + y *this->_sz_line;
    
    if (to_init)
    {
        Tjs_El_User.ElAssert
        (
         (v_init<this->vmax()) && (v_init>=this->vmin()),
         EEM0 << "Bad init value in Im2D_Bits \n"
         << "|  Got " << v_init << ", expected >= " << this->vmin() << " and < " << this->vmax()
         );
        for (int b=0; b<nb_per_byte ; b++)
            set(b,0,v_init);
        U_int1  v0 = this->_data_lin[0];
        set_cste(this->_data_lin,v0,this->_sz_line*ty());
    }
}


// Methodes deplacees dans le header suite a des erreurs de compilation sous MacOS entre gcc4.0 et gcc4.2 (LLVM)
// du type : error: explicit specialization of 'TheType' after instantiation


template <const int nbb>  void DataGenImBits<nbb>::input_rle
(void * v_out,int nb,const void* v_in,int offs_0) const
{
    
    Tabul_Bits<nbb,true>::The_Only_One.input
    (
     C_CAST(int *,v_out),
     C_CAST(const U_int1 *,v_in),
     offs_0,
     offs_0+nb
     );
}

template <const int nbb>  void DataGenImBits<nbb>::out_rle
(void * v_out,int nb,const int * v_in,int offs_0) const
{
    
    Tabul_Bits<nbb,true>::The_Only_One.output
    (
     C_CAST(U_int1 *,v_out),
     v_in,
     offs_0,
     offs_0+nb
     );
}

template <const int nbb>  void DataGenImBits<nbb>::out_rle
(void * v_out,int nb,const double_t * v_in,int offs_0) const
{
    
    Tabul_Bits<nbb,true>::The_Only_One.output
    (
     C_CAST(U_int1 *,v_out),
     v_in,
     offs_0,
     offs_0+nb
     );
}

template <const int nbb>  GenIm::type_el  DataGenImBits<nbb>::type() const
{
    return type_el_bitm;
}




#endif // _ELISE_BITM_BITS_H
