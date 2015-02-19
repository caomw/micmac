#ifndef _ELISE_GENERAL_PHGR_FORMEL_CCAMERAFORMELLE_H
#define _ELISE_GENERAL_PHGR_FORMEL_CCAMERAFORMELLE_H

#include "general/sys_dep.h"

class cCameraFormelle :  public cNameSpaceEqF ,
                         public cObjFormel2Destroy
{
     public :
          
          void PrepareEqFForPointIm(const cIncListInterv &,cElCompiledFonc *,const Pt2dr &,bool EqDroite,int aKCam);  // Transmet a Intrinseque
          ElAffin2D & ResiduM2C();


	  void     SetCurRot(const ElRotation3D & aR2CM);
          friend class cParamIntrinsequeFormel;

	  Pt3d<Fonc_Num>   DirRayonF(Pt2d<Fonc_Num>,int aKCam);
          Pt3d<Fonc_Num>   COptF();
	  virtual ~cCameraFormelle();
	  ElRotation3D     CurRot();

	  //
	  //
	  //  Ne refait pas le calcul a chaque fois, est memorise
	  //  dans mCameraCourante ; C'est CalcCameraCourante qui 
	  //  refait le calc
	  //
	  const CamStenope * CameraCourante() const;
	  CamStenope * NC_CameraCourante() ;

          bool SameIntr(const cCameraFormelle &) const;
          cRotationFormelle &       RF();
          cParamIntrinsequeFormel & PIF();

          cSetEqFormelles & Set();
          const std::string & Name() const;
          eModeContrRot  ModeRot() const;
	  void SetModeRot(eModeContrRot);

	  // static void GenAllCode();

	  // Le resultat est un point renvoyant le vecteur de residu
	  Pt2dr  AddAppui(Pt3dr aP,Pt2dr aPIm,REAL aPds);
	         // Donne le residu mais n'ajoute pas au systeme
	  Pt2dr  ResiduAppui(Pt3dr aP,Pt2dr aPIm);

	   Pt2dr  CorrigePFromDAdd(const Pt2dr & aP1,bool UseGrid,bool ModeDr);

           class cEqAppui ;
	   cEqAppui * AddFctrEqAppuisInc(bool aGenCode,bool Proj,bool isGL,bool wDist,bool EqDr);  // Initialise si nec le fcteur
	   cEqAppui * AddForUseFctrEqAppuisInc(bool aGenCode,bool Proj,bool wDist,bool IsEqDr);  // Initialise si nec le fcteur
	   cIncListInterv & IntervAppuisPtsInc(); 
	   Pt2dr AddEqAppuisInc(const Pt2dr & aPIm,double aPds, cParamPtProj &,bool IsEqDroite);
           virtual void Update_0F2D();
           void TestVB10(const std::string& aMes) const;
           void SetGL(bool aModeGL);
           // cMatr_Etat_PhgrF &  MatRGL(bool isP) ;     // Mode Gimbal Lock
           bool IsGL() const;

#ifndef _ELISE_GENERAL_PHGR_FORMEL_CEQAPPUI_H
#define _ELISE_GENERAL_PHGR_FORMEL_CEQAPPUI_H

#include "general/sys_dep.h"

	  class cEqAppui
	  {
		  public :
                      void PrepareEqFForPointIm(const Pt2dr &);  // Transmet a Camera Formelle
                      friend class cCameraFormelle;
                      cEqAppui
		      (
		           bool wDist,
		           bool isGL,
		           bool isProj,
		           bool isPTerrainFixe,
		           bool Comp,
			   cCameraFormelle &,
			   bool GenCode, 
                           bool IsEqDroite
                      );
		      void GenCode();
                      cIncListInterv & LInterv();

		      // Si P <0, n'ajoute pas au sys
		      Pt2dr Residu(Pt3dr aP1,Pt2dr aP2,REAL Pds);
		      Pt2dr ResiduPInc(Pt2dr aP2,REAL Pds,const cParamPtProj & aPPP);
		  private :

                      cCameraFormelle & mCam;
                      bool            mUseEqNoVar;
                      cIncListInterv  mLInterv;
		      bool            mIsPTerrainFixe;
		      std::string     mNameType;
		      std::string     mNameTerX;
		      std::string     mNameTerY;
		      std::string     mNameTerZ;
		      std::string     mNameStdScaleN;
		      cEqfP3dIncTmp * mEqP3I;

		      std::string     mNameImX;
		      std::string     mNameImY;

		      Pt3d<Fonc_Num>  mPTerrain;
		      Pt2d<Fonc_Num>  mPIm;
                      Fonc_Num         mFScN;
		      std::vector<Fonc_Num>        mEcarts;
                      cElCompiledFonc * mFoncEqResidu ;

		      double          * pAdrXTer;
		      double          * pAdrYTer;
		      double          * pAdrZTer;
		      double          * pAdrXIm;
		      double          * pAdrYIm;
		      double          * pAdrScN;

                      cP3d_Etat_PhgrF * mProjP0;
                      cP3d_Etat_PhgrF * mProjI;
                      cP3d_Etat_PhgrF * mProjJ;
                      cP3d_Etat_PhgrF * mProjK;
                      cMatr_Etat_PhgrF * mMatriceGL;

                      cP2d_Etat_PhgrF *  mNDP0;
                      cP2d_Etat_PhgrF *  mNDdx;
                      cP2d_Etat_PhgrF *  mNDdy;
                      bool               mEqDroite;

	  };
	  CamStenope *  DuplicataCameraCourante();
     private :
	  CamStenope *  CalcCameraCourante();
	  friend class cEqAppui;

          cCameraFormelle
          (
                 eModeContrRot,
                 ElRotation3D,
                 cParamIntrinsequeFormel &,
                 cCameraFormelle * CamAttach ,
		 const std::string & aName,
		 bool   CompEqAppui,
		 bool   GenCodeAppui,
                 bool   HasEqDroite
          );
          cCameraFormelle   *         pCamAttach;
          cParamIntrinsequeFormel &   mIntr;
          cSetEqFormelles &           mSet;
          cRotationFormelle *         mRot;
	  std::string                 mName;

          cEqAppui *                    mEqAppuiTerNoGL;
          cEqAppui *                    mEqAppuiTerGL;

          cEqAppui *                    mEqAppuiIncXY ;
          cEqAppui *                    mEqAppuiProjIncXY ;
          cEqAppui *                    mEqAppuiGLIncXY ;
          cEqAppui *                    mEqAppuiGLProjIncXY ;


          cEqAppui *                    mEqAppuiSDistIncXY ;
          cEqAppui *                    mEqAppuiSDistProjIncXY ;
          cEqAppui *                    mEqAppuiSDistGLIncXY ;
          cEqAppui *                    mEqAppuiSDistGLProjIncXY ;

          static const int TheNbEqDr = 8;
          cEqAppui *                    mEqAppuiDroite[TheNbEqDr] ; // Dist X Proj X Gl

	  CamStenope *                  mCameraCourante;


        // S'ajoute eventuellement a mGlobOrImaM2C pour  ResiduMond2Cam
         // permet de gerer les marques fiduciaire qui etant integre par modif
         // des points homols, n'interviennent pas dans la camera
         ElAffin2D                      mResiduM2C;
         bool                           mHasEqDroite;


};

#endif
