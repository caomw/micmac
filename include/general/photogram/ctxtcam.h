#ifndef _ELISE_GENERAL_PHOTOGRAM_CTXTCAM_H
#define _ELISE_GENERAL_PHOTOGRAM_CTXTCAM_H

#include <string>

#include "general/sys_dep.h"

class CamStenope;
class cOrientationConique;

class cTxtCam
{
public :

    cTxtCam();
    void SetVitesse(const Pt3dr& aV);

    std::string          mNameIm;
    std::string          mNameOri;
    CamStenope *         mCam;
    CamStenope *         mRefCam;// En cas de reference exacte pour faire du reverse engenering
    cOrientationConique  * mOC;
    double               mPrio;
    bool                 mSelC;
    Pt3dr                mC;  // Center
    Pt3dr                mV;  // Vitesse
    Pt3dr                mWPK;  // Angles
    bool                 mVIsCalc;  // Vitesse
    int                  mNum;
    int                  mNumBande;
    double               mTime;
    const cMetaDataPhoto *     mMTD;
};

#endif
