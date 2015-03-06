#ifndef _ELISE_GENERAL_PHOTOGRAM_CCAMSTENOPEBILIN_H
#define _ELISE_GENERAL_PHOTOGRAM_CCAMSTENOPEBILIN_H

#include "general/sys_dep.h"

#include <cDistorBilin>
#include <CamStenope>

class cCamStenopeBilin : public CamStenope
{
public :
    cCamStenopeBilin
    (
            double_t Focale,
            Pt2dr Centre,
            const  cDistorBilin & aDBL
            );

    const ElDistortion22_Gen & Dist() const;
    ElDistortion22_Gen & Dist() ;
    const cDistorBilin & DBL() const;

    cCamStenopeBilin * CSBil_SVP();
private :

    cDistorBilin mDBL;
};

#endif
