#ifndef _ELISE_GENERAL_PHOTOGRAM_CELFAISCEAUDR2D_H
#define _ELISE_GENERAL_PHOTOGRAM_CELFAISCEAUDR2D_H

#include "general/sys_dep.h"

class cElFaisceauDr2D
{
public :
    // Calcul un point projectif correspond a un point de
    // convergence commun du faisceau de droite,
    // suppose une valeur initiale approche en teta,phi

    void PtsConvergence(REAL  & teta0,REAL & phi0, bool OptimPhi);

    // Itere, s'arrete apres NbStep Etape ou si le
    // de residu < Epsilon, ou si le delta residu < DeltaRes
    void PtsConvergenceItere
    (
            REAL  & teta0,REAL & phi0,INT NbStep,
            REAL Epsilon, bool OptimPhi,REAL DeltaResidu =-1
            );
    //  Residu de convergence MOYEN du faisceau vers le point
    //  projectif

    REAL ResiduConvergence(REAL  teta,REAL phi);

    void AddFaisceau(Pt2dr aP0,Pt2dr aDir,REAL aPds);



    // Si tout les faisceau ont approximativement la meme
    // direction renvoie une estimation de cette direction,
    // ne necessite pas de valeur initiale
    REAL TetaDirectionInf();


    void CalibrDistRadiale
    (
            Pt2dr   &            aC0,
            bool                 CentreMobile,
            REAL    &            TetaEpip,
            REAL    &            PhiEpip,
            std::vector<REAL> &  Coeffs
            );


private :
    enum {IndTeta,IndPhi};
#ifndef _ELISE_GENERAL_PHOTOGRAM_CFAISCEAU_H
#define _ELISE_GENERAL_PHOTOGRAM_CFAISCEAU_H

#include "general/sys_dep.h"

    class cFaisceau : public SegComp
    {
    public :
        cFaisceau(Pt2dr aP0,Pt2dr aDir,REAL aPds);
        REAL Pds() const;
    private :
        REAL mPds;
    };

    typedef cFaisceau        tDr;
    typedef std::list<tDr>   tPckDr;
    typedef tPckDr::iterator tIter;

    tIter Begin() {return mPckDr.begin();}
    tIter End() {return mPckDr.end();}
    INT NbDr() {return (INT) mPckDr.size();}

    tPckDr  mPckDr;
};

#endif
