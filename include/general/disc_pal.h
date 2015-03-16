/*Header-MicMac-eLiSe-25/06/2007

    MicMac : Multi Image Correspondances par Methodes Automatiques de Correlation
    eLiSe  : ELements of an Image Software Environnement

    www.micmac.ign.fr

   
    Copyright : Institut Geographique National
    Author : Marc Pierrot Deseilligny
    Contributors : Gregoire Maillet, Didier Boldo.
	Refactoring : Helio Chissini de Castro <helio@kde.org>

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



#ifndef _ELISE_GENERAL_COLOUR_DISC_PAL_H
#define _ELISE_GENERAL_COLOUR_DISC_PAL_H

#include <Elise_Palette>

class Disc_Pal :  public Elise_Palette
{
       friend class Tiff_Im;
       friend class DATA_Tiff_Ifd;
       friend class El_Window;
       public :  
          Disc_Pal      (   
                            L_El_Col,
                            bool reverse = false
                        );

         Disc_Pal(Elise_colour *,int nb);
         void  getcolors(Elise_colour *);
         Elise_colour *  create_tab_c();  // allocated by NEW_VECTEUR

         // Just for compatiblity with my old clisp data
         static  Disc_Pal    clisp_pal(int nb);

         static  Disc_Pal    P8COL();
         static  Disc_Pal    PNCOL();
         static  Disc_Pal    PBIN();
         static  Disc_Pal    PCirc(int = 256); // Palette en teinte, 
         class Col_Pal operator () (int);
         int  nb_col();

         class DEP_Discrete * depd() 
               {return SAFE_DYNC(class DEP_Discrete *,_ptr);}

         Disc_Pal reduce_col(Im1D_int4 lut,int nb_cible);

      private :
         Disc_Pal();
         Disc_Pal(Elise_Palette);
};

#endif
