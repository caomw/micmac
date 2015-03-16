#ifndef _ELISE_GENERAL_PHOTOGRAM_CPROJCPLE_H
#define _ELISE_GENERAL_PHOTOGRAM_CPROJCPLE_H



class cProjCple
{
public :
    cProjCple(const Pt3dr &,const Pt3dr &,double aPds);
    const Pt3dr & P1() const;
    const Pt3dr & P2() const;

    static cProjCple Spherik(const ElCamera & aCam1,const Pt2dr & ,const ElCamera & aCam2,const Pt2dr &,double aPds);
    static cProjCple Projection(const ElCamera & aCam1,const Pt2dr & ,const ElCamera & aCam2,const Pt2dr &,double aPds);
private :
    Pt3dr  mP1;
    Pt3dr  mP2;
    double mPds;
};

#endif
