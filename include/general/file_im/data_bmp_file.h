#ifndef _ELISE_GENERAL_FILE_IM_BMP_IM_H
#define _ELISE_GENERAL_FILE_IM_BMP_IM_H

#include "general/sys_dep.h"

class  Bmp_Im : public PRC0
{
    friend class Bmp_Im_Not_Comp;
    friend class Bmp_Out_Not_Comp;
public :


    typedef enum
    {
        col_maped,
        true_col
    } type_of_image;

    typedef enum
    {
        no_compr  = 0,
        rle_8bits = 1,
        rle_4bits = 2
    } mode_compr;

    Bmp_Im(const char * name);
    Output              out();
    Fonc_Num              in();
    Fonc_Num              in(int);
    int      bpp() const;   // bits per pixel
    Disc_Pal   pal() const ;  // error when bpp() == 24
    mode_compr  compr();
    Pt2di       sz();

    bool                im_present() const;
    // type_of_image       toi()        const;


private :
#ifndef _ELISE_GENERAL_FILE_IM_DATA_BMP_FILE_H
#define _ELISE_GENERAL_FILE_IM_DATA_BMP_FILE_H

#include "general/sys_dep.h"

    class Data_BMP_File * dbmp() const
    {return SAFE_DYNC(class Data_BMP_File *,_ptr);}
};

#endif
