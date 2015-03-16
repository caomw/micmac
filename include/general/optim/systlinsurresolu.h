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


#ifndef _ELISE_GENERAL_OPTIM_SYSTLINSURRESOLU_H
#define _ELISE_GENERAL_OPTIM_SYSTLINSURRESOLU_H

#include <cGenSysSurResol>

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

#endif
