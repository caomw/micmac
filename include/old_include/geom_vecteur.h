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


class Seg2d
{
   public :

     Seg2d(double_t x1,double_t y1,double_t x2,double_t y2);
     Seg2d(Pt2dr,Pt2dr);
     Seg2d();  // create an empty seg

    Seg2d reverse() const {assert_non_empty(); return Seg2d(p1(),p0());}

     Seg2d clip(Box2dr) const;
     Seg2d clip(Box2dr,double_t,double_t,bool IsSeg) const;
     Seg2d clipDroite(Box2dr) const;
     Seg2d clip(Box2di) const;

     inline bool  empty() const {return _empty;}
     inline Pt2dr p0() const {assert_non_empty();  return _pts[0];}
     inline Pt2dr p1() const {assert_non_empty();  return _pts[1];}

     inline double_t x0() const {assert_non_empty();  return _pts[0].x;}
     inline double_t x1() const {assert_non_empty();  return _pts[1].x;}
     inline double_t y0() const {assert_non_empty();  return _pts[0].y;}
     inline double_t y1() const {assert_non_empty();  return _pts[1].y;}

     inline Pt2dr milieu() const {assert_non_empty();  return (_pts[1]+_pts[0])/2.0;}

     inline Pt2dr v01() const {assert_non_empty();  return _pts[1]-_pts[0];}

     inline Seg2d trans(Pt2dr tr) const {assert_non_empty();  return Seg2d(_pts[0]+tr,_pts[1]+tr);}

      double_t AbsiceInterDroiteHoriz(double_t anOrdonnee) const;

   protected :

    inline Pt2dr kpts(int k) const {return _pts[k];}

     void assert_non_empty() const
     {
          ELISE_ASSERT
          (    (! _empty)   ,
               "try to access to value of empty segment"
          );
     }



     Pt2dr  _pts[2];
     bool   _empty;
};


class SegComp : public Seg2d
{
    // equation normale de la droite
    //  (p1 p). _normale = 0;
    //   p._normale  - _p1. _normale = 0
    //  c = - _p1. _normale


//  Le repere de la droite (quand on parle abscisse et ordonnees)
//  est le repere Ortho Normee direct d'origine p1 et de 1ere dir p1p2

     public :

        Pt2dr ToRhoTeta() const;
        static SegComp FromRhoTeta(const Pt2dr &aP);

        typedef enum
        {
           droite =0,
           demi_droite =1,
           seg =2
        }  ModePrim;


        // Constructeur par defaut, necessaire pour creer des vector,
        //  ElFilo etc... A ne jamais utiliser sinon (etat douteux)
        SegComp();
        SegComp(Pt2dr p1,Pt2dr p2);
        SegComp(const Seg2d &);


        // tel que Cx X + Cy Y + C0 est la fonction ordonnee
    // qui prend une valeur 1 en P, utile pour calculer
    // une "matrice" de coeeficent bary dans un triangle
        void CoeffFoncOrdonnee
         (
              const Pt2dr& aP,
          double & Cx,
          double & Cy,
          double & aC0
             ) const;


        double_t ordonnee(Pt2dr pt) const;
        double_t ordonnee(Pt3dr pt) const;  // Point Projectif
        Fonc_Num ordonnee(Pt3d<Fonc_Num> pt) const;  // Point Projectif Formel
        double_t  abscisse(Pt2dr pt) const;

        double_t  abscisse_proj_seg(Pt2dr pt) const;  // clippee dans [0 lenght]
        double_t  recouvrement_seg(const Seg2d &) const;  // clippee dans [0 lenght]

        Pt2dr to_rep_loc(Pt2dr) const;
        Pt2dr from_rep_loc(Pt2dr) const;

        double_t  length()   const  {return _length;}
        Pt2dr tangente() const  {return _tangente;}
        Pt2dr normale()  const  {return _normale;}
        double_t  c()        const  {return _c;}

        bool in_bande(Pt2dr pt,ModePrim) const;

