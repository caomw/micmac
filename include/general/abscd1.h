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


#ifndef _ELISE_GENERAL_OPTIM_ABSCD1_H
#define _ELISE_GENERAL_OPTIM_ABSCD1_H

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

#endif
