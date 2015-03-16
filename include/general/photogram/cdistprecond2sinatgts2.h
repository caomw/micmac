#ifndef _ELISE_GENERAL_PHOTOGRAM_CDISTPRECOND2SINATGTS2_H
#define _ELISE_GENERAL_PHOTOGRAM_CDISTPRECOND2SINATGTS2_H



class cDistPrecond2SinAtgtS2 : public cDistPrecondRadial
{
public :
    cDistPrecond2SinAtgtS2(double aFocApriori,const Pt2dr & aCentre);
private :
    double  DerMultDirect(const double & ) const ;
    double  MultDirect(const double & ) const ;
    double  MultInverse(const double & ) const ;
    int     Mode() const ;
};

#endif
