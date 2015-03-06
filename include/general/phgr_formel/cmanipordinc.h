#ifndef _ELISE_GENERAL_PHGR_FORMEL_CMANIPORDINC_H
#define _ELISE_GENERAL_PHGR_FORMEL_CMANIPORDINC_H

#include "general/sys_dep.h"

class cManipOrdInc
{
     public :
        
        cManipOrdInc();
        void Init(const std::vector<cIncIntervale *> &aBlocsIncAlloc);
        Im1D_double_t8 ReordonneSol(Im1D_double_t8 aIm);
        std::vector<cIncIntervale *> &  BlocsIncSolve();
        std::vector<int>             &  I02NblSolve();
        std::vector<int>             &  Alloc2Solve();
        std::vector<int>             &  Solve2Alloc();
     private :
        std::vector<cIncIntervale *> mBlocsIncSolve;
        std::vector<int>              mI02NblSolve;

        std::vector<int>              mAlloc2Solve;
        std::vector<int>              mSolve2Alloc;
};

#endif
