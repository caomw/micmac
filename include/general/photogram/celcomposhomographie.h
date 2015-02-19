#ifndef _ELISE_GENERAL_PHOTOGRAM_CELCOMPOSHOMOGRAPHIE_H
#define _ELISE_GENERAL_PHOTOGRAM_CELCOMPOSHOMOGRAPHIE_H

#include "general/sys_dep.h"

class cElComposHomographie
{
public :
    REAL operator() (const Pt2dr & aP) const
    {
        return mX*aP.x + mY*aP.y + m1;
    }
    Fonc_Num operator() (Pt2d<Fonc_Num> ) const;


    cElComposHomographie(REAL aX,REAL aY,REAL a1);
    cElComposHomographie(const cXmlAffinR2ToR &);
    cXmlAffinR2ToR ToXml() const;

    cElComposHomographie MulXY(REAL ) const;
    cElComposHomographie MulCste(REAL ) const;

    void write(class  ELISE_fp & aFile) const;
    static cElComposHomographie read(ELISE_fp & aFile);
    friend class cElHomographie;


    REAL & CoeffX();
    REAL & CoeffY();
    REAL & Coeff1();

    REAL  CoeffX() const;
    REAL  CoeffY() const;
    REAL  Coeff1() const;

    void Show(const std::string & aMes);
    bool HasNan() const;

private  :
    void SetCoHom(REAL *) const;
    void Divide (REAL);
    REAL mX;
    REAL mY;
    REAL m1;
};

#endif
