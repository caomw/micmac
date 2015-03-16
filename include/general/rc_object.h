/*Header-MicMac-eLiSe-25/06/2007

    MicMac : Multi Image Correspondances par Methodes Automatiques de Correlation
    eLiSe  : ELements of an Image Software Environnement

    www.micmac.ign.fr


    Copyright : Institut Geographique National
    Author : Marc Pierrot Deseilligny
    Contributors : Gregoire Maillet, Didier Boldo.

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

#ifndef _ELISE_ALLOCATION_RC_OBJECT_H
#define _ELISE_ALLOCATION_RC_OBJECT_H

/*******************************************************************/
/*                                                                 */
/*        Classes for garbage collection                           */
/*                                                                 */
/*******************************************************************/

/*
   Class RC_Object :

   References Counting Object
   */

#include "mcheck.h"

class RC_Object : public Mcheck
{

    friend void decr_ref(class Object_cptref * oc);
    //friend class PRC0;


protected :

    RC_Object();
    virtual ~RC_Object();

    //---- data ----
    union
    {
        int            cpt_ref;
        RC_Object * next;
    }    _d;

private :



    // declared as static so that they can be called with 0

    static void decr_ref(RC_Object *);
public :
    static void incr_ref(RC_Object *);
};

#endif
