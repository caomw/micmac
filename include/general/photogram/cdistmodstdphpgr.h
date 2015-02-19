#ifndef _ELISE_GENERAL_PHOTOGRAM_CDISTMODSTDPHPGR_H
#define _ELISE_GENERAL_PHOTOGRAM_CDISTMODSTDPHPGR_H

#include "general/sys_dep.h"

class cDistModStdPhpgr : public ElDistRadiale_PolynImpair
{
public :
    cDistModStdPhpgr(const ElDistRadiale_PolynImpair &);

    Pt2dr Direct(Pt2dr) const ;
    void  Diff(ElMatrix<REAL> &,Pt2dr) const;
    virtual bool OwnInverse(Pt2dr &) const ;    //  Pour "casser" la valeur radiale
    virtual Pt2dr GuessInv(const Pt2dr & aP) const ;

    REAL & P1();
    REAL & P2();
    REAL & b1();
    REAL & b2();
    ElDistRadiale_PolynImpair & DRad();
    const ElDistRadiale_PolynImpair & DRad() const;
    virtual ElDistRadiale_PolynImpair * DRADPol(bool strict = false);

    virtual cCalibDistortion ToXmlStruct(const ElCamera *) const;
    cCalibrationInternePghrStd ToXmlPhgrStdStruct() const;
private  :
    bool  AcceptScaling() const;
    bool  AcceptTranslate() const;
    void V_SetScalingTranslate(const double &,const Pt2dr &);
    // ElDistRadiale_PolynImpair mDRad;
    double mP1;
    double mP2;
    double mb1;
    double mb2;

};

#endif
