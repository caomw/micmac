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
                double_t *             aV0,
                int                aDegre
        );
        Fonc_Num  Fonc();
        double_t  Val(double_t aTime);

     private :
        double_t *                  mV0;
        int                     mDegre;
        Fonc_Num                mFonc;
        std::vector<double_t>       mValsCur;

        cPolynome1VarFormel(const cPolynome1VarFormel &);  // Non Implemante
        void    operator = (const cPolynome1VarFormel &);  // Non Implemante
};

#endif
