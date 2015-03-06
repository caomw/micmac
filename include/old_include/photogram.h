/*Header-MicMac-eLiSe-25/06/2007

    MicMac : Multi Image Correspondances par Methodes Automatiques de Correlation
    eLiSe  : ELements of an Image Software Environnement

    www.micmac.ign.fr


    Copyright : Institut Geographique National
    Author : Marc Pierrot Deseilligny
    Contributors : Gregoire Maillet, Didier Boldo.

[1] M. Pierrot-Deseilligny, N. Paparoditis.
    "A multiresolution and optimization-based image matching approach:
    An application to surface reconstruction from SPOT5-HRS stereo imagery."
    In IAPRS vol XXXVI-1/W41 in ISPRS Workshop On Topographic Mapping From Space
    (With Special Emphasis on Small Satellites), Ankara, Turquie, 02-2006.

[2] M. Pierrot-Deseilligny, "MicMac, un lociel de mise en correspondance
    d'images, adapte au contexte geograhique" to appears in
    Bulletin d'information de l'Institut Geographique National, 2007.

Francais :

   MicMac est un logiciel de mise en correspondance d'image adapte
   au contexte de recherche en information geographique. Il s'appuie sur
   la bibliotheque de manipulation d'image eLiSe. Il est distibue sous la
   licences Cecill-B.  Voir en bas de fichier et  http://www.cecill.info.


English :

    MicMac is an open source software specialized in image matching
    for research in geographic information. MicMac is built on the
    eLiSe image library. MicMac is governed by the  "Cecill-B licence".
    See below and http://www.cecill.info.

Header-MicMac-eLiSe-25/06/2007*/



#ifndef _ELISE_GENERAL_PHOTOGRAM_H
#define _ELISE_GENERAL_PHOTOGRAM_H

#include <list>


//  La distorsion est-elle codee de maniere privilegiee dans le sens
//  Monde->Cam (M2C,=true) ou Cam->Mond (C2M), jusqu'a present (mars 2008)
//  c'etait dans le
//  sens C2M car c'est le sens utile pour les point de liaison avec une
//  equation de coplanarite. Les convention hors elise sont plutot C2M
//
//  Avec l'introduction des residus terrain (point 3D subsitues), on
//  peut faire l'un ou l'autre. Les avantage de M2C sont :
//
//    - coherence avec le reste du monde,
//    - residu vraiment images
//
//  Les avantages de C2M :
//
//     - on sait a 100% que ca marche, puisque c'est le systeme actuel
//     - on peut continuer a utiliser l'equation de coplanarite
//     (mais, est elle utile avec les points terrain ?)
//
//
//
//
//
#define  ElPrefDist_M2C  true

extern bool NewBug;
extern bool DoCheckResiduPhgrm;
extern bool AcceptFalseRot;

// Definis dans phgr_formel.h
class cSetEqFormelles;
class cParamIntrinsequeFormel;
class cParamIFDistStdPhgr;
class cParamIFDistRadiale;



class ElSeg3D;
class Appar23;
class ElCplePtsHomologues;
class ElPackHomologue;
class StatElPackH;
class ElPhotogram;
class ElProj32;
template <class Type> class  ElProjStenopeGen;
class ElProjStenope;
class ElDistortion22_Gen;
class ElDistortion22_Triviale;
class ElDistRadiale;
class ElDistRadiale_PolynImpair;
class ElDistRadiale_Pol357;
class PolyDegre2XY;
class ElDistPolyDegre2;

class ElDistortionPolynomiale;
class ElCamera;
class CamStenope;
class cCamStenopeGen;
class CamStenopeIdeale;
class CalcPtsInteret;
class cCamStenopeDistRadPol;

class cDistorBilin;
class cCamStenopeBilin;

class PolynomialEpipolaireCoordinate;
class EpipolaireCoordinate;

class CpleEpipolaireCoord;
class cElHomographie;

class cElemMepRelCoplan;
class cResMepRelCoplan;

class cDbleGrid ;
class cDistCamStenopeGrid;
class cCamStenopeGrid;

class cMirePolygonEtal;


class cCalibrationInternConique;
class cOrientationConique;
class cVerifOrient;
class cCalibDistortion;
class cCalibrationInterneRadiale;
class cCalibrationInternePghrStd;
class cGridDirecteEtInverse;
class cParamForGrid;
class cPreCondGrid;
class cCorrectionRefractionAPosteriori;

class Appar23
{
public :
    Pt2dr pim;
    Pt3dr pter;
    int   mNum;  // Rajoutes pour gerer les cibles

    Appar23 (Pt2dr PIM,Pt3dr PTER,int aNum=-1) ;

private  :

};
Appar23  BarryImTer(const std::list<Appar23> &);
void InvY(std::list<Appar23> &,Pt2dr aSzIm,bool InvX=false);


// extern bool BugSolveCstr;
// extern bool BugCstr;
extern bool BugFE; // pour debuguer les pb de non inversibilite des dist fortes
extern bool BugAZL; // pour debuguer les pb d'AZL
extern bool BugGL; // pour debuguer les pb de Guimbal Lock


class cProjCple
{
public :
    cProjCple(const Pt3dr &,const Pt3dr &,double aPds);
    const Pt3dr & P1() const;
    const Pt3dr & P2() const;

    static cProjCple Spherik(const ElCamera & aCam1,const Pt2dr & ,const ElCamera & aCam2,const Pt2dr &,double aPds);
    static cProjCple Projection(const ElCamera & aCam1,const Pt2dr & ,const ElCamera & aCam2,const Pt2dr &,double aPds);
private :
    Pt3dr  mP1;
    Pt3dr  mP2;
    double mPds;
};

class cProjListHom
{
public :
    typedef std::vector<cProjCple>      tCont;
    typedef tCont::iterator           tIter;
    typedef tCont::const_iterator     tCstIter;
    tCstIter & begin() const;
    tCstIter & end() const;

    cProjListHom(  const ElCamera & aCam1,const ElPackHomologue & aPack12,
                   const ElCamera & aCam2,const ElPackHomologue & aPack21,
                   bool Spherik
                   );
public :
    tCont       mLClpe;
    bool        mSpherik;
};



class cNupletPtsHomologues
{
public :
    ElCplePtsHomologues & ToCple();
    const ElCplePtsHomologues & ToCple() const;

    // Uniquement en dim 2
    const Pt2dr & P1() const ;
    Pt2dr & P1() ;
    const Pt2dr & P2() const ;
    Pt2dr & P2() ;



    const double_t & Pds() const ;
    double_t & Pds() ;

    cNupletPtsHomologues(int aNb,double aPds=1.0);
    int NbPts() const;

    const Pt2dr & PK(int aK) const ;
    Pt2dr & PK(int aK) ;

    void write(class  ELISE_fp & aFile) const;
    static cNupletPtsHomologues read(ELISE_fp & aFile);

    void AddPts(const Pt2dr & aPt);

    bool IsDr(int aK) const;
    void SetDr(int aK);

private :
    void AssertD2() const;
    std::vector<Pt2dr> mPts;
    double_t  mPds;
    // Gestion super bas-niveau avec des flag de bits pour etre compatible avec la structure physique faite
    // quand on ne contenait que des points ....
    int   mFlagDr;
    void AssertIsValideFlagDr(int aK) const;
    bool IsValideFlagDr(int aK) const;

};

class ElRotation3D;
class ElCplePtsHomologues : public cNupletPtsHomologues
{
public :

    ElCplePtsHomologues (Pt2dr aP1,Pt2dr aP2,double_t aPds=1.0);

    const Pt2dr & P1() const ;
    Pt2dr & P1() ;

    const Pt2dr & P2() const ;
    Pt2dr & P2() ;


    // Box2D
    void SelfSwap(); // Intervertit les  2

    double Profondeur(const ElRotation3D & aR) const;

private :

};

enum eModeleCamera
{
    eModeleCamIdeale,
    eModeleCamDRad,
    eModeleCamPhgrsStd
};


class cResolvAmbiBase
{
public :
    // Les orientations sont des orientations tq R.ImAff(0) est le centre optique, Cam->Monde
    cResolvAmbiBase
    (
            const ElRotation3D &  aR0,   // Orientation connue completement
            const ElRotation3D &  aR1   // Orientation connue a un facteur d'echelle pres sur la base
            );

    void AddHom(const ElPackHomologue & aH12,const ElRotation3D & aR2);
    double SolveBase();
    ElRotation3D SolOrient(double & aLambda);


private :

    Pt3dr mC0;
    Pt3dr mV01;
    ElRotation3D &mR1;
    std::vector<double> mLambdas;
};

// txt : format texte,  dat : format binaire (int , double[3] *)
std::vector<Pt3dr> * StdNuage3DFromFile(const std::string &);


// Representation des points homologues comme images, utiles lorsqu'ils
// sont denses et + ou - regulierement espaces avec une image maitresse

class cElImPackHom
{
public :
    cElImPackHom(const ElPackHomologue &,int mSsResol,Pt2di aSzR);
    cElImPackHom(const std::string &);
    void AddFile(const std::string &);
    void SauvFile(const std::string &);
    int NbIm() const;  // Minimum 2
    ElPackHomologue  ToPackH(int aK);   // aK commence a O
    Pt2di Sz() const;

    Pt2dr P1(Pt2di);
    Pt2dr PN(Pt2di,int aK);
    double PdsN(Pt2di,int aK);
private :
    void VerifInd(Pt2di aP);
    void VerifInd(Pt2di aP,int aK);

