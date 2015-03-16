#ifndef _ELISE_GENERAL_PHGR_FORMEL_CCPLEGRIDEQ_H
#define _ELISE_GENERAL_PHGR_FORMEL_CCPLEGRIDEQ_H



class cCpleGridEq : public cNameSpaceEqF,
                    public cSignedEqFPtLiaison,
                    public cObjFormel2Destroy
{
      public :
          double_t AddLiaisonP1P2(Pt2dr P1,Pt2dr P2,double_t aPds,bool WithD2);
          double_t ResiduSigneP1P2(Pt2dr P1,Pt2dr P2); 

	  void   GenCode();
	  // static void   GenAllCode();
	  // static void   GenAllCode(eModeResidu);

         friend class cSetEqFormelles;


      private :


          void  SetP1P2(Pt2dr P1,Pt2dr P2); 
	  Fonc_Num   EqCoPlan();
          cCpleGridEq
          (
              cTriangulFormelle &, cRotationFormelle &,
              cTriangulFormelle &, cRotationFormelle &,
	      eModeResidu aModeResidu,
	      bool Code2Gen
          );
	  
	  static const std::string NamePdsA1;
	  static const std::string NamePdsA2;
	  static const std::string NamePdsA3;
	  static const std::string NamePdsB1;
	  static const std::string NamePdsB2;
	  static const std::string NamePdsB3;


	  cSetEqFormelles & mSet;
	  cTriangulFormelle &   mTriA;
	  cRotationFormelle &   mRotA;
	  cTriangulFormelle &   mTriB;
	  cRotationFormelle &   mRotB;
          cIncListInterv        mLInterv;
          cElCompiledFonc *     mFoncEqCoP;

          double          *     pAdrPdsA1;
          double          *     pAdrPdsA2;
          double          *     pAdrPdsA3;

          double          *     pAdrPdsB1;
          double          *     pAdrPdsB2;
          double          *     pAdrPdsB3;
	  eModeResidu           mModeResidu;
	  std::string           mNameType;
};

#endif
