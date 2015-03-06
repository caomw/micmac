#ifndef _ELISE_GENERAL_PHOTOGRAM_ELDISTORTION22_TRIVIALE_H
#define _ELISE_GENERAL_PHOTOGRAM_ELDISTORTION22_TRIVIALE_H

#include "general/sys_dep.h"

class ElDistortion22_Triviale : public ElDistortion22_Gen
{
public :
    void  Diff(ElMatrix<double_t> &,Pt2dr) const ;  // ** differentielle
    Pt2dr Direct(Pt2dr) const  ;     //  **
    static ElDistortion22_Triviale  TheOne;
    virtual ElDistortion22_Gen  * D22G_ChScale(double_t aS) const; // Def erreur fatale
    virtual bool IsId() const;
    virtual cCalibDistortion ToXmlStruct(const ElCamera *) const;

private :
    virtual bool OwnInverse(Pt2dr &) const ;    //  return false
};

#endif
