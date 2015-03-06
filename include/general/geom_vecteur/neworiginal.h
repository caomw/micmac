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



#ifndef _ELISE_GENERAL_GEOM_VECTEUR_H  // general
#define _ELISE_GENERAL_GEOM_VECTEUR_H

#include "ext_stl/fifo.h"
#include <general/ptxd.h>









double_t   surf_or_poly(const ElFifo<Pt2dr> &);
double_t   surf_or_poly(const std::vector<Pt2dr> &);
double_t   perimetre_poly(const std::vector<Pt2dr> &);
Pt2dr  barrycentre(const ElFifo<Pt2dr> &);
Pt2dr  barrycentre(const std::vector<Pt2dr> &);
double_t   SquareDistPointPoly(const ElFifo<Pt2dr> & f,Pt2dr pt);
bool   PointInPoly(const ElFifo<Pt2dr> & f,Pt2dr pt);
bool   PointInPoly(const std::vector<Pt2dr> & f,Pt2dr pt);
bool   PointInterieurPoly(const ElFifo<Pt2dr> & f,Pt2dr pt,double_t d);
void   BoxPts(ElFifo<Pt2dr> & pts,Pt2dr & p0,Pt2dr & p1);
Box2dr BoxPts(const std::vector<Pt2dr> & pts);

bool HasInter(const std::vector<Pt2dr> & f1,const std::vector<Pt2dr> & f2);

std::vector<Pt2dr> DilateHomotetik
                   (const std::vector<Pt2dr> &,double,const Pt2dr & aCentre);
std::vector<Pt2dr> DilateHomotetikCdg(const std::vector<Pt2dr> &,double);

void PtsOfSquare(ElFifo<Pt2dr> & pts,Pt2dr p0,Pt2dr p1);



#define IMat_Inertie  Mat_Inertie<ElStdTypeScal<int> >
#define RMat_Inertie  Mat_Inertie<ElStdTypeScal<double_t> >

inline Pt2dr MatCdg(const RMat_Inertie& aMat)
{
   return Pt2dr(aMat.s1(),aMat.s2());
}
inline double ValQuad(const RMat_Inertie& aMat,const Pt2dr aP)
{
   return     aMat.s11() * ElSquare(aP.x)
         +  2*aMat.s12() * aP.x* aP.y
         +    aMat.s22() * ElSquare(aP.y);
}

template <class Type> double_t square_dist_droite(const SegComp &, const Mat_Inertie<Type> &);
template <class Type> Seg2d seg_mean_square(const Mat_Inertie<Type> &,double_t norm = 1.0);


void env_conv
     (
         ElFifo<int> &          ind,
         const ElFilo<Pt2di> &  pts,
         bool                   env_min
     );
void env_conv
     (
         ElFifo<int> &          ind,
         const ElFilo<Pt2dr> &  pts,
         bool                   env_min
     );









/*****************************************************************/
/*                                                               */
/*        Classes pour QTree                                     */
/*                                                               */
/*****************************************************************/













/*******************************************************/
/*                                                     */
/*    3D 3D 3D 3D 3D 3D 3D 3D 3D 3D 3D 3D 3D 3D 3D     */
/*                                                     */
/*******************************************************/

class cRapOnZ;


Pt3dr   norm_or_poly(const ElFifo<Pt3dr> &,double_t * surf =0);

struct cResOptInterFaisceaux
{
  public :
     void Init(const ElMatrix<double> &);
     double  mVal1;
     double  mVal2;
     double  mVal3;
     Pt3dr   mVec1;
     Pt3dr   mVec2;
     Pt3dr   mVec3;






/*
*/

void TestInterPolyCercle();

double_t SurfIER (Pt2dr,double_t,double_t,double_t,Pt2dr,Pt2dr);
double_t DerASurfIER (Pt2dr,double_t,double_t,double_t,Pt2dr,Pt2dr);
double_t DerBSurfIER (Pt2dr,double_t,double_t,double_t,Pt2dr,Pt2dr);
double_t DerCSurfIER (Pt2dr,double_t,double_t,double_t,Pt2dr,Pt2dr);
double_t DerCElXSurfIER (Pt2dr,double_t,double_t,double_t,Pt2dr,Pt2dr);
double_t DerCElYSurfIER (Pt2dr,double_t,double_t,double_t,Pt2dr,Pt2dr);
double_t DerP0XSurfIER (Pt2dr,double_t,double_t,double_t,Pt2dr,Pt2dr);
double_t DerP0YSurfIER (Pt2dr,double_t,double_t,double_t,Pt2dr,Pt2dr);
double_t DerP1XSurfIER (Pt2dr,double_t,double_t,double_t,Pt2dr,Pt2dr);
double_t DerP1YSurfIER (Pt2dr,double_t,double_t,double_t,Pt2dr,Pt2dr);
Fonc_Num    FN_SurfIER
            (
                Pt2d<Fonc_Num> aCel,
                Fonc_Num aA,Fonc_Num aB,Fonc_Num aC,
                Pt2d<Fonc_Num> aP0,Pt2d<Fonc_Num> aP1
            );

// A partir de l'image d'un repere orthonorme V0,V1
// calcule les parametres A,B,C d'une ellipse
// passant par V0 et V1

void ImRON2ParmEllipse
     (
         double_t & A,
         double_t & B,
         double_t & C,
         const Pt2dr & aV0,
         const Pt2dr & aV1
     );

Box2dr BoxEllipse(Pt2dr aCenter,double_t A,double_t B,double_t C);

     // return faux si pas Ellispe physique (ie pas deux VP pos)
bool EllipseEq2ParamPhys
     (
        double_t  & V1,
        double_t  & V2,
        double_t  & teta,
        double_t  A,
        double_t  B,
        double_t  C
     );

void InvertParamEllipse
     (
        double_t & A,  double_t & B,  double_t & C ,
        double_t  A0,  double_t  B0,  double_t   C0
     );


double_t  SimilariteEllipse(double_t A1,double_t B1,double_t C1,double_t A2,double_t B2,double_t C2);


/*************************************************************/
/*                                                           */
/*               Images de distances                         */
/*                                                           */
/*************************************************************/

void TestImDist(int,char **);




class cQtcElNuageLaser;



struct gpc_polygon;



// Representation maillee d'un nuage de points 3D



/*
*/

#endif // _ELISE_GENERAL_GEOM_VECTEUR_H

