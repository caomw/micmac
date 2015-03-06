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


#ifndef _ELISE_GENERAL_BITM_EL_CTYPETRAITS_H
#define _ELISE_GENERAL_BITM_EL_CTYPETRAITS_H

#include "general/sys_dep.h"

template <class Type> class El_CTypeTraits
{
public :
    typedef Type  tVal;
    typedef Type  tBase;
    enum   {eSizeOf = 1111};
    static tVal  RawDataToVal(U_int1 *);
private :
};

template <> class El_CTypeTraits<int1>
{
public :
    static std::string   Name() {return "int1";}
    static const int1 MaxValue() {return SCHAR_MAX;}
    static const int1 MinValue() {return SCHAR_MIN;}
    static Fonc_Num TronqueF(Fonc_Num aFonc) {return Max(tBase(eVMin),Min(tBase(eVMax),aFonc));}
    typedef int1    tSignedVal;
    typedef U_int1  tUnSignedVal;

    typedef int1   tVal;
    typedef int    tBase;
    static bool IsIntType() {return true;}
    static tVal Tronque(tBase aVal) {return ElMax(tBase(eVMin),ElMin(tBase(eVMax),aVal));}
    static tVal TronqueR(double aVal)
    {
        if (aVal>eVMax) return eVMax;
        if (aVal<eVMin) return eVMin;
        return round_ni(aVal);
    }
    enum   {
        eSizeOf = 1,
        eVMax=127,
        eVMin=-128,
        e100PozSize =0
    };
};


template <> class El_CTypeTraits<int2>
{
public :
    static std::string   Name() {return "int2";}
    static const int2 MaxValue () { return SHRT_MAX;}
    static const int2 MinValue () { return SHRT_MIN;}
    static Fonc_Num TronqueF(Fonc_Num aFonc) {return Max(tBase(eVMin),Min(tBase(eVMax),aFonc));}
    typedef int2  tVal;
    typedef int     tBase;
    static bool IsIntType() {return true;}
    static tVal Tronque(tBase aVal) {return ElMax(tBase(eVMin),ElMin(tBase(eVMax),aVal));}
    static tVal TronqueR(double aVal)
    {
        if (aVal>eVMax) return eVMax;
        if (aVal<eVMin) return eVMin;
        return round_ni(aVal);
    }
    enum   {
        eSizeOf = 2,
        eVMax=SHRT_MAX,
        eVMin=SHRT_MIN,
        e100PozSize =10000
    };
};

template <> class El_CTypeTraits<int>
{
public :
    static const int MaxValue (){ return int_MAX;}
    static const int MinValue (){ return int_MIN;}
    static Fonc_Num TronqueF(Fonc_Num aFonc) {return aFonc;}
    static std::string   Name() {return "int";}
    typedef int   tVal;
    typedef int   tBase;
    static bool IsIntType() {return true;}
    static tVal Tronque(tBase aVal) {return aVal;}
    static tVal TronqueR(double aVal) { return round_ni(aVal); }
    enum   {
        eSizeOf = 4,
        eVMax=0,
        eVMin=0,
        e100PozSize =0
    };

};


template <> class El_CTypeTraits<double_t16>
{
public :
    static std::string   Name() {return "double_t16";}
    typedef double_t16   tVal;
    typedef double_t16   tBase;
    static bool IsIntType() {return false;}
    enum   {
        eSizeOf = 16,
        eVMax=0,
        eVMin=0,
        e100PozSize =0
    };
    static tVal Tronque(tBase aVal) {return aVal;}
    static tVal TronqueR(double aVal) { return   aVal;}
};


template <> class El_CTypeTraits<double_t4>
{
public :
    static const double_t4 MaxValue (){return FLT_MAX;}
    static const double_t4 MinValue (){return -FLT_MAX;}
    static Fonc_Num TronqueF(Fonc_Num aFonc) {return aFonc;}
    static std::string   Name() {return "double_t4";}
    typedef double_t4   tVal;
    typedef double_t8   tBase;
    static bool IsIntType() {return false;}
    enum   {
        eSizeOf = 4,
        eVMax=0,
        eVMin=0,
        e100PozSize =0
    };
    static tVal Tronque(tBase aVal) {return (tVal) aVal;}

    static tVal TronqueR(double aVal) { return  (tVal) aVal;}

};

