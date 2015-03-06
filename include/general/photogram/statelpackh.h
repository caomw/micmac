#ifndef _ELISE_GENERAL_PHOTOGRAM_STATELPACKH_H
#define _ELISE_GENERAL_PHOTOGRAM_STATELPACKH_H

#include "general/sys_dep.h"

class StatElPackH
{
public :
    StatElPackH(const ElPackHomologue &);
    Pt2dr Cdg1 () const;
    Pt2dr Cdg2 () const;
    double_t  RMax1 () const;
    double_t  RMax2 () const;
    int   NbPts() const;
    double_t  SomD1 () const;
    double_t  SomD2 () const;
private :
    double_t  mSPds;
    int   mNbPts;
    Pt2dr mCdg1;
    Pt2dr mCdg2;
    double_t  mRMax1;
    double_t  mRMax2;
    double_t  mSomD1;
    double_t  mSomD2;
};

#endif
