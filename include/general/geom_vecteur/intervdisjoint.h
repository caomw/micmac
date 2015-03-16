#ifndef _ELISE_GENERAL_GEOM_VECTEUR_intERVDISJOint_H
#define _ELISE_GENERAL_GEOM_VECTEUR_intERVDISJOint_H



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
