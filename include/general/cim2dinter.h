#ifndef _ELISE_GENERAL_BITM_CIM2DintER_H
#define _ELISE_GENERAL_BITM_CIM2DintER_H



class cIm2DInter
{
    public :
       virtual double Get(const Pt2dr &)= 0;
       virtual double GetDef(const Pt2dr &,double)= 0;
       virtual int  SzKernel() const = 0;
       virtual ~cIm2DInter(){}
};

#endif
