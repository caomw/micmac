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


#ifndef _ELISE_GENERAL_PTXD_ELSIMILITUDE_H
#define _ELISE_GENERAL_PTXD_ELSIMILITUDE_H

#include "general/sys_dep.h"

class ElSimilitude : public cElMap2D
{
     public :

         ElSimilitude(Pt2dr trans = Pt2dr(0,0),Pt2dr ComplScale = Pt2dr(1,0)) :
            _tr (trans),
            _sc (ComplScale)
         {
         }

         static ElSimilitude SimOfCentre(Pt2dr centre,Pt2dr ComplScale)
         {
            return ElSimilitude
                   (
                        centre-centre*ComplScale,
                        ComplScale
                   );
         }

         static ElSimilitude SimOfCentre(Pt2dr centre,double_t rho,double_t teta)
         {
                return SimOfCentre
                       (
                           centre,
                           Pt2dr::FromPolar(rho,teta)
                       );
         }

         Pt2dr operator () (const Pt2dr & p) const
         {
               return _tr + p * _sc;
         }

         // sim1 * sim2 renvoie la similitude composee (celle z-> sim1(sim2(z)))

         ElSimilitude operator * (const ElSimilitude & sim2) const
         {
              return ElSimilitude
                     (
                         _tr + _sc * sim2._tr,
                         _sc * sim2._sc
                     );
         }

         ElSimilitude inv () const
         {
              return ElSimilitude
                     (
                         (-_tr)/_sc,
                         _sc.inv()
                     );
         }

         Pt2dr tr () const {return _tr;}
         Pt2dr sc () const {return _sc;}

     private :
          Pt2dr  _tr;
          Pt2dr  _sc;
};

#endif
