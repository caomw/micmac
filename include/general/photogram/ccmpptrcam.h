#ifndef _ELISE_GENERAL_PHOTOGRAM_CCMPPTRCAM_H
#define _ELISE_GENERAL_PHOTOGRAM_CCMPPTRCAM_H

#include "general/sys_dep.h"

class cCmpPtrCam
{
public :
    bool operator() (const cTxtCamPtr & aC1  ,const cTxtCamPtr & aC2);
};

#endif
