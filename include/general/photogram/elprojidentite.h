#ifndef _ELISE_GENERAL_PHOTOGRAM_ELPROJIDENTITE_H
#define _ELISE_GENERAL_PHOTOGRAM_ELPROJIDENTITE_H



class ElProjIdentite : public ElProj32
{
public :
    Pt2dr Proj(Pt3dr) const ;
    Pt3dr DirRayon(Pt2dr) const ;
    void  Diff(ElMatrix<double_t> &,Pt3dr) const ;  // differentielle
    void Rayon(Pt2dr,Pt3dr &p0,Pt3dr & p1) const ;

    static ElProjIdentite  TheOne;
};

#endif
