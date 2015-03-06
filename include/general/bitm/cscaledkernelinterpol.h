#ifndef _ELISE_GENERAL_BITM_CSCALEDKERNELintERPOL_H
#define _ELISE_GENERAL_BITM_CSCALEDKERNELintERPOL_H

#include "general/sys_dep.h"

class cScaledKernelInterpol :  public cKernelInterpol1D

{
      public :
         double  Value(double x) const ;
         cScaledKernelInterpol(const cKernelInterpol1D *,double ascale);
         ~cScaledKernelInterpol();
      private :
         const cKernelInterpol1D * mKer0;  // Adopte
         double                  mScale;
         double                  m1SurS;
};

#endif
