#ifndef _ELISE_GENERAL_BITM_TYPEEL>_H
#define _ELISE_GENERAL_BITM_TYPEEL>_H

#include "general/sys_dep.h"

template <class TypeEl>
#ifndef _ELISE_GENERAL_BITM_CintERPOLBILINEAIRE_H
#define _ELISE_GENERAL_BITM_CintERPOLBILINEAIRE_H

#include "general/sys_dep.h"

class cInterpolBilineaire : public cInterpolateurIm2D<TypeEl>
{
     public :
         inline double  IL_GetVal(TypeEl ** aTab,const Pt2dr &  aP) const ;
         double GetVal(TypeEl ** aTab,const Pt2dr &  aP) const ;
         virtual int  SzKernel() const;
         virtual void  GetVals(TypeEl ** aTab,const Pt2dr *  aP,double *,int Nb) const;
   private :
};

#endif
