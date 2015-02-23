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


#ifndef _ELISE_GENERAL_PTXD_CSYSCOORD_H
#define _ELISE_GENERAL_PTXD_CSYSCOORD_H

#include "general/sys_dep.h"

class cSysCoord
{
     public :

         ElMatrix<double> JacobToGeoc(const Pt3dr &,const Pt3dr& Epsilon = Pt3dr(0.1,0.1,0.1) ) const;
         ElMatrix<double> JacobFromGeoc(const Pt3dr &,const Pt3dr& Epsilon = Pt3dr(0.1,0.1,0.1)) const;



         // Au moins un des deux ToGeoC doit etre defini, car les version par defaut definissent l'un par rapport
         // a l'autre, d'ou possible recursion infinie ....
         virtual Pt3dr ToGeoC(const Pt3dr &) const ;
         virtual std::vector<Pt3dr> ToGeoC(const std::vector<Pt3dr> &) const ;

         // Idem from GeoC
         virtual Pt3dr FromGeoC(const Pt3dr &) const ;
         virtual std::vector<Pt3dr> FromGeoC(const std::vector<Pt3dr> &) const ;






         Pt3dr FromSys2This(const cSysCoord &,const Pt3dr &) const;

         ElMatrix<double> JacobSys2This(const cSysCoord &,const Pt3dr &,const Pt3dr& Epsilon = Pt3dr(0.1,0.1,0.1)) const;

         virtual cSystemeCoord ToXML() const = 0;

          virtual Pt3dr OdgEnMetre() const = 0;  // Ordre dde grandeir en metre
                                                 //  tq. p.x est la valeur donnant en ordre de grandeur un dep de 1

          static cSysCoord * GeoC();
          static cSysCoord * WGS84();
          static cSysCoord * WGS84Degre();
          static cSysCoord * RTL(const Pt3dr & Ori);
          static cSysCoord * FromXML(const cSystemeCoord &,const char * aDir);

          static cSysCoord * FromFile(const std::string & aNF,const std::string & aTag="SystemeCoord");

          static cSysCoord * ModelePolyNomial
                             (
                                    Pt3di aDegX,
                                    Pt3di aDegY,
                                    Pt3di aDegZ,
                                    cSysCoord * aSysIn,
                                    const std::vector<Pt3dr> & aVin,
                                    const std::vector<Pt3dr> & aVout
                             );

          static cSysCoordPolyn * TypedModelePolyNomial
                             (
                                    Pt3di aDegX,
                                    Pt3di aDegY,
                                    Pt3di aDegZ,
                                    cSysCoord * aSysIn,
                                    const std::vector<Pt3dr> & aVin,
                                    const std::vector<Pt3dr> & aVout
                             );

          virtual void Delete() = 0;  //  Virtuel car certain sont "indestructible"

         ElMatrix<double> Jacobien(const Pt3dr &,const Pt3dr& Epsilon,bool SensToGeoC) const;
         std::vector<ElMatrix<double> > Jacobien(const std::vector<Pt3dr > &,const Pt3dr& Epsilon,bool SensToGeoC,std::vector<Pt3dr> * aVPts=0 ) const;

     protected :
           virtual ~cSysCoord();
     private :

         Pt3dr  Transfo(const Pt3dr &, bool SensToGeoC) const;
         std::vector<Pt3dr>  Transfo(const std::vector<Pt3dr> & aV, bool SensToGeoC) const;



          static cSysCoord * FromXML
                             (
                                   const cBasicSystemeCoord * &,
                                   int  & aNbB,
                                   const char * aDir
                             );
};

#endif
