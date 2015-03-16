#ifndef _ELISE_GENERAL_GEOM_VECTEUR_CELTRIANGLECOMP_H
#define _ELISE_GENERAL_GEOM_VECTEUR_CELTRIANGLECOMP_H



class cElTriangleComp
{
    public :
        cElTriangleComp(Pt2dr aP0,Pt2dr aP1,Pt2dr aP2);
            double_t square_dist(Pt2dr pt) const;

        bool Inside(const Pt2dr &) const;

        Pt2dr P0() const;
        Pt2dr P1() const;
        Pt2dr P2() const;

           // Renvoie une matrice telle que pour
       //  un point (x,y) on trouve ses trois
       //  coordonnees bary a partir de
       //
       //
       //    | X |   |  Coeff P1
       //  M | Y | = |  Coeff P2
       //    | 1 |   |  Coeff P3
       //

        ElMatrix<double>  MatCoeffBarry() const;


        Pt3dr  CoordBarry(const Pt2dr &) const;
        Pt2dr  FromCoordBarry(double_t,double_t,double_t) const;

        static void Test();

        const SegComp & S01() const;
        const SegComp & S12() const;
        const SegComp & S20() const;

            // Est ce que ordre trigo
        static bool ToSwap(const Pt2dr & aP0,const  Pt2dr & aP1,const Pt2dr & aP2);
    private :
        static SegComp ReorderDirect(Pt2dr & aP0, Pt2dr & aP1,Pt2dr & aP2);
        SegComp mS01;
        SegComp mS12;
        SegComp mS20;


};

#endif
