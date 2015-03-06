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

#ifndef _ELISE_GENERAL_OPTIM_H
#define _ELISE_GENERAL_OPTIM_H


#include <general/sys_dep.h>
#include <general/ptxd.h>
#include <general/phgr_formel.h>
#include <general/bitm.h>

class NROptF1vND;
class NROptF1vDer;

// NROptF1vND : Num Recipes Optimisation de Fonction d'1 var, Non Derivable 

class NROptF1vND
{
     public :
          virtual double_t NRF1v(double_t) = 0;
          virtual bool NROptF1vContinue() const;
          virtual ~NROptF1vND();
          NROptF1vND(int aNbIterMax=-1);


          //+++++++++++++++++++++++++++
          // Golden search for mimimum
          //+++++++++++++++++++++++++++

          double_t golden(double_t ax,double_t bx,double_t cx,double_t tol,double_t * xmin);

          //+++++++++++++++++++++++++++
          // Brent search for mimimum
          //+++++++++++++++++++++++++++

               // Appelle une eventuelle redifinition de Brent
               // (cas derivable), fait le bracketing initial
               // sur les valeur 0,1,2 
               Pt2dr  brent (bool ForBench=false);

          //++++++++++++++++++++++++++++++++++++++++++++++++
          // Van Wijngaarden-Deker-Brent search for root
          //++++++++++++++++++++++++++++++++++++++++++++++++
          // double_t zbrent(double_t ax,double_t bx,double_t tol,int ITMAX=100);


                  // NR interface
          void mnbrack( double_t *ax,double_t *bx,double_t *cx,
                        double_t *fa,double_t * fb,double_t *fc
                      );
     protected :
         int mNbIter;
         int mNbIterMax;
         double  mTolGolden;
         double  TOL;
         double x0,x1,x2,x3;
     private :

          // precondition :
          // f(ax) > f(bx), f(cx) > f(bx),  bx entre ax et cx 
          virtual double_t PrivBrent
                  (
                    double_t ax,double_t bx,double_t cx,
                    double_t tol,
                    double_t * xmin,
                    int ITMAX=100
               );

};

// NROptF1vDer : Num Recipes Optimisation de Fonction d'1 var, Derivable 

class NROptF1vDer : public NROptF1vND
{
     public :
          virtual double_t DerNRF1v(double_t) = 0;

          //+++++++++++++++++++++++++++
          // Brent search for minimum
          //+++++++++++++++++++++++++++


          //++++++++++++++++++++++++++++++++++++++++++++++++
          // Van Wijngaarden-Deker-Brent recherche de racines
          // en utilisant les derivees
          //++++++++++++++++++++++++++++++++++++++++++++++++
          double_t rtsafe(double_t ax,double_t bx,double_t tol,int ITMAX=100);

     private :
          double_t PrivBrent  // Retourne la valeur de F au min
               (
                   double_t ax,double_t bx,double_t cx,
                   double_t tol,
                   double_t * xmin,  // retourne xmin
                   int ITMAX=100
               );
};


template <class Type> class FoncNVarND
{
    public :

       FoncNVarND(int NbVar);
       virtual ~FoncNVarND();

       virtual double_t ValFNV(const Type *  v) = 0;
       int NbVar() const;
       int powel(Type *,double_t ftol,int ITMAX = 200);

    protected :

       const int           _NbVar;

       inline double_t NRValFNV(const Type *);  // Just Recall ValFNV with NR convention
       void powel(Type *,double_t ftol,int *iter,double_t * fret,int ITMAX = 200);
};

template <class Type> class  FoncNVarDer : public FoncNVarND<Type>
{
    public :
       virtual void GradFNV(Type *grad,const Type *   v) = 0;

       FoncNVarDer(int NbVar);
       int GradConj(Type *p,double_t ftol,int ITMAX);


    protected :
       void NRGradFNV(const Type *,Type *);  // Just Recall ValFNV
       void GradConj(Type *p,double_t ftol,int *iter,double_t *fret,int ITMAX);

};



class GaussjPrec
{
      public :

          GaussjPrec(int n,int m);
          bool init_rec();
          void amelior_sol();
          double_t ecart() const;
          double_t ecart_inv() const;
          void set_size_nm(int n,int m);
          void set_size_m(int);

          ElMatrix<double_t> & M()     {return _M;}
          ElMatrix<double_t> & b()     {return _b;}
          ElMatrix<double_t> & Minv()  {return _Minv;}
          ElMatrix<double_t> & x ()    {return _x;}


          void SelfSetMatrixInverse(ElMatrix<double_t> & aM,int aNbIter);

      private :

      // resoud _M * _x = _b
          void set_ecart();

          int            _n;
          int            _m;

          ElMatrix<double_t> _M;
          ElMatrix<double_t> _Minv;
          ElMatrix<double_t> _b;
          ElMatrix<double_t> _x;
          ElMatrix<double_t> _eps;
          ElMatrix<double_t> _ec;
};                

class AllocateurDInconnues;

