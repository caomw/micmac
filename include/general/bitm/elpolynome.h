#ifndef _ELISE_GENERAL_BITM_ELPOLYNOME_H
#define _ELISE_GENERAL_BITM_ELPOLYNOME_H

#include "general/sys_dep.h"

template <class Type>  class ElPolynome
{
     public :
          friend  ElPolynome<Type> operator *<Type> (const Type &,const ElPolynome<Type> &) ;
          ElPolynome<Type> operator * (const Type &) const;
          ElPolynome<Type> operator * (const ElPolynome<Type> &) const;
          ElPolynome<Type> operator + (const ElPolynome<Type> &) const;
          ElPolynome<Type> operator - (const ElPolynome<Type> &) const;

          void self_deriv() ;
          ElPolynome deriv() const;

          Type  operator()(const Type &) const;
          Type &  operator[](int k);
          const Type &  operator[](int k) const;
          Type   at(int k) const;  // def = 0
          INT degre() const {return (int) _coeff.size()-1;}

          ElPolynome();
          ElPolynome(char *,INT degre);  // Arg 1 : bidon, pour eviter
                                         // confusion avec ElPolynome(INT)
          ElPolynome(const Type &);
          ElPolynome(const Type &,const Type &);
          ElPolynome(const Type &,const Type &,const Type &);

          static ElPolynome FromRoots(const std::vector < Type > &);
          static ElPolynome FromRoots(const Type&);
          static ElPolynome FromRoots(const Type&,const Type&);
          static ElPolynome FromRoots(const Type&,const Type&,const Type&);
          static ElPolynome FromRoots(const Type&,const Type&,const Type&,const Type&);
      friend void Reduce(ElPolynome<REAL> &); // Supprime les coeffs de degre haut nuls

     private :
          std::vector<Type> _coeff;
      static const Type  El0;
      static const Type  El1;
};

#endif
