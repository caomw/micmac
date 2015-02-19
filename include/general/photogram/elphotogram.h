#ifndef _ELISE_GENERAL_PHOTOGRAM_ELPHOTOGRAM_H
#define _ELISE_GENERAL_PHOTOGRAM_ELPHOTOGRAM_H

#include "general/sys_dep.h"

class ElPhotogram  // + ou - NameSpace
{
public :
    static  void bench_photogram_0();

    static Pt2dr   StdProj(Pt3dr);
    static Pt3dr   PProj(Pt2dr);


    static void ProfChampsFromDist
    (
            std::list<Pt3dr>&  res,  // liste de triplets de prof de champs
            Pt3dr p1,Pt3dr p2,Pt3dr p3, // points de projection
            REAL d12, REAL d13, REAL d23
            );
};

#endif
