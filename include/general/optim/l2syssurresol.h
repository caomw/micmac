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


#ifndef _ELISE_GENERAL_OPTIM_L2SYSSURRESOL_H
#define _ELISE_GENERAL_OPTIM_L2SYSSURRESOL_H

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

#endif
