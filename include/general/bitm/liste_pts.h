#ifndef _ELISE_GENERAL_BITM_LISTE_PTS_H
#define _ELISE_GENERAL_BITM_LISTE_PTS_H



template <class Type,class Type_Base> class Liste_Pts : public Liste_Pts_Gen
{
     public :
        Liste_Pts(int dim);
        Liste_Pts(int dim,Type **,int nb);
        Liste_Pts(Type * x,Type * y,int nb);
        Im2D<Type,Type_Base>  image() const;
        void add_pt(Type *);
    private :
        Data_Liste_Pts<Type,Type_Base> * dlpt() const;
};

#endif
