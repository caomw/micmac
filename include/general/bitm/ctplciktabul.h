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
REAL  BicubicInterpolVal
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


          cTplCIKTabul(INT aNBBVal,INT aNBBResol,REAL aVal,eModeInterTabul = eTabulBicub);


          REAL     XofInd(INT Ind) {return Ind/REAL(mNbResol);}

          inline tTabulCIK     InterpolateVal(TypeEl *,INT Frac) const ;
          inline tTabulCIK     InterpolateDer(TypeEl *,INT Frac) const ;

          REAL     BicubValue(TypeEl ** aTab,const Pt2dr &  aP) const ;
          Pt3dr    BicubValueAndDer(TypeEl ** aTab,const Pt2dr &  aP) const ;

      bool OkForInterp(Pt2di aSz,Pt2dr aP) const;

          double GetVal(TypeEl ** aTab,const Pt2dr &  aP) const;
          int SzKernel() const;

       private :
          INT            mNbResol;
          INT            mNbVal;
          REAL           mNbVal2;
          Im2D<tTabulCIK,tTabulCIK>  mTV;
          tTabulCIK **       mDV;
          Im2D<tTabulCIK,tTabulCIK>  mTD;
          tTabulCIK **       mDD;
};

#endif
