#ifndef _ELISE_GENERAL_BITM_CCUBICintERPKERNEL_H
#define _ELISE_GENERAL_BITM_CCUBICintERPKERNEL_H

#include "general/sys_dep.h"

class cCubicInterpKernel : public cKernelInterpol1D
{
     public :
         double  Value(double x) const ;
         // double  SzKernel() const;
         double_t Derivee(double_t x) const;
         void ValAndDerivee(double_t x,double_t &V,double_t &D) const;
         // aA = valeur de la derivee en 0
         // si vaut -0.5, reconstitue parfaitement une droite
         // doit etre comprise en 0 et -3
         cCubicInterpKernel(double_t aA);
     private :
         double_t mA;
};

#endif
