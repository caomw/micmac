#ifndef _ELISE_GENERAL_PHGR_FORMEL_CHOMOGFORMELLE_H
#define _ELISE_GENERAL_PHGR_FORMEL_CHOMOGFORMELLE_H

#include "general/sys_dep.h"

class cHomogFormelle : public cElemEqFormelle,
                       public cObjFormel2Destroy
{
        public :
            friend class cSetEqFormelles;
            Pt2d< Fonc_Num>  operator ()(Pt2d< Fonc_Num>);
            Pt2d< Fonc_Num>  ImRec(Pt2d< Fonc_Num>);

            cMultiContEQF      StdContraintes() ;

           const cElHomographie & HomInit() const;
           const cElHomographie & HomCur() const;
           void ReinitHom(const cElHomographie &);

	   void SetModeCtrl(eModeContrHom);
        private :
            cHomogFormelle(const cElHomographie &,cSetEqFormelles &,eModeContrHom);

#ifndef _ELISE_GENERAL_PHGR_FORMEL_CCOMP_H
#define _ELISE_GENERAL_PHGR_FORMEL_CCOMP_H

#include "general/sys_dep.h"

            class cComp
            {
                 public :
                    cComp
                    (
                         cElComposHomographie &,
                         cSetEqFormelles &,
                         bool IsDenom
                    );
                    Fonc_Num operator ()(Pt2d< Fonc_Num>);


                  // private :
                    Fonc_Num  mX;
                    Fonc_Num  mY;
                    Fonc_Num  m1;
            };

            // Foncteur de Rappel sur Valeur Init
            cElHomographie  &mHomInit;
            cElHomographie  &mCurHom;

            cComp           mCX;
            cComp           mCY;
            cComp           mCZ;
            eModeContrHom   mModeContr;
	    double          mHomFTol;
};

#endif
