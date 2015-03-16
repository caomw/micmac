#ifndef _ELISE_GENERAL_PHOTOGRAM_CEQTRIANGUAPPARIMAGE_H
#define _ELISE_GENERAL_PHOTOGRAM_CEQTRIANGUAPPARIMAGE_H



class cEqTrianguApparImage
{
    typedef double_t tV6[6];
public :
    // Ordre des variables A.x A.y B.x etc ....
    cEqTrianguApparImage(int aCapa);
    ~cEqTrianguApparImage();
    void Reset();
    void Close();
    void Add
    (
            double_t aI,
            double_t aJ, double_t aDxJ, double_t aDyJ,
            double_t aPdsA, double_t aPdsB, double_t aPdsC
            );

    void SetDer(double_t & aCste,double_t  * aDer,int aK);

private :
    int  mCapa;
    int  mN;     // Nombre de point
    double_t mSI1;   // Moyenne/Somme de l'image I
    double_t mSI2;   // Moyenne/Somme du carre l'image I
    double_t   mSigmaI;
    double_t mSJ1;   // Moyenne/Somme de l'image J
    double_t mSJ2;   // Moyenne/Somme du carre de l'image J
    double_t   mSigmaJ2;
    double_t   mSigmaJ;
    double_t   mSigmaJ3;


    tV6   mDerSJ1;     // Derivee de SJ1 / a A.x A.y B.x etc ..
    tV6   mDerSJ2;     // Derivee de SJ2 / a A.x A.y B.x etc ..
    tV6   mDerSigmaJ2; // Derivee SigmaJ2 = mSJ2 - Square(mSJ1)
    tV6 * mDerJk;      // mDerJk[k][0] derivee de kieme J / a A.x

    double_t * mVI;
    double_t * mVJ;
};

#endif