class cStateAllocI
{
     public :
           friend class AllocateurDInconnues;
           cStateAllocI(const AllocateurDInconnues&);
           void ShowDiff(const cStateAllocI &) const;
     private  :
        const AllocateurDInconnues & mAlloc;
        std::vector<double>          mVals;
};


class AllocateurDInconnues
{
      public :
        void AssertUsable(const cStateAllocI &) const;
        void RestoreState(const cStateAllocI &);
        AllocateurDInconnues();
        Fonc_Num        NewF(double_t *);
        int             NewInc(double_t *);
        Pt3d<Fonc_Num>  NewPt3(double_t *,double_t*,double_t*);
        Pt3d<Fonc_Num>            NewPt3(Pt3dr &);
        Pt2d<Fonc_Num>            NewPt2(double_t*,double_t*);
        Pt2d<Fonc_Num>            NewPt2(Pt2dr &);

        std::vector<Fonc_Num>            NewVectInc(std::vector<double> &);

        TplElRotation3D<Fonc_Num> NewRot(double_t *,double_t*,double_t*,double_t *,double_t*,double_t*);
        int CurInc() const;

	PtsKD PInits();
	void SetVars(const double_t * aSol);
	double  GetVar(int aK) const;
	double * GetAdrVar(int aK);
	void  SetVar(double aVal,int aK);
	void  SetVarPt(Pt2dr  aVal,int aK);
	double_t * ValsVar();
        void Reinit(int aK);

      private :
	void PushVar(double_t *);
	std::vector<double_t *>  mAdrVar;
	std::vector<double_t  >  mValsVar;
        int GetNewInc();
        int mIdInc;
        AllocateurDInconnues (const AllocateurDInconnues &);
        void operator = (const AllocateurDInconnues &);
};


// Classe pour gerer rapidement des ensemble entier;
// Permet de cumuler les avantages d'un "std::set" et 
// d'un "std::vector<bool> du point de vue ajout, consultation
// par contre, pas de suppression
// 
// On essaye d'avoir le max de compatibilite avec les set de 
// la stl.

class ElGrowingSetInd 
{
     public :
         // Partie typedef

            typedef int key_type;
            typedef int value_type;
            typedef std::vector<int>::const_iterator const_iterator;

         // "Big Three"
            ElGrowingSetInd
            (
                 int aCapa, 
                 double_t aRatioEncombr = 0.1 // Pour dimensionner mIndexes, Pas Fondamental.
            );
            ~ElGrowingSetInd();
            /// ElGrowingSetInd(const ElGrowingSetInd &); => en private, non implante

         // Pour parcourir un ElGrowingSetInd
            const_iterator begin() const  {return mIndexes.begin();}
            const_iterator end()   const  {return mIndexes.end();}



         // Partie set classique
            void clear();
            void insert(const int&) ;
            int size() const;


         /*
             >,>=, == , != : peuvent etre fait rapidement
         */

     private :
         inline void AssertValideIndexe(int anIndexe) const;
         inline bool PrivMember(int anIndexe) const;
         inline void PrivSet(int anIndexe,bool) ;
         ElGrowingSetInd(const ElGrowingSetInd &);  // Non implante

         int         mCapa;
         std::vector<int>  mIndexes;
         Im2D_Bits<1>      mBuzyIndexes;

         // void erase(const int&);  a definir dans une classe derivee, "non growing"
};

class ElSignedGrowingSetInd 
{
    public :
    private :
       ElGrowingSetInd mSetPos;
       ElGrowingSetInd mSetNeg;
};

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
        virtual bool DirectInverse(const double_t *,double_t *);

      //========= Optimisations possibles =======================

                 // Indique si l'opt est geree
          virtual bool IsOptForEcrireInMatr() const;
          virtual bool IsOptForSousP3x3() const;
          virtual bool IsOptForQuadSet0() const;
          virtual bool IsOptForAddEqIndexee() const;

                 // Optimise , defaut erreur
         virtual void Indexee_EcrireDansMatrWithQuad
	      (   ElMatrix<double_t> &aMatr,
                  const std::vector<cSsBloc> &  aVx,
                  const std::vector<cSsBloc> &  aVy
              )   const;

        virtual void SoutraitProduc3x3
                     (
                          bool                   Sym,
                          ElMatrix<double_t> &aM1,
                          ElMatrix<double_t> &aM2,
                          const std::vector<cSsBloc> * aYVSB
                     );
         virtual void Indexee_QuadSet0 (const std::vector<cSsBloc> & aVIndx,
	                                const std::vector<cSsBloc> & aVIndy);
         
	 virtual void VMAT_GSSR_AddNewEquation_Indexe
		      ( 
                        const std::vector<cSsBloc> * aVSB,
                        double *  FullCoeff,
                        int aNbTot,
			double_t aPds,double_t * aDataLin,double_t aB);

         //=====================================

         bool OptSym() const;
         virtual void Verif(const std::string & aMes) ;


	 static cElMatCreuseGen * StdBlocSym
                ( 
                      const  std::vector<cIncIntervale *> &  Blocs,
                      const  std::vector<int> &              I2Bloc
                );

	 static cElMatCreuseGen * StdNewOne(int aNbCol,int aNbLign,bool Fixe);
	 virtual ~cElMatCreuseGen();

         virtual void  MulVect(double_t * out,const double_t * in) const = 0;
         // virtual void  tMulVect(double_t * out,const double_t * in) const = 0;
         Im1D<double_t,double_t> MulVect(Im1D<double_t,double_t>) const;
         void  MulVect8(double * out,const double * in) ;

	 void AddElem(int aX,int aY,double_t);


	 virtual double_t   LowGetElem(int aX,int aY) const =0;
	 virtual void    LowSetElem(int aX,int aY,const double_t &) =0;



	 void LowAddElem(int aX,int aY,double_t) ;

	 virtual void Reset()= 0; // Remet tous les elements a 0

	 virtual void AddLineInd
		      (
		          int aKY,
		          int aY,
			  double_t aCyP,
			  const std::vector<int> & aVInd,
			  double_t * aCoeff
		      );
	 virtual void SetOffsets(const std::vector<int> & aVIndexes);
	 virtual void   EqMatIndexee
                        (
                           const std::vector<int> & aVInd,
		           double_t aPds,double_t ** aMat
                        );
          virtual void PrecCondQuad(double *); // Def erreur

          virtual void PrepPreCond();
          virtual void  VPCDo(double * out,double * in);
      protected :
         cElMatCreuseGen(bool OptSym,int aNbCol,int aNbLign);
      // private :

         bool mOptSym;
         int  mNbCol;
         int  mNbLig;
	 Im1D_double_t8         mDiagPreCond;
         double *           mDDPrec;
};


