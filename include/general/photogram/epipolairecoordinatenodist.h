#ifndef _ELISE_GENERAL_PHOTOGRAM_EPIPOLAIRECOORDINATENODIST_H
#define _ELISE_GENERAL_PHOTOGRAM_EPIPOLAIRECOORDINATENODIST_H

#include "general/sys_dep.h"

class EpipolaireCoordinateNoDist : public EpipolaireCoordinate
{
public :
    EpipolaireCoordinateNoDist
    (
            Pt2dr aP0,
            Pt2dr aDirX
            );
private :
    virtual Pt2dr ToCoordEpipol(Pt2dr aPInit) const ;
    virtual Pt2dr ToCoordInit(Pt2dr aPEpi) const ;
    virtual EpipolaireCoordinate *
    MapingChScale(double_t aChSacle) const;
};

#endif
