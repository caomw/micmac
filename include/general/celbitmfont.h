#ifndef _ELISE_GENERAL_BITM_CELBITMFONT_H
#define _ELISE_GENERAL_BITM_CELBITMFONT_H



class cElBitmFont
{
    public :
       static  cElBitmFont & BasicFont_10x8();
       virtual Im2D_Bits<1> ImChar(char) = 0;
       virtual ~cElBitmFont();
    private :
      static class cElImplemBitmFont * theFont_10x8;
};

#endif
