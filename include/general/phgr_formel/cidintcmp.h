#ifndef _ELISE_GENERAL_PHGR_FORMEL_CIDintCMP_H
#define _ELISE_GENERAL_PHGR_FORMEL_CIDintCMP_H

#include "general/sys_dep.h"

class cIdIntCmp
{
     public :
          bool operator()(const cIncIntervale & anII1,const cIncIntervale & anII2) const;
};

#endif
