// File Automatically generated by eLiSe
#include "StdAfx.h"


class cEqAppui_PTInc_M2CCamBilin: public cElCompiledFonc
{
   public :

      cEqAppui_PTInc_M2CCamBilin();
      void ComputeVal();
      void ComputeValDeriv();
      void ComputeValDerivHessian();
      double * AdrVarLocFromString(const std::string &);
      void SetPts0_x(double);
      void SetPts0_y(double);
      void SetPts1_x(double);
      void SetPts2_y(double);
      void SetScNorm(double);
      void SetXIm(double);
      void SetYIm(double);


      static cAutoAddEntry  mTheAuto;
      static cElCompiledFonc *  Alloc();
   private :

      double mLocPts0_x;
      double mLocPts0_y;
      double mLocPts1_x;
      double mLocPts2_y;
      double mLocScNorm;
      double mLocXIm;
      double mLocYIm;
};
