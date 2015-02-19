#ifndef _ELISE_GENERAL_PHOTOGRAM_CDISTHOMOGRAPHIE_H
#define _ELISE_GENERAL_PHOTOGRAM_CDISTHOMOGRAPHIE_H

#include "general/sys_dep.h"

class cDistHomographie : public  ElDistortion22_Gen
{
public :
    cDistHomographie(const ElPackHomologue &,bool aL2);
    cDistHomographie(const cElHomographie &);

    virtual bool OwnInverse(Pt2dr &) const ;    //
    virtual Pt2dr Direct(Pt2dr) const  ;    //
    cDistHomographie MapingChScale(REAL aChSacle) const;
    const cElHomographie & Hom() const;
private :

    virtual ElDistortion22_Gen  * D22G_ChScale(REAL aS) const; // Def erreur fatale
    void  Diff(ElMatrix<REAL> &,Pt2dr) const ;  //  Erreur Fatale
    cElHomographie mHDir;
    cElHomographie mHInv;
};

#endif
