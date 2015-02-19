#ifndef _ELISE_GENERAL_PHOTOGRAM_CCAMSTENOPEDISTPOLYN_H
#define _ELISE_GENERAL_PHOTOGRAM_CCAMSTENOPEDISTPOLYN_H

#include "general/sys_dep.h"

class cCamStenopeDistPolyn : public CamStenope
{
public :
    cCamStenopeDistPolyn
    (bool isDistC2M,REAL Focale,Pt2dr Centre, const ElDistortionPolynomiale &,const std::vector<double> &);
    const ElDistortionPolynomiale & DistPol() const;
private :
    ElDistortionPolynomiale mDist;
    cCamStenopeDistPolyn(const cCamStenopeDistPolyn &);
    virtual ElDistortion22_Gen   &  Dist();
    virtual const ElDistortion22_Gen   &  Dist() const;
};

#endif