/*
                          ----- cGenSysSurResol ----   ContraintesAssumed -
                         /          |             \
          cFormQuadCreuse     L2SysSurResol   SystLinSurResolu


         cGenSysSurResol   :  ContraintesAssumed, true

        SystLinSurResolu    :  solveur L1
                               ContraintesAssumed, false

        L2SysSurResol    :     solveur L2 , matrice pleine

        cFormQuadCreuse  :      solveur L2, matrice creuse !
*/



std::vector<cSsBloc> SomVSBl(const std::vector<cSsBloc> &,const std::vector<cSsBloc> &);

class cTestPbChol
{
     public :
       cTestPbChol(const std::string & aName);
       std::string mName;
       double  mMinVP;
       double  mMinSomVNeg;
};




class cGenSysSurResol 
{
     public :

           ElMatrix<double_t>  MatQuad() const;

          virtual double CoeffNorm() const;

//  FONCTION LIEES AU DEBUG DES  VALEUR <0 DANS CHOLESKY SUR PIAZZABRA
          void VerifGlob(const std::vector<cSsBloc> &,bool doCheck,bool doSVD,bool doV0);
          void BasicVerifMatPos(const std::vector<cSsBloc> &,int );

          void VerifMatPos(ElMatrix<double_t>,ElMatrix<double_t>  aLambda,cTestPbChol & aTPC,const std::vector<cSsBloc> &);
          void VerifMatPos(const ElMatrix<double_t> & ,const ElMatrix<double_t> & aLambda,cTestPbChol & aTPC,const std::vector<cSsBloc> &,const std::vector<cSsBloc> &);

 // Mode 0 =  Null ou non   *-
         void ShowGSR(int aMode);

         virtual void VerifGSS(const std::string & aMes) ;

         bool  OptSym() const;
         virtual void AddOneBloc(const cSsBloc &,const cSsBloc &, double_t aPds,double_t * aCoeff);
         virtual void AddOneBlocDiag(const cSsBloc &, double_t aPds,double_t * aCoeff);
         virtual void AddOneBlocCste(const cSsBloc &, double_t aPds,double_t * aCoeff,double_t aB);


        // void toto(const std::vector<cSsBloc>  &);

         virtual ~cGenSysSurResol();
         cGenSysSurResol(bool CstrAssumed,bool OptSym,bool GereNonSym,bool GereBloc);

         Im1D_double_t8  GSSR_Solve(bool * aResOk) ;
         void GSSR_Reset(bool WithCstr) ;

     //           aPds (aCoeff . X = aB) 
         void GSSR_AddNewEquation 
              (
                   double_t aPds,
                   double_t * aCoeff,
                   double_t aB,
                   double * aCoordCur  // Pour les contra univ, peut etre NULL
               );

     //  Pour resoudre, de maniere  simplifiee, une equation 
     //   en Ax et B de la forme
     //       Ax* Xi + B = Yi
     //   Typiquement pour fitter une droite
	void GSSR_Add_EqFitDroite(double_t aXi,double_t aYi,double_t aPds=1.0);
	void GSSR_SolveEqFitDroite(double_t & aAx,double_t &aB,bool * Ok=0);

