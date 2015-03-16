#ifndef _ELISE_GENERAL_BITM_TYPEEL>_H
#define _ELISE_GENERAL_BITM_TYPEEL>_H



template <class TypeEl>
#ifndef _ELISE_GENERAL_BITM_CintERPOLBICUBIQUE_H
#define _ELISE_GENERAL_BITM_CintERPOLBICUBIQUE_H



class cInterpolBicubique : public cInterpolateurIm2D<TypeEl>
{
     public :
         virtual double GetVal(TypeEl ** aTab,const Pt2dr &  aP) const ;
         virtual int  SzKernel() const;
         cInterpolBicubique(double_t aVal);  // -0.5 val par def (droite->droite)
   private :
        cCubicInterpKernel mCIK;
};

#endif