    Pt2di      mSz;
    Im2D_double_t4 mImX1;
    Im2D_double_t4 mImY1;
    std::vector<Im2D_double_t4> mImXn;
    std::vector<Im2D_double_t4> mImYn;
    std::vector<Im2D_double_t4> mImPdsN;

};




class cPackNupletsHom
{
public :
    typedef std::list<cNupletPtsHomologues>   tCont;
    typedef tCont::iterator                  tIter;
    typedef tCont::const_iterator            tCstIter;
    cPackNupletsHom(int aDim);

    void write(class  ELISE_fp & aFile) const;
    static cPackNupletsHom read(ELISE_fp & aFile);
    typedef tCont::iterator         iterator;
    typedef tCont::const_iterator   const_iterator;

    cNupletPtsHomologues & back();
    const cNupletPtsHomologues & back() const;

    iterator       begin();
    const_iterator begin() const;
    iterator       end();
    const_iterator end() const;
    int size() const ;
    void clear();

    void AddNuplet(const cNupletPtsHomologues &);

    const cNupletPtsHomologues * Nuple_Nearest(Pt2dr aP,int aK) const;
    void  Nuple_RemoveNearest(Pt2dr aP,int aK) ;

    const ElPackHomologue & ToPckCple() const;

protected :
    tCont::iterator  NearestIter(Pt2dr aP,int aK);
private :
    tCont mCont;
    int   mDim;
};


typedef std::pair<Pt2dr,Pt2dr> tPairPt;

class ElPackHomologue : public cPackNupletsHom
{
private :

    tCont::iterator  NearestIter(Pt2dr aP,bool P1 = true);


    // utilise pour parametrer l'ajustement dans FitDistPolynomiale
    // Par defaut resoud aux moindre L1, l'aspect virtuel permet
    // de definir une classe ayant exactement le meme
    // comportement
    ElMatrix<double_t> SolveSys(const  ElMatrix<double_t> &);


    void  PrivDirEpipolaire(Pt2dr & aDir1,Pt2dr & aDir2,int aNbDir) const;
    bool  mSolveInL1;

public :
    ElPackHomologue();
    void SelfSwap(); // Intervertit les  2
    void ApplyHomographies
    (const cElHomographie &H1,const cElHomographie &);

    ElCplePtsHomologues & Cple_Back();
    const ElCplePtsHomologues & Cple_Back() const;


    void Cple_Add(const ElCplePtsHomologues &);

    const ElCplePtsHomologues * Cple_Nearest(Pt2dr aP,bool P1 = true) const;
    void  Cple_RemoveNearest(Pt2dr aP,bool P1 = true) ;
    static ElPackHomologue read(ELISE_fp & aFile);

    Polynome2dReal  FitPolynome
    (
            bool aModeL2,
            int aDegre,
            double_t anAmpl,
            bool aFitX
            );

    ElDistortionPolynomiale FitDistPolynomiale
    (
            bool aL2,
            int aDegre,
            double_t anAmpl,
            double_t anEpsInv = 1e-7
            );
    void  DirEpipolaire(Pt2dr & aDir1,Pt2dr & aDir2,int WantedPts,int aNbDir,int aDegre) const;
    CpleEpipolaireCoord *  DirAndCpleEpipolaire
    (Pt2dr & aDir1,Pt2dr & aDir2,int WantedPts,int aNbDir,int aDegreFinal) const;

    ElMatrix<double_t> MatriceEssentielle(bool SysL2);

    double_t MatriceEssentielle
    (
            class cGenSysSurResol &,
            double *  Vect,
            double_t  EcartForPond
            );


    // Optimise la mise en place relative par un algo generique
    // (powel) de descente sur un critere L1
    ElRotation3D OptimiseMEPRel(const ElRotation3D & );

    // Teste la matrice essentielle et le plan et retient la meilleure
    // Par defaut fait une optimisation , pas forcement opportune
    ElRotation3D MepRelGen(double_t LongBase,bool L2,double & aD);
    ElRotation3D MepRelGenSsOpt(double_t LongBase,bool L2,double & aD);
    ElRotation3D MepRelGen(double_t LongBase,bool L2,double & aD,bool Optimize);


    // Comme dab, en entree des couple "photogrammetrique" en sortie
    // la rotation qui envoie de 1 vers 2
    ElMatrix<double_t> MepRelCocentrique(int aNbRansac,int aNbMaxPts) const;


    //   Toutes les mises en place relatives font les hypotheses suivantes
    //
    //      - points "photogrammetriques" (x,y) -> (x,y,1)
    //      - orientation 1 : identite

    // renvoie les rotation qui permet, etant donne
    // un point en coordonnee camera1, d'avoir
    // ses coordonnees en camera 2
    std::list<ElRotation3D> MepRelStd(double_t LongBase,bool L2);

    // Phys : cherche a avoir le max de couples de rayons
    // qui s'intersectent avec des Z positifs
    ElRotation3D MepRelPhysStd(double_t LongBase,bool L2);

    // Nombre de points ayant une intersection positive en Im1 et Im2
    double_t SignInters
    (
            const ElRotation3D & aRot1to2,
            int &                NbP1,
            int &                NbP2
            );

    tPairPt  PMed() const;

    // Si tous les points sont coplanaires, ou presque,
    //  la mise en place par l'algo standard est degenere,
    // on choisit donc un algo ad hoc
    cResMepRelCoplan   MepRelCoplan (double_t LongBase,bool HomEstL2);
    static cResMepRelCoplan   MepRelCoplan (double_t LongBase,cElHomographie,const tPairPt & Centre);

    // s'adapte a xml, tif , dat
    static ElPackHomologue   FromFile(const std::string &);
    ElPackHomologue   FiltreByFileMasq(const std::string &,double aVMin=0.5) const;
    // Si Post = xml -> XML; si Post = dat -> Bin; sinon erreur
    void StdPutInFile(const std::string &) const;
    void StdAddInFile(const std::string &) const;
    void Add(const ElPackHomologue &) ;

    //  Les mise en place relatives levent l'ambiguite avec un parametre
    //  de distance, souvent il est plus naturel de fixer la profondeur
    //  moyenne, c'est ce que permet de corriger cette fonction
    //
    void SetProfondeur(ElRotation3D & aR,double aProf) const;
    double Profondeur(const ElRotation3D & aR) const;
    void InvY(Pt2dr aSzIm1,Pt2dr aSzIm2);

    // Dist moy des intersections
    double AngularDistInter(const ElRotation3D & aR) const;

    void  ProfMedCam2
    (
            std::vector<double> & VProf,
            const ElRotation3D & aR
            ) const;
    // Quasi equiv a la dist inter et (?) bcp + rapide
    double QuickDistInter
    (
            const ElRotation3D & aR,
            const std::vector<double> & VProf
            ) const;

};

class StatElPackH
{
public :
    StatElPackH(const ElPackHomologue &);
    Pt2dr Cdg1 () const;
    Pt2dr Cdg2 () const;
    double_t  RMax1 () const;
    double_t  RMax2 () const;
    int   NbPts() const;
    double_t  SomD1 () const;
    double_t  SomD2 () const;
private :
    double_t  mSPds;
    int   mNbPts;
    Pt2dr mCdg1;
    Pt2dr mCdg2;
    double_t  mRMax1;
    double_t  mRMax2;
    double_t  mSomD1;
    double_t  mSomD2;
};



class ElPhotogram  // + ou - NameSpace
{
public :
    static  void bench_photogram_0();

    static Pt2dr   StdProj(Pt3dr);
    static Pt3dr   PProj(Pt2dr);


    static void ProfChampsFromDist
    (
            std::list<Pt3dr>&  res,  // liste de triplets de prof de champs
            Pt3dr p1,Pt3dr p2,Pt3dr p3, // points de projection
            double_t d12, double_t d13, double_t d23
            );
};




// Toutes les projections R3->R2 consideree  dans ElProj32
// sont des projections avec rayon perspectif droits

class ElProj32
{
public :

    // Methodes de bases a redefinir pour chaque type de projection

    virtual Pt2dr Proj(Pt3dr) const = 0;
    virtual Pt3dr DirRayon(Pt2dr) const = 0;
    virtual void  Diff(ElMatrix<double_t> &,Pt3dr) const = 0;  // differentielle


    virtual void Rayon(Pt2dr,Pt3dr &p0,Pt3dr & p1) const = 0;

    // Interfaces simplifiee
    ElMatrix<double_t> Diff(Pt3dr)const ;

    virtual ~ElProj32() {}
};

class ElProjIdentite : public ElProj32
{
public :
    Pt2dr Proj(Pt3dr) const ;
    Pt3dr DirRayon(Pt2dr) const ;
    void  Diff(ElMatrix<double_t> &,Pt3dr) const ;  // differentielle
    void Rayon(Pt2dr,Pt3dr &p0,Pt3dr & p1) const ;

    static ElProjIdentite  TheOne;
};

/* Le neologisme AFocal designe les projection qui sont quasi-stenope, cad dont le
   point nodal varie en fonction  de l'angle de visee


*/

#define NbParamAF 2



template <class Type> class  ElProjStenopeGen
{
public :
    ElProjStenopeGen(Type foc,Type cx,Type cy,const std::vector<Type> & ParamAF);

    Type & focale();
    Type   focale() const;
    Pt2d<Type> PP() const;
    void SetPP(const  Pt2d<Type> &) ;

    void Proj  (Type & x2,Type & y2,Type   x3,Type y3,Type z3) const;
    void DirRayon(Type & x3,Type & y3,Type & z3,Type x2,Type y2) const;

    void  Diff(ElMatrix<Type> &,Type,Type,Type)const ;

    const std::vector<Type>  & ParamAF() const;

    bool   UseAFocal() const;
protected :
    Type DeltaCProjDirTer(Type x3,Type y3,Type z3) const;
    Type DeltaCProjTer(Type x3,Type y3,Type z3) const;
    Type DeltaCProjIm(Type x2,Type y2) const;

    Type               _focale;
    Type               _cx;
    Type               _cy;
    bool               mUseAFocal;
    std::vector<Type>  mParamAF;
};



