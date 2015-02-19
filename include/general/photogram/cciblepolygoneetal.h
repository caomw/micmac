#ifndef _ELISE_GENERAL_PHOTOGRAM_CCIBLEPOLYGONEETAL_H
#define _ELISE_GENERAL_PHOTOGRAM_CCIBLEPOLYGONEETAL_H

#include "general/sys_dep.h"

class cCiblePolygoneEtal
{
public :
    typedef int tInd;
    typedef enum
    {
        ePerfect = 0,
        eBeurk   = 1
    } tQualCible;


    void SetPos(Pt3dr aP );
    Pt3dr Pos() const;
    tInd Ind() const;
    const cMirePolygonEtal &  Mire() const;
    tQualCible Qual() const;

    cCiblePolygoneEtal
    (
            tInd,Pt3dr,const cMirePolygonEtal &,INT Qual,
            cCibleCalib *,
            int anOrder
            );
    cCiblePolygoneEtal();

    cCibleCalib * CC() const;
    int Order() const;

private :
    tInd                     mInd;
    Pt3dr                    mPos;
    const cMirePolygonEtal * mMire;
    tQualCible               mQual;
    cCibleCalib *            mCC;
    int                      mOrder;
};

#endif
