#ifndef _ELISE_GENERAL_PHOTOGRAM_CCAMERAORTHO_H
#define _ELISE_GENERAL_PHOTOGRAM_CCAMERAORTHO_H



class cCameraOrtho : public ElCamera
{
public :
    // Pour appeler methode virtuelle dans cstrteur ...
    static cCameraOrtho * Alloc(const Pt2di & aSz);
    Pt3dr OrigineProf() const;
    bool  HasOrigineProf() const;
    double ResolutionSol() const ;
    double ResolutionSol(const Pt3dr &) const ;
private :
    double SzDiffFinie() const;
    cCameraOrtho(const Pt2di & aSz);

    Pt3dr R3toL3(Pt3dr) const;
    Pt3dr L3toR3(Pt3dr) const;

    ElDistortion22_Gen   &  Dist()        ;
    const ElDistortion22_Gen   &  Dist() const  ;
    ElProj32 &        Proj()       ;
    const ElProj32       &  Proj() const ;
    void InstanceModifParam(cCalibrationInternConique &) const ;
    Pt3dr ImEtProf2Terrain(const Pt2dr & aP,double aZ) const;
    Pt3dr NoDistImEtProf2Terrain(const Pt2dr & aP,double aZ) const;

    // La notion d'origine n'a pas reellement de sens pour un projection ortho (au mieux elle
    // situee n'importe ou sur le rayon partant du centre de l'image), pourtant il en faut bien une
    // meme completement arbitraire  pour  des fonctions telle que image et profondeur 2 Terrains
    // quand on correle en faisceau
    Pt3dr mCentre;
};

#endif
