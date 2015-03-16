#ifndef _ELISE_GENERAL_PHOTOGRAM_CAMSTENOPE_H
#define _ELISE_GENERAL_PHOTOGRAM_CAMSTENOPE_H



#include <ElCamera>

class CamStenope : public ElCamera
{
public :

    double GetRoughProfondeur() const; // Tente Prof puis Alti
    const tParamAFocal   & ParamAF() const;

    void StdNormalise(bool doScale,bool  doTr);
    void StdNormalise(bool doScale,bool  doTr,double aS,Pt2dr  aTr);
    void UnNormalize();
    // .xml ou .ori
    static CamStenope * StdCamFromFile(bool UseGr,const std::string &,cInterfChantierNameManipulateur * anICNM);

    virtual const cCamStenopeDistRadPol * Debug_CSDRP() const;


    // renvoit la distance de p1 a la projection de la droite
    // Inhibee car non testee

    // La methode a ete definie dans la mere, il n'y a aucun interet
    // apparement a la specialiser

    // double_t EcartProj(Pt2dr aPF2A,const ElCamera & CamB,Pt2dr aPF2B);

    // Helas, le SzIm n'est pas integre dans mes CamStenope ...





    CamStenope(bool isDistC2M,double_t Focale,Pt2dr centre,const std::vector<double>  & AFocalParam);
    CamStenope(const CamStenope &,const ElRotation3D &);

    // Par defaut true, mais peut redefini, par exemple pour
    // un fish-eye
    virtual bool CanExportDistAsGrid() const;

    void OrientFromPtsAppui
    (
            std::list<ElRotation3D> &,
            Pt3dr R3A, Pt3dr R3B, Pt3dr R3C,
            Pt2dr F2A, Pt2dr F2B, Pt2dr F2C
            );
    void OrientFromPtsAppui
    (
            std::list<ElRotation3D> & Res,
            const std::list<Pt3dr> & PR3 ,
            const std::list<Pt2dr> & PF2
            );
    void OrientFromPtsAppui
    (
            std::list<ElRotation3D>  & Res,
            const std::list<Appar23> & P32
            );

    // Si  NbSol ==  0 et resultat vide => Erreur
    // Sinon *NbSol Contient  le nombre de solution

    ElRotation3D  OrientFromPtsAppui
    (
            bool TousDevant,
            const std::list<Pt3dr> & PR3 ,
            const std::list<Pt2dr> & PF2 ,
            double_t * Ecart = 0,
            int  * NbSol    = 0
            );

    ElRotation3D  OrientFromPtsAppui
    (
            bool TousDevant,
            const std::list<Appar23> & P32 ,
            double_t * Ecart = 0,
            int  * NbSol    = 0
            );
    ElRotation3D  CombinatoireOFPAGen
    (
            bool TousDevant,
            int  NbTest,
            const std::list<Pt3dr> & PR3 ,
            const std::list<Pt2dr> & PF2,
            double_t * Res_Dmin,
            bool   ModeRansac,
            Pt3dr * aDirApprox = 0
            );

    ElRotation3D  CombinatoireOFPA
    (
            bool TousDevant,
            int  NbTest,
            const std::list<Pt3dr> & PR3 ,
            const std::list<Pt2dr> & PF2,
            double_t * Res_Dmin,
            Pt3dr * aDirApprox = 0
            );

    ElRotation3D  RansacOFPA
    (
            bool TousDevant,
            int  NbTest,
            const std::list<Appar23> & P23 ,
            double_t * Res_Dmin,
            Pt3dr * aDirApprox = 0
            );



    ElRotation3D  CombinatoireOFPA
    (
            bool TousDevant,
            int  NbTest,
            const std::list<Appar23> & P32 ,
            double_t * Res_Dmin,
            Pt3dr * aDirApprox = 0
            );


    // Orientations avec "GPS", i.e. avec centre fixe

    void Set_GPS_Orientation_From_Appuis
    (
            const Pt3dr & aGPS,
            const std::vector<Appar23> & aVApp,
            int  aNbRansac
            );

    // Pour compatibilite temporaire avec la proj carto d'orilib
    virtual Ori3D_Std * CastOliLib();  // OO  Def return 0
    Ori3D_Std * NN_CastOliLib();  //OO   Erreur si 0
    double ResolutionPDVVerticale();  //OO   OriLib::resolution, assume implicitement une
    // PDV sub verticale
    double ResolutionAngulaire() const;  // OO
    double ResolutionSol() const ;
    double ResolutionSol(const Pt3dr &) const ;
    // Pour l'instant bovin, passe par le xml
    virtual CamStenope * Dupl() const;   // OO


    double_t Focale() const ;
    Pt2dr PP() const ;
    Pt3dr VraiOpticalCenter() const;
    Pt3dr PseudoOpticalCenter() const;
    Pt3dr OpticalVarCenterIm(const Pt2dr &) const;
    Pt3dr OpticalVarCenterTer(const Pt3dr &) const;
    Pt3dr ImEtProf2Terrain(const Pt2dr & aP,double aZ) const;
    Pt3dr NoDistImEtProf2Terrain(const Pt2dr & aP,double aZ) const;
    Pt3dr ImEtZ2Terrain(const Pt2dr & aP,double aZ) const;
    void  Coins(Pt3dr &aP1, Pt3dr &aP2, Pt3dr &aP3, Pt3dr &aP4, double aZ) const;

    Pt3dr  ImEtProfSpherik2Terrain(const Pt2dr & aPIm,const double_t & aProf) const; //OO
    Pt3dr  ImDirEtProf2Terrain(const Pt2dr & aPIm,const double_t & aProf,const Pt3dr & aNormPl) const; //OO
    Pt3dr Im1DirEtProf2_To_Terrain  //OO
    (Pt2dr p1,const CamStenope &  ph2,double prof2,const Pt3dr & aDir) const;
    Pt3dr Im1EtProfSpherik2_To_Terrain (Pt2dr p1,const CamStenope &  ph2,double prof2) const;


    double ProfInDir(const Pt3dr & aP,const Pt3dr &) const; // OO


    // Sert pour un clonage, par defaut null
    virtual ElProj32             &  Proj();
    virtual const ElProj32       &  Proj() const;
    virtual ElDistortion22_Gen   &  Dist();
    virtual const ElDistortion22_Gen   &  Dist() const;

    // Def  : erreur fatale
    virtual cParamIntrinsequeFormel * AllocParamInc(bool isDC2M,cSetEqFormelles &);


    cCamStenopeDistRadPol *Change2Format_DRP
    (
            bool C2M,
            int  aDegreOut,
            bool CDistPPLie,
            double Resol,
            Pt2dr  Origine
            );




    void InstanceModifParam(cCalibrationInternConique &)  const;
    Pt3dr OrigineProf() const;
    bool  HasOrigineProf() const;
    bool  UseAFocal() const;
private :
    CamStenope(const CamStenope &); // N.I.

protected :
    ElProjStenope  _PrSten;
    bool                 mUseAF;
    ElDistortion22_Gen * mDist;

    double SzDiffFinie() const;
};

#endif
