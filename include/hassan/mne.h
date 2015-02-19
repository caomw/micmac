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
#ifndef    _HASSAN_MNE_H
#define    _HASSAN_MNE_H



class Mne
{
   public:

     Im2D_INT2 _mne;
     Pt3dr     _orig;
     Pt3dr     _ray_x;
     Pt3dr     _ray_y;
     Pt3dr     _ray_z;
     Pt3dr     _pas;
     INT       _label_interdit;
     REAL      _z_min;
     REAL      _z_max;
     bool      _trapu;
     Pt2dr     _cor_trapu;

     Mne();

     Mne(
           Im2D_INT2 mne,
           Pt3dr p0,
           Pt3dr vect_x,
           Pt3dr le_pas,
           INT   val_interdite
        );

     Mne(
           Im2D_INT2 mne,
           Pt3dr p0,
           Pt3dr vect_x,
           Pt3dr vect_y,
           Pt3dr le_pas,
           INT   val_interdite
        );

     Mne(
           Boite& b_mne
        );
    
     Mne( Cub3DTer c_ter, REAL pas_z );


     Mne(
           char* name_file, 
           bool mne_de_noyau = false 
        );


     Mne(Mne& mne);
     Mne(Mne& mne, Facette_2d f, bool eliminer_points_dhore = false);

     Mne& operator = (Mne& mne);
     Mne& operator +=(Mne& mne);
     Mne& operator -=(Mne& mne);
     Mne  operator + (Mne& mne);
     Mne  operator - (Mne& mne);
     Mne  operator & (Mne& mne);


     bool read( char* name_file,  bool mne_de_noyau = false );
     bool write( char* name_file, bool mne_de_noyau = false );

     Pt3dr orig();
     Pt3dr ray_x();
     Pt3dr ray_y();
     Pt3dr ray_z();
     Pt3dr pas();
     INT   label_interdit();
     REAL  z_min();
     REAL  z_max();
     REAL  z_volume();
     REAL  z_interval();
     INT   tx();
     INT   ty();

     void          initialiser();
     void          deplace_orig(Pt3dr p);
     void          set_pas(Pt3dr p);
     void          set(Facette_3d f);
     void          set(ElFilo<Facette_3d>& f_f);
     void          set(H_Graphe& graphe);
     void          set(Pt3di p);
     void          set(Pt3dr p);

     Pt3dr         mne_to_terr(Pt3di p);
     Pt3dr         mne_to_terr(Pt3dr p);
     Facette_2d    mne_to_terr(Facette_2d f);
     Facette_3d    mne_to_terr(Facette_3d f);
     Hplan         mne_to_terr(Hplan plan);
     ElList<Hplan> mne_to_terr(ElList<Hplan> list_plan);
     void          mne_to_terr(ElFilo<Facette_3d>& f_f);
     
     Pt3dr      terr_to_mne(Pt3dr p);
     Pt2dr      terr_to_mne(Pt2dr p);
     Facette_2d terr_to_mne(Facette_2d f);
     Facette_3d terr_to_mne(Facette_3d f);
     Hplan      terr_to_mne(Hplan plan);
     Hdroite    terr_to_mne(Hdroite drt);
     void       terr_to_mne(ElFilo<Facette_3d>& f_f);
     void       terr_to_mne(H_Graphe& graphe);

     INT       mne(INT x, INT y);
     Im2D_INT2 mne(){return _mne;}

     void           facette_to_points(Facette_2d f, ElFilo<Pt3dr>& f_p);  //facette en reference terrain

     Liste_Pts_INT2 intersection(Facette_3d f, INT decal = 0);
     REAL           poids_gaussian(Facette_3d f, REAL sigma = 1, INT distance = 3);
     REAL           poids(Facette_3d f, INT decal = 0 , INT test_stab = 0);
     REAL           filtrer(ElFilo<Facette_3d>& f_f, REAL seuil = 30, INT decal = 0, INT test_stab = 0);  //f_f en reference terrain
     REAL           distance_volumique(Mne& mne);    //très particulière
     REAL           distance_max(Mne& mne);    //très particulière
     void           distance_surface_volumique(Mne& mne, REAL& dist, REAL& surf);    //très particulière

     bool  mediane(Facette_2d f, INT2& z);
     bool  mediane(Facette_2d f, REAL& z);

     void  afficher(Output out, INT nb_color);
     void  afficher(Output out, INT nb_color, Pt2di p0, Pt2di p1);
     void  afficher(Facette_3d f, INT decal_max, Output out, INT nb_color);  //decal_max : distance d'un point de la facette
};

#endif   //_HASSAN_MNE_H

