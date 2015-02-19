#ifndef _ELISE_GENERAL_OPTIM_L2SYSSURRESOL_H
#define _ELISE_GENERAL_OPTIM_L2SYSSURRESOL_H

#include "general/sys_dep.h"

class L2SysSurResol : public cGenSysSurResol
{
     public :
         virtual double  ResiduOfSol(const double *);
         void  GSSR_Add_EqInterPlan3D(const Pt3dr& aDirOrtho,const Pt3dr& aP0,double aPds=1.0);
         void  GSSR_Add_EqInterDroite3D(const Pt3dr& aDirDroite,const Pt3dr& aP0,double aPds=1.0);

         void   GSSR_AddEquationFitOneVar(int aNumVar,double aVal,double aPds);
         void   GSSR_AddEquationPoint3D(const Pt3dr & aP,const Pt3dr &  anInc);

        virtual void SoutraitProduc3x3
                     (
                          bool                   Sym,
                          ElMatrix<double> &aM1,
                          ElMatrix<double> &aM2,
                          const std::vector<cSsBloc> * aYVSB
                     );
         
         void Indexee_EcrireDansMatrWithQuad
	      (  ElMatrix<double> &aMatr,
                 const std::vector<cSsBloc> &  aVx,
                 const std::vector<cSsBloc> &  aVy
              )   const;

         void Indexee_EcrireDansMatrColWithLin
	      (ElMatrix<double> &aMatr,const std::vector<cSsBloc> &  aVx) const;

         void Indexee_LinSet0  (const std::vector<cSsBloc> & aVInd);
         void Indexee_QuadSet0 (const std::vector<cSsBloc> & aVIndx,
	                        const std::vector<cSsBloc> & aVIndy);

   //===================================================

         Im1D_REAL8  V_GSSR_Solve(bool * aResOk);
         void V_GSSR_Reset();
         void V_GSSR_AddNewEquation(REAL aPds,REAL * aCoeff,REAL aB);

         void AddTermLineaire(INT aK,REAL aVal);
         void AddTermQuad(INT aK1,INT aK2,REAL aVal);



        L2SysSurResol (INT aNbVar,bool IsSym=true);
        void SetSize(INT aNbVar);
        void GetMatr(ElMatrix<REAL> & M,ElMatrix<REAL> & tB);

     // Ajoute   :  
     //           aPds (aCoeff . X = aB) 

        void AddEquation(REAL aPds,REAL * aCoeff,REAL aB);
        void Reset();
        Im1D_REAL8  Solve(bool * aResOk);
        Pt3d<double>  Solve3x3Sym(bool * OK);

	INT NbVar() const;


	 virtual bool GSSR_UseEqMatIndexee();
         // aCste + aVect . X + 1/2 tX aMat X
	 virtual void V_GSSR_EqMatIndexee
                      (
                           const std::vector<INT> & aVInd,
		           REAL aPds,REAL ** aMat,
			   REAL * aVect,REAL aCste
                      );
         virtual tSysCho   GetElemQuad(int i,int j) const;
         virtual void  SetElemQuad(int i,int j,const tSysCho& );
         virtual tSysCho  GetElemLin(int i) const;
         virtual void  SetElemLin(int i,const tSysCho& ) ;

	  Im2D_REAL8   tLi_Li(); // Sigma des trans(Li) Li

     private :
	  virtual void V_GSSR_AddNewEquation_Indexe
                      (  const std::vector<cSsBloc> * aVSB,
                        double *  FullCoeff,
                        int aNbTot,
		         const std::vector<INT> & aVInd ,
			REAL aPds,REAL * aCoeff,REAL aB);

        INT          mNbVar;
	Im2D_REAL8   mtLi_Li; // Sigma des trans(Li) Li
        REAL8 **     mDatatLi_Li;
	Im2D_REAL8   mInvtLi_Li;    // Inverse Sigma des trans(Li) Li
        REAL8 **     mDataInvtLi_Li;
        Im1D_REAL8   mbi_Li;  // Sigma des bi * Li
        REAL8 *      mDatabi_Li;
        REAL8        mBibi;
        Im1D_REAL8   mSolL2;
        REAL8 *      mDataSolL2;
        INT          mNbEq; // Debug
        double       mMaxBibi; // Debug
};

#endif
