#ifndef _ELISE_GENERAL_BITM_CSINCARDAPODintERPOL1D_H
#define _ELISE_GENERAL_BITM_CSINCARDAPODintERPOL1D_H

#include "general/sys_dep.h"

class cSinCardApodInterpol1D : public cKernelInterpol1D
{
      public :
         typedef  enum
         {
            eTukeyApod,
            eModePorte
         }  eModeApod;
         double  Value(double x) const ;
         cSinCardApodInterpol1D
         (
                eModeApod,
                double aSzK,
                double aSzApod,
                double aEpsilon=1e-3,
                bool   OnlyApod = false
         );
      private :
         eModeApod mModeApod;
         bool      mOnlyApod;
         double    mSzApod;
         double    mEpsilon;

};

#endif
