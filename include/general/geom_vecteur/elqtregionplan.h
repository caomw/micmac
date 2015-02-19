#ifndef _ELISE_GENERAL_GEOM_VECTEUR_ELQTREGIONPLAN_H
#define _ELISE_GENERAL_GEOM_VECTEUR_ELQTREGIONPLAN_H

#include "general/sys_dep.h"

class ElQTRegionPlan
{
      public :

         virtual REAL D2(const Box2dr &) const = 0;
         virtual REAL D2(const Pt2dr &)  const = 0;
         virtual REAL D2(const SegComp &)  const = 0;
         virtual REAL D2(const cElTriangleComp &)  const ; // Def = err fatale
     virtual ~ElQTRegionPlan() {}
};

#endif
