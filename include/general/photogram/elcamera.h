#ifndef _ELISE_GENERAL_PHOTOGRAM_ELCAMERA_H
#define _ELISE_GENERAL_PHOTOGRAM_ELCAMERA_H

#include "general/sys_dep.h"

class ElCamera : public cCapture3D
{
public :
    typedef ElAffin2D tOrIntIma ;

    const bool &   IsScanned() const;
    void  SetScanned(bool mIsSC);

    bool  CaptHasData(const Pt2dr &) const ;
    Pt2dr    Ter2Capteur   (const Pt3dr & aP) const;
    bool     PIsVisibleInImage   (const Pt3dr & aP) const ;
    ElSeg3D  Capteur2RayTer(const Pt2dr & aP) const;
    double ResolImRefFromCapteur() const ;
    bool  HasRoughCapteur2Terrain() const ;
    Pt2dr ImRef2Capteur   (const Pt2dr & aP) const ;
    bool  HasPreciseCapteur2Terrain() const ;
    Pt3dr RoughCapteur2Terrain   (const Pt2dr & aP) const ;
    Pt3dr PreciseCapteur2Terrain   (const Pt2dr & aP) const ;
    double ResolSolOfPt(const Pt3dr &) const;
    double ResolSolGlob() const;

    double  ScaleAfnt() const;

    Pt3dr Vitesse() const;
    void  SetVitesse(const Pt3dr &);
    bool  VitesseIsInit() const;
    Pt3dr IncCentre() const;
    void  SetIncCentre(const Pt3dr &);

    void TestCam(const std::string & aMes);
    const double & GetTime() const;
    void   SetTime(const double &);
    // ProfIsZ si true, ZProf est l'altisol habituel, sinon c'est une profondeur de champ
    cOrientationConique ExportCalibGlob(Pt2di aSzIm,double AltiSol,double Prof,int AddVerif,bool ModMatr,const char * aNameAux,const Pt3di * aNbVeridDet=0) const;

    cCalibrationInternConique ExportCalibInterne2XmlStruct(Pt2di aSzIm) const;
    // cCalibrationInternConique ExportCalibInterne2XmlStruct(Pt2di aSzIm) const;
    cVerifOrient MakeVerif( int aNbVerif,double aProf,const char *,const Pt3di  * aNbDeterm=0) const;
    cOrientationConique  StdExportCalibGlob(bool Matr) const;
    cOrientationConique  StdExportCalibGlob() const;

    virtual  Pt3dr ImEtProf2Terrain(const Pt2dr & aP,double aZ) const = 0;
    virtual  Pt3dr NoDistImEtProf2Terrain(const Pt2dr & aP,double aZ) const = 0;
    void SetAltiSol(double );
    void SetProfondeur(double );

    // void ChangeSys(const cSysCoord & a1Source,const cSysCoord & a2Cible,const Pt3dr & aP);
    static void ChangeSys
    (
            const std::vector<ElCamera *>& ,
            const cTransfo3D & aTr3D,
            bool ForceRot,
            bool AtGroundLevel
            );

    // Pour compatibilite stricte avec ce qui etait fait avant
    // dans cDistStdFromCam::Diff
    virtual double SzDiffFinie() const = 0;
    Pt3dr DirVisee() const;
    double ProfondeurDeChamps(const Pt3dr & aP) const;

    virtual double ResolutionSol() const = 0;
    virtual double ResolutionSol(const Pt3dr &) const = 0;
    double GetAltiSol() const;
    bool AltisSolIsDef() const;
    void UndefAltisSol() ;


    double GetProfondeur() const;
    virtual double GetRoughProfondeur() const; // Tente Prof puis Alti
    bool   ProfIsDef() const;
    eTypeProj GetTypeProj() const;
    CamStenope * CS();
    const CamStenope * CS() const;


    virtual cCamStenopeBilin * CSBil_SVP();
    cCamStenopeBilin * CSBil();

    double  RatioInterSol(const ElCamera &) const;

    double   EcartAngulaire(Pt2dr aPF2A, const ElCamera & CamB, Pt2dr aPF2B) const;
    double   SomEcartAngulaire(const ElPackHomologue &, const ElCamera & CamB, double & aSomP) const;
    double   EcartAngulaire(const Appar23 &) const;
    double   SomEcartAngulaire(const std::vector<Appar23> & aVApp) const;
    // L'identifiant ou le nom d'un camera, est qq chose d'optionnel , rajoute a posteriori
    // pour la debugage-tracabilite

    const std::string &  IdCam() const;
    void SetIdCam(const std::string & aName);

    // ========================

    ElRotation3D & Orient();
    const ElRotation3D & Orient() const;

    void SetOrientation(const ElRotation3D &);

    Pt3dr  PseudoInter(Pt2dr aPF2A,const ElCamera & CamB,Pt2dr aPF2B,double * aD=0) const;
    Pt3dr  CdgPseudoInter(const ElPackHomologue &,const ElCamera & CamB,double & aD) const;

    REAL EcartProj(Pt2dr aPF2A,const ElCamera & CamB,Pt2dr aPF2B) const;

