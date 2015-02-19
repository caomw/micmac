#ifndef _ELISE_GENERAL_PHOTOGRAM_ELDISTORTION22_GEN_H
#define _ELISE_GENERAL_PHOTOGRAM_ELDISTORTION22_GEN_H

#include "general/sys_dep.h"
#include "XML_GEN/ParamChantierPhotogram.h"

#include <ElDistortionPolynomiale>

class ElDistortion22_Gen
{
public :
    virtual cCalibDistortion ToXmlStruct(const ElCamera *) const;
    void SetName(const char * aName);
    virtual std::string Type() const;
    std::string Name() const;

    static cCalibDistortion  XmlDistNoVal();
    virtual  cPreCondGrid GetAsPreCond() const;
    static ElDistortion22_Gen * AllocPreC
    (const cPreCondGrid&);


    REAL D1(const ElDistortion22_Gen &,Pt2dr P0, Pt2dr P1,INT NbEch) const;
    REAL D2(const ElDistortion22_Gen &,Pt2dr P0, Pt2dr P1,INT NbEch) const;
    REAL DInfini(const ElDistortion22_Gen &,Pt2dr P0, Pt2dr P1,INT NbEch) const;

    virtual Pt2dr Direct(Pt2dr) const = 0 ;    //
    Pt2dr Inverse(Pt2dr) const ; //  Pour inverser :
    //    (1) On tente le OwnInverse
    //    (2) Sinon on tente le  mPolynInv
    //    (3) Sinon on applique le ComputeInvFromDirByDiff


    ElMatrix<REAL> Diff(Pt2dr) const;  // Juste interf a "Diff(ElMatrix<REAL> &,..)"
    virtual ~ElDistortion22_Gen();

    // PolynLeastSquareInverse (REAL aDom,INT aDegre);

    ElDistortionPolynomiale NewPolynLeastSquareInverse
    (
            Box2dr aBox,
            INT  aDegre,
            INT  aNbPts = -1
            );
    Polynome2dReal  NewPolynLeastSquareInverse_OneCoord
    (
            bool XCoord,
            Box2dr aBox,
            INT  aDegre,
            INT  aNbPts = -1
            );
    //  aSc * Direct (aP/aSc*)
    // Def renvoit un objet contenant un pointeur sur this
    virtual ElDistortion22_Gen  * D22G_ChScale(REAL aS) const;
    virtual bool IsId() const; // Def false

    // Fonction "ad hoc" de dynamic cast, par defaut return 0, strict change pour PhgStd qui
    // ne se voit pas alors comme un cas particulier de DRad
    virtual ElDistRadiale_PolynImpair * DRADPol(bool strict = false);

    Box2dr ImageOfBox(Box2dr,INT aNbPtsDisc=8 );
    Box2dr ImageRecOfBox(Box2dr,INT aNbPtsDisc=8  );

    // Par defaut renvoie un objet contenant un pointeur sur this
    // et redirigeant Direct sur inverse et Lycee de Versailles
    virtual ElDistortion22_Gen * CalcInverse() const;
    void SetParamConvInvDiff(INT aNbIter,REAL aEps);

    void SaveAsGrid(const std::string&,const Pt2dr& aP0,const Pt2dr& aP1,const Pt2dr& aStep);

    // Def erreur fatale
    virtual Pt2dr  DirectAndDer(Pt2dr aP,Pt2dr & aGradX,Pt2dr & aGradY) const;

    // Est-ce que les distorsion savent se transformer  en F-1 D F ou F est une translation ou
    // une homotetie
    virtual  bool  AcceptScaling() const;
    virtual  bool  AcceptTranslate() const;

    //    Soit H (X) == PP + X * F   se transforme en H-1 D H
    void SetScalingTranslate(const double & F,const Pt2dr & aPP);

    double & ScN();
    const double & ScN() const;


    // ULTRA -DANGEREUX, rajoute a contre coeur, comme moyen d'inhiber la parie
    // Tgt-Argt des fishe-eye afin qu'il puisse calcule des pseudo inverse

    void    SetDist22Gen_UsePreConditionner(bool) const;  // Tous sauf const !!
    const bool &   Dist22Gen_UsePreConditionner() const;
    Pt2dr  ComputeInvFromDirByDiff ( Pt2dr aPt, Pt2dr InvEstim0, bool DiffReestim) const;

    void    SetDist22Gen_SupressPreCondInInverse(bool) const;  // Tous sauf const !!
    const bool &   Dist22Gen_SupressPreCondInInverse() const;

protected :

    void ErrorInvert() const;
    ElDistortion22_Gen();
    void DiffByDiffFinies(ElMatrix<REAL> &,Pt2dr,Pt2dr Eps) const;
    void DiffByDiffFinies(ElMatrix<REAL> &,Pt2dr,REAL Eps) const;

private :

    virtual  void V_SetScalingTranslate(const double &,const Pt2dr &);

    REAL DistanceObjet(INT tagDist,const ElDistortion22_Gen &,Pt2dr P0, Pt2dr P1,INT NbEch) const;


    ElDistortionPolynomiale * mPolynInv;

    virtual void  Diff(ElMatrix<REAL> &,Pt2dr) const ;  //  differentielle
    // Def err fatale



    // Defaut 0,0 pas forcement le meilleur choix mais
    // compatibilite anterieure

public :
    virtual Pt2dr GuessInv(const Pt2dr & aP) const ;
private :
    virtual bool OwnInverse(Pt2dr &) const ;    //  return false


protected :
    REAL mEpsInvDiff;
    INT  mNbIterMaxInvDiff;
private :
    double mScN;
    bool   mDist22Gen_UsePreConditionner;
    bool   mDist22Gen_SupressPreCondInInverse;
protected :
    const char * mName;
private :
};

#endif
