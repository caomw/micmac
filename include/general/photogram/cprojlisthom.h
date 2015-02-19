#ifndef _ELISE_GENERAL_PHOTOGRAM_CPROJLISTHOM_H
#define _ELISE_GENERAL_PHOTOGRAM_CPROJLISTHOM_H

#include "general/sys_dep.h"

class cProjListHom
{
public :
    typedef std::vector<cProjCple>      tCont;
    typedef tCont::iterator           tIter;
    typedef tCont::const_iterator     tCstIter;
    tCstIter & begin() const;
    tCstIter & end() const;

    cProjListHom(  const ElCamera & aCam1,const ElPackHomologue & aPack12,
                   const ElCamera & aCam2,const ElPackHomologue & aPack21,
                   bool Spherik
                   );
public :
    tCont       mLClpe;
    bool        mSpherik;
};

#endif
