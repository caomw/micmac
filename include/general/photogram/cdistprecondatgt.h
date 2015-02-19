#ifndef _ELISE_GENERAL_PHOTOGRAM_CDISTPRECONDATGT_H
#define _ELISE_GENERAL_PHOTOGRAM_CDISTPRECONDATGT_H

#include "general/sys_dep.h"

class cDistPrecondAtgt : public cDistPrecondRadial
{
public :
    cDistPrecondAtgt(double aFocApriori,const Pt2dr & aCentre);
private :
    double  DerMultDirect(const double & ) const ;
    double  MultDirect(const double & ) const ;
    double  MultInverse(const double & ) const ;
    int     Mode() const ;
};

#endif
