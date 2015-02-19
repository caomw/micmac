#ifndef _ELISE_GENERAL_OPTIM_CMSYMCOFFACT3X3_H
#define _ELISE_GENERAL_OPTIM_CMSYMCOFFACT3X3_H

#include "general/sys_dep.h"

template <class Type> class cMSymCoffact3x3
{
public:
    Type a;
    Type e;
    Type i;
    Type b;
    Type c;
    Type f;

    Type mA;
    Type mE;
    Type mI;
    Type mB;
    Type mC;
    Type mF;
    Type mDet;

    cMSymCoffact3x3(Type ** aMat);
    void CoffSetInv(Type **);
    Pt3d<Type>  CoffVecInv(const Type *) const;
};

#endif
