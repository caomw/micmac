#ifndef _ELISE_GENERAL_GEOM_VECTEUR_ELSEG3D_H
#define _ELISE_GENERAL_GEOM_VECTEUR_ELSEG3D_H



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

#endif
