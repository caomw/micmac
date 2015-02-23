#ifndef _ELISE_GENERAL_BITM_IM1D_H
#define _ELISE_GENERAL_BITM_IM1D_H

#include "general/sys_dep.h"

#include <GenIm>

template <class Type,class TyBase> class Im1D : public GenIm
{
   public :
      Type At(int aK) const;
      explicit Im1D(INT tx);
      Im1D(INT tx,TyBase v_init);
      Im1D(INT tx,const char * v_init);
      Type *    data();
      const Type *    data() const;
      INT     tx() const;
      INT  vmax() const;
      void raz();
      void Resize(INT aTx);

      // friend GenIm alloc_im1d(GenIm::type_el type_el,int tx,void * data);
      // premier parametre bidon, mais permet d'eviter des ambiguite
      // avec les syntaxes "standard"
      Im1D(Im1D<Type,TyBase> *,INT tx,void * );
      Im1D<Type,TyBase>  AugmentSizeTo(INT aTx,Type aValCompl = 0);
};

typedef Im1D<U_INT1,INT>  Im1D_U_INT1;
typedef Im1D<INT1,INT>    Im1D_INT1;
typedef Im1D<U_INT2,INT>  Im1D_U_INT2;
typedef Im1D<INT2,INT>    Im1D_INT2;
typedef Im1D<INT4,INT>    Im1D_INT4;

typedef Im1D<REAL4,REAL>  Im1D_REAL4;
typedef Im1D<REAL8,REAL>  Im1D_REAL8;

#endif
