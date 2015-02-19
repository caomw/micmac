#ifndef _ELISE_GENERAL_PHOTOGRAM_ELPACKHOMOLOGUE_H
#define _ELISE_GENERAL_PHOTOGRAM_ELPACKHOMOLOGUE_H

#include "general/sys_dep.h"

class ElPackHomologue : public cPackNupletsHom
{
private :

    tCont::iterator  NearestIter(Pt2dr aP,bool P1 = true);


    // utilise pour parametrer l'ajustement dans FitDistPolynomiale
    // Par defaut resoud aux moindre L1, l'aspect virtuel permet
    // de definir une classe ayant exactement le meme
    // comportement
    ElMatrix<REAL> SolveSys(const  ElMatrix<REAL> &);


    void  PrivDirEpipolaire(Pt2dr & aDir1,Pt2dr & aDir2,INT aNbDir) const;
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
            INT aDegre,
            REAL anAmpl,
            bool aFitX
            );

    ElDistortionPolynomiale FitDistPolynomiale
    (
            bool aL2,
            INT aDegre,
            REAL anAmpl,
            REAL anEpsInv = 1e-7
            );
    void  DirEpipolaire(Pt2dr & aDir1,Pt2dr & aDir2,INT WantedPts,INT aNbDir,INT aDegre) const;
    CpleEpipolaireCoord *  DirAndCpleEpipolaire
    (Pt2dr & aDir1,Pt2dr & aDir2,INT WantedPts,INT aNbDir,INT aDegreFinal) const;

    ElMatrix<REAL> MatriceEssentielle(bool SysL2);

    REAL MatriceEssentielle
    (
#ifndef _ELISE_GENERAL_PHOTOGRAM_CGENSYSSURRESOL_H
#define _ELISE_GENERAL_PHOTOGRAM_CGENSYSSURRESOL_H

#include "general/sys_dep.h"

            class cGenSysSurResol &,
            double *  Vect,
            REAL  EcartForPond
            );


    // Optimise la mise en place relative par un algo generique
    // (powel) de descente sur un critere L1
    ElRotation3D OptimiseMEPRel(const ElRotation3D & );

    // Teste la matrice essentielle et le plan et retient la meilleure
    // Par defaut fait une optimisation , pas forcement opportune
    ElRotation3D MepRelGen(REAL LongBase,bool L2,double & aD);
    ElRotation3D MepRelGenSsOpt(REAL LongBase,bool L2,double & aD);
    ElRotation3D MepRelGen(REAL LongBase,bool L2,double & aD,bool Optimize);


    // Comme dab, en entree des couple "photogrammetrique" en sortie
    // la rotation qui envoie de 1 vers 2
    ElMatrix<REAL> MepRelCocentrique(int aNbRansac,int aNbMaxPts) const;


    //   Toutes les mises en place relatives font les hypotheses suivantes
    //
    //      - points "photogrammetriques" (x,y) -> (x,y,1)
    //      - orientation 1 : identite

    // renvoie les rotation qui permet, etant donne
    // un point en coordonnee camera1, d'avoir
    // ses coordonnees en camera 2
    std::list<ElRotation3D> MepRelStd(REAL LongBase,bool L2);

    // Phys : cherche a avoir le max de couples de rayons
    // qui s'intersectent avec des Z positifs
    ElRotation3D MepRelPhysStd(REAL LongBase,bool L2);

    // Nombre de points ayant une intersection positive en Im1 et Im2
    REAL SignInters
    (
            const ElRotation3D & aRot1to2,
            INT &                NbP1,
            INT &                NbP2
            );

    tPairPt  PMed() const;

    // Si tous les points sont coplanaires, ou presque,
    //  la mise en place par l'algo standard est degenere,
    // on choisit donc un algo ad hoc
    cResMepRelCoplan   MepRelCoplan (REAL LongBase,bool HomEstL2);
    static cResMepRelCoplan   MepRelCoplan (REAL LongBase,cElHomographie,const tPairPt & Centre);

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

#endif
