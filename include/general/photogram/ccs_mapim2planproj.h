#ifndef _ELISE_GENERAL_PHOTOGRAM_CCS_MAPIM2PLANPROJ_H
#define _ELISE_GENERAL_PHOTOGRAM_CCS_MAPIM2PLANPROJ_H

#include "general/sys_dep.h"

class   cCS_MapIm2PlanProj : public ElDistortion22_Gen
{
public :
    cCS_MapIm2PlanProj(CamStenope * pCam) ;
    // Directe Image -> Direction de rayon

    Pt2dr Direct(Pt2dr aP) const;
private :
    bool OwnInverse(Pt2dr & aP) const;
    void  Diff(ElMatrix<double_t> &,Pt2dr) const;

    CamStenope & mCam;
};

#endif
