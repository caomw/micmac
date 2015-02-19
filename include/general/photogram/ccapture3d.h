#ifndef _ELISE_GENERAL_PHOTOGRAM_CCAPTURE3D_H
#define _ELISE_GENERAL_PHOTOGRAM_CCAPTURE3D_H

#include "general/sys_dep.h"

class cCapture3D
{
public :
    virtual Pt2dr    Ter2Capteur   (const Pt3dr & aP) const =0;
    virtual bool     PIsVisibleInImage   (const Pt3dr & aP) const =0;
    virtual ElSeg3D  Capteur2RayTer(const Pt2dr & aP) const =0;

    virtual bool  HasRoughCapteur2Terrain() const = 0;
    virtual bool  HasPreciseCapteur2Terrain() const = 0;
    virtual Pt3dr RoughCapteur2Terrain   (const Pt2dr & aP) const =0;
    virtual Pt3dr PreciseCapteur2Terrain   (const Pt2dr & aP) const =0;

    virtual double ResolSolOfPt(const Pt3dr &) const = 0;
    virtual double ResolSolGlob() const = 0;
    virtual bool  CaptHasData(const Pt2dr &) const = 0;

    virtual Pt2dr ImRef2Capteur   (const Pt2dr & aP) const =0;
    virtual double ResolImRefFromCapteur() const =0;
};

#endif
