#ifndef _ELISE_GENERAL_BITM_TEMPLATE_H
#define _ELISE_GENERAL_BITM_TEMPLATE_H

#include "general/sys_dep.h"

template  <const int nbb> Im2D_Bits<nbb>::Im2D_Bits(INT tx,INT ty) :
        Im2DGen(new DataIm2D_Bits<nbb>(tx,ty,false,0,0))
{
}


typedef enum
{
   eModeBilin,
   eModeBicub
} eModeInterp;

#ifndef _ELISE_GENERAL_BITM_TIN>_H
#define _ELISE_GENERAL_BITM_TIN>_H

#include "general/sys_dep.h"

template <class TOut,class TIn>
#ifndef _ELISE_GENERAL_BITM_CCHCOORD_H
#define _ELISE_GENERAL_BITM_CCHCOORD_H

#include "general/sys_dep.h"

class cChCoord
{
   public :
     static void DoIt
                 (
                   const ElDistortion22_Gen & aDist,
                   TOut aImOut,Im2D_Bits<1> aMasqOut,
                   TIn aImIn,Im2D_Bits<1> aMasqIn,
                   eModeInterp            aMode,
                   REAL aFact
                 );
};

#endif
