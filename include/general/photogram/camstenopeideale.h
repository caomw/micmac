#ifndef _ELISE_GENERAL_PHOTOGRAM_CAMSTENOPEIDEALE_H
#define _ELISE_GENERAL_PHOTOGRAM_CAMSTENOPEIDEALE_H

#include "general/sys_dep.h"

class CamStenopeIdeale : public CamStenope
{
public :
    CamStenopeIdeale (bool isDistC2M,REAL Focale,Pt2dr Centre,const std::vector<double> & ParamAF);
    CamStenopeIdeale(const CamStenopeIdeale &,const ElRotation3D &);
    static CamStenopeIdeale  CameraId(bool isDistC2M,const ElRotation3D &);
    CamStenopeIdeale(const CamStenopeIdeale &);

private :
    virtual ElDistortion22_Gen   &  Dist();
    virtual const ElDistortion22_Gen   &  Dist() const;
};

#endif
