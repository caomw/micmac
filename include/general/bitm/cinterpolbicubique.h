#ifndef _ELISE_GENERAL_BITM_TYPEEL>_H
#define _ELISE_GENERAL_BITM_TYPEEL>_H

#include "general/sys_dep.h"

template <class TypeEl>
#ifndef _ELISE_GENERAL_BITM_CINTERPOLBICUBIQUE_H
#define _ELISE_GENERAL_BITM_CINTERPOLBICUBIQUE_H

#include "general/sys_dep.h"

class cInterpolBicubique : public cInterpolateurIm2D<TypeEl>
{
     public :
         virtual double GetVal(TypeEl ** aTab,const Pt2dr &  aP) const ;
         virtual int  SzKernel() const;
         cInterpolBicubique(REAL aVal);  // -0.5 val par def (droite->droite)
   private :
        cCubicInterpKernel mCIK;
};

#endif
