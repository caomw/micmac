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


#ifndef _ELISE_GENERAL_FILE_IM_ELGENFILEIM_H
#define _ELISE_GENERAL_FILE_IM_ELGENFILEIM_H

#include "general/sys_dep.h"
#include "general/allocation.h"

#include <GenIm>
#include <Rectang_Object>

class ElDataGenFileIm;

class ElGenFileIm :  public PRC0,
        public Rectang_Object
{
public :

    virtual ~ElGenFileIm();

    // caracteristique logique :

    INT              Dim()       const;
    const int *      Sz()        const;
    INT              NbChannel() const;
    Pt2di 			Sz2() const;  // Error if Dim != 1


    // caracteristique physique liees a la  representation
    // des valeurs numeriques

    bool       SigneType()      const;
    bool       IntegralType()   const ;
    int        NbBits()         const;
    GenIm::type_el type_el();

    // carateristique d'organisation du fichier

    const int *      SzTile() const;
    bool       Compressed() const;

    Fonc_Num in();
    Fonc_Num in(REAL val);
    Output   out();


protected :

    ElGenFileIm(ElDataGenFileIm *);

private :

    virtual Elise_Rect box() const;
    const ElDataGenFileIm * edgfi() const;
    ElDataGenFileIm * edgfi();

};

#endif