typedef  std::vector<double> tParamAFocal;

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

class ElDistortion22_Gen
{
public :
    virtual cCalibDistortion ToXmlStruct(const ElCamera *) const;
    void SetName(const char * aName);
    virtual std::string Type() const;
    std::string Name() const;

    static cCalibDistortion  XmlDistNoVal();
    virtual  cPreCondGrid GetAsPreCond() const;
    static ElDistortion22_Gen * AllocPreC
    (const cPreCondGrid&);


    double_t D1(const ElDistortion22_Gen &,Pt2dr P0, Pt2dr P1,int NbEch) const;
    double_t D2(const ElDistortion22_Gen &,Pt2dr P0, Pt2dr P1,int NbEch) const;
    double_t DInfini(const ElDistortion22_Gen &,Pt2dr P0, Pt2dr P1,int NbEch) const;

    virtual Pt2dr Direct(Pt2dr) const = 0 ;    //
    Pt2dr Inverse(Pt2dr) const ; //  Pour inverser :
    //    (1) On tente le OwnInverse
    //    (2) Sinon on tente le  mPolynInv
    //    (3) Sinon on applique le ComputeInvFromDirByDiff


    ElMatrix<double_t> Diff(Pt2dr) const;  // Juste interf a "Diff(ElMatrix<double_t> &,..)"
    virtual ~ElDistortion22_Gen();

    // PolynLeastSquareInverse (double_t aDom,int aDegre);

    ElDistortionPolynomiale NewPolynLeastSquareInverse
    (
            Box2dr aBox,
            int  aDegre,
            int  aNbPts = -1
            );
    Polynome2dReal  NewPolynLeastSquareInverse_OneCoord
    (
            bool XCoord,
            Box2dr aBox,
            int  aDegre,
            int  aNbPts = -1
            );
    //  aSc * Direct (aP/aSc*)
    // Def renvoit un objet contenant un pointeur sur this
    virtual ElDistortion22_Gen  * D22G_ChScale(double_t aS) const;
    virtual bool IsId() const; // Def false

    // Fonction "ad hoc" de dynamic cast, par defaut return 0, strict change pour PhgStd qui
    // ne se voit pas alors comme un cas particulier de DRad
    virtual ElDistRadiale_PolynImpair * DRADPol(bool strict = false);

    Box2dr ImageOfBox(Box2dr,int aNbPtsDisc=8 );
    Box2dr ImageRecOfBox(Box2dr,int aNbPtsDisc=8  );

    // Par defaut renvoie un objet contenant un pointeur sur this
    // et redirigeant Direct sur inverse et Lycee de Versailles
    virtual ElDistortion22_Gen * CalcInverse() const;
    void SetParamConvInvDiff(int aNbIter,double_t aEps);

    void SaveAsGrid(const std::string&,const Pt2dr& aP0,const Pt2dr& aP1,const Pt2dr& aStep);

    // Def erreur fatale
    virtual Pt2dr  DirectAndDer(Pt2dr aP,Pt2dr & aGradX,Pt2dr & aGradY) const;

    // Est-ce que les distorsion savent se transformer  en F-1 D F ou F est une translation ou
    // une homotetie
    virtual  bool  AcceptScaling() const;
    virtual  bool  AcceptTranslate() const;

    //    Soit H (X) == PP + X * F   se transforme en H-1 D H
    void SetScalingTranslate(const double & F,const Pt2dr & aPP);

    double & ScN();
    const double & ScN() const;


    // ULTRA -DANGEREUX, rajoute a contre coeur, comme moyen d'inhiber la parie
    // Tgt-Argt des fishe-eye afin qu'il puisse calcule des pseudo inverse

    void    SetDist22Gen_UsePreConditionner(bool) const;  // Tous sauf const !!
    const bool &   Dist22Gen_UsePreConditionner() const;
    Pt2dr  ComputeInvFromDirByDiff ( Pt2dr aPt, Pt2dr InvEstim0, bool DiffReestim) const;

    void    SetDist22Gen_SupressPreCondInInverse(bool) const;  // Tous sauf const !!
    const bool &   Dist22Gen_SupressPreCondInInverse() const;

protected :

    void ErrorInvert() const;
    ElDistortion22_Gen();
    void DiffByDiffFinies(ElMatrix<double_t> &,Pt2dr,Pt2dr Eps) const;
    void DiffByDiffFinies(ElMatrix<double_t> &,Pt2dr,double_t Eps) const;

private :

    virtual  void V_SetScalingTranslate(const double &,const Pt2dr &);

    double_t DistanceObjet(int tagDist,const ElDistortion22_Gen &,Pt2dr P0, Pt2dr P1,int NbEch) const;


    ElDistortionPolynomiale * mPolynInv;

    virtual void  Diff(ElMatrix<double_t> &,Pt2dr) const ;  //  differentielle
    // Def err fatale



    // Defaut 0,0 pas forcement le meilleur choix mais
    // compatibilite anterieure

public :
    virtual Pt2dr GuessInv(const Pt2dr & aP) const ;
private :
    virtual bool OwnInverse(Pt2dr &) const ;    //  return false


protected :
    double_t mEpsInvDiff;
    int  mNbIterMaxInvDiff;
private :
    double mScN;
    bool   mDist22Gen_UsePreConditionner;
    bool   mDist22Gen_SupressPreCondInInverse;
protected :
    const char * mName;
private :
};

class cXmlAffinR2ToR;

class cElComposHomographie
{
public :
    double_t operator() (const Pt2dr & aP) const
    {
        return mX*aP.x + mY*aP.y + m1;
    }
    Fonc_Num operator() (Pt2d<Fonc_Num> ) const;


    cElComposHomographie(double_t aX,double_t aY,double_t a1);
    cElComposHomographie(const cXmlAffinR2ToR &);
    cXmlAffinR2ToR ToXml() const;

    cElComposHomographie MulXY(double_t ) const;
    cElComposHomographie MulCste(double_t ) const;

    void write(class  ELISE_fp & aFile) const;
    static cElComposHomographie read(ELISE_fp & aFile);
    friend class cElHomographie;


    double_t & CoeffX();
    double_t & CoeffY();
    double_t & Coeff1();

    double_t  CoeffX() const;
    double_t  CoeffY() const;
    double_t  Coeff1() const;

    void Show(const std::string & aMes);
    bool HasNan() const;

private  :
    void SetCoHom(double_t *) const;
    void Divide (double_t);
    double_t mX;
    double_t mY;
    double_t m1;
};

class cXmlHomogr;

class cElHomographie
{
public :
    bool HasNan() const;
    Pt2dr Direct  (const Pt2dr & aP) const;
    Pt2d<Fonc_Num> Direct (Pt2d<Fonc_Num> ) const;

    void Show();
    // Renvoie H tel que H(P1) = P2
    // Size = 0 , identite
    // Size = 1 , translation
    // Size = 2 , similitude
    // Size = 3 , affinite
    // Size = 4 ou +, homographie reelle, ajuste par moindre L2  ou  L1

    cElHomographie(const ElPackHomologue &,bool aL2);
    cElHomographie(const cXmlHomogr &);
    cXmlHomogr ToXml() const;

    static cElHomographie RansacInitH(const ElPackHomologue & aPack,int aNbRansac,int aNbMaxPts);

    static cElHomographie Id();
    static cElHomographie Homotie(Pt2dr aP,double_t aSc);  // -> tr + aSc * P
    static cElHomographie FromMatrix(const ElMatrix<double_t> &);

    void ToMatrix(ElMatrix<double_t> &) const;

    cElHomographie
    (
            const cElComposHomographie &,
            const cElComposHomographie &,
            const cElComposHomographie &
            );


    cElHomographie Inverse() const;
    cElHomographie operator * (const cElHomographie &) const;
    //     P ->  aChSacle * Pol(P/aChSacle)
    cElHomographie MapingChScale(double_t aChSacle) const;
    void write(class  ELISE_fp & aFile) const;
    static cElHomographie read(ELISE_fp & aFile);

    cElComposHomographie & HX();
    cElComposHomographie & HY();
    cElComposHomographie & HZ();

    const cElComposHomographie & HX() const;
    const cElComposHomographie & HY() const;
    const cElComposHomographie & HZ() const;

    // Renvoie sa representation matricielle en coordonnees homogenes
    ElMatrix<double_t>  MatCoordHom() const;
    static cElHomographie  RobustInit(double * aQuality,const ElPackHomologue & aPack,bool & Ok ,int aNbTestEstim, double aPerc,int aNbMaxPts);

    static cElHomographie SomPondHom(const std::vector<cElHomographie> & aVH,const std::vector<double> & aVP);


private :
    cElComposHomographie mHX;
    cElComposHomographie mHY;
    cElComposHomographie mHZ;

    void AddForInverse(ElPackHomologue & aPack,Pt2dr aP) const;
    void Normalize();
};

class cDistHomographie : public  ElDistortion22_Gen
{
public :
    cDistHomographie(const ElPackHomologue &,bool aL2);
    cDistHomographie(const cElHomographie &);

    virtual bool OwnInverse(Pt2dr &) const ;    //
    virtual Pt2dr Direct(Pt2dr) const  ;    //
    cDistHomographie MapingChScale(double_t aChSacle) const;
    const cElHomographie & Hom() const;
private :

