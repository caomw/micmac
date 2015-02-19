#ifndef _ELISE_GENERAL_OPTIM_CSTATEALLOCI_H
#define _ELISE_GENERAL_OPTIM_CSTATEALLOCI_H

#include "general/sys_dep.h"

class cStateAllocI
{
     public :
           friend class AllocateurDInconnues;
           cStateAllocI(const AllocateurDInconnues&);
           void ShowDiff(const cStateAllocI &) const;
     private  :
        const AllocateurDInconnues & mAlloc;
        std::vector<double>          mVals;
};

#endif
