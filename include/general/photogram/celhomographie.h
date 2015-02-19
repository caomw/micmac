#ifndef _ELISE_GENERAL_PHOTOGRAM_CELHOMOGRAPHIE_H
#define _ELISE_GENERAL_PHOTOGRAM_CELHOMOGRAPHIE_H

#include "general/sys_dep.h"

class cElHomographie
{
public :
    bool HasNan() const;
    Pt2dr Direct  (const Pt2dr & aP) const;
    Pt2d<Fonc_Num> Direct (Pt2d<Fonc_Num> ) const;

    void Show();
    // Renvoie H tel que H(P1) = P2
    // Size = 0 , identite
    // Size = 1 , translation
    // Size = 2 , similitude
    // Size = 3 , affinite
    // Size = 4 ou +, homographie reelle, ajuste par moindre L2  ou  L1

    cElHomographie(const ElPackHomologue &,bool aL2);
    cElHomographie(const cXmlHomogr &);
    cXmlHomogr ToXml() const;

    static cElHomographie RansacInitH(const ElPackHomologue & aPack,int aNbRansac,int aNbMaxPts);

    static cElHomographie Id();
    static cElHomographie Homotie(Pt2dr aP,REAL aSc);  // -> tr + aSc * P
    static cElHomographie FromMatrix(const ElMatrix<REAL> &);

    void ToMatrix(ElMatrix<REAL> &) const;

    cElHomographie
    (
            const cElComposHomographie &,
            const cElComposHomographie &,
            const cElComposHomographie &
            );


    cElHomographie Inverse() const;
    cElHomographie operator * (const cElHomographie &) const;
    //     P ->  aChSacle * Pol(P/aChSacle)
    cElHomographie MapingChScale(REAL aChSacle) const;
    void write(class  ELISE_fp & aFile) const;
    static cElHomographie read(ELISE_fp & aFile);

    cElComposHomographie & HX();
    cElComposHomographie & HY();
    cElComposHomographie & HZ();

    const cElComposHomographie & HX() const;
    const cElComposHomographie & HY() const;
    const cElComposHomographie & HZ() const;

    // Renvoie sa representation matricielle en coordonnees homogenes
    ElMatrix<REAL>  MatCoordHom() const;
    static cElHomographie  RobustInit(double * aQuality,const ElPackHomologue & aPack,bool & Ok ,int aNbTestEstim, double aPerc,int aNbMaxPts);

    static cElHomographie SomPondHom(const std::vector<cElHomographie> & aVH,const std::vector<double> & aVP);


private :
    cElComposHomographie mHX;
    cElComposHomographie mHY;
    cElComposHomographie mHZ;

    void AddForInverse(ElPackHomologue & aPack,Pt2dr aP) const;
    void Normalize();
};

#endif