    virtual ElDistortion22_Gen  * D22G_ChScale(double_t aS) const; // Def erreur fatale
    void  Diff(ElMatrix<double_t> &,Pt2dr) const ;  //  Erreur Fatale
    cElHomographie mHDir;
    cElHomographie mHInv;
};





class ElDistortion22_Triviale : public ElDistortion22_Gen
{
public :
    void  Diff(ElMatrix<double_t> &,Pt2dr) const ;  // ** differentielle
    Pt2dr Direct(Pt2dr) const  ;     //  **
    static ElDistortion22_Triviale  TheOne;
    virtual ElDistortion22_Gen  * D22G_ChScale(double_t aS) const; // Def erreur fatale
    virtual bool IsId() const;
    virtual cCalibDistortion ToXmlStruct(const ElCamera *) const;

private :
    virtual bool OwnInverse(Pt2dr &) const ;    //  return false
};




/*
 *    ** : Methodes a redefinir imperativement si distortion non triviale.
 *
 */


class ElDistRadiale : public ElDistortion22_Gen
{
public :


    Pt2dr  & Centre();
    const Pt2dr  & Centre() const;
    virtual bool OwnInverse(Pt2dr &) const ;    //  return false
    virtual Pt2dr Direct(Pt2dr) const ;

    virtual void  Diff(ElMatrix<double_t> &,Pt2dr) const;  // differentielle

    // rho -> K0 *rho * (1 + DistDirecte(rho))
    virtual double_t K0() const; // def : return 1
    virtual double_t DistDirecte(double_t R) const = 0;
    virtual double_t DistDirecteR2(double_t R) const = 0;

    // doit renvoyer la derivee de DistDirecte, divisee par rho
    virtual double_t  DerSurRho(double_t R) const = 0; // en delta / a 1

    virtual double_t DistInverse(double_t R)  const;
    // Par defaut les distortion sont
    // supposees faibles et la fontion inverse est
    // - la fonction directe

protected  :

    ElDistRadiale(Pt2dr Centre);

private  :
    Pt2dr _centre;
};

class ElDistRadiale_PolynImpair  : public ElDistRadiale // polynome en r de degre impair
{
public :
    // Pour eviter les comportements sinuguliers
    // si R > RMax on remplace par la differentielle en RMax


    ElDistRadiale_PolynImpair(double_t RMax,Pt2dr centre);
    void ActuRMaxFromDist(Pt2di aSz);
    void ActuRMax();
    void SetRMax(double_t aV);
    virtual double_t DistDirecte(double_t) const;
    double_t DistDirecteR2NoSeuil(double_t R) const ;
    virtual double_t DistDirecteR2(double_t) const;
    virtual double_t DerSurRho(double_t) const;

    void PushCoeff(double_t); // Premiere fois fixe r3 , etc ....
    void PushCoeff(const std::vector<double_t> &); // Premiere fois fixe r3 , etc ....
    double_t & Coeff(int k);
    double_t  Coeff(int k) const;
    int NbCoeff() const;
    int NbCoeffNN() const;  // Elimine les eventuelles coefficient nul rajoutes
    void VerifCoeff(int aK) const;
    double_t   CoeffGen(int aK) const;


    ElDistRadiale_PolynImpair DistRadialeInverse(double_t RhoApp,int DeltaDeg = 1);


    // aPt -> aChSacle * Direct (aPt / aChSacle)
    ElDistRadiale_PolynImpair MapingChScale(double_t aChSacle) const;

    static ElDistRadiale_PolynImpair DistId(double_t aRMax,Pt2dr aCentre,int aDeg);

    static ElDistRadiale_PolynImpair read(ELISE_fp & aFile);
    static ElDistRadiale_PolynImpair read(const std::string &);
    void write(ELISE_fp & aFile);

    // DEBUG PURPOSE,
    double_t RMax() const;
    double_t ValRMax() const;
    double_t DiffRMax() const;
    virtual ElDistRadiale_PolynImpair * DRADPol(bool strict = false);

    ElPolynome<double_t> PolynOfR();
    // Rayon max a l'interieur duquel la fonction de
    // distortion est bijective croissante
    double_t RMaxCroissant(double_t BorneInit);

    virtual cCalibDistortion ToXmlStruct(const ElCamera *) const;
    cCalibrationInterneRadiale ToXmlDradStruct() const;

protected :
    bool  AcceptScaling() const;
    bool  AcceptTranslate() const;
    void V_SetScalingTranslate(const double &,const Pt2dr &);


private :
    std::vector<double_t> mCoeffs;  // mCoeffs[0] en r3,  mCoeffs[1] en r5 , etc ....

    double_t              mRMax;
    double_t              mRMaxP2N;
    double_t              mValRMax;
    double_t              mDiffRMax;
};

class ElDistRadiale_Pol357  : public ElDistRadiale_PolynImpair // polynome en r de degre 3,5,7
{
public :
    ElDistRadiale_Pol357(double_t aRMax,Pt2dr centre,double_t  c3,double_t c5,double_t c7);

private  :
};


// Implemante des deformations du type "D-1 o H o D" avec
// D disrortion radiale polynomiale et H homographie

class cDistHomographieRadiale : public ElDistortion22_Gen
{
public :
    cDistHomographieRadiale
    (
            const cElHomographie & anHom,
            const ElDistRadiale_PolynImpair & aDRad,
            double_t aRayInv,
            int  aDeltaDegraInv
            );
    virtual bool OwnInverse(Pt2dr &) const ;    //
    virtual Pt2dr Direct(Pt2dr) const  ;    //
    // aPt -> aChSacle * Direct (aPt / aChSacle)
    cDistHomographieRadiale MapingChScale(double_t aChSacle) const;
private:
    virtual ElDistortion22_Gen  * D22G_ChScale(double_t aS) const; // Def erreur fatale
    void  Diff(ElMatrix<double_t> &,Pt2dr) const ;  //  Erreur Fatale
    cElHomographie            mHom;
    cElHomographie            mHomInv;
    ElDistRadiale_PolynImpair mDist;
    ElDistRadiale_PolynImpair mDistInv;
    double_t                      mRay;
    int                       mDeg;
};



// Classe de distortion par polynome de degre 2, Pas un interet fou
// (elle sont un peu + rapide que si definies par polynomes generiques)
// mais developpee pour tester rapidement certaine fonctionnalites
// generiques
//

class PolyDegre2XY
{
public :
    PolyDegre2XY (double_t a,double_t aX,double_t aY,double_t aXX,double_t aXY,double_t aYY);

    double_t Val(Pt2dr aPt) const;
    Pt2dr Grad(Pt2dr aPt) const;

    double_t & Coeff() {return m;}
    double_t & CoeffX() {return mX;}
    double_t & CoeffY() {return mY;}
private :
    double_t m;
    double_t mX;
    double_t mY;
    double_t mXX;
    double_t mXY;
    double_t mYY;

};


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


class ElDistortionPolynomiale : public ElDistortion22_Gen
{
    // Pour les inverses et autres, on fait l'hypothese
    // que les coeff, hors degres <=1, ont des valeur
    // tres faible

public :
    static ElDistortionPolynomiale DistId(int aDegre,double anAmpl);
    ElDistortionPolynomiale
    (
            const Polynome2dReal & aDistX,
            const Polynome2dReal & aDistY,
            double_t                   anEpsilonInv = 1e-7
            );
    virtual Pt2dr Direct(Pt2dr) const ;  // **

    const Polynome2dReal & DistX() const ;
    const Polynome2dReal & DistY() const ;
    Fonc_Num FNum() const ;

    ElDistortionPolynomiale (double_t anAmpl,double_t anEpsilonInv = 1e-7) ;

    // par defaut appel au fonctions "Quick" (ou Quasi)

    virtual void  Diff(ElMatrix<double_t> &,Pt2dr) const;  // ** differentielle

    // aPt -> aChSacle * Direct (aPt / aChSacle)
    ElDistortionPolynomiale MapingChScale(double_t aChSacle) const;
    virtual ElDistortion22_Gen  * D22G_ChScale(double_t aS) const; // Def erreur fatale

private :
    Polynome2dReal mDistX;
    Polynome2dReal mDistY;
    double_t           mEpsilon;
};

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

class EpipolaireCoordinateNoDist : public EpipolaireCoordinate
{
public :
    EpipolaireCoordinateNoDist
    (
            Pt2dr aP0,
            Pt2dr aDirX
            );
private :
    virtual Pt2dr ToCoordEpipol(Pt2dr aPInit) const ;
    virtual Pt2dr ToCoordInit(Pt2dr aPEpi) const ;
    virtual EpipolaireCoordinate *
    MapingChScale(double_t aChSacle) const;
};

class cMappingEpipCoord : public EpipolaireCoordinate
{
public :
    cMappingEpipCoord(ElDistortion22_Gen *,bool toDel);
    ~cMappingEpipCoord();
private :
    virtual bool IsEpipId() const;
    EpipolaireCoordinate * MapingChScale(double_t aChSacle) const;
    Pt2dr ToCoordEpipol(Pt2dr aPInit) const ;
    Pt2dr ToCoordInit(Pt2dr aPEpi) const ;

    ElDistortion22_Gen * mDist;
    bool                 mToDel;
};


class PolynomialEpipolaireCoordinate : public EpipolaireCoordinate
{
public :


    PolynomialEpipolaireCoordinate
    (
            Pt2dr aP0,
            Pt2dr aDirX,
            const Polynome2dReal & aPolY,
            double_t                   anAmpl,
            int                    DeltaDegreInv = 2,
            Pt2dr                  aTrFin = Pt2dr(0,0)
            );


