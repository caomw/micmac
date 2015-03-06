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
    int MAXIMG,MINIMG,mCOULEUR,mCAMERA;
    int FOCALE,TDI,TAILLEPIX,NBCOL,NBLIG;
    std::string NOM;
    double_t EXPOTIME,DIAPHRAGME;
    int OFFSET;
    std::string MERE;
    int BLANC;
    int BIDON;
    int BYTEORD;
};

#endif
