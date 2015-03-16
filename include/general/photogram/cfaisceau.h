#ifndef _ELISE_GENERAL_PHOTOGRAM_CELFAISCEAUDR2D_H
#define _ELISE_GENERAL_PHOTOGRAM_CELFAISCEAUDR2D_H



class cElFaisceauDr2D
{
public :
    // Calcul un point projectif correspond a un point de
    // convergence commun du faisceau de droite,
    // suppose une valeur initiale approche en teta,phi

    void PtsConvergence(double_t  & teta0,double_t & phi0, bool OptimPhi);

    // Itere, s'arrete apres NbStep Etape ou si le
    // de residu < Epsilon, ou si le delta residu < DeltaRes
    void PtsConvergenceItere
    (
            double_t  & teta0,double_t & phi0,int NbStep,
            double_t Epsilon, bool OptimPhi,double_t DeltaResidu =-1
            );
    //  Residu de convergence MOYEN du faisceau vers le point
    //  projectif

    double_t ResiduConvergence(double_t  teta,double_t phi);

    void AddFaisceau(Pt2dr aP0,Pt2dr aDir,double_t aPds);



    // Si tout les faisceau ont approximativement la meme
    // direction renvoie une estimation de cette direction,
    // ne necessite pas de valeur initiale
    double_t TetaDirectionInf();


    void CalibrDistRadiale
    (
            Pt2dr   &            aC0,
            bool                 CentreMobile,
            double_t    &            TetaEpip,
            double_t    &            PhiEpip,
            std::vector<double_t> &  Coeffs
            );


private :
    enum {IndTeta,IndPhi};
#ifndef _ELISE_GENERAL_PHOTOGRAM_CFAISCEAU_H
#define _ELISE_GENERAL_PHOTOGRAM_CFAISCEAU_H



    class cFaisceau : public SegComp
    {
    public :
        cFaisceau(Pt2dr aP0,Pt2dr aDir,double_t aPds);
        double_t Pds() const;
    private :
        double_t mPds;
    };

    typedef cFaisceau        tDr;
    typedef std::list<tDr>   tPckDr;
    typedef tPckDr::iterator tIter;

    tIter Begin() {return mPckDr.begin();}
    tIter End() {return mPckDr.end();}
    int NbDr() {return (int) mPckDr.size();}

    tPckDr  mPckDr;
};

#endif
