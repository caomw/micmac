#ifndef _ELISE_GENERAL_PHOTOGRAM_CDISTPRECONDRADIAL_H
#define _ELISE_GENERAL_PHOTOGRAM_CDISTPRECONDRADIAL_H



class cDistPrecondRadial : public ElDistortion22_Gen
{
public :
    cDistPrecondRadial(double aFocApriori,const Pt2dr & aCentre);
    cPreCondGrid GetAsPreCond() const;
    Pt2dr  DirectAndDer(Pt2dr aP,Pt2dr & aGradX,Pt2dr & aGradY) const;

private :

    virtual double  DerMultDirect(const double & ) const = 0;
    virtual double  MultDirect(const double & ) const = 0;
    virtual double  MultInverse(const double & ) const = 0;
    virtual int     Mode() const = 0;

    Pt2dr Direct(Pt2dr) const;    // -> DistDirect() = M2C
    bool OwnInverse(Pt2dr &) const ;

    double  mF;
    Pt2dr   mC;
};

#endif
