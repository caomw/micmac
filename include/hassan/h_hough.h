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
#ifndef _ELISE_GENERAL_H_HOUGH_H
#define _ELISE_GENERAL_H_HOUGH_H


//////////////////////////////////////////////////////////////////////

class H_Hough
{
    public:

      H_Hough(  double_t     pas_rho=1,
                double_t     pas_teta=1,
                int      nb_min = 20,
                double_t     debut_teta=0,
                double_t     fin_teta = 180
             );

      H_Hough(  Im2D_U_int1 contour,
                bool        cont,
                Output      w,
                int         color,
                double_t        pas_rho=1,
                double_t        pas_teta=1,
                int         nb_min = 20,
                double_t        debut_teta=0,
                double_t        fin_teta = 180
             );

      H_Hough(  Im2D_U_int1 image,
                double_t        deriche,
                double_t        hyst_bas,
                double_t        hyst_haut,
                Output      w,
                int         color,
                double_t        pas_rho=1,
                double_t        pas_teta=1,
                int         nb_min = 20,
                double_t        debut_teta=0,
                double_t        fin_teta = 180
             );

      void accumuler(Im2D_U_int1 contour, bool cont = true);

      Im2D_double_t8 accumulator();
      ElList<Pt2di> max_loc(int nb_max = 5);
      ElList<Pt2di> max_loc_p();
      ElList<Pt2di > droites();
      void tracer(Output W,  int color = 7);
      void tracer(Output W, Pt2di p, int color = 7);
      void tracer(Output W, ElList<Pt2di> l, int color = 7);
      void tracer(Im2D_U_int1 im);
      int  nb_droite();

   private:

     Im2D_double_t8    _accumulator;
     Im2D_int4     _accumulator_im;
     Im2D_U_int1   _contour;
     Im1D_double_t8    _teta;
     Im1D_double_t8    _s_teta;
     Im1D_double_t8    _c_teta;
     Im1D_double_t8    _moderator;
     double_t8**       _accumulator_data;
     int4**        _accumulator_im_data;
     U_int1**      _contour_data;
     double_t8*        _teta_data;
     double_t8*        _s_teta_data;
     double_t8*        _c_teta_data;
     double_t8*        _moderator_data;
 
     ElList<Pt2di> _l;
     double_t          _pas_r;
     double_t          _pas_t;
     double_t          _debut_teta;
     double_t          _fin_teta;
     double_t          _intervale_teta;
     double_t          _merge_teta;
     int           _tr;
     int           _tt;
     int           _semi_tr;
     int           _tx;
     int           _ty;
     int           _nb_min;
     Pt2di         _centre;
     int           _nb_droite;
     ElList<Pt2di> _l_droite;

     void accumuler(Pt2di p);
     void accumuler_im(Pt2di p);
     void desaccumuler(Pt2di p);
     void conversion(Pt2di p);

};


//////////////////////////////////////////////////////////////////////

class H_Hough_3D
{
    public:

      H_Hough_3D(
                   double_t     pas_rho    = 1, 
                   double_t     pas_teta   = 1, 
                   double_t     pas_phi    = 1, 
                   int      nb_min     = 20, 
                   double_t     debut_teta = 0, 
                   double_t     fin_teta   = 180,
                   double_t     debut_phi  = 0, 
                   double_t     fin_phi    = 180
                );

      H_Hough_3D(
                   Im3D_U_int1 entrer,
                   Boite    sortir,
                   double_t     pas_rho    = 1, 
                   double_t     pas_teta   = 1, 
                   double_t     pas_phi    = 1, 
                   int      nb_min     = 20, 
                   double_t     debut_teta = 0, 
                   double_t     fin_teta   = 180,
                   double_t     debut_phi  = 0, 
                   double_t     fin_phi    = 180
             );
virtual ~H_Hough_3D(){};
      void accumuler(Im3D_U_int1 entrer, int debut = 0, int fin = 0);
      void accumuler(Im3D_U_int1 entrer, Im2D_U_int1 masq, int debut = 0, int fin = 0);
//      void accumuler(Liste_Pts_double_t nuage);

      Im3D_double_t8 accumulator();
      ElList<Pt3di> max_loc(int nb_max = 6, bool afficher = false, int d_teta = 3, int d_phi = 2, int d_rho = 1); 
      void tracer(Boite& sortir);
      void tracer(Boite& sortir, Pt3di p, int color = 1);
      void tracer(Boite& sortir, ElList<Pt3di> l);
      void tracer(Im3D_U_int1 entrer, Im2D_U_int1 masq, int debut = 0, int fin = 0);
virtual      Hplan conversion(Pt3di p);
      ElList<Hplan> conversion(ElList<Pt3di> l);
      ElList<Hplan> plans();
      void plans(ElFilo<Hplan>& f_pl);

      void push_cas_privilegie(double_t angl_teta, double_t angl_phi); //idee accepte extension
      void clear_cas_privilegie(){_cas_privilegie.clear();}

      void afficher_accumulator();

   protected:

     Im3D_double_t8    _accumulator;
     Im3D_double_t8    _accumulator_im;
     Im1D_double_t8    _teta;
     Im1D_double_t8    _phi;
     Im2D_double_t8    _c_phi_s_teta;
     Im2D_double_t8    _c_phi_c_teta;
     Im2D_double_t8    _s_phi;
     U_int1***     _entrer;
     double_t8***      _accumulator_data;
     double_t8***      _accumulator_im_data;
     double_t8*        _teta_data;
     double_t8*        _phi_data;
     double_t8**       _c_phi_s_teta_data;
     double_t8**       _c_phi_c_teta_data;
     double_t8**       _s_phi_data;

