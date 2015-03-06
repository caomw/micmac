#ifndef _ELISE_GENERAL_PHGR_FORMEL_CEQELLIPSEIMAGE_H
#define _ELISE_GENERAL_PHGR_FORMEL_CEQELLIPSEIMAGE_H

#include "general/sys_dep.h"

class cEqEllipseImage : public cElemEqFormelle,
	                public cObjFormel2Destroy
{
      public :
          double_t GraySynt(double_t aX,double_t aY);
          double_t AddEq(double_t aX,double_t aY,double_t aGray,double_t Pds=1, bool WithD2=false);
	  Pt2dr CurCentre() const;
	  double_t  CurA() const;
	  double_t  CurB() const;
	  double_t  CurC() const;
	  double_t  CurLarg() const;
	  double_t  CurBlanc() const;
	  double_t  CurNoir() const;
	  bool OkCurEllispe() const;

	  void SetCentre(Pt2dr);
	  void SetA(double_t);
	  void SetB(double_t);
	  void SetC(double_t);
	  void SetLarg(double_t);
	  void SetBlanc(double_t);
	  void SetNoir(double_t);

          cMultiContEQF  ContrFigeABC();
          cMultiContEQF  ContrFigeLarg();

	  const cMirePolygonEtal & Mire() const;
	  // Si Fact > 1 donne ellipse plus grande
	  Box2dr  BoxCurEllipse(double_t Fact=1.0) const;
	  double_t SurfIER(Pt2dr aP,double_t Fact=1.0,double_t Larg=-1) const;

      private :
	  struct  cVarRay
	  {
		  cVarRay(int aNum);

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
             double_t  anA,
             double_t  aB,
             double_t  aC,
             double_t  aLarg,
             double_t  aBlanc,
             double_t  aNoir,
	     bool  Code2Gen
          );
	               
	      
	  const cMirePolygonEtal & mMire;
          std::string mNameType;
          cSetEqFormelles &       mEq;
          AllocateurDInconnues &  mAlloc;
	  int   mI0;
	  int   mIndCentre;
          Pt2dr mCentre;
          Pt2d<Fonc_Num> fCentre;
	  int      mIndA;
          double_t     mA;
          Fonc_Num fA;
	  int      mIndB;
          double_t     mB;
          Fonc_Num fB;
	  int      mIndC;
          double_t     mC;
          Fonc_Num fC;
	  int      mIndLarg;
          double_t     mLarg;
          Fonc_Num fLarg;
          Pt2d<Fonc_Num> fPLarg;
          std::string mNPX;
          std::string mNPY;


          Pt2d<Fonc_Num> fCPIX;
          Pt2d<Fonc_Num> fP0;
          Pt2d<Fonc_Num> fP1;
	  int       mIndBlanc;
          double_t      mBlanc;
          Fonc_Num  fBlanc;
	  int       mIndNoir;
          double_t      mNoir;
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
