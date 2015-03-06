#ifndef _ELISE_GENERAL_PHGR_FORMEL_CEQONEHOMOGFORMELLE_H
#define _ELISE_GENERAL_PHGR_FORMEL_CEQONEHOMOGFORMELLE_H

#include "general/sys_dep.h"

class cEqOneHomogFormelle : public  cNameSpaceEqF ,
                         public cEqFPtLiaison,
                         public cObjFormel2Destroy
{
      public :
          ~cEqOneHomogFormelle();
          cEqOneHomogFormelle
          (
                cHomogFormelle &,
                bool Code2Gen
          );

         // WithD2 : avec derivees secondes
          double_t AddLiaisonP1P2(Pt2dr P1, Pt2dr aP2, double_t aPds,bool WithD2);
          Pt2dr StdAddLiaisonP1P2(Pt2dr P1,Pt2dr P2,double_t aPds,bool WithD2); // Version moderne type camera
          double_t ResiduNonSigneP1P2(Pt2dr aP1,Pt2dr aP2);
          Pt2dr  PtResidu(Pt2dr aP1,Pt2dr aP2);

          cHomogFormelle&       HF();
          cSetEqFormelles &       Set();
      private :
          struct cOneHEq
          {
              cEqOneHomogFormelle & mEQF;
              cElCompiledFonc * pFEq;
              double          * pAdrX1;
              double          * pAdrY1;
              double          * pAdrX2;
              double          * pAdrY2;
              std::string     mName;

              ~cOneHEq();
              cOneHEq(Fonc_Num F,cEqOneHomogFormelle &,bool isX,bool Code2Gen);

              double_t AddLiaisonP1P2(Pt2dr P1,Pt2dr P2,double_t aPds,bool WithD2);
              double_t ResiduSigneP1P2(Pt2dr aP1,Pt2dr aP2);
              void  InitPts(Pt2dr P1,Pt2dr P2);
          };
          friend struct cOneHEq;

          cSetEqFormelles & mSet;
          cHomogFormelle&       mHF;

          Pt2d<Fonc_Num>        mEqHom;
          cIncListInterv        mLInterv;
          cOneHEq*                  pFEqX;
          cOneHEq*                  pFEqY;
};

#endif
