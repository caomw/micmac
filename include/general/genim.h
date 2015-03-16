#ifndef _ELISE_GENERAL_BITM_GENIM_H
#define _ELISE_GENERAL_BITM_GENIM_H

#include <PRC0>
#include <Rectang_Object>

class GenIm : public PRC0 ,
              public Rectang_Object
{
    friend class Gen_Elise_File_Im_Comp;
    friend class B2d_Spec_Neigh_Not_Comp;
    friend class Std_Bitm_Fich_Im_2d;
    friend class TIFF_TAG_VALUE;
    friend class TAG_TIF;
    friend class Tiff_Tiles_Cpr;

    public :
        bool same_dim_and_sz(GenIm);

        virtual ~GenIm();

        typedef enum
        {
             u_int1,
             int1,
             u_int2,
             int2,
             int4,
             real4,
             real8,
             bits1_msbf,  // 1,2,4 bits; Most signifant first
             bits2_msbf,
             bits4_msbf,
             bits1_lsbf,  // 1,2,4 bits; Most signifant last
             bits2_lsbf,
             bits4_lsbf,

             real16,
             no_type    // to have some def value
        } type_el;

       // must be same size, use optimized if same type,
       // else use ELISE_COPY
       void load_file(class Elise_File_Im);

       virtual Elise_Rect box() const;
       Fonc_Num  in(void);
       Fonc_Num  in(double_t def_out);
       Fonc_Num  in_proj();  // prolongation by projection

    // oclip : output cliped, = ELISE select the points
    // inside the bitmap before writting

       Output    oclip(void);

    // out : the points are clipped with RLE flux of points (because
    // anyway it is cheap to do in this case) and not clipped
    // with others.

       Output    out(void);
       void * data_lin();
       const int * P1();


     //    sum_eg, .. ,mul_eg : just interface function to oper_ass_eg;
     //    histo : just a current name for sum_eg


          Output histo(bool auto_clip = false);
          Output sum_eg(bool auto_clip = false);
          Output max_eg(bool auto_clip = false);
          Output min_eg(bool auto_clip = false);
          Output mul_eg(bool auto_clip = false);
          Output oper_ass_eg(const OperAssocMixte & op,bool auto_clip);


          void read_data(class ELISE_fp & fp);
          void write_data(class ELISE_fp & fp) const;


    protected :
       GenIm(DataGenIm *);
    private :

       void tiff_predictor(int nb_el,int nb_ch,int max_val,bool codage);
       DataGenIm * data_im();
       const DataGenIm * data_im() const;


    // onotcl : probably a bd idea; do not supress it now but make it
    // private.
       Output    onotcl(void);

    // onotcl : output NOT cliped = ELISE does not select
    // the points. Faster when you are absolutely sure that
    // all the points are in fact in the bitmap. If this
    // happened to be false :
    //   - you'll got a fatale= error with DEBUG_USER actived
    //   - you'll  probably get a core dumped elsewhere.

};

#endif