    Polynome2dReal  PolToYEpip();
    Polynome2dReal  PolToYInit();

    virtual  const PolynomialEpipolaireCoordinate * CastToPol() const;
    void write(class  ELISE_fp & aFile) const;
    static PolynomialEpipolaireCoordinate read(ELISE_fp & aFile);
    //     P ->  aChSacle * Pol(P/aChSacle)
    EpipolaireCoordinate * MapingChScale(double_t aChSacle) const;
    PolynomialEpipolaireCoordinate * PolMapingChScale(double_t aChSacle) const;

private :

    int DeltaDegre() const;
    double_t AmplInv() const;

    Polynome2dReal  mPolToYEpip;
    Polynome2dReal  mPolToYInit;

    Pt2dr ToCoordEpipol(Pt2dr aPInit) const;
    Pt2dr ToCoordInit(Pt2dr aPEpi) const;
};


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


typedef enum
{
    eProjectionStenope,
    eProjectionOrtho
} eTypeProj;


class cCorrRefracAPost
{
public :
    Pt2dr CorrM2C(const Pt2dr &) const;
    Pt2dr CorrC2M(const Pt2dr &) const;
    cCorrRefracAPost(const cCorrectionRefractionAPosteriori &);

    // Le coefficient est le ratio du coeef de refrac du milieu d'entree sur le milieu de sortie
    Pt3dr CorrectRefrac(const Pt3dr &,double aCoef) const;

    const cCorrectionRefractionAPosteriori & ToXML() const;
private :

    cCorrectionRefractionAPosteriori * mXML;
    ElCamera *  mCamEstim;
    double      mCoeffRefrac;
    bool       mIntegDist;
};


//  Classe qui permet de manipuler de manière via une interface uniforme une image,
// ou un nuage de point
class cCapture3D
{
public :
    virtual Pt2dr    Ter2Capteur   (const Pt3dr & aP) const =0;
    virtual bool     PIsVisibleInImage   (const Pt3dr & aP) const =0;
    virtual ElSeg3D  Capteur2RayTer(const Pt2dr & aP) const =0;

    virtual bool  HasRoughCapteur2Terrain() const = 0;
    virtual bool  HasPreciseCapteur2Terrain() const = 0;
    virtual Pt3dr RoughCapteur2Terrain   (const Pt2dr & aP) const =0;
    virtual Pt3dr PreciseCapteur2Terrain   (const Pt2dr & aP) const =0;

    virtual double ResolSolOfPt(const Pt3dr &) const = 0;
    virtual double ResolSolGlob() const = 0;
    virtual bool  CaptHasData(const Pt2dr &) const = 0;

    virtual Pt2dr ImRef2Capteur   (const Pt2dr & aP) const =0;
    virtual double ResolImRefFromCapteur() const =0;
};



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

    double_t EcartProj(Pt2dr aPF2A,const ElCamera & CamB,Pt2dr aPF2B) const;

    double_t EcartProj(Pt2dr aPF2A,Pt3dr aPR3,Pt3dr aDirR3) const;


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
    double_t EcProj(const std::list<Pt3dr> & PR3 ,
                const std::list<Pt2dr> & PF2) const;

    double_t EcProj ( const std::list<Appar23> & P23);

    // Differentielle de l'application globale
    // par rapport a un point
    void  DiffR3F2(ElMatrix<double_t> &,Pt3dr) const;
    ElMatrix<double_t>  DiffR3F2(Pt3dr) const;
    // par rapport aux params
    void  DiffR3F2Param(ElMatrix<double_t> &,Pt3dr) const;
    ElMatrix<double_t>  DiffR3F2Param(Pt3dr) const;

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


// Represente les cameras a projection parallele (focale infinie),
//
//  La focale et le point principal sont indissociables de la translation,
//  ce sont des parametres extrinseques representes dans la translation
//  (via le R3toL3/L3toR3)

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

// Preconditionnement en arc-tangente, adapte a un fish eye conservant
// les angles.
//
class cDistPrecondRadial : public ElDistortion22_Gen
{
public :
    cDistPrecondRadial(double aFocApriori,const Pt2dr & aCentre);
    cPreCondGrid GetAsPreCond() const;
    Pt2dr  DirectAndDer(Pt2dr aP,Pt2dr & aGradX,Pt2dr & aGradY) const;

private :

    virtual double  DerMultDirect(const double & ) const = 0;
    virtual double  MultDirect(const double & ) const = 0;
    virtual double  MultInverse(const double & ) const = 0;
    virtual int     Mode() const = 0;

    Pt2dr Direct(Pt2dr) const;    // -> DistDirect() = M2C
    bool OwnInverse(Pt2dr &) const ;

    double  mF;
    Pt2dr   mC;
};


// Modele pour fish eye lineaire

class cDistPrecondAtgt : public cDistPrecondRadial
{
public :
    cDistPrecondAtgt(double aFocApriori,const Pt2dr & aCentre);
private :
    double  DerMultDirect(const double & ) const ;
    double  MultDirect(const double & ) const ;
    double  MultInverse(const double & ) const ;
    int     Mode() const ;
};

// Modele pour fish eye equisolid

class cDistPrecond2SinAtgtS2 : public cDistPrecondRadial
{
public :
    cDistPrecond2SinAtgtS2(double aFocApriori,const Pt2dr & aCentre);
private :
    double  DerMultDirect(const double & ) const ;
    double  MultDirect(const double & ) const ;
    double  MultInverse(const double & ) const ;
    int     Mode() const ;
};


class cElDistFromCam : public ElDistortion22_Gen
{
public :
    cElDistFromCam(const ElCamera &,bool UseRayUtile);
    Pt2dr Direct(Pt2dr) const;    // -> DistDirect() = M2C
    bool OwnInverse(Pt2dr &) const ;
    const ElCamera & mCam;
    void  Diff(ElMatrix<double_t> & aMat,Pt2dr aP) const;

private :
    bool mUseRay;
    Pt2dr  mSzC;
    Pt2dr  mMil;
    double mRayU;
};


// Donne une mesure en pixel (non distordu) de l'ecart d'appariement
double_t EcartTotalProjection
(
        const ElCamera & CamA,Pt2dr aPF2A,
        const ElCamera & CamB,Pt2dr aPF2B
        );

/*
Pt3dr IntersectionRayonPerspectif
      (
             const ElCamera & CamA, Pt2dr PF2A,
             const ElCamera & CamB, Pt2dr PF2B
       );
      A FAIRE
*/

// Camera a Stenope

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





//
// Soit une camera et l'application D du plan dans le
// plan telle que pour un point P=(U,V) camera,
//  R=(D(U),D(V),1.0) soit la direction issu de P,
//  cDistStdFromCam permet de representer cette application
//  sous forme d'une ElDistortion22_Gen, ce qui peut etre utile
//  par exemple pour generer des grilles;
//  l'Inversion n'est pas tres rapide car elle calcule des
//  derivees par differences finies.

class cDistStdFromCam : public ElDistortion22_Gen
{
public :
    cDistStdFromCam(ElCamera & Cam);
    Pt2dr Direct(Pt2dr) const ;
    void  Diff(ElMatrix<double_t> &,Pt2dr) const;

private :
    ElCamera & mCam;
};



// Classe pour presenter une image Orilib comme une
// camera Elise

class cDistorsionOrilib;
class cCamera_Orilib : public CamStenope
{
public :
    cCamera_Orilib(Data_Ori3D_Std *);
private :
    Ori3D_Std * CastOliLib();  // Def return 0

    Ori3D_Std                       mOri;
    cDistorsionOrilib             * mDist;
    virtual ElDistortion22_Gen   &  Dist();
    virtual const ElDistortion22_Gen   &  Dist() const;
};


// Camera a Stenope Ideale

class CamStenopeIdeale : public CamStenope
{
public :
    CamStenopeIdeale (bool isDistC2M,double_t Focale,Pt2dr Centre,const std::vector<double> & ParamAF);
    CamStenopeIdeale(const CamStenopeIdeale &,const ElRotation3D &);
    static CamStenopeIdeale  CameraId(bool isDistC2M,const ElRotation3D &);
    CamStenopeIdeale(const CamStenopeIdeale &);

private :
    virtual ElDistortion22_Gen   &  Dist();
    virtual const ElDistortion22_Gen   &  Dist() const;
};


//  Permet de dupliquer une camera, sans copier les distorsion
//  sans connaitre son origine

class cCamStenopeGen : public CamStenope
{
public :
    cCamStenopeGen(CamStenope &);
private :
};



class cCamStenopeDistRadPol : public CamStenope
{
public :
    const cCamStenopeDistRadPol * Debug_CSDRP() const;

    cCamStenopeDistRadPol
    (
            bool isDistC2M,
            double_t Focale,
            Pt2dr Centre,
            ElDistRadiale_PolynImpair,
            const std::vector<double> & ParamAF,
            ElDistRadiale_PolynImpair * RefDist  = 0,
            const Pt2di &  aSz = ElCamera::TheSzUndef
            );

    ElDistRadiale_PolynImpair & DRad();
    const ElDistRadiale_PolynImpair & DRad() const;

    void write(class  ELISE_fp & aFile) ;
    void write(const std::string & aName);
    static cCamStenopeDistRadPol * read_new(ELISE_fp & aFile);
    static cCamStenopeDistRadPol * read_new(const std::string &);

