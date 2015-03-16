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


#ifndef _ELISE_GENERAL_WINDOW_VIDEO_WIN_H
#define _ELISE_GENERAL_WINDOW_VIDEO_WIN_H

class Video_Win   :  public El_Window
{
    friend class ElXim;
    public :

        void DumpImage(const std::string & aName);


         void raise();
         void lower();
         void move_to(const Pt2di&);
         void move_translate(const Pt2di&);

         EliseStdImageInteractor * Interactor();
	 void  SetInteractor(EliseStdImageInteractor *);
         
         static Video_Win  WStd(Pt2di sz,double_t zoom,bool all_pal= true,bool SetClikCoord = true);
         static Video_Win  WStd(Pt2di sz,double_t zoom,Video_Win,bool SetClikCoord = true);
         static Video_Win  WSzMax(Pt2dr aSzTarget,Pt2dr aSzMax);

         static Video_Win *  PtrWStd(Pt2di sz,bool all_pal= true,const Pt2dr & aScale=Pt2dr(1,1));

         static Output  WiewAv(Pt2di sz,Pt2di szmax = Pt2di(500,500));

         void set_sop(Elise_Set_Of_Palette);

         // Video_Win (Pt2di);          

         Video_Win
         (
                Video_Display          ,
                Elise_Set_Of_Palette   ,
                Pt2di                  ,
                Pt2di                  ,
                int          border_witdh = 5
         );

         typedef enum
         {
             eDroiteH,
             eBasG,
             eSamePos
         }  ePosRel;

         Video_Win
         (
                Video_Win   aSoeur,
                ePosRel     aPos,
                Pt2di       aSz,
                int         border_witdh = 5
         );

        class HJ_PtrDisplay  display();   //  HJMPD
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
        ElList<Pt2di> GetPolyg(Line_St,int aButonEnd);
		void grab(Grab_Untill_Realeased &);
		Video_Display    disp();

		// Manipulation d'images
		// Ignorent les coordonnees 

	 void write_image
           (
              Pt2di p0src,
              Pt2di p0dest,
              Pt2di sz,
              int *** Im,
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
