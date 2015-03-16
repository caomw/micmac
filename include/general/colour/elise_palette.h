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



#ifndef _ELISE_GENERAL_COLOUR_ELISE_PALETTE_H
#define _ELISE_GENERAL_COLOUR_ELISE_PALETTE_H

#include <PRC0>
#include <Fonc_Num>

class  Elise_Palette : public PRC0
{
       friend class Data_Disp_Pallete;
       friend class  Elise_Set_Of_Palette;
       friend class  DE_GW_Not_Comp;
       friend class  Data_Col_Pal;
       friend class  Data_Elise_PS_Disp;
       friend class  PS_Out_RLE_computed;
       friend class  PS_Pts_Not_RLE;
       friend class  Disc_Pal;
       friend class  RGB_Pal;
       friend class  Gray_Pal;
       friend class  Circ_Pal;
       friend class  Video_Win;
       friend class  ElXim;

       public :
           int  nb();
           Fonc_Num to_rgb(Fonc_Num);
		   int  dim_pal();
		   enum {MaxDimPal = 3};


       protected :
           Elise_Palette(Data_Elise_Palette *);
           inline Data_Elise_Palette * dep() const
           {
               return SAFE_DYNC(Data_Elise_Palette *,_ptr);
           }
       private :

           class Elise_PS_Palette * ps_comp(const char * name);

           inline TYOFPAL::t type_pal() const;
};

#endif
