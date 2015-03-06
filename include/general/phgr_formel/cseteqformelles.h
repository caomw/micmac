#ifndef _ELISE_GENERAL_PHGR_FORMEL_CSETEQFORMELLES_H
#define _ELISE_GENERAL_PHGR_FORMEL_CSETEQFORMELLES_H

#include "general/sys_dep.h"

class cSetEqFormelles : public cNameSpaceEqF
{
        public :


              //  Som Coef[K] X(Inde[K]) = B
              double AddEqEqualVar(double aPds,int aK1,int aK2,bool  AddEq);
              double AddEqLineaire (
                          double aPds, const std::vector<int>  &    indexe,
                          const std::vector<double>  & aCoeff,double aB);
              double ResiduEqLineaire (
                          double aPds, const std::vector<int>  &    indexe,
                          const std::vector<double>  & aCoeff,double aB);



              const std::vector<cIncIntervale *> &  BlocsIncAlloc() const;
              int NbBloc() const;
              void SetTmpBegun();
              void ShowVar() ;
              static void VerifC2MForPIF(bool isDC2M,CamStenope *);
              void SetPhaseEquation();
              // evite les duplicatas


              cGenSysSurResol * Sys();
	      cFormQuadCreuse*  FQC();  // Evtlt 0
              cEqFormelleLineaire * NewEqLin(int aNInc,int aNbVt,bool GenCode = false);
              cEqCorrelGrid * NewEqCorrelGrid(int aNbPix, bool Im2MoyVar, bool GenCode = false);
	      cEqCorrelGrid * ReuseEqCorrelGrid(int aNbPix, bool Im2MoyVar);


              // Valeur par defaut, correspondant ancienne
              // utilisation PosInit=0, 
              // 
              //   DMax en valeur relative de la boite englobante
              //
              cTriangulFormelle * NewTriangulFormelle
                                 ( int aDim,
				   const std::list<Pt2dr> &,double_t Dmax,
                                  ElDistortion22_Gen * PosInit= 0
                                  );
              cTriangulFormelle * NewTriangulFormelle
                                  ( int aDim,
				    Box2dr aBox,int aNb,double_t Dmax,
                                    ElDistortion22_Gen * PosInit= 0
                                  );
              cTriangulFormelle * NewTriangulFormelleUnitaire(int aDim);
              cCpleGridEq * NewCpleGridEq
              (
                  cTriangulFormelle &, cRotationFormelle &,
                  cTriangulFormelle &, cRotationFormelle &,
                  eModeResidu = eResiduCoplan,
		  bool Code2Gen=false
              );
	  

              ~cSetEqFormelles();
              cSetEqFormelles(eTypeSysResol = eSysPlein,int aNbEq=1);
              AllocateurDInconnues & Alloc();
              cHomogFormelle * NewHomF
		      (const cElHomographie &,
		       eModeContrHom aModeControle,
		       const std::string & = "");
              cHomogFormelle * GetHomFromName(const std::string &);
	      cCameraFormelle * GetCamFromName(const std::string &);
	      cRotationFormelle * GetRotFromName(const std::string &);


              cParamIFHomogr  * NewDistHomF(bool isDistC2M,cCamStenopeDistHomogr *,eModeContrHom);

              cDistRadialeFormelle * NewDistF(bool CloseEEF,bool isCFige,int aDegFig,
			                      const ElDistRadiale_PolynImpair &);
              cEqHomogFormelle * NewEqHomog
                         (
                             bool InSpaceInit,
                             cHomogFormelle &,
                             cHomogFormelle &,
                             cDistRadialeFormelle *,
			     bool Code2Gen = false
                         );
              cEqOneHomogFormelle * NewOneEqHomog
                         (
                             cHomogFormelle &,
			     bool Code2Gen = false
                         );




	       cParamIntrinsequeFormel * NewParamIntrNoDist(bool isDC2M,CamStenope * aCamInit,bool ParamVar=true);

               cBaseGPS * NewBaseGPS(const Pt3dr & aV0);
               cEqOffsetGPS * NewEqOffsetGPS(cRotationFormelle & aRF,cBaseGPS  &aBase,bool Code2Gen = false);
               cEqOffsetGPS * NewEqOffsetGPS(cCameraFormelle & aRF,cBaseGPS  &aBase);

               cEqObsBlockCam * NewEqBlockCal( cRotationFormelle & aRotRT0,
                                               cRotationFormelle & aRotLT0,
                                               cRotationFormelle & aRotRT1,
                                               cRotationFormelle & aRotLT1,
                                               bool                doGenerateCode
                                           );