    virtual cParamIntrinsequeFormel * AllocParamInc(bool isDC2M,cSetEqFormelles &);
    cParamIFDistRadiale * AllocDRadInc(bool isDC2M,cSetEqFormelles &);
private :
    ElDistRadiale_PolynImpair & mDist;
    ElDistRadiale_PolynImpair mDistInterne;
    // Non implemente , pb sur la copie de _dist
    // (reference mal initialisee)
    //   Surtout avec mDist != mDistInterne
    cCamStenopeDistRadPol(const cCamStenopeDistRadPol &);

    virtual ElDistortion22_Gen   &  Dist();
    virtual const ElDistortion22_Gen   &  Dist() const;
};




// Classe pour modeliser ma distortion telle que
// decrite dans Fraser, ISPRS 97, Vol 52, 149-159
//



class cDistModStdPhpgr : public ElDistRadiale_PolynImpair
{
public :
    cDistModStdPhpgr(const ElDistRadiale_PolynImpair &);

    Pt2dr Direct(Pt2dr) const ;
    void  Diff(ElMatrix<double_t> &,Pt2dr) const;
    virtual bool OwnInverse(Pt2dr &) const ;    //  Pour "casser" la valeur radiale
    virtual Pt2dr GuessInv(const Pt2dr & aP) const ;

    double_t & P1();
    double_t & P2();
    double_t & b1();
    double_t & b2();
    ElDistRadiale_PolynImpair & DRad();
    const ElDistRadiale_PolynImpair & DRad() const;
    virtual ElDistRadiale_PolynImpair * DRADPol(bool strict = false);

    virtual cCalibDistortion ToXmlStruct(const ElCamera *) const;
    cCalibrationInternePghrStd ToXmlPhgrStdStruct() const;
private  :
    bool  AcceptScaling() const;
    bool  AcceptTranslate() const;
    void V_SetScalingTranslate(const double &,const Pt2dr &);
    // ElDistRadiale_PolynImpair mDRad;
    double mP1;
    double mP2;
    double mb1;
    double mb2;

};
//   /*Par defaut fonctionne en inverse (ie Cam -> Monde)

class cCamStenopeModStdPhpgr : public cCamStenopeDistRadPol
{
public :
    cCamStenopeModStdPhpgr
    (
            bool DistIsC2M, // [1]
            double_t Focale,
            Pt2dr Centre,
            cDistModStdPhpgr,
            const std::vector<double> & ParamAF
            );
    cDistModStdPhpgr & DModPhgrStd();
    const cDistModStdPhpgr & DModPhgrStd() const;
    // [1]  DistIsC2M:
    // En point de liaison les equation sont faite C->M, compte
    // tenu de l'absence d'inversion triviale pour le Modele Std,
    // on a interet a toujours raisonner dans ce sens
    virtual ElDistortion22_Gen   &  Dist();
    virtual const ElDistortion22_Gen   &  Dist() const;
    virtual cParamIntrinsequeFormel * AllocParamInc(bool isDC2M,cSetEqFormelles &);
    cParamIFDistStdPhgr * AllocPhgrStdInc(bool isDC2M,cSetEqFormelles &);
private :
    cCamStenopeModStdPhpgr(const cCamStenopeModStdPhpgr &); // N.I.
    cDistModStdPhpgr mDist;
};






class cCamStenopeDistPolyn : public CamStenope
{
public :
    cCamStenopeDistPolyn
    (bool isDistC2M,double_t Focale,Pt2dr Centre, const ElDistortionPolynomiale &,const std::vector<double> &);
    const ElDistortionPolynomiale & DistPol() const;
private :
    ElDistortionPolynomiale mDist;
    cCamStenopeDistPolyn(const cCamStenopeDistPolyn &);
    virtual ElDistortion22_Gen   &  Dist();
    virtual const ElDistortion22_Gen   &  Dist() const;
};

class cCamStenopeDistHomogr : public CamStenope
{
public :
    cCamStenopeDistHomogr
    (bool isDistC2M,double_t Focale,Pt2dr Centre, const cDistHomographie &,const std::vector<double> &);
    const cElHomographie & Hom() const;
private :
    cDistHomographie   mDist;
    cCamStenopeDistHomogr(const cCamStenopeDistHomogr &);
    virtual ElDistortion22_Gen   &  Dist();
    virtual const ElDistortion22_Gen   &  Dist() const;
};


class cDistCamStenopeGrid : public ElDistortion22_Gen
{
public :
    friend class cCamStenopeGrid;
    Pt2dr DirectAndDer(Pt2dr aP,Pt2dr & aGX, Pt2dr & aGY) const;
    Pt2dr Direct(Pt2dr) const;
    virtual bool OwnInverse(Pt2dr &) const ;    //  return true

    // Si RayonInv <=0 pas utilise
    static cDistCamStenopeGrid * Alloc(double aRayInv,const CamStenope &,Pt2dr aStepGr,bool doDir=true,bool doInv=true);

    cDistCamStenopeGrid
    (
            ElDistortion22_Gen *,
            cDbleGrid *
            );

    static void Test(double aRayInv,const CamStenope &,Pt2dr aStepGr);

    virtual cCalibDistortion ToXmlStruct(const ElCamera *) const;

    std::string Type() const;
private :
    cDistCamStenopeGrid(const cDistCamStenopeGrid &); // N.I.


    ElDistortion22_Gen * mPreC;  // Pre Conditionnement optionnel
    cDbleGrid  *         mGrid;
};


class cCamStenopeGrid :  public CamStenope
{
public :
    static cCamStenopeGrid * Alloc(double aRayonInv,const CamStenope &,Pt2dr aStepGr,bool doDir=true,bool doInv=true);
    cCamStenopeGrid
    (
            const double & aFoc,
            const Pt2dr &,
            cDistCamStenopeGrid *,
            const Pt2di  & aSz,
            const std::vector<double> & ParamAF
            );

    Pt2dr L2toF2AndDer(Pt2dr aP,Pt2dr & aGX,Pt2dr & aGY);
private :
    bool IsGrid() const;
    ElDistortion22_Gen   *  DistPreCond() const;

    cCamStenopeGrid(const cCamStenopeGrid &); // N.I.
    cDistCamStenopeGrid * mDGrid;
};



class CalcPtsInteret
{
public :

    typedef std::list<Pt2dr>  tContainerPtsInt;


    static Fonc_Num CritereFonc(Fonc_Num);  // Typiquement une genre Harris
    static Pt2di GetOnePtsInteret(Flux_Pts,Fonc_Num aFonc); // aFonc -> Avant appli de critere


    // Dans cette version, on specifie la taille des carres
    // de recherche de 1 Pts Interet

    static tContainerPtsInt GetEnsPtsInteret_Size
    (
            Pt2di aP0,
            Pt2di aP1,
            Fonc_Num aFonc,
            double_t aSize,
            double_t aRatio = 0.8
            );

    static tContainerPtsInt GetEnsPtsInteret_Nb
    (
            Pt2di aP0,
            Pt2di aP1,
            Fonc_Num aFonc,
            int  aNb,  // NbTot = NbX * NbY
            double_t aRatio = 0.8
            );

    static tContainerPtsInt GetEnsPtsInteret_Size
    (
            Im2D_U_int1,
            double_t aSize,
            double_t aRatio = 0.8
            );
    static tContainerPtsInt GetEnsPtsInteret_Nb
    (
            Im2D_U_int1,
            int  aNb,
            double_t aRatio = 0.8
            );

private :

};


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




class cElemMepRelCoplan
{
public :
    cElemMepRelCoplan
    (
            const cElHomographie &,
            const ElRotation3D &
            );

    cElemMepRelCoplan ToGivenProf(double aProProf);


    bool PhysOk() const;
    void Show() const;
    double_t AngTot() const;
    double_t Ang1() const;
    double_t Ang2() const;
    const ElRotation3D & Rot() const;

    double TestSol() const;
    void TestPack(const ElPackHomologue &) const;


    // Normale au plan dans le repere cam1
    Pt3dr          Norm() const;
    //  Distance entre le centre optique et l'image "reciproque"
    //  du centre camera 1 sur le plan, permet de normalisee
    //  les bases
    double_t DPlan() const;


    // "Vraie" distance min entre le plan et
    double DistanceEuclid() const;

    // Idem camera2
    double_t DPlan2() ;
    // Point du plan, ayant P1 comme image  par cam1
    // (en coord camera 1)
    Pt3dr ImCam1(Pt2dr aP1);
    // Homographie envoyant un (u,v,1) en (X,Y,0)
    cElHomographie HomCam2Plan(double * aResidu = 0);

    cElPlan3D  Plan() const;
    const Pt3dr & P0() const;
    const Pt3dr & P1() const;
    const Pt3dr & P2() const;

    // Des coordoones Cam2 a Cam1

    Pt3dr ToR1(Pt3dr aP2) const;

private :

    // Point du plan, ayant P2 comme image  par cam2
    // (en coord camera 1)
    Pt3dr ImCam2(Pt2dr aP2);

    double_t AngleNormale(Pt3dr);


    cElHomographie mHom;
    cElHomographie mHomI;
    ElRotation3D   mRot;

    // tous les points 3D sont en coordonnees Cam1

    // mP0,mP1,mP2  trois point (coord Cam1) du plan
    // mNorm un vecteur unitaire  de la normale au plan
    Pt3dr          mP0;
    Pt3dr          mP1;
    Pt3dr          mP2;
    Pt3dr          mNorm;
    Pt2dr          mCZCC2; // Centre Zone Commune
    Pt2dr          mCZCC1;
    Pt3dr          mCZCMur;
    Pt3dr          mCOptC1;
    Pt3dr          mCOptC2;
    double_t           mProfC1;
    double_t           mProfC2;
    double_t           mAng1;
    double_t           mAng2;
    double_t           mAngTot;
    double         mDEuclidP;
};

