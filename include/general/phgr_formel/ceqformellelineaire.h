#ifndef _ELISE_GENERAL_PHGR_FORMEL_CEQFORMELLELINEAIRE_H
#define _ELISE_GENERAL_PHGR_FORMEL_CEQFORMELLELINEAIRE_H

#include "general/sys_dep.h"

class cEqFormelleLineaire
{
     public :
	     friend class cSetEqFormelles;
	     void AddEqNonIndexee
		  (
                        double_t Cste,
                        double_t * Val,
                        double_t aPds,
                        const std::vector<int>  & VIncs
                   );
	     void AddEqIndexee
		  (
                        double_t Cste,
                        double_t * Val,
                        double_t aPds,
                        const std::vector<int>  & VIncs
                   );


     private :
	     cEqFormelleLineaire(const cEqFormelleLineaire &); // NI
	     cEqFormelleLineaire(cSetEqFormelles &,int aNbInc,int aNbVT,bool GenCode);
	     static cAllocNameFromInt    TheNK;
	     static std::string          TheNameCste;

	     int                         mNbInc;
	     cSetEqFormelles &           mSet;
	     std::vector<cIncIntervale>  mIntervs;
	     cIncListInterv              mLInterv;
	     double *                    mAdrCste;
	     std::vector<double *>       mAdrCoeff;
	     std::string                 mNameType;
             cElCompiledFonc *           mFctr ;

};

#endif
