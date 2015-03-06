#ifndef _ELISE_GENERAL_BITM_TYPEOUT>_H
#define _ELISE_GENERAL_BITM_TYPEOUT>_H

#include "general/sys_dep.h"

template <class TypeIn,class TypeOut> TypeOut Conv2Type(TypeIn anImIn,TypeOut * )
{
   Pt2di aSz = anImIn.sz();
   TypeOut aRes(aSz.x,aSz.y);
   ELISE_COPY(anImIn.all_pts(),anImIn.in(),aRes.out());
   return aRes;
}



#ifndef _ELISE_GENERAL_BITM_TYPE_BASE>_H
#define _ELISE_GENERAL_BITM_TYPE_BASE>_H

#include "general/sys_dep.h"

template <class Type,class Type_Base> Im2D<Type,Type_Base> ImMediane
                                      (
                                           const std::vector<Im2D<Type,Type_Base> > &,
                                           Type_Base VaUnused ,
                                           Type      ValDef,   // Si tous unused
                                           double    aTol
                                      );

template  <class Type,class Type_Base> class  TIm2D;

Flux_Pts to_flux(Im2D<int,int> );
Flux_Pts to_flux(Im2D<double_t,double_t> );

template <const int nbb> class DataIm2D_Bits;

class Im2D_BitsIntitDataLin{};

#ifndef _ELISE_GENERAL_BITM_IM2D_BITS_H
#define _ELISE_GENERAL_BITM_IM2D_BITS_H

#include "general/sys_dep.h"

template <const int nbb> class Im2D_Bits : public Im2DGen
{
     friend class DataIm2D_Bits<nbb>;
   public :
      Seg2d   OptimizeSegTournantSomIm
              (
                    double_t &                 score,
                    Seg2d                  seg,
                    int                    NbPts,
                    double_t                   step_init,
                    double_t                   step_limite,
                    bool                   optim_absc  = true,
                    bool                   optim_teta  = true,
                    bool  *                FreelyOpt = 0
              );


      double Val(const int & x,const int & y) const;
      void SetI(const Pt2di & ,int aValI) ;
      void SetR(const Pt2di & ,double aValR) ;
      int     GetI(const Pt2di &) const ;
      double  GetR(const Pt2di &) const ;
      int     tx() const;
      int     ty() const;
      Im2D_Bits(Im2D_BitsIntitDataLin,int tx, int ty,void * aDataLin);
      Im2D_Bits(int tx, int ty);
      Im2D_Bits(int tx, int ty,int v_init);
      Im2D_Bits(Pt2di pt, int v_init);
      int  vmax() const;
      U_int1 **   data();
      U_int1 **   data() const;
      int    get(int x,int y) const;
      int    get_def(int x,int y,int v) const;
      void   set(int x,int y,int v);
      void   SetAll(int);

      Im2D<U_int1,int>  gray_im_red(int & zoom);
      Im2DGen  *ImOfSameType(const Pt2di & aSz) const;
   private :
       Im2D_Bits(DataIm2D_Bits<nbb> *);
       inline DataIm2D_Bits<nbb> * didb() const;
};

#endif