     //  Pour resoudre, de maniere  simplifiee, une equation 
     //   en Ax et By et C de la forme
     //       Ax* Xi + By * Yi + C = Zi
     //   Typiquement pour fitter un plan
	void GSSR_Add_EqFitPlan(double_t aXi,double_t aYi,double_t aZi,double_t aPds=1.0);
	void GSSR_SolveEqFitPlan(double_t & aAx,double_t &aB,double_t & aC,bool * Ok=0);


     // Pour calculer des pseudo-intersection de droite ou de plan 3D
	 Pt3dr Pt3dSolInter(bool * Ok=0);


	 //  Ajoute une contrainte, sous la forme aC. X = aE 
	 //  sous laquelle sera resolu le systeme
	 //  L'ensemble des contrainte doit forme un systeme libre
         // void GSSR_AddContrainte (double_t * aC,double_t aE);
         void GSSR_AddContrainteIndexee (const std::vector<int> & aVI,double_t * aC,double_t aE);

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
		           double_t aPds,double_t ** aMat,
			   double_t * aVect,double_t aCste
                      );



	 void GSSR_AddNewEquation_Indexe( const std::vector<cSsBloc> *aVSB,
                                          double *  FullCoeff,
                                          int aNbTot,
                                          const std::vector<int> & aVInd ,
			                double_t aPds,double_t * aCoeff,double_t aB);
         // GSSR_AddNewEquation_Indexe fait des pretraitement de prise en compte des contraintes
         // qu'on ne doit pas faire toujours
	 void Basic_GSSR_AddNewEquation_Indexe(
                                        const std::vector<cSsBloc> * aVSB,
                                        double *  FullCoeff,
                                        int aNbTot,
                                        const std::vector<int> & aVInd ,
			                double_t aPds,double_t * aCoeff,double_t aB);

         // Def = Erreur fatale, n'a pas de sens pout systeme L1
         virtual double_t   GetElemQuad(int i,int j) const;
         virtual void  SetElemQuad(int i,int j,const double_t& );
         virtual double_t  GetElemLin(int i) const;
         virtual void  SetElemLin(int i,const double_t& ) ;

	 // Pour ces 4 Fon, Def, utilise GetElemQuad-GetElemLin

/*
         virtual void Indexee_EcrireDansMatrColWithLin
	      (ElMatrix<double> &aMatr,const std::vector<int> & aVInd) const;
*/
         virtual void Indexee_EcrireDansMatrWithQuad
	      (  ElMatrix<double_t> &aMatr,
	         const std::vector<int> & aVIndx,
		 const std::vector<int> & aVIndy
              )   const;
         virtual void Indexee_LinSet0  (const std::vector<int> & aVInd);
         virtual void Indexee_QuadSet0 (const std::vector<int> & aVIndx,
	                                const std::vector<int> & aVIndy);


         virtual void Indexee_EcrireDansMatrColWithLin
	      (ElMatrix<double_t> &aMatr,const std::vector<cSsBloc> &  aVx) const;
         virtual void Indexee_EcrireDansMatrWithQuad
	      (   ElMatrix<double_t> &aMatr,
                  const std::vector<cSsBloc> &  aVx,
                  const std::vector<cSsBloc> &  aVy
              )   const;

         virtual void Indexee_LinSet0  (const std::vector<cSsBloc> & aVInd);
         virtual void Indexee_QuadSet0 (const std::vector<cSsBloc> & aVIndx,
	                                const std::vector<cSsBloc> & aVIndy);




         virtual void Indexee_UpdateLinWithMatrCol
	      (const ElMatrix<double_t> &aMatr,const std::vector<int> & aVInd);
         virtual void Indexee_UpdateQuadWithMatr
	      (  const ElMatrix<double_t> &aMatr,
	         const std::vector<int> & aVIndx,
		 const std::vector<int> & aVIndy
              )  ;

         virtual void Indexee_SoustraitMatrColInLin
	      (const ElMatrix<double_t> &aMatr,const std::vector<cSsBloc> & aVInd);
         virtual void Indexee_SoustraitMatrInQuad
	      (  const ElMatrix<double_t> &aMatr,
	         const std::vector<int> & aVIndx,
		 const std::vector<int> & aVIndy
              )  ;

        virtual void SoutraitProduc3x3
                     (
                          bool                   Sym,
                          ElMatrix<double_t> &aM1,
                          ElMatrix<double_t> &aM2,
                          const std::vector<cSsBloc> * aYVSB
                     );
         

         virtual void Indexee_QuadSetId (const std::vector<int> & aVIndxy);

         void  SetPhaseEquation(const std::vector<int> *);

         virtual double  ResiduOfSol(const double *);
     protected :
	 virtual void V_GSSR_EqMatIndexee
                      (
                           const std::vector<int> & aVInd,
		           double_t aPds,double_t ** aMat,
			   double_t * aVect,double_t aCste
                      );
	 // Def = erreur fatale
	 virtual void V_GSSR_AddNewEquation_Indexe
		      ( 
                        const std::vector<cSsBloc> * aVSB,
                        double *  FullCoeff,
                        int aNbTot,
                        const std::vector<int> & aVInd ,
			double_t aPds,double_t * aCoeff,double_t aB);
 
         virtual Im1D_double_t8  V_GSSR_Solve(bool * aResOk) = 0;
         virtual void V_GSSR_Reset() = 0;
         virtual void V_GSSR_AddNewEquation
		      (double_t aPds,double_t * aCoeff,double_t aB) = 0;


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
	 ElMatrix<double_t> mC;
	 ElMatrix<double_t> mE;
	 ElMatrix<double_t> mtL;
	 ElMatrix<double_t> mtLC;
	 ElMatrix<double_t> mtLCE;

	 ElMatrix<double_t> mSol;
	 ElMatrix<double_t> mCSol;

         GaussjPrec     mGP;
