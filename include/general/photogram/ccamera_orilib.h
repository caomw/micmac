#ifndef _ELISE_GENERAL_PHOTOGRAM_CCAMERA_ORILIB_H
#define _ELISE_GENERAL_PHOTOGRAM_CCAMERA_ORILIB_H

#include "general/sys_dep.h"

class cCamera_Orilib : public CamStenope
{
public :
    cCamera_Orilib(Data_Ori3D_Std *);
private :
    Ori3D_Std * CastOliLib();  // Def return 0

    Ori3D_Std                       mOri;
    cDistorsionOrilib             * mDist;
    virtual ElDistortion22_Gen   &  Dist();
    virtual const ElDistortion22_Gen   &  Dist() const;
};

#endif
