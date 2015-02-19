#ifndef _ELISE_GENERAL_PHOTOGRAM_CDISTORBILIN_H
#define _ELISE_GENERAL_PHOTOGRAM_CDISTORBILIN_H

#include "general/sys_dep.h"

#include <ElDistortion22_Gen>

class cDistorBilin :   public ElDistortion22_Gen
{
public :
    friend class cPIF_Bilin;

    friend void Test_DBL();

    cDistorBilin(Pt2dr aSz,Pt2dr aP0,Pt2di aNb);
    Pt2dr Direct(Pt2dr) const ;

    Pt2dr & Dist(const Pt2di aP) {return mVDist[aP.x + aP.y*(mNb.x+1)];}
    const Pt2dr & Dist(const Pt2di aP) const {return mVDist[aP.x + aP.y*(mNb.x+1)];}
    const Pt2di & Nb() const {return mNb ;}


    virtual cCalibDistortion ToXmlStruct(const ElCamera *) const;
    cCalibrationInterneGridDef ToXmlGridStruct() const;

    static cDistorBilin FromXmlGridStuct(const cCalibrationInterneGridDef & );


    bool  AcceptScaling() const;
    bool  AcceptTranslate() const;
    void V_SetScalingTranslate(const double &,const Pt2dr &);

private  :
    //  ==== Tests ============
    Box2dr BoxRab(double aMulStep) const;
    void Randomize(double aFact=0.1);
    void InitAffine(double aF,Pt2dr aPP);

    //  =============
    void  Diff(ElMatrix<REAL> &,Pt2dr) const;
    Pt2dr ToCoordGrid(const Pt2dr &) const;
    Pt2dr FromCoordGrid(const Pt2dr &) const;
    // Renvoie le meilleur interval [X0, X0+1[ contenat aCoordGr, valide qqsoit aCoordGr
    void GetDebInterval(int & aX0,const int & aSzGrd,const double & aCoordGr) const;
    //  tel que aCoordGr soit le barry de (aX0,aX0+1) avec (aPdsX0,1-aPdsX0)  et 0<= aX0 < aSzGr, aX0 entier
    void GetDebIntervalAndPds(int & aX0,double & aPdsX0,const int & aSzGrd,const double & aCoordGr) const;
    //  A partir d'un points en coordonnees grille retourne le coin bas-gauche et le poids
    void GetParamCorner(Pt2di & aCornerBG,Pt2dr & aPdsBG,const Pt2dr & aCoorGr) const;
    void InitEtatFromCorner(const Pt2dr & aCoorGr) const;

    Pt2dr                               mP0;
    Pt2dr                               mP1;
    Pt2dr                               mStep;
    Pt2di                               mNb;
    std::vector<Pt2dr >                 mVDist;

    mutable Pt2di                               mCurCorner;
    mutable double                              mPds[4];
};

#endif
