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


#ifndef _ELISE_GENERAL_UTIL_CEQUIV1D_H
#define _ELISE_GENERAL_UTIL_CEQUIV1D_H

#include "general/sys_dep.h"

class cEquiv1D
{
     public :
          // Intervalle [aV0 aV1[
          cEquiv1D ();
          void InitFromFctr
          (
                 int aV0,
                 int aV1,
                 const cFonc1D &
          );
          void InitByFusion(const cEquiv1D &,int aFus);
          // InitByFusion, vs constructeur
          class cCstrFusion {};
          cEquiv1D(const cCstrFusion &,const cEquiv1D &,int aFus);

          void InitByClipAndTr
               (
                    const cEquiv1D &,
                    int aHomOfNewV0,
                    int aNewV0,
                    int aNewV1
               );
          void InitByDeZoom
               (
                    const cEquiv1D &,
                    int aDz,
                    cVectTr<int> * mLut
               );
         int NbClasses() const { return mNbClasses; }
          int V0()        const { return mV0; }
          int V1()        const { return mV1; }
          int  NumClasse(const int & aV) const
          {
               return mNumOfClasse[aV-mV0];
          }
          // La fonction "inverse" renvoie un intervalle
          void ClasseOfNum(int & aV0,int & aV1,const int & aNCL) const
          {
                aV0 = mDebOfClasse[aNCL];
                aV1 = mDebOfClasse[aNCL+1];
          }
          int SzMaxClasses() const;
     private:
          void Reset(int aV0,int aV1);
          std::vector<int> mNumOfClasse; // Pour un entier, son numero de classe
          std::vector<int> mDebOfClasse; // Pour un numero de classe, sont entier de debut

          int mV0;
          int mV1;
          int mNbClasses;
};

#endif
