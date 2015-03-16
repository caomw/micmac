#ifndef _ELISE_GENERAL_BITM_CTABIM2D_FROMIM2D_H
#define _ELISE_GENERAL_BITM_CTABIM2D_FROMIM2D_H



template <class TypeEl> class cTabIM2D_FromIm2D : public cInterpolateurIm2D<TypeEl>
{
     public :
         virtual double GetVal(TypeEl ** aTab,const Pt2dr &  aP) const ;
         virtual Pt3dr GetValDer(TypeEl ** aTab,const Pt2dr &  aP) const ;
         // SzKernel, a partir de l'arrondi inferieur, de combien
         // faut il dilater x, typiquement 1 pour bilin, 2 pour bicub
         //  1 pour PPV (car fait a partir de round_ni)
         virtual int  SzKernel() const;
         virtual ~cTabIM2D_FromIm2D();

          cTabIM2D_FromIm2D(const cKernelInterpol1D * ,int aNbDisc,bool aByBil);
   private :


          const cKernelInterpol1D*    mK0; // Debug
          cTabulKernelInterpol  mK1;
          int                   mSzK;



};

#endif
