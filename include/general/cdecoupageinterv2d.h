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


#ifndef _ELISE_GENERAL_PTXD_CDECOUPAGEintERV2D_H
#define _ELISE_GENERAL_PTXD_CDECOUPAGEintERV2D_H



class cDecoupageInterv2D
{
      public :

          // dil peut etre < 0, dilate sauf
          Box2di DilateBox(int aKBox,const Box2di &,int aDil);


          cDecoupageInterv2D
          (
              const Box2di & aBoxGlob,
              Pt2di aSzMax,
              const Box2di   & aSzBord,
              int              anArrondi=1
          );
          static cDecoupageInterv2D SimpleDec(Pt2di aSz,int aSzMax,int aSzBrd,int anArrondi=1);

          int NbInterv() const;
          Box2di KthIntervOut(int aK) const;
          Pt2di  IndexOfKBox(int aKBOx) const;

      // Avec Bord par defaut
          Box2di  KthIntervIn(int aK) const;
          Box2di  KthIntervIn(int aK, const Box2di   & aSzBord) const;
       // Majorant de la taille des boites
      Pt2di   SzMaxOut() const;
      Pt2di   SzMaxIn (const Box2di   & aSzBord) const;
      Pt2di   SzMaxIn () const;
      private :
          cDecoupageInterv1D mDecX;
          cDecoupageInterv1D mDecY;
      int mNbX;
      Box2di mSzBrd;

};

#endif
