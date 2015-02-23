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

#ifndef _ELISE_INCLUDE_GENERAL_PTXD_H_
#define _ELISE_INCLUDE_GENERAL_PTXD_H_

#include <general/util.h>

//#define Pt2di  Pt2d<INT>
//#define Pt2dr  Pt2d<REAL>

class Output;
class SegComp;
class Seg2d;
class cElTriangleComp;
template <class Type> class Pt3d;


inline INT  scal(INT v1 ,INT v2 ) { return v1 * v2;}
inline REAL scal(REAL v1,REAL v2) { return v1 * v2;}







template <class Type> class Pt2d;









double DMaxCoins(ElAffin2D AfC2M,Pt2dr aSzIm,Pt2dr aC);




// Fonctions specifiques a un des types de points

    // When a Pt2di p is used as a ``seed'' to generate a digital line the average euclidean
    // distance d between two consecutives points is variable according to p
    // For example  : d = sqrt(2) for p = (1,1) or p = (234,234) and d = 1 for p = (-99,0)
REAL  average_euclid_line_seed (Pt2di);
Pt2di  best_4_approx(const Pt2di & p);
Pt2di  second_freeman_approx(Pt2di u, bool conx_8,Pt2di u1);
INT    num_4_freeman(Pt2di);
Pt2dr ImAppSym(REAL A,REAL B,REAL C,Pt2dr aP);

Pt2di corner_box_included(Pt2di pmin,Pt2di pmax,bool left,bool down);

inline Pt2di round_ni(Pt2dr  p)
{
    return Pt2di(round_ni(p.x),round_ni(p.y));
}
inline Pt2di round_up(Pt2dr  p)
{
    return Pt2di(round_up(p.x),round_up(p.y));
}
inline Pt2di round_down(Pt2dr  p)
{
    return Pt2di(round_down(p.x),round_down(p.y));
}


inline Pt2di arrondi_sup(Pt2di a,Pt2di b)
{
    return Pt2di
           (
               arrondi_sup(a.x,b.x),
               arrondi_sup(a.y,b.y)
           );
}

inline Pt2di arrondi_sup(Pt2di a,int b)
{
   return arrondi_sup(a,Pt2di(b,b));
}



inline Pt2dr rot90(Pt2dr p)
{
    return Pt2dr(-p.y,p.x);
}
inline Pt2dr vunit(Pt2dr p,REAL & d)
{
   d = euclid(p);
   ELISE_ASSERT((d!=0),"Null seg in vunit");
   return p/d;
}

inline Pt2dr vunit(Pt2dr p)
{
   REAL d ;
   return vunit(p,d);
}

/*
inline Pt2dr barry(REAL pds1,const Pt2dr & p1,const Pt2dr & p2 )
{
     return p1*pds1  + p2*(1-pds1);
}
*/








/* JYCAR
*/




template <class Type> class BoxFreemanCompil;
template <class Type> class Box2d;

template <class Type> Box2d<Type> Sup(const Box2d<Type> & b1, const Box2d<Type> & b2);
template <class Type> Box2d<Type> Inf(const Box2d<Type> & b1, const Box2d<Type> & b2);
template <class Type> bool InterVide(const Box2d<Type> & b1, const Box2d<Type> & b2);


inline Pt2dr ToPt2dr(const Pt2dr & aP) {return aP;}
inline Pt2dr ToPt2dr(const Pt2di & aP) {return Pt2dr(aP.x,aP.y);}
inline Pt2dr ToPt2dr(const Pt2dlr & aP){return Pt2dr(aP.x,aP.y);}
inline Pt2di ToPt2di(const Pt2dr & aP) {return Pt2di(round_ni(aP.x),round_ni(aP.y));}
inline Pt2di ToPt2di(const Pt2di & aP) {return aP;}
inline Pt2di ToPt2di(const Pt2dlr & aP){return Pt2di(round_ni(aP.x),round_ni(aP.y));}


class Flux_Pts;



Pt2di BoxPClipedIntervC(const Box2di &,const Pt2di &);

extern std::istream & operator >> (std::istream & ifs,Box2dr  &aBox);
extern std::istream & operator >> (std::istream & ifs,Box2di  &aBox);
Pt2di  RandomlyGenereInside(const Box2di &) ;

Box2dr  I2R(const Box2di &);
Box2di  R2I(const Box2dr &);   // Par round_ni
Box2di  R2ISup(const Box2dr &);   // Par down et sup

std::ostream & operator << (std::ostream & ofs,const Box2di  &aBox);
std::ostream & operator << (std::ostream & ofs,const Box2dr  &aBox);



void AdaptParamCopyTrans(INT& X0src,INT& X0dest,INT& NB,INT NbSrc,INT NbDest);

void AdaptParamCopyTrans(Pt2di& p0src,Pt2di& p0dest,Pt2di& sz,
                          Pt2di   SzSrc, Pt2di   SzDest);




extern const Pt2dr aPRefFullFrame;
class cElRegex;
// cCameraEntry *  CamOfName(const std::string & aName);

extern double GetFocalMmDefined(const std::string & aNameFile);

extern bool CmpY(const Pt2di & aP1,const Pt2di & aP2);



class cSystemeCoord;
class cChangementCoordonnees;
class cBasicSystemeCoord;
class cXmlGeoRefFile;


class cSysCoordPolyn;
template <class Type>  class ElMatrix;



class ElCamera;





Pt3dr  tCho2double(const Pt3d<tSysCho> & aP);


typedef TypeSubst<Pt2di>   Pt2diSubst;
typedef TypeSubst<Pt2dr>   Pt2drSubst;

std::vector<Pt3dr>  GetDistribRepreBySort(std::vector<Pt2dr> & aVP,const Pt2di & aNbOut,Pt3dr & aPRep);

std::vector<Pt3dr> GetDistribRepresentative(Pt3dr & aCdg,const std::vector<Pt2dr> & aV,const Pt2di & aNb);


namespace std
{
bool operator < (const Pt3di & aP1,const Pt3di & aP2);
}


class cMTDImCalc;
class cMIC_IndicAutoCorrel;

cMTDImCalc GetMTDImCalc(const std::string & aNameIm);
const cMIC_IndicAutoCorrel * GetIndicAutoCorrel(const cMTDImCalc & aMTD,int aSzW);
std::string NameMTDImCalc(const std::string & aFullName);


#endif //  _ELISE_INCLUDE_GENERAL_PTXD_H_