class cResMepRelCoplan
{
public :
    cResMepRelCoplan();
    cElemMepRelCoplan & BestSol();
    void AddSol(const cElemMepRelCoplan &);
    const std::list<ElRotation3D> &  LRot() const;
    const std::vector<cElemMepRelCoplan> & VElOk() const;
private :
    std::list<cElemMepRelCoplan>    mLElem;
    std::vector<cElemMepRelCoplan>  mVElOk;
    std::list<ElRotation3D>         mLRot;
};

//  -----------------------------------------------
//
//      POLYGONE D'ETALONNAGE
//
//  -----------------------------------------------


class cMirePolygonEtal
{
public :
    bool IsNegatif() const;
    cMirePolygonEtal();
    static const cMirePolygonEtal & IgnMireN6();
    static const cMirePolygonEtal & MtdMire9();
    static const cMirePolygonEtal & IGNMire7();
    static const cMirePolygonEtal & IGNMire5();
    static const cMirePolygonEtal & SofianeMire3();
    static const cMirePolygonEtal & SofianeMire2();
    static const cMirePolygonEtal & SofianeMireR5();
    static const cMirePolygonEtal & MT0();
    static const cMirePolygonEtal & MTClous1();
    static const cMirePolygonEtal & GetFromName(const std::string &);
    int NbDiam() const;
    double_t KthDiam(int aK) const;
    const std::string & Name() const;


private :

    static const double TheIgnN6[6];
    static const double TheMTD9[6];
    static const double TheIGNDiams7[7];
    static const double TheIGNDiams5[5];
    static const double TheSofianeDiam3[1];
    static const double TheSofianeDiam2[1];
    static const double TheSofianeDiamR5[5];
    static const double TheMT0Diams[1];
    static const double TheDiamMTClous1[1];

    static cMirePolygonEtal TheNewIGN6;
    static cMirePolygonEtal TheMTDMire9;
    static cMirePolygonEtal TheIGNMire7;
    static cMirePolygonEtal TheIGNMire5;
    static cMirePolygonEtal TheSofiane3;
    static cMirePolygonEtal TheSofiane2;
    static cMirePolygonEtal TheSofianeR5;
    static cMirePolygonEtal TheMT0;
    static cMirePolygonEtal TheMTClous1;

    cMirePolygonEtal(const std::string & mName,const double *,int NB);

    std::string  mName;
    const double *     mDiams;
    int          mNBDiam;
};


// La classe cCibleCalib est la nouvelle "classe" pour representer les
// cibles, elle est plus complete (normale ...) et admet une lecture
// ecriture standard par xml. Pour des raisons de compatibilite on
// conserve cCiblePolygoneEtal qui contient un cCibleCalib *. C'est
// un peu batard mais correspond au moyen le + econome de gerer
//  cette classe qui n'a pas vocation a generer de grand developpement


class cCibleCalib;
class cPolygoneCalib;
class cComplParamEtalPoly;

class cCiblePolygoneEtal
{
public :
    typedef int tInd;
    typedef enum
    {
        ePerfect = 0,
        eBeurk   = 1
    } tQualCible;


    void SetPos(Pt3dr aP );
    Pt3dr Pos() const;
    tInd Ind() const;
    const cMirePolygonEtal &  Mire() const;
    tQualCible Qual() const;

    cCiblePolygoneEtal
    (
            tInd,Pt3dr,const cMirePolygonEtal &,int Qual,
            cCibleCalib *,
            int anOrder
            );
    cCiblePolygoneEtal();

    cCibleCalib * CC() const;
    int Order() const;

private :
    tInd                     mInd;
    Pt3dr                    mPos;
    const cMirePolygonEtal * mMire;
    tQualCible               mQual;
    cCibleCalib *            mCC;
    int                      mOrder;
};

class cPolygoneEtal
{
public :
    virtual void AddCible(const cCiblePolygoneEtal &) =0;
    virtual const cCiblePolygoneEtal & Cible(cCiblePolygoneEtal::tInd) const = 0;
    virtual ~cPolygoneEtal();
    static cPolygoneEtal * IGN();
    static cPolygoneEtal * FromName
    (
            const std::string &,
            const cComplParamEtalPoly * aParam
            );

    typedef std::list<const cCiblePolygoneEtal *>  tContCible;

    const  tContCible  & ListeCible() const;
    cPolygoneCalib * PC() const;
    void SetPC(cPolygoneCalib *);
protected :
    void LocAddCible(const cCiblePolygoneEtal *);
    cPolygoneEtal();
    void PostProcess();
private :
    tContCible mListeCible;
    cPolygoneCalib * mPC;
};


class cPointeEtalonage
{
public :
    cPointeEtalonage(cCiblePolygoneEtal::tInd,Pt2dr,const cPolygoneEtal &);
    Pt2dr PosIm() const;
    Pt3dr PosTer() const;
    void SetPosIm(Pt2dr);
    const cCiblePolygoneEtal  & Cible() const;
    bool  UseIt () const;
    double_t  Pds()    const;
private :

    Pt2dr                       mPos;
    const cCiblePolygoneEtal *  mCible;
    bool                        mUseIt;
    double_t                        mPds;

};


class cSetNImSetPointes;
class cSetPointes1Im
{
public :
    friend class cSetNImSetPointes;
    cSetPointes1Im
    (
            const cPolygoneEtal &,
            const std::string &,
            bool  SVP = false  // Si true et fichier inexistant cree set vide
            );
    typedef std::list<cPointeEtalonage> tCont;
    tCont  & Pointes() ;
    cPointeEtalonage & PointeOfId(cCiblePolygoneEtal::tInd);
    cPointeEtalonage * PointeOfIdSvp(cCiblePolygoneEtal::tInd);
    void RemoveCibles(const std::vector<int> & IndToRemove);
    bool  InitFromFile(const cPolygoneEtal &,ELISE_fp & aFp,bool InPK1);
private :
    tCont mPointes;
    cSetPointes1Im();
};

class cSetNImSetPointes
{
public :
    cSetNImSetPointes
    (
            const cPolygoneEtal &,
            const std::string &,
            bool  SVP = false  // Si true et fichier inexistant cree set vide
            );
    typedef std::list<cSetPointes1Im> tCont;
    tCont  & Pointes() ;
    int NbPointes();
private :
    tCont mLPointes;

};

class cDbleGrid : public ElDistortion22_Gen
{
public :

    // Dans le cas ou il s'agit d'une grille photogram
    // le PP est l'image reciproque de (0,0),
    // la Focale est calculee par differnce finie,
    // en X, avec un pas de 1 Pixel
    double_t Focale();
    Pt2dr PP() ;
    const Pt2dr & P0_Dir() const;
    const Pt2dr & P1_Dir() const;
    const Pt2dr  & Step_Dir() const;

    static cDbleGrid *  StdGridPhotogram(const std::string & aName,int aSzDisc=30);



    cDbleGrid
    (
            bool AdaptStep,
            Pt2dr aP0,Pt2dr aP1,
            Pt2dr               aStep,
            ElDistortion22_Gen &,
            const std::string & aName = "DbleGrid",
            bool  doDir = true,
            bool  doInv = true
            );
    const std::string & Name() const;

    static cDbleGrid * read(const  std::string &);
    static cDbleGrid * read(ELISE_fp & aFile);

    void write(const  std::string &);
    void write(ELISE_fp & aFile);
    ~cDbleGrid();
    Pt2dr ValueAndDer(Pt2dr aRealP,Pt2dr & aGradX,Pt2dr & aGradY);
    virtual Pt2dr Direct(Pt2dr) const  ;    //
    const PtImGrid & GrDir() const ;
    const PtImGrid & GrInv() const ;
    PtImGrid & GrDir() ;
    PtImGrid & GrInv() ;

    // Applique un chgt d'echelle sur les image direct
    // typiquement si ChScale=Focale() Tr= PP() ; alors
    // on une correction de distorsion assez classique
    void SetTrChScaleDir(double_t aChScale,Pt2dr aTr);
    void SetTrChScaleInv(double_t aChScale,Pt2dr aTr);

    class cXMLMode {
    public :
        cXMLMode(bool toSwapDirInv = false);
        bool    toSwapDirInv;
    };
    cDbleGrid(cXMLMode,const std::string & aDir,const std::string & aXML);


    cDbleGrid(const cGridDirecteEtInverse &);

    void PutXMWithData
    (
            class cElXMLFileIn &       aFileXML,
            const std::string &  aNameDir
            );
    bool StepAdapted() const;

    // Nouveau format avec Image incluse
    void SaveXML(const std::string &);


private :

    void SauvDataGrid
    (
            const std::string &  aNameDir,
            Im2D_double_t8 anIm,
            const std::string & aName
            );

    virtual bool OwnInverse(Pt2dr &) const ;    //  return true
    virtual void  Diff(ElMatrix<double_t> &,Pt2dr) const ;  //  differentielle
    cDbleGrid(PtImGrid*,PtImGrid*);



    PtImGrid * pGrDir;
    PtImGrid * pGrInv;
    std::string mName;
};


class cEqTrianguApparImage
{
    typedef double_t tV6[6];
public :
    // Ordre des variables A.x A.y B.x etc ....
    cEqTrianguApparImage(int aCapa);
    ~cEqTrianguApparImage();
    void Reset();
    void Close();
    void Add
    (
            double_t aI,
            double_t aJ, double_t aDxJ, double_t aDyJ,
            double_t aPdsA, double_t aPdsB, double_t aPdsC
            );

