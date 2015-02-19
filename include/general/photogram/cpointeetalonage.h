#ifndef _ELISE_GENERAL_PHOTOGRAM_CPOINTEETALONAGE_H
#define _ELISE_GENERAL_PHOTOGRAM_CPOINTEETALONAGE_H

#include "general/sys_dep.h"

class cPointeEtalonage
{
public :
    cPointeEtalonage(cCiblePolygoneEtal::tInd,Pt2dr,const cPolygoneEtal &);
    Pt2dr PosIm() const;
    Pt3dr PosTer() const;
    void SetPosIm(Pt2dr);
    const cCiblePolygoneEtal  & Cible() const;
    bool  UseIt () const;
    REAL  Pds()    const;
private :

    Pt2dr                       mPos;
    const cCiblePolygoneEtal *  mCible;
    bool                        mUseIt;
    REAL                        mPds;

};

#endif
