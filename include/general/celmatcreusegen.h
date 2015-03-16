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


#ifndef _ELISE_GENERAL_OPTIM_CELMATCREUSEGEN_H
#define _ELISE_GENERAL_OPTIM_CELMATCREUSEGEN_H

#include <cIncIntervale>
#include <ElMatrix>
#include <Im1D>

#include <vector>


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
    virtual bool DirectInverse(const double *,double *);

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
    void  MulVect8(double_t * out,const double_t * in) ;
    Im1D<double_t,double_t> MulVect(Im1D<double_t,double_t>) const;

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
    Im1D_REAL8         mDiagPreCond;
    double *           mDDPrec;
};

#endif
