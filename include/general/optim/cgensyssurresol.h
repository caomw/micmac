#ifndef _ELISE_GENERAL_OPTIM_CGENSYSSURRESOL_H
#define _ELISE_GENERAL_OPTIM_CGENSYSSURRESOL_H

#include "general/sys_dep.h"

class cGenSysSurResol 
{
     public :

           ElMatrix<tSysCho>  MatQuad() const;

          virtual double CoeffNorm() const;

//  FONCTION LIEES AU DEBUG DES  VALEUR <0 DANS CHOLESKY SUR PIAZZABRA
          void VerifGlob(const std::vector<cSsBloc> &,bool doCheck,bool doSVD,bool doV0);
          void BasicVerifMatPos(const std::vector<cSsBloc> &,int );

          void VerifMatPos(ElMatrix<tSysCho>,ElMatrix<tSysCho>  aLambda,cTestPbChol & aTPC,const std::vector<cSsBloc> &);
          void VerifMatPos(const ElMatrix<tSysCho> & ,const ElMatrix<tSysCho> & aLambda,cTestPbChol & aTPC,const std::vector<cSsBloc> &,const std::vector<cSsBloc> &);

 // Mode 0 =  Null ou non   *-
         void ShowGSR(int aMode);

         virtual void VerifGSS(const std::string & aMes) ;

         bool  OptSym() const;
         virtual void AddOneBloc(const cSsBloc &,const cSsBloc &, REAL aPds,REAL * aCoeff);
         virtual void AddOneBlocDiag(const cSsBloc &, REAL aPds,REAL * aCoeff);
         virtual void AddOneBlocCste(const cSsBloc &, REAL aPds,REAL * aCoeff,REAL aB);


        // void toto(const std::vector<cSsBloc>  &);

         virtual ~cGenSysSurResol();
         cGenSysSurResol(bool CstrAssumed,bool OptSym,bool GereNonSym,bool GereBloc);

         Im1D_REAL8  GSSR_Solve(bool * aResOk) ;
         void GSSR_Reset(bool WithCstr) ;

     //           aPds (aCoeff . X = aB) 
         void GSSR_AddNewEquation 
              (
                   REAL aPds,
                   REAL * aCoeff,
                   REAL aB,
                   double * aCoordCur  // Pour les contra univ, peut etre NULL
               );

     //  Pour resoudre, de maniere  simplifiee, une equation 
     //   en Ax et B de la forme
     //       Ax* Xi + B = Yi
     //   Typiquement pour fitter une droite
	void GSSR_Add_EqFitDroite(REAL aXi,REAL aYi,REAL aPds=1.0);
	void GSSR_SolveEqFitDroite(REAL & aAx,REAL &aB,bool * Ok=0);

     //  Pour resoudre, de maniere  simplifiee, une equation 
     //   en Ax et By et C de la forme
     //       Ax* Xi + By * Yi + C = Zi
     //   Typiquement pour fitter un plan
	void GSSR_Add_EqFitPlan(REAL aXi,REAL aYi,REAL aZi,REAL aPds=1.0);
	void GSSR_SolveEqFitPlan(REAL & aAx,REAL &aB,REAL & aC,bool * Ok=0);


     // Pour calculer des pseudo-intersection de droite ou de plan 3D
	 Pt3dr Pt3dSolInter(bool * Ok=0);


	 //  Ajoute une contrainte, sous la forme aC. X = aE 
	 //  sous laquelle sera resolu le systeme
	 //  L'ensemble des contrainte doit forme un systeme libre
         // void GSSR_AddContrainte (REAL * aC,REAL aE);
         void GSSR_AddContrainteIndexee (const std::vector<int> & aVI,REAL * aC,REAL aE);

	 virtual INT NbVar() const = 0;

	 // Renvoie true, deviendra virtuelle
	 virtual bool  	AcceptContrainteNonUniV() const;
         void TraitementContrainteUniVar(const std::vector<int> * aVA2S);


          bool IsCstrUniv(int anX,double & aVal);


// Manipulation  directe des matrices
         // aCste + aVect . X + 1/2 tX aMat X
	 virtual bool GSSR_UseEqMatIndexee();
	 void GSSR_EqMatIndexee
                      (
                           const std::vector<INT> & aVInd,
		           REAL aPds,REAL ** aMat,
			   REAL * aVect,REAL aCste
                      );



	 void GSSR_AddNewEquation_Indexe( const std::vector<cSsBloc> *aVSB,
                                          double *  FullCoeff,
                                          int aNbTot,
                                          const std::vector<INT> & aVInd ,
			                REAL aPds,REAL * aCoeff,REAL aB);
         // GSSR_AddNewEquation_Indexe fait des pretraitement de prise en compte des contraintes
         // qu'on ne doit pas faire toujours
	 void Basic_GSSR_AddNewEquation_Indexe(
                                        const std::vector<cSsBloc> * aVSB,
                                        double *  FullCoeff,
                                        int aNbTot,
                                        const std::vector<INT> & aVInd ,
			                REAL aPds,REAL * aCoeff,REAL aB);

