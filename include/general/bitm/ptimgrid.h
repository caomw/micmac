#ifndef _ELISE_GENERAL_BITM_PTIMGRID_H
#define _ELISE_GENERAL_BITM_PTIMGRID_H

#include "general/sys_dep.h"

class PtImGrid
{
    public :
       PtImGrid (bool AdaptStep, Pt2dr aP0, Pt2dr aP1, Pt2dr  aStepGr,const std::string & = "PtImGrid");
       // ToGrid et ToReal : transfo lineaire, conversion
       // entre le monde reel et les coordonnes d'entree de la grille
       Pt2dr ToGrid(Pt2dr aP) const;
       Pt2dr ToReal(Pt2dr aP) const;
       Pt2di SzGrid() const;

       Pt2dr  Value(Pt2dr aRealP);
      // aGradX : grad de la valeur en X / a x ET y
       Pt2dr ValueAndDer(Pt2dr aRealP,Pt2dr & aGradX,Pt2dr & aGradY);
       void SetValueGrid(Pt2di aP,Pt2dr  aV);

        void write(class  ELISE_fp & aFile) const;
        static PtImGrid  * read(ELISE_fp & aFile);
       ~PtImGrid();
    const Pt2dr & Step() const;
    Pt2dr Origine() const;

        Im2D_REAL8           DataGridX();
        Im2D_REAL8           DataGridY();
    const std::string & Name() const ;
    const std::string & NameX() const ;
    const std::string & NameY() const ;

       PtImGrid (RImGrid *,RImGrid * GY,const std::string &);
       void SetTrChScaleOut(REAL aChScale,Pt2dr aTr);
       void SetTrChScaleIn(REAL aChScale,Pt2dr aTr);

       const Pt2dr & P0() const;
       const Pt2dr & P1() const;
       bool  StepAdapted() const;
    private :
    PtImGrid (ELISE_fp & aFile);
        RImGrid   *mGX;
        RImGrid   *mGY;
    std::string          mName;
};

#endif
