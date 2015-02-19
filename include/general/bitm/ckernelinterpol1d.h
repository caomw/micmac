#ifndef _ELISE_GENERAL_BITM_CKERNELINTERPOL1D_H
#define _ELISE_GENERAL_BITM_CKERNELINTERPOL1D_H

#include "general/sys_dep.h"

class cKernelInterpol1D
{
      public :
       //  Interpolateur "standard" de changement  de coordonnees, un bicubique
       // dilate  et tabule, le parametre du bicub est calcule selon la regle du
       // ChScale ( 0 si > 1.5, -0.5  si < 1.0, interpole entre les 2)
        static cKernelInterpol1D  * StdInterpCHC(double aScale,int aNbTab=100);

        double Interpole(const cFoncI2D &,const double & x,const double & y);

        virtual double  Value(double x) const = 0;
        inline const double &  SzKernel() const{return mSzKernel;}

       virtual ~cKernelInterpol1D();
       cKernelInterpol1D (double mSzKernel);
      protected :
        double mSzKernel;
        std::vector<double> mVecPX;
        double *            mDataPX;
        std::vector<double> mVecPY;
        double *            mDataPY;
};

#endif
