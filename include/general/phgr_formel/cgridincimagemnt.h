#ifndef _ELISE_GENERAL_PHGR_FORMEL_CGRIDINCIMAGEMNT_H
#define _ELISE_GENERAL_PHGR_FORMEL_CGRIDINCIMAGEMNT_H



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

	     void OneStepEqCorrel(double_t aPds,int aSzVgn,bool Im2Var,int anEcart=1);
	     void OneStepRegulD2 (double_t aPds);
	     void OneStepRegulD1 (double_t aPds);
	     void OneStepRapCur  (double_t aPds);

	     void SolveSys();
	     void InitIncs(double_t);
	     void SetEps(double_t);

             Im2D_double_t8   CurZ();

	protected :
	     inline double_t CurZ(Pt2di aP) const;
	     inline double_t XHomZ0(Pt2di aP) const;
	     inline double_t YHomZ0(Pt2di aP) const;
	     inline double_t Hom_dXdZ(Pt2di aP) const;
	     inline double_t Hom_dYdZ(Pt2di aP) const;
	     inline Pt2dr  HomOfZ0(Pt2di aP) const;
	     inline Pt2dr DerZ(Pt2di aP) const;
	     inline Pt2dr HomOfZ(Pt2di aP,double_t aZ) const;
	     inline Pt2dr HomOfCurZ(Pt2di aP) const;

	     void SetSizeGeom();
	     void CalcGeomI1();


	     Pt2di        mSzI1;
             Im2D_double_t8   mCurZ;
	     double_t8 **     mDCurZ;

             Im2D_double_t4   mXHomZ0;
	     double_t4 **     mDXHomZ0;
             Im2D_double_t4   mYHomZ0;
	     double_t4 **     mDYHomZ0;

             Im2D_double_t4   mHom_dXdZ;
	     double_t4 **     mDHom_dXdZ;
             Im2D_double_t4   mHom_dYdZ;
	     double_t4 **     mDHom_dYdZ;

             Im2D_U_int1  mIm1;
	     U_int1 **    mDIm1;

	     Pt2di        mSzI2;
             Im2D_U_int1  mIm2;
	     U_int1 **    mDIm2;

             Im2D_double_t4   mI2G1;
	     double_t4 **     mDI2G1;
             Im2D_double_t4   mDi2g1Dz;
	     double_t4 **     mDDi2g1Dz;
             Im2D_U_int1  mOK;
             U_int1 **    mDOK;
 
	     cSetEqFormelles  * pSetIncs;
	     Im2D_int4          mNumsZInc;
	     int4 **            mDNZI;

	     cElCompiledFonc * pRegD1;
	     cElCompiledFonc * pRegD2;
	     cElCompiledFonc * pRapCur;
	     static cCIKTabul  TheCIK;
};

#endif
