#ifndef _ELISE_GENERAL_PHOTOGRAM_ELDISTRADIALE_POL357_H
#define _ELISE_GENERAL_PHOTOGRAM_ELDISTRADIALE_POL357_H

#include "general/sys_dep.h"

class ElDistRadiale_Pol357  : public ElDistRadiale_PolynImpair // polynome en r de degre 3,5,7
{
public :
    ElDistRadiale_Pol357(REAL aRMax,Pt2dr centre,REAL  c3,REAL c5,REAL c7);

private  :
};

#endif
