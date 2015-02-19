#ifndef _ELISE_GENERAL_OPTIM_SYSTLINSURRESOLU_H
#define _ELISE_GENERAL_OPTIM_SYSTLINSURRESOLU_H

#include "general/sys_dep.h"

class  SystLinSurResolu : public cGenSysSurResol  // Herite en tant que Solveur L1
{
	public :
               Im1D_REAL8  V_GSSR_Solve(bool * aResOk);
               void V_GSSR_Reset();
               void V_GSSR_AddNewEquation(REAL aPds,REAL * aCoeff,REAL aB);
	        INT NbVar() const;

               SystLinSurResolu(INT NbVar,INT NbEq);

                  void SetSize(INT NbVar,INT NbEq);
			void SetNbEquation(INT aNbEq);
			void SetNoEquation();


			void PushDifferentialEquation
			     (
                                   Fonc_Num      aFonc,
                                   const PtsKD & aPts,
                                   REAL          aPds = 1.0
                             );
			void PushEquation
			     (
                                   Im1D_REAL8    aFormLin,
				   REAL          aValue,
                                   REAL          aPds = 1.0
                             );
			void PopEquation();
			void PushEquation
			     (
                                   REAL8 *       aFormLin,
				   REAL          aValue,
                                   REAL          aPds = 1.0
                             );

			Im1D_REAL8  L1Solve();
			// Si Ok ==0, matrice sing => erreur fatale
			Im1D_REAL8  L2Solve(bool *Ok); 

			// Non Pondere, signe
			REAL Residu(Im1D_REAL8,INT iEq) const; 
			// Pondere :
			REAL L2SomResiduPond(Im1D_REAL8)const; 
			INT NbEq() const;

			REAL Pds(INT iEq) const;
			REAL CoefLin(INT iVar,INT iEq) const;
			REAL CoefCste(INT iEq) const;

			REAL Residu(const REAL *,INT iEq) const; 
		protected :
		private :

                        void AdjustSizeCapa();
			void BarrodaleSetSize();
			void L2SetSize();
			void AssertIndexEqValide(INT IndEq) const;
			void AssertIndexVarValide(INT IndEq) const;
			void AssertIndexGoodNbVar(INT aNbVar) const;


			INT          mNbVarCur;
			INT          mNbEqCur;
			INT          mNbVarCapa;
			INT          mNbEqCapa;

			Im2D_REAL8   mA;  // mA.data() [IEqu][Ivar]
			REAL8 **     mDataA;
			Im1D_REAL8   mB;
			REAL8 *      mDataB;
			Im1D_REAL8   mPds;
			REAL8 *      mDataPds;


			// variables tempo pour  L1 Barrodale
			Im1D_REAL8   mBarodA;
			REAL8 *      mDataBarodA;
			Im1D_REAL8   mBarodB;
			REAL8 *      mDataBarodB;
			Im1D_REAL8   mBarodSOL;
			REAL8 *      mDataBarodSOL;
			Im1D_REAL8   mBarodRESIDU;
			REAL8 *      mDataBarodRESIDU;
		
			// variables tempo pour  L2-Gaussj
			// Pour resoudre au moindre carre
			// Li X = bi

                         L2SysSurResol mL2;
		
/*
			 Im2D_REAL8   mtLi_Li; // Sigma des trans(Li) Li
                         REAL8 **     mDatatLi_Li;
			 Im1D_REAL8   mbi_Li;  // Sigma des bi * Li
                         REAL8 *      mDatabi_Li;
			 Im1D_REAL8   mSolL2;
                         REAL8 *      mDataSolL2;
*/

};

#endif
