#ifndef _ELISE_GENERAL_PHOTOGRAM_CDISTHOMOGRAPHIERADIALE_H
#define _ELISE_GENERAL_PHOTOGRAM_CDISTHOMOGRAPHIERADIALE_H

#include "general/sys_dep.h"

class cDistHomographieRadiale : public ElDistortion22_Gen
{
public :
    cDistHomographieRadiale
    (
            const cElHomographie & anHom,
            const ElDistRadiale_PolynImpair & aDRad,
            REAL aRayInv,
            INT  aDeltaDegraInv
            );
    virtual bool OwnInverse(Pt2dr &) const ;    //
    virtual Pt2dr Direct(Pt2dr) const  ;    //
    // aPt -> aChSacle * Direct (aPt / aChSacle)
    cDistHomographieRadiale MapingChScale(REAL aChSacle) const;
private:
    virtual ElDistortion22_Gen  * D22G_ChScale(REAL aS) const; // Def erreur fatale
    void  Diff(ElMatrix<REAL> &,Pt2dr) const ;  //  Erreur Fatale
    cElHomographie            mHom;
    cElHomographie            mHomInv;
    ElDistRadiale_PolynImpair mDist;
    ElDistRadiale_PolynImpair mDistInv;
    REAL                      mRay;
    INT                       mDeg;
};

#endif
