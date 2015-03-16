/*Header-MicMac-eLiSe-25/06/2007

    MicMac : Multi Image Correspondances par Methodes Automatiques de Correlation
    eLiSe  : ELements of an Image Software Environnement

    www.micmac.ign.fr

   
    Copyright : Institut Geographique National
    Author : Marc Pierrot Deseilligny
    Contributors : Gregoire Maillet, Didier Boldo.
	Refactoring : Helio Chissini de Castro <helio@kde.org>

[1] M. Pierrot-Deseilligny, N. Paparoditis.
    "A multiresolution and optimization-based image matching approach:
    An application to surface reconstruction from SPOT5-HRS stereo imagery."
    In IAPRS vol XXXVI-1/W41 in ISPRS Workshop On Topographic Mapping From Space
    (With Special Emphasis on Small Satellites), Ankara, Turquie, 02-2006.

[2] M. Pierrot-Deseilligny, "MicMac, un lociel de mise en correspondance
    d'images, adapte au contexte geograhique" to appears in 
    Bulletin d'information de l'Institut Geographique National, 2007.

Francais :

   MicMac est un logiciel de mise en correspondance d'image adapte 
   au contexte de recherche en information geographique. Il s'appuie sur
   la bibliotheque de manipulation d'image eLiSe. Il est distibue sous la
   licences Cecill-B.  Voir en bas de fichier et  http://www.cecill.info.


English :

    MicMac is an open source software specialized in image matching
    for research in geographic information. MicMac is built on the
    eLiSe image library. MicMac is governed by the  "Cecill-B licence".
    See below and http://www.cecill.info.

Header-MicMac-eLiSe-25/06/2007*/



#ifndef _ELISE_GENERAL_COMPR_IM_GRIDPOPUPMENUTRANSP_H
#define _ELISE_GENERAL_COMPR_IM_GRIDPOPUPMENUTRANSP_H

#include "general/sys_dep.h"

class GridPopUpMenuTransp : public PopUpMenuTransp
{
    public :
		friend class CaseGPUMT;
        GridPopUpMenuTransp
        (
             Video_Win aW,
             Pt2di aSzGrid,
             Pt2di aNbGrid,
             Pt2di aBrdGrid
       );



       void  SetPtActif(Pt2di Pt);
       CaseGPUMT * PopAndGet();
	   void SetBorderMotif(Pt2di iGrid);

       Pt2di SzGrid() const {return mSzGrid;};
    private :


       void   VisuCaseGridActif(Pt2di iGrid);
       void   EffaceCaseGridActif(Pt2di iGrid);

       virtual void compute_menu_actif(Pt2di P0,Pt2di p1) ;

       Pt2di Indice2P0Grid(Pt2di iGrid) const;
       Pt2di Indice2P1Grid(Pt2di iGrid) const;
       Pt2di Pt2Indice(Pt2di Pt) const;

       Pt2di mSzGrid;
       Pt2di mNbGrid;
       Pt2di mBrdGrid;

       Pt2di mIndGrAct;
       bool  mGridIsAct;
	   std::vector<std::vector<CaseGPUMT *> > mCases;
	   CaseGPUMT *                            mCurCase;
};

#endif
