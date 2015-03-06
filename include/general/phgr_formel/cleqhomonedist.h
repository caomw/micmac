#ifndef _ELISE_GENERAL_PHGR_FORMEL_CLEQHOMONEDIST_H
#define _ELISE_GENERAL_PHGR_FORMEL_CLEQHOMONEDIST_H

#include "general/sys_dep.h"

class  cLEqHomOneDist
{
      public :
         cLEqHomOneDist(double_t aDiag);
         void AddCple(const ElPackHomologue &);

         // Calcul un score, en mettant tous les parametres a leur valeur
         // initiale sauf le centre fige a aCentre


         cDistRadialeFormelle *    DRF();


         double_t  NStepOpt(int aNb,bool CentreFiged);
         void PondereFromErreur(double_t aDCut);
         void CloseSet();

      protected :
         // Met dans le systeme toute les equation de laison + contrainte
         // renvoie la moyenne des equation de liaisons

         void AddLiaisonOnTop(Pt2dr aP1,Pt2dr aP2,double_t aPds);
         double_t AddAllEquationsToSet();
         cSetEqFormelles * Set();

         void AddHomogF(cHomogFormelle *);
         void AddEqF(cEqHomogFormelle *);

         double_t                              mDiag;
         std::vector<cEqHomogFormelle *>   mEqFs;
         std::vector<ElPackHomologue *>    mLiaisons;

         std::vector<cHomogFormelle *>     mHomFs;
         std::vector<cElHomographie >      mHomInits;

         cSetEqFormelles              mSet;
         ElDistRadiale_PolynImpair mDistInit;
         bool                      mCentreFige;
         int                       mDegreDRFFiged;
         cDistRadialeFormelle *    mDRF;

         bool                      mDerSec;

};

#endif
