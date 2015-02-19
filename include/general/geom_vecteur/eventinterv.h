#ifndef _ELISE_GENERAL_GEOM_VECTEUR_EVENTINTERV_H
#define _ELISE_GENERAL_GEOM_VECTEUR_EVENTINTERV_H

#include "general/sys_dep.h"

class EventInterv
{
     public :
       EventInterv(REAL absc,bool entr);
       REAL absc() const;
       bool entr() const;
       EventInterv();

     private :
       REAL    _absc;
       bool    _entr;
};

#endif
