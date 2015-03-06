#ifndef _ELISE_GENERAL_PHGR_FORMEL_CCONTRAintEEQF_H
#define _ELISE_GENERAL_PHGR_FORMEL_CCONTRAintEEQF_H

#include "general/sys_dep.h"

class cContrainteEQF
{
    public :
        static const double  theContrStricte;// = -1;

        cContrainteEQF(cElCompiledFonc * mFCtr,double aTol);
	cElCompiledFonc * FctrContrEQF() const;

         bool   ContrainteIsStricte() const;
	 double PdsOfEcart(double anEcart) const;
    private :
         cElCompiledFonc* mFctr;
	 double           mTol;
	 double           mMin;
         double           mMax;
         double           mPds;
};

#endif
