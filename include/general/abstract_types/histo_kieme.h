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


#ifndef _ELISE_GENERAL_ABSTRACT_TYPES_HISTO_KIEME_H
#define _ELISE_GENERAL_ABSTRACT_TYPES_HISTO_KIEME_H

#include "general/sys_dep.h"

class Histo_Kieme : public Mcheck
{
        public :

                typedef enum
                                {
                                        bin_tree,
                                        last_rank,
                                        undef
                                } mode_h;

                typedef enum
                        {
                                KTH,
                                RANK
                        } mode_res;

                static Histo_Kieme * New_HK(mode_h,INT max_vals);
                // renvoit un pointeur sur une class derivee (BinTree_HK ou
                // LastRank_HK)
                static mode_h  Opt_HK(INT ty,INT max_vals);
                static mode_h  Opt_HK(mode_h aModePref,INT ty,INT max_vals);


                virtual void add(INT radiom) ;
                virtual void sub(INT radiom) ;
                virtual void AddPop(INT radiom,INT aPop) = 0;

                INT  RKthVal(REAL aProp,INT adef);


                virtual void raz() = 0;
               virtual INT kth_val(INT kth) = 0;
                virtual INT rank(INT radiom) = 0;

                virtual  ~Histo_Kieme();
                virtual void verif_vals(const INT *,INT nb);



        protected :
                INT   _max_vals;
                INT   mPopTot;
                Histo_Kieme(INT max_vals);

        private :
};

#endif
