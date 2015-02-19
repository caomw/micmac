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


#ifndef _ELISE_GENERAL_OPTIM_NROPTF1VND_H
#define _ELISE_GENERAL_OPTIM_NROPTF1VND_H

#include "general/sys_dep.h"

class NROptF1vND
{
     public :
          virtual REAL NRF1v(REAL) = 0;
          virtual bool NROptF1vContinue() const;
          virtual ~NROptF1vND();
          NROptF1vND(int aNbIterMax=-1);


          //+++++++++++++++++++++++++++
          // Golden search for mimimum
          //+++++++++++++++++++++++++++

          REAL golden(REAL ax,REAL bx,REAL cx,REAL tol,REAL * xmin);

          //+++++++++++++++++++++++++++
          // Brent search for mimimum
          //+++++++++++++++++++++++++++

               // Appelle une eventuelle redifinition de Brent
               // (cas derivable), fait le bracketing initial
               // sur les valeur 0,1,2 
               Pt2dr  brent (bool ForBench=false);

          //++++++++++++++++++++++++++++++++++++++++++++++++
          // Van Wijngaarden-Deker-Brent search for root
          //++++++++++++++++++++++++++++++++++++++++++++++++
          // REAL zbrent(REAL ax,REAL bx,REAL tol,INT ITMAX=100);


                  // NR interface
          void mnbrack( REAL *ax,REAL *bx,REAL *cx,
                        REAL *fa,REAL * fb,REAL *fc
                      );
     protected :
         int mNbIter;
         int mNbIterMax;
         double  mTolGolden;
         double  TOL;
         double x0,x1,x2,x3;
     private :

          // precondition :
          // f(ax) > f(bx), f(cx) > f(bx),  bx entre ax et cx 
          virtual REAL PrivBrent
                  (
                    REAL ax,REAL bx,REAL cx,
                    REAL tol,
                    REAL * xmin,
                    INT ITMAX=100
               );

};

#endif
