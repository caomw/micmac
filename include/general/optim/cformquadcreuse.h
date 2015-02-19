#ifndef _ELISE_GENERAL_OPTIM_CFORMQUADCREUSE_H
#define _ELISE_GENERAL_OPTIM_CFORMQUADCREUSE_H

#include "general/sys_dep.h"

class cFormQuadCreuse : public cVectMatMul,
                        public cVectPreCond,
                        public FoncNVarDer<REAL>,
                        public cGenSysSurResol
{
      // mVO + mFLin . X + 1/2 tX mMat X
      public :
          virtual double CoeffNorm() const;
         virtual double  ResiduOfSol(const double *);
         virtual void VerifGSS(const std::string & aMes) ;
         
	  bool  	AcceptContrainteNonUniV() const;
          cFormQuadCreuse(INT aNbVar,cElMatCreuseGen * aMatCr);
	  void AddDiff(Fonc_Num,const ElGrowingSetInd &);
	  void AddDiff(Fonc_Num);
	  virtual ~cFormQuadCreuse();

          virtual void GradFNV(REAL *grad,const REAL *   v) ;
          virtual REAL ValFNV(const REAL *  v) ;
 
	 void SetOffsets(const std::vector<INT> & aVIndexes);
	 bool GSSR_UseEqMatIndexee();
         // aCste + aVect . X + 1/2 tX aMat X
	 void V_GSSR_EqMatIndexee
                      (
                           const std::vector<INT> & aVInd,
		           REAL aPds,REAL ** aMat,
			   REAL * aVect,REAL aCste
                      );
         virtual tSysCho   GetElemQuad(int i,int j) const;
         virtual void  SetElemQuad(int i,int j,const tSysCho& );
         virtual tSysCho  GetElemLin(int i) const;
         virtual void  SetElemLin(int i,const tSysCho& ) ;


         virtual void SoutraitProduc3x3
                     (
                          bool                   Sym,
                          ElMatrix<tSysCho> &aM1,
                          ElMatrix<tSysCho> &aM2,
                          const std::vector<cSsBloc> * aYVSB
                     );
           
         virtual void Indexee_EcrireDansMatrWithQuad
                      (
                             ElMatrix<tSysCho> &aMatr,
                             const std::vector<cSsBloc> &  aVx,
                             const std::vector<cSsBloc> &  aVy
                      )  const;

         virtual void  Indexee_QuadSet0
                       (
                              const std::vector<cSsBloc> & aVx,
                              const std::vector<cSsBloc> & aVy
                       );



         
      private :
           void VMMDo(Im1D_REAL8 in,Im1D_REAL8 out);
           void VPCDo(Im1D_REAL8 in,Im1D_REAL8 out);



           // void SMFGC_Atsub(double *in,double *out,int) ;

	  virtual void V_GSSR_AddNewEquation_Indexe
		      (
                        const std::vector<cSsBloc> * aVSB,
                        double *  FullCoeff,
                        int aNbTot,
                        const std::vector<INT> & aVInd ,
			REAL aPds,REAL * aCoeff,REAL aB);
	 virtual INT NbVar() const ;
         virtual Im1D_REAL8  V_GSSR_Solve(bool * aResOk) ;
         virtual void V_GSSR_Reset() ;
         virtual void V_GSSR_AddNewEquation
		      (REAL aPds,REAL * aCoeff,REAL aB) ;

	  INT                mNbVar;
	  REAL               mV0;
	  Im1D<tSysCho,tSysCho>  mFLin;
	  tSysCho *          mDataLin;
	  Im1D_REAL8         mVGrad;
	  REAL8 *            mDataGrad;
	  cElMatCreuseGen *  mMat;
	  ElGrowingSetInd *  mEGSI;
	  PtsKD           *  mP000;

          bool mMatIsOptForEcrireInMatr;
          bool mMatIsOptForSousP3x3;
          bool mMatIsOptForQuadSet0;
          bool mMatIsOptForAddEqIndexee;
};

#endif
