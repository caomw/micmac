#ifndef _ELISE_GENERAL_PHGR_FORMEL_CDISTRADIALEFORMELLE_H
#define _ELISE_GENERAL_PHGR_FORMEL_CDISTRADIALEFORMELLE_H

#include "general/sys_dep.h"

class cDistRadialeFormelle : public cElemEqFormelle,
                             public cObjFormel2Destroy
{
        public :

           friend class cSetEqFormelles;
           friend class cParamIFDistRadiale;
           Pt2d< Fonc_Num>  operator ()(Pt2d< Fonc_Num>);
           Pt2d<Fonc_Num>  FCentre() const;

           const ElDistRadiale_PolynImpair & DistInit() const;
           const ElDistRadiale_PolynImpair & DistCur() const;
           void ReinitDist(const ElDistRadiale_PolynImpair & );
           cMultiContEQF      StdContraintes() ;
	   void SetCentreFige(bool);
           void SetDegreFige(INT aDF,double aTol=cContrainteEQF::theContrStricte);

	   INT   IndCentre() const;

           cDistModStdPhpgr & DistCurStd();
           const cDistModStdPhpgr & DistCurStd() const;
           cDistModStdPhpgr & DistInitStd();
           const cDistModStdPhpgr & DistInitStd() const;

	   double RMax() const;
           void ActuRMax(CamStenope *,bool C2M);

	   void SetTolCDist(double aTol);
	   void SetTolCoeff(double aTol);

           bool IsFiged() const;


        protected :
	   void  AddContrCentre(cMultiContEQF & aContr);
	   void  AddContrCoeff(cMultiContEQF & aContr);

           cMultiContEQF   CentreFRapInit() ;
           cMultiContEQF   CoeffsRapInit(INT aCoef0);
           cDistRadialeFormelle
           (
                bool closeEEF,
	        bool isCFige,
		int aDegFig,
		const ElDistRadiale_PolynImpair &,
		cSetEqFormelles &,
                cCamStenopeModStdPhpgr * aDP = 0
	   );


	   bool                       mCentreFige;
	   INT                        mDegreFige;
           cDistModStdPhpgr           &mDistInitStd;
           cDistModStdPhpgr           &mCurDistStd;
	   ElDistRadiale_PolynImpair& mDistInit;
	   ElDistRadiale_PolynImpair& mCurDist;
	   INT                        mIndCentre;
           Pt2d<Fonc_Num>             mFCentre;
           std::vector<Fonc_Num>      mFCoeffs;

	   double                     mTolCDist;
	   double                     mTolCoeffs;
};

#endif
