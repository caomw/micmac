#ifndef _ELISE_GENERAL_PHGR_FORMEL_CEQELLIPSEIMAGE_H
#define _ELISE_GENERAL_PHGR_FORMEL_CEQELLIPSEIMAGE_H

#include "general/sys_dep.h"

class cEqEllipseImage : public cElemEqFormelle,
	                public cObjFormel2Destroy
{
      public :
          REAL GraySynt(REAL aX,REAL aY);
          REAL AddEq(REAL aX,REAL aY,REAL aGray,REAL Pds=1, bool WithD2=false);
	  Pt2dr CurCentre() const;
	  REAL  CurA() const;
	  REAL  CurB() const;
	  REAL  CurC() const;
	  REAL  CurLarg() const;
	  REAL  CurBlanc() const;
	  REAL  CurNoir() const;
	  bool OkCurEllispe() const;

	  void SetCentre(Pt2dr);
	  void SetA(REAL);
	  void SetB(REAL);
	  void SetC(REAL);
	  void SetLarg(REAL);
	  void SetBlanc(REAL);
	  void SetNoir(REAL);

          cMultiContEQF  ContrFigeABC();
          cMultiContEQF  ContrFigeLarg();

	  const cMirePolygonEtal & Mire() const;
	  // Si Fact > 1 donne ellipse plus grande
	  Box2dr  BoxCurEllipse(REAL Fact=1.0) const;
	  REAL SurfIER(Pt2dr aP,REAL Fact=1.0,REAL Larg=-1) const;

      private :
	  struct  cVarRay
	  {
		  cVarRay(INT aNum);

		  cVarSpec    mFRay;
		  double *    mAdrVar;

	  };

          void GenCode();
          friend class  cSetEqFormelles ;
          cEqEllipseImage
          (
             cSetEqFormelles &,
	     const cMirePolygonEtal &,
             Pt2dr aCentre,
             REAL  anA,
             REAL  aB,
             REAL  aC,
             REAL  aLarg,
             REAL  aBlanc,
             REAL  aNoir,
	     bool  Code2Gen
          );
	               
	      
	  const cMirePolygonEtal & mMire;
          std::string mNameType;
          cSetEqFormelles &       mEq;
          AllocateurDInconnues &  mAlloc;
	  INT   mI0;
	  INT   mIndCentre;
          Pt2dr mCentre;
          Pt2d<Fonc_Num> fCentre;
	  INT      mIndA;
          REAL     mA;
          Fonc_Num fA;
	  INT      mIndB;
          REAL     mB;
          Fonc_Num fB;
	  INT      mIndC;
          REAL     mC;
          Fonc_Num fC;
	  INT      mIndLarg;
          REAL     mLarg;
          Fonc_Num fLarg;
          Pt2d<Fonc_Num> fPLarg;
          std::string mNPX;
          std::string mNPY;


          Pt2d<Fonc_Num> fCPIX;
          Pt2d<Fonc_Num> fP0;
          Pt2d<Fonc_Num> fP1;
	  INT       mIndBlanc;
          REAL      mBlanc;
          Fonc_Num  fBlanc;
	  INT       mIndNoir;
          REAL      mNoir;
          Fonc_Num  fNoir;
          std::string mNGR;
          Fonc_Num    fGray;
	  std::vector<cVarRay>    mVarsRays;
          Fonc_Num    fNumEqResidu;
          cElCompiledFonc * mFctrEqResidu;
          cIncListInterv    mLInterv;
          double *          pAdrX;
          double *          pAdrY;
          double *          pGray;
	            
          // static const int theNbDiam = 7;
          // static double theDiams[theNbDiam];
          
	  std::vector<cVarRay>  VarsRays();
          Fonc_Num              EqResidu();
};

#endif
