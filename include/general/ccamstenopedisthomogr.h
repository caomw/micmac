#ifndef _ELISE_GENERAL_PHOTOGRAM_CCAMSTENOPEDISTHOMOGR_H
#define _ELISE_GENERAL_PHOTOGRAM_CCAMSTENOPEDISTHOMOGR_H



class cCamStenopeDistHomogr : public CamStenope
{
public :
    cCamStenopeDistHomogr
    (bool isDistC2M,double_t Focale,Pt2dr Centre, const cDistHomographie &,const std::vector<double> &);
    const cElHomographie & Hom() const;
private :
    cDistHomographie   mDist;
    cCamStenopeDistHomogr(const cCamStenopeDistHomogr &);
    virtual ElDistortion22_Gen   &  Dist();
    virtual const ElDistortion22_Gen   &  Dist() const;
};

#endif