        bool BoxContains(Pt2dr pt,double_t DLong,double_t DLarg) const;
        bool BoxContains(const Seg2d & ,double_t DLong,double_t DLarg) const;

   //=========   DISTANCES   ==============

        double_t square_dist_droite(Pt2dr pt) const;
        double_t square_dist_demi_droite(Pt2dr pt) const;
        double_t square_dist_seg(Pt2dr pt) const;
        double_t square_dist(ModePrim  mode,Pt2dr   pt) const;

        double_t dist_droite(Pt2dr pt) const;
        double_t dist_demi_droite(Pt2dr pt) const;
        double_t dist_seg(Pt2dr pt) const;
        double_t dist(ModePrim  mode,Pt2dr   pt) const;

        double_t square_dist(ModePrim,const SegComp &,ModePrim) const;
        double_t dist(ModePrim,const SegComp &,ModePrim) const;

   //=========   DISTANCES DE HAUSSDORF   ==============

        // la 1ere primitive est tjs consideree comme un segment
        // (sinon Haussdorf = infini, hors paralellisme notoire)
        // dans les version assym, il s'agit de la dist du point de la premiere
        // le pus loin de la deuxieme.

        double_t  square_haussdorf_seg_assym(const SegComp &) const;
        double_t  square_haussdorf_seg_sym(const SegComp &) const;
        double_t  square_haussdorf_droite_assym(const SegComp &) const;

              // max de "square_haussdorf_droite_assym" dans
              // les 2 sens, donc pas vraiment une distance de haussdorf
              //  au sens mathematique du terme

        double_t  square_haussdorf_droite_sym(const SegComp &) const;

   //=========   PROJECTIONS   ==============

        Pt2dr  proj_ortho_droite(Pt2dr pt) const;
        Pt2dr  proj_ortho_demi_droite(Pt2dr pt) const;
        Pt2dr  proj_ortho_seg(Pt2dr pt) const;
        Pt2dr  proj_ortho(ModePrim,Pt2dr pt) const;
        Seg2d  proj_ortho(ModePrim,const SegComp &,ModePrim) const;

   //=========   intERSECTION   ==============

        Pt2dr   inter(const SegComp &,bool &) const;  // droite
        Pt2dr   inter(ModePrim,const SegComp &,ModePrim,bool &) const;

        void inter_polyline
             (
                 ModePrim,
                 const ElFifo<Pt2dr> &,
                 ElFifo<int>  &,   // index
                 ElFifo<Pt2dr> &   // resultats
             );

        static const Pt2dr NoPoint;
        std::vector<Seg2d> Clip(const std::vector<Pt2dr> &);

     protected :

        Pt2dr _tangente;
        double_t  _length;
        Pt2dr _normale;
        double_t  _c;
        double_t  _a1;   // abscisse p1, dans le repere de la droite

        double_t   _square_dist(ModePrim m1,const SegComp & s2,ModePrim m2) const;
        void   proj_ortho
               (
                   ModePrim,
                   const SegComp &,
                   ModePrim,
                   double_t & dmin,
                   Pt2dr & p0min,
                   Pt2dr & p1min
               ) const;

};


class cElTriangleComp
{
    public :
        cElTriangleComp(Pt2dr aP0,Pt2dr aP1,Pt2dr aP2);
            double_t square_dist(Pt2dr pt) const;

        bool Inside(const Pt2dr &) const;

        Pt2dr P0() const;
        Pt2dr P1() const;
        Pt2dr P2() const;

           // Renvoie une matrice telle que pour
       //  un point (x,y) on trouve ses trois
       //  coordonnees bary a partir de
       //
       //
       //    | X |   |  Coeff P1
       //  M | Y | = |  Coeff P2
       //    | 1 |   |  Coeff P3
       //

        ElMatrix<double>  MatCoeffBarry() const;


        Pt3dr  CoordBarry(const Pt2dr &) const;
        Pt2dr  FromCoordBarry(double_t,double_t,double_t) const;

        static void Test();

        const SegComp & S01() const;
        const SegComp & S12() const;
        const SegComp & S20() const;

