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



#ifndef _ELISE_GENERAL_COMPR_IM_VISU_ELIMSCR_H
#define _ELISE_GENERAL_COMPR_IM_VISU_ELIMSCR_H

#include "general/sys_dep.h"

class Visu_ElImScr : public Visu_ElImDest
{
	  friend class ElImScroller;
	  friend class ElImIncruster;

      public :

           virtual ~Visu_ElImScr();
           virtual Pt2di SzW() = 0;
		   virtual void AdaptTiffFile(Tiff_Im,bool AdaptPal,bool ForceGray);

	 protected :
	 	Visu_ElImScr(Pt2di aSz,int aDimOut);
     private :
		   virtual void InscrustImage(std::vector<Im2D_int4> &,Pt2di p0Src,Pt2di P0Dest,Pt2di sz,int NbIm) = 0;
		   virtual void InscrustImage(std::vector<Im2D_int4> &,Pt2di p0Src,Pt2di P0Dest,Pt2di sz,int NbIm,Elise_Palette) = 0;
           virtual void load_rect_image(Pt2di p0,Pt2di p1,bool Quick) =0;
           virtual void translate(Pt2di) = 0;
           virtual void write_image_out(Pt2di p0_src,Pt2di p0_dest,Pt2di sz) =0;
           Visu_ElImScr(const Visu_ElImScr &);
};

#endif
