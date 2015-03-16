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


#ifndef _ELISE_GENERAL_PTXD_ELAFFIN2D_H
#define _ELISE_GENERAL_PTXD_ELAFFIN2D_H



class ElAffin2D : public cElMap2D
{
     public :
        ElAffin2D
        (
            Pt2dr im00,  // partie affine
            Pt2dr im10,  // partie vecto
            Pt2dr im01  // partie vecto
        );


       static ElAffin2D  L2Fit(const class ElPackHomologue &);

        bool IsId() const;
        // bool operator == (const ElAffin2D & aF2);

        static ElAffin2D Id();
        static ElAffin2D trans(Pt2dr aTr);  // Ajoute Tr

  // Soit une image I1, que l'on Crop de Tr, puis que l'on sous echantillone
  // a d'une resolution aResol, pour avoir une image I2 renvoie la transfo qui donne les coordonnees
  // de l'homologue de I1 dans I2
  //
  //  Si aSzInOut est donne, on rajoute une eventuelle translation pour que l'image
  //  de la box est son coin en 0,0. La taille est modifiee et contient la taille finale
  //
  //
        static ElAffin2D TransfoImCropAndSousEch(Pt2dr aTr,Pt2dr aResol,Pt2dr * aSzInOut=0);  // Ajoute Tr
        static ElAffin2D TransfoImCropAndSousEch(Pt2dr aTr,double aResol,Pt2dr * aSzInOut=0);  // Ajoute Tr




        ElAffin2D (const ElSimilitude &);

        ElAffin2D();  // identite, on le laisse par compatibilite

        Pt2dr IVect (const Pt2dr & aP) const
        {
              return   mI10 *aP.x + mI01 *aP.y;
        }
        Pt2dr operator() (const Pt2dr & aP) const
        {
              return  mI00 + IVect(aP);
        }

         // idem sim Aff1 * Aff2 renvoie l'affinite e composee (celle z-> Aff1(Aff2(z)))
       ElAffin2D operator * (const ElAffin2D & sim2) const;
       ElAffin2D inv() const;

       Pt2dr I00() const {return mI00;}
       Pt2dr I10() const {return mI10;}
       Pt2dr I01() const {return mI01;}
     private :

            Pt2dr mI00;
            Pt2dr mI10;
            Pt2dr mI01;
};

#endif
