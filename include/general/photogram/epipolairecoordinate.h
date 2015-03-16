#ifndef _ELISE_GENERAL_PHOTOGRAM_EPIPOLAIRECOORDINATE_H
#define _ELISE_GENERAL_PHOTOGRAM_EPIPOLAIRECOORDINATE_H



class EpipolaireCoordinate : public ElDistortion22_Gen
{
public :

    // Lorsque aParal ballaye R, on obtient
    // la courbe epipolaire passant par aP
    Pt2dr  TransOnLineEpip
    (
            Pt2dr aP,
            double_t aParal
            );



    virtual Pt2dr Direct(Pt2dr) const ;
    virtual bool IsEpipId() const;
    // Inverse est heritee  et fait appel a OwnInverse


    Pt2dr DirEpip(Pt2dr,double_t anEpsilon); // Calcul par difference finie !


    Pt2dr P0() const;
    Pt2dr DirX() const;
    Pt2dr TrFin() const;

    virtual const PolynomialEpipolaireCoordinate * CastToPol() const ; // Down cast, Def = Erreur

    //     P ->  aChSacle * Pol(P/aChSacle)
    virtual EpipolaireCoordinate *
    MapingChScale(double_t aChSacle) const = 0;

    // Fait heriter les parametre globaux aP0, aDirX, aTrFin
    void HeriteChScale(EpipolaireCoordinate &,double_t aChSacle);

    Box2dr ImageOfBox(Box2dr );
    void   AddTrFinale(Pt2dr);
    void   SetTrFinale(Pt2dr);


    void   SetGridCorrec
    (
            Fonc_Num DeltaY, // rab de Y epip, exprime en coord image
            Fonc_Num Pond,   // Binarisee en 0/1 , exprime en coord image
            double_t  aStepGr ,
            Box2dr aBoxIm,
            double_t   aRatioMin = 0.2 // Ratio pour remplir la grille
            );
    virtual ~EpipolaireCoordinate();
protected :
    EpipolaireCoordinate
    (
            Pt2dr aP0,
            Pt2dr aDirX,
            Pt2dr aTrFin
            );
    RImGrid *  mGridCor; // Pour une eventuelle correction finale avec grille
private :


    // Pour les "vrai" systemes epipolaire, la transformation
    // epiplaire ne change pas le X, cependant afin de pouvoir
    // utilise dans les correlateur des mappigng quelconques
    // on redefinit ToYEpipol en ToCoordEpipole

    virtual Pt2dr ToCoordEpipol(Pt2dr aPInit) const = 0;
    virtual Pt2dr ToCoordInit(Pt2dr aPEpi) const = 0;


    virtual bool OwnInverse(Pt2dr &) const ;
    virtual void  Diff(ElMatrix<double_t> &,Pt2dr) const ;  //  => Error Fatale, for now


    Pt2dr      mP0;
    Pt2dr      mDirX;
    Pt2dr      mTrFin;
};

#endif
