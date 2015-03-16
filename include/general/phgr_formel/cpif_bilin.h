#ifndef _ELISE_GENERAL_PHGR_FORMEL_CPIF_BILIN_H
#define _ELISE_GENERAL_PHGR_FORMEL_CPIF_BILIN_H



class cPIF_Bilin : public cParamIntrinsequeFormel
{
     public :
         cPIF_Bilin(cCamStenopeBilin *,cSetEqFormelles &);
         static cPIF_Bilin * Alloc(const cPIF_Bilin &,cSetEqFormelles &);

         void SetDistFigee();
         void SetDistFree(int aDegree);

     private  :
          // virtual Fonc_Num  NormGradC2M(Pt2d<Fonc_Num>); a priori inutile
          virtual void PrepareEqFForPointIm(const cIncListInterv &,cElCompiledFonc *,const Pt2dr &,bool EqDroite,int aKCam);
          virtual  Pt2d<Fonc_Num> VDist(Pt2d<Fonc_Num>,int aKCam);
          void    NV_UpdateCurPIF();   // Non virtuel, pour appel constructeur ????
          virtual void    UpdateCurPIF();
          virtual bool IsDistFiged() const;
          virtual std::string  NameType() const;
          virtual ~cPIF_Bilin();
          virtual CamStenope * CurPIF(); ;
          virtual CamStenope * DupCurPIF(); ;
          virtual cMultiContEQF  StdContraintes();

          virtual void AddToListInterval(cIncListInterv & aLInterv);
          // virtual bool UseSz() const; ==> A priori 
/*




*/

          cSomBilin & FDist(const Pt2di & aP);

       // ==============================================
          static const std::string TheNameType ;
       // ==============================================
          cSetEqFormelles &                            mSet;
          std::vector<cP2d_Etat_PhgrF>                 mCornF; // Size 8, pour eventuelleme,t gerer aKCam=1
          bool                                         mFiged;
          int                                          mDegreFree;
          cDistorBilin                                 mDistInit;
          cDistorBilin                                 mDistCur;
          cCamStenopeBilin *                           mCurPIF;
          // std::vector<Pt2d<Fonc_Num>  >                mFVDist;
          std::vector<std::vector<cSomBilin > >        mFVDist;
          std::vector<std::vector<cQuadrangle > >      mQuads;

          std::vector<cElCompiledFonc* >               mFctrRegul;

          // Index des deux point qui doivent etre figee arbirtairemnt pour fixer PP,Focale, Rotation
          // situes sur les extre de la ligne horiz coupant la capteur en 2
          int                                          mIndFrozen0;
          int                                          mIndFrozen1;

          Pt2di                                        mLastCase;
          // cIncListInterv                               mLInterv;
          // cCamStenopeBilin                             
};

#endif
