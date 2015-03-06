/*Header-MicMac-eLiSe-25/06/2007

    MicMac : Multi Image Correspondances par Methodes Automatiques de Correlation
    eLiSe  : ELements of an Image Software Environnement

    www.micmac.ign.fr


    Copyright : Institut Geographique National
    Author : Marc Pierrot Deseilligny
    Contributors : Gregoire Maillet, Didier Boldo.
    Refactoring: Helio Chissini de Castro <helio@kde.org>

[1] M. Pierrot-Deseilligny, N. Paparoditis.
    "A multiresolution and optimization-based image matching approach:
    An application to surface reconstruction from SPOT5-HRS stereo imagery."
    In IAPRS vol XXXVI-1/W41 in ISPRS Workshop On Topographic Mapping From Space
    (With Special Emphasis on Small Satellites), Ankara, Turquie, 02-2006.

[2] M. Pierrot-Deseilligny, "MicMac, un lociel de mise en correspondance
    d'images, adapte au contexte geograhique" to appears in
    Bulletin d'information de l'Institut Geographique National, 2007.

Francais :

   MicMac est un logiciel de mise en correspondance d'image adapte
   au contexte de recherche en information geographique. Il s'appuie sur
   la bibliotheque de manipulation d'image eLiSe. Il est distibue sous la
   licences Cecill-B.  Voir en bas de fichier et  http://www.cecill.info.


English :

    MicMac is an open source software specialized in image matching
    for research in geographic information. MicMac is built on the
    eLiSe image library. MicMac is governed by the  "Cecill-B licence".
    See below and http://www.cecill.info.

Header-MicMac-eLiSe-25/06/2007*/


#ifndef _ELISE_GENERAL_OPTIM_CGENSYSSURRESOL_H
#define _ELISE_GENERAL_OPTIM_CGENSYSSURRESOL_H

#include <cTestPbChol>
#include <Im1D>
#include <Pt3d>
#include <GaussjPrec>
#include <ElMatrix>

#include <vector>

class cGenSysSurResol 
{
     public :

           ElMatrix<double>  MatQuad() const;

          virtual double CoeffNorm() const;

//  FONCTION LIEES AU DEBUG DES  VALEUR <0 DANS CHOLESKY SUR PIAZZABRA
          void VerifGlob(const std::vector<cSsBloc> &,bool doCheck,bool doSVD,bool doV0);
          void BasicVerifMatPos(const std::vector<cSsBloc> &,int );

          void VerifMatPos(ElMatrix<double>,ElMatrix<double>  aLambda,cTestPbChol & aTPC,const std::vector<cSsBloc> &);
          void VerifMatPos(const ElMatrix<double> & ,const ElMatrix<double> & aLambda,cTestPbChol & aTPC,const std::vector<cSsBloc> &,const std::vector<cSsBloc> &);

 // Mode 0 =  Null ou non   *-
         void ShowGSR(int aMode);

         virtual void VerifGSS(const std::string & aMes) ;

         bool  OptSym() const;
         virtual void AddOneBloc(const cSsBloc &,const cSsBloc &, double aPds,double * aCoeff);
         virtual void AddOneBlocDiag(const cSsBloc &, double aPds,double * aCoeff);
         virtual void AddOneBlocCste(const cSsBloc &, double aPds,double * aCoeff,double aB);


        // void toto(const std::vector<cSsBloc>  &);

         virtual ~cGenSysSurResol();
         cGenSysSurResol(bool CstrAssumed,bool OptSym,bool GereNonSym,bool GereBloc);

         Im1D_REAL8  GSSR_Solve(bool * aResOk) ;
         void GSSR_Reset(bool WithCstr) ;

     //           aPds (aCoeff . X = aB) 
         void GSSR_AddNewEquation 
              (
                   double aPds,
                   double * aCoeff,
                   double aB,
                   double * aCoordCur  // Pour les contra univ, peut etre NULL
               );

     //  Pour resoudre, de maniere  simplifiee, une equation 
     //   en Ax et B de la forme
     //       Ax* Xi + B = Yi
     //   Typiquement pour fitter une droite
        void GSSR_Add_EqFitDroite(double aXi,double aYi,double aPds=1.0);
        void GSSR_SolveEqFitDroite(double & aAx,double &aB,bool * Ok=0);

     //  Pour resoudre, de maniere  simplifiee, une equation 
     //   en Ax et By et C de la forme
     //       Ax* Xi + By * Yi + C = Zi
     //   Typiquement pour fitter un plan
        void GSSR_Add_EqFitPlan(double aXi,double aYi,double aZi,double aPds=1.0);
        void GSSR_SolveEqFitPlan(double & aAx,double &aB,double & aC,bool * Ok=0);


     // Pour calculer des pseudo-intersection de droite ou de plan 3D
         Pt3dr Pt3dSolinter(bool * Ok=0);


         //  Ajoute une contrainte, sous la forme aC. X = aE
	 //  sous laquelle sera resolu le systeme
         //  L'ensemble des contrainte doit forme un systeme libre
         // void GSSR_AddContrainte (double * aC,double aE);
         void GSSR_AddContrainteIndexee (const std::vector<int> & aVI,double * aC,double aE);

         virtual int NbVar() const = 0;

	 // Renvoie true, deviendra virtuelle
         virtual bool  	AcceptContrainteNonUniV() const;
         void TraitementContrainteUniVar(const std::vector<int> * aVA2S);


          bool IsCstrUniv(int anX,double & aVal);


// Manipulation  directe des matrices
         // aCste + aVect . X + 1/2 tX aMat X
	 virtual bool GSSR_UseEqMatIndexee();
	 void GSSR_EqMatIndexee
                      (
                           const std::vector<int> & aVInd,
                           double aPds,double ** aMat,
                           double * aVect,double aCste
                      );