	       cRotationFormelle * NewRotation
                                   (
                                        eModeContrRot,
		                        ElRotation3D aRC2MInit,
                                        cRotationFormelle *  = 0, // Rot Attach
		                        const std::string & aName = ""
                                   );

              cRotationFormelle * NewRotationEvol
                                  (
                                        ElRotation3D aRC2MInit,
                                        int aDegre,
                                        const std::string & aName = ""
                                  );

                cCpleCamFormelle *NewCpleCam
			         (
				      cCameraFormelle &,
				      cCameraFormelle &,
				      eModeResidu = eResiduCoplan,
				      bool Code2Gen=false
				 );

                cParamIFDistRadiale * NewIntrDistRad
                                      (
				           bool isDistC2M,
					   cCamStenopeDistRadPol *,
                                           int aDegFig
                                      );
		cParamIFDistPolynXY  * NewIntrPolyn(bool isDistC2M,cCamStenopeDistPolyn *);
                cParamIFDistStdPhgr * NewIntrDistStdPhgr
			              (bool isDistC2M,cCamStenopeModStdPhpgr *, int aDegFig);

                cPIF_Bilin *  NewPIFBilin(cCamStenopeBilin * aCSB);
                cParamIntrinsequeFormel *  AsPIF_NewPIFBilin(cCamStenopeBilin * aCSB); // Pour utiliser sans connaitre cPIF_Bilin


                cEqEllipseImage * NewEqElIm
                (
	           const cMirePolygonEtal &,
                   Pt2dr aCentre, double_t  anA, double_t  aB, double_t  aC,
                   double_t  aLarg, double_t  aBlanc, double_t  aNoir,
		   bool  Code2Gen = false
                );
                cAppuiGridEq * NewEqAppuiGrid
                (
                       cTriangulFormelle &,
                       cRotationFormelle &,
                       bool Code2Gen = false
                );
                cL2EqObsBascult  * NewEqObsBascult
                                   (
                                      const cSolBasculeRig &  aVInit,
                                      bool                    Cod2Gen
                                   );
             
              // dans phgr_cEqObsRotVect.cpp
                cEqObsRotVect * NewEqObsRotVect
                                (
                     // Si nulle, la rotation est allouee
                     // le seul cas envisage aujourd'hui une seule rot 1
                     // seule equation
                                    cRotationFormelle * aRot=0,
                                    bool Code2Gen = false
                                );
                cEqCalibCroisee * NewEqCalibCroisee
                                (
				    bool    SensC2M,
			            cParamIntrinsequeFormel & aPIF,
                                    cRotationFormelle * aRot=0,
                                    bool Code2Gen = false
				);
                cEqDirecteDistorsion * NewEqDirecteDistorsion
                                       (
			                   cParamIntrinsequeFormel & aPIF,
                                           eTypeEqDisDirecre   Usage,
                                           bool Code2Gen = false
				       );

                 cEqPlanInconnuFormel * NewEqPlanIF(cTFI_Triangle * aTri,bool Code2Gen);
                 cEqPlanInconnuFormel * NewEqPlanIF(const Pt3dr &aP0,const Pt3dr &aP1,const Pt3dr &aP2);
		 cTFI_AttrSom *         AttrP3(const Pt3dr &aP0);

		// VALEURS INIT BIDON , car souvent usage multiple
		// du meme objet, donc initialise
                cEqEllipseImage * NewEqElIm(const cMirePolygonEtal &,bool  Code2Gen = false);
	               



		cLIParam_Image *  NewLIParamImage
                                 (
                                    Im2D_double_t4 anIm,
                                    double_t  aZoom,
                                    CamStenope & aCam,
                                    cNameSpaceEqF::eModeContrRot
                                 );
		cEqVueLaserImage * NewLIEqVueLaserIm
                                   ( cRotationFormelle * aRotPts,
			             bool Multi,
			             bool Normalize,
				     int aNbPts,
				     cLIParam_Image &,cLIParam_Image &,
				     bool GenCode = false);
	               

                cCylindreRevolFormel & AllocCylindre
                                       (
                                         const  cCylindreRevolution &,
				         bool GenCode = false
                                       );
	               
		// Par defaut, centre figee, PP fige, foc fige


              void AddFonct(cElCompiledFonc *);
              void SolveResetUpdate(double aExpectedResidu=-1,bool *OK=0);
              void Solve(double aExpectedResidu,bool *OK);
              void ResetUpdate(double aLambda);  // aLambda "absicse" sur le droite de grad
              void SetSol(double aLambda);
              void DebugResetSys();

              void SetClosed();
              void AssertClosed();
              void AssertUnClosed();
              bool IsClosed() const;


	  void AddContrainte(const cContrainteEQF &,bool Strictes);
	  void AddContrainte(const cMultiContEQF &,bool Strictes);

