#ifndef _ELISE_GENERAL_BITM_CCUBICINTERPKERNEL_H
#define _ELISE_GENERAL_BITM_CCUBICINTERPKERNEL_H

#include "general/sys_dep.h"

class cCubicInterpKernel : public cKernelInterpol1D
{
     public :
         double  Value(double x) const ;
         // double  SzKernel() const;
         REAL Derivee(REAL x) const;
         void ValAndDerivee(REAL x,REAL &V,REAL &D) const;
         // aA = valeur de la derivee en 0
         // si vaut -0.5, reconstitue parfaitement une droite
         // doit etre comprise en 0 et -3
         cCubicInterpKernel(REAL aA);
     private :
         REAL mA;
};

#endif
