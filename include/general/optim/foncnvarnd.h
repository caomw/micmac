#ifndef _ELISE_GENERAL_OPTIM_FONCNVARND_H
#define _ELISE_GENERAL_OPTIM_FONCNVARND_H

#include "general/sys_dep.h"

template <class Type> class FoncNVarND
{
    public :

       FoncNVarND(INT NbVar);
       virtual ~FoncNVarND();

       virtual REAL ValFNV(const Type *  v) = 0;
       INT NbVar() const;
       INT powel(Type *,REAL ftol,INT ITMAX = 200);

    protected :

       const INT           _NbVar;

       inline REAL NRValFNV(const Type *);  // Just Recall ValFNV with NR convention
       void powel(Type *,REAL ftol,int *iter,REAL * fret,INT ITMAX = 200);
};

#endif