template <> class El_CTypeTraits<double_t8>
{
public :
    static double_t8 MaxValue() {return DBL_MAX;}
    static double_t8 MinValue() {return -DBL_MAX;}
    static Fonc_Num TronqueF(Fonc_Num aFonc) {return aFonc;}
    static std::string   Name() {return "double_t8";}
    typedef double_t8   tVal;
    typedef double_t8   tBase;
    static bool IsIntType() {return false;}
    enum   {
        eSizeOf = 8,
        eVMax=0,
        eVMin=0,
        e100PozSize =0
    };
    static tVal Tronque(tBase aVal) {return aVal;}
    static tVal TronqueR(double aVal) { return   aVal;}
};


template <> class El_CTypeTraits<U_int1>
{
public :
    static const U_int1 MaxValue() {return   UCHAR_MAX;}
    static const U_int1 MinValue() {return   0;}
    static Fonc_Num TronqueF(Fonc_Num aFonc) {return Max(tBase(eVMin),Min(tBase(eVMax),aFonc));}

    static std::string   Name() {return "U_int1";}
    typedef int1    tSignedVal;
    typedef U_int1  tUnSignedVal;

    typedef U_int1  tVal;
    typedef int     tBase;
    static tVal Tronque(tBase aVal) {return ElMax(tBase(eVMin),ElMin(tBase(eVMax),aVal));}
    static tVal TronqueR(double aVal)
    {
        if (aVal>eVMax) return eVMax;
        if (aVal<eVMin) return eVMin;
        return round_ni(aVal);
    }
    static bool IsIntType() {return true;}

    enum   {eSizeOf = 1,eVMin=0,eVMax=255,e100PozSize = 100};
    static tVal  RawData2Val(const U_int1 * Raw) {return  *Raw;}
    static void Val2RawData(U_int1 * Raw,U_int1 val) {*Raw = val;}
    static bool EqualsRaw2Val(const U_int1 * Raw1,const U_int1 * Raw2){return *Raw1==*Raw2;}
private :
};


template <> class El_CTypeTraits<U_int2>
{
public :
    static const U_int2 MaxValue() {return   USHRT_MAX;}
    static const U_int2 MinValue() {return  0;}
    static Fonc_Num TronqueF(Fonc_Num aFonc) {return Max(tBase(eVMin),Min(tBase(eVMax),aFonc));}
    static std::string   Name() {return "U_int2";}
    typedef U_int2  tVal;
    typedef int     tBase;
    static bool IsIntType() {return true;}
    static tVal Tronque(tBase aVal) {return ElMax(tBase(eVMin),ElMin(tBase(eVMax),aVal));}
    static tVal TronqueR(double aVal)
    {
        if (aVal>eVMax) return eVMax;
        if (aVal<eVMin) return eVMin;
        return round_ni(aVal);
    }

    enum   {eSizeOf = 2,eVMin=0,eVMax=0xFFFF,e100PozSize =10000};
    static tVal  RawData2Val(const U_int1 * Raw)
    {
        tVal u;
        ((U_int1 *)&u)[0] = Raw[0];
        ((U_int1 *)&u)[1] = Raw[1];
        return u;
    }
    static void Val2RawData(U_int1 * Raw,U_int2 val)
    {
        Raw[0] = ((U_int1 *)&val)[0]  ;
        Raw[1] = ((U_int1 *)&val)[1]  ;
    }
    static bool EqualsRaw2Val(const U_int1 * Raw1,const U_int1 * Raw2)
    {
        return Raw1[0]==Raw2[0]&& Raw1[1]==Raw2[1];
    }
private :
};

#endif
