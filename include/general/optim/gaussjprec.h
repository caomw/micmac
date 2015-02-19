#ifndef _ELISE_GENERAL_OPTIM_GAUSSJPREC_H
#define _ELISE_GENERAL_OPTIM_GAUSSJPREC_H

#include "general/sys_dep.h"

class GaussjPrec
{
      public :

          GaussjPrec(INT n,INT m);
          bool init_rec();
          void amelior_sol();
          REAL ecart() const;
          REAL ecart_inv() const;
          void set_size_nm(int n,int m);
          void set_size_m(int);

          ElMatrix<REAL> & M()     {return _M;}
          ElMatrix<REAL> & b()     {return _b;}
          ElMatrix<REAL> & Minv()  {return _Minv;}
          ElMatrix<REAL> & x ()    {return _x;}


          void SelfSetMatrixInverse(ElMatrix<REAL> & aM,INT aNbIter);

      private :

      // resoud _M * _x = _b
          void set_ecart();

          INT            _n;
          INT            _m;

          ElMatrix<REAL> _M;
          ElMatrix<REAL> _Minv;
          ElMatrix<REAL> _b;
          ElMatrix<REAL> _x;
          ElMatrix<REAL> _eps;
          ElMatrix<REAL> _ec;
};                

#endif