    void SetDer(double_t & aCste,double_t  * aDer,int aK);

private :
    int  mCapa;
    int  mN;     // Nombre de point
    double_t mSI1;   // Moyenne/Somme de l'image I
    double_t mSI2;   // Moyenne/Somme du carre l'image I
    double_t   mSigmaI;
    double_t mSJ1;   // Moyenne/Somme de l'image J
    double_t mSJ2;   // Moyenne/Somme du carre de l'image J
    double_t   mSigmaJ2;
    double_t   mSigmaJ;
    double_t   mSigmaJ3;


    tV6   mDerSJ1;     // Derivee de SJ1 / a A.x A.y B.x etc ..
    tV6   mDerSJ2;     // Derivee de SJ2 / a A.x A.y B.x etc ..
    tV6   mDerSigmaJ2; // Derivee SigmaJ2 = mSJ2 - Square(mSJ1)
    tV6 * mDerJk;      // mDerJk[k][0] derivee de kieme J / a A.x

    double_t * mVI;
    double_t * mVJ;
};



ElRotation3D RotationCart2RTL(Pt3dr  aP, double aZ);
ElRotation3D RotationCart2RTL(Pt3dr  aP, double aZ,Pt3dr axe_des_x);



class cAnalyseZoneLiaison
{
public :
    cAnalyseZoneLiaison();
    void AddPt(const Pt2dr &);
    void Reset();

    //  2 - 1 correpond a l'inertie du petit axe
    //  1 -1  correpond a la moyenne des val abs (dans le ptit axe)
    //  2 -0   correpond a l'inertie du petit axe avec une ponderation
    //         normalisee independante du nombre de points
    double Score(double ExposantDist,double ExposantPds);
    const std::vector<Pt2dr> & VPts() const;
private  :
    cAnalyseZoneLiaison(const cAnalyseZoneLiaison&);
    std::vector<Pt2dr>  mVPts;
    RMat_Inertie        mMat;
};


class   cCS_MapIm2PlanProj : public ElDistortion22_Gen
{
public :
    cCS_MapIm2PlanProj(CamStenope * pCam) ;
    // Directe Image -> Direction de rayon

    Pt2dr Direct(Pt2dr aP) const;
private :
    bool OwnInverse(Pt2dr & aP) const;
    void  Diff(ElMatrix<double_t> &,Pt2dr) const;

    CamStenope & mCam;
};

std::string LocPxFileMatch(const std::string & aDir,int aNum,int aDeZoom);
std::string LocMasqFileMatch(const std::string & aDirM,int aNum);


class cCpleEpip
{
public :
    cCpleEpip
    (
            const std::string & aDir,
            double aScale,
            const CamStenope & aC1,const std::string & aName1,
            const CamStenope & aC2,const std::string & aName2,
            const std::string & PrefLeft =   "Left_",
            const std::string & PrefRight =  "Right_"
            );
    Pt2dr RatioExp() const;
    double RatioCam() const;
    const bool & Ok() const;
    const int & SzX() const;
    const int & SzY() const;

    double BSurHOfPx(bool Im1,double aPx);
    Fonc_Num BSurHOfPx(bool Im1,Fonc_Num aPx);

    std::string Dir();

    bool IsIm1(const std::string & aNameIm);  // Erreur si ni Im1 ni Im2


    std::string LocDirMatch(const std::string & Im);
    std::string LocNameImEpi(const std::string & Im,int aDeZoom=1,bool Pyram = true);
    std::string LocPxFileMatch(const std::string & Im,int aNum,int aDeZoom);
    std::string LocMasqFileMatch(const std::string & Im,int aNum);


    std::string LocDirMatch(bool Im1);
    std::string LocNameImEpi(bool Im1,int aDeZoom=1,bool Pyram=true);
    std::string LocPxFileMatch(bool Im1,int aNum,int aDeZoom);
    std::string LocMasqFileMatch(bool Im1,int aNum);



    bool IsLeft(bool Im1);
    bool IsLeft(const std::string &);


    void ImEpip(Tiff_Im aFile,const std::string & aNameOriIn,bool Im1,bool InParal=true,bool DoIm=true,const char * NameHom= 0,int aDegPloCor=-1);
    void AssertOk() const;

    void LockMess(const std::string & aMes);
    void SetNameLock(const std::string & anExt);
private :

    Box2dr   BoxCam(const CamStenope & aCam,const CamStenope & aCamOut,bool Show) const;
    inline Pt2dr TransfoEpip(const Pt2dr &,const CamStenope & aCamIn,const CamStenope & aCamOut) const;
    CamStenopeIdeale  CamOut(const CamStenope &,Pt2dr aPP,Pt2di aSz);





    double             mScale;
    std::string        mDir;
    cInterfChantierNameManipulateur  * mICNM;
    const CamStenope & mCInit1;
    std::string        mName1;
    const CamStenope & mCInit2;
    std::string        mName2;
    std::string        mNamePair;
    std::string        mPrefLeft;
    std::string        mPrefRight;
    Pt2di              mSzIn;
    double             mFoc;
    ElMatrix<double_t>     mMatM2C;
    ElMatrix<double_t>     mMatC2M;

    CamStenopeIdeale   mCamOut1;
    CamStenopeIdeale   mCamOut2;
    bool               mOk;
    bool               mFirstIsLeft;
    int                mSzX;
    int                mSzY;
    double             mPxInf;

    std::string        mFileLock;
};
std::string LocDirMec2Im(const std::string & Im1,const std::string & Im2);
std::string StdNameImDeZoom(const std::string & Im1,int aDeZoom);


cCpleEpip * StdCpleEpip
(
        std::string  aDir,
        std::string  aNameOri,
        std::string  aNameIm1,
        std::string  aNameIm2
        );



// Pour assurer la compatibilite avec les format 2003 ....
CamStenope * CamCompatible_doublegrid(const std::string & aNameFile);



class cTxtCam
{
public :

    cTxtCam();
    void SetVitesse(const Pt3dr& aV);

    std::string          mNameIm;
    std::string          mNameOri;
    CamStenope *         mCam;
    CamStenope *         mRefCam;// En cas de reference exacte pour faire du reverse engenering
    cOrientationConique  * mOC;
    double               mPrio;
    bool                 mSelC;
    Pt3dr                mC;  // Center
    Pt3dr                mV;  // Vitesse
    Pt3dr                mWPK;  // Angles
    bool                 mVIsCalc;  // Vitesse
    int                  mNum;
    int                  mNumBande;
    double               mTime;
    const cMetaDataPhoto *     mMTD;
};
typedef cTxtCam * cTxtCamPtr;

class cCmpPtrCam
{
public :
    bool operator() (const cTxtCamPtr & aC1  ,const cTxtCamPtr & aC2);
};


class cCalibrationInterneGridDef;

class cDistorBilin :   public ElDistortion22_Gen
{
public :
    friend class cPIF_Bilin;

    friend void Test_DBL();

    cDistorBilin(Pt2dr aSz,Pt2dr aP0,Pt2di aNb);
    Pt2dr Direct(Pt2dr) const ;

    Pt2dr & Dist(const Pt2di aP) {return mVDist[aP.x + aP.y*(mNb.x+1)];}
    const Pt2dr & Dist(const Pt2di aP) const {return mVDist[aP.x + aP.y*(mNb.x+1)];}
    const Pt2di & Nb() const {return mNb ;}


    virtual cCalibDistortion ToXmlStruct(const ElCamera *) const;
    cCalibrationInterneGridDef ToXmlGridStruct() const;

    static cDistorBilin FromXmlGridStuct(const cCalibrationInterneGridDef & );


    bool  AcceptScaling() const;
    bool  AcceptTranslate() const;
    void V_SetScalingTranslate(const double &,const Pt2dr &);

private  :
    //  ==== Tests ============
    Box2dr BoxRab(double aMulStep) const;
    void Randomize(double aFact=0.1);
    void InitAffine(double aF,Pt2dr aPP);

    //  =============
    void  Diff(ElMatrix<double_t> &,Pt2dr) const;
    Pt2dr ToCoordGrid(const Pt2dr &) const;
    Pt2dr FromCoordGrid(const Pt2dr &) const;
    // Renvoie le meilleur interval [X0, X0+1[ contenat aCoordGr, valide qqsoit aCoordGr
    void GetDebInterval(int & aX0,const int & aSzGrd,const double & aCoordGr) const;
    //  tel que aCoordGr soit le barry de (aX0,aX0+1) avec (aPdsX0,1-aPdsX0)  et 0<= aX0 < aSzGr, aX0 entier
    void GetDebIntervalAndPds(int & aX0,double & aPdsX0,const int & aSzGrd,const double & aCoordGr) const;
    //  A partir d'un points en coordonnees grille retourne le coin bas-gauche et le poids
    void GetParamCorner(Pt2di & aCornerBG,Pt2dr & aPdsBG,const Pt2dr & aCoorGr) const;
    void InitEtatFromCorner(const Pt2dr & aCoorGr) const;

    Pt2dr                               mP0;
    Pt2dr                               mP1;
    Pt2dr                               mStep;
    Pt2di                               mNb;
    std::vector<Pt2dr >                 mVDist;

    mutable Pt2di                               mCurCorner;
    mutable double                              mPds[4];
};

class cCamStenopeBilin : public CamStenope
{
public :
    cCamStenopeBilin
    (
            double_t Focale,
            Pt2dr Centre,
            const  cDistorBilin & aDBL
            );

    const ElDistortion22_Gen & Dist() const;
    ElDistortion22_Gen & Dist() ;
    const cDistorBilin & DBL() const;

    cCamStenopeBilin * CSBil_SVP();
private :

    cDistorBilin mDBL;
};





#endif // !  _ELISE_GENERAL_PHOTOGRAM_H
