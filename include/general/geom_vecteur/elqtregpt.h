#ifndef _ELISE_GENERAL_GEOM_VECTEUR_ELQTREGPT_H
#define _ELISE_GENERAL_GEOM_VECTEUR_ELQTREGPT_H

#include "general/sys_dep.h"

class ElQTRegPt : public ElQTRegionPlan
{
      public :

         virtual double_t D2(const Box2dr &)  const ;
         virtual double_t D2(const Pt2dr & )  const ;
         virtual double_t D2(const SegComp &)  const;
         virtual double_t D2(const cElTriangleComp &)  const ; // Implantee

         ElQTRegPt (Pt2dr);
     virtual ~ElQTRegPt() {}

      private :

          Pt2dr _pt;
};

#endif
