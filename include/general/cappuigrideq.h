#ifndef _ELISE_GENERAL_PHGR_FORMEL_CAPPUIGRIDEQ_H
#define _ELISE_GENERAL_PHGR_FORMEL_CAPPUIGRIDEQ_H



class cAppuiGridEq : public cNameSpaceEqF,
                     public cObjFormel2Destroy
{
     public :
	  void   GenCode();
	  Pt2dr  AddAppui(Pt3dr aP,Pt2dr aPIm,double_t aPds);
	         // Donne le residu mais n'ajoute pas au systeme
	  Pt2dr  ResiduAppui(Pt3dr aP,Pt2dr aPIm);

     private  :
          cAppuiGridEq
          (
              cTriangulFormelle &, 
	      cRotationFormelle &,
	      bool Code2Gen
	  );
         friend class cSetEqFormelles;
	 Pt2d<Fonc_Num>        ResiduForm();

	 static const std::string NamePds1;
	 static const std::string NamePds2;
	 static const std::string NamePds3;
	 static const std::string NameTerX;
	 static const std::string NameTerY;
	 static const std::string NameTerZ;

	 cSetEqFormelles &     mSet;
	 cTriangulFormelle &   mTri;
	 cRotationFormelle &   mRot;
         double          *     pAdrPds1;
         double          *     pAdrPds2;
         double          *     pAdrPds3;
         double          *     pAdrXTer;
         double          *     pAdrYTer;
         double          *     pAdrZTer;
         cIncListInterv        mLInterv;
         cElCompiledFonc *     mFoncEq;
	 std::string           mNameType;
};

#endif
