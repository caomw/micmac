#ifndef _ELISE_GENERAL_BITM_TEMPLATE_H
#define _ELISE_GENERAL_BITM_TEMPLATE_H



template  <const int nbb> Im2D_Bits<nbb>::Im2D_Bits(int tx,int ty) :
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



template <class TOut,class TIn>
#ifndef _ELISE_GENERAL_BITM_CCHCOORD_H
#define _ELISE_GENERAL_BITM_CCHCOORD_H



class cChCoord
{
   public :
     static void DoIt
                 (
                   const ElDistortion22_Gen & aDist,
                   TOut aImOut,Im2D_Bits<1> aMasqOut,
                   TIn aImIn,Im2D_Bits<1> aMasqIn,
                   eModeInterp            aMode,
                   double_t aFact
                 );
};

#endif
