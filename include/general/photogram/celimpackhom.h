#ifndef _ELISE_GENERAL_PHOTOGRAM_CELIMPACKHOM_H
#define _ELISE_GENERAL_PHOTOGRAM_CELIMPACKHOM_H

#include "general/sys_dep.h"

class cElImPackHom
{
public :
    cElImPackHom(const ElPackHomologue &,int mSsResol,Pt2di aSzR);
    cElImPackHom(const std::string &);
    void AddFile(const std::string &);
    void SauvFile(const std::string &);
    int NbIm() const;  // Minimum 2
    ElPackHomologue  ToPackH(int aK);   // aK commence a O
    Pt2di Sz() const;

    Pt2dr P1(Pt2di);
    Pt2dr PN(Pt2di,int aK);
    double PdsN(Pt2di,int aK);
private :
    void VerifInd(Pt2di aP);
    void VerifInd(Pt2di aP,int aK);

    Pt2di      mSz;
    Im2D_double_t4 mImX1;
    Im2D_double_t4 mImY1;
    std::vector<Im2D_double_t4> mImXn;
    std::vector<Im2D_double_t4> mImYn;
    std::vector<Im2D_double_t4> mImPdsN;

};

#endif
