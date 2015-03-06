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


#ifndef _ELISE_GENERAL_OPTIM_ALLOCATEURDINCONNUES_H
#define _ELISE_GENERAL_OPTIM_ALLOCATEURDINCONNUES_H

#include "general/sys_dep.h"

class AllocateurDInconnues
{
      public :
        void AssertUsable(const cStateAllocI &) const;
        void RestoreState(const cStateAllocI &);
        AllocateurDInconnues();
        Fonc_Num        NewF(double_t *);
        int             NewInc(double_t *);
        Pt3d<Fonc_Num>  NewPt3(double_t *,double_t*,double_t*);
        Pt3d<Fonc_Num>            NewPt3(Pt3dr &);
        Pt2d<Fonc_Num>            NewPt2(double_t*,double_t*);
        Pt2d<Fonc_Num>            NewPt2(Pt2dr &);

        std::vector<Fonc_Num>            NewVectInc(std::vector<double> &);

        TplElRotation3D<Fonc_Num> NewRot(double_t *,double_t*,double_t*,double_t *,double_t*,double_t*);
        int CurInc() const;

	PtsKD PInits();
	void SetVars(const double_t * aSol);
	double  GetVar(int aK) const;
	double * GetAdrVar(int aK);
	void  SetVar(double aVal,int aK);
	void  SetVarPt(Pt2dr  aVal,int aK);
	double_t * ValsVar();
        void Reinit(int aK);

      private :
	void PushVar(double_t *);
	std::vector<double_t *>  mAdrVar;
	std::vector<double_t  >  mValsVar;
        int GetNewInc();
        int mIdInc;
        AllocateurDInconnues (const AllocateurDInconnues &);
        void operator = (const AllocateurDInconnues &);
};

#endif
