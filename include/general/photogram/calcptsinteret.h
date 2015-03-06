#ifndef _ELISE_GENERAL_PHOTOGRAM_CALCPTSintERET_H
#define _ELISE_GENERAL_PHOTOGRAM_CALCPTSintERET_H

#include "general/sys_dep.h"

class CalcPtsInteret
{
public :

    typedef std::list<Pt2dr>  tContainerPtsInt;


    static Fonc_Num CritereFonc(Fonc_Num);  // Typiquement une genre Harris
    static Pt2di GetOnePtsInteret(Flux_Pts,Fonc_Num aFonc); // aFonc -> Avant appli de critere


    // Dans cette version, on specifie la taille des carres
    // de recherche de 1 Pts Interet

    static tContainerPtsInt GetEnsPtsInteret_Size
    (
            Pt2di aP0,
            Pt2di aP1,
            Fonc_Num aFonc,
            double_t aSize,
            double_t aRatio = 0.8
            );

    static tContainerPtsInt GetEnsPtsInteret_Nb
    (
            Pt2di aP0,
            Pt2di aP1,
            Fonc_Num aFonc,
            int  aNb,  // NbTot = NbX * NbY
            double_t aRatio = 0.8
            );

    static tContainerPtsInt GetEnsPtsInteret_Size
    (
            Im2D_U_int1,
            double_t aSize,
            double_t aRatio = 0.8
            );
    static tContainerPtsInt GetEnsPtsInteret_Nb
    (
            Im2D_U_int1,
            int  aNb,
            double_t aRatio = 0.8
            );

private :

};

#endif
