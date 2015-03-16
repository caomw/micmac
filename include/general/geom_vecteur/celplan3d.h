#ifndef _ELISE_GENERAL_GEOM_VECTEUR_CELPLAN3D_H
#define _ELISE_GENERAL_GEOM_VECTEUR_CELPLAN3D_H



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

#endif
