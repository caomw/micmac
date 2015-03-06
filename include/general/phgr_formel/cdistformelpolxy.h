#ifndef _ELISE_GENERAL_PHGR_FORMEL_CDISTFORMELPOLXY_H
#define _ELISE_GENERAL_PHGR_FORMEL_CDISTFORMELPOLXY_H

#include "general/sys_dep.h"

class cDistFormelPolXY  : public cNameSpaceEqF
{
       public :
           cDistFormelPolXY
           (
	       const ElDistortionPolynomiale & aDist,
               cSetEqFormelles & aSet
           );
           ~cDistFormelPolXY();
           Pt2d<Fonc_Num> operator () (Pt2d<Fonc_Num> aP);
              
           int Degre() const;
           cMultiContEQF      StdContraintes() ;
           void SetFige(int DegreMax,bool Std);
	              
	   ElDistortionPolynomiale DistCur() const;
       private :
           int              mDegre;
           int              mDegreFige;
           cPolynFormelXY * mPolX;
           cPolynFormelXY * mPolY;
};

#endif
