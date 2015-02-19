#ifndef _ELISE_GENERAL_PHOTOGRAM_STATELPACKH_H
#define _ELISE_GENERAL_PHOTOGRAM_STATELPACKH_H

#include "general/sys_dep.h"

class StatElPackH
{
public :
    StatElPackH(const ElPackHomologue &);
    Pt2dr Cdg1 () const;
    Pt2dr Cdg2 () const;
    REAL  RMax1 () const;
    REAL  RMax2 () const;
    INT   NbPts() const;
    REAL  SomD1 () const;
    REAL  SomD2 () const;
private :
    REAL  mSPds;
    INT   mNbPts;
    Pt2dr mCdg1;
    Pt2dr mCdg2;
    REAL  mRMax1;
    REAL  mRMax2;
    REAL  mSomD1;
    REAL  mSomD2;
};

#endif