    REAL EcartProj(Pt2dr aPF2A,Pt3dr aPR3,Pt3dr aDirR3) const;


    double  ScaleCamNorm() const;
    Pt2dr   TrCamNorm() const;

    //   R3 : "reel" coordonnee initiale
    //   L3 : "Locale", apres rotation
    //   C2 :  camera, avant distortion
    //   F2 : finale apres Distortion
    //
    //       Orientation      Projection      Distortion
    //   R3 -------------> L3------------>C2------------->F2

    Pt2dr R3toF2(Pt3dr) const;
    Pt2dr R3toC2(Pt3dr) const;

    virtual Pt3dr R3toL3(Pt3dr) const;
    virtual Pt3dr L3toR3(Pt3dr) const;

    // Direction en terrain de l'axe camera
    Pt3dr  DirK() const; // OO

    // A la orilib
    Pt3dr F2AndZtoR3(const Pt2dr & aPIm,double aZ) const;

    Pt2dr F2toC2(Pt2dr) const;
    void F2toRayonL3(Pt2dr,Pt3dr &aP0,Pt3dr & aP1) const;
    void F2toRayonR3(Pt2dr,Pt3dr &aP0,Pt3dr & aP1) const;

    Pt3dr PtFromPlanAndIm(const cElPlan3D  & aPlan,const Pt2dr& aP) const;


    ElSeg3D F2toRayonR3(Pt2dr) const;
    Pt3dr   F2toDirRayonL3(Pt2dr) const;
    Pt3dr   F2toDirRayonR3(Pt2dr) const;
    Pt3dr   C2toDirRayonR3(Pt2dr) const;
    Pt2dr   F2toPtDirRayonL3(Pt2dr) const;  // Meme chose, enleve la z a 1
    Pt2dr   L3toF2(Pt3dr) const;
    Pt2dr   PtDirRayonL3toF2(Pt2dr) const;

    Pt3dr   C2toDirRayonL3(Pt2dr) const;
    Pt2dr   L3toC2(Pt3dr) const;

    // Transforme en points photogrammetriques
    ElPackHomologue F2toPtDirRayonL3(const ElPackHomologue &,ElCamera * aCam2=0);  // Def = this
    ElCplePtsHomologues F2toPtDirRayonL3(const ElCplePtsHomologues &,ElCamera * aCam2=0); // Def = this

    Appar23   F2toPtDirRayonL3(const Appar23 &);
    std::list<Appar23>  F2toPtDirRayonL3(const std::list<Appar23>&);

    // Renvoie la somme des ecarts entre la projection des points
    // 3D et les points 2D

    bool Devant(const Pt3dr &) const;
    bool TousDevant(const std::list<Pt3dr> &) const;
    REAL EcProj(const std::list<Pt3dr> & PR3 ,
                const std::list<Pt2dr> & PF2) const;

    REAL EcProj ( const std::list<Appar23> & P23);

    // Differentielle de l'application globale
    // par rapport a un point
    void  DiffR3F2(ElMatrix<REAL> &,Pt3dr) const;
    ElMatrix<REAL>  DiffR3F2(Pt3dr) const;
    // par rapport aux params
    void  DiffR3F2Param(ElMatrix<REAL> &,Pt3dr) const;
    ElMatrix<REAL>  DiffR3F2Param(Pt3dr) const;

    // void SetDistInverse();
    // void SetDistDirecte();

    bool DistIsDirecte() const;
    bool DistIsC2M() const;
    Pt2dr DistDirecte(Pt2dr aP) const;
    Pt2dr DistInverse(Pt2dr aP) const;
    Pt2dr DistDirecteSsComplem(Pt2dr aP) const;
    Pt2dr DistInverseSsComplem(Pt2dr aP) const;


    // Les tailles representent des capteurs avant Clip et Reech
    const  Pt2di & Sz() const;
    Pt2dr  SzPixel() const;
    Pt2dr  SzPixelBasik() const;
    void  SetSzPixel(const Pt2dr &) ;

    void  SetSz(const Pt2di &aSz,bool AcceptInitMult=false);
    bool SzIsInit() const;

    void SetParamGrid(const cParamForGrid &);
    // AVANT REECH etc... , sz soit etre connu
    void  SetRayonUtile(double aRay,int aNbDisc);

    // La Box utile tient compte d'une eventuelle  affinite
    // elle peut tres bien avoir des coord negatives
    Box2dr BoxUtile() const;

    void HeritComplAndSz(const ElCamera &);
    void CamHeritGen(const ElCamera &,bool WithCompl,bool WithOrientInterne=true);

    void AddCorrecRefrac(cCorrRefracAPost *);
    void AddDistCompl(bool isDirect,ElDistortion22_Gen *);
    void AddDistCompl
    (
            const std::vector<bool> &  isDirect,
            const std::vector<ElDistortion22_Gen *> &
            );
    Pt2dr DComplC2M(Pt2dr  ) const;
    Pt2dr DComplM2C(Pt2dr,bool UseTrScN = true  ) const;
    Pt2dr NormC2M(Pt2dr aP) const;
    Pt2dr NormM2C(Pt2dr aP) const;

