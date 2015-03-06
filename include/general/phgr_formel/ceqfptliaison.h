#ifndef _ELISE_GENERAL_PHGR_FORMEL_CEQFPTLIAISON_H
#define _ELISE_GENERAL_PHGR_FORMEL_CEQFPTLIAISON_H

#include "general/sys_dep.h"

class cEqFPtLiaison
{
     public  :
          virtual double_t AddLiaisonP1P2(Pt2dr P1,Pt2dr P2,double_t aPds,bool WithD2) = 0;
          double_t AddPackLiaisonP1P2
	       (
		    const ElPackHomologue & aPack,
		    bool WithD2,
		    cElStatErreur * = 0,
                    double_t aPdsGlob  = 1.0,
		    double_t * SomPdsTot = 0
	       );
	  virtual double_t ResiduNonSigneP1P2(Pt2dr aP1,Pt2dr aP2) = 0;
	  void PondereFromResidu
	       (ElPackHomologue & aPack,double_t Ecart,double_t Coupure = -1);


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
