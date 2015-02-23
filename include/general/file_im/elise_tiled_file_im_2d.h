#ifndef _ELISE_GENERAL_FILE_IM_ELISE_TILED_FILE_IM_2D_H
#define _ELISE_GENERAL_FILE_IM_ELISE_TILED_FILE_IM_2D_H

#include "general/sys_dep.h"
#include "general/tiff_file_im.h"

#include <ElGenFileIm>
#include <GenIm>


class Elise_Tiled_File_Im_2D : public ElGenFileIm 
{

public :
    /* Use this constructor for :
       1- Declare a file from another compatible format;
       2- To specify the paramater of a file to create.
   */
    virtual ~Elise_Tiled_File_Im_2D();
    static const bool DefCLT         = false;
    static const bool DefChunk       = true;
    static const int  DefOffset0     = 0;
    static const bool DefCreate      = false;
    static const bool DefByteOrdered = true;

    Elise_Tiled_File_Im_2D
    (
            const char *     name                   ,
            Pt2di            sz                     ,
            GenIm::type_el   type                   ,
            INT              dim_out                ,
            Pt2di            sz_tiles               ,
            bool             clip_last_tile = DefCLT,         // false ,
            bool             chunk          = DefChunk,       // true  ,
            tFileOffset              offset_0       = DefOffset0,     // 0     ,
            bool             create         = DefCreate,      // false ,
            bool             byte_ordered   = DefByteOrdered  // true
            );

    Fonc_Num in();
    Fonc_Num in(REAL def_out);
    Output out();

    static Elise_Tiled_File_Im_2D HDR(const std::string & aNameHdr);
    static Elise_Tiled_File_Im_2D XML(const std::string & aNameHdr);
    static Elise_Tiled_File_Im_2D Saphir
    (const char * name_file,const char * name_header);
    static Elise_Tiled_File_Im_2D  sun_raster(const char *);
    static Elise_Tiled_File_Im_2D Thom (const char * name_file);

    Tiff_Im to_tiff();

private  :

    class DATA_Tiff_Ifd * dtifd();
};

#endif
