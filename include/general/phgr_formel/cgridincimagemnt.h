#ifndef _ELISE_GENERAL_PHGR_FORMEL_CGRIDINCIMAGEMNT_H
#define _ELISE_GENERAL_PHGR_FORMEL_CGRIDINCIMAGEMNT_H

#include "general/sys_dep.h"

class cGridIncImageMnt  : public cObjFormel2Destroy
{
	public :
             cGridIncImageMnt
		     (
		          Pt2di    aSzI1,
			  Fonc_Num fZCur,
		          Fonc_Num fHomZ0,
		          Fonc_Num fDzHom,
			  Fonc_Num fI1,
		          Pt2di    aSzI2,
			  Fonc_Num fI2
		     );

	     static  cGridIncImageMnt * StdFromFile(const std::string &  aPref);

	     void MakeI2G1();

	     Flux_Pts  All1();
	     Flux_Pts  All2();
	     Fonc_Num  fHomOfZ0();
             Fonc_Num  fDerZ();
             Fonc_Num  fHomOfZ(Fonc_Num fZ);
	     Fonc_Num  fHomOfCurZ();
	     Fonc_Num  fI2GeoI1();
	     Fonc_Num  fSupI1I2();
	     void SauvAll(const std::string & aPrefix);

	     void OneStepEqCorrel(REAL aPds,INT aSzVgn,bool Im2Var,INT anEcart=1);
	     void OneStepRegulD2 (REAL aPds);
	     void OneStepRegulD1 (REAL aPds);
	     void OneStepRapCur  (REAL aPds);

	     void SolveSys();
	     void InitIncs(REAL);
	     void SetEps(REAL);

             Im2D_REAL8   CurZ();

	protected :
	     inline REAL CurZ(Pt2di aP) const;
	     inline REAL XHomZ0(Pt2di aP) const;
	     inline REAL YHomZ0(Pt2di aP) const;
	     inline REAL Hom_dXdZ(Pt2di aP) const;
	     inline REAL Hom_dYdZ(Pt2di aP) const;
	     inline Pt2dr  HomOfZ0(Pt2di aP) const;
	     inline Pt2dr DerZ(Pt2di aP) const;
	     inline Pt2dr HomOfZ(Pt2di aP,REAL aZ) const;
	     inline Pt2dr HomOfCurZ(Pt2di aP) const;

	     void SetSizeGeom();
	     void CalcGeomI1();


	     Pt2di        mSzI1;
             Im2D_REAL8   mCurZ;
	     REAL8 **     mDCurZ;

             Im2D_REAL4   mXHomZ0;
	     REAL4 **     mDXHomZ0;
             Im2D_REAL4   mYHomZ0;
	     REAL4 **     mDYHomZ0;

             Im2D_REAL4   mHom_dXdZ;
	     REAL4 **     mDHom_dXdZ;
             Im2D_REAL4   mHom_dYdZ;
	     REAL4 **     mDHom_dYdZ;

             Im2D_U_INT1  mIm1;
	     U_INT1 **    mDIm1;

	     Pt2di        mSzI2;
             Im2D_U_INT1  mIm2;
	     U_INT1 **    mDIm2;

             Im2D_REAL4   mI2G1;
	     REAL4 **     mDI2G1;
             Im2D_REAL4   mDi2g1Dz;
	     REAL4 **     mDDi2g1Dz;
             Im2D_U_INT1  mOK;
             U_INT1 **    mDOK;
 
	     cSetEqFormelles  * pSetIncs;
	     Im2D_INT4          mNumsZInc;
	     INT4 **            mDNZI;

	     cElCompiledFonc * pRegD1;
	     cElCompiledFonc * pRegD2;
	     cElCompiledFonc * pRapCur;
	     static cCIKTabul  TheCIK;
};

#endif
