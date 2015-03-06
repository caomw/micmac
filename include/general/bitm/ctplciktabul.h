#ifndef _ELISE_GENERAL_BITM_TYPE>_H
#define _ELISE_GENERAL_BITM_TYPE>_H

#include "general/sys_dep.h"

template <class Type>
Pt3dr BicubicInterpol
      (const cCubicInterpKernel & aCIK,Type ** data,Pt2dr aP);
#ifndef _ELISE_GENERAL_BITM_TYPE>_H
#define _ELISE_GENERAL_BITM_TYPE>_H

#include "general/sys_dep.h"

template <class Type>
double_t  BicubicInterpolVal
      (const cCubicInterpKernel & aCIK,Type ** data,Pt2dr aP);



// EN FAIT cTplCIKTabul sert a tabuler d'autre interp que bicub
//

typedef enum
{
   eTabulBicub,
   eTabulMPD_EcartMoyen,
   eTabulMPD_EcartType,
   eTabul_Bilin
}
eModeInterTabul;


#ifndef _ELISE_GENERAL_BITM_TTABULCIK>_H
#define _ELISE_GENERAL_BITM_TTABULCIK>_H

#include "general/sys_dep.h"

template <class TypeEl,class tTabulCIK>
#ifndef _ELISE_GENERAL_BITM_CTPLCIKTABUL_H
#define _ELISE_GENERAL_BITM_CTPLCIKTABUL_H

#include "general/sys_dep.h"

class  cTplCIKTabul  : public cInterpolateurIm2D<TypeEl>
{
       public :
           // typedef typename El_CTypeTraits<TypeEl>::tBase tTabulCIK;
           // Nombre de bits pour le codage des valeurs et de la resol


          cTplCIKTabul(int aNBBVal,int aNBBResol,double_t aVal,eModeInterTabul = eTabulBicub);


          double_t     XofInd(int Ind) {return Ind/double_t(mNbResol);}

          inline tTabulCIK     InterpolateVal(TypeEl *,int Frac) const ;
          inline tTabulCIK     InterpolateDer(TypeEl *,int Frac) const ;

          double_t     BicubValue(TypeEl ** aTab,const Pt2dr &  aP) const ;
          Pt3dr    BicubValueAndDer(TypeEl ** aTab,const Pt2dr &  aP) const ;

      bool OkForInterp(Pt2di aSz,Pt2dr aP) const;

          double GetVal(TypeEl ** aTab,const Pt2dr &  aP) const;
          int SzKernel() const;

       private :
          int            mNbResol;
          int            mNbVal;
          double_t           mNbVal2;
          Im2D<tTabulCIK,tTabulCIK>  mTV;
          tTabulCIK **       mDV;
          Im2D<tTabulCIK,tTabulCIK>  mTD;
          tTabulCIK **       mDD;
};

#endif
