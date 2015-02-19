#ifndef _ELISE_GENERAL_OPTIM_FONCNVARDER_H
#define _ELISE_GENERAL_OPTIM_FONCNVARDER_H

#include "general/sys_dep.h"

template <class Type> class  FoncNVarDer : public FoncNVarND<Type>
{
    public :
       virtual void GradFNV(Type *grad,const Type *   v) = 0;

       FoncNVarDer(INT NbVar);
       INT GradConj(Type *p,REAL ftol,INT ITMAX);


    protected :
       void NRGradFNV(const Type *,Type *);  // Just Recall ValFNV
       void GradConj(Type *p,REAL ftol,INT *iter,REAL *fret,INT ITMAX);

};

#endif
