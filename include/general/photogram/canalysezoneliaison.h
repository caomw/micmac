#ifndef _ELISE_GENERAL_PHOTOGRAM_CANALYSEZONELIAISON_H
#define _ELISE_GENERAL_PHOTOGRAM_CANALYSEZONELIAISON_H

#include "general/sys_dep.h"

class cAnalyseZoneLiaison
{
public :
    cAnalyseZoneLiaison();
    void AddPt(const Pt2dr &);
    void Reset();

    //  2 - 1 correpond a l'inertie du petit axe
    //  1 -1  correpond a la moyenne des val abs (dans le ptit axe)
    //  2 -0   correpond a l'inertie du petit axe avec une ponderation
    //         normalisee independante du nombre de points
    double Score(double ExposantDist,double ExposantPds);
    const std::vector<Pt2dr> & VPts() const;
private  :
    cAnalyseZoneLiaison(const cAnalyseZoneLiaison&);
    std::vector<Pt2dr>  mVPts;
    RMat_Inertie        mMat;
};

#endif
