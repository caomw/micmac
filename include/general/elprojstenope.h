#ifndef _ELISE_GENERAL_PHOTOGRAM_ELPROJSTENOPE_H
#define _ELISE_GENERAL_PHOTOGRAM_ELPROJSTENOPE_H



class ElProjStenope : public ElProj32 ,
        public ElProjStenopeGen<double_t>
{
public :

    ElProjStenope(double_t Focale,Pt2dr centre, const tParamAFocal  & AFocalParam);

    Pt2dr Proj(Pt3dr) const;
    Pt3dr DirRayon(Pt2dr) const;
    virtual void Rayon(Pt2dr,Pt3dr &p0,Pt3dr & p1) const;
    void  Diff(ElMatrix<double_t> &,Pt3dr)const ;


    Pt2dr   centre() const;
    void    set_centre(Pt2dr) ;
    virtual ~ElProjStenope() {}
    Pt3dr   CentreProjIm(const Pt2dr &) const;
    Pt3dr   CentreProjTer(const Pt3dr &) const;
private :
};

#endif
