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


#ifndef _ELISE_GENERAL_OPTIM_CFORMQUADCREUSE_H
#define _ELISE_GENERAL_OPTIM_CFORMQUADCREUSE_H

#include "general/sys_dep.h"

#include <cVectMatMul>
#include <cVectPreCond>
#include <FoncNVarDer>
#include <cGenSysSurResol>

class cElMatCreuseGen;

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
           void VMMDo(Im1D_REAL8 in,Im1D_REAL8 out);
           void VPCDo(Im1D_REAL8 in,Im1D_REAL8 out);



           // void SMFGC_Atsub(double *in,double *out,int) ;

	  virtual void V_GSSR_AddNewEquation_Indexe
		      (
                        const std::vector<cSsBloc> * aVSB,
                        double *  FullCoeff,
                        int aNbTot,
                        const std::vector<int> & aVInd ,
                        double_t aPds,double_t * aCoeff,double_t aB);
         virtual int NbVar() const ;
         virtual Im1D_REAL8  V_GSSR_Solve(bool * aResOk) ;
         virtual void V_GSSR_Reset() ;
         virtual void V_GSSR_AddNewEquation
                      (double_t aPds,double_t * aCoeff,double_t aB) ;

          int                mNbVar;
          double_t               mV0;
	  Im1D<double_t,double_t>  mFLin;
	  double_t *          mDataLin;
          Im1D_REAL8         mVGrad;
          double_t *            mDataGrad;
	  cElMatCreuseGen *  mMat;
	  ElGrowingSetInd *  mEGSI;
	  PtsKD           *  mP000;

          bool mMatIsOptForEcrireInMatr;
          bool mMatIsOptForSousP3x3;
          bool mMatIsOptForQuadSet0;
          bool mMatIsOptForAddEqIndexee;
};

#endif