// Gestion des contraintes , nouvelle prise en compte specifique des contraintes
// univariees 
         bool        mNewCstrIsInit;
         bool        mNewCstrIsTraitee;
         bool        mUseSpeciCstrUniVar;  // a priori tjs true, false permet de revenir en arriere
         Im1D_double_t8  mValCstr;
         double *    mDValCstr;
         Im1D_U_int1 mIsCstr;
         U_int1 *    mDIsCstr;
};


class cVectMatMul
{
    public :
       virtual void VMMDo(Im1D_double_t8 in,Im1D_double_t8 out) = 0;
       virtual ~cVectMatMul();
};
// Meme classe a priori que cVectMatMul, mais comme les matrice doivent en heriter deux fois ....
class cVectPreCond
{
    public :
       virtual void VPCDo(Im1D_double_t8 in,Im1D_double_t8 out) = 0;
       virtual ~cVectPreCond();
};

struct cControleGC
{
     public :
          cControleGC(int aNbIterMax);

          const int mNbIterMax;
};

bool GradConjPrecondSolve
     (
            cVectMatMul&,
            cVectPreCond&,
            Im1D_double_t8  aImB,
            Im1D_double_t8  aImXSol,
            const cControleGC &
     );



class cFormQuadCreuse : public cVectMatMul,
                        public cVectPreCond,
                        public FoncNVarDer<double_t>,
                        public cGenSysSurResol
{
      // mVO + mFLin . X + 1/2 tX mMat X
      public :
          virtual double CoeffNorm() const;
         virtual double  ResiduOfSol(const double *);
         virtual void VerifGSS(const std::string & aMes) ;
         
	  bool  	AcceptContrainteNonUniV() const;
          cFormQuadCreuse(int aNbVar,cElMatCreuseGen * aMatCr);
	  void AddDiff(Fonc_Num,const ElGrowingSetInd &);
	  void AddDiff(Fonc_Num);
	  virtual ~cFormQuadCreuse();

          virtual void GradFNV(double_t *grad,const double_t *   v) ;
          virtual double_t ValFNV(const double_t *  v) ;
 
	 void SetOffsets(const std::vector<int> & aVIndexes);
	 bool GSSR_UseEqMatIndexee();
         // aCste + aVect . X + 1/2 tX aMat X
	 void V_GSSR_EqMatIndexee
                      (
                           const std::vector<int> & aVInd,
		           double_t aPds,double_t ** aMat,
			   double_t * aVect,double_t aCste
                      );
         virtual double_t   GetElemQuad(int i,int j) const;
         virtual void  SetElemQuad(int i,int j,const double_t& );
         virtual double_t  GetElemLin(int i) const;
         virtual void  SetElemLin(int i,const double_t& ) ;


         virtual void SoutraitProduc3x3
                     (
                          bool                   Sym,
                          ElMatrix<double_t> &aM1,
                          ElMatrix<double_t> &aM2,
                          const std::vector<cSsBloc> * aYVSB
                     );
           
         virtual void Indexee_EcrireDansMatrWithQuad
                      (
                             ElMatrix<double_t> &aMatr,
                             const std::vector<cSsBloc> &  aVx,
                             const std::vector<cSsBloc> &  aVy
                      )  const;

         virtual void  Indexee_QuadSet0
                       (
                              const std::vector<cSsBloc> & aVx,
                              const std::vector<cSsBloc> & aVy
                       );



         
      private :
           void VMMDo(Im1D_double_t8 in,Im1D_double_t8 out);
           void VPCDo(Im1D_double_t8 in,Im1D_double_t8 out);



           // void SMFGC_Atsub(double *in,double *out,int) ;

	  virtual void V_GSSR_AddNewEquation_Indexe
		      (
                        const std::vector<cSsBloc> * aVSB,
                        double *  FullCoeff,
                        int aNbTot,
                        const std::vector<int> & aVInd ,
			double_t aPds,double_t * aCoeff,double_t aB);
	 virtual int NbVar() const ;
         virtual Im1D_double_t8  V_GSSR_Solve(bool * aResOk) ;
         virtual void V_GSSR_Reset() ;
         virtual void V_GSSR_AddNewEquation
		      (double_t aPds,double_t * aCoeff,double_t aB) ;

	  int                mNbVar;
	  double_t               mV0;
	  Im1D<double_t,double_t>  mFLin;
	  double_t *          mDataLin;
	  Im1D_double_t8         mVGrad;
	  double_t8 *            mDataGrad;
	  cElMatCreuseGen *  mMat;
	  ElGrowingSetInd *  mEGSI;
	  PtsKD           *  mP000;

          bool mMatIsOptForEcrireInMatr;
          bool mMatIsOptForSousP3x3;
          bool mMatIsOptForQuadSet0;
          bool mMatIsOptForAddEqIndexee;
};


