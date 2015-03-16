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



#ifndef _ELISE_GENERAL_COMPR_IM_BISCROLLER_H
#define _ELISE_GENERAL_COMPR_IM_BISCROLLER_H

#include "general/sys_dep.h"

class BiScroller : public ElImScroller
{
       public :

                 typedef enum
                 {
                     FusLut ,
                     FusRG1B2,
                     eModeMasq
                 } ModeFusion;

                 static  BiScroller  * LutColoredBiscroller
                 (
                     VideoWin_Visu_ElImScr &Visu,
                     const std::string &   NameGray,
                     const std::string &   NameCol,
                     Elise_colour * Cols,
                     int            NbCol
                 );
                 static  BiScroller  * RG1B2Biscroller
                 (
                     VideoWin_Visu_ElImScr &Visu,
                     const std::string &   NameGray,
                     const std::string &   NameCol
                 );

                 static  BiScroller  * MasqBiscroller
                 (
                     VideoWin_Visu_ElImScr &Visu,
                     const std::string &   NameGray,
                     const std::string &   NameMasq
                 );



                 void SetTranslate(Pt2dr aTr);
                 Pt2dr  CurTr() const;

                ElImScroller & Scr1();
                ElImScroller & Scr2();
                Im2D_U_int1  Im1();
                Im2D_U_int1  Im2();


                Im2D_U_int1 ImMasq();

                const std::vector<ElImScroller *> & SubScrolls();


                 BiScroller
                 (
                     VideoWin_Visu_ElImScr &Visu,
                     ElImScroller * ScrGray,
                     ElImScroller * ScrCol,
                     ModeFusion     aMode,
                     Elise_colour * Cols,
                     int            NbCol,
                     const std::string &  aNameMasq
                 );

                void GraySetGamaCorrec(double_t aGama);
                void SetRGBEntry(int Gray,int IndCol,const Elise_colour &);

                void SetImAct(bool,bool);
                bool Im1Act() const;
                bool Im2Act() const;
                ElImScroller & TheScrAct();
                ElImScroller & TheFirstScrAct();
                ElImScroller & OtherScrol();   // "Complem" du TheFirstScrAct

                Video_Win  W() {return mVideoVisu.W();}

           protected :
				void LoadXImage(Pt2di p0W,Pt2di p1W,bool quick);
            private :
                   virtual void MakeOneLine
                   (
                            U_int1 * aDataImR,
                            U_int1 * aDataImG,
                            U_int1 * aDataImB,
                            int      aY,
                            int      anX0,
                            int      anX1,
                            U_int1 * aLineGr,
                            U_int1 * aLineCol
                   );

                   void LutMakeOneLine
                   (
                            U_int1 * aDataImR, U_int1 * aDataImG, U_int1 * aDataImB,
                            int anY,int      anX0, int      anX1,
                            U_int1 * aLineGr, U_int1 * aLineCol
                   );

                   void RG1B2MakeOneLine
                   (
                            U_int1 * aDataImR, U_int1 * aDataImG, U_int1 * aDataImB,
                            int anY,int      anX0, int      anX1,
                            U_int1 * aLineGr, U_int1 * aLineCol
                   );

                   void MasqMakeOneLine
                   (
                            U_int1 * aDataImR, U_int1 * aDataImG, U_int1 * aDataImB,
                            int anY,int      anX0, int      anX1,
                            U_int1 * aLineGr, U_int1 * aLineCol
                   );


				enum
						{
							eIndR =0,
							eIndG =1,
							eIndB =2
						};


                U_int1 * RGBEntry(int Gray,int IndCol) {return mDataTabRGB[Gray][IndCol];}


                Memory_ElImDest<U_int1>   mMemGray;
                ElImScroller *            mScrGray;

                Memory_ElImDest<U_int1>   mMemCol;
                ElImScroller *            mScrCol;
                ModeFusion                mModeFusion;

				VideoWin_Visu_ElImScr &  mVideoVisu;

                Im2D_U_int1              mImGray;
                U_int1 **                mDataGray;
                Im2D_U_int1              mImCol;
                U_int1 **                mDataCol;

                Pt2di                    mSzCols;
                Im3D_U_int1              mTabRGB;
                U_int1 ***               mDataTabRGB;



                Im2D_U_int1   mImR;
                U_int1 *      mDataImR;
                Im2D_U_int1   mImG;
                U_int1 *      mDataImG;
                Im2D_U_int1   mImB;
                U_int1 *      mDataImB;

                Pt2dr         mTr;
                std::vector<ElImScroller *> mSubScrolls;
                bool                           mIm1Act;
                bool                           mIm2Act;
                Im2D_U_int1                    mImMasq;
};

#endif
