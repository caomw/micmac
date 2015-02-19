#ifndef _ELISE_GENERAL_PHOTOGRAM_ELDISTRADIALE_POLYNIMPAIR_H
#define _ELISE_GENERAL_PHOTOGRAM_ELDISTRADIALE_POLYNIMPAIR_H

#include "general/sys_dep.h"

class ElDistRadiale_PolynImpair  : public ElDistRadiale // polynome en r de degre impair
{
public :
    // Pour eviter les comportements sinuguliers
    // si R > RMax on remplace par la differentielle en RMax


    ElDistRadiale_PolynImpair(REAL RMax,Pt2dr centre);
    void ActuRMaxFromDist(Pt2di aSz);
    void ActuRMax();
    void SetRMax(REAL aV);
    virtual REAL DistDirecte(REAL) const;
    REAL DistDirecteR2NoSeuil(REAL R) const ;
    virtual REAL DistDirecteR2(REAL) const;
    virtual REAL DerSurRho(REAL) const;

    void PushCoeff(REAL); // Premiere fois fixe r3 , etc ....
    void PushCoeff(const std::vector<REAL> &); // Premiere fois fixe r3 , etc ....
    REAL & Coeff(INT k);
    REAL  Coeff(INT k) const;
    INT NbCoeff() const;
    INT NbCoeffNN() const;  // Elimine les eventuelles coefficient nul rajoutes
    void VerifCoeff(INT aK) const;
    REAL   CoeffGen(INT aK) const;


    ElDistRadiale_PolynImpair DistRadialeInverse(REAL RhoApp,INT DeltaDeg = 1);


    // aPt -> aChSacle * Direct (aPt / aChSacle)
    ElDistRadiale_PolynImpair MapingChScale(REAL aChSacle) const;

    static ElDistRadiale_PolynImpair DistId(REAL aRMax,Pt2dr aCentre,INT aDeg);

    static ElDistRadiale_PolynImpair read(ELISE_fp & aFile);
    static ElDistRadiale_PolynImpair read(const std::string &);
    void write(ELISE_fp & aFile);

    // DEBUG PURPOSE,
    REAL RMax() const;
    REAL ValRMax() const;
    REAL DiffRMax() const;
    virtual ElDistRadiale_PolynImpair * DRADPol(bool strict = false);

    ElPolynome<REAL> PolynOfR();
    // Rayon max a l'interieur duquel la fonction de
    // distortion est bijective croissante
    REAL RMaxCroissant(REAL BorneInit);

    virtual cCalibDistortion ToXmlStruct(const ElCamera *) const;
    cCalibrationInterneRadiale ToXmlDradStruct() const;

protected :
    bool  AcceptScaling() const;
    bool  AcceptTranslate() const;
    void V_SetScalingTranslate(const double &,const Pt2dr &);


private :
    std::vector<REAL> mCoeffs;  // mCoeffs[0] en r3,  mCoeffs[1] en r5 , etc ....

    REAL              mRMax;
    REAL              mRMaxP2N;
    REAL              mValRMax;
    REAL              mDiffRMax;
};

#endif
