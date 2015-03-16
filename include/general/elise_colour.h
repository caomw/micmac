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



#ifndef _ELISE_GENERAL_COLOUR_ELISE_COLOUR_H
#define _ELISE_GENERAL_COLOUR_ELISE_COLOUR_H

#include "general/sys_dep.h"

class Elise_colour
{
    public :

        double_t eucl_dist (const Elise_colour &); 

        friend Elise_colour operator - (Elise_colour,Elise_colour);
        friend Elise_colour operator + (Elise_colour,Elise_colour);
        friend Elise_colour operator * (double_t,Elise_colour);

        friend  Elise_colour som_pond(Elise_colour C1,double_t pds,Elise_colour C2);
                  // pds (*this) + (1-pds) c2

        static inline Elise_colour rgb(double_t rr,double_t gg,double_t bb)   
        {
               return Elise_colour(rr,gg,bb);
        }

        static Elise_colour cmy(double_t,double_t,double_t);   
        static Elise_colour rand();   
        static Elise_colour gray(double_t);


        static const Elise_colour   red;
        static const Elise_colour   green;
        static const Elise_colour   blue;

        static const Elise_colour   cyan;
        static const Elise_colour   magenta;
        static const Elise_colour   yellow;

        static const Elise_colour   black;
        static const Elise_colour   white;

        static const Elise_colour   medium_gray;
        static const Elise_colour   brown;
        static const Elise_colour   orange;
        static const Elise_colour   pink;
        static const Elise_colour   kaki;
        static const Elise_colour   golfgreen;
        static const Elise_colour   coterotie;
        static const Elise_colour   cobalt;
        static const Elise_colour   caramel;
        static const Elise_colour   bishop;
        static const Elise_colour   sky;
        static const Elise_colour   salmon;
        static const Elise_colour   emerald;

        inline double_t r() const { return _rgb[0];}
        inline double_t g() const { return _rgb[1];}
        inline double_t b() const { return _rgb[2];}
		inline double_t GrayVal() const {return (r()+g()+b()) /3.0;}
		inline double_t MinRGB() const {return ElMin3(r(),g(),b());}
		inline double_t MaxRGB() const {return ElMax3(r(),g(),b());}

        Elise_colour() {*this = rgb(0,0,0);};

        void to_its(double_t & i,double_t & t, double_t & s);
        static Elise_colour its(double_t i,double_t t,double_t s);

    private :

        double_t    _rgb[3];
        inline Elise_colour(double_t rr,double_t gg,double_t bb)
        {
             _rgb[0] = rr; _rgb[1] = gg; _rgb[2] = bb;
        }

        static double_t adj_rvb(double_t);


       friend class Disc_Pal GIF_palette(class ELISE_fp,int nb);
};

#endif
