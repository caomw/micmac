#ifndef _ELISE_GENERAL_PHGR_FORMEL_CPARAMIFDISTSTDPHGR_H
#define _ELISE_GENERAL_PHGR_FORMEL_CPARAMIFDISTSTDPHGR_H



class cParamIFDistStdPhgr : public cParamIFDistRadiale 
{
	public :
            friend class cSetEqFormelles;
	    virtual std::string  NameType() const;
            cMultiContEQF  StdContraintes();
	    cDistModStdPhpgr & CurDist();
	    const cDistModStdPhpgr & CurDist() const;

	   CamStenope * CurPIF() ;
	   CamStenope * DupCurPIF();
	   cCamStenopeModStdPhpgr *  CurPIFStdPhgr();
	   virtual void    UpdateCurPIF();
	   void    NV_UpdateCurPIF();   // Non virtuel, pour appel constructeur

	   void SetParam_Aff_Fige(double aTol=cContrainteEQF::theContrStricte);
	   void SetParam_Dec_Fige(double aTol=cContrainteEQF::theContrStricte);

	   void SetParam_Aff_Free();
	   void SetParam_Dec_Free();

           bool IsDistFiged() const;

	private :
           virtual  Pt2d<Fonc_Num> VDist(Pt2d<Fonc_Num>,int aKCam);
           cParamIFDistStdPhgr(bool isDC2M,cCamStenopeModStdPhpgr *,cSetEqFormelles &,int aDegFig);

	   cDistModStdPhpgr &      mDStd;
	   cDistModStdPhpgr &      mInitDStd;

	   bool                    mParamDecentreFree;
	   bool                    mParamAffineFree;

	   Fonc_Num                mFP1;
	   Fonc_Num                mFP2;
	   Fonc_Num                mFb1;
	   Fonc_Num                mFb2;
	   double                  mTol_Dec_PhgStdPIF;
	   double                  mTol_Aff_PhgStdPIF;
	   cCamStenopeModStdPhpgr * mCurPIF;
};

#endif
