#ifndef _ELISE_GENERAL_BITM_RIMGRID_H
#define _ELISE_GENERAL_BITM_RIMGRID_H

#include "general/sys_dep.h"

class RImGrid
{
    public :
       RImGrid
       (
           Pt2dr      anOrigine,
           Pt2dr      aStep,
           Im2D_REAL8 anIm
       );
       RImGrid
       (
          bool  AdaptStep,  // Si true, le pas est calcule pour
                        // diviser exactement l'intervalle P0 P1
          Pt2dr aP0,
          Pt2dr aP1,
          Pt2dr  aStepGr,
      const std::string & aName = "RImGrid",
          Pt2di  aSz = Pt2di(0,0)
       );
       ~RImGrid();
       void InitGlob( Fonc_Num aFonc );

       Pt2dr ToGrid(Pt2dr aP) const;
       Pt2dr ToReal(Pt2dr aP) const;
       Pt2di SzGrid() const;
       void TranlateIn(Pt2dr);

       REAL Value(Pt2dr  aRealP) const;
       REAL ValueAndDer(Pt2dr aRealP,Pt2dr & aDer);
       void SetValueGrid(Pt2di aP,REAL aV);
       void ExtDef(); // Fait une extension "genre" ppv des pixels
                      // initialisee sur les pixels valant Def


        // aPt -> Value (aPt / aChSacle)
        // aPt -> aChSacle * Value (aPt / aChSacle)  (si ModeMapping = true)

        RImGrid *  NewChScale(double aChSacle ,bool ModeMapping);

        void write(class  ELISE_fp & aFile) const;
        static RImGrid  * read(ELISE_fp & aFile);
    const Pt2dr & Step() const;
    Pt2dr Origine() const;
        Im2D_REAL8           DataGrid();

        // Les conventions sont compatible avec le
        // le cas ou aChScale est une focale et Tr une
        //  coordonnees de point principal, en sortie : (X *aChScale + aTr)
        void SetTrChScaleOut(REAL aChScale,REAL aTr);
        void SetTrChScaleIn(REAL aChScale,Pt2dr aTr);

    const std::string & Name() const;

        const Pt2dr & P0() const;
        const Pt2dr & P1() const;
    bool  StepAdapted() const;

        private :
           RImGrid(const RImGrid &) ; // NImpl
           Pt2dr                mP0;
           Pt2dr                mP1;
           Pt2dr                mStepGr;
           Pt2di                mSzGrid;
           REAL                 mDef;
           Im2D_REAL8           mGrid;
           TIm2D<REAL,REAL>*    mTim;
       std::string          mName;
       bool                 mStepAdapted;

};

#endif
