/*Header-MicMac-eLiSe-25/06/2007

    MicMac : Multi Image Correspondances par Methodes Automatiques de Correlation
    eLiSe  : ELements of an Image Software Environnement

    www.micmac.ign.fr

   
    Copyright : Institut Geographique National
    Author : Marc Pierrot Deseilligny
    Contributors : Gregoire Maillet, Didier Boldo.
	Refactoring : Helio Chissini de Castro <helio@kde.org>

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

#ifndef _ELISE_GENERAL_PRIVATE_FLUX_PTS_PACK_OF_PTS_H
#define _ELISE_GENERAL_PRIVATE_FLUX_PTS_PACK_OF_PTS_H

#include <Mcheck>
#include <Std_Pack_Of_Pts_Gen>

#include "micmac_global.h"

class RLE_Pack_Of_Pts;
template <class Type> class Std_Pack_Of_Pts;

class Pack_Of_Pts : public Mcheck
{
public :

    const RLE_Pack_Of_Pts * rle_cast () const
    {
        ASSERT_INTERNAL(_type == rle,"RLE Convertion");
        return (const RLE_Pack_Of_Pts *) this;
    }

    const Std_Pack_Of_Pts_Gen * std_cast () const
    {
        ASSERT_INTERNAL(_type != rle,"Std  Convertion");
        return (const Std_Pack_Of_Pts_Gen *) this;
    }

    const Std_Pack_Of_Pts<int> * std_cast (int *) const
    {
        ASSERT_INTERNAL(_type == integer,"Std int Convertion");
        return (const Std_Pack_Of_Pts<int> *) this;
    }

    const Std_Pack_Of_Pts<double_t> * std_cast (double_t *) const
    {
        ASSERT_INTERNAL(_type == double_t,"Std double_t Convertion");
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

    inline int           nb(void) const {return _nb;}
    inline int          dim(void) const {return _dim;}
    inline int          pck_sz_buf(void) const {return _sz_buf;}
    inline int          not_full() const { return _nb < _sz_buf;}
    inline void         set_nb(int aNb) {_nb = aNb;}
    inline type_pack    type(void) const {return _type;}

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

#endif
