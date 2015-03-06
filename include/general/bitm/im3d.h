#ifndef _ELISE_GENERAL_BITM_IM3D_H
#define _ELISE_GENERAL_BITM_IM3D_H

#include "general/sys_dep.h"

template <class Type,class TyBase> class Im3D : public GenIm
{
   public :
      Im3D(int tx,int ty,int tz);
      Im3D(int tx,int ty,int tz,TyBase v_init);
      Im3D(int tx,int ty,int tz,const char * v_init);

      Im3D(Im3D_WithDataLin,int tx,int ty,int tz,Type *);
      Type ***    data();
      int     tx() const;
      int     ty() const;
      int     tz() const;
      int  vmax() const;
   private :
};

#endif
