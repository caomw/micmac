#ifndef _ELISE_GENERAL_PHOTOGRAM_CPOintEETALONAGE_H
#define _ELISE_GENERAL_PHOTOGRAM_CPOintEETALONAGE_H



class cPointeEtalonage
{
public :
    cPointeEtalonage(cCiblePolygoneEtal::tInd,Pt2dr,const cPolygoneEtal &);
    Pt2dr PosIm() const;
    Pt3dr PosTer() const;
    void SetPosIm(Pt2dr);
    const cCiblePolygoneEtal  & Cible() const;
    bool  UseIt () const;
    double_t  Pds()    const;
private :

    Pt2dr                       mPos;
    const cCiblePolygoneEtal *  mCible;
    bool                        mUseIt;
    double_t                        mPds;

};

#endif
