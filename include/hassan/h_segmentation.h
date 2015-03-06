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
#ifndef _ELISE_GENERAL_H_SEGMENTATION_H
#define _ELISE_GENERAL_H_SEGMENTATION_H


class H_Cours_Water
{
    public:

       H_Cours_Water(Output wdisc);
       Im2D_int4 etiquette(Im2D_U_int1 Im_init);
       ElList<Pt2di> sommet();
       int nbr_sommet();
       Im2D_int4 max_loc(Im2D_U_int1 Im_init);
   private:

       int tx;
       int ty;
       int indice;
       int v_min;
       int lev_max;
       Im2D_U_int1 Im;
       Im2D_int4 etiquet;
       Im1D_int4 histog;
       ElList<Pt2di> lqueu;
       ElList<Pt2di> l_som;
       Output Wdisc;

       void pixel_suivant(int x, int y, int v);
       void pixel_suivant_m_l(int x, int y, int v);
       void histograme(int color);
};


class H_Cours_Water_3D
{
    public:

       H_Cours_Water_3D();
       Im3D_int4 etiquette(Im3D_U_int1 Im_init);
       Im3D_U_int1 surface();
       ElList<Pt3di> sommet();
       int nbr_sommet();

   private:

       int _tx;
       int _ty;
       int _tz;
       int _indice;
       int _v_min;
       int _lev_max;
       Im3D_U_int1 _Im;
       Im3D_int4 _etiquet;
       Im1D_int4 _histog;
       U_int1*** _Im_data;
       int4*** _etiquet_data;
       int4* _histog_data;
       ElList<Pt3di> _lqueu;
       ElList<Pt3di> _l_som;

       void pixel_suivant(int x, int y, int z, int v);
       void histograme(Output w, int color);
};


template<class type1, class type2> class H_Partage_eaux
{
    public:
      H_Partage_eaux(Output wodisc);
      Im2D_int4 sommets();
      ElList<Pt2di> top();
      Im2D_int4 regions(Im2D<type1, type2> Im);
      int nbr_regions();
 
    private:
      Im2D<type1, type2> im;
      Im2D_int4 reg;
      Im2D_int4 sommet;
      ElList<Pt2di> _top;
      ElList<Pt2di> graphe;
      int indice;
      int bord;
      int interdit;
      int val_retour;
      int tx;
      int ty;
      Output Wodisc;

      void monter();
      void descendre();
      void remplacer(int x, int y, type1& val_max, Pt2di& p);
};



template<class type1, class type2> class H_Partage_eaux_3D
{
    public:
      H_Partage_eaux_3D();
      ElList<Pt3di> top();
      Im3D_int4 regions(Im3D<type1, type2> Im);
      Im3D_U_int1 surface();
      int nbr_regions();
 
    private:
      Im3D_int4 reg;
      type1*** _im_d;
      int4*** _reg_d;
      ElList<Pt3di> _top;
      ElList<Pt3di> graphe;
      int indice;
      int bord;
      int interdit;
      int val_retour;
      int tx;
      int ty;
      int tz;

      void monter();
      void descendre();
      void remplacer(int x, int y, int z, type1& val_max, Pt3di& p);
};


#endif //_ELISE_GENERAL_H_SEGMENTATION_H

/*Footer-MicMac-eLiSe-25/06/2007

Ce logiciel est un programme informatique servant à la mise en
correspondances d'images pour la reconstruction du relief.

Ce logiciel est régi par la licence CeCILL-B soumise au droit français et
respectant les principes de diffusion des logiciels libres. Vous pouvez
utiliser, modifier et/ou redistribuer ce programme sous les conditions
de la licence CeCILL-B telle que diffusée par le CEA, le CNRS et l'INRIA 
sur le site "http://www.cecill.info".

En contrepartie de l'accessibilité au code source et des droits de copie,
de modification et de redistribution accordés par cette licence, il n'est
offert aux utilisateurs qu'une garantie limitée.  Pour les mêmes raisons,
seule une responsabilité restreinte pèse sur l'auteur du programme,  le
titulaire des droits patrimoniaux et les concédants successifs.

A cet égard  l'attention de l'utilisateur est attirée sur les risques
associés au chargement,  à l'utilisation,  à la modification et/ou au
développement et à la reproduction du logiciel par l'utilisateur étant 
donné sa spécificité de logiciel libre, qui peut le rendre complexe à 
manipuler et qui le réserve donc à des développeurs et des professionnels
avertis possédant  des  connaissances  informatiques approfondies.  Les
utilisateurs sont donc invités à charger  et  tester  l'adéquation  du
logiciel à leurs besoins dans des conditions permettant d'assurer la
sécurité de leurs systèmes et ou de leurs données et, plus généralement, 
à l'utiliser et l'exploiter dans les mêmes conditions de sécurité. 

Le fait que vous puissiez accéder à cet en-tête signifie que vous avez 
pris connaissance de la licence CeCILL-B, et que vous en avez accepté les
termes.
Footer-MicMac-eLiSe-25/06/2007*/
