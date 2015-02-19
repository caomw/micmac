#ifndef _ELISE_GENERAL_PHGR_FORMEL_CEQFPTLIAISON_H
#define _ELISE_GENERAL_PHGR_FORMEL_CEQFPTLIAISON_H

#include "general/sys_dep.h"

class cEqFPtLiaison
{
     public  :
          virtual REAL AddLiaisonP1P2(Pt2dr P1,Pt2dr P2,REAL aPds,bool WithD2) = 0;
          REAL AddPackLiaisonP1P2
	       (
		    const ElPackHomologue & aPack,
		    bool WithD2,
		    cElStatErreur * = 0,
                    REAL aPdsGlob  = 1.0,
		    REAL * SomPdsTot = 0
	       );
	  virtual REAL ResiduNonSigneP1P2(Pt2dr aP1,Pt2dr aP2) = 0;
	  void PondereFromResidu
	       (ElPackHomologue & aPack,REAL Ecart,REAL Coupure = -1);


          ElPackHomologue & StdPack();
     protected :
          ElPackHomologue  & mStdPack;
	  virtual ~cEqFPtLiaison();
          cEqFPtLiaison();

	  // Ce qui suit n'est pas toujours utilise
          std::string           mMemberX1;
          std::string           mMemberY1;
          std::string           mMemberX2;
          std::string           mMemberY2;
          Pt2d<Fonc_Num>        mP1;
          Pt2d<Fonc_Num>        mP2;
};

#endif
