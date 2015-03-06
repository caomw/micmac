#ifndef _ELISE_GENERAL_PHGR_FORMEL_CSIGNEDEQFPTLIAISON_H
#define _ELISE_GENERAL_PHGR_FORMEL_CSIGNEDEQFPTLIAISON_H

#include "general/sys_dep.h"

class cSignedEqFPtLiaison  : public cEqFPtLiaison
{
     public :
	  virtual double_t ResiduSigneP1P2(Pt2dr aP1,Pt2dr aP2) = 0;
	  // Par Defaut, renvoie la valeur abs    
	  double_t ResiduNonSigneP1P2(Pt2dr aP1,Pt2dr aP2) ;
     private :
};

#endif
