#ifndef _ELISE_GENERAL_BITM_POLYNOME2Ddouble_t_H
#define _ELISE_GENERAL_BITM_POLYNOME2Ddouble_t_H



class Polynome2dReal
{
      public :
            std::vector<double> ToVect() const;
            static Polynome2dReal FromVect(const std::vector<double>&,double anAmp);


            Polynome2dReal(int aD0,double_t anAmpl); // Contient tous les monomes, avec un coeff 1.0
            void SetDegre1(double_t aV0,double_t aVX, double_t aVY,bool AnnulOthers = true);

            double_t operator () (Pt2dr aP) const;
            Pt2dr grad(Pt2dr aP) const;
            int NbMonome() const;
            const Monome2dReal &  KthMonome(int) const;
            int    DegreX(int) const;
            int    DegreY(int) const;
            int    DegreTot(int) const;


            void SetCoeff(int aNumMon,double_t aCoeff);
            double_t Coeff(int aNumMon) const;
            double_t & Coeff(int aNumMon) ;
            void Show(int aNumMon) const;
            void Show() const;

            Fonc_Num FNum() const;
            double_t  Ampl() const;
        void write(class  ELISE_fp &) const;
        static Polynome2dReal read(class  ELISE_fp &);

            // return le polynome correspondant a :
            //     P ->  aChSacle * Pol(P/aChSacle)
            Polynome2dReal MapingChScale(double_t aChSacle) const;


            Polynome2dReal operator + (const Polynome2dReal &) const;
            Polynome2dReal operator - (const Polynome2dReal &) const;
            Polynome2dReal operator * (double_t) const;
            Polynome2dReal operator / (double_t) const;
            int DMax() const;

            static  Polynome2dReal PolyDegre1(double_t aV0,double_t aVX,double_t aVY);

      private :
            Polynome2dReal
            (
                  const Polynome2dReal & aPol1,
                  double_t aCoeff1,
                  const Polynome2dReal & aPol2,
                  double_t aCoeff2
            );


            double_t   CoeffNewAmpl (int k,double_t NewAmpl) const;

            void AssertIndexeValide(int) const;

            std::vector<Monome2dReal>  mMons;
            std::vector<double_t>  mCoeff;
            double_t mAmpl;
            int mDMax;

};

#endif
