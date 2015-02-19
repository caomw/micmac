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

Appar23  BarryImTer(const std::list<Appar23> &);
void InvY(std::list<Appar23> &,Pt2dr aSzIm,bool InvX=false);


// extern bool BugSolveCstr;
// extern bool BugCstr;
extern bool BugFE; // pour debuguer les pb de non inversibilite des dist fortes
extern bool BugAZL; // pour debuguer les pb d'AZL
extern bool BugGL; // pour debuguer les pb de Guimbal Lock







class ElRotation3D;

enum eModeleCamera
{
    eModeleCamIdeale,
    eModeleCamDRad,
    eModeleCamPhgrsStd



// txt : format texte,  dat : format binaire (int , double[3] *)
std::vector<Pt3dr> * StdNuage3DFromFile(const std::string &);


// Representation des points homologues comme images, utiles lorsqu'ils
// sont denses et + ou - regulierement espaces avec une image maitresse







typedef std::pair<Pt2dr,Pt2dr> tPairPt;









// Toutes les projections R3->R2 consideree  dans ElProj32
// sont des projections avec rayon perspectif droits



/* Le neologisme AFocal designe les projection qui sont quasi-stenope, cad dont le
   point nodal varie en fonction  de l'angle de visee


*/

#define NbParamAF 2






typedef  std::vector<double> tParamAFocal;



class cXmlAffinR2ToR;


class cXmlHomogr;











/*
 *    ** : Methodes a redefinir imperativement si distortion non triviale.
 *
 */






// Implemante des deformations du type "D-1 o H o D" avec
// D disrortion radiale polynomiale et H homographie




// Classe de distortion par polynome de degre 2, Pas un interet fou
// (elle sont un peu + rapide que si definies par polynomes generiques)
// mais developpee pour tester rapidement certaine fonctionnalites
// generiques
//














typedef enum
{
    eProjectionStenope,
    eProjectionOrtho
} eTypeProj;




//  Classe qui permet de manipuler de manière via une interface uniforme une image,
// ou un nuage de point





// Represente les cameras a projection parallele (focale infinie),
//
//  La focale et le point principal sont indissociables de la translation,
//  ce sont des parametres extrinseques representes dans la translation
//  (via le R3toL3/L3toR3)


// Preconditionnement en arc-tangente, adapte a un fish eye conservant
// les angles.
//


// Modele pour fish eye lineaire


// Modele pour fish eye equisolid





// Donne une mesure en pixel (non distordu) de l'ecart d'appariement
REAL EcartTotalProjection
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






//
// Soit une camera et l'application D du plan dans le
// plan telle que pour un point P=(U,V) camera,
//  R=(D(U),D(V),1.0) soit la direction issu de P,
//  cDistStdFromCam permet de representer cette application
//  sous forme d'une ElDistortion22_Gen, ce qui peut etre utile
//  par exemple pour generer des grilles;
//  l'Inversion n'est pas tres rapide car elle calcule des
//  derivees par differences finies.




// Classe pour presenter une image Orilib comme une
// camera Elise

class cDistorsionOrilib;


// Camera a Stenope Ideale



//  Permet de dupliquer une camera, sans copier les distorsion
//  sans connaitre son origine








// Classe pour modeliser ma distortion telle que
// decrite dans Fraser, ISPRS 97, Vol 52, 149-159
//



//   /*Par defaut fonctionne en inverse (ie Cam -> Monde)























//  -----------------------------------------------
//
//      POLYGONE D'ETALONNAGE
//
//  -----------------------------------------------




// La classe cCibleCalib est la nouvelle "classe" pour representer les
// cibles, elle est plus complete (normale ...) et admet une lecture
// ecriture standard par xml. Pour des raisons de compatibilite on
// conserve cCiblePolygoneEtal qui contient un cCibleCalib *. C'est
// un peu batard mais correspond au moyen le + econome de gerer
//  cette classe qui n'a pas vocation a generer de grand developpement


class cCibleCalib;
class cPolygoneCalib;
class cComplParamEtalPoly;






class cSetNImSetPointes;







ElRotation3D RotationCart2RTL(Pt3dr  aP, double aZ);
ElRotation3D RotationCart2RTL(Pt3dr  aP, double aZ,Pt3dr axe_des_x);






std::string LocPxFileMatch(const std::string & aDir,int aNum,int aDeZoom);
std::string LocMasqFileMatch(const std::string & aDirM,int aNum);


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



typedef cTxtCam * cTxtCamPtr;



class cCalibrationInterneGridDef;







#endif // !  _ELISE_GENERAL_PHOTOGRAM_H
