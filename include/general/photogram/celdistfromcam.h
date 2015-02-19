#ifndef _ELISE_GENERAL_PHOTOGRAM_CELDISTFROMCAM_H
#define _ELISE_GENERAL_PHOTOGRAM_CELDISTFROMCAM_H

#include "general/sys_dep.h"

class cElDistFromCam : public ElDistortion22_Gen
{
public :
    cElDistFromCam(const ElCamera &,bool UseRayUtile);
    Pt2dr Direct(Pt2dr) const;    // -> DistDirect() = M2C
    bool OwnInverse(Pt2dr &) const ;
    const ElCamera & mCam;
    void  Diff(ElMatrix<REAL> & aMat,Pt2dr aP) const;

private :
    bool mUseRay;
    Pt2dr  mSzC;
    Pt2dr  mMil;
    double mRayU;
};

#endif
