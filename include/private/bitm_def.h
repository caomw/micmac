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

#ifndef __BITM_DEF__
#define __BITM_DEF__

#include <private/flux_pts.h>
#include <general/ptxd.h>
#include <general/operator.h>

extern INT PTS_00000000000000 [];

class  Image_Lut_1D_Compile
{
public :
    INT * _l;
    INT   _b1;
    INT   _b2;

    Image_Lut_1D_Compile(Im1D<INT4,INT>);
};


class DataGenIm : public RC_Object
{

public :

    virtual ~DataGenIm();

    virtual INT sz_el() const = 0;
    virtual INT sz_base_el() const = 0;
    virtual INT dim()   const = 0;
    virtual INT sz_tot() const = 0;   // Number of pixels
    virtual bool integral_type() const = 0;

    // p0, p1 => return limit of bounding box
    virtual const INT  * p0() const = 0;
    virtual const INT  * p1() const = 0;


    virtual void  out_rle(void *,INT,const INT*,INT offs_0) const  = 0;
    virtual void  out_rle(void *,INT,const REAL*,INT offs_0)const  = 0;
    virtual void  * calc_adr_seg(INT *)     = 0;
    virtual void  input_rle(void *,INT,const void*,INT offs_0)const  = 0;

    virtual void  striped_input_rle(void *,INT nb,INT dim,const void*,INT offs_0) const = 0;
    virtual void  striped_output_rle(void *,INT nb,INT dim,const void*,INT offs_0) const = 0;

    virtual void  verif_in_range_type(INT*,const Pack_Of_Pts *) ;
    virtual void  verif_in_range_type(REAL*,const Pack_Of_Pts *);


    static void  verif_in_range_type(INT*,const Pack_Of_Pts *,INT,INT) ;
    static void  verif_in_range_type(REAL*,const Pack_Of_Pts *,INT,INT);

    // This function is used for the not rle input or output, so it is described
    // in each specialization of dimention to allow a quicker implementation

    virtual void out_pts_integer(Const_INT_PP coord,INT nb,const void *)  = 0;
    virtual void input_pts_integer(void *,Const_INT_PP coord,INT nb) const  = 0;
    virtual void input_pts_reel(REAL *,Const_REAL_PP coord,INT nb) const  = 0;

    virtual INT vmin() const = 0;
    virtual INT vmax() const = 0;

    virtual void out_assoc
    (
            void * out, // never 0
            const OperAssocMixte &,
            Const_INT_PP coord,
            INT nb,
            const void * values
            )  const = 0;


    virtual void  *  data_lin_gen() =0 ;


    // By default : generate a fatal error. Redefined to 2-dimentionnal images.
    virtual void q_dilate
    (  Std_Pack_Of_Pts<INT> * set_dilated,
       char **,
       const Std_Pack_Of_Pts<INT> * set_to_dilate,
       INT **,
       INT   nb_v,
       Image_Lut_1D_Compile   func_selection,
       Image_Lut_1D_Compile   func_update
       );


    // def error fatale
    virtual void tiff_predictor
    (INT nb_el,INT nb_ch,INT max_val,bool codage);

    void load_file(Elise_File_Im,GenIm);
    void read_data(ELISE_fp &);
    void write_data(ELISE_fp &) const;

    virtual GenIm::type_el type() const = 0;
protected :

private :
    Fonc_Num  in(bool,REAL);
};

#endif

//             Warning    !!!!!!!!!!!!!!!!
//          
//              Withs  Bits-Images, alloc_im1d return u_int1 images;
//

/*
extern GenIm alloc_im1d(GenIm::type_el type_el,int tx,void * data = 0);
extern GenIm alloc_im2d(GenIm::type_el type_el,int tx,int ty);
extern bool  type_im_integral(GenIm::type_el type_el);

extern INT nbb_type_num(GenIm::type_el type_el);     // nb byte
extern bool msbf_type_num(GenIm::type_el type_el);   // is most signif first
extern bool signed_type_num(GenIm::type_el type_el); // is it signed int
extern GenIm::type_el type_u_int_of_nbb(INT nbb,bool msbf = true);

extern void min_max_type_num(GenIm::type_el,INT & v_min,INT &v_max);
*/
