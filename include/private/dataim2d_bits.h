/*Header-MicMac-eLiSe-25/06/2007

    MicMac : Multi Image Correspondances par Methodes Automatiques de Correlation
    eLiSe  : ELements of an Image Software Environnement

    www.micmac.ign.fr


    Copyright : Institut Geographique National
    Author : Marc Pierrot Deseilligny
    Contributors : Gregoire Maillet, Didier Boldo.
    Refactoring: Helio Chissini de Castro <helio@kde.org>

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

#ifndef _ELISE_GENERAL_BITM_BITS_DATAIM2D_BITS_H
#define _ELISE_GENERAL_BITM_BITS_DATAIM2D_BITS_H

#include <DataGenImBits>
#include <DataIm2DGen>
#include <Tabul_Bits>
#include <Im2D>

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
        unsigned char * adr_x = _data[y] +  x / nb_per_byte;
        *adr_x =  Tabul_Bits<nbb,true>::out_tab[*adr_x][val][x%nb_per_byte];
    }

    virtual void out_pts_integer(Const_INT_PP coord,int nb,const void *) ;
    virtual void input_pts_integer(void *,Const_INT_PP coord,int nb) const;
    virtual void input_pts_reel(double_t *,Const_REAL_PP coord,int nb) const;

    virtual void  *   calc_adr_seg(int *);
    virtual ~DataIm2D_Bits();


    virtual int    dim() const;
    virtual const int  * p0()  const;
    virtual const int  * p1()  const;

    unsigned char **     _data;

    Im2D_U_int1  gray_im_red(int & zoom);


    DataIm2D_Bits(int tx, int ty,bool to_init,int v_init,void *);

    virtual void out_assoc
    (
            void * out, // eventually 0
            const OperAssocMixte &,
            Const_INT_PP coord,
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

#endif
