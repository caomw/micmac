#ifndef _ELISE_GENERAL_OPTIM_CAMD_INTERF_H
#define _ELISE_GENERAL_OPTIM_CAMD_INTERF_H

#include "general/sys_dep.h"

class cAMD_Interf
{
    public :
         cAMD_Interf(int aNumberInc);
         void AddArc(int aN1,int aN2,bool VerifDup=false);

     // Renvoie un vecteur qui indique le rang de chaque indexe
     //  si V[0]=3, 0 est le troisiem el (et non, 3 est le premier)
         std::vector<int> DoRank(bool Show=false) ;
    private :
         void VerifN(int aN) const;
         int                           mNb;
         std::vector<std::vector<int> > mV;

};

#endif
