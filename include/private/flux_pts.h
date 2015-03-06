/*Header-MicMac-eLiSe-25/06/2007

    MicMac : Multi Image Correspondances par Methodes Automatiques de Correlation
    eLiSe  : ELements of an Image Software Environnement

    www.micmac.ign.fr


    Copyright : Institut Geographique National
    Author : Marc Pierrot Deseilligny
    Contributors : Gregoire Maillet, Didier Boldo.

[1] M. Pierrot-Deseilligny, N. Paparoditis.
    "A multiresolution and optimization-based image matching approach:
    An application to surface reconstruction from SPOT5-HRS stereo imagery."
    In IAPRS vol XXXVI-1/W41 in ISPRS Workshop On Topographic Mapping From Space
    (With Special Emphasis on Small Satellites), Ankara, Turquie, 02-2006.

[2] M. Pierrot-Deseilligny, "MicMac, un lociel de mise en correspondance
    d'images, adapte au contexte geograhique" to appears in
    Bulletin d'information de l'Institut Geographique National, 2007.

Francais :

   MicMac est un logiciel de mise en correspondance d'image adapte
   au contexte de recherche en information geographique. Il s'appuie sur
   la bibliotheque de manipulation d'image eLiSe. Il est distibue sous la
   licences Cecill-B.  Voir en bas de fichier et  http://www.cecill.info.


English :

    MicMac is an open source software specialized in image matching
    for research in geographic information. MicMac is built on the
    eLiSe image library. MicMac is governed by the  "Cecill-B licence".
    See below and http://www.cecill.info.

Header-MicMac-eLiSe-25/06/2007*/

#ifndef _ELISE_FLUX_PTS
#define _ELISE_FLUX_PTS

#include <general/sys_dep.h>
#include <private/garb_coll_tpl.h>

#include <Pt2d>

/*
      One of the major feature of the ELISE'lib is the generality of the
    set of point that can be manipulated.  The abstract data_type used
    to describe a set of points in general terms is "Flux_Pts_Compute".

       Logically a Flux_Pts_Compute is an iterator that return points.


*/



/***********************************************************/
/*                                                         */
/*   Packet of points                                      */
/*                                                         */
/***********************************************************/


/*
       For computation speed the Flux_Pts_Compute  do not describe their
    set points by points but by packet of point. A Pack_Of_Pts contains :

    * dim : dimension, ie dim=2 for the majority of still image
      application;

    * nb : number of points;

    * type_pck : describe how the packet is coded, it can have the following
      value :

             rle, for run line encoding, this the way surfacic set are
              described;

             integer for a set of point with integer coordinate where the
              rle coding is not appropriate;

             double_t  for a set of point with double_t coordinates;
*/


template <class Type> class Std_Pack_Of_Pts;
class   RLE_Pack_Of_Pts;
class   Std_Pack_Of_Pts_Gen;

class Pack_Of_Pts : public Mcheck
{
public :

    const RLE_Pack_Of_Pts * rle_cast () const
    {
        ASSERT_intERNAL(_type == rle,"RLE Convertion");
        return (const RLE_Pack_Of_Pts *) this;
    }

    const Std_Pack_Of_Pts_Gen * std_cast () const
    {
        ASSERT_intERNAL(_type != rle,"Std  Convertion");
        return (const Std_Pack_Of_Pts_Gen *) this;
    }

    const Std_Pack_Of_Pts<int> * std_cast (int *) const
    {
        ASSERT_intERNAL(_type == integer,"Std int Convertion");
        return (const Std_Pack_Of_Pts<int> *) this;
    }

    const Std_Pack_Of_Pts<double_t> * std_cast (double_t *) const
    {
        ASSERT_intERNAL(_type == double_t,"Std double_t Convertion");
        return (const Std_Pack_Of_Pts<double_t> *) this;
    }
    const Std_Pack_Of_Pts<double_t> * double_t_cast () const
    {
        return std_cast((double_t *) 0);
    }
    const Std_Pack_Of_Pts<int> * int_cast () const
    {
        return std_cast((int *) 0);
    }


