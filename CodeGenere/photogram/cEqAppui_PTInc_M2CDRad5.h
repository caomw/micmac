// File Automatically generated by eLiSe
#include "general/all.h"
#include "private/all.h"


class cEqAppui_PTInc_M2CDRad5: public cElCompiledFonc
{
   public :

      cEqAppui_PTInc_M2CDRad5();
      void ComputeVal();
      void ComputeValDeriv();
      void ComputeValDerivHessian();
      double * AdrVarLocFromString(const std::string &);
      void SetScNorm(double);
      void SetXIm(double);
      void SetYIm(double);


      static cAutoAddEntry  mTheAuto;
      static cElCompiledFonc *  Alloc();
   private :

      double mLocScNorm;
      double mLocXIm;
      double mLocYIm;
};
