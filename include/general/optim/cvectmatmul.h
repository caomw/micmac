#ifndef _ELISE_GENERAL_OPTIM_CVECTMATMUL_H
#define _ELISE_GENERAL_OPTIM_CVECTMATMUL_H

#include "general/sys_dep.h"

class cVectMatMul
{
    public :
       virtual void VMMDo(Im1D_REAL8 in,Im1D_REAL8 out) = 0;
       virtual ~cVectMatMul();
};

#endif
