#ifndef _ELISE_GENERAL_OPTIM_ALLOCATEURDINCONNUES_H
#define _ELISE_GENERAL_OPTIM_ALLOCATEURDINCONNUES_H

#include "general/sys_dep.h"

class AllocateurDInconnues
{
      public :
        void AssertUsable(const cStateAllocI &) const;
        void RestoreState(const cStateAllocI &);
        AllocateurDInconnues();
        Fonc_Num        NewF(REAL *);
        INT             NewInc(REAL *);
        Pt3d<Fonc_Num>  NewPt3(REAL *,REAL*,REAL*);
        Pt3d<Fonc_Num>            NewPt3(Pt3dr &);
        Pt2d<Fonc_Num>            NewPt2(REAL*,REAL*);
        Pt2d<Fonc_Num>            NewPt2(Pt2dr &);

        std::vector<Fonc_Num>            NewVectInc(std::vector<double> &);

        TplElRotation3D<Fonc_Num> NewRot(REAL *,REAL*,REAL*,REAL *,REAL*,REAL*);
        INT CurInc() const;

	PtsKD PInits();
	void SetVars(const REAL * aSol);
	double  GetVar(INT aK) const;
	double * GetAdrVar(INT aK);
	void  SetVar(double aVal,INT aK);
	void  SetVarPt(Pt2dr  aVal,INT aK);
	REAL * ValsVar();
        void Reinit(INT aK);

      private :
	void PushVar(REAL *);
	std::vector<REAL *>  mAdrVar;
	std::vector<REAL  >  mValsVar;
        INT GetNewInc();
        INT mIdInc;
        AllocateurDInconnues (const AllocateurDInconnues &);
        void operator = (const AllocateurDInconnues &);
};

#endif
