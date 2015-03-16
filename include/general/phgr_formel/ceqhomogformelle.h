#ifndef _ELISE_GENERAL_PHGR_FORMEL_CEQHOMOGFORMELLE_H
#define _ELISE_GENERAL_PHGR_FORMEL_CEQHOMOGFORMELLE_H



class cEqHomogFormelle : public  cNameSpaceEqF ,
                         public cEqFPtLiaison,
                         public cObjFormel2Destroy
{
      public :
          ~cEqHomogFormelle();
          cEqHomogFormelle
          (
                bool InSpaceInit, // Si true equation H1 H2-1
                cHomogFormelle &,
                cHomogFormelle &,
                cDistRadialeFormelle *,
		bool Code2Gen
          );

         // WithD2 : avec derivees secondes
          double_t AddLiaisonP1P2(Pt2dr P1,Pt2dr P2,double_t aPds,bool WithD2);
          Pt2dr StdAddLiaisonP1P2(Pt2dr P1,Pt2dr P2,double_t aPds,bool WithD2); // Version moderne type camera
	  double_t ResiduNonSigneP1P2(Pt2dr aP1,Pt2dr aP2);
	  Pt2dr  PtResidu(Pt2dr aP1,Pt2dr aP2);

          cHomogFormelle&       HF1();
          cHomogFormelle&       HF2();
          cDistRadialeFormelle& DistRF();
          cDistRadialeFormelle*   DRF();
          cSetEqFormelles &       Set();

          void StdRepondere(ElPackHomologue &,double_t aCoeff);
          void StdRepondere(double_t aCoeff);
          double_t MoyErreur(ElPackHomologue &);
          double_t MoyErreur();

      private :
          Pt2d<Fonc_Num> ComposeDRF (Pt2d<Fonc_Num> aP);
          struct cEq
          {
              cEqHomogFormelle & mEQF;
              cElCompiledFonc * pFEq;
              double          * pAdrX1;
              double          * pAdrY1;
              double          * pAdrX2;
              double          * pAdrY2;
              std::string     mName;

	      ~cEq();
              cEq(Fonc_Num F,cEqHomogFormelle &,bool isX,bool Code2Gen);
              double_t AddLiaisonP1P2(Pt2dr P1,Pt2dr P2,double_t aPds,bool WithD2);
	      double_t ResiduSigneP1P2(Pt2dr aP1,Pt2dr aP2);
          };
          friend struct cEq;

                          
          bool              mInSpaceInit;
          cSetEqFormelles & mSet;
          cHomogFormelle&       mHF1;
          cHomogFormelle&       mHF2;
          cDistRadialeFormelle* mDRF;

          Pt2d<Fonc_Num>        mEqHom;
          cIncListInterv        mLInterv;
          cEq*                  pFEqX;
          cEq*                  pFEqY;
};

#endif
