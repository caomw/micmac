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

#ifndef _ELISE_GENERAL_PRIVATE_FLUX_PTS_RLE_PACK_OF_PTS_H
#define _ELISE_GENERAL_PRIVATE_FLUX_PTS_RLE_PACK_OF_PTS_H

#include <Pack_Of_Pts>
#include <Tab_Prov>

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

    inline int     & x0(){return _pt0[0];}
    inline int      vx0() const {return _pt0[0];}
    inline int     x1() const {return _pt0[0] + _nb;}
    inline int * pt0() const {return _pt0;}

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

#endif
