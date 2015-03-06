#ifndef _ELISE_GENERAL_PHGR_FORMEL_CPARAMIFDISTRADIALE_H
#define _ELISE_GENERAL_PHGR_FORMEL_CPARAMIFDISTRADIALE_H

#include "general/sys_dep.h"

class cParamIFDistRadiale : public cParamIntrinsequeFormel 
{
      public :

           bool IsDistFiged() const;
           friend class cSetEqFormelles;
	   virtual std::string  NameType() const;

           // La distortion est toujours ramenee a un degre 5
           const ElDistRadiale_PolynImpair & DistInit() const;
           const ElDistRadiale_PolynImpair & DistCur() const;

            cMultiContEQF  StdContraintes();

	   CamStenope * CurPIF() ;
	   CamStenope * DupCurPIF();
	   cCamStenopeDistRadPol  * CurPIFPolRad();
	   virtual void    UpdateCurPIF();
	   void    NV_UpdateCurPIF();   // Non virtuel, pour appel constructeur

            // L'option PP-CDist lie est exclusive des options
            // PP lie ou CDist lie
                    void  SetLibertePPAndCDist(bool,bool,double aTol=cContrainteEQF::theContrStricte);
                    void  SetCDistPPLie(double aTol=cContrainteEQF::theContrStricte);


           void SetDRFDegreFige(int aDF,double aTol=cContrainteEQF::theContrStricte);
	   virtual void SetValInitOnValCur();

      protected :

           cParamIFDistRadiale
           (
                bool isDC2M,
                cCamStenopeDistRadPol *,
                cSetEqFormelles&,
                int aDegFig,
                cCamStenopeModStdPhpgr * = 0
           );

            bool                    mCDistPPLie;
	    cElCompiledFonc *       mFoncEqPPCDistX;
	    cElCompiledFonc *       mFoncEqPPCDistY;

            virtual  Pt2d<Fonc_Num> VDist(Pt2d<Fonc_Num>,int aKCam);
            cDistRadialeFormelle    mDRF;
	    cCamStenopeDistRadPol * mCurPIF;
      private :
            virtual void  SetPPFree(bool);
};

#endif
