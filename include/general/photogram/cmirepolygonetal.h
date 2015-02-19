#ifndef _ELISE_GENERAL_PHOTOGRAM_CMIREPOLYGONETAL_H
#define _ELISE_GENERAL_PHOTOGRAM_CMIREPOLYGONETAL_H

#include "general/sys_dep.h"

class cMirePolygonEtal
{
public :
    bool IsNegatif() const;
    cMirePolygonEtal();
    static const cMirePolygonEtal & IgnMireN6();
    static const cMirePolygonEtal & MtdMire9();
    static const cMirePolygonEtal & IGNMire7();
    static const cMirePolygonEtal & IGNMire5();
    static const cMirePolygonEtal & SofianeMire3();
    static const cMirePolygonEtal & SofianeMire2();
    static const cMirePolygonEtal & SofianeMireR5();
    static const cMirePolygonEtal & MT0();
    static const cMirePolygonEtal & MTClous1();
    static const cMirePolygonEtal & GetFromName(const std::string &);
    INT NbDiam() const;
    REAL KthDiam(INT aK) const;
    const std::string & Name() const;


private :

    static const double TheIgnN6[6];
    static const double TheMTD9[6];
    static const double TheIGNDiams7[7];
    static const double TheIGNDiams5[5];
    static const double TheSofianeDiam3[1];
    static const double TheSofianeDiam2[1];
    static const double TheSofianeDiamR5[5];
    static const double TheMT0Diams[1];
    static const double TheDiamMTClous1[1];

    static cMirePolygonEtal TheNewIGN6;
    static cMirePolygonEtal TheMTDMire9;
    static cMirePolygonEtal TheIGNMire7;
    static cMirePolygonEtal TheIGNMire5;
    static cMirePolygonEtal TheSofiane3;
    static cMirePolygonEtal TheSofiane2;
    static cMirePolygonEtal TheSofianeR5;
    static cMirePolygonEtal TheMT0;
    static cMirePolygonEtal TheMTClous1;

    cMirePolygonEtal(const std::string & mName,const double *,INT NB);

    std::string  mName;
    const double *     mDiams;
    INT          mNBDiam;
};

#endif
