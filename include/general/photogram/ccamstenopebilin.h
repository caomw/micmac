#ifndef _ELISE_GENERAL_PHOTOGRAM_CCAMSTENOPEBILIN_H
#define _ELISE_GENERAL_PHOTOGRAM_CCAMSTENOPEBILIN_H

#include "general/sys_dep.h"

class cCamStenopeBilin : public CamStenope
{
public :
    cCamStenopeBilin
    (
            REAL Focale,
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
