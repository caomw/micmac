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


#ifndef _ELISE_GENERAL_UTIL_CELDATE_H
#define _ELISE_GENERAL_UTIL_CELDATE_H

#include "general/sys_dep.h"

class cElDate
{
    public :
       cXmlDate ToXml();
       static cElDate FromXml(const cXmlDate &);

       static const cElDate NoDate;
       bool IsNoDate() const;
       cElDate
       (
         int aDay,
         int aMonth,
         int aYear,
     const cElHour &
       );

        const cElHour &  H() const;
    int Y() const;
    int M() const;
    int D() const;

    static cElDate FromString(const std::string &);

    int NbDayFrom1erJ() const;
    // Ne prend pas en compte les 13 jours "sautes " au 17e
    int NbDayFromJC() const;
    int    DifInDay(const cElDate&) const;
    double DifInSec(const cElDate&) const;

    bool operator==( const cElDate &i_b ) const;
    bool operator!=( const cElDate &i_b ) const;

    // read/write in raw binary format
    void from_raw_data( const char *&io_rawData, bool i_reverseByteOrder );
    void to_raw_data( bool i_reverseByteOrder, char *&o_rawData ) const;
    static unsigned int raw_size();

    void read_raw( std::istream &io_istream, bool i_inverseByteOrder=false );
    void write_raw( std::ostream &io_ostream, bool i_inverseByteOrder=false ) const;

    static void getCurrentDate_local( cElDate &o_localDate );
    static void getCurrentDate_UTC( cElDate &o_utcDate );

    private :
         int mD;
         int mM;
         int mY;
     cElHour mH;

         // !! Les mois commencent a 1
     static const int TheNonBisLengthMonth[12];
     static int TheNonBisLengthMonthCum[12];
     static int TheBisLengthMonthCum[12];
     static bool TheIsBis[3000];
     static int  TheNbDayFromJC[3000];

     static bool mTabuliIsInit;

     static void InitTabul();


     static bool PrivIsBissextile(int aY);
};

#endif
