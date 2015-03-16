#ifndef _ELISE_GENERAL_GEOM_VECTEUR_EVENTintERV_H
#define _ELISE_GENERAL_GEOM_VECTEUR_EVENTintERV_H



class EventInterv
{
     public :
       EventInterv(double_t absc,bool entr);
       double_t absc() const;
       bool entr() const;
       EventInterv();

     private :
       double_t    _absc;
       bool    _entr;
};

#endif
