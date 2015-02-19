#ifndef _ELISE_GENERAL_PHGR_FORMEL_CEQFORMELLELINEAIRE_H
#define _ELISE_GENERAL_PHGR_FORMEL_CEQFORMELLELINEAIRE_H

#include "general/sys_dep.h"

class cEqFormelleLineaire
{
     public :
	     friend class cSetEqFormelles;
	     void AddEqNonIndexee
		  (
                        REAL Cste,
                        REAL * Val,
                        REAL aPds,
                        const std::vector<INT>  & VIncs
                   );
	     void AddEqIndexee
		  (
                        REAL Cste,
                        REAL * Val,
                        REAL aPds,
                        const std::vector<INT>  & VIncs
                   );


     private :
	     cEqFormelleLineaire(const cEqFormelleLineaire &); // NI
	     cEqFormelleLineaire(cSetEqFormelles &,INT aNbInc,INT aNbVT,bool GenCode);
	     static cAllocNameFromInt    TheNK;
	     static std::string          TheNameCste;

	     INT                         mNbInc;
	     cSetEqFormelles &           mSet;
	     std::vector<cIncIntervale>  mIntervs;
	     cIncListInterv              mLInterv;
	     double *                    mAdrCste;
	     std::vector<double *>       mAdrCoeff;
	     std::string                 mNameType;
             cElCompiledFonc *           mFctr ;

};

#endif
