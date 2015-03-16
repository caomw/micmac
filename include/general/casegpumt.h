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



#ifndef _ELISE_GENERAL_COMPR_IM_CASEGPUMT_H
#define _ELISE_GENERAL_COMPR_IM_CASEGPUMT_H

#include "general/sys_dep.h"

class CaseGPUMT
{
		public :
			friend class GridPopUpMenuTransp;

			virtual ~CaseGPUMT();
			virtual void CaseGPUMTOnActif();
			virtual void CaseGPUMTOffActif();
			virtual void CaseGPUMTOnSelected();

			CaseGPUMT(GridPopUpMenuTransp &,const std::string & aName,Pt2di anInd,Fonc_Num anInit);

			const std::string & Name() const;

		protected:
			void SetFonc(Fonc_Num aFonc,Im2D_U_int1);
			void SetMotif(Fonc_Num aFonc);
			void SetTransp(Fonc_Num aFonc);
		private:
            GridPopUpMenuTransp &   mGPUMT;
			std::string             mName;
			Pt2di                   mInd;
};

#endif
