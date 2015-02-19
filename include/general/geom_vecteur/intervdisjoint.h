#ifndef _ELISE_GENERAL_GEOM_VECTEUR_INTERVDISJOINT_H
#define _ELISE_GENERAL_GEOM_VECTEUR_INTERVDISJOINT_H

#include "general/sys_dep.h"

class  IntervDisjoint
{
      public :

            const ElFilo<Interval>  & intervs() {return _intervs;};

            void init(PileEvInterv &);
            IntervDisjoint(PileEvInterv &);
            IntervDisjoint();


      private :

            ElFilo<Interval>  _intervs;
};

#endif
