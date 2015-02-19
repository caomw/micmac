#ifndef _ELISE_GENERAL_BITM_TYPEEL>_H
#define _ELISE_GENERAL_BITM_TYPEEL>_H

#include "general/sys_dep.h"

template <class TypeEl>
#ifndef _ELISE_GENERAL_BITM_CGENTABULATEDINTERPOLATEUR_H
#define _ELISE_GENERAL_BITM_CGENTABULATEDINTERPOLATEUR_H

#include "general/sys_dep.h"

class cGenTabulatedInterpolateur
{
     public :
         virtual double GetVal(TypeEl ** aTab,const Pt2dr &  aP) const = 0;
         virtual void  GetVals(TypeEl ** aTab,const Pt2dr *  aP,double *,int Nb) const;
         // SzKernel, a partir de l'arrondi inferieur, de combien
         // faut il dilater x, typiquement 1 pour bilin, 2 pour bicub
         //  1 pour PPV (car fait a partir de round_ni)
         virtual int  SzKernel() const=0;
         virtual ~cGenTabulatedInterpolateur();
   private :
};

#endif
