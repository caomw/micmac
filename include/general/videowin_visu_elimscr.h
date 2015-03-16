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



#ifndef _ELISE_GENERAL_COMPR_IM_VIDEOWIN_VISU_ELIMSCR_H
#define _ELISE_GENERAL_COMPR_IM_VIDEOWIN_VISU_ELIMSCR_H

#include "general/sys_dep.h"

class VideoWin_Visu_ElImScr  : public Visu_ElImScr
{
     public :

         Video_Win  W() {return _w;}

         Pt2di SzW() {return _w.sz();}
         VideoWin_Visu_ElImScr(Video_Win,Elise_Palette,Pt2di SzImIncr = Pt2di(1,1),int vMin=0,int vMax=255);
         VideoWin_Visu_ElImScr(Video_Win,Tiff_Im,Pt2di SzImIncr = Pt2di(1,1),bool ForceGray=false);   // vMin,vMax =>Tiff_Im


		 virtual void AdaptTiffFile(Tiff_Im,bool AdaptPal,bool ForceGray);



		 void XIm_write_image_brute
			  (
			        Pt2di P0Src,
					Pt2di P0Dest,
					Pt2di Sz,
					Im2D_U_int1 ImR,
					Im2D_U_int1 ImG,
					Im2D_U_int1 ImB
			  );

	protected :
         virtual void load_rect_image(Pt2di p0,Pt2di p1,bool Quick);
     private :
		 virtual void VerifDim(int DimOut);
         virtual void write_image_brute(int  x0src,Pt2di p0dest,int nb,int ** data);
         virtual void translate(Pt2di);
         virtual void write_image_out(Pt2di p0_src,Pt2di p0_dest,Pt2di sz);
	 virtual void InscrustImage(std::vector<Im2D_int4> &,Pt2di p0Src,Pt2di P0Dest,Pt2di sz,int NbIm);
	 virtual void InscrustImage(std::vector<Im2D_int4> &,Pt2di p0Src,Pt2di P0Dest,Pt2di sz,int NbIm,Elise_Palette);



		static ElXim StdIm(Video_Win w);


		ElXim             mBigIm;
		ElXim             mImPer;
		Pt2di             mSzImIncr;
		ElXim             mImIncr;
		Video_Win         _w;
		Elise_Palette   _pal;
		VideoWin_Visu_ElImScr(const VideoWin_Visu_ElImScr &);


};

#endif
