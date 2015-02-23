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


#ifndef _ELISE_GENERAL_PTXD_CMETADATAPHOTO_H
#define _ELISE_GENERAL_PTXD_CMETADATAPHOTO_H

#include "general/sys_dep.h"

class cMetaDataPhoto
{
    public :

        bool  IsNoMTD() const;


        // Valeur par laquelle il faut mulpitlier elle meme pour egaliser Ref
        double MultiplierEqual(const cMetaDataPhoto &,bool * AllOk) const;

        // static const cMetaDataPhoto &  CreateExiv2(const std::string &,const char * aNameTest=0);
        static const cMetaDataPhoto &  CreateExiv2(const std::string &);
        const cElDate & Date(bool Svp=false) const;
        void SetSz(const Pt2di &);
        void SetFocal(const double &);
        void SetFoc35(const double &);
        void SetCam(const std::string &);
        double FocMm(bool Svp=false) const;
        double Foc35(bool Svp=false) const;
        double  FocPix() const;
        int NbBits(bool Svp=false) const;

        double ExpTime(bool Svp=false) const;
        double Diaph(bool Svp=false) const;
        double IsoSpeed(bool Svp=false) const;
        const std::string &  Cam(bool Svp=false) const;

        Pt2di XifSzIm(bool Svp=false) const;
        Pt2di TifSzIm(bool Svp=false) const;
        Pt2di SzImTifOrXif(bool Svp=false) const;

        void SetXYZTetas(const Pt3dr & aXYZ,const Pt3dr & Tetas);
        bool XYZTetasInit() const;
        const Pt3dr & XYZ() const;
        const Pt3dr & Tetas() const;


         const bool   &  HasGPSLatLon() const;
         const double &  GPSLat() const;
         const double &  GPSLon() const;
         const bool   &  HasGPSAlt() const;
         const double &  GPSAlt() const;
         void SetGPSLatLon(const double & aLat,const double & aLon);
         void SetGPSAlt(const double & anAlt);

         cMetaDataPhoto
         (
                const std::string & aNameIm,
                Pt2di aSzIm,
                const std::string & aCam,
                cElDate mDate,double aFocMm,double Foc35,double aExpTime,
                double aDiaph,double anIsoSpeed,const std::string & aBayPat,
                const std::string & anOrientation, const std::string & aCameraOrientation,
                int aNbBits
         );
         cMetaDataPhoto();
         const std::string  & BayPat() const;
         bool & FocForced();
         const std::string & Orientation() const;
         const std::string & CameraOrientation() const;
   private :
        static cMetaDataPhoto  CreateNewExiv2(const std::string &);

         static cMetaDataPhoto Create(const std::string & aCom,const std::string &);
         static std::string  ExeCom(const std::string & aNameProg,const std::string & aNameFile);

         static cElRegex * mDateRegExiV2;
         static cElRegex * mFocRegExiV2;
         static cElRegex * mFoc35RegExiV2;
         static cElRegex * mExpTimeRegExiV2;
         static cElRegex * mDiaphRegExiV2;
         static cElRegex * mIsoSpeedRegExiV2;
         static cElRegex * mCameraExiV2;
         static cElRegex * mSzImExiV2;
         static const std::string theNameTMP;

         static const cMetaDataPhoto  TheNoMTD;

         std::string  mNameIm;
         mutable Pt2di   mTifSzIm;
         Pt2di   mXifSzIm;
         std::string mCam;
         cElDate mDate;
         double  mFocMm;
         bool    mFocForced;
         double  mFoc35;
         double  mExpTime;
         double  mDiaph;
         double  mIsoSpeed;
         bool    mXYZ_Init;
         bool    mTeta_Init;
         Pt3dr   mXYZ;
         Pt3dr   mTetas;
         std::string  mBayPat;
         bool    mHasGPSLatLon;
         double  mGPSLat;
         double  mGPSLon;
         bool    mHasGPSAlt;
         double  mGPSAlt;
         std::string mOrientation;
         std::string mCameraOrientation;
         int         mNbBits;  // Par defaut initialisee a -1

};

#endif
