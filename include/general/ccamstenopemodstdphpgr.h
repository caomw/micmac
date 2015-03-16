#ifndef _ELISE_GENERAL_PHOTOGRAM_CCAMSTENOPEMODSTDPHPGR_H
#define _ELISE_GENERAL_PHOTOGRAM_CCAMSTENOPEMODSTDPHPGR_H



class cCamStenopeModStdPhpgr : public cCamStenopeDistRadPol
{
public :
    cCamStenopeModStdPhpgr
    (
            bool DistIsC2M, // [1]
            double_t Focale,
            Pt2dr Centre,
            cDistModStdPhpgr,
            const std::vector<double> & ParamAF
            );
    cDistModStdPhpgr & DModPhgrStd();
    const cDistModStdPhpgr & DModPhgrStd() const;
    // [1]  DistIsC2M:
    // En point de liaison les equation sont faite C->M, compte
    // tenu de l'absence d'inversion triviale pour le Modele Std,
    // on a interet a toujours raisonner dans ce sens
    virtual ElDistortion22_Gen   &  Dist();
    virtual const ElDistortion22_Gen   &  Dist() const;
    virtual cParamIntrinsequeFormel * AllocParamInc(bool isDC2M,cSetEqFormelles &);
    cParamIFDistStdPhgr * AllocPhgrStdInc(bool isDC2M,cSetEqFormelles &);
private :
    cCamStenopeModStdPhpgr(const cCamStenopeModStdPhpgr &); // N.I.
    cDistModStdPhpgr mDist;
};

#endif
