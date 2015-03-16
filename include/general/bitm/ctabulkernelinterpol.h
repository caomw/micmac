#ifndef _ELISE_GENERAL_BITM_CTABULKERNELintERPOL_H
#define _ELISE_GENERAL_BITM_CTABULKERNELintERPOL_H



class cTabulKernelInterpol : public cKernelInterpol1D
{
    public :
        cTabulKernelInterpol(const cKernelInterpol1D *, int NbDisc1,bool mPrecBil);
        ~cTabulKernelInterpol();
        double  Value(double x) const ;
        double  ValueDer(double x) const ;
        inline const double *   AdrDisc2Real(double  aX) const;
        inline const double *   DerAdrDisc2Real(double  aX) const;
        inline int NbDisc1() const {return mNbDisc1;}
    private :
        inline double   Disc2Real(double  aX) const;
        inline int   Real2Disc(double  aX) const;
        //  const cKernelInterpol1D  * mKer0; // Adopte
        int                        mNbDisc1;
        int                        mNbValPos;
        int                        mSzTab;
        Im1D_double_t8                 mImTab;
        double *                   mTab;
        Im1D_double_t8                 mImDer;
        double *                   mDer;
};

#endif
