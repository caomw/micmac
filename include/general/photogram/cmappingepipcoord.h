#ifndef _ELISE_GENERAL_PHOTOGRAM_CMAPPINGEPIPCOORD_H
#define _ELISE_GENERAL_PHOTOGRAM_CMAPPINGEPIPCOORD_H



class cMappingEpipCoord : public EpipolaireCoordinate
{
public :
    cMappingEpipCoord(ElDistortion22_Gen *,bool toDel);
    ~cMappingEpipCoord();
private :
    virtual bool IsEpipId() const;
    EpipolaireCoordinate * MapingChScale(double_t aChSacle) const;
    Pt2dr ToCoordEpipol(Pt2dr aPInit) const ;
    Pt2dr ToCoordInit(Pt2dr aPEpi) const ;

    ElDistortion22_Gen * mDist;
    bool                 mToDel;
};

#endif
