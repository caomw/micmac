#ifndef _ELISE_GENERAL_FILE_IM_GIF_FILE_H
#define _ELISE_GENERAL_FILE_IM_GIF_FILE_H

#include "general/sys_dep.h"

class Gif_File : public PRC0
{
public :
    Gif_File(const char * name);

    INT      nb_im   ()        const;
    Gif_Im   kth_im  (INT)     const;


private :
#ifndef _ELISE_GENERAL_FILE_IM_DATA_GIFF_H
#define _ELISE_GENERAL_FILE_IM_DATA_GIFF_H

#include "general/sys_dep.h"

    class Data_Giff * dgi() const
    {return SAFE_DYNC(Data_Giff *,_ptr);}
};

#endif
