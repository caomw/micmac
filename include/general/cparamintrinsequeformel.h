#ifndef _ELISE_GENERAL_PHGR_FORMEL_CPARAMintRINSEQUEFORMEL_H
#define _ELISE_GENERAL_PHGR_FORMEL_CPARAMintRINSEQUEFORMEL_H



class cParamIntrinsequeFormel : public cElemEqFormelle,
                                public cObjFormel2Destroy
{
	public  :
           // certaine camera (par exe de type grid def) ont besoin de "changer l'état" des equations ou
           // elle interviennet notamment sur la numeroration  dans les inconnues des variable
           virtual void PrepareEqFForPointIm(const cIncListInterv &,cElCompiledFonc *,const Pt2dr &,bool EqDroite,int aKCam); 

           // Avant il y avait en dur :   mLInterv.AddInterv(mCam.PIF().IncInterv());
           // Pour prendre en compte les camera grilles avec des intervalles d'inconnues non connexes
           // (et evolutif) on ajoute cette fonction virtuelle qui pemet de specialiser
           virtual void AddToListInterval( cIncListInterv &);


           bool UseAFocal() const;
           bool   AllParamIsFiged() const;
           virtual bool IsDistFiged() const;
           friend class cSetEqFormelles;
	   virtual ~cParamIntrinsequeFormel();

           void Update_0F2D();
	   virtual CamStenope * CurPIF();
	   virtual CamStenope * DupCurPIF();
	   virtual void    UpdateCurPIF();
	   void    NV_UpdateCurPIF();   // Non virtuel, pour appel constructeur

           double StdScaleN() const;
           double StdScaleNNoGrid() const;
	   CamStenope * CamInit();  // Utilisee pour pre-corriger les distortions
           cCamStenopeGrid * CamGrid();
           void              UpdateCamGrid( double aTol );

	   virtual  std::string  NameType() const;
	    // Direction rayon ,  Cam->Monde
            Pt3d<Fonc_Num>   Cam2DirRayMonde(Pt2d<Fonc_Num>,int aKCam);
	    Pt3d<Fonc_Num>   CorrDist2DirRayMonde(Pt2d<Fonc_Num> aP);
	    Pt2d<Fonc_Num>   DirRayMonde2CorrDist(Pt3d<Fonc_Num> aP);
	    Pt2d<Fonc_Num>   DirRayMonde2Cam(Pt3d<Fonc_Num> aP,int aKCam);

             virtual Fonc_Num  NormGradC2M(Pt2d<Fonc_Num>);
             virtual bool UseSz() const;
	    // DOIT se CHARGER DE Foc et PP si necessaire


            cCameraFormelle * NewCam
                              (
                                   eModeContrRot,
                                   ElRotation3D,
                                   cCameraFormelle *  = 0, // Cam Att,
				   const std::string &  aName = "",
				   bool  CompEqAppui = false,
				   bool  GenCodeAppui = false,
                                   bool  HasEqDroite  = false
                              );

            double_t  CurFocale() const;
            Pt2dr CurPP() const;
            const tParamAFocal  & CurAFoc() const;
            virtual cMultiContEQF  StdContraintes();

            void  SetFocFree(bool);
            void  SetFocFigee(double aTol);

            void  SetAF1Free(bool);
            void  SetAF2Free(bool);
            virtual void  SetPPFree(bool);
            void  SetPPFFige(double aTol);


	    int IndPP() const;
	    // Lorsque le PIF possede des variables d'etats et que plusieurs PIF sont
	    // impliques dans une equation, il importe de pouvoir distinguer les variables,
	    // d'ou le role de KCam
	    
            Pt2d<Fonc_Num> DistC2M(Pt2d<Fonc_Num>,int aKCam);
            Pt2d<Fonc_Num> DistM2C(Pt2d<Fonc_Num>,int aKCam);
	    bool  DistIsC2M() const;


	    Pt2d<Fonc_Num> FPP();
	    Fonc_Num       FFoc();

	    virtual void InitStateOfFoncteur(cElCompiledFonc *,int aKCam);

	    Pt2dr  CorrigePFromDAdd(const Pt2dr & aP1,bool UseGrid);


            // Nom horrible coherent avec un usage prohibee en dehors du cas tres particulier de
	    // la conversion de format; on utilise la distorsion dans le sens M->C ce qui est
	    // contraire aux usages d'Elise
	    //
	    // Rajoute un Z nul uniquement pour la compat avec ce qui a ete fait dans le sens standard
	    // C2M de cEqCalibCroisee
	    //
            // Pt2d<Fonc_Num>   DirCam_2_PtCam_AssumingDistDirecte(Pt3d<Fonc_Num>,int aKCam);


            void AssertNoAFocalParam(const std::string &);
            void AddRapViscosite(double aTol);


        protected :

            // Par defaut focale et PP sont figes
	    // Ne fait pas "Close", doit etre fait pres construction
	    // des derives, donc est fait par l'allocateur static
	    // de cSetEqFormelles
            cParamIntrinsequeFormel
		    (
                         bool isDC2M,
		         CamStenope *,
			 cSetEqFormelles &,
			 bool ParamVar
                   );

            // Dist Cam->Monde, Def = Id


             bool                       isDistC2M;
             bool                       isFocaleFree;
             bool                       isPPFree;

             bool                       isAFoc1Free;
             bool                       isAFoc2Free;

	     CamStenope *               mCamInit;
	     CamStenopeIdeale *         mCurPIF;
             cCamStenopeGrid *          mCamGrid;
             bool                       mFiged;
             double                     mRayonGrid;
             double_t                       mFocaleInit;
	     double_t                       mCurFocale;
	     Pt2dr                      mPPInit;
	     Pt2dr                      mCurPP;
             tParamAFocal               mAFocInit;
             tParamAFocal               mCurAFoc;
	     Fonc_Num                   mFFoc;
	     int                        mIndPP;
	     Pt2d<Fonc_Num>             mFPP;
	     int                        mIndAF;
             std::vector<Fonc_Num>      mFAFoc;
             bool                       mParamVar;
	     double                     mTolFoc;
	     double                     mTolPP;
	     double                     mTolAF1;
	     double                     mTolAF2;
             ElProjStenopeGen<Fonc_Num> mProjStenF;
      private :
            virtual  Pt2d<Fonc_Num> VDist(Pt2d<Fonc_Num>,int aKCam);
};

#endif
