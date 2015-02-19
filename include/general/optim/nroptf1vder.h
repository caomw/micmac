#ifndef _ELISE_GENERAL_OPTIM_NROPTF1VDER_H
#define _ELISE_GENERAL_OPTIM_NROPTF1VDER_H

#include "general/sys_dep.h"

class NROptF1vDer : public NROptF1vND
{
     public :
          virtual REAL DerNRF1v(REAL) = 0;

          //+++++++++++++++++++++++++++
          // Brent search for minimum
          //+++++++++++++++++++++++++++


          //++++++++++++++++++++++++++++++++++++++++++++++++
          // Van Wijngaarden-Deker-Brent recherche de racines
          // en utilisant les derivees
          //++++++++++++++++++++++++++++++++++++++++++++++++
          REAL rtsafe(REAL ax,REAL bx,REAL tol,INT ITMAX=100);

     private :
          REAL PrivBrent  // Retourne la valeur de F au min
               (
                   REAL ax,REAL bx,REAL cx,
                   REAL tol,
                   REAL * xmin,  // retourne xmin
                   INT ITMAX=100
               );
};

#endif
