#ifndef _ELISE_GENERAL_PHOTOGRAM_CDISTMODSTDPHPGR_H
#define _ELISE_GENERAL_PHOTOGRAM_CDISTMODSTDPHPGR_H



class cDistModStdPhpgr : public ElDistRadiale_PolynImpair
{
public :
    cDistModStdPhpgr(const ElDistRadiale_PolynImpair &);

    Pt2dr Direct(Pt2dr) const ;
    void  Diff(ElMatrix<double_t> &,Pt2dr) const;
    virtual bool OwnInverse(Pt2dr &) const ;    //  Pour "casser" la valeur radiale
    virtual Pt2dr GuessInv(const Pt2dr & aP) const ;

    double_t & P1();
    double_t & P2();
    double_t & b1();
    double_t & b2();
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
