#ifndef _ELISE_GENERAL_BITM_IM3D_H
#define _ELISE_GENERAL_BITM_IM3D_H

#include "general/sys_dep.h"

template <class Type,class TyBase> class Im3D : public GenIm
{
   public :
      Im3D(INT tx,INT ty,INT tz);
      Im3D(INT tx,INT ty,INT tz,TyBase v_init);
      Im3D(INT tx,INT ty,INT tz,const char * v_init);

      Im3D(Im3D_WithDataLin,INT tx,INT ty,INT tz,Type *);
      Type ***    data();
      INT     tx() const;
      INT     ty() const;
      INT     tz() const;
      INT  vmax() const;
   private :
};

#endif
