#ifndef _ELISE_GENERAL_FILE_IM_ELISE_FILE_IM_H
#define _ELISE_GENERAL_FILE_IM_ELISE_FILE_IM_H

#include "general/sys_dep.h"

#include <ElGenFileIm>
#include <GenIm>
#include <Elise_Tiled_File_Im_2D>

class Elise_File_Im : public ElGenFileIm 
{
    friend class DataGenIm;
    friend class Data_Elise_File_Im;

public :
    /* Use this constructor for :
       1- Declare a file from another compatible format;
       2- To specify the paramater of a file to create.
   */
    virtual ~Elise_File_Im();
    Elise_File_Im
    (
            const char *     name,
            INT        dim,        // 2 for usual images
            INT *      sz,         // tx,ty for usual images
            GenIm::type_el,        // U_INT1,INT ....
            INT        dim_out,    // 1 for gray level, 3 for RVB ...
            tFileOffset        offset_0,   // size of header to pass
            INT        _szd0 = -1,  // see just down
            bool       create = false      // if does not exist
            );


    // _szd0 : the "physical" size in first dim,  currently
    //        _szd0 = sz[0] and this  assumed when _szd0 is given
    //         the default values -1; however, it can differ
    //         for padding reason (for example, with a 1 bits images,
    //         padded for each line, we may have _szd0 = 16, when
    //         sz[0] = 13


    // to create a pnm,pgm,ppm file
    static Elise_File_Im pbm (const char *,Pt2di  sz,char ** comment = 0);
    static Elise_File_Im pgm (const char *,Pt2di  sz,char ** comment = 0);
    static Elise_File_Im ppm (const char *,Pt2di  sz,char ** comment = 0);


    // to open an alreaduy created  file
    static Elise_File_Im pnm(const char *);


    // for simple 1d-file
    Elise_File_Im
    (
            const char *     name,
            INT        sz,      // tx,ty for usual images
            GenIm::type_el,      // U_INT1,INT ....
            tFileOffset    offset_0 = 0,  // size of header to pass
            bool       create = false      // if does not exist
            );
    // for simple 2d-file
    Elise_File_Im
    (
            const char *     name,
            Pt2di       sz,      // tx,ty for usual images
            GenIm::type_el,      // U_INT1,INT ....
            tFileOffset    offset_0 = 0,  // size of header to pass
            bool       create = false      // if does not exist
            );

    // for simple 3d-file
    Elise_File_Im
    (
            const char *     name,
            Pt3di       sz,      // tx,ty for usual images
            GenIm::type_el,      // U_INT1,INT ....
            tFileOffset    offset_0 = 0,  // size of header to pass
            bool       create = false      // if does not exist
            );

    /* Use this constructor for a file created under Elise.
         Elise_File_Im(const char * name);
     */

    Fonc_Num in();
    Fonc_Num in(REAL);

    // Image file are, by default, always cliped when used as
    // output.
    Output out();

    // Use this if you really do not want cliping. BUT, be sure
    // that you do not get out of the file.
    Output onotcl();

    virtual Elise_Rect box() const;

    Elise_Tiled_File_Im_2D  to_elise_tiled(bool byte_ordered = true);
    Tiff_Im to_tiff(bool byte_ordered = true);

private  :

    Elise_File_Im(Data_Elise_File_Im *);

    static Elise_File_Im pnm
    (
            const char *,
            char **   comment,
            Pt2di  sz,
            GenIm::type_el,
            INT    dim,
            INT    mode_pnm
            );
    Data_Elise_File_Im * defi() const
    {
        return SAFE_DYNC(Data_Elise_File_Im *,_ptr);
    }
};

#endif
