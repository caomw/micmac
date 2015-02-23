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


#ifndef _ELISE_GENERAL_WINDOW_HJ_WINDOW_H
#define _ELISE_GENERAL_WINDOW_HJ_WINDOW_H

#include "general/sys_dep.h"

        class HJ_Window      window();    //  HJMPD


         Video_Win (Video_Win_LawLevelId,void * IdW,void * IdScreen,Pt2di sz);

		 bool operator == (const Video_Win &) const;

        Pt2dr to_user_geom(Pt2dr p);



        void clear();

        void set_title(const char * name);
        void  set_cl_coord(Pt2dr,Pt2dr);
        Video_Win chc(Pt2dr tr,Pt2dr sc,bool SetClikCoord = false);
        Video_Win * PtrChc(Pt2dr tr,Pt2dr sc,bool SetClikCoord = false);


        Video_Win  chc_fit_sz(Pt2dr aSz,bool SetClikCoord = false);




        std::string GetString(const Pt2dr & aP,Col_Pal aColDr,Col_Pal aColErase);
        Clik   clik_in();
        ElList<Pt2di> GetPolyg(Line_St,INT aButonEnd);
		void grab(Grab_Untill_Realeased &);
		Video_Display    disp();

		// Manipulation d'images
		// Ignorent les coordonnees 

	 void write_image
           (
              Pt2di p0src,
              Pt2di p0dest,
              Pt2di sz,
              INT *** Im,
              Elise_Palette 
           );
      	void load_image(Pt2di p0src,Pt2di p0dest,Pt2di sz); 
      	void load_image(Pt2di p0,Pt2di p1);
      	void load_image();
      	void translate(Pt2di);
      	void image_translate(Pt2di);
        ElXim  StdBigImage();
         
     private :
         static const Pt2dr  _tr00;
         static const Pt2dr  _sc11;

         friend class Data_El_Video_Display;
         class Data_Elise_Video_Win * devw();
         const class Data_Elise_Video_Win * devw() const;
         Video_Win(  class Data_Elise_Video_Win *,
                           Pt2dr tr = _tr00,
                           Pt2dr sc = _sc11
                   );
};

#endif
