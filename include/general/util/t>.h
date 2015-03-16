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


#ifndef _ELISE_GENERAL_UTIL_T>_H
#define _ELISE_GENERAL_UTIL_T>_H



template <class T> const T* VData(const std::vector<T> & aV)  {return aV.data();}
#endif

///  Ajoute des regles speciales pour que chaque pixle ait au moins un 
//  precedcesseur et un antecedant
//   Z est dans l'intervalle ouvert I1 [aZ1Min,aZ1Max[,

void ComputeIntervaleDelta
              (
                  int & aDzMin,
                  int & aDzMax,
                  int aZ,
                  int MaxDeltaZ,
                  int aZ1Min,
                  int aZ1Max,
                  int aZ0Min,
                  int aZ0Max
              );

///  Ne force pas les connexions
void BasicComputeIntervaleDelta
              (
                  int & aDzMin,
                  int & aDzMax,
                  int aZ,
                  int MaxDeltaZ,
                  int aZ0Min,
                  int aZ0Max
              );
double FromSzW2FactExp(double aSzW,double mCurNbIterFenSpec);

std::string getBanniereMM3D();

void BanniereMM3D();



extern "C" {
FILE * ElFopen(const char *path, const char *mode);
int ElFclose(FILE *fp);
void ShowFClose();

};

#endif
