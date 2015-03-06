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


#ifndef _ELISE_GENERAL_WINDOW_VIDEO_DISPLAY_H
#define _ELISE_GENERAL_WINDOW_VIDEO_DISPLAY_H

#include "general/sys_dep.h"

class  Video_Display : public PRC0
{
     friend class Data_Elise_Video_Win;
     friend class Video_Win;

     public :
         Video_Display(const char * name);
         Video_Display(Video_Win_LawLevelId,void * Id);
         void  load(Elise_Set_Of_Palette);
         Clik   clik();
         Clik   clik_press();
         Clik   clik_release();
		 int  Depth() const; // Nombre de bits par pixel
		 Pt2di  Sz() const; // Nombre de pixels
		 bool TrueCol() const; // false si col-indexe

     private :
         Video_Display(Data_El_Video_Display *);
         Data_El_Video_Display * devd();
         const Data_El_Video_Display * devd() const;
		 
};

#endif