            // Est ce que ordre trigo
        static bool ToSwap(const Pt2dr & aP0,const  Pt2dr & aP1,const Pt2dr & aP2);
    private :
        static SegComp ReorderDirect(Pt2dr & aP0, Pt2dr & aP1,Pt2dr & aP2);
        SegComp mS01;
        SegComp mS12;
        SegComp mS20;


};


template <class Type> class Mat_Inertie
{
     public  :

       Mat_Inertie();
       Mat_Inertie
       (
               typename Type::TypeScal S,
               typename Type::TypeEff  S1,
               typename Type::TypeEff  S2,
               typename Type::TypeScal S11,
               typename Type::TypeScal S12,
               typename Type::TypeScal S22
       )
          :
               _s     (S),
               _s1    (S1),
               _s2    (S2),
               _s11   (S11),
               _s12   (S12),
               _s22   (S22)
       {
       }

       void add_pt_en_place( typename Type::TypeEff v1,  typename Type::TypeEff v2)
       {
            _s   += 1;
            _s1  += v1;
            _s2  += v2;
            _s11 += scal(v1,v1);
            _s12 += scal(v1,v2);
            _s22 += scal(v2,v2);
       }

       void add_pt_en_place
           (
                typename Type::TypeEff v1,
                typename Type::TypeEff v2,
                typename Type::TypeScal pds
            )
       {
            _s   += pds;
            _s1  += v1 *pds;
            _s2  += v2 *pds;
            _s11 += scal(v1,v1) *pds;
            _s12 += scal(v1,v2) *pds;
            _s22 += scal(v2,v2) *pds;
       }


        typename Type::TypeScal    s()    const {return _s;}
        typename Type::TypeEff     s1()   const {return _s1;}
        typename Type::TypeEff     s2()   const {return _s2;}
        typename Type::TypeScal    s11()  const {return _s11;}
        typename Type::TypeScal    s12()  const {return _s12;}
        typename Type::TypeScal    s22()  const {return _s22;}


       Mat_Inertie  plus_cple
                    (
                       typename Type::TypeEff v1,
                       typename Type::TypeEff v2,
                       typename Type::TypeScal pds =1
                    ) const
       {
            return Mat_Inertie
                   (
                       _s   + pds,
                       _s1  +  v1 * pds,
                       _s2  +  v2 * pds,
                       _s11 +  scal(v1,v1) * pds,
                       _s12 +  scal(v1,v2) * pds,
                       _s22 +  scal(v2,v2) * pds
                   );
       }

       Mat_Inertie operator - (const Mat_Inertie &) const;
       void operator += (const Mat_Inertie &);


            // renvoie la droite au moinde carre, point initial = cdg;
            // second point (indertermine a pi pres) situe a dun distance norm


       Mat_Inertie< typename Type::TypeReel>  normalize() const
       {
             ELISE_ASSERT
             (
                  _s != 0,
                  "som pds = 0 in Mat_Inertie::normalize"
             );

              typename Type::TypeReel::TypeEff  S1 =  _s1 / (double_t) _s;
              typename Type::TypeReel::TypeEff  S2 =  _s2 / (double_t) _s;


#if ( ELISE_windows & ELISE_MinGW )
    return Mat_Inertie<typename Type::TypeReel>
#else
    return Mat_Inertie<typename Type::TypeReel>
#endif
                    (
                         _s,
                         S1,
                         S2,
                         _s11/(double_t)_s  -scal(S1,S1),
                         _s12/(double_t)_s  -scal(S1,S2),
                         _s22/(double_t)_s  -scal(S2,S2)
                    );
       }

       double_t  correlation(double_t epsilon = 1e-14)
       {
           #if ( ELISE_windows & ELISE_MinGW )
             Mat_Inertie<typename  Type::TypeReel> m =  normalize();
           #else
             Mat_Inertie<typename  Type::TypeReel> m =  normalize();
           #endif
             return m.s12() / sqrt(ElMax(epsilon,m.s11()*m.s22()));
       }

       double_t  correlation_with_def(double_t aDef)
       {
            #if ( ELISE_windows & ELISE_MinGW )
              Mat_Inertie<typename  Type::TypeReel> m =  normalize();
            #else
              Mat_Inertie<typename  Type::TypeReel> m =  normalize();
            #endif
         if ((m.s11()<=0) || (m.s22() <=0)) return aDef;
             return m.s12() / sqrt(m.s11()*m.s22());
       }



       typename Type::TypeScal S0() const {return _s;}
       typename Type::TypeReel::TypeEff  V2toV1(const typename Type::TypeReel::TypeEff & aV2,double_t epsilon = 1e-14);
       typename Type::TypeReel::TypeEff  V1toV2(const typename Type::TypeReel::TypeEff & aV2,double_t epsilon = 1e-14);


    private :


           typename Type::TypeScal         _s;
           typename Type::TypeEff          _s1;
           typename Type::TypeEff          _s2;
           typename Type::TypeScal         _s11;
           typename Type::TypeScal         _s12;
           typename Type::TypeScal         _s22;
};

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



