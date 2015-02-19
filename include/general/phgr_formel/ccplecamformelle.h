#ifndef _ELISE_GENERAL_PHGR_FORMEL_CCPLECAMFORMELLE_H
#define _ELISE_GENERAL_PHGR_FORMEL_CCPLECAMFORMELLE_H

#include "general/sys_dep.h"

class cCpleCamFormelle : public cNameSpaceEqF,
                         public cSignedEqFPtLiaison,
                         public cObjFormel2Destroy
{
     public :

          friend class cSetEqFormelles;
	  static void GenAllCode();
         // WithD2 : avec derivees secondes
          REAL AddLiaisonP1P2(Pt2dr P1,Pt2dr P2,REAL aPds,bool WithD2);

          REAL ResiduSigneP1P2(Pt2dr P1,Pt2dr P2); 
	  // Pondere en 1 / (1+ square(Residu/Ecart))
	  // Si Residu > Coupure > 0 , poids = 0


          cCameraFormelle & Cam1();
          cCameraFormelle & Cam2();
       
	  ~cCpleCamFormelle();

	  void CorrigeP1P2FromDAdd(Pt2dr & aP1,Pt2dr & aP2);
     private :

	  void GenCode();
          cCpleCamFormelle
	  (
              cCameraFormelle & aCam1,
              cCameraFormelle & aCam2,
	      eModeResidu,
	      bool Code2Gen
          );

          cCameraFormelle & mCam1;
          cCameraFormelle & mCam2;
          cSetEqFormelles & mSet;
          Pt3d<Fonc_Num>    mBaseNN;
          Pt3d<Fonc_Num>    mBaseU;
          cIncListInterv    mLInterv;
	  eModeResidu       mModeResidu;
	  Fonc_Num          mEqResidu;
	  std::string       mNameType;

          cElCompiledFonc * mFoncEqResidu ;
          double          * pAdrX1;
          double          * pAdrY1;
          double          * pAdrX2;
          double          * pAdrY2;
};

#endif
