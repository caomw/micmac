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



#ifndef _ELISE_GENERAL_PRIVATE_FLUX_PTS_TMPL_STD_PACK_OF_PTS_GEN_H
#define _ELISE_GENERAL_PRIVATE_FLUX_PTS_TMPL_STD_PACK_OF_PTS_GEN_H

#include <Pack_Of_Pts>

class  Std_Pack_Of_Pts_Gen : public Pack_Of_Pts
{
       public :
            virtual void interv(const Std_Pack_Of_Pts_Gen * pck,int n1,int n2) = 0;

            // suppose the type of to_cat is the same than this
            virtual void cat_gen (const Std_Pack_Of_Pts_Gen * to_cat) = 0;
           
            virtual void rgb_bgr() = 0;
            virtual void rgb_bgr(const Std_Pack_Of_Pts_Gen *) = 0;

            
       protected :
            Std_Pack_Of_Pts_Gen(int dim,int _sz_buf,type_pack);


};

#endif
