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


#ifndef _ELISE_GENERAL_ABSTRACT_TYPES_FLUX_PTS_H
#define _ELISE_GENERAL_ABSTRACT_TYPES_FLUX_PTS_H

#include "general/sys_dep.h"

#include "private/flux_pts.h"

#include <PRC0>
#include <Pt2d>
#include <ElList>

class Flux_Pts : public  PRC0
{
   // &Arg_Flux_Pts_Comp : a reference, just to allow
   // the definition of the class in another file.


   public :
     ~Flux_Pts(void);
     Flux_Pts(class Flux_Pts_Not_Comp *);
     class Flux_Pts_Computed * compute (const class  Arg_Flux_Pts_Comp &);

     Flux_Pts(Std_Pack_Of_Pts<INT> *);
     Flux_Pts(ElList<Pt2di>);
     Flux_Pts(Pt2di);

     Flux_Pts chc(class Fonc_Num);

     Flux_Pts operator || (Flux_Pts);
};

#endif