     ElFilo<Pt2di> _cas_privilegie;
     ElList<Pt3di> _l;
     ElList<Hplan> _lplan;
     double_t          _pas_r;
     double_t          _pas_t;
     double_t          _pas_p;

     double_t          _debut_teta;
     double_t          _fin_teta;
     double_t          _intervale_teta;
     double_t          _merge_teta;

     double_t          _debut_phi;
     double_t          _fin_phi;
     double_t          _intervale_phi;
     double_t          _merge_phi;

     int           _tr;
     int           _tt;
     int           _tp;
     int           _semi_tr;
     int           _semi_tp;
     int           _tx;
     int           _ty;
     int           _tz;
     int           _nb_min;
     Pt3dr         _centre;

     void accumuler(Pt3di p);
     void accumuler_im(Pt3di p);
     void accumuler_nuage(Pt3dr p);
     void desaccumuler(Pt3di p);

};

class H_Hough_mne:public H_Hough_3D
{
    public:

      H_Hough_mne(
                   int      diff       = 1,
                   double_t     pas_rho    = 1, 
                   double_t     pas_teta   = 1, 
                   double_t     pas_phi    = 1, 
                   int      nb_min     = 20, 
                   double_t     debut_teta = 0, 
                   double_t     fin_teta   = 180,
                   double_t     debut_phi  = 0, 
                   double_t     fin_phi    = 180
                );

      H_Hough_mne(
                   Mne&     mne,
                   int      diff       = 1,
                   double_t     pas_rho    = 1, 
                   double_t     pas_teta   = 1, 
                   double_t     pas_phi    = 1, 
                   int      nb_min     = 20, 
                   double_t     debut_teta = 0, 
                   double_t     fin_teta   = 180,
                   double_t     debut_phi  = 0, 
                   double_t     fin_phi    = 180
             );
virtual ~H_Hough_mne(){};

      void accumuler(Mne& mne, int diff = 1);
      ElList<Pt3di> max_loc(int nb_max = 6, bool afficher = false, int d_teta = 3, int d_phi = 2, int d_rho = 1); 

   protected:

      int _diff;
};



class H_Hough_seg : public H_Hough_mne
{
    public:

  
      H_Hough_seg(
                   double_t     pas_rho    = 1, 
                   double_t     pas_teta   = 1, 
                   double_t     pas_phi    = 1, 
                   int      nb_min     = 20, 
                   double_t     debut_teta = 0, 
                   double_t     fin_teta   = 180,
                   double_t     debut_phi  = 0, 
                   double_t     fin_phi    = 180
                );
virtual ~H_Hough_seg(){};

      void accumuler(ElFilo<double_t>& seg, double_t debut_angl = 0, double_t fin_angl = 180);
      void accumuler(ElFilo<double_t>& seg, ElFilo<double_t>& incert_teta,  double_t debut_angl = 0, double_t fin_angl = 180);
      Hplan conversion(Pt3di p);
};



class H_Hough_nuage : public H_Hough_seg
{
    public:

    //  H_Hough_nuage();

      H_Hough_nuage(
                   double_t     pas_rho    = 1,
                   double_t     pas_teta   = 1,
                   double_t     pas_phi    = 1,
                   int      nb_min     = 20,
                   double_t     debut_teta = 0,
                   double_t     fin_teta   = 180,
                   double_t     debut_phi  = 0,
                   double_t     fin_phi    = 180
                );
virtual ~H_Hough_nuage(){};

      void accumuler(ElFilo<Pt3dr>& points, double_t sigma);
};



void detection_hypotheses_plans_segments(
	                                       std::vector<double>& v_seg,
	                                       std::vector<double>& plans,
                                           double_t d_t = 2,
                                           double_t d_p = 2,
                                           double_t d_r = .5,
                                           double_t t_min = 0,
                                           double_t t_max = 180,
                                           double_t p_min = 30,
                                           double_t p_max = 150,
                                           double_t long_min = 20, 
                                           int  nb_max_plans = 400
                                        );



void detection_hypotheses_droites_segments(
                                           std::vector<double>& v_seg,
                                           std::vector<double>& droites,
                                           double_t d_t = 1,
                                           double_t d_r = .25,
                                           double_t t_min = 0,
                                           double_t t_max = 180,
                                           double_t long_min = 5,
                                           int  nb_max_plans = 400
                                        );


void detection_hypotheses_droites_segments_incert(
                                           std::vector<double>& v_seg,
                                           std::vector<double>& droites,
                                           std::vector<double>& incert_teta,
                                           double_t d_t = 1,
                                           double_t d_r = .25,
                                           double_t t_min = 0,
                                           double_t t_max = 180,
                                           double_t long_min = 5,
                                           int  nb_max_plans = 400
                                        );


void detection_hypotheses_droites_segments_2dd(
                                           std::vector<double>& v_seg,
                                           std::vector<double>& droites,
                                           double_t d_t = 1,
                                           double_t d_r = .25,
                                           double_t t_min = 0,
                                           double_t t_max = 180,
                                           double_t long_min = 5,
                                           int  nb_max_plans = 400
                                        );

void detection_hypotheses_droites_segments_2dd_incert(
                                           std::vector<double>& v_seg,
                                           std::vector<double>& droites,
                                           std::vector<double>& incert_teta,
                                           double_t d_t = 1,
                                           double_t d_r = .25,
                                           double_t t_min = 0,
                                           double_t t_max = 180,
                                           double_t long_min = 5,
                                           int  nb_max_plans = 400
                                        );


#endif //_ELISE_GENERAL_H_HOUGH_H

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
