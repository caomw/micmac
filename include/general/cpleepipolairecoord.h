#ifndef _ELISE_GENERAL_PHOTOGRAM_CPLEEPIPOLAIRECOORD_H
#define _ELISE_GENERAL_PHOTOGRAM_CPLEEPIPOLAIRECOORD_H



class CpleEpipolaireCoord
{
public :

    static CpleEpipolaireCoord * EpipolaireNoDist
    (Pt2dr aPHom1,Pt2dr aPHom2,Pt2dr aDir1,Pt2dr aDir2);


    static CpleEpipolaireCoord * PolynomialFromHomologue
    (
            const ElPackHomologue &,
            int   aDegre,
            Pt2dr aDir1,
            Pt2dr aDir2
            );
    static CpleEpipolaireCoord * PolynomialFromHomologue
    (
            const ElPackHomologue & lHL1,
            int   aDegreL1,
            const ElPackHomologue & lHL2,
            int   aDegreL2,
            Pt2dr aDir1,
            Pt2dr aDir2
            );

    static CpleEpipolaireCoord * PolynomialFromHomologue
    (
            CpleEpipolaireCoord  *  aSolApprox, // Solution pour calcul de residu
            double_t  aResiduMin,
            const ElPackHomologue &,
            int   aDegre,
            Pt2dr aDir1,
            Pt2dr aDir2
            );


    static CpleEpipolaireCoord * MappingEpipolaire(ElDistortion22_Gen *,bool ToDel);

    // Il ne s'agit pas d'un vrai systeme epipolaire, l'hoomographie ets
    // utilisee comme un mapping qcq, fait  appel a MappingEpipolaire
    static CpleEpipolaireCoord * MappEpiFromHomographie(cElHomographie);
    static CpleEpipolaireCoord * MappEpiFromHomographieAndDist
    (
            const cElHomographie &,
            const ElDistRadiale_PolynImpair &,
            double_t aRayInv,
            int aDeltaDegreInv
            );

    static CpleEpipolaireCoord * OriEpipolaire
    (
            const std::string & aName1, Pt2dr aP1,
            const std::string & aName2, Pt2dr aP2,
            double_t aZoom
            );

    static CpleEpipolaireCoord * CamEpipolaire
    (
            CamStenope  & aCam1, Pt2dr aP1,
            CamStenope  & aCam2, Pt2dr aP2,
            double_t aZoom
            );

    ~CpleEpipolaireCoord();
    EpipolaireCoordinate & EPI1();
    EpipolaireCoordinate & EPI2();

    Pt2dr Hom12(Pt2dr,Pt2dr aParalaxe); // x=> paralaxe, y variation de colonne
    Pt2dr Hom12(Pt2dr,double_t aParalaxe);
    Pt2dr Hom21(Pt2dr,double_t aParalaxe);
    Pt2dr Hom21(Pt2dr,Pt2dr aParalaxe); // x=> paralaxe, y variation de colonne

    Pt2dr Homol(Pt2dr,Pt2dr aParalaxe,bool Sens12);

    Pt2d<Fonc_Num>  Hom12(Pt2d<Fonc_Num> fXY,Pt2d<Fonc_Num> fParalaxe);


    void write(class  ELISE_fp & aFile) const;
    static CpleEpipolaireCoord * read(ELISE_fp & aFile);
    //     P ->  aChSacle * Pol(P/aChSacle)
    CpleEpipolaireCoord * MapingChScale(double_t aChSacle) const;

    void SelfSwap(); // Intervertit les  2
    CpleEpipolaireCoord * Swap();  // renvoie une nouvelle avec Intervertion
    void AdjustTr2Boxes(Box2dr aBox1,Box2dr aBox2);

    bool IsMappingEpi1() const;

private:

    EpipolaireCoordinate * mEPI1;
    EpipolaireCoordinate * mEPI2;
    double_t                   mFact;

    CpleEpipolaireCoord
    (
            EpipolaireCoordinate * mEPI1,
            EpipolaireCoordinate * mEPI2
            );

    CpleEpipolaireCoord(const CpleEpipolaireCoord &); // Unimplemented
    friend class PourFairePlaisirAGccQuiMemerde;


};

#endif