/*
    SymBlocMatr :

     void cGenSysSurResol::Indexee_EcrireDansMatrWithQuad
     (
            ElMatrix<double> &aMatr,
            const std::vector<cSsBloc> &  aVx,
            const std::vector<cSsBloc> &  aVy
     )  const;


         virtual void Indexee_EcrireDansMatrColWithLin
	      (ElMatrix<double> &aMatr,const std::vector<cSsBloc> &  aVx) const;

         virtual void Indexee_LinSet0  (const std::vector<cSsBloc> & aVInd);
         virtual void Indexee_QuadSet0 (const std::vector<cSsBloc> & aVIndx,
	                                const std::vector<cSsBloc> & aVIndy);
        virtual void SoutraitProduc3x3
                     (
                          bool                   Sym,
                          ElMatrix<double> &aM1,
                          ElMatrix<double> &aM2,
                          const std::vector<cSsBloc> * aYVSB,
                          const std::vector<int> & aVIndy
                     );
         
*/


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

         Im1D_double_t8  V_GSSR_Solve(bool * aResOk);
         void V_GSSR_Reset();
         void V_GSSR_AddNewEquation(double_t aPds,double_t * aCoeff,double_t aB);

         void AddTermLineaire(int aK,double_t aVal);
         void AddTermQuad(int aK1,int aK2,double_t aVal);



        L2SysSurResol (int aNbVar,bool IsSym=true);
        void SetSize(int aNbVar);
        void GetMatr(ElMatrix<double_t> & M,ElMatrix<double_t> & tB);

     // Ajoute   :  
     //           aPds (aCoeff . X = aB) 

        void AddEquation(double_t aPds,double_t * aCoeff,double_t aB);
        void Reset();
        Im1D_double_t8  Solve(bool * aResOk);
        Pt3d<double>  Solve3x3Sym(bool * OK);

	int NbVar() const;


	 virtual bool GSSR_UseEqMatIndexee();
         // aCste + aVect . X + 1/2 tX aMat X
	 virtual void V_GSSR_EqMatIndexee
                      (
                           const std::vector<int> & aVInd,
		           double_t aPds,double_t ** aMat,
			   double_t * aVect,double_t aCste
                      );
         virtual double_t   GetElemQuad(int i,int j) const;
         virtual void  SetElemQuad(int i,int j,const double_t& );
         virtual double_t  GetElemLin(int i) const;
         virtual void  SetElemLin(int i,const double_t& ) ;

	  Im2D_double_t8   tLi_Li(); // Sigma des trans(Li) Li

     private :
	  virtual void V_GSSR_AddNewEquation_Indexe
                      (  const std::vector<cSsBloc> * aVSB,
                        double *  FullCoeff,
                        int aNbTot,
		         const std::vector<int> & aVInd ,
			double_t aPds,double_t * aCoeff,double_t aB);

        int          mNbVar;
	Im2D_double_t8   mtLi_Li; // Sigma des trans(Li) Li
        double_t8 **     mDatatLi_Li;
	Im2D_double_t8   mInvtLi_Li;    // Inverse Sigma des trans(Li) Li
        double_t8 **     mDataInvtLi_Li;
        Im1D_double_t8   mbi_Li;  // Sigma des bi * Li
        double_t8 *      mDatabi_Li;
        double_t8        mBibi;
        Im1D_double_t8   mSolL2;
        double_t8 *      mDataSolL2;
        int          mNbEq; // Debug
        double       mMaxBibi; // Debug
};

// Classe Adaptee au contexte bcp d'equations, (relativement) peu de variable
// avec necessite de memoriser ttes les equation (parceque, par exemple)
// resolution L1-barrodale, our resolution par moindre carres ponderes.
//
// En fait, typiquement tout ce qui est estimateur robuste

class  SystLinSurResolu : public cGenSysSurResol  // Herite en tant que Solveur L1
{
	public :
               Im1D_double_t8  V_GSSR_Solve(bool * aResOk);
               void V_GSSR_Reset();
               void V_GSSR_AddNewEquation(double_t aPds,double_t * aCoeff,double_t aB);
	        int NbVar() const;

               SystLinSurResolu(int NbVar,int NbEq);

                  void SetSize(int NbVar,int NbEq);
			void SetNbEquation(int aNbEq);
			void SetNoEquation();


			void PushDifferentialEquation
			     (
                                   Fonc_Num      aFonc,
                                   const PtsKD & aPts,
                                   double_t          aPds = 1.0
                             );
			void PushEquation
			     (
                                   Im1D_double_t8    aFormLin,
				   double_t          aValue,
                                   double_t          aPds = 1.0
                             );
			void PopEquation();
			void PushEquation
			     (
                                   double_t8 *       aFormLin,
				   double_t          aValue,
                                   double_t          aPds = 1.0
                             );