    typedef enum type_pack
    {
        rle,
        integer,
        real
    }
    type_pack;

    static type_pack type_common(type_pack,type_pack);
    // return the type necessary to represent object
    // of both type in a  common one (+or-, max of type)

    inline int           nb(void) const {return _nb;};
    inline int          dim(void) const {return _dim;};
    inline int          pck_sz_buf(void) const {return _sz_buf;};
    inline int          not_full() const { return _nb < _sz_buf;}
    inline void         set_nb(int aNb) {_nb = aNb;};
    inline type_pack    type(void) const {return _type;};

    virtual  ~Pack_Of_Pts() ;
    virtual  void show (void) const =0; // debug purpose

    virtual  void show_kth (int k) const =0; // debug purpose

    virtual  void * adr_coord() const;

    virtual  void trans(const Pack_Of_Pts *, const int * tr) =0;
    static Pack_Of_Pts  * new_pck(int dim,int sz_buf,type_pack);

    // NEW convention !! the result is the arg.
    virtual void select_tab
    (Pack_Of_Pts * pck,const int * tab_sel) const =0;

    virtual Pack_Of_Pts * dup(int sz_buf = -1) const = 0;
    virtual void  copy(const Pack_Of_Pts *)  = 0;


    void convert_from(const Pack_Of_Pts *) ;
    virtual void  kth_pts(int *,int k) const = 0;

    virtual int   proj_brd
    (
            const Pack_Of_Pts * pck,
            const int * p0,
            const int * p1,
            int         rab
            ) =0;
protected :

    virtual void convert_from_rle(const RLE_Pack_Of_Pts *) ;
    virtual void convert_from_int(const Std_Pack_Of_Pts<int>  *) ;
    virtual void convert_from_double_t(const Std_Pack_Of_Pts<double_t>  *) ;

    Pack_Of_Pts (int dim,int _sz_buf,type_pack);
    int      _nb;
    const int      _dim;
    const int      _sz_buf;
    type_pack      _type;
};


class Curser_on_PoP : public Mcheck
{
public :

    virtual  Pack_Of_Pts * next()    =0;
    virtual  void re_start(const Pack_Of_Pts *) =0;
    virtual  ~Curser_on_PoP();
    static   Curser_on_PoP * new_curs(int dim,int sz_buf,Pack_Of_Pts::type_pack);

protected :
    Curser_on_PoP(int dim,int _sz_buf,Pack_Of_Pts::type_pack);
    int                       _dim;
    int                       _sz_buf;
    Pack_Of_Pts::type_pack    _type;
    int                       _nb_rest;

};



class RLE_Pack_Of_Pts : public Pack_Of_Pts
{
    friend class RLE_Curser_on_PoP;

public :
    virtual ~RLE_Pack_Of_Pts(void);
    virtual  void show (void) const ; // debug purpose
    virtual  void show_kth (int k) const; // debug purpose
    static RLE_Pack_Of_Pts  * new_pck(int dim,int sz_buf);
    void set_pt0(Pt2di);
    void set_pt0(const int *);

    inline int     & x0(){return _pt0[0];};
    inline int      vx0() const {return _pt0[0];};
    inline int     x1() const {return _pt0[0] + _nb;};
    inline int * pt0() const {return _pt0;};

    inline int y() const
    {
        ELISE_ASSERT(_dim>=2,"RLE_Pack_Of_Pts::y()");
        return _pt0[1];
    };


    // clip the pack of point in the box defined by p0 & p1;
    // the result, is the number of point supressed at the beginig
    // of segment;

    int   clip(const RLE_Pack_Of_Pts * pck,const int * p0,const int * p1);
    int   clip(const RLE_Pack_Of_Pts * pck,Pt2di p0,Pt2di p1);

    int   proj_brd
    (
            const Pack_Of_Pts * pck,
            const int * p0,
            const int * p1,
            int         rab
            );

    bool same_line(const RLE_Pack_Of_Pts *) const;


