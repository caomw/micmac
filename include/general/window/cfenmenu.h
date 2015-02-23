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


#ifndef _ELISE_GENERAL_WINDOW_CFENMENU_H
#define _ELISE_GENERAL_WINDOW_CFENMENU_H

#include "general/sys_dep.h"

class cFenMenu
{
      public :
         cFenMenu(Video_Win aWSoeur,const Pt2di & aSzCase,const Pt2di & aNb);
         int Get();
         Video_Win W();

         void ColorieCase(const Pt2di & aKse,Col_Pal,int aBrd);
         void StringCase(const Pt2di & aKse,const std::string &,bool center);
         Pt2di  Pt2Case(const Pt2di & aP) const;
         Pt2di  Case2Pt(const Pt2di & aP) const;
      protected :
         Video_Win mW;
      private :
         Pt2di     mSzCase;
         Pt2di      mNb;
};

#endif
