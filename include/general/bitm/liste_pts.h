#ifndef _ELISE_GENERAL_BITM_LISTE_PTS_H
#define _ELISE_GENERAL_BITM_LISTE_PTS_H

#include "general/sys_dep.h"

template <class Type,class Type_Base> class Liste_Pts : public Liste_Pts_Gen
{
     public :
        Liste_Pts(INT dim);
        Liste_Pts(INT dim,Type **,INT nb);
        Liste_Pts(Type * x,Type * y,INT nb);
        Im2D<Type,Type_Base>  image() const;
        void add_pt(Type *);
    private :
        Data_Liste_Pts<Type,Type_Base> * dlpt() const;
};

#endif
