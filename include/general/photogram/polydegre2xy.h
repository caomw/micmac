#ifndef _ELISE_GENERAL_PHOTOGRAM_POLYDEGRE2XY_H
#define _ELISE_GENERAL_PHOTOGRAM_POLYDEGRE2XY_H



class PolyDegre2XY
{
public :
    PolyDegre2XY (double_t a,double_t aX,double_t aY,double_t aXX,double_t aXY,double_t aYY);

    double_t Val(Pt2dr aPt) const;
    Pt2dr Grad(Pt2dr aPt) const;

    double_t & Coeff() {return m;}
    double_t & CoeffX() {return mX;}
    double_t & CoeffY() {return mY;}
private :
    double_t m;
    double_t mX;
    double_t mY;
    double_t mXX;
    double_t mXY;
    double_t mYY;

};

#endif
