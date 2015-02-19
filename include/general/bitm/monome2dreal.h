#ifndef _ELISE_GENERAL_BITM_TYPE>_H
#define _ELISE_GENERAL_BITM_TYPE>_H

#include "general/sys_dep.h"

template <class Type> void  RealRootsOfRealPolynome
     (
         std::vector<Type> &  Sols,
         const ElPolynome<Type>  &aPol,
         Type                    tol,
         INT                     ItMax
     );


void RacinesPolyneDegre2Reel
     (REAL a0,REAL a1,REAL a2,INT & CAS,Pt2dr & X1,Pt2dr  & X2);
void RacineCarreesComplexe (Pt2dr X,Pt2dr &A1,Pt2dr &A2);
void RacinesPolyneDegre3Reel
     (
        REAL A0,REAL A1,REAL A2,REAL A3,
        INT & CAS,
        Pt2dr & X1,Pt2dr  & X2,Pt2dr & X3
     );
void RacinesPolyneDegre4Reel
     (
        REAL A0,REAL A1,REAL A2,REAL A3, REAL A4,
        INT & CAS,
        Pt2dr & X1,Pt2dr  & X2,Pt2dr & X3,Pt2dr & X4
     );



#ifndef _ELISE_GENERAL_BITM_MONOME2DREAL_H
#define _ELISE_GENERAL_BITM_MONOME2DREAL_H

#include "general/sys_dep.h"

class Monome2dReal
{
     public :
         Monome2dReal (INT d0X,INT d0Y,REAL ampl) :
             mD0X  (d0X),
             mD0Y  (d0Y),
             mAmpl (ampl)
         {
         }


         REAL   CoeffMulNewAmpl (REAL NewAmpl) const;

         void SetAmpl(REAL);
         REAL Ampl(REAL) const;

         REAL operator () (Pt2dr aP) const;
         Pt2dr grad(Pt2dr aP) const;

         Fonc_Num FNum() const;
         INT DegreX() const {return mD0X;}
         INT DegreY() const {return mD0Y;}
         INT DegreTot() const;

         void Show(bool X) const;

      private :


         INT mD0X;
         INT mD0Y;
         REAL mAmpl;
};

#endif
