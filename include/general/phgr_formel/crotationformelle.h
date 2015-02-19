#ifndef _ELISE_GENERAL_PHGR_FORMEL_CROTATIONFORMELLE_H
#define _ELISE_GENERAL_PHGR_FORMEL_CROTATIONFORMELLE_H

#include "general/sys_dep.h"

class cRotationFormelle : public cElemEqFormelle,
                          public cObjFormel2Destroy
{
	// Sauf eventuel cas contraire explicite,
	// toutes les rotations sont passees, memorisees
	// et stockees dans le sens Cam->Monde
	//
	// Donc si ca ne correspond pas une orientation de camera
	// C2M est le sens direct et M2C le sens reciproque
	public  :
          bool IsFiged() const;


          double AddRappelOnAngles(bool OnCur,int aK,double aTol,bool AddEq);
          double AddRappelOnAngles(bool OnCur,const std::list<int> & ,double aTol,bool AddEq);
          double AddRappelOnCentre(bool OnCur,Pt3dr aTol,bool AddEq) ;

          friend class cSetEqFormelles;
          cMultiContEQF      StdContraintes() ;
	  Pt3d<Fonc_Num>   C2M(Pt3d<Fonc_Num>,int  aKForceGL=-1);  // ImAff
	  Pt3d<Fonc_Num>   M2C(Pt3d<Fonc_Num>,int  aKForceGL=-1);

	  Pt3d<Fonc_Num>   VectM2C(Pt3d<Fonc_Num>,int  aKForceGL=-1);
	  Pt3d<Fonc_Num>   VectC2M(Pt3d<Fonc_Num>,int  aKForceGL=-1); // == ImVect
	  // Monde -> Cam
	  Pt3d<Fonc_Num>   ImVect(Pt3d<Fonc_Num>,int aKForceGL=-1);
          Pt3d<Fonc_Num>   COpt();
	  ElRotation3D     CurRot();
	  void     SetCurRot(const ElRotation3D & aR2CM);
	  ElRotation3D     CurRot(REAL aT);

	   ~cRotationFormelle();

           INT IndexeAllocationCOpt();
           // cRotationFormelle * RotAttach();
           eModeContrRot  ModeRot() const;
	   void SetModeRot(eModeContrRot);
           const std::string & Name() const;
	   virtual void SetValInitOnValCur();
	   Pt3dr  CurCOpt() const;
	   Pt3dr  CurCOpt(REAL aT) const;
           INT    Degre() const;

           const std::string & NameParamTime();
           void  SetFlagAnglFige(int aFlag);
	   void  SetTolAng(double);
	   void  SetTolCentre(double);

           Pt3dr AddRappOnCentre(const Pt3dr & aVal,const Pt3dr & aPds,bool WithDerSec);
           void ReactuFcteurRapCoU();

           // cMatr_Etat_PhgrF &  MatGL(bool) ;     // Mode Gimbal Lock
           void SetGL(bool aModeGL);
           const ElMatrix<Fonc_Num> & MatFGL(int ForceGL);
           ElMatrix<Fonc_Num>  MatFGLComplete(int ForceGL);
           const ElMatrix<REAL> &       MGL() const;
           bool IsGL() const;
           // void InitEtatGL(bool isP);
           int NumCentre(int aK) const;
           int NumTeta(int aK) const;
           void SetRotPseudoBaseU (cRotationFormelle *);
        private :
	   cElCompiledFonc *    FcteurRapCoU();
	   cRotationFormelle
           (
                eModeContrRot,
		ElRotation3D aRC2MInit,
                cSetEqFormelles &,
                cRotationFormelle *,  // Rotation de ratachement eventuelle
		const std::string & aName,
                INT   aDegre,            // Cas des parametre variables dans le temps
                                         // -1 correspond au cas non employe
                bool  aUseVraiBaseU
           );



           cPolynome1VarFormel  * AllocPol(REAL * ValCste);
           void AssertDegre0() const;


	   eModeContrRot mModeContr;
         

           std::string    mNameParamTime;
           cVarSpec       mVarTime;
           INT            mDegre;


	   REAL           mTeta01Init;
	   REAL           mTeta02Init;
	   REAL           mTeta12Init;

	   REAL           mCurTeta01;
	   REAL           mCurTeta02;
	   REAL           mCurTeta12;

           cPolynome1VarFormel * mPolTeta01;
           cPolynome1VarFormel * mPolTeta02;
           cPolynome1VarFormel * mPolTeta12;

	   Fonc_Num       mFTeta01;
	   Fonc_Num       mFTeta02;
	   Fonc_Num       mFTeta12;
           ElMatrix<Fonc_Num> mFMatr;
           ElMatrix<Fonc_Num> mFMatrInv;

	   Pt3dr          mCOptInit;
	   Pt3dr          mCurCOpt;
	   INT            mIndAllocCOpt;
           cPolynome1VarFormel * mPolCoptX;
           cPolynome1VarFormel * mPolCoptY;
           cPolynome1VarFormel * mPolCoptZ;
	   Pt3d<Fonc_Num> mFCOpt;

           cRotationFormelle *  pRotAttach;
           // Le pRotAttach est assez lourd et en gal inutile grace au nouveau mode
           // de controle par fixage d'une des var en mode pseudo  .. ; pour ne
           // pas interferer avec on rajoute
           cRotationFormelle *  pRotPseudoBaseU;
	   cElCompiledFonc *    mFcteurRapCoU;
	   std::string          mName;
           int                  mFlagAnglFig;

	   double                mTolAng;
	   double                mTolCentre;
           bool                  mModeGL;     // Mode Gimbal Lock
           // cMatr_Etat_PhgrF *    mSMatriceGL;     // Mode Gimbal Lock -Stantard
           // cMatr_Etat_PhgrF *    mPMatriceGL;     // Mode Gimbal Lock -Proj
           ElMatrix<REAL>        mMGL;
           bool                  mVraiBaseU;
};

#endif
