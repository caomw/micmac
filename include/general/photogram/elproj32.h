#ifndef _ELISE_GENERAL_PHOTOGRAM_ELPROJ32_H
#define _ELISE_GENERAL_PHOTOGRAM_ELPROJ32_H



class ElProj32
{
public :

    // Methodes de bases a redefinir pour chaque type de projection

    virtual Pt2dr Proj(Pt3dr) const = 0;
    virtual Pt3dr DirRayon(Pt2dr) const = 0;
    virtual void  Diff(ElMatrix<double_t> &,Pt3dr) const = 0;  // differentielle


    virtual void Rayon(Pt2dr,Pt3dr &p0,Pt3dr & p1) const = 0;

    // Interfaces simplifiee
    ElMatrix<double_t> Diff(Pt3dr)const ;

    virtual ~ElProj32() {}
};

#endif
