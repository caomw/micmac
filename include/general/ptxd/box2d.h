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


#ifndef _ELISE_GENERAL_PTXD_BOX2D_H
#define _ELISE_GENERAL_PTXD_BOX2D_H

#include "general/sys_dep.h"

#include <cElMap2D>
#include <Interval>
#include <Pt2d>
#include <Flux_Pts>
#include <SegComp>
#include <cElTriangleComp>

template <class Type> class Box2d
{
   public :

      Box2d<double> BoxImage(const cElMap2D &) const;

      Interval  XInterv() const {return Interval(_p0.x,_p1.x);}
      Interval  YInterv() const {return Interval(_p0.y,_p1.y);}

     typedef  Box2d<Type> QBox[4];
     typedef  Pt2d<Type>  P4[4];

     Pt2dr  RandomlyGenereInside() const;

     std::vector<Pt2dr> ClipConpMax(const std::vector<Pt2dr> &);


     Pt2d<Type>  _p0;
     Pt2d<Type>  _p1;
     Pt2d<Type> milieu() const { return (_p0+_p1) / 2;}
     Pt2d<Type> sz() const { return _p1 - _p0;}
     Pt2d<Type> FromCoordLoc(Pt2dr aP) const { return Pt2d<Type>(ToPt2dr(_p0)+aP.mcbyc(ToPt2dr(sz())));}


     Pt2dr ToCoordLoc(Pt2dr aP) const { return (aP-ToPt2dr(_p0)).dcbyc(ToPt2dr(sz()));}

     Type   hauteur() const { return _p1.y-_p0.y;}
     Type   largeur() const { return _p1.x-_p0.x;}
     REAL  diam() const{return euclid(_p0,_p1);}
     Type surf() {return hauteur() * largeur();}
     Type x(int i) const {return i ? _p1.x : _p0.x;}
     Type y(int i) const {return i ? _p1.y : _p0.y;}

     Box2d<Type> trans(Pt2d<Type>) const;
     Pt2d<Type> P0() const {return _p0;}
     Pt2d<Type> P1() const {return _p1;}
     Flux_Pts Flux() const;


     // 0 a l'exterieur, distance (d8) au bord a l'interieur
     double Interiorite(const Pt2dr & aP) const;


     Box2d(){}
     Box2d(Type);
     Box2d(Pt2d<Type>);
     Box2d(const Pt2d<Type> *,INT aNb);
     Box2d(Pt2di,Pt2di);
     Box2d(Pt2dr,Pt2dr);  // cast up and down
     Box2d(Pt2dlr,Pt2dlr);  // cast up and down
     Box2d(const Type *,const Type *,INT);
     bool include_in(const Box2d<Type> & b2) const;
     Box2d<Type>  erode(Pt2d<Type>) const;
     Box2d<Type>  dilate(Pt2d<Type>) const;
     Box2d<Type>  dilate(Type) const;

     std::vector<Pt2d<Type> >   Contour() const;


     // + ou - dilatation signee, en fait equivalent avec la
     // definition actuelle de dilate (mais le cote algebrique de
     // de dilate n'est pas acquis a 100%)
     Box2d<Type>  AddTol(const Box2d<Type> &) const;
     Box2d<Type>  AddTol(const Pt2d<Type> &) const;
     Box2d<Type>  AddTol(const Type &) const;

     bool  inside(const Pt2d<Type> & p) const;  // p0 <= Box._p1
     bool  inside_std(const Pt2d<Type> & p) const;  // p0 < Box._p1

     bool contains(const Pt2d<int> & pt) const
     {
        return (pt.x>=_p0.x) && (pt.y>=_p0.y) && (pt.x<_p1.x) && (pt.y<_p1.y);
     }
     bool contains(const Pt2d<double> & pt) const
     {
        return (pt.x>=_p0.x) && (pt.y>=_p0.y) && (pt.x<_p1.x) && (pt.y<_p1.y);
     }
     bool contains(const Pt2d<long double> & pt) const
     {
        return (pt.x>=_p0.x) && (pt.y>=_p0.y) && (pt.x<_p1.x) && (pt.y<_p1.y);
     }



     Pt2dr FromCoordBar(Pt2dr aCBar) const;


   //   QT

          // generaux

          INT  freeman_pos(const Pt2dr & pt) const;

          // box point

     bool   Intersecte(const Pt2dr &) const;
     bool   Intersecte(const SegComp &) const;
     bool   Intersecte(const Seg2d &) const;
     bool   Intersecte(const cElTriangleComp &) const;
     bool   Include(const Pt2dr &) const;
     bool   Include(const SegComp &) const;
     bool   Include(const Seg2d &) const;
     bool   Include(const cElTriangleComp &) const;
     REAL8  SquareDist(const Pt2dr &) const;
     REAL8  SquareDist(const SegComp &) const;
     REAL8  SquareDist(const Seg2d &) const;
     REAL8  SquareDist(const Box2d<Type> &) const;

     void   QSplit(QBox &) const; // Split in 4 box (for Q-Tree)
     void   QSplitWithRab(QBox &,Type aRab) const; // Split in 4 box (for Q-Tree)
     void   Corners(P4 &) const; // Split in 4 box (for Q-Tree)

      void PtsDisc(std::vector<Pt2dr> &,INT aNbPts);
   private :
        typedef REAL8 (Box2d<Type>:: * R_fonc_Pt2dr)(const Pt2dr &) const;

        REAL  Freem0SquareDist(const Pt2dr &) const;
        REAL  Freem1SquareDist(const Pt2dr &) const;
        REAL  Freem2SquareDist(const Pt2dr &) const;
        REAL  Freem3SquareDist(const Pt2dr &) const;
        REAL  Freem4SquareDist(const Pt2dr &) const;
        REAL  Freem5SquareDist(const Pt2dr &) const;
        REAL  Freem6SquareDist(const Pt2dr &) const;
        REAL  Freem7SquareDist(const Pt2dr &) const;
        REAL  Freem8SquareDist(const Pt2dr &) const;

        friend  class BoxFreemanCompil<Type>;
        REAL8  SquareDist(const Pt2dr &,INT c) const;

        static R_fonc_Pt2dr _Tab_FreemSquareDist[9];
};

typedef Box2d<INT> Box2di;
typedef Box2d<REAL> Box2dr;

#endif
