#ifndef _ELISE_GENERAL_FILE_IM_GIF_IM_H
#define _ELISE_GENERAL_FILE_IM_GIF_IM_H



class Gif_Im : public ElGenFileIm
{
    friend class Data_Giff;
    friend class Data_GifIm;
    friend class Gif_Im_Not_Comp;
    friend void instatiate_liste();

public :
    Gif_Im(const char * name);
    Im2D_U_int1     im();
    Disc_Pal              pal();
    Fonc_Num              in();
    Fonc_Num              in(int);
    Pt2di                 sz();

    static  Output create  (
            const char *             name,
            Pt2di              sz,
            Elise_colour *     tec,
            int                nbb
            );


private :
    Gif_Im(const char * name,class ELISE_fp fp,class Data_Giff *gh);
    Gif_Im(Data_GifIm *);
#ifndef _ELISE_GENERAL_FILE_IM_DATA_GIFIM_H
#define _ELISE_GENERAL_FILE_IM_DATA_GIFIM_H



    class Data_GifIm * dgi()
    { return SAFE_DYNC(class Data_GifIm *,_ptr);}

};

#endif
