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



#ifndef _ELISE_GENERAL_COMPR_IM_ELIMINCRUSTER_H
#define _ELISE_GENERAL_COMPR_IM_ELIMINCRUSTER_H

#include "general/sys_dep.h"

class ElImIncruster
{
		public :

			virtual ~ElImIncruster();

			ElImIncruster
			(
				Pt2di                           SzIm,
				Pt2di                           SzBrd,
				Visu_ElImScr &                  Visu,
				const std::vector<ElImScroller*>   & Scrols,
				int                             NbImRab = 0
			);

			void SetActiveKthIm(int Kth,bool active);

			void BeginIncrust();
			void BeginIncrust(Pt2dr aPInvW,double_t aScale);
			void EndIncrust();

			void IncrustOrigineAtPtW(Pt2di pt);
			void IncrustOrigineAtPtW(Pt2di pt,Elise_Palette);
			void IncrustCenterAtPtW(Pt2di pt);
			void IncrustCenterAtPtW(Pt2di pt,Elise_Palette);
			void IncrSzAndReaff(Pt2di pCenter,Pt2di dSz);
			void IncrSzAndReaff(Pt2di pCenter,Pt2di dSz,Elise_Palette);

			Pt2di P0Tot() const;
			Pt2di P1Tot() const;

			Pt2di P0Uti() const;
			Pt2di P1Uti() const;

			Pt2di CurSize() const;
			Pt2di CurBrd() const;
			Pt2di BrdMax() const;
			void SetBrd(Pt2di);

			Box2di BoxIncrust() const;
			int    NbImInMax() const;

		protected :

		private  :

			Pt2dr  TrScrol(int k);
			double_t  ScaleScrol(int k);


			void SetSize(Pt2di);
			void IncrSzAndReaff(Pt2di pCenter,Pt2di dSz,Elise_Palette *);
			void SetBox(Box2di NewBox,Elise_Palette * aPal);
			void SetNewBoxFromScratch(Box2di NewBox,Elise_Palette * aPal);
			void SetNewBoxDiffer(Box2di NewBox,Elise_Palette * aPal);

			void InitSz();

			void IncrustOrigineAtPtW(Pt2di pt,Elise_Palette *);
			virtual int Filters
                                    (
                                          std::vector<ElImIncr_ScrAttr> & Attrs,
                                          std::vector<Im2D_int4> &        OutPut,
                                          std::vector<Im2D_int4> &        InPut,
                                          Pt2di p0,
                                          Pt2di p1
                                    ) =0;
			            // return value = Nombre de cannaux utiles

			virtual bool PixelIndep() const =0; // Si PixelIndep vaut true la valeur calculee en 1 pixel
			                              // reste valable apres changement de  tr  ou de sz


			Pt2di mSzBrd0;
			Pt2di mSzImUti0;
			Pt2di mSzImTot0;

			Pt2di mSzBrdCur;
			Pt2di mSzImUtiCur;
			Pt2di mSzImTotCur;
			Pt2di mCenter;
			Pt2di mDec;

			Box2di mOldBox;


			std::vector<Im2D_int4>           mImagesIn;
			std::vector<Im2D_int4>           mImagesOut;

			std::vector<ElImScroller*>       mTabScr;
			std::vector<ElImIncr_ScrAttr>    mTabAttrScr;
			Pt2dr  mTrScrol;
			double_t   mScaleScrol;
			std::vector<Memory_ElImDest<int4> *>   mMEID;
			Visu_ElImScr &                   mVisu;
			bool                             mLastDecUpToDate;
                        bool                             mSynchroGeom;
};

#endif