         // Def = Erreur fatale, n'a pas de sens pout systeme L1
         virtual tSysCho   GetElemQuad(int i,int j) const;
         virtual void  SetElemQuad(int i,int j,const tSysCho& );
         virtual tSysCho  GetElemLin(int i) const;
         virtual void  SetElemLin(int i,const tSysCho& ) ;

	 // Pour ces 4 Fon, Def, utilise GetElemQuad-GetElemLin

/*
         virtual void Indexee_EcrireDansMatrColWithLin
	      (ElMatrix<double> &aMatr,const std::vector<INT> & aVInd) const;
*/
         virtual void Indexee_EcrireDansMatrWithQuad
	      (  ElMatrix<tSysCho> &aMatr,
	         const std::vector<INT> & aVIndx,
		 const std::vector<INT> & aVIndy
              )   const;
         virtual void Indexee_LinSet0  (const std::vector<INT> & aVInd);
         virtual void Indexee_QuadSet0 (const std::vector<INT> & aVIndx,
	                                const std::vector<INT> & aVIndy);


         virtual void Indexee_EcrireDansMatrColWithLin
	      (ElMatrix<tSysCho> &aMatr,const std::vector<cSsBloc> &  aVx) const;
         virtual void Indexee_EcrireDansMatrWithQuad
	      (   ElMatrix<tSysCho> &aMatr,
                  const std::vector<cSsBloc> &  aVx,
                  const std::vector<cSsBloc> &  aVy
              )   const;

         virtual void Indexee_LinSet0  (const std::vector<cSsBloc> & aVInd);
         virtual void Indexee_QuadSet0 (const std::vector<cSsBloc> & aVIndx,
	                                const std::vector<cSsBloc> & aVIndy);




         virtual void Indexee_UpdateLinWithMatrCol
	      (const ElMatrix<tSysCho> &aMatr,const std::vector<INT> & aVInd);
         virtual void Indexee_UpdateQuadWithMatr
	      (  const ElMatrix<tSysCho> &aMatr,
	         const std::vector<INT> & aVIndx,
		 const std::vector<INT> & aVIndy
              )  ;

         virtual void Indexee_SoustraitMatrColInLin
	      (const ElMatrix<tSysCho> &aMatr,const std::vector<cSsBloc> & aVInd);
         virtual void Indexee_SoustraitMatrInQuad
	      (  const ElMatrix<tSysCho> &aMatr,
	         const std::vector<INT> & aVIndx,
		 const std::vector<INT> & aVIndy
              )  ;

        virtual void SoutraitProduc3x3
                     (
                          bool                   Sym,
                          ElMatrix<tSysCho> &aM1,
                          ElMatrix<tSysCho> &aM2,
                          const std::vector<cSsBloc> * aYVSB
                     );
         

         virtual void Indexee_QuadSetId (const std::vector<INT> & aVIndxy);

         void  SetPhaseEquation(const std::vector<int> *);

         virtual double  ResiduOfSol(const double *);
     protected :
	 virtual void V_GSSR_EqMatIndexee
                      (
                           const std::vector<INT> & aVInd,
		           REAL aPds,REAL ** aMat,
			   REAL * aVect,REAL aCste
                      );
	 // Def = erreur fatale
	 virtual void V_GSSR_AddNewEquation_Indexe
		      ( 
                        const std::vector<cSsBloc> * aVSB,
                        double *  FullCoeff,
                        int aNbTot,
                        const std::vector<INT> & aVInd ,
			REAL aPds,REAL * aCoeff,REAL aB);
 
         virtual Im1D_REAL8  V_GSSR_Solve(bool * aResOk) = 0;
         virtual void V_GSSR_Reset() = 0;
         virtual void V_GSSR_AddNewEquation
		      (REAL aPds,REAL * aCoeff,REAL aB) = 0;


         bool  mCstrAssumed;
// Si mOptSym est true , c'est la partie "superieure" des matrice qui est remplie,

         bool  mOptSym;
         bool  mGereNonSym;
         bool  mGereBloc;
	 bool  mPhaseContrainte;
	 bool  mFirstEquation;

         void AssertPhaseContrainte();
         void AssertPhaseEquation();



	 INT   mNbContrainte;
	 INT   mLineCC;
//  Gestion des contraintes, ancienne mode
	 ElMatrix<REAL> mC;
	 ElMatrix<REAL> mE;
	 ElMatrix<REAL> mtL;
	 ElMatrix<REAL> mtLC;
	 ElMatrix<REAL> mtLCE;

	 ElMatrix<REAL> mSol;
	 ElMatrix<REAL> mCSol;

         GaussjPrec     mGP;
// Gestion des contraintes , nouvelle prise en compte specifique des contraintes
// univariees 
         bool        mNewCstrIsInit;
         bool        mNewCstrIsTraitee;
         bool        mUseSpeciCstrUniVar;  // a priori tjs true, false permet de revenir en arriere
         Im1D_REAL8  mValCstr;
         double *    mDValCstr;
         Im1D_U_INT1 mIsCstr;
         U_INT1 *    mDIsCstr;
};

#endif