    ElDistortion22_Gen   &  Get_dist()        ;
    const ElDistortion22_Gen   &  Get_dist() const  ;
    const std::vector<ElDistortion22_Gen *> & DistCompl() const;
    const std::vector<bool> & DistComplIsDir() const;


    // Ajoute une transfo finale pour aller vers la
    // camera, typiquement pour un crop/scale

    void SetScanImaM2C(const tOrIntIma  &);
    void SetScanImaC2M(const tOrIntIma &);
    void SetIntrImaM2C(const tOrIntIma  &);
    void SetIntrImaC2M(const tOrIntIma &);

    Pt2dr OrGlbImaM2C(const Pt2dr &) const;
    Pt2dr OrGlbImaC2M(const Pt2dr &) const;

    Pt2dr OrScanImaM2C(const Pt2dr &) const;

    Pt2dr OrIntrImaC2M(const Pt2dr &) const;

    // const ElSimilitude & SimM2C();
    static const Pt2di   TheSzUndef ;
    const std::vector<Pt2dr> &  ContourUtile() ;
    bool  HasRayonUtile() const;
    bool IsInZoneUtile(const Pt2dr & aP) const;
    bool     GetZoneUtilInPixel() const;

    double  RayonUtile() const;
    // A priori lie a HasRayonUtile, mais eventuellement
    // autre chose
    bool    HasDomaineSpecial() const;

    virtual ElDistortion22_Gen   *  DistPreCond() const ;
    // Eventuellement a redef; now : DistPreCond != 0
    bool IsForteDist() const;


    virtual bool IsGrid() const;
    virtual ~ElCamera();
    // Coincide avec le centre optique pour les camera stenope, est la position
    // du centre origine pour les camera ortho (utilise pour la geom faisceau)
    virtual Pt3dr OrigineProf() const;
    virtual bool  HasOrigineProf() const;
    const cElPolygone &  EmpriseSol() const;

    const tOrIntIma & IntrOrImaC2M() const;

    virtual Pt3dr ImEtZ2Terrain(const Pt2dr & aP,double aZ) const;

    Pt2dr ResiduMond2Cam(const Pt2dr & aRes)const;
    tOrIntIma  InhibeScaneOri();
    void RestoreScaneOri(const tOrIntIma &);
protected :

    // Ces deux similitudes permettent d'implanter le crop-scale-rotate
    // peut-etre a remplacer un jour par une ElAffin2D; sans changer
    // l'interface
    //
    tOrIntIma                      mScanOrImaC2M;
    tOrIntIma                      mIntrOrImaC2M;
    tOrIntIma                      mGlobOrImaC2M;

    tOrIntIma                      mScanOrImaM2C;
    tOrIntIma                      mIntrOrImaM2C;
    tOrIntIma                      mGlobOrImaM2C;


    void ReCalcGlbOrInt();




    // Translation et scale de Normalisation
    Pt2dr                          mTrN;
    double                         mScN;


    std::vector<ElDistortion22_Gen *> mDistCompl;
    std::vector<bool>                 mDComplIsDirect;
    cCorrRefracAPost *                mCRAP;

    ElCamera(bool isDistC2M,eTypeProj);
    ElRotation3D     _orient;

    virtual       ElProj32 &        Proj()       = 0;
    virtual const ElProj32       &  Proj() const = 0;
    Pt2di    mSz;
    Pt2dr    mSzPixel;



    // Une distorsion de "pre-conditionnement" est une fonction "simple"
    // qui approxime la partie non lineaire de la distorsion, si !=0 elle
    // est exprimee dans le sens M->C , 0 signifie identite
    //
    // Elle est utilisee notamment parce que les distorsions "compliquees"
    // peuvent etre exprimees comme la composition d'une distorsion
    // grille a faible distorsion de la distorsion de "pre-conditionnement"
protected :
    bool             mDIsDirect;
public :
    virtual       ElDistortion22_Gen   &  Dist()        = 0;
protected :
    virtual void InstanceModifParam(cCalibrationInternConique &) const  =0;
    virtual const ElDistortion22_Gen   &  Dist() const  = 0;

    void AssertSolInit() const;


    eTypeProj   mTypeProj;
protected :
    bool        mAltisSolIsDef;
    double      mAltiSol;
    bool        mProfondeurIsDef;
    double      mProfondeur;

private :

    std::string  mIdCam;

    //double      mPrecisionEmpriseSol;
    cElPolygone mEmpriseSol;
    Box2dr      mBoxSol;

    double              mRayonUtile;
    bool                mHasDomaineSpecial;
    bool                mDoneScanContU;
    std::vector<Pt2dr>  mContourUtile;

protected :
    bool                 mParamGridIsInit;
    Pt2dr                mStepGrid;
    double               mRayonInvGrid;
    double               mTime;
    double               mScaleAfnt;  // Echelle de l'affinite !!
    bool                 mScanned;

private :
    Pt3dr  mVitesse;
    bool   mVitesseIsInit;
    Pt3dr  mIncCentre;
};

#endif
