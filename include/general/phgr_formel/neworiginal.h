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

#ifndef  _PHGR_FORMEL_H_
#define  _PHGR_FORMEL_H_

#include <photogram_defs.h>

#include <ElProjStenopeGen>
#include <CamStenopeIdeale>

#include <string>
#include <vector>
#include <set>

#define DIRECTORY_GENCODE_FORMEL "CodeGenere/photogram/"


// Pour mettre au point les pb de conditionnement
extern double aSeuilMaxCondSubstFaiseau;
extern bool DebugPbCondFaisceau ;
extern bool BugUPL;
void ReinitStatCondFaisceau();
void ShowStatCondFaisceau(bool ShowVect);

extern bool DBFActiveProf6 ;

// Appuis
// Croisee
// Liaison
//  cEqDirecteDistorsion
//

extern const bool AFocalAcceptNoDist;

extern bool TestPermutVar;
extern bool ShowPermutVar;
extern bool ShowCholesky;
// Devrait toujours etre true, mais il y a un bug pour l'instant, avant
// d'assurer une reversibilite tant que le bug n'est pas trouve ....

extern Pt2dr aDebugPIm;
extern Pt2dr aDebugPL3;


void DebugLaser(const std::string & aName);

// dans exemple_phgr_formel.h
 
      // Qc classe simple liee aux equation directe entre calib,
      // aussi a but "didactique"
class cEqObsRotVect;
class cEqCalibCroisee;
class cEqDirecteDistorsion;








typedef std::set<cIncIntervale,cIdIntCmp> cMapIncInterv;
/*
*/




















class cDicoHomogSEF;
class cDicoCameraSEF;
class cDicoRotSEF;

// But est de reutiliser celles qui existe
// Pas d'associer un nom a chaque
class cDicoEqCorrGrid; 




class AllocateurDInconnues;
class CamStenope;
class cFormQuadCreuse;
class cCamStenopeDistRadPol;
class cCamStenopeDistPolyn;
class cCamStenopeModStdPhpgr;
class cCamStenopeDistHomogr;
class cCamStenopeBilin;
class cGenSysSurResol;
class cMirePolygonEtal;
class cElHomographie;
class ElDistRadiale_PolynImpair;


extern void ShowSpectrSys(cSetEqFormelles & aSetEq);



#if (0)
#endif

class cElComposHomographie;

class cDistModStdPhpgr;


class cCamStenopeGrid;


// class cHomogFormelle;
// class cParamIntrinsequeFormel : public cElemEqFormelle,




// Classe pour modeliser ma distortion telle que
//  decrite dans Fraser, ISPRS 97, Vol 52, 149-159
//  i.e.  : Radiale + Decentrique + Affine




// Pour le GL (Gimbal-Lock) ,c'est la rotation qui transforme Cam->Monde
//   cRotationFormelle::C2M  mFMatr * aP + mFCOpt;
//    mFMatrInv * (aP - mFCOpt);


// eTypeEqAppui






#if (0)

#endif













// Class pour resoudre de maniere simplifiee, l'equation homographique

/*
    Cette classe se specialise dans la resolution
   de l'equation

       Hom1 (Dist(P1)) =  Hom2 (Dist(P2))

*/








class cPolynFormelXY;









// Classe d'Interface
//
//  Une triangulation formelle peut etre de dimension qcq sur les attribut
//  (parametre Dim), ce n'est que lorsque Dim=2 qu'elle herite pertinement
//  de ElDistortion22_Gen 
//







// Les Grids ne peuvent pas (simplement) etre utlisees comme
// les autres distorsions parce qu'elle necessite un manipulation
// non standard des indices (le jeux des indices d'inconnues
// intervennant dans les equation depends du (ou des) triangles
// en jeux. Par ailleurs, il n'ont pas de raison d'avoir une
// focale ou un point principal variable.




















struct  cElemEqCorrelGrid 
{
            cElemEqCorrelGrid
            (
	         cSetEqFormelles & aSet,
		 INT               aNum,
                 bool              GenCode
            );
	    void InitAdr(cElCompiledFonc *,bool Im2MoyVar);

	    std::string    mNN;  // Name Num
	    cIncIntervale  mInterv;
	    std::string    mNameGr1;
	    std::string    mNameGr2of0;
	    std::string    mNameDGr2Dz;
	    std::string    mNameZCur;

	    cVarSpec       mGr1;
	    cVarSpec       mGr2of0;
            cVarSpec       mDGr2Dz;
            cVarSpec       mZCur;
	    double *       mAdrGr1;
	    double *       mAdrGr2Of0;
	    double *       mAdrDGr2Dz;
	    double *       mAdrZCur;
            Fonc_Num       mZ;
            Fonc_Num       mGr2ofZ;
            Fonc_Num       mGr2ofZCur;


/*
*/


class cAllocNameFromInt;







#endif  // _PHGR_FORMEL_H_
