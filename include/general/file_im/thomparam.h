#ifndef _ELISE_GENERAL_FILE_IM_THOMPARAM_H
#define _ELISE_GENERAL_FILE_IM_THOMPARAM_H

#include "general/sys_dep.h"

class  ThomParam
{
public :
    ThomParam(const char * name_file);
    Elise_Tiled_File_Im_2D   file(const char * );

    //private :
    std::string ORIGINE,OBJECTIF,DATE,FORMAT;
    INT MAXIMG,MINIMG,mCOULEUR,mCAMERA;
    INT FOCALE,TDI,TAILLEPIX,NBCOL,NBLIG;
    std::string NOM;
    REAL EXPOTIME,DIAPHRAGME;
    INT OFFSET;
    std::string MERE;
    INT BLANC;
    INT BIDON;
    INT BYTEORD;
};

#endif
