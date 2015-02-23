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


#ifndef _ELISE_GENERAL_GEOM_VECTEUR_SEG2D_H
#define _ELISE_GENERAL_GEOM_VECTEUR_SEG2D_H

#include "general/sys_dep.h"

#include <Box2d>

class Seg2d
{
   public :

     Seg2d(REAL x1,REAL y1,REAL x2,REAL y2);
     Seg2d(Pt2dr,Pt2dr);
     Seg2d();  // create an empty seg

    Seg2d reverse() const {assert_non_empty(); return Seg2d(p1(),p0());}

     Seg2d clip(Box2dr) const;
     Seg2d clip(Box2dr,REAL,REAL,bool IsSeg) const;
     Seg2d clipDroite(Box2dr) const;
     Seg2d clip(Box2di) const;

     inline bool  empty() const {return _empty;}
     inline Pt2dr p0() const {assert_non_empty();  return _pts[0];}
     inline Pt2dr p1() const {assert_non_empty();  return _pts[1];}

     inline REAL x0() const {assert_non_empty();  return _pts[0].x;}
     inline REAL x1() const {assert_non_empty();  return _pts[1].x;}
     inline REAL y0() const {assert_non_empty();  return _pts[0].y;}
     inline REAL y1() const {assert_non_empty();  return _pts[1].y;}

     inline Pt2dr milieu() const {assert_non_empty();  return (_pts[1]+_pts[0])/2.0;}

     inline Pt2dr v01() const {assert_non_empty();  return _pts[1]-_pts[0];}

     inline Seg2d trans(Pt2dr tr) const {assert_non_empty();  return Seg2d(_pts[0]+tr,_pts[1]+tr);}

      REAL AbsiceInterDroiteHoriz(REAL anOrdonnee) const;

   protected :

    inline Pt2dr kpts(INT k) const {return _pts[k];}

     void assert_non_empty() const
     {
          ELISE_ASSERT
          (    (! _empty)   ,
               "try to access to value of empty segment"
          );
     }



     Pt2dr  _pts[2];
     bool   _empty;
};

#endif
