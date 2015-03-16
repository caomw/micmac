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


#ifndef _ELISE_GENERAL_OPTIM_GAUSSJPREC_H
#define _ELISE_GENERAL_OPTIM_GAUSSJPREC_H

class GaussjPrec
{
      public :

          GaussjPrec(int n,int m);
          bool init_rec();
          void amelior_sol();
          double_t ecart() const;
          double_t ecart_inv() const;
          void set_size_nm(int n,int m);
          void set_size_m(int);

          ElMatrix<double_t> & M()     {return _M;}
          ElMatrix<double_t> & b()     {return _b;}
          ElMatrix<double_t> & Minv()  {return _Minv;}
          ElMatrix<double_t> & x ()    {return _x;}


          void SelfSetMatrixInverse(ElMatrix<double_t> & aM,int aNbIter);

      private :

      // resoud _M * _x = _b
          void set_ecart();

          int            _n;
          int            _m;

          ElMatrix<double_t> _M;
          ElMatrix<double_t> _Minv;
          ElMatrix<double_t> _b;
          ElMatrix<double_t> _x;
          ElMatrix<double_t> _eps;
          ElMatrix<double_t> _ec;
};

#endif
