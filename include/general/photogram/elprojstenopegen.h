#ifndef _ELISE_GENERAL_PHOTOGRAM_ELPROJSTENOPEGEN_H
#define _ELISE_GENERAL_PHOTOGRAM_ELPROJSTENOPEGEN_H

#include "general/sys_dep.h"

template <class Type> class  ElProjStenopeGen
{
public :
    ElProjStenopeGen(Type foc,Type cx,Type cy,const std::vector<Type> & ParamAF);

    Type & focale();
    Type   focale() const;
    Pt2d<Type> PP() const;
    void SetPP(const  Pt2d<Type> &) ;

    void Proj  (Type & x2,Type & y2,Type   x3,Type y3,Type z3) const;
    void DirRayon(Type & x3,Type & y3,Type & z3,Type x2,Type y2) const;

    void  Diff(ElMatrix<Type> &,Type,Type,Type)const ;

    const std::vector<Type>  & ParamAF() const;

    bool   UseAFocal() const;
protected :
    Type DeltaCProjDirTer(Type x3,Type y3,Type z3) const;
    Type DeltaCProjTer(Type x3,Type y3,Type z3) const;
    Type DeltaCProjIm(Type x2,Type y2) const;

    Type               _focale;
    Type               _cx;
    Type               _cy;
    bool               mUseAFocal;
    std::vector<Type>  mParamAF;
};

#endif