	 void GSSR_AddNewEquation_Indexe( const std::vector<cSsBloc> *aVSB,
                                          double *  FullCoeff,
                                          int aNbTot,
                                          const std::vector<int> & aVInd ,
                                        double aPds,double * aCoeff,double aB);
         // GSSR_AddNewEquation_Indexe fait des pretraitement de prise en compte des contraintes
         // qu'on ne doit pas faire toujours
	 void Basic_GSSR_AddNewEquation_Indexe(
                                        const std::vector<cSsBloc> * aVSB,
                                        double *  FullCoeff,
                                        int aNbTot,
                                        const std::vector<int> & aVInd ,
                                        double aPds,double * aCoeff,double aB);

         // Def = Erreur fatale, n'a pas de sens pout systeme L1
         virtual double   GetElemQuad(int i,int j) const;
         virtual void  SetElemQuad(int i,int j,const double& );
         virtual double  GetElemLin(int i) const;
         virtual void  SetElemLin(int i,const double& ) ;

	 // Pour ces 4 Fon, Def, utilise GetElemQuad-GetElemLin

/*
         virtual void Indexee_EcrireDansMatrColWithLin
              (ElMatrix<double> &aMatr,const std::vector<int> & aVInd) const;
*/
         virtual void Indexee_EcrireDansMatrWithQuad
              (  ElMatrix<double> &aMatr,
                 const std::vector<int> & aVIndx,
                 const std::vector<int> & aVIndy
              )   const;
         virtual void Indexee_LinSet0  (const std::vector<int> & aVInd);
         virtual void Indexee_QuadSet0 (const std::vector<int> & aVIndx,
                                        const std::vector<int> & aVIndy);


         virtual void Indexee_EcrireDansMatrColWithLin
              (ElMatrix<double> &aMatr,const std::vector<cSsBloc> &  aVx) const;
         virtual void Indexee_EcrireDansMatrWithQuad
              (   ElMatrix<double> &aMatr,
                  const std::vector<cSsBloc> &  aVx,
                  const std::vector<cSsBloc> &  aVy
              )   const;

         virtual void Indexee_LinSet0  (const std::vector<cSsBloc> & aVInd);
         virtual void Indexee_QuadSet0 (const std::vector<cSsBloc> & aVIndx,
	                                const std::vector<cSsBloc> & aVIndy);




         virtual void Indexee_UpdateLinWithMatrCol
              (const ElMatrix<double> &aMatr,const std::vector<int> & aVInd);
         virtual void Indexee_UpdateQuadWithMatr
              (  const ElMatrix<double> &aMatr,
                 const std::vector<int> & aVIndx,
                 const std::vector<int> & aVIndy
              )  ;

         virtual void Indexee_SoustraitMatrColInLin
              (const ElMatrix<double> &aMatr,const std::vector<cSsBloc> & aVInd);
         virtual void Indexee_SoustraitMatrInQuad
              (  const ElMatrix<double> &aMatr,
                 const std::vector<int> & aVIndx,
                 const std::vector<int> & aVIndy
              )  ;

        virtual void SoutraitProduc3x3
                     (
                          bool                   Sym,
                          ElMatrix<double> &aM1,
                          ElMatrix<double> &aM2,
                          const std::vector<cSsBloc> * aYVSB
                     );
         

         virtual void Indexee_QuadSetId (const std::vector<int> & aVIndxy);

         void  SetPhaseEquation(const std::vector<int> *);

         virtual double  ResiduOfSol(const double *);
     protected :
	 virtual void V_GSSR_EqMatIndexee
                      (
                           const std::vector<int> & aVInd,
                           double aPds,double ** aMat,
                           double * aVect,double aCste
                      );
	 // Def = erreur fatale
	 virtual void V_GSSR_AddNewEquation_Indexe
		      ( 
                        const std::vector<cSsBloc> * aVSB,
                        double *  FullCoeff,
                        int aNbTot,
                        const std::vector<int> & aVInd ,
                        double aPds,double * aCoeff,double aB);
 
         virtual Im1D_REAL8  V_GSSR_Solve(bool * aResOk) = 0;
         virtual void V_GSSR_Reset() = 0;
         virtual void V_GSSR_AddNewEquation
                      (double aPds,double * aCoeff,double aB) = 0;


         bool  mCstrAssumed;
// Si mOptSym est true , c'est la partie "superieure" des matrice qui est remplie,

         bool  mOptSym;
         bool  mGereNonSym;
         bool  mGereBloc;
         bool  mPhaseContrainte;
	 bool  mFirstEquation;

         void AssertPhaseContrainte();
         void AssertPhaseEquation();



         int   mNbContrainte;
         int   mLineCC;
//  Gestion des contraintes, ancienne mode
         ElMatrix<double> mC;
         ElMatrix<double> mE;
         ElMatrix<double> mtL;
         ElMatrix<double> mtLC;
         ElMatrix<double> mtLCE;

         ElMatrix<double> mSol;
         ElMatrix<double> mCSol;

         GaussjPrec     mGP;
// Gestion des contraintes , nouvelle prise en compte specifique des contraintes
// univariees 
         bool        mNewCstrIsInit;
         bool        mNewCstrIsTraitee;
         bool        mUseSpeciCstrUniVar;  // a priori tjs true, false permet de revenir en arriere
         Im1D_REAL8  mValCstr;
         double *    mDValCstr;
         Im1D_U_INT1 mIsCstr;
         unsigned char *    mDIsCstr;
};

#endif
