#ifndef _ELISE_GENERAL_PHOTOGRAM_ELDISTRADIALE_POLYNIMPAIR_H
#define _ELISE_GENERAL_PHOTOGRAM_ELDISTRADIALE_POLYNIMPAIR_H

#include "general/sys_dep.h"

class ElDistRadiale_PolynImpair  : public ElDistRadiale // polynome en r de degre impair
{
public :
    // Pour eviter les comportements sinuguliers
    // si R > RMax on remplace par la differentielle en RMax


    ElDistRadiale_PolynImpair(double_t RMax,Pt2dr centre);
    void ActuRMaxFromDist(Pt2di aSz);
    void ActuRMax();
    void SetRMax(double_t aV);
    virtual double_t DistDirecte(double_t) const;
    double_t DistDirecteR2NoSeuil(double_t R) const ;
    virtual double_t DistDirecteR2(double_t) const;
    virtual double_t DerSurRho(double_t) const;

    void PushCoeff(double_t); // Premiere fois fixe r3 , etc ....
    void PushCoeff(const std::vector<double_t> &); // Premiere fois fixe r3 , etc ....
    double_t & Coeff(int k);
    double_t  Coeff(int k) const;
    int NbCoeff() const;
    int NbCoeffNN() const;  // Elimine les eventuelles coefficient nul rajoutes
    void VerifCoeff(int aK) const;
    double_t   CoeffGen(int aK) const;


    ElDistRadiale_PolynImpair DistRadialeInverse(double_t RhoApp,int DeltaDeg = 1);


    // aPt -> aChSacle * Direct (aPt / aChSacle)
    ElDistRadiale_PolynImpair MapingChScale(double_t aChSacle) const;

    static ElDistRadiale_PolynImpair DistId(double_t aRMax,Pt2dr aCentre,int aDeg);

    static ElDistRadiale_PolynImpair read(ELISE_fp & aFile);
    static ElDistRadiale_PolynImpair read(const std::string &);
    void write(ELISE_fp & aFile);

    // DEBUG PURPOSE,
    double_t RMax() const;
    double_t ValRMax() const;
    double_t DiffRMax() const;
    virtual ElDistRadiale_PolynImpair * DRADPol(bool strict = false);

    ElPolynome<double_t> PolynOfR();
    // Rayon max a l'interieur duquel la fonction de
    // distortion est bijective croissante
    double_t RMaxCroissant(double_t BorneInit);

    virtual cCalibDistortion ToXmlStruct(const ElCamera *) const;
    cCalibrationInterneRadiale ToXmlDradStruct() const;

protected :
    bool  AcceptScaling() const;
    bool  AcceptTranslate() const;
    void V_SetScalingTranslate(const double &,const Pt2dr &);


private :
    std::vector<double_t> mCoeffs;  // mCoeffs[0] en r3,  mCoeffs[1] en r5 , etc ....

    double_t              mRMax;
    double_t              mRMaxP2N;
    double_t              mValRMax;
    double_t              mDiffRMax;
};

#endif
