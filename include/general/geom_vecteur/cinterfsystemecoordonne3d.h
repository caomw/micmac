#ifndef _ELISE_GENERAL_GEOM_VECTEUR_CINTERFSYSTEMECOORDONNE3D_H
#define _ELISE_GENERAL_GEOM_VECTEUR_CINTERFSYSTEMECOORDONNE3D_H

#include "general/sys_dep.h"

class cInterfSystemeCoordonne3D
{
     public :

         virtual Pt3dr ToEuclid(const Pt3dr & aP) const = 0;
         virtual Pt3dr FromEuclid(const Pt3dr & aP) const = 0;
     public :
};

#endif
