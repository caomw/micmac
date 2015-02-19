#ifndef _ELISE_GENERAL_BITM_POLYNOME2DREAL_H
#define _ELISE_GENERAL_BITM_POLYNOME2DREAL_H

#include "general/sys_dep.h"

class Polynome2dReal
{
      public :
            std::vector<double> ToVect() const;
            static Polynome2dReal FromVect(const std::vector<double>&,double anAmp);


            Polynome2dReal(INT aD0,REAL anAmpl); // Contient tous les monomes, avec un coeff 1.0
            void SetDegre1(REAL aV0,REAL aVX, REAL aVY,bool AnnulOthers = true);

            REAL operator () (Pt2dr aP) const;
            Pt2dr grad(Pt2dr aP) const;
            INT NbMonome() const;
            const Monome2dReal &  KthMonome(INT) const;
            INT    DegreX(INT) const;
            INT    DegreY(INT) const;
            INT    DegreTot(INT) const;


            void SetCoeff(INT aNumMon,REAL aCoeff);
            REAL Coeff(INT aNumMon) const;
            REAL & Coeff(INT aNumMon) ;
            void Show(INT aNumMon) const;
            void Show() const;

            Fonc_Num FNum() const;
            REAL  Ampl() const;
        void write(class  ELISE_fp &) const;
        static Polynome2dReal read(class  ELISE_fp &);

            // return le polynome correspondant a :
            //     P ->  aChSacle * Pol(P/aChSacle)
            Polynome2dReal MapingChScale(REAL aChSacle) const;


            Polynome2dReal operator + (const Polynome2dReal &) const;
            Polynome2dReal operator - (const Polynome2dReal &) const;
            Polynome2dReal operator * (REAL) const;
            Polynome2dReal operator / (REAL) const;
            INT DMax() const;

            static  Polynome2dReal PolyDegre1(REAL aV0,REAL aVX,REAL aVY);

      private :
            Polynome2dReal
            (
                  const Polynome2dReal & aPol1,
                  REAL aCoeff1,
                  const Polynome2dReal & aPol2,
                  REAL aCoeff2
            );


            REAL   CoeffNewAmpl (INT k,REAL NewAmpl) const;

            void AssertIndexeValide(INT) const;

            std::vector<Monome2dReal>  mMons;
            std::vector<REAL>  mCoeff;
            REAL mAmpl;
            INT mDMax;

};

#endif
