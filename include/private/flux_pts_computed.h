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



#ifndef _ELISE_GENERAL_PRIVATE_FLUX_PTS_FLUX_PTS_COMPUTED_H
#define _ELISE_GENERAL_PRIVATE_FLUX_PTS_FLUX_PTS_COMPUTED_H

#include "general/sys_dep.h"

class Flux_Pts_Computed : public Mcheck
{
    friend class Split_to_max_buf_rle;

public :
    virtual  bool   is_rect_2d(Box2di &);
    virtual  bool   is_line_map_rect();
    virtual  double_t   average_dist();  // to use only if is_line_map_rect -> True


    virtual const Pack_Of_Pts * next(void) = 0;
    virtual  ~Flux_Pts_Computed();
    inline int                          dim(void) const {return _dim;}
    inline  Pack_Of_Pts::type_pack     type(void) const {return _type;}
    inline int                       sz_buf(void) const {return _sz_buf;}
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

#endif
