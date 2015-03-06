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

#ifndef _ELISE_GENERAL_FIFO_ELSUBFILO_H
#define _ELISE_GENERAL_FIFO_ELSUBFILO_H

template <class Type> class ElSubFilo
{
     public :
         typedef Type value_type;
         friend class ElPartition<Type>;

         int size() const { return _i2-_i1;}
         int nb() const { return size();}
         Type & operator [] (int k) {return (*_f)[k+_i1];}
         const Type & operator [] (int k) const {return (*_f)[k+_i1];}
         const Type & top (int k=0) const {return (*_f)[_i2-1-k];}
         Type * tab() {return (*_f).tab()+_i1;}

         ElSubFilo() : _f(0), _i1(0), _i2(0) {}


         void * AdrFilo() {return _f;}
         int    I1 () {return _i1;}
         int    I2 () {return _i2;}

          std::vector<Type> ToVect()
	  {
             std::vector<Type> aV;
	     for (int aK=0; aK<nb() ; aK++)
		     aV.push_back((*this)[aK]);
	     return aV;
	  }

      private :
         ElSubFilo(ElFilo<Type> & f,int i1,int i2) : _f(&f), _i1(i1), _i2(i2) {}

         ElFilo<Type> *    _f;
         int               _i1;
         int               _i2;
};

#endif
