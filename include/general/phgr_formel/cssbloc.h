#ifndef _ELISE_GENERAL_PHGR_FORMEL_CSSBLOC_H
#define _ELISE_GENERAL_PHGR_FORMEL_CSSBLOC_H

#include "general/sys_dep.h"

class cIncIntervale;

class cSsBloc
{
     public :
         bool operator ==(const cSsBloc &) const;
         bool disjoint (const cSsBloc &) const;
         int  I0AbsAlloc() const;
         int  I1AbsAlloc() const;
         int  I0AbsSolve() const;
         int  I1AbsSolve() const;

         int  I0Brut() const;
         int  I1Brut() const;
         int  Nb() const;

         cSsBloc(int aI0,int aI1);
         // cSsBloc(int aI0,int aI1,cIncIntervale *);

         void AssertIntInit() const;
         void BlocSetInt(cIncIntervale &);
         inline const cIncIntervale *  Intervale() const {return mInt;}
          
        int Cpt() const;
         
     private :
         int              mI0;  // Relatif au ss bloc
         int              mNb;  // Nb d'elet
         cIncIntervale *  mInt;
         int              mCpt;
         static int       theCptGlob;
};

#endif
