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



#ifndef _ELISE_GENERAL_COMPR_IM_POPUPMENUTRANSP_H
#define _ELISE_GENERAL_COMPR_IM_POPUPMENUTRANSP_H

#include "general/sys_dep.h"

class PopUpMenuTransp
{
      public :

        virtual ~PopUpMenuTransp();
        PopUpMenuTransp(Video_Win aW,Pt2di aSz);


        void UpP0(Pt2di p0Im);
        void UpCenter(Pt2di p0Im);
        bool PtInsideMenu(Pt2di pt);
		Box2di BoxInFen() const;


      protected :

        void Pop();
        Pt2di P0Cur() const;

        void reset_im_ori(Pt2di P0,Pt2di p1);
        void load_compute_show_rgb(Pt2di P0Src,Pt2di P0Dest,Pt2di sz);

        virtual void load_rgb(Pt2di P0Src,Pt2di P0Dest,Pt2di sz);
        void show_rgb(Pt2di P0Src,Pt2di P0Dest,Pt2di sz);

        virtual void compute_rgb ( Pt2di P0,Pt2di p1) ;


        void AdaptP0(Pt2di & p0Im);


        Pt2di         mSz;
        Video_Win     mW;
        ElXim         mWStdIm;
        ElXim         mWAffIm;

        Im2D_U_int1   mImMotif;
        Im2D_U_int1   mImTransp;

        Im2D_U_int1   mImR;
        Im2D_U_int1   mImG;
        Im2D_U_int1   mImB;

        U_int1**       mDataM;  // Motif
        U_int1**       mDataT;  // Transparence
        U_int1**       mDataR;
        U_int1**       mDataG;
        U_int1**       mDataB;

        bool          mUp;
        Pt2di         mP0Cur;
};

#endif
