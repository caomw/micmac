#ifndef _ELISE_GENERAL_PHOTOGRAM_CELEMMEPRELCOPLAN_H
#define _ELISE_GENERAL_PHOTOGRAM_CELEMMEPRELCOPLAN_H

#include "general/sys_dep.h"

class cElemMepRelCoplan
{
public :
    cElemMepRelCoplan
    (
            const cElHomographie &,
            const ElRotation3D &
            );

    cElemMepRelCoplan ToGivenProf(double aProProf);


    bool PhysOk() const;
    void Show() const;
    REAL AngTot() const;
    REAL Ang1() const;
    REAL Ang2() const;
    const ElRotation3D & Rot() const;

    double TestSol() const;
    void TestPack(const ElPackHomologue &) const;


    // Normale au plan dans le repere cam1
    Pt3dr          Norm() const;
    //  Distance entre le centre optique et l'image "reciproque"
    //  du centre camera 1 sur le plan, permet de normalisee
    //  les bases
    REAL DPlan() const;


    // "Vraie" distance min entre le plan et
    double DistanceEuclid() const;

    // Idem camera2
    REAL DPlan2() ;
    // Point du plan, ayant P1 comme image  par cam1
    // (en coord camera 1)
    Pt3dr ImCam1(Pt2dr aP1);
    // Homographie envoyant un (u,v,1) en (X,Y,0)
    cElHomographie HomCam2Plan(double * aResidu = 0);

    cElPlan3D  Plan() const;
    const Pt3dr & P0() const;
    const Pt3dr & P1() const;
    const Pt3dr & P2() const;

    // Des coordoones Cam2 a Cam1

    Pt3dr ToR1(Pt3dr aP2) const;

private :

    // Point du plan, ayant P2 comme image  par cam2
    // (en coord camera 1)
    Pt3dr ImCam2(Pt2dr aP2);

    REAL AngleNormale(Pt3dr);


    cElHomographie mHom;
    cElHomographie mHomI;
    ElRotation3D   mRot;

    // tous les points 3D sont en coordonnees Cam1

    // mP0,mP1,mP2  trois point (coord Cam1) du plan
    // mNorm un vecteur unitaire  de la normale au plan
    Pt3dr          mP0;
    Pt3dr          mP1;
    Pt3dr          mP2;
    Pt3dr          mNorm;
    Pt2dr          mCZCC2; // Centre Zone Commune
    Pt2dr          mCZCC1;
    Pt3dr          mCZCMur;
    Pt3dr          mCOptC1;
    Pt3dr          mCOptC2;
    REAL           mProfC1;
    REAL           mProfC2;
    REAL           mAng1;
    REAL           mAng2;
    REAL           mAngTot;
    double         mDEuclidP;
};

#endif
