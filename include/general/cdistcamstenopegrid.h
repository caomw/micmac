#ifndef _ELISE_GENERAL_PHOTOGRAM_CDISTCAMSTENOPEGRID_H
#define _ELISE_GENERAL_PHOTOGRAM_CDISTCAMSTENOPEGRID_H



class cDistCamStenopeGrid : public ElDistortion22_Gen
{
public :
    friend class cCamStenopeGrid;
    Pt2dr DirectAndDer(Pt2dr aP,Pt2dr & aGX, Pt2dr & aGY) const;
    Pt2dr Direct(Pt2dr) const;
    virtual bool OwnInverse(Pt2dr &) const ;    //  return true

    // Si RayonInv <=0 pas utilise
    static cDistCamStenopeGrid * Alloc(double aRayInv,const CamStenope &,Pt2dr aStepGr,bool doDir=true,bool doInv=true);

    cDistCamStenopeGrid
    (
            ElDistortion22_Gen *,
            cDbleGrid *
            );

    static void Test(double aRayInv,const CamStenope &,Pt2dr aStepGr);

    virtual cCalibDistortion ToXmlStruct(const ElCamera *) const;

    std::string Type() const;
private :
    cDistCamStenopeGrid(const cDistCamStenopeGrid &); // N.I.


    ElDistortion22_Gen * mPreC;  // Pre Conditionnement optionnel
    cDbleGrid  *         mGrid;
};

#endif
