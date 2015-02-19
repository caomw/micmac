#ifndef _ELISE_GENERAL_PHGR_FORMEL_CINCLISTINTERV_H
#define _ELISE_GENERAL_PHGR_FORMEL_CINCLISTINTERV_H

#include "general/sys_dep.h"

class  cIncListInterv
{
    public :

       cIncListInterv();
       bool Equal(const cIncListInterv&) const;
       cIncListInterv(bool isTmp,const cIncIntervale::tId & anId,INT anI0,INT anI1);

       ~cIncListInterv();
       void AddInterv(const cIncIntervale &,bool CanOverlap=false);
       void ResetInterv(const cIncIntervale &);
       bool IsConnexe0N() const;

       INT I0Min() const;
       INT I1Max() const;
       INT Surf()  const;
       const cIncIntervale & FindEquiv(const cIncIntervale &) const;

       const cMapIncInterv &Map() const;
       bool  MayOverlap() const;

       void Init();
    private :

       // cIncListInterv  (const cIncListInterv &) ; // Un imlemanted
       void operator = (const cIncListInterv &) ; // Un imlemanted

       INT          mI0Min;
       INT          mI1Max;
       INT          mSurf;
       cMapIncInterv mMap;
       bool          mMayOverlap;  // Est-ce que l'overlap est possible
};

#endif
