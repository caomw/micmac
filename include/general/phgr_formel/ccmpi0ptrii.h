#ifndef _ELISE_GENERAL_PHGR_FORMEL_CCMPI0PTRII_H
#define _ELISE_GENERAL_PHGR_FORMEL_CCMPI0PTRII_H



class cCmpI0PtrII
{
    public :
     bool operator () (const cIncIntervale * aI1,const cIncIntervale *aI2)
     {
          return aI1->I0Alloc() < aI2->I0Alloc();
     }
};

#endif