class EventInterv
{
     public :
       EventInterv(double_t absc,bool entr);
       double_t absc() const;
       bool entr() const;
       EventInterv();

     private :
       double_t    _absc;
       bool    _entr;
};

class PileEvInterv
{
      public :

        void add_ev(EventInterv);
        void clear();
        void sort_ev();

        ElFilo<EventInterv> & events();

      private :

        ElFilo<EventInterv> _events;
};


class  IntervDisjoint
{
      public :

            const ElFilo<Interval>  & intervs() {return _intervs;};

            void init(PileEvInterv &);
            IntervDisjoint(PileEvInterv &);
            IntervDisjoint();


      private :

            ElFilo<Interval>  _intervs;
};



/*****************************************************************/
/*                                                               */
/*        Classes pour QTree                                     */
/*                                                               */
/*****************************************************************/

class ElQTRegionPlan
{
      public :

         virtual double_t D2(const Box2dr &) const = 0;
         virtual double_t D2(const Pt2dr &)  const = 0;
         virtual double_t D2(const SegComp &)  const = 0;
         virtual double_t D2(const cElTriangleComp &)  const ; // Def = err fatale
     virtual ~ElQTRegionPlan() {}
};


class ElQTRegPt : public ElQTRegionPlan
{
      public :

         virtual double_t D2(const Box2dr &)  const ;
         virtual double_t D2(const Pt2dr & )  const ;
         virtual double_t D2(const SegComp &)  const;
         virtual double_t D2(const cElTriangleComp &)  const ; // Implantee

         ElQTRegPt (Pt2dr);
     virtual ~ElQTRegPt() {}

      private :

          Pt2dr _pt;
};

class ElQTRegSeg : public ElQTRegionPlan
{
      public :

         virtual double_t D2(const Box2dr &)  const ;
         virtual double_t D2(const Pt2dr & )  const ;
         virtual double_t D2(const SegComp &)  const;

         ElQTRegSeg (Seg2d);
     virtual ~ElQTRegSeg() {}
      private :

          SegComp _seg;
};

class ElQTRegBox : public ElQTRegionPlan
{
      public :

         virtual double_t D2(const Box2dr &)  const ;
         virtual double_t D2(const Pt2dr & )  const ;
         virtual double_t D2(const SegComp &)  const;
         ElQTRegBox (const Box2dr &box);
     virtual ~ElQTRegBox() {}
      private :

          Box2dr _box;
};






class ElQdtGen
{
      public  :

          int NbObjMax() const { return _NbObjMax;}
          int SzMin()    const { return _SzMin;}

      protected :

          ElQdtGen
          (
                     Box2dr        box,
                     int           NbObjMax,
                     double_t          SzMin
          );


          Box2dr                        _box;
          int                           _NbObjMax;
          int                           _SzMin;

     private :
          static Box2dr BoxQdt(const Box2dr &);

};


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
};



