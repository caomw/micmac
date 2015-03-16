#ifndef _ELISE_GENERAL_BITM_IM2D_BITS_H
#define _ELISE_GENERAL_BITM_IM2D_BITS_H

#include <Seg2d>
#include <Im2D>
#include <Im2DGen>
#include <DataIm2D_Bits>

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
    unsigned char **   data();
    unsigned char **   data() const;
    int    get(int x,int y) const;
    int    get_def(int x,int y,int v) const;
    void   set(int x,int y,int v);
    void   SetAll(int);

    Im2D<unsigned char,int>  gray_im_red(int & zoom);
    Im2DGen  *ImOfSameType(const Pt2di & aSz) const;
private :
    Im2D_Bits(DataIm2D_Bits<nbb> *);
    inline DataIm2D_Bits<nbb> * didb() const;
};

typedef Im2D_Bits<1>	  Im2D_BIN;

Im2D_Bits<1> ReducCentered(Im2D_Bits<1>);
Im2D_Bits<1> MasqForInterpole(Im2D_Bits<1> aMasqInInit,eModeInterp aMode);

#endif