    // inside : boolean indicating if the set is inside the box
    bool   inside(const int * p0,const int * p1) const;
    void   Show_Outside(const int * p0,const int * p1) const;
    int   ind_outside(const int * p0,const int * p1) const;


    // following constant, a priori. used for "internally manipulated packs"
    // where size_buf is useless because pak is not exported,

    static const int _sz_buf_infinite ;
    virtual  void  trans(const Pack_Of_Pts *, const int * tr);
    virtual void select_tab
    (Pack_Of_Pts * pck,const int * tab_sel) const ;

    virtual Pack_Of_Pts * dup(int sz_buf = -1) const ;
    virtual void  copy(const Pack_Of_Pts *) ;
    virtual void  kth_pts(int *,int k) const;
private :
    RLE_Pack_Of_Pts (int dim,int sz_buf);
    int * _pt0;
    Tprov_int * _tpr;

};


/***********************************************************/
/*                                                         */
/*   Flux_Pts_Computed                                     */
/*                                                         */
/***********************************************************/

#include <Box2d>

class Flux_Pts_Computed : public Mcheck
{
    friend class Split_to_max_buf_rle;

public :
    virtual  bool   is_rect_2d(Box2di &);
    virtual  bool   is_line_map_rect();
    virtual  double_t   average_dist();  // to use only if is_line_map_rect -> True


    virtual const Pack_Of_Pts * next(void) = 0;
    virtual  ~Flux_Pts_Computed();
    inline int                          dim(void) const {return _dim;};
    inline  Pack_Of_Pts::type_pack     type(void) const {return _type;};
    inline int                       sz_buf(void) const {return _sz_buf;};
    inline bool integral_flux() const {return _type != Pack_Of_Pts::real;}

    Flux_Pts_Computed * convert(Pack_Of_Pts::type_pack) ;

    static void type_common(Flux_Pts_Computed **,Flux_Pts_Computed **);

protected :

    Flux_Pts_Computed(int dim,Pack_Of_Pts::type_pack type,int sz_buf);

private :
    const int                              _dim;
    const Pack_Of_Pts::type_pack           _type;
    const int                              _sz_buf;
};

class RLE_Flux_Pts_Computed : public Flux_Pts_Computed
{
public :
    static Flux_Pts_Computed * rect_2d_interface( Pt2di p0,
                                                  Pt2di p1,
                                                  int sz_buf
                                                  );

protected :
    virtual ~RLE_Flux_Pts_Computed();

    RLE_Flux_Pts_Computed(int dim,int sz_buf);
    RLE_Pack_Of_Pts * _rle_pack;
};

class RLE_Flux_Interface : public RLE_Flux_Pts_Computed
{
    friend Flux_Pts_Computed * flx_interface
    (int dim, Pack_Of_Pts::type_pack type,int sz_buf);
private :
    RLE_Flux_Interface(int dim,int sz_buf);
    virtual const Pack_Of_Pts * next();

};

class Arg_Flux_Pts_Comp
{
public :
    Arg_Flux_Pts_Comp() ;
    Arg_Flux_Pts_Comp(int SzBuf) ;
    inline int sz_buf()  const { return _sz_buf;}
private :
    int _sz_buf;

};

extern Flux_Pts_Computed *  split_to_max_buf
(
        Flux_Pts_Computed *,
        const  Arg_Flux_Pts_Comp &   arg
        );


class Flux_Pts_Not_Comp  : public RC_Object
{    
public :
    virtual Flux_Pts_Computed * compute(const Arg_Flux_Pts_Comp &) = 0;
};



/**************************************************************/
/**************************************************************/
/**************************************************************/

template <class Type> void bitm_marq_line 
(Type ** im,int tx,int ty,Pt2di p1,Pt2di p2,int val);
template <class Type> void bitm_marq_line 
(Type ** im,int tx,int ty,Pt2di p1,Pt2di p2,int val,double_t width);



#endif /* !  _ELISE_FLUX_PTS */