class ElSeg3D
{
     public :
         ElSeg3D(Pt3dr aP0,Pt3dr aP1);

          Pt3dr  Tgt() const;
          Pt3dr  TgNormee() const;
          Pt3dr  ProjOrtho(Pt3dr aP0) const;  // A la droite
          double_t   DistDoite(Pt3dr aP0) const;
          Pt3dr  PtOfAbsc(double_t anAbsc) const;
          double_t   AbscOfProj(Pt3dr aP) const;


          static ElSeg3D  CombinL1(const std::vector<Pt3dr> & aV);
          static ElSeg3D  CreateL2(const std::vector<Pt3dr> & aV);
          double  SomDistDroite(const std::vector<Pt3dr> & aV) const;

          void   AbscissesPseudoInter(double_t &anAbsc1,double_t & anAbsc2,const ElSeg3D & aS2);

          Pt3dr  PseudoInter(const ElSeg3D & aS2);



          void   Projections(Pt3dr & Proj2On1,const ElSeg3D & aS2,Pt3dr & Proj1On2);

          Pt3dr P0() const;
          Pt3dr P1() const;

      static Pt3dr L2InterFaisceaux
                   (
                           const std::vector<double> *,
                           const std::vector<ElSeg3D> &aVS,
                           bool * aOK=0,
                           const cRapOnZ *      aRAZ = 0,
                           cResOptInterFaisceaux * = 0,
                           const std::vector<Pt3dr> *  aVPts =0// Si existe doit etre pair et c'est une alternance pts/inc
               );
     private :

         Pt3dr mP0;
         Pt3dr mP1;
         Pt3dr mTN;
};

class cElPlan3D
{
      public :
          // Peu importe P0,P1,P2 du moment
          // qu'ils definissent le meme plan
          cElPlan3D(Pt3dr aP0,Pt3dr aP1,Pt3dr aP2);

              // Plan au moindre carres; si Pds=0 -> Pds[aK] = 1
              cElPlan3D(const std::vector<Pt3dr> &,const std::vector<double>*,ElSeg3D * aBestSeg=0);

          Pt3dr Inter(const cElPlan3D&,const cElPlan3D &,bool &OK) const;
          Pt3dr Inter(const ElSeg3D &,bool *OK=0) const;
              ElSeg3D Inter(const cElPlan3D&,bool &OK) const;

          // Plante si Plan Vertical
          double_t   ZOfXY(Pt2dr aP) const;
          Pt3dr  AddZ(Pt2dr aP) const;

             // void L1Ameliore(const std::vector<Pt3dr> & aVP,int aNbMax=-1);
             ElRotation3D CoordPlan2Euclid();
             const Pt3dr & Norm() const;
             const Pt3dr & U() const;
             const Pt3dr & V() const;
             const Pt3dr & P0() const;

             Pt3dr Proj(const Pt3dr &) const;

             void NoOp();

             void Revert() ;   // Z => -Z
      private :
          // Le plan est donne par son equation normale
          // mScal + mNorm.P = 0
          Pt3dr mNorm;
          double_t mScal;
          Pt3dr mP0;
          Pt3dr mU;
          Pt3dr mV;
};