			Im1D_double_t8  L1Solve();
			// Si Ok ==0, matrice sing => erreur fatale
			Im1D_double_t8  L2Solve(bool *Ok); 

			// Non Pondere, signe
			double_t Residu(Im1D_double_t8,int iEq) const; 
			// Pondere :
			double_t L2SomResiduPond(Im1D_double_t8)const; 
			int NbEq() const;

			double_t Pds(int iEq) const;
			double_t CoefLin(int iVar,int iEq) const;
			double_t CoefCste(int iEq) const;

			double_t Residu(const double_t *,int iEq) const; 
		protected :
		private :

                        void AdjustSizeCapa();
			void BarrodaleSetSize();
			void L2SetSize();
			void AssertIndexEqValide(int IndEq) const;
			void AssertIndexVarValide(int IndEq) const;
			void AssertIndexGoodNbVar(int aNbVar) const;


			int          mNbVarCur;
			int          mNbEqCur;
			int          mNbVarCapa;
			int          mNbEqCapa;

			Im2D_double_t8   mA;  // mA.data() [IEqu][Ivar]
			double_t8 **     mDataA;
			Im1D_double_t8   mB;
			double_t8 *      mDataB;
			Im1D_double_t8   mPds;
			double_t8 *      mDataPds;


			// variables tempo pour  L1 Barrodale
			Im1D_double_t8   mBarodA;
			double_t8 *      mDataBarodA;
			Im1D_double_t8   mBarodB;
			double_t8 *      mDataBarodB;
			Im1D_double_t8   mBarodSOL;
			double_t8 *      mDataBarodSOL;
			Im1D_double_t8   mBarodRESIDU;
			double_t8 *      mDataBarodRESIDU;
		
			// variables tempo pour  L2-Gaussj
			// Pour resoudre au moindre carre
			// Li X = bi

                         L2SysSurResol mL2;
		
/*
			 Im2D_double_t8   mtLi_Li; // Sigma des trans(Li) Li
                         double_t8 **     mDatatLi_Li;
			 Im1D_double_t8   mbi_Li;  // Sigma des bi * Li
                         double_t8 *      mDatabi_Li;
			 Im1D_double_t8   mSolL2;
                         double_t8 *      mDataSolL2;
*/

};


class cOptimSommeFormelle
{
     public :
	 cOptimSommeFormelle(int aNbVar);
	 ~cOptimSommeFormelle();
	 void Add(Fonc_Num,bool CasSpecQuad = true);

	 int GradConjMin(double_t *,double_t ftol,int ITMAX);
	 int GradConjMin(PtsKD & ,double_t ftol,int ITMAX);
	 void Show() ; // Debug purpose
	 int Dim() const;

         double_t ValFNV(const double_t *  v) ;
         void GradFNV(double_t *grad,const double_t *   v);

     private :
	 cOptimSommeFormelle(const cOptimSommeFormelle &); // Undef 

	 class cMin : public FoncNVarDer<double_t> 
	 {
              public :
                 cMin(cOptimSommeFormelle &);
              private :
                 double_t ValFNV(const double_t *  v) ;
                 void GradFNV(double_t *grad,const double_t *   v);

		 cOptimSommeFormelle & mOSF;
	 };
         friend class cMin;




	 void SetPts(const double_t *);
  
         int                   mNbVar;
	 std::vector<Fonc_Num> mTabDP;
	 Fonc_Num              mSomme;
	 ElGrowingSetInd       mSetInd;
	 PtsKD *               mPts;

         cElMatCreuseGen*      mMatCr;
	 cFormQuadCreuse       mQuadPart;
};


class Optim_L1FormLin
{
     public :

        // Soit N le nombre de variable et M le nombre de contrainte
        // Flin de taille (N+1,M)


        Optim_L1FormLin (const ElMatrix<double_t> &Flin );

        ElMatrix<double_t> Solve();

        static void bench();
        double_t score(const ElMatrix<double_t> & M); // M : (1,N)


        ElMatrix<double_t> MpdSolve();
        ElMatrix<double_t> BarrodaleSolve();

     private :

       class  AbscD1
       {
           public :
               AbscD1(ElMatrix<double_t> & sc,int ind);

               double_t _x0;
               double_t _pds;
               int  _k;
              inline bool operator < (const AbscD1 &) const;
       };

        double_t EcartVar(int v);
        int RandF();
        bool get_sol_adm(ElFilo<int> & SubSet);
        void BenchCombin(double_t val);
        double_t MinCombin();
        void MinCombin
             (
                   ElFilo<int> & CurSubset, ElFilo<int> & BestSet,
                   double_t & ScMin,int NbVarPos,int CurVarPos
             );

        double_t score(ElFilo<int> & SubSet);
        double_t Kth_score(const ElMatrix<double_t> & M,int k); // M : (N,1)

