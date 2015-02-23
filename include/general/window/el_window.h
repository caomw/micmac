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


#ifndef _ELISE_GENERAL_WINDOW_EL_WINDOW_H
#define _ELISE_GENERAL_WINDOW_EL_WINDOW_H

#include "general/sys_dep.h"

class El_Window  : public PRC0        ,
                   public Rectang_Object
{
    friend class DE_GW_Not_Comp;
    friend class Data_Param_Plot_1d;
    friend class Graph_8_neigh_Not_Win_Comp;
    friend class Data_El_Geom_GWin;


    public :

        virtual ~El_Window();
        Output out(Elise_Palette);
        Output ogray();
        Output orgb();
        Output odisc();
        Output obicol();
        Output ocirc();
        Output olin1();


        Disc_Pal pdisc();
        RGB_Pal  prgb();
        Gray_Pal pgray();
        Circ_Pal pcirc();

        Output out_graph(Line_St,bool sym = true);
        Output out_fr_graph(Line_St);

        El_Window operator  | (El_Window);


//  PW = Sc * (PU-Tr) 
//  PU = Tr + PW /Sc


        El_Window chc(Pt2dr tr,Pt2dr sc);
        Pt2di sz() const;
        virtual Elise_Rect box() const;

        void draw_circle_loc(Pt2dr,REAL,Line_St);  // radius depends from coord
        void draw_circle_abs(Pt2dr,REAL,Line_St);  // radius does not depend from coord

	// Bovin, le fait via un polygone
        void draw_ellipse_loc
             (
	        Pt2dr,REAL A,REAL B,REAL C,Line_St,
		  INT Nb=100);  // radius does not depend from coord

        void draw_seg(Pt2dr,Pt2dr,Line_St);
        void draw_rect(Pt2dr,Pt2dr,Line_St);
        void draw_rect(Box2dr,Line_St);
        void fill_rect(Pt2dr,Pt2dr,Fill_St);

        void draw_poly(const std::vector<Pt2dr> &,Line_St,bool isFerm);
        void draw_poly_ouv(const std::vector<Pt2dr> &,Line_St);
        void draw_poly_ferm(const std::vector<Pt2dr> &,Line_St);


        void hach(ElFifo<Pt2dr> & poly,Pt2dr dir,REAL esp,Line_St);
        void hach(std::vector<Pt2dr> & poly,Pt2dr dir,REAL esp,Line_St);


        void draw_arrow
             (
                Pt2dr, Pt2dr, Line_St Style_axe, Line_St Style_pointe,
                REAL size_pointe, REAL pos = 0.5, REAL teta = (PI/4.0)
             );
        void draw_arrow
             (
                Pt2dr, Pt2dr, Line_St Axe_and_Pointe,
                REAL size_pointe, REAL pos = 0.5, REAL teta = (PI/4.0)
             );




              // cache misere, en attendant d'avoir 
              // installe un systeme de fonte portable correct
        void fixed_string(Pt2dr pt,const char * name, Col_Pal,bool draw_im = false);
		Elise_Set_Of_Palette sop();


         Pt2dr U2W(Pt2dr aP);
         Pt2dr W2U(Pt2di aP);
    protected :
         El_Window(class Data_Elise_Gra_Win *,Pt2dr,Pt2dr);
         El_Window(Data_El_Geom_GWin *);
        inline class Data_El_Geom_GWin * degeow() const 
                {return SAFE_DYNC(class Data_El_Geom_GWin *,_ptr);}

        class Data_Elise_Gra_Win * degraw() const; 

    private :
        Output out(TYOFPAL::t);
        Elise_Palette palette(TYOFPAL::t);
};

#endif
