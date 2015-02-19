#ifndef _ELISE_GENERAL_PHOTOGRAM_ELDISTORTIONPOLYNOMIALE_H
#define _ELISE_GENERAL_PHOTOGRAM_ELDISTORTIONPOLYNOMIALE_H

#include "general/sys_dep.h"

class ElDistortionPolynomiale : public ElDistortion22_Gen
{
    // Pour les inverses et autres, on fait l'hypothese
    // que les coeff, hors degres <=1, ont des valeur
    // tres faible

public :
    static ElDistortionPolynomiale DistId(int aDegre,double anAmpl);
    ElDistortionPolynomiale
    (
            const Polynome2dReal & aDistX,
            const Polynome2dReal & aDistY,
            REAL                   anEpsilonInv = 1e-7
            );
    virtual Pt2dr Direct(Pt2dr) const ;  // **

    const Polynome2dReal & DistX() const ;
    const Polynome2dReal & DistY() const ;
    Fonc_Num FNum() const ;

    ElDistortionPolynomiale (REAL anAmpl,REAL anEpsilonInv = 1e-7) ;

    // par defaut appel au fonctions "Quick" (ou Quasi)

    virtual void  Diff(ElMatrix<REAL> &,Pt2dr) const;  // ** differentielle

    // aPt -> aChSacle * Direct (aPt / aChSacle)
    ElDistortionPolynomiale MapingChScale(REAL aChSacle) const;
    virtual ElDistortion22_Gen  * D22G_ChScale(REAL aS) const; // Def erreur fatale

private :
    Polynome2dReal mDistX;
    Polynome2dReal mDistY;
    REAL           mEpsilon;
};

#endif
