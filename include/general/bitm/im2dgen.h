#ifndef _ELISE_GENERAL_BITM_IM2DGEN_H
#define _ELISE_GENERAL_BITM_IM2DGEN_H

#include <Im1D>
#include <GenIm>
#include <cFoncI2D>
#include <Neigh_Rel>
#include <Neighbourhood>

class Im2DGen : public GenIm,
                public cFoncI2D
{
    public :
      Neigh_Rel neigh_test_and_set(Neighbourhood,Im1D<int,int> sel,Im1D<int,int> update);
      Neigh_Rel neigh_test_and_set(Neighbourhood,int sel,int udpate,int v_max);

      // the list of point is considered as a list of couple of value :
      //   x => values to select, y => udpating of x
      Neigh_Rel neigh_test_and_set(Neighbourhood,ElList<Pt2di>,int v_max);

      virtual ~Im2DGen();
      virtual  GenIm::type_el TypeEl() const ;

      virtual Seg2d   OptimizeSegTournantSomIm
              (
                    double_t &                 score,
                    Seg2d                  seg,
                    int                    NbPts,
                    double_t                   step_init,
                    double_t                   step_limite,
                    bool                   optim_absc  = true,
                    bool                   optim_teta  = true,
                    bool  *                FreelyOpt = 0
              )  ;

      // DEF = erreur fatale, mais necessaire pou creer des Im2DGen
      virtual int     tx() const ;
      virtual int     ty() const ;
      Pt2di sz() const {return Pt2di(tx(),ty());}
      Box2di ImBox2d() const  {return Box2di(Pt2di(0,0),sz());}
      Box2di ImBox2d(int Brd) const {return Box2di(Pt2di(Brd,Brd),Pt2di(tx()-Brd,ty()-Brd));}

      virtual void TronqueAndSet(const Pt2di &,double aVal);
      virtual double  MoyG2() const ; // Grad au carre
      virtual int  vmax() const ;
      virtual int  vmin() const ;
      virtual cIm2DInter * BilinIm() ;
      virtual cIm2DInter * BiCubIm(double aCoef,double aScale=1.0) ;

      virtual void SetI(const Pt2di & ,int aValI) ;
      virtual void SetR(const Pt2di & ,double aValR) ;
      void SetI_SVP(const Pt2di & ,int aValI) ;
      void SetR_SVP(const Pt2di & ,double aValR) ;

      virtual int     GetI(const Pt2di & ) const ;
      virtual double  GetR(const Pt2di  &) const ;
      void AssertInside(const Pt2di &) const;
      bool  Inside(const Pt2di &) const;
      int     GetI(const Pt2di&,int ) const ;
      double  GetR(const Pt2di&,double ) const ;
      // Pas def pour les ImBits
      virtual void PutData(FILE * aFP,const Pt2di & anI,bool aModeBin) const;

      virtual Im2DGen * ImOfSameType(const Pt2di & aSz) const;
      virtual Im2DGen * ImRotate(int aRot ) const;  // aRot = (1,0) , (0,1), (-1,0), (0,-1)


       Box2di BoxDef() const ;
       double Val(const int & x,const int & y) const;
      virtual  void Resize(Pt2di aSz);  // Pas definie pour ImBits

    protected :
      Im2DGen(DataGenIm *);
      DataGenIm * DGI()const;
};

#endif
