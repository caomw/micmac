#ifndef _ELISE_GENERAL_PHGR_FORMEL_CTFI_ATTRSOM_H
#define _ELISE_GENERAL_PHGR_FORMEL_CTFI_ATTRSOM_H

#include "general/sys_dep.h"

class  cTFI_AttrSom
{
       public :
              

          // static cTFI_AttrSom * Som2D(cSetEqFormelles &,Pt2dr aPos,Pt2dr aVal);
	  cTFI_AttrSom (cSetEqFormelles &,Pt2dr aPosistion,const std::vector<double> & aVInit);



	  const cIncIntervale &   Interv() const;
	  int Dim() const;
	  const Pt2dr &                 PosPt() const;
	  const std::vector<Fonc_Num> & Incs() const;
	  const std::vector<double> &   ValsInc() const;

	  Pt2dr                   ValCurAsPt()  const;
	  Pt2d<Fonc_Num>          ValsIncAsPt()  const;


	  Fonc_Num   ValsIncAsScal() const;
	  Pt3dr  P3ValAsZ() const;

          void SetValCurPt(cSetEqFormelles & aSet,const Pt2dr &); // SetPCur
              
          cSetEqFormelles &     Set();
       private :
          void AssertD1() const;
          void AssertD2() const;


          cTFI_AttrSom(const cTFI_AttrSom &);

          cSetEqFormelles &     mSet;
	  cIncIntervale         mInterv;
          Pt2dr                 mPos;
	  std::vector<double>   mValsInc;
          int                   mNumInc;
	  int                   mDim;
	  std::vector<Fonc_Num> mIncs;

	  /*
          Pt2dr          mPtInit;
          Pt2dr          mPtCur;
          int            mNumInc;
          Pt2d<Fonc_Num> mPtInc;
	  */
};

#endif
