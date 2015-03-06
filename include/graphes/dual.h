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

#ifndef _ELISE_GRAPHE_ALGO_DUAL
#define _ELISE_GRAPHE_ALGO_DUAL
#include "graphes/algo_planarite.h"
#include <map>


template <class  Graphe, class GrDual> class ElMakeDual
{
     public :

        //======================
        // Section typedef 
        //======================

        typedef Graphe::ASom                 AttrSom;
        typedef Graphe::AArc                 AttrArc;
        typedef ElSubGraphe<AttrSom,AttrArc>          SubGraphe;
        typedef ElArc<AttrSom,AttrArc>                TArc;
        typedef ElSom<AttrSom,AttrArc>                TSom;

        typedef GrDual::ASom                 DASom;
        typedef GrDual::AArc                 DAArc;
        typedef ElSom<DASom,DAArc>                    DTSom;
        typedef ElArc<DASom,DAArc>                    DTArc;

        typedef map<TArc *,int>                       MapArc;


        //====================================================
        // Section Methode a (re)definir  par l'utilisateur 
        //====================================================

        virtual bool  DM_OkFace(ElSubFilo<TArc *> )
        {
            return true;
        }

        virtual  DAArc  DM_CreateAttrArcDualInit(DTSom & , DTSom & )
        {
             return DAArc();
        }
        virtual  DAArc  DM_CreateAttrArcDualRec(DAArc & attr,DTSom & , DTSom & )
        {
             return attr;
        }
        virtual void DM_CumulAttrArcDual(DTArc & ,TArc &)
        {
        }



        virtual  DASom  DM_CreateAttrFace(ElSubFilo<TArc *>)
        {
             return DASom();
        }



        void make_dual(Graphe &  gr,SubGraphe & sub,GrDual & dual)
        {
             ElPartition<TArc *> FArcs;
             ElFilo<DTSom *>     FDual;
             MapArc              FaceD;


              all_face_trigo(gr,sub,FArcs);
             for (int Kf =0 ; Kf<FArcs.nb(); Kf++)
             {
                 ElSubFilo<TArc *>  fa = FArcs[Kf];

                 if (DM_OkFace(fa))
                 {
                    DTSom & f = dual.new_som(DM_CreateAttrFace(fa));
                    FDual.pushlast(&f);
                    for (int ka = 0 ; ka<fa.nb() ; ka++)
                    {
                         //  FaceG[fa[ka]] = Kf; => acces implicite
                         FaceD[&(fa[ka]->arc_rec())] = Kf;
                    }
                 }
                 else
                 {
                    FDual.pushlast(0);
                 }
             }

             for (int Kf =0 ; Kf<FArcs.nb(); Kf++)
             {
                  DTSom * f1 = FDual[Kf];
                  if (f1 != 0)
                  {
                      ElSubFilo<TArc *>  fa = FArcs[Kf];
                      for (int ka = 0 ; ka<fa.nb() ; ka++)
                      {
                          TArc * arcInit = fa[ka];
                          MapArc::iterator ItD = FaceD.find(arcInit);
                          if (ItD != FaceD.end())
                          {
                             DTSom * f2 = FDual[ItD->second];
                             if (f1 != f2)
                             {
                                DTArc * arcD = dual.arc_s1s2(*f1,*f2);
                                if (! arcD)
                                {
                                    DAArc a12 = DM_CreateAttrArcDualInit(*f1,*f2);
                                    DAArc a21 = DM_CreateAttrArcDualRec(a12,*f2,*f1);
                                    DTArc & NarcD = dual.add_arc(*f1,*f2,a12,a21);
                                    arcD = & NarcD;
                                }
                                DM_CumulAttrArcDual(*arcD,*arcInit);
                             }
                          }
                      }
                  }
             }
              
        }
};


#endif // _ELISE_GRAPHE_ALGO_DUAL