	  // VAddEqFonctToSys est la plus utile,
	  // AddEqFonctToSys est connservee pour compatibilite

	  const std::vector<double_t> & VAddEqFonctToSys
               (
                  cElCompiledFonc * aFonct,
                  const std::vector<double> & aVPds,
                  bool WithDerSec
               );
	  const std::vector<double_t> & VAddEqFonctToSys
               (
                  cElCompiledFonc * aFonct,
                  double_t aPds,
                  bool WithDerSec
               );



          double_t AddEqFonctToSys
               (
                  cElCompiledFonc * aFonct,
                  double_t aPds,
                  bool WithDerSec
               );

	   const std::vector<double_t> & AddEqIndexeToSys
		                     (  
                                         cElCompiledFonc * aFonct,
                                         double_t aPds,const std::vector<int>  & VIncs
				     );
	  
          double_t ResiduSigne ( cElCompiledFonc * aFonct);
	  const std::vector<double_t> & VResiduSigne ( cElCompiledFonc * aFonct);


          double_t AddEqFonctToSys
               (
                  const tContFcteur &,
                  double_t aPds,
                  bool WithDerSec
               );

          void Reinit(int k0,int k1);
          void AddElem(cElemEqFormelle & anEq);
          void  AddObj2Kill(cObjFormel2Destroy *);

	//  Gestion des subsitutions
          cEqfP3dIncTmp * Pt3dIncTmp( );

          void AddABlocAlloc(cIncIntervale *);
           // return le Bloc avec le bon intervalle
          cSsBloc GetBlocOfI0Alloc(int aI0Alloc,int aI1Alloc) const;
          cSsBloc GetBlocOfI0Alloc(const cIncIntervale & aBl) const;
          // cSsBloc GetBlocOfI0(const cIncIntervale & aBl) const;
          int    GetNumBlocInclusIAlloc(int anI) const;
          cIncIntervale *  GetIntervInclusIAlloc(int anI) const;

          int   Alloc2Solve(const int aK){return mMOI.Alloc2Solve()[aK];}
          void TestPbFaisceau(bool doCheck,bool doSVD,bool doV0);
        private :
           Im1D_double_t8 ReordonneSol(Im1D_double_t8 aIm);
           void NumeroteBloc();


           cEqCorrelGrid * NewEqCorrelGridGen
		              (int aNbPix, bool Im2MoyVar, bool GenCode,bool Reuse);
	  friend class cParamIntrinsequeFormel;  // pour AddCamFormelle
          void  AddCamFormelle(cCameraFormelle  *,const std::string &);


          void SetPtCur(const double * aPt);
          void UpdateFctr();
          AllocateurDInconnues  & mAlloc;
          tContFcteur             mLFoncteurs;
          int                     mNbVar;
          // L2SysSurResol *      mSys;
          cGenSysSurResol *       mSys;
	  cFormQuadCreuse*        mFQC;
          bool                    mClosed;
          cDicoHomogSEF &         mDicHom;
	  cDicoCameraSEF &        mDicCam;
	  cDicoRotSEF &           mDicRot;
          cDicoEqCorrGrid &       mDicEqCorGrid; 
          // cDicoEqHomogSEF *       mDicEqHom;

          std::list<cObjFormel2Destroy *> mLobj2Kill;
	  eTypeSysResol mTypeSys;
          int   mEstimNbEq;

	   cRotationFormelle * NewRotationGen
                               (
                                        eModeContrRot,
		                        ElRotation3D aRC2MInit,
                                        cRotationFormelle *  , // Rot Attach
		                        const std::string & aName ,
                                        int   aDegre,
                                        bool aVraiBaseU
                               );

          cEqfP3dIncTmp  *  mPt3dIncTmp;
          bool              mTmpBegun;
          int               mIndIncTmp;
	  // Sert, avant un solve a mettre a Id les coeffs
	  std::list<cEqfBlocIncTmp *>  mLBlocTmp;
          std::list<cElemEqFormelle *>  mLEEF;


          std::vector<cIncIntervale *>  mBlocsIncAlloc;
          // std::vector<cIncIntervale *>  mBlocsIncSolve;
          std::vector<int>              mI02NblAlloc;
          // std::vector<int>              mI02NblSolve;

          // std::vector<int>              mAlloc2Solve;
          // std::vector<int>              mSolve2Alloc;
          cManipOrdInc                  mMOI;
          Im1D_double_t8                    mSolQuad;
          Im1D_double_t8                    mCurSol;


          cSetEqFormelles(const cSetEqFormelles &); // N.I.
          cSetEqFormelles operator = (const cSetEqFormelles &); // N.I.
};

#endif
