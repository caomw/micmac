#ifndef _ELISE_GENERAL_BITM_IM1D_H
#define _ELISE_GENERAL_BITM_IM1D_H

#include "general/sys_dep.h"

#include <GenIm>

template <class Type,class TyBase> class Im1D : public GenIm
{
   public :
      Type At(int aK) const;
      explicit Im1D(int tx);
      Im1D(int tx,TyBase v_init);
      Im1D(int tx,const char * v_init);
      Type *    data();
      const Type *    data() const;
      int     tx() const;
      int  vmax() const;
      void raz();
      void Resize(int aTx);

      // friend GenIm alloc_im1d(GenIm::type_el type_el,int tx,void * data);
      // premier parametre bidon, mais permet d'eviter des ambiguite
      // avec les syntaxes "standard"
      Im1D(Im1D<Type,TyBase> *,int tx,void * );
      Im1D<Type,TyBase>  AugmentSizeTo(int aTx,Type aValCompl = 0);
};

typedef Im1D<unsigned char,int>  Im1D_U_INT1;
typedef Im1D<char,int>    Im1D_INT1;
typedef Im1D<unsigned short,int>  Im1D_U_INT2;
typedef Im1D<short,int>    Im1D_INT2;
typedef Im1D<int,int>    Im1D_INT4;

typedef Im1D<float_t,double_t>  Im1D_REAL4;
typedef Im1D<double_t,double_t>  Im1D_REAL8;

#endif
