#ifndef _ELISE_GENERAL_PHGR_FORMEL_CPARAMIFHOMOGR_H
#define _ELISE_GENERAL_PHGR_FORMEL_CPARAMIFHOMOGR_H

#include "general/sys_dep.h"

class cParamIFHomogr  : public cParamIntrinsequeFormel 
{ 
	public :
           friend class cSetEqFormelles;
	   void SetFigee();
	   void SetLibre();
	   void SetStdBloqueRot();
	   CamStenope * CurPIF() ;
	   CamStenope * DupCurPIF();
	   cCamStenopeDistHomogr *  CurPIFHom();
	   virtual void    UpdateCurPIF();
	   void    NV_UpdateCurPIF();   // Non virtuel, pour appel constructeur
	private  :
            cParamIFHomogr(bool isDC2M,cCamStenopeDistHomogr *,cSetEqFormelles &,eModeContrHom);
	    virtual ~cParamIFHomogr();
            virtual cMultiContEQF  StdContraintes();
	    virtual  std::string  NameType() const;
            virtual  Pt2d<Fonc_Num> VDist(Pt2d<Fonc_Num>,int aKCam);
            // virtual  Pt2d<Fonc_Num> DistM2C(Pt2d<Fonc_Num>);

	    cHomogFormelle *  mHF;
	    cCamStenopeDistHomogr * mCurPIF;
};

#endif
