#ifndef _ELISE_GENERAL_PHGR_FORMEL_CQUADRANGLE_H
#define _ELISE_GENERAL_PHGR_FORMEL_CQUADRANGLE_H

#include "general/sys_dep.h"

class cQuadrangle
{
      public :
           cQuadrangle
           (
                   const cIncIntervale & aI00,
                   const cIncIntervale & aI10,
                   const cIncIntervale & aI01,
                   const cIncIntervale & aI11
           );
           cIncIntervale    mInt00;
           cIncIntervale    mInt10;
           cIncIntervale    mInt01;
           cIncIntervale    mInt11;
};

#endif
