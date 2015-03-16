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

#ifndef _ELISE_GENERAL_BITM_BITS_TABUL_BITS_H
#define _ELISE_GENERAL_BITM_BITS_TABUL_BITS_H

#include <Tabul_Bits_Gen>

template<const int nbb,const bool msbf>
class Tabul_Bits : public Tabul_Bits_Gen
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

        typedef unsigned char  tLineInputTab[nb_per_byte];
        typedef unsigned char  tLineOutputTab[nb_val][nb_per_byte];

        static  tLineInputTab *  input_tab;
        static  tLineOutputTab * out_tab;

        // static U_int1  input_tab[256][nb_per_byte];
        // static U_int1  out_tab[256][nb_val][nb_per_byte];


         void  input(int * out,const unsigned char * in,int x0,int x1) const;
         void  output(unsigned char * out,const  int * in,int x0,int x1) const ;
         void  output(unsigned char * out,const double_t * in,int x0,int x1) const ;

         virtual int   kieme_val      (int byte,int k) const;
         virtual int   set_kieme_val  (int old_byte,int val,int k) const;


        static  Tabul_Bits<nbb,msbf> The_Only_One;
    private:
        Tabul_Bits(int ArgBid);
        ~Tabul_Bits();
        static void init_tabul();
};

#endif
