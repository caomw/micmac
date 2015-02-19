#ifndef _ELISE_GENERAL_PHOTOGRAM_POLYNOMIALEPIPOLAIRECOORDINATE_H
#define _ELISE_GENERAL_PHOTOGRAM_POLYNOMIALEPIPOLAIRECOORDINATE_H

#include "general/sys_dep.h"

class PolynomialEpipolaireCoordinate : public EpipolaireCoordinate
{
public :


    PolynomialEpipolaireCoordinate
    (
            Pt2dr aP0,
            Pt2dr aDirX,
            const Polynome2dReal & aPolY,
            REAL                   anAmpl,
            INT                    DeltaDegreInv = 2,
            Pt2dr                  aTrFin = Pt2dr(0,0)
            );


    Polynome2dReal  PolToYEpip();
    Polynome2dReal  PolToYInit();

    virtual  const PolynomialEpipolaireCoordinate * CastToPol() const;
    void write(class  ELISE_fp & aFile) const;
    static PolynomialEpipolaireCoordinate read(ELISE_fp & aFile);
    //     P ->  aChSacle * Pol(P/aChSacle)
    EpipolaireCoordinate * MapingChScale(REAL aChSacle) const;
    PolynomialEpipolaireCoordinate * PolMapingChScale(REAL aChSacle) const;

private :

    INT DeltaDegre() const;
    REAL AmplInv() const;

    Polynome2dReal  mPolToYEpip;
    Polynome2dReal  mPolToYInit;

    Pt2dr ToCoordEpipol(Pt2dr aPInit) const;
    Pt2dr ToCoordInit(Pt2dr aPEpi) const;
};

#endif
