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



#ifndef _ELISE_GENERAL_PRIVATE_FLUX_PTS_TMPL_TRACE_DIGITAL_LINE_H
#define _ELISE_GENERAL_PRIVATE_FLUX_PTS_TMPL_TRACE_DIGITAL_LINE_H

#include "general/sys_dep.h"

class Trace_Digital_line
{
   public :

     Trace_Digital_line(Pt2di p1,Pt2di p2,bool conx_8,bool include_p2);
     Trace_Digital_line(){};

     // fill x and y with the nb next point, where nb is the maximun
     // value <= sz_buf, return nb;
     int next_buf(int *x,int *y,int sz_buf);

     void next_pt()
     {
        if (ElAbs(_delta+_delta_1)<ElAbs(_delta+_delta_2))
        {
           _p_cur += _u1;
           _delta += _delta_1;
        }
        else
        {
           _p_cur += _u2;
           _delta += _delta_2;
        }
        _nb_pts--;
     }
     Pt2di pcur () { return _p_cur;}
     int nb_residu() {return _nb_pts;}

   private :
     Pt2di  _u;  // vector p1 p2
     Pt2di  _u1; // firts direction approximation
     Pt2di  _u2; // second ....
     Pt2di  _p_cur; // current point

     //  _delta, stores  the quantity (_p_cur-_p0) ^ _u, that is, to a scaling factor
     //  the distance between _p_cur and the line p1,p2. _delta1 (2), represent
     //  the variation of delta if you add _u2 to _p_cur

     // because, _u1,_u2 is alway anti-clockwise, 
     // we always have _delta1 =< 0 and _delta2 >= 0;

     int _delta_1;
     int _delta_2;
     int _delta;

     int _nb_pts;
};

#endif
