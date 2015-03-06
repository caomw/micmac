#ifndef _ELISE_GENERAL_BITM_TYPE>_H
#define _ELISE_GENERAL_BITM_TYPE>_H

#include "general/sys_dep.h"

template <class Type> void  RealRootsOfRealPolynome
     (
         std::vector<Type> &  Sols,
         const ElPolynome<Type>  &aPol,
         Type                    tol,
         int                     ItMax
     );


void RacinesPolyneDegre2Reel
     (double_t a0,double_t a1,double_t a2,int & CAS,Pt2dr & X1,Pt2dr  & X2);
void RacineCarreesComplexe (Pt2dr X,Pt2dr &A1,Pt2dr &A2);
void RacinesPolyneDegre3Reel
     (
        double_t A0,double_t A1,double_t A2,double_t A3,
        int & CAS,
        Pt2dr & X1,Pt2dr  & X2,Pt2dr & X3
     );
void RacinesPolyneDegre4Reel
     (
        double_t A0,double_t A1,double_t A2,double_t A3, double_t A4,
        int & CAS,
        Pt2dr & X1,Pt2dr  & X2,Pt2dr & X3,Pt2dr & X4
     );



#ifndef _ELISE_GENERAL_BITM_MONOME2Ddouble_t_H
#define _ELISE_GENERAL_BITM_MONOME2Ddouble_t_H

#include "general/sys_dep.h"

class Monome2dReal
{
     public :
         Monome2dReal (int d0X,int d0Y,double_t ampl) :
             mD0X  (d0X),
             mD0Y  (d0Y),
             mAmpl (ampl)
         {
         }


         double_t   CoeffMulNewAmpl (double_t NewAmpl) const;

         void SetAmpl(double_t);
         double_t Ampl(double_t) const;

         double_t operator () (Pt2dr aP) const;
         Pt2dr grad(Pt2dr aP) const;

         Fonc_Num FNum() const;
         int DegreX() const {return mD0X;}
         int DegreY() const {return mD0Y;}
         int DegreTot() const;

         void Show(bool X) const;

      private :


         int mD0X;
         int mD0Y;
         double_t mAmpl;
};

#endif
