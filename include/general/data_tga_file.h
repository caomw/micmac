#ifndef _ELISE_GENERAL_FILE_IM_TGA_IM_H
#define _ELISE_GENERAL_FILE_IM_TGA_IM_H



class  Tga_Im : public PRC0
{
    friend class Tga_Im_Not_Comp;
public :

    typedef enum
    {
        col_maped = 0,
        true_col  = 1,
        bw_image  = 2
    } type_of_image;

    typedef enum
    {
        no_compr,
        rle_compr
    } mode_compr;






    Tga_Im(const char * name);
    Fonc_Num              in();
    Fonc_Num              in(int);

    bool                im_present() const;
    type_of_image       toi()        const;


private :
#ifndef _ELISE_GENERAL_FILE_IM_DATA_TGA_FILE_H
#define _ELISE_GENERAL_FILE_IM_DATA_TGA_FILE_H



    class Data_TGA_File * dtga() const
    {return SAFE_DYNC(Data_TGA_File *,_ptr);}
};

#endif
