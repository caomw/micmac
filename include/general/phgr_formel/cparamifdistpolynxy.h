#ifndef _ELISE_GENERAL_PHGR_FORMEL_CPARAMIFDISTPOLYNXY_H
#define _ELISE_GENERAL_PHGR_FORMEL_CPARAMIFDISTPOLYNXY_H

#include "general/sys_dep.h"

class cParamIFDistPolynXY : public cParamIntrinsequeFormel
{
      public :
          virtual std::string  NameType() const;
          virtual ~cParamIFDistPolynXY();

          cMultiContEQF      StdContraintes() ;
          void SetFige(int DegreMax);
	   ElDistortionPolynomiale DistCur() const;

	  friend class cSetEqFormelles;

	   CamStenope * CurPIF() ;
	   CamStenope * DupCurPIF();
	   cCamStenopeDistPolyn *  CurPIFPolyn();
	   virtual void    UpdateCurPIF();
	   void    NV_UpdateCurPIF();   // Non virtuel, pour appel constructeur
      private :
          cParamIFDistPolynXY(bool IsC2M,cCamStenopeDistPolyn *,cSetEqFormelles & aSet);
          cDistFormelPolXY  mDist;

	  cCamStenopeDistPolyn * mCurPIF;
          virtual  Pt2d<Fonc_Num> VDist(Pt2d<Fonc_Num>,int aKCam);
};

#endif
