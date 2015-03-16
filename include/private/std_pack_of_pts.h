/*Header-MicMac-eLiSe-25/06/2007

    MicMac : Multi Image Correspondances par Methodes Automatiques de Correlation
    eLiSe  : ELements of an Image Software Environnement

    www.micmac.ign.fr


    Copyright : Institut Geographique National
    Author : Marc Pierrot Deseilligny
    Contributors : Gregoire Maillet, Didier Boldo.
    Refactoring: Helio Chissini de Castro <helio@kde.org>

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

#ifndef _ELISE_GENERAL_PRIVATE_FLUX_PTS_TMPL_STD_PACK_OF_PTS_H
#define _ELISE_GENERAL_PRIVATE_FLUX_PTS_TMPL_STD_PACK_OF_PTS_H

#include <Pack_Of_Pts>
#include <Std_Pack_Of_Pts_Gen>
#include <Tab_Prov>

template <class Type>
class Std_Pack_Of_Pts : public Std_Pack_Of_Pts_Gen
{
public :
    virtual ~Std_Pack_Of_Pts(void);
    virtual  void show (void) const; // debug purpose
    virtual  void show_kth (int k) const;
    static Std_Pack_Of_Pts<Type>  * new_pck(int dim,int sz_buf);

    // give two dif name, elsewhere visual is confused
    virtual void convert_from_int(const Std_Pack_Of_Pts<int> *);
    virtual void convert_from_real(const Std_Pack_Of_Pts<double_t> *);
    virtual void convert_from_rle(const RLE_Pack_Of_Pts *) ;


    //  _pts shoulde be private with a definition like
    // inline  Type ** pts() const {return _pts;}
    // but I have double_tLY some problem with template instatiation
    // and g++

    Type ** _pts;
    virtual  void * adr_coord() const;

    virtual void select_tab(Pack_Of_Pts * pck,const int * tab_sel) const;

    void interv(const Std_Pack_Of_Pts_Gen * pck,int n1,int n2);

    void push(Type *);

    Pack_Of_Pts * dup(int sz_buf= -1) const; // -1 => sz_buf will be set to _nb

    virtual void  copy(const Pack_Of_Pts *);
    virtual void trans (const Pack_Of_Pts * pack, const int * tr);

    //  cat this at the end of res, replace res by a new set of size
    //  sz_buf (at least) if res is unsuifficient (and delete res).
    //  Return-value is the res or the eventually new set creates.

    Std_Pack_Of_Pts<Type> * cat_and_grow
    (Std_Pack_Of_Pts<Type> *  res,int new_sz_buf,bool & chang) const;

    void cat (const Std_Pack_Of_Pts<Type> * to_cat);
    virtual void cat_gen (const Std_Pack_Of_Pts_Gen * to_cat);

    void auto_reverse();
    virtual void  kth_pts(int *,int k) const;

    int   proj_brd
    (
            const Pack_Of_Pts * pck,
            const int * p0,
            const int * p1,
            int         rab    // 0 for int, 1 for real
            );

    void verif_inside
    (
            const int * pt_min, const int * pt_max,
            Type        rap_p0,
            Type        rap_p1
            ) const;

    virtual void rgb_bgr(const Std_Pack_Of_Pts_Gen *);

private :
    Std_Pack_Of_Pts<Type> (int dim,int sz_buf);

    // _pts[d][i] == coordinate of the ith Pts in the dth dimension
    Tab_Prov<Tab_Prov<Type> *>   * _tprov_tprov;
    Tab_Prov<Type *>             * _tprov_ptr;

    static const Pack_Of_Pts::type_pack type_glob;

    virtual void rgb_bgr() ;

};

#endif
