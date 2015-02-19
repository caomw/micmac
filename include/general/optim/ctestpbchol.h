#ifndef _ELISE_GENERAL_OPTIM_CTESTPBCHOL_H
#define _ELISE_GENERAL_OPTIM_CTESTPBCHOL_H

#include "general/sys_dep.h"

class cTestPbChol
{
     public :
       cTestPbChol(const std::string & aName);
       std::string mName;
       double  mMinVP;
       double  mMinSomVNeg;
};

#endif
