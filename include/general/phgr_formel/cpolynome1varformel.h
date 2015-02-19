#ifndef _ELISE_GENERAL_PHGR_FORMEL_CPOLYNOME1VARFORMEL_H
#define _ELISE_GENERAL_PHGR_FORMEL_CPOLYNOME1VARFORMEL_H

#include "general/sys_dep.h"

class  cPolynome1VarFormel
{
     public :
        cPolynome1VarFormel
        (
                cSetEqFormelles    &,
                cVarSpec           aVarTime,
                REAL *             aV0,
                INT                aDegre
        );
        Fonc_Num  Fonc();
        REAL  Val(REAL aTime);

     private :
        REAL *                  mV0;
        INT                     mDegre;
        Fonc_Num                mFonc;
        std::vector<REAL>       mValsCur;

        cPolynome1VarFormel(const cPolynome1VarFormel &);  // Non Implemante
        void    operator = (const cPolynome1VarFormel &);  // Non Implemante
};

#endif
