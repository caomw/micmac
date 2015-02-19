#ifndef _ELISE_GENERAL_GEOM_VECTEUR_CRESREQNUAGELASER_H
#define _ELISE_GENERAL_GEOM_VECTEUR_CRESREQNUAGELASER_H

#include "general/sys_dep.h"

class cResReqNuageLaser
{
   public :
     virtual void cResReqNuageLaser_Add(const Pt3dr & aP) = 0;
   virtual ~cResReqNuageLaser() {}
};

#endif
