#ifndef _ELISE_GENERAL_PHGR_FORMEL_CSOMBILIN_H
#define _ELISE_GENERAL_PHGR_FORMEL_CSOMBILIN_H



class cSomBilin
{
     public :
        cSomBilin(cSetEqFormelles &,Pt2dr &,const cIncIntervale & anInt);

        Pt2d<Fonc_Num>   mPtF;
        cIncIntervale    mInterv;

};

#endif
