#ifndef _ELISE_GENERAL_PHOTOGRAM_CEQTRIANGUAPPARIMAGE_H
#define _ELISE_GENERAL_PHOTOGRAM_CEQTRIANGUAPPARIMAGE_H

#include "general/sys_dep.h"

class cEqTrianguApparImage
{
    typedef REAL tV6[6];
public :
    // Ordre des variables A.x A.y B.x etc ....
    cEqTrianguApparImage(INT aCapa);
    ~cEqTrianguApparImage();
    void Reset();
    void Close();
    void Add
    (
            REAL aI,
            REAL aJ, REAL aDxJ, REAL aDyJ,
            REAL aPdsA, REAL aPdsB, REAL aPdsC
            );

    void SetDer(REAL & aCste,REAL  * aDer,INT aK);

private :
    INT  mCapa;
    INT  mN;     // Nombre de point
    REAL mSI1;   // Moyenne/Somme de l'image I
    REAL mSI2;   // Moyenne/Somme du carre l'image I
    REAL   mSigmaI;
    REAL mSJ1;   // Moyenne/Somme de l'image J
    REAL mSJ2;   // Moyenne/Somme du carre de l'image J
    REAL   mSigmaJ2;
    REAL   mSigmaJ;
    REAL   mSigmaJ3;


    tV6   mDerSJ1;     // Derivee de SJ1 / a A.x A.y B.x etc ..
    tV6   mDerSJ2;     // Derivee de SJ2 / a A.x A.y B.x etc ..
    tV6   mDerSigmaJ2; // Derivee SigmaJ2 = mSJ2 - Square(mSJ1)
    tV6 * mDerJk;      // mDerJk[k][0] derivee de kieme J / a A.x

    REAL * mVI;
    REAL * mVJ;
};

#endif
