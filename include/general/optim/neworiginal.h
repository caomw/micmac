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


// NROptF1vDer : Num Recipes Optimisation de Fonction d'1 var, Derivable 








class AllocateurDInconnues;





// Classe pour gerer rapidement des ensemble entier;
// Permet de cumuler les avantages d'un "std::set" et 
// d'un "std::vector<bool> du point de vue ajout, consultation
// par contre, pas de suppression
// 
// On essaye d'avoir le max de compatibilite avec les set de 
// la stl.





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







// Meme classe a priori que cVectMatMul, mais comme les matrice doivent en heriter deux fois ....

struct cControleGC
{
     public :
          cControleGC(int aNbIterMax);

          const int mNbIterMax;

bool GradConjPrecondSolve
     (
            cVectMatMul&,
            cVectPreCond&,
            Im1D_double_t8  aImB,
            Im1D_double_t8  aImXSol,
            const cControleGC &
     );





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



// Classe Adaptee au contexte bcp d'equations, (relativement) peu de variable
// avec necessite de memoriser ttes les equation (parceque, par exemple)
// resolution L1-barrodale, our resolution par moindre carres ponderes.
//
// En fait, typiquement tout ce qui est estimateur robuste






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



int amd_demo_1 (void);


/*   
    0 = (p0 x + p1 y + p2 z + p3) - I (p8 x + p9 y + p10 z + p11)
    0 = (p4 x + p5 y + p6 z + p7) - J (p8 x + p9 y + p10 z + p11)
*/



#endif  // _ELISE_GENERAL_OPTIM_H

