#ifndef _ELISE_GENERAL_OPTIM_CEQ12PARAMETRE_H
#define _ELISE_GENERAL_OPTIM_CEQ12PARAMETRE_H

#include "general/sys_dep.h"

class cEq12Parametre
{
    public :
        cEq12Parametre();
        void AddObs(const Pt3dr & aPGround,const Pt2dr & aPPhgr,const double&  aPds);

        // Cam 2 Monde
        std::pair<ElMatrix<double>,Pt3dr> ComputeNonOrtho();

        // Intrinseques + extrinseques
        std::pair<ElMatrix<double>,ElRotation3D > ComputeOrtho();

    private :
        L2SysSurResol mSys;
        std::vector<Pt3dr>  mVPG;
        std::vector<Pt2dr>  mVPPhgr;
        std::vector<double> mVPds;

        void ComputeOneObs(const Pt3dr & aPGround,const Pt2dr & aPPhgr,const double&  aPds);

        // Indexe et valeur permettant de fixer l'arbitraire
        int    mIndFixArb;
        double mValueFixArb;
};

#endif