/*
class cInterfSystemeCoordonne3D
{
     public :

         virtual Pt3dr ToEuclid(const Pt3dr & aP) const = 0;
         virtual Pt3dr FromEuclid(const Pt3dr & aP) const = 0;
     public :
};
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

class cMailageSphere
{
    public :
        cMailageSphere(Pt2dr,Pt2dr,Pt2dr,bool Inv);
        void SetStep(Pt2dr);
        void SetMax(Pt2dr);
        void SetMin(Pt2dr);

        Pt2dr Pix2Spherik(Pt2dr aIndTP);
        Pt2di Spherik2PixI(Pt2dr  aTetaPhi);
        Pt2dr Spherik2PixR(Pt2dr  aTetaPhi);

        Pt2di SZEnglob();
        void WriteFile(const std::string & aNameFile);
        static cMailageSphere FromFile(const std::string & aNameFile);

        Pt3dr DirMoy();
        Pt2dr DirMoyH();

    private :
        Pt2dr mStep;  // Teta ,Phi
        Pt2dr mMin;
        Pt2dr mMax;
        int   mInv;
};

class cGridNuageP3D
{
    public :
            cGridNuageP3D
        (
             const std::string &,
         Pt2di aSz = Pt2di(-1,-1), // Def => Tiff.sz()
         Pt2di aP0 = Pt2di(0,0)
            );
        Pt2di Sz() const;
        int   Cpt(Pt2di) const;
        Pt3dr P3D(Pt2di) const;

        std::string NameShade() const;
        Im2D_U_int1   ImShade();
        Im2D_int1     ImCpt();

        // Profondeur dans la direction moyenne
        Fonc_Num FProfDMoyH();

        Tiff_Im   TifFile(const std::string & aShortName);
    private :
        static const std::string theNameShade;
        void Init(Im2DGen,const std::string &);

        std::string   mName;
        Pt2di         mSz;
        Pt2di         mP0;

        Im2D_double_t4    mImX;
        double_t4 **      mDX;
        Im2D_double_t4    mImY;
        double_t4 **      mDY;
        Im2D_double_t4    mImZ;
        double_t4 **      mDZ;
        Im2D_int1     mImCpt;
        Im2D_U_int1   mImShade;
        cMailageSphere  mMSph;
};


class cQtcElNuageLaser;
class cResReqNuageLaser
{
   public :
     virtual void cResReqNuageLaser_Add(const Pt3dr & aP) = 0;
   virtual ~cResReqNuageLaser() {}
};

class cElNuageLaser
{
     public  :

       typedef enum
       {
            eConvId,
            eConvCarto2Terr,
            eConvCarto2TerIm
       } eModeConvGeom;
       cElNuageLaser
       (
              const std::string & aNameFile,
              const char *  aNameOri = NULL,
              const char *  aNameGeomCible = NULL,  // GeomCarto GeomTerrain GeomTerIm1
              const char *  aNameGeomInit = "GeomCarto"
       );
       const std::vector<Pt3dr> & VPts() const;
       void SauvCur(const std::string &);
       void Debug(const std::string & aName);


       double_t   ZMin () const;
       double_t   ZMax () const;
       Box2dr Box() const;

       void  AddQt(int aNbObjMaxParFeuille,double_t aDistPave);

       void ParseNuage(cResReqNuageLaser & aResParse,Box2dr aBox);

     private :
       cElNuageLaser(const cElNuageLaser &);  // Non Implemente

       std::vector<Pt3dr>  mVPts;

       double_t                mZMax;
       double_t                mZMin;
       Pt2dr               mPInf;
       Pt2dr               mPSup;
       cQtcElNuageLaser *  mQt;
};


struct gpc_polygon;

class cElPolygone
{
    public :
       typedef std::vector<Pt2dr> tContour;
       typedef const std::list<tContour>  tConstLC;
       typedef std::list<tContour>::const_iterator  tItConstLC;

       void AddContour(const tContour &,bool isHole);
       cElPolygone();
       cElPolygone (const gpc_polygon &);
       struct gpc_polygon ToGPC() const;

       const std::list<tContour> & Contours() const;
       const std::list<bool> &     IsHole();
       tContour  ContSMax() const;


       cElPolygone operator * (const cElPolygone & aPol)  const;
       cElPolygone operator + (const cElPolygone & aPol)  const;
       cElPolygone operator - (const cElPolygone & aPol)  const;
       cElPolygone operator ^ (const cElPolygone & aPol)  const;

       double Surf() const;
       double DiamSimple() const;  // Suppose que existe surf englob

    private  :
       cElPolygone GenOp(const cElPolygone & aPol,int)const;

       std::list<tContour>   mContours;
       std::list<bool>       mIsHole;
};


// Representation maillee d'un nuage de points 3D



/*
*/

#endif // _ELISE_GENERAL_GEOM_VECTEUR_H

