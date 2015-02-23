/*Header-MicMac-eLiSe-25/06/2007

    MicMac : Multi Image Correspondances par Methodes Automatiques de Correlation
    eLiSe  : ELements of an Image Software Environnement

    www.micmac.ign.fr


    Copyright : Institut Geographique National
    Author : Marc Pierrot Deseilligny
    Contributors : Gregoire Maillet, Didier Boldo.
    Refactoring: Helio Chissini de Castro <helio@kde.org>

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


#ifndef _ELISE_GENERAL_WINDOW_ELXIM_H
#define _ELISE_GENERAL_WINDOW_ELXIM_H

#include "general/sys_dep.h"

class ElXim : public PRC0
{
     public :

        friend class Video_Win;

        ElXim(Video_Win,Pt2di,Fonc_Num,Elise_Palette);
        ElXim(Video_Win,Pt2di);
        void load();
        void load(Pt2di   p0src,Pt2di  p0dest,Pt2di  sz);
	void write_image_per(Pt2di   p0src,Pt2di  p0dest,Pt2di  sz); 
		// recopie, periodiquement, la petite image sur la grande image
		// associee a la fenetre
		

	void fill_with_el_image
             (
                 Pt2di p0src,
                 Pt2di p0dest,
                 Pt2di sz, 
		 std::vector<Im2D_INT4> & Images,
                 Elise_Palette
             );

        void read_in_el_image
             ( 
                  Pt2di       aP0Src,
                  Pt2di       aP0Dest,
                  Pt2di       aSz,
                  Im2D_U_INT1 anImR,
                  Im2D_U_INT1 anImG,
                  Im2D_U_INT1 anImB
             );

	void fill_with_el_image
             ( 
                  Pt2di       aP0Src,
                  Pt2di       aP0Dest,
                  Pt2di       aSz,
                  Im2D_U_INT1 anImR,
                  Im2D_U_INT1 anImG,
                  Im2D_U_INT1 anImB
             );



     private :
        DataElXim * dex();
        ElXim(DataElXim *);
};           

#endif
