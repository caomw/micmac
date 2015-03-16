#ifndef _ELISE_GENERAL_GEOM_VECTEUR_PILEEVintERV_H
#define _ELISE_GENERAL_GEOM_VECTEUR_PILEEVintERV_H



class PileEvInterv
{
      public :

        void add_ev(EventInterv);
        void clear();
        void sort_ev();

        ElFilo<EventInterv> & events();

      private :

        ElFilo<EventInterv> _events;
};

#endif
