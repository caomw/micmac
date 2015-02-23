#ifndef _ELISE_GENERAL_OPTIM_CELMATCREUSEGEN_H
#define _ELISE_GENERAL_OPTIM_CELMATCREUSEGEN_H

#include "general/sys_dep.h"

#include <cSsBloc>
#include <Im1D>


class cElMatCreuseGen
{
      public :
// aSys.Indexee_EcrireDansMatrWithQuad
// aSys.SoutraitProduc3x3
// Indexee_QuadSet0
// V_GSSR_AddNewEquation_Indexe

        virtual void Test();

        // true si sait inverser non iterativement (cas cholesky),
       // Defaut false
        virtual bool DirectInverse(const tSysCho *,tSysCho *);

      //========= Optimisations possibles =======================

                 // Indique si l'opt est geree
          virtual bool IsOptForEcrireInMatr() const;
          virtual bool IsOptForSousP3x3() const;
          virtual bool IsOptForQuadSet0() const;
          virtual bool IsOptForAddEqIndexee() const;

                 // Optimise , defaut erreur
         virtual void Indexee_EcrireDansMatrWithQuad
	      (   ElMatrix<tSysCho> &aMatr,
                  const std::vector<cSsBloc> &  aVx,
                  const std::vector<cSsBloc> &  aVy
              )   const;

        virtual void SoutraitProduc3x3
                     (
                          bool                   Sym,
                          ElMatrix<tSysCho> &aM1,
                          ElMatrix<tSysCho> &aM2,
                          const std::vector<cSsBloc> * aYVSB
                     );
         virtual void Indexee_QuadSet0 (const std::vector<cSsBloc> & aVIndx,
	                                const std::vector<cSsBloc> & aVIndy);
         
	 virtual void VMAT_GSSR_AddNewEquation_Indexe
		      ( 
                        const std::vector<cSsBloc> * aVSB,
                        double *  FullCoeff,
                        int aNbTot,
			REAL aPds,tSysCho * aDataLin,REAL aB);

         //=====================================

         bool OptSym() const;
         virtual void Verif(const std::string & aMes) ;


	 static cElMatCreuseGen * StdBlocSym
                ( 
                      const  std::vector<cIncIntervale *> &  Blocs,
                      const  std::vector<int> &              I2Bloc
                );

	 static cElMatCreuseGen * StdNewOne(INT aNbCol,INT aNbLign,bool Fixe);
	 virtual ~cElMatCreuseGen();

         virtual void  MulVect(tSysCho * out,const tSysCho * in) const = 0;
         // virtual void  tMulVect(REAL * out,const REAL * in) const = 0;
         Im1D<tSysCho,tSysCho> MulVect(Im1D<tSysCho,tSysCho>) const;
         void  MulVect8(double * out,const double * in) ;

	 void AddElem(INT aX,INT aY,REAL);


	 virtual tSysCho   LowGetElem(INT aX,INT aY) const =0;
	 virtual void    LowSetElem(INT aX,INT aY,const tSysCho &) =0;



	 void LowAddElem(INT aX,INT aY,REAL) ;

	 virtual void Reset()= 0; // Remet tous les elements a 0

	 virtual void AddLineInd
		      (
		          INT aKY,
		          INT aY,
			  REAL aCyP,
			  const std::vector<INT> & aVInd,
			  REAL * aCoeff
		      );
	 virtual void SetOffsets(const std::vector<INT> & aVIndexes);
	 virtual void   EqMatIndexee
                        (
                           const std::vector<INT> & aVInd,
		           REAL aPds,REAL ** aMat
                        );
          virtual void PrecCondQuad(double *); // Def erreur

          virtual void PrepPreCond();
          virtual void  VPCDo(double * out,double * in);
      protected :
         cElMatCreuseGen(bool OptSym,INT aNbCol,INT aNbLign);
      // private :

         bool mOptSym;
         INT  mNbCol;
         INT  mNbLig;
	 Im1D_REAL8         mDiagPreCond;
         double *           mDDPrec;
};

#endif
