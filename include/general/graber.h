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



#ifndef _ELISE_GENERAL_COMPR_IM_GRABER_H
#define _ELISE_GENERAL_COMPR_IM_GRABER_H

#include "general/sys_dep.h"

          class Graber :  public  Grab_Untill_Realeased
          {
                public :
                   Graber(EliseStdImageInteractor &) ;

                private :
                    void  GUR_query_pointer(Clik ,bool);
                    void  GUR_button_released(Clik);

                    EliseStdImageInteractor & mESII;
          };


          Video_Win          mW;
          ElImScroller &     mScr;
          int                mButtonGeom;
          int                mButtonZoomIn;
          int                mButtonZoomOut;
          bool               mScaleMode;
          Pt2dr              mP0Grab;
          Pt2dr              mLastPGrab;
          double_t               mScale0Grab;
          double_t               mSpeedTranslate;  // 1.0
          double_t               mYDoubleScale;    // 100.0
          double_t               mScaleMax;        // 10.0
          double_t               mScaleMin;        // 0.02
          bool               mRasterQuickZoom; // true
          Graber             *mGeoGraber;
          bool               mModeReplicationPixel;

          std::vector<Pt2dr> mPolygCur;
          int                mCoulSomPolygCur;
          int                mCoulEdgePolygCur;


          friend class Graber;
};

#endif
