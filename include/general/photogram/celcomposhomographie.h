#ifndef _ELISE_GENERAL_PHOTOGRAM_CELCOMPOSHOMOGRAPHIE_H
#define _ELISE_GENERAL_PHOTOGRAM_CELCOMPOSHOMOGRAPHIE_H

#include "general/sys_dep.h"

class cElComposHomographie
{
public :
    double_t operator() (const Pt2dr & aP) const
    {
        return mX*aP.x + mY*aP.y + m1;
    }
    Fonc_Num operator() (Pt2d<Fonc_Num> ) const;


    cElComposHomographie(double_t aX,double_t aY,double_t a1);
    cElComposHomographie(const cXmlAffinR2ToR &);
    cXmlAffinR2ToR ToXml() const;

    cElComposHomographie MulXY(double_t ) const;
    cElComposHomographie MulCste(double_t ) const;

    void write(class  ELISE_fp & aFile) const;
    static cElComposHomographie read(ELISE_fp & aFile);
    friend class cElHomographie;


    double_t & CoeffX();
    double_t & CoeffY();
    double_t & Coeff1();

    double_t  CoeffX() const;
    double_t  CoeffY() const;
    double_t  Coeff1() const;

    void Show(const std::string & aMes);
    bool HasNan() const;

private  :
    void SetCoHom(double_t *) const;
    void Divide (double_t);
    double_t mX;
    double_t mY;
    double_t m1;
};

#endif
