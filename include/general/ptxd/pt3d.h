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


#ifndef _ELISE_GENERAL_PTXD_PT3D_H
#define _ELISE_GENERAL_PTXD_PT3D_H

#include "general/sys_dep.h"

#include <ElStdTypeScal>
#include <TCompl>

template <class Type> class Pt3d : public  ElStdTypeScal<Type>
{
   public :
     typedef typename TCompl<Type>::TypeCompl  tCompl;
     Type   x;
     Type   y;
     Type   z;

     Pt3d();

     Pt3d<Type>(const Pt3d<Type>& ); // to please visual
     explicit Pt3d<Type>(const Pt3d<tCompl>& p);

     static  Pt3d<Type> P3ToThisT(const Pt3d<int> & aP){return Pt3d<Type>(Type(aP.x),Type(aP.y),Type(aP.z));}
     static  Pt3d<Type> P3ToThisT(const Pt3d<double> & aP){return Pt3d<Type>(Type(aP.x),Type(aP.y),Type(aP.z));}
     static  Pt3d<Type> P3ToThisT(const Pt3d<float> & aP){return Pt3d<Type>(Type(aP.x),Type(aP.y),Type(aP.z));}


     Pt3d<Type>(const Pt2d<Type>&,Type z); // to please visual



     Pt3d(Type X,Type Y,Type Z);
     Pt3d<Type> operator + (const Pt3d<Type> & p2) const;

     Pt3d<Type> operator * (Type) const;
     Pt3d<Type> operator / (Type) const;

     Pt3d<Type> operator - (const Pt3d & p2) const;
     Pt3d<Type> operator - () const;

     typename ElStdTypeScal<Type>::TypeBool  operator == (const Pt3d<Type> & p2) const {return (x==p2.x) && (y==p2.y) && (z==p2.z);}

     // multiplication coordinate by coordinate

     // friend Type  scal<Type> (const Pt3d<Type> & p1,const Pt3d<Type> & p2);
/*
     friend Type Det(const Pt3d<Type> & p1,const Pt3d<Type> & p2,const Pt3d<Type> & p3)
     {
         return scal(p1 ,p2^p3);
     }
*/

     Pt3d<Type>  operator ^ (const Pt3d<Type> & p2) const;
     Pt3d<Type>  &  operator = (const Pt3d<Type> & p2) ;


     void to_tab(Type (& t)[3] ) const;
     static Pt3d<Type> FromTab(const Type *);
     static Pt3d<Type> FromTab(const std::vector<Type> &);


     Pt3d<Type> AbsP() const {return Pt3d<Type>(ElAbs(x),ElAbs(y),ElAbs(z));}
     /*
     friend Pt3d<Type> Sup (const Pt3d<Type> & p1,const Pt3d<Type> & p2)
           { return Pt3d<Type>(ElMax(p1.x,p2.x),ElMax(p1.y,p2.y),ElMax(p1.z,p2.z));}
     friend Pt3d<Type> Inf (const Pt3d<Type> & p1,const Pt3d<Type> & p2)
            { return Pt3d<Type>(ElMin(p1.x,p2.x),ElMin(p1.y,p2.y),ElMin(p1.z,p2.z));}
      */
     Output sigma();
     Output VMax();
     Output VMin();
     Output WhichMax();
     Output WhichMin();

     static Type instantiate();



     // ! Convention Phi = 0 "a l'equateur"
     static  Pt3d<Type>  TyFromSpherique(Type Rho,Type Teta,Type Phi)
     {
        return   Pt3d<Type>
         (
          ElStdTypeScal<Type>::RTtoT(cos(Phi)*cos(Teta)*Rho),
          ElStdTypeScal<Type>::RTtoT(cos(Phi)*sin(Teta)*Rho),
          ElStdTypeScal<Type>::RTtoT(sin(Phi)*Rho)
         );
     }

     private :
          void Verif_adr_xy();
};

typedef Pt3d<int> Pt3di;
typedef Pt3d<double_t> Pt3dr;
typedef Pt3d<float_t> Pt3df;

#endif
