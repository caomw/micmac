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


#ifndef _ELISE_GENERAL_OPTIM_ELGROWINGSETIND_H
#define _ELISE_GENERAL_OPTIM_ELGROWINGSETIND_H

#include "general/sys_dep.h"

class ElGrowingSetInd 
{
     public :
         // Partie typedef

            typedef int key_type;
            typedef int value_type;
            typedef std::vector<int>::const_iterator const_iterator;

         // "Big Three"
            ElGrowingSetInd
            (
                 int aCapa, 
                 double_t aRatioEncombr = 0.1 // Pour dimensionner mIndexes, Pas Fondamental.
            );
            ~ElGrowingSetInd();
            /// ElGrowingSetInd(const ElGrowingSetInd &); => en private, non implante

         // Pour parcourir un ElGrowingSetInd
            const_iterator begin() const  {return mIndexes.begin();}
            const_iterator end()   const  {return mIndexes.end();}



         // Partie set classique
            void clear();
            void insert(const int&) ;
            int size() const;


         /*
             >,>=, == , != : peuvent etre fait rapidement
         */

     private :
         inline void AssertValideIndexe(int anIndexe) const;
         inline bool PrivMember(int anIndexe) const;
         inline void PrivSet(int anIndexe,bool) ;
         ElGrowingSetInd(const ElGrowingSetInd &);  // Non implante

         int         mCapa;
         std::vector<int>  mIndexes;
         Im2D_Bits<1>      mBuzyIndexes;

         // void erase(const int&);  a definir dans une classe derivee, "non growing"
};

#endif
