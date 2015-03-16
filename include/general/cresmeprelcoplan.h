#ifndef _ELISE_GENERAL_PHOTOGRAM_CRESMEPRELCOPLAN_H
#define _ELISE_GENERAL_PHOTOGRAM_CRESMEPRELCOPLAN_H



class cResMepRelCoplan
{
public :
    cResMepRelCoplan();
    cElemMepRelCoplan & BestSol();
    void AddSol(const cElemMepRelCoplan &);
    const std::list<ElRotation3D> &  LRot() const;
    const std::vector<cElemMepRelCoplan> & VElOk() const;
private :
    std::list<cElemMepRelCoplan>    mLElem;
    std::vector<cElemMepRelCoplan>  mVElOk;
    std::list<ElRotation3D>         mLRot;
};

#endif
