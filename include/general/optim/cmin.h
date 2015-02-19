#ifndef _ELISE_GENERAL_OPTIM_COPTIMSOMMEFORMELLE_H
#define _ELISE_GENERAL_OPTIM_COPTIMSOMMEFORMELLE_H

#include "general/sys_dep.h"

class cOptimSommeFormelle
{
     public :
	 cOptimSommeFormelle(INT aNbVar);
	 ~cOptimSommeFormelle();
	 void Add(Fonc_Num,bool CasSpecQuad = true);

	 INT GradConjMin(REAL *,REAL ftol,INT ITMAX);
	 INT GradConjMin(PtsKD & ,REAL ftol,INT ITMAX);
	 void Show() ; // Debug purpose
	 INT Dim() const;

         REAL ValFNV(const REAL *  v) ;
         void GradFNV(REAL *grad,const REAL *   v);

     private :
	 cOptimSommeFormelle(const cOptimSommeFormelle &); // Undef 

#ifndef _ELISE_GENERAL_OPTIM_CMIN_H
#define _ELISE_GENERAL_OPTIM_CMIN_H

#include "general/sys_dep.h"

	 class cMin : public FoncNVarDer<REAL> 
	 {
              public :
                 cMin(cOptimSommeFormelle &);
              private :
                 REAL ValFNV(const REAL *  v) ;
                 void GradFNV(REAL *grad,const REAL *   v);

		 cOptimSommeFormelle & mOSF;
	 };
         friend class cMin;




	 void SetPts(const REAL *);
  
         INT                   mNbVar;
	 std::vector<Fonc_Num> mTabDP;
	 Fonc_Num              mSomme;
	 ElGrowingSetInd       mSetInd;
	 PtsKD *               mPts;

         cElMatCreuseGen*      mMatCr;
	 cFormQuadCreuse       mQuadPart;
};

#endif
