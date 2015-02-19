#ifndef _ELISE_GENERAL_OPTIM_OPTIM_L1FORMLIN_H
#define _ELISE_GENERAL_OPTIM_OPTIM_L1FORMLIN_H

#include "general/sys_dep.h"

class Optim_L1FormLin
{
     public :

        // Soit N le nombre de variable et M le nombre de contrainte
        // Flin de taille (N+1,M)


        Optim_L1FormLin (const ElMatrix<REAL> &Flin );

        ElMatrix<REAL> Solve();

        static void bench();
        REAL score(const ElMatrix<REAL> & M); // M : (1,N)


        ElMatrix<REAL> MpdSolve();
        ElMatrix<REAL> BarrodaleSolve();

     private :

#ifndef _ELISE_GENERAL_OPTIM_ABSCD1_H
#define _ELISE_GENERAL_OPTIM_ABSCD1_H

#include "general/sys_dep.h"

       class  AbscD1
       {
           public :
               AbscD1(ElMatrix<REAL> & sc,INT ind);

               REAL _x0;
               REAL _pds;
               INT  _k;
              inline bool operator < (const AbscD1 &) const;
       };

        REAL EcartVar(INT v);
        INT RandF();
        bool get_sol_adm(ElFilo<INT> & SubSet);
        void BenchCombin(REAL val);
        REAL MinCombin();
        void MinCombin
             (
                   ElFilo<INT> & CurSubset, ElFilo<INT> & BestSet,
                   REAL & ScMin,INT NbVarPos,INT CurVarPos
             );

        REAL score(ElFilo<INT> & SubSet);
        REAL Kth_score(const ElMatrix<REAL> & M,INT k); // M : (N,1)

        bool ExploreChVARBov
             (
                ElFilo<INT> & SubSet,
                REAL        & sc_min,
                INT kv
             );
        bool ExploreChVAR
             (
                ElFilo<INT> & SubSet,
                REAL        & sc_min,
                INT kv
             );





        bool Sol(const  ElFilo<INT> & SubSet);

        INT _NbVar;
        INT _NbForm;
		INT _NbStep;

        ElMatrix<REAL> _Flin;

        GaussjPrec     _GP;
        ElMatrix<REAL> & _MGauss;
        ElMatrix<REAL> & _MVGauss;
        ElMatrix<REAL> & _Sol;                           

        ElMatrix<REAL> _SolDirRech;
        ElMatrix<REAL> _Scal1D;

        ElMatrix<REAL>    _BestSol;
        bool              _bench_comb_made;
        std::vector<AbscD1>    _vad1;

        static Optim_L1FormLin RandOLF(INT NbVar,INT NbForm,INT Nb0 = 0);
        static void BenchRand(INT NbVar,INT NbForm,INT NbTest,bool Comb);

        static void BenchRandComb(INT NbVar,INT NbForm);
        static void BenchRandComb();



        // Pour le bench "dur" sur les minimum  locaux 

        void SubsetOfFlags(ElFilo<INT> & Subset,INT flag);

        void CombinConjMinLoc
             (
                ElFilo<REAL>&  dic,
                ElFilo<INT> &  Subset,
                ElFilo<INT> &  FlagPos,
                INT            FlagSubset,
                INT            NbVarPos,
                INT            CurVarPos
             );


        void show_flag(INT flag);

        REAL TestNeighConjMinLoc(INT FlagSubset,ElFilo<REAL>&  dic);

        void CombinConjMinLoc
             (
                ElFilo<REAL>&  dic,
                ElFilo<INT> &  Subset,
                ElFilo<INT> &  FlagPos
             );
        static void CombinConjMinLoc
                    (
                         INT N,
                         INT M,
                         ElFilo<REAL>&  dic,
                         ElFilo<INT> &  Subset,
                         ElFilo<INT> &  FlagPos,
						 INT            Nb0 = 0
                    );
        static void CombinConjMinLoc();

		void One_bench_craig();
		static  void bench_craig();
		static  void rand_bench_craig(INT N,INT M);
        
};                      

#endif
