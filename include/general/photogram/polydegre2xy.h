#ifndef _ELISE_GENERAL_PHOTOGRAM_POLYDEGRE2XY_H
#define _ELISE_GENERAL_PHOTOGRAM_POLYDEGRE2XY_H

#include "general/sys_dep.h"

class PolyDegre2XY
{
public :
    PolyDegre2XY (REAL a,REAL aX,REAL aY,REAL aXX,REAL aXY,REAL aYY);

    REAL Val(Pt2dr aPt) const;
    Pt2dr Grad(Pt2dr aPt) const;

    REAL & Coeff() {return m;}
    REAL & CoeffX() {return mX;}
    REAL & CoeffY() {return mY;}
private :
    REAL m;
    REAL mX;
    REAL mY;
    REAL mXX;
    REAL mXY;
    REAL mYY;

};

#endif
