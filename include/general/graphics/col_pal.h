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


#ifndef _ELISE_GENERAL_GRAPHICS_COL_PAL_H
#define _ELISE_GENERAL_GRAPHICS_COL_PAL_H

#include <PRC0>

class Col_Pal : public PRC0
{
    public :

       friend class Gray_Pal;
       friend class BiCol_Pal;
       friend class Disc_Pal;
       friend class Circ_Pal;
       friend class TriCol_Pal;
       friend class RGB_Pal;
       friend class Lin1Col_Pal;

       friend class Data_Line_St;
       friend class Data_Fill_St;
       friend class PS_Pts_Not_RLE;
       friend class Data_Elise_PS_Disp;

        inline class Data_Col_Pal * dcp() const 
               {return SAFE_DYNC(class Data_Col_Pal *,_ptr);}

    private :


        Col_Pal(Elise_Palette,int);
        Col_Pal(Elise_Palette,int,int);
        Col_Pal(Elise_Palette,int,int,int);

};

#endif
