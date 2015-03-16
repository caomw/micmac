#ifndef _ELISE_GENERAL_PHOTOGRAM_ELDISTPOLYDEGRE2_H
#define _ELISE_GENERAL_PHOTOGRAM_ELDISTPOLYDEGRE2_H



class ElDistPolyDegre2 : public ElDistortion22_Gen
{
public :

    virtual Pt2dr Direct(Pt2dr) const ;  // **
    ElDistPolyDegre2
    (
            const PolyDegre2XY & aPolX,
            const PolyDegre2XY & aPolY,
            double_t EpsilonInv
            );

    // par defaut appel au fonctions "Quick" (ou Quasi)

    virtual void  Diff(ElMatrix<double_t> &,Pt2dr) const;  // ** differentielle

private :

    PolyDegre2XY mPolX;
    PolyDegre2XY mPolY;
    //double_t         mEpsilon;
};

#endif