        bool ExploreChVARBov
             (
                ElFilo<int> & SubSet,
                double_t        & sc_min,
                int kv
             );
        bool ExploreChVAR
             (
                ElFilo<int> & SubSet,
                double_t        & sc_min,
                int kv
             );





        bool Sol(const  ElFilo<int> & SubSet);

        int _NbVar;
        int _NbForm;
		int _NbStep;

        ElMatrix<double_t> _Flin;

        GaussjPrec     _GP;
        ElMatrix<double_t> & _MGauss;
        ElMatrix<double_t> & _MVGauss;
        ElMatrix<double_t> & _Sol;                           

        ElMatrix<double_t> _SolDirRech;
        ElMatrix<double_t> _Scal1D;

        ElMatrix<double_t>    _BestSol;
        bool              _bench_comb_made;
        std::vector<AbscD1>    _vad1;

        static Optim_L1FormLin RandOLF(int NbVar,int NbForm,int Nb0 = 0);
        static void BenchRand(int NbVar,int NbForm,int NbTest,bool Comb);

        static void BenchRandComb(int NbVar,int NbForm);
        static void BenchRandComb();



        // Pour le bench "dur" sur les minimum  locaux 

        void SubsetOfFlags(ElFilo<int> & Subset,int flag);

        void CombinConjMinLoc
             (
                ElFilo<double_t>&  dic,
                ElFilo<int> &  Subset,
                ElFilo<int> &  FlagPos,
                int            FlagSubset,
                int            NbVarPos,
                int            CurVarPos
             );


        void show_flag(int flag);

        double_t TestNeighConjMinLoc(int FlagSubset,ElFilo<double_t>&  dic);

        void CombinConjMinLoc
             (
                ElFilo<double_t>&  dic,
                ElFilo<int> &  Subset,
                ElFilo<int> &  FlagPos
             );
        static void CombinConjMinLoc
                    (
                         int N,
                         int M,
                         ElFilo<double_t>&  dic,
                         ElFilo<int> &  Subset,
                         ElFilo<int> &  FlagPos,
						 int            Nb0 = 0
                    );
        static void CombinConjMinLoc();

		void One_bench_craig();
		static  void bench_craig();
		static  void rand_bench_craig(int N,int M);
        
};                      

// Nunerics, roots of polyonme

double_t IRoots(double_t val,int exp);

ElMatrix<double_t8> MatrFoncMeanSquare
                (
                     Flux_Pts       flux,
                     std::list<Fonc_Num> Lfonc,
                     Fonc_Num       Obs,
                     Fonc_Num       Pds
                );

Fonc_Num ApproxFoncMeanSquare
         (
            Flux_Pts       flux,
            std::list<Fonc_Num> Lfonc,
            Fonc_Num       Obs,
            Fonc_Num       Pds
         );

	
Fonc_Num SomPondFoncNum
         (
		   std::   list<Fonc_Num> Lfonc,
			  ElMatrix<double_t8>
		 );
template <class Type> class cMSymCoffact3x3
{
public:
    Type a;
    Type e;
    Type i;
    Type b;
    Type c;
    Type f;

    Type mA;
    Type mE;
    Type mI;
    Type mB;
    Type mC;
    Type mF;
    Type mDet;

    cMSymCoffact3x3(Type ** aMat);
    void CoffSetInv(Type **);
    Pt3d<Type>  CoffVecInv(const Type *) const;
};

class cAMD_Interf
{
    public :
         cAMD_Interf(int aNumberInc);
         void AddArc(int aN1,int aN2,bool VerifDup=false);

     // Renvoie un vecteur qui indique le rang de chaque indexe
     //  si V[0]=3, 0 est le troisiem el (et non, 3 est le premier)
         std::vector<int> DoRank(bool Show=false) ;
    private :
         void VerifN(int aN) const;
         int                           mNb;
         std::vector<std::vector<int> > mV;

};


int amd_demo_1 (void);


/*   
    0 = (p0 x + p1 y + p2 z + p3) - I (p8 x + p9 y + p10 z + p11)
    0 = (p4 x + p5 y + p6 z + p7) - J (p8 x + p9 y + p10 z + p11)
*/


class cEq12Parametre
{
    public :
        cEq12Parametre();
        void AddObs(const Pt3dr & aPGround,const Pt2dr & aPPhgr,const double&  aPds);

        // Cam 2 Monde
        std::pair<ElMatrix<double>,Pt3dr> ComputeNonOrtho();

        // Intrinseques + extrinseques
        std::pair<ElMatrix<double>,ElRotation3D > ComputeOrtho();

    private :
        L2SysSurResol mSys;
        std::vector<Pt3dr>  mVPG;
        std::vector<Pt2dr>  mVPPhgr;
        std::vector<double> mVPds;

        void ComputeOneObs(const Pt3dr & aPGround,const Pt2dr & aPPhgr,const double&  aPds);

        // Indexe et valeur permettant de fixer l'arbitraire
        int    mIndFixArb;
        double mValueFixArb;
};

#endif  // _ELISE_GENERAL_OPTIM_H

