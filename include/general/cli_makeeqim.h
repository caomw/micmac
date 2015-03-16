#ifndef _ELISE_GENERAL_PHGR_FORMEL_CLI_MAKEEQIM_H
#define _ELISE_GENERAL_PHGR_FORMEL_CLI_MAKEEQIM_H



class cLI_MakeEqIm
{
      public :
	      friend class cEqVueLaserImage;
      private:
	      cLI_MakeEqIm
	      (
	           const std::string &      aPref,
		   cLIParam_Image &              anIm,
                   bool Normalize, // Si faux pas de normalisation Moy/Ect
		   int        aNbPts,
                   cRotationFormelle * aRotPts
	      );
	      Fonc_Num     FRad();
	      Fonc_Num              KthRad(int aK);
              void InitAdr(cElCompiledFonc *);
	      bool  InitEquations(std::vector<Pt3dr>,int Offset,const ElRotation3D &);


              struct  cPts
	      {
                    cPts
                    ( 
                          const std::string &   aPref,
                          int,
                          cRotationFormelle &,
                          cRotationFormelle * aRotPts
                    );
		    void InitAdr(cElCompiledFonc *);
		    Fonc_Num  RadiomOfP(Pt3d<Fonc_Num> aP);

	            cRotationFormelle &   mRotIm;
	            cRotationFormelle *   mRotPts;
		    cVarSpec  m0;
		    cVarSpec  mU;
		    cVarSpec  mV;
		    cVarSpec  mX;
		    cVarSpec  mY;
		    cVarSpec  mZ;
		    Fonc_Num  mRad;

		    double * mAdr0;
		    double * mAdrU;
		    double * mAdrV;
		    double * mAdrX;
		    double * mAdrY;
		    double * mAdrZ;
	      };


	      cLI_MakeEqIm(const cLI_MakeEqIm &); // NI
	      bool InitOneEquation(Pt3dr aP,cPts &,const ElRotation3D & aRot);

	      std::string           mPref;
	      cLIParam_Image &      mIm;
	      cRotationFormelle &   mRot;
	      std::vector<cPts*>    mIncPts;
	      Fonc_Num              mMoy;
	      Fonc_Num              mEct;
	      Fonc_Num              mRadC;
              ElMatrix<double_t>        mMat;
              bool                  mNormalize;
};

#endif
