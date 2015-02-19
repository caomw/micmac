#ifndef _ELISE_GENERAL_GEOM_VECTEUR_SEGCOMP_H
#define _ELISE_GENERAL_GEOM_VECTEUR_SEGCOMP_H

#include "general/sys_dep.h"

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


        REAL ordonnee(Pt2dr pt) const;
        REAL ordonnee(Pt3dr pt) const;  // Point Projectif
        Fonc_Num ordonnee(Pt3d<Fonc_Num> pt) const;  // Point Projectif Formel
        REAL  abscisse(Pt2dr pt) const;

        REAL  abscisse_proj_seg(Pt2dr pt) const;  // clippee dans [0 lenght]
        REAL  recouvrement_seg(const Seg2d &) const;  // clippee dans [0 lenght]

        Pt2dr to_rep_loc(Pt2dr) const;
        Pt2dr from_rep_loc(Pt2dr) const;

        REAL  length()   const  {return _length;}
        Pt2dr tangente() const  {return _tangente;}
        Pt2dr normale()  const  {return _normale;}
        REAL  c()        const  {return _c;}

        bool in_bande(Pt2dr pt,ModePrim) const;

        bool BoxContains(Pt2dr pt,REAL DLong,REAL DLarg) const;
        bool BoxContains(const Seg2d & ,REAL DLong,REAL DLarg) const;

   //=========   DISTANCES   ==============

        REAL square_dist_droite(Pt2dr pt) const;
        REAL square_dist_demi_droite(Pt2dr pt) const;
        REAL square_dist_seg(Pt2dr pt) const;
        REAL square_dist(ModePrim  mode,Pt2dr   pt) const;

        REAL dist_droite(Pt2dr pt) const;
        REAL dist_demi_droite(Pt2dr pt) const;
        REAL dist_seg(Pt2dr pt) const;
        REAL dist(ModePrim  mode,Pt2dr   pt) const;

        REAL square_dist(ModePrim,const SegComp &,ModePrim) const;
        REAL dist(ModePrim,const SegComp &,ModePrim) const;

   //=========   DISTANCES DE HAUSSDORF   ==============

        // la 1ere primitive est tjs consideree comme un segment
        // (sinon Haussdorf = infini, hors paralellisme notoire)
        // dans les version assym, il s'agit de la dist du point de la premiere
        // le pus loin de la deuxieme.

        REAL  square_haussdorf_seg_assym(const SegComp &) const;
        REAL  square_haussdorf_seg_sym(const SegComp &) const;
        REAL  square_haussdorf_droite_assym(const SegComp &) const;

              // max de "square_haussdorf_droite_assym" dans
              // les 2 sens, donc pas vraiment une distance de haussdorf
              //  au sens mathematique du terme

        REAL  square_haussdorf_droite_sym(const SegComp &) const;

   //=========   PROJECTIONS   ==============

        Pt2dr  proj_ortho_droite(Pt2dr pt) const;
        Pt2dr  proj_ortho_demi_droite(Pt2dr pt) const;
        Pt2dr  proj_ortho_seg(Pt2dr pt) const;
        Pt2dr  proj_ortho(ModePrim,Pt2dr pt) const;
        Seg2d  proj_ortho(ModePrim,const SegComp &,ModePrim) const;

   //=========   INTERSECTION   ==============

        Pt2dr   inter(const SegComp &,bool &) const;  // droite
        Pt2dr   inter(ModePrim,const SegComp &,ModePrim,bool &) const;

        void inter_polyline
             (
                 ModePrim,
                 const ElFifo<Pt2dr> &,
                 ElFifo<INT>  &,   // index
                 ElFifo<Pt2dr> &   // resultats
             );

        static const Pt2dr NoPoint;
        std::vector<Seg2d> Clip(const std::vector<Pt2dr> &);

     protected :

        Pt2dr _tangente;
        REAL  _length;
        Pt2dr _normale;
        REAL  _c;
        REAL  _a1;   // abscisse p1, dans le repere de la droite

        REAL   _square_dist(ModePrim m1,const SegComp & s2,ModePrim m2) const;
        void   proj_ortho
               (
                   ModePrim,
                   const SegComp &,
                   ModePrim,
                   REAL & dmin,
                   Pt2dr & p0min,
                   Pt2dr & p1min
               ) const;

};

#endif
