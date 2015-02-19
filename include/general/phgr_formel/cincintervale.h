/*Header-MicMac-eLiSe-25/06/2007

    MicMac : Multi Image Correspondances par Methodes Automatiques de Correlation
    eLiSe  : ELements of an Image Software Environnement

    www.micmac.ign.fr


    Copyright : Institut Geographique National
    Author : Marc Pierrot Deseilligny
    Contributors : Gregoire Maillet, Didier Boldo.
    Refactoring: Helio Chissini de Castro <helio@kde.org>

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


#ifndef _ELISE_GENERAL_PHGR_FORMEL_CEQF1INCTMP;_H
#define _ELISE_GENERAL_PHGR_FORMEL_CEQF1INCTMP;_H

#include "general/sys_dep.h"

class cEqf1IncTmp;   // 1 Inconnue temporaire
#ifndef _ELISE_GENERAL_PHGR_FORMEL_CEQFBLOCINCTMP;_H
#define _ELISE_GENERAL_PHGR_FORMEL_CEQFBLOCINCTMP;_H

#include "general/sys_dep.h"

class cEqfBlocIncTmp;  // 1 Bloc d'inconnue temporaire
#ifndef _ELISE_GENERAL_PHGR_FORMEL_CEQFP3DINCTMP;_H
#define _ELISE_GENERAL_PHGR_FORMEL_CEQFP3DINCTMP;_H

#include "general/sys_dep.h"

class cEqfP3dIncTmp;  // Une specialisation de cEqfBlocIncTmp pour point terrain

class cParamPtProj;
class cP3d_Etat_PhgrF;
class cP2d_Etat_PhgrF;
class cMatr_Etat_PhgrF;

// -----------------------------
//class cMapIncInterv;
class cElCompiledFonc ;

class cIncIntervale;
class cIncListInterv;

class cNameSpaceEqF;
class cSetEqFormelles;
class cHomogFormelle;
class cDistRadialeFormelle;
class cEqHomogFormelle;
class cEqOneHomogFormelle;
class cParamIntrinsequeFormel;
class cRotationFormelle;
class cCameraFormelle;
class cCpleCamFormelle;
class cParamIFDistRadiale;
class cParamIFDistPolynXY ;
class cTriangulFormelle;
class cCpleGridEq;
class cEqEllipseImage;
class cParamIFHomogr;
class cLIParam_Image;
class cEqVueLaserImage;
class cEqCorrelGrid;
class cEqFormelleLineaire;
class cParamIFDistStdPhgr;
class cAppuiGridEq;
class cEqPlanInconnuFormel;
class cTFI_Triangle;

class cTFI_AttrSom;

class cInterfSurfaceAnalytique ;
class cInterfSurfAn_Formelle;
class cCylindreRevolution;
class cCylindreRevolFormel;


class cL2EqObsBascult;
class cSolBasculeRig;

class cPIF_Bilin;


class cEqOffsetGPS;
class cBaseGPS;
class cEqObsBlockCam;


//   Il n'avait pas ete prevu de renumeroter les intervales. Quand le besoin
//   est apparu, pour la resolution des systemes par cholesky creux, on a gere
//   ca par une double numerotation :
//         - I0Init : numerotation initiale, lie a l'ordre d'allocation des inconnues
//         - I0Final : systeme de numerotation  optumisie pour les matrices
//    En premiere phase, on duplique touts les numero, sans doute certains deviendront
//   inutiles.
// 

class cSsBloc;

#ifndef _ELISE_GENERAL_PHGR_FORMEL_CINCINTERVALE_H
#define _ELISE_GENERAL_PHGR_FORMEL_CINCINTERVALE_H

#include "general/sys_dep.h"

class cIncIntervale
{
    public :
       cSsBloc  SsBlocComplet();

       bool operator == (const cIncIntervale &) const;
       typedef std::string tId;

       cIncIntervale(bool isTmp,const tId & anId,cSetEqFormelles     &,int aNbInc=-1);
       cIncIntervale(const tId & anId,INT anI0,INT anI1,bool isTmp=false);
    // Copie, avec renommage
       cIncIntervale(const cIncIntervale &,const tId &);

       void SetName(const tId &);
       void SetI0I1Alloc(INT I0,INT I1);

       INT I0Alloc()  const ;
       INT I1Alloc()  const ;
       int NumBlocAlloc() const {return mNumBlocAlloc;}
       INT I0Solve()  const ;
       INT I1Solve()  const ;
       int NumBlocSolve() const {return mNumBlocSolve;}


       INT Sz()  const ;
       const tId & Id() const;
       void Close();
       void SetNumAlloc(int aNum);

       bool Overlap(const cIncIntervale &) const;
    // bool operator < (const cIncIntervale &) const; // Compare les Id

       void SetFiged(bool);
       bool IsFiged() const;  // Est ce que TOUTES les var sont figees dans l'int
       double Order() const;
       void SetOrder(double) ;
       void SetFirstIntervalSolve();
       void InitntervalSolve(const cIncIntervale &);
       bool IsTmp() const;
    private :

       INT mI0Alloc;
       INT mI1Alloc;
       INT mI0Solve;
       INT mI1Solve;

       cSetEqFormelles     * mSet;
       tId                    mId;
       int                    mNumBlocAlloc;
       int                    mNumBlocSolve;
       bool                   mFiged;
       double                 mOrder;
       bool                   mIsTmp;
};

#endif
