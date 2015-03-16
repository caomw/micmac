#ifndef _ELISE_GENERAL_PHOTOGRAM_CCAMSTENOPEGRID_H
#define _ELISE_GENERAL_PHOTOGRAM_CCAMSTENOPEGRID_H



class cCamStenopeGrid :  public CamStenope
{
public :
    static cCamStenopeGrid * Alloc(double aRayonInv,const CamStenope &,Pt2dr aStepGr,bool doDir=true,bool doInv=true);
    cCamStenopeGrid
    (
            const double & aFoc,
            const Pt2dr &,
            cDistCamStenopeGrid *,
            const Pt2di  & aSz,
            const std::vector<double> & ParamAF
            );

    Pt2dr L2toF2AndDer(Pt2dr aP,Pt2dr & aGX,Pt2dr & aGY);
private :
    bool IsGrid() const;
    ElDistortion22_Gen   *  DistPreCond() const;

    cCamStenopeGrid(const cCamStenopeGrid &); // N.I.
    cDistCamStenopeGrid * mDGrid;
};

#endif
