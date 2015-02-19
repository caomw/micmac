#ifndef _ELISE_GENERAL_PHOTOGRAM_ELDISTRADIALE_H
#define _ELISE_GENERAL_PHOTOGRAM_ELDISTRADIALE_H

#include "general/sys_dep.h"

class ElDistRadiale : public ElDistortion22_Gen
{
public :


    Pt2dr  & Centre();
    const Pt2dr  & Centre() const;
    virtual bool OwnInverse(Pt2dr &) const ;    //  return false
    virtual Pt2dr Direct(Pt2dr) const ;

    virtual void  Diff(ElMatrix<REAL> &,Pt2dr) const;  // differentielle

    // rho -> K0 *rho * (1 + DistDirecte(rho))
    virtual REAL K0() const; // def : return 1
    virtual REAL DistDirecte(REAL R) const = 0;
    virtual REAL DistDirecteR2(REAL R) const = 0;

    // doit renvoyer la derivee de DistDirecte, divisee par rho
    virtual REAL  DerSurRho(REAL R) const = 0; // en delta / a 1

    virtual REAL DistInverse(REAL R)  const;
    // Par defaut les distortion sont
    // supposees faibles et la fontion inverse est
    // - la fonction directe

protected  :

    ElDistRadiale(Pt2dr Centre);

private  :
    Pt2dr _centre;
};

#endif
