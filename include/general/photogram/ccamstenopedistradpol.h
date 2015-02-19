#ifndef _ELISE_GENERAL_PHOTOGRAM_CCAMSTENOPEDISTRADPOL_H
#define _ELISE_GENERAL_PHOTOGRAM_CCAMSTENOPEDISTRADPOL_H

#include "general/sys_dep.h"

class cCamStenopeDistRadPol : public CamStenope
{
public :
    const cCamStenopeDistRadPol * Debug_CSDRP() const;

    cCamStenopeDistRadPol
    (
            bool isDistC2M,
            REAL Focale,
            Pt2dr Centre,
            ElDistRadiale_PolynImpair,
            const std::vector<double> & ParamAF,
            ElDistRadiale_PolynImpair * RefDist  = 0,
            const Pt2di &  aSz = ElCamera::TheSzUndef
            );

    ElDistRadiale_PolynImpair & DRad();
    const ElDistRadiale_PolynImpair & DRad() const;

    void write(class  ELISE_fp & aFile) ;
    void write(const std::string & aName);
    static cCamStenopeDistRadPol * read_new(ELISE_fp & aFile);
    static cCamStenopeDistRadPol * read_new(const std::string &);

    virtual cParamIntrinsequeFormel * AllocParamInc(bool isDC2M,cSetEqFormelles &);
    cParamIFDistRadiale * AllocDRadInc(bool isDC2M,cSetEqFormelles &);
private :
    ElDistRadiale_PolynImpair & mDist;
    ElDistRadiale_PolynImpair mDistInterne;
    // Non implemente , pb sur la copie de _dist
    // (reference mal initialisee)
    //   Surtout avec mDist != mDistInterne
    cCamStenopeDistRadPol(const cCamStenopeDistRadPol &);

    virtual ElDistortion22_Gen   &  Dist();
    virtual const ElDistortion22_Gen   &  Dist() const;
};

#endif
