#ifndef _ELISE_GENERAL_GEOM_VECTEUR_ELQTREGSEG_H
#define _ELISE_GENERAL_GEOM_VECTEUR_ELQTREGSEG_H

#include "general/sys_dep.h"

class ElQTRegSeg : public ElQTRegionPlan
{
      public :

         virtual double_t D2(const Box2dr &)  const ;
         virtual double_t D2(const Pt2dr & )  const ;
         virtual double_t D2(const SegComp &)  const;

         ElQTRegSeg (Seg2d);
     virtual ~ElQTRegSeg() {}
      private :

          SegComp _seg;
};

#endif
