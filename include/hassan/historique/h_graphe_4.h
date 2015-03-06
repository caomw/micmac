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
#ifndef _ELISE_GENERAL_H_GRAPHE_H
#define _ELISE_GENERAL_H_GRAPHE_H

//////////////////////////////////////////////////////////////////////

class H_Graphe : public Camera_V
{
    public:


      ElFilo<Pt3dr>           _sommet;
      ElFilo<int>             _sommet_flag;
      ElFilo<int>             _sommet_enleve;

      ElFilo<int>             _segment_0;
      ElFilo<int>             _segment_1;
      ElFilo<int>             _segment_flag;
      ElFilo<int>             _segment_enleve;
      ElFilo< ElFilo<int>* >  _segment_facette;
      ElFilo< ElFilo<int>* >  _seg_facet_droite;
      ElFilo< ElFilo<int>* >  _seg_facet_gauche;
      ElFilo<int>             _seg_discontinuite;
      ElFilo<double_t>            _seg_long;
      ElFilo<double_t>            _seg_poids;
      ElFilo<int>             _seg_facet_vot_gauche;
      ElFilo<int>             _seg_facet_vot_droite;

      ElFilo< ElFilo<int>* >  _facette;
      ElFilo<int>             _facette_flag;
      ElFilo<int>             _facette_plan;
      ElFilo<int>             _facette_enleve;
      ElFilo<double_t>            _facette_surface;
      ElFilo<double_t>            _facette_poids;

      ElFilo< ElFilo<int>* >  _solution;
      ElFilo< double_t >          _solution_poids;


      Pt2di*                  _p_proj;
      int                     _col1;
      int                     _col2;
      int                     _col3;
      int                     _col4;
      int                     _col5;


      H_Graphe(  Video_Win W, int nb_color, ElFilo<Facette_3d> & f_f, double_t element_petit = .1 );     //.1 metre
      H_Graphe(  H_Graphe& graphe );     

      ~H_Graphe();

      int  sommet_in(Pt3dr p);
      void sommet_en(int i);
      
      int  segment_in(int i, int j);
      void segment_en(int n_s, bool continuite = false);
      void segment_valide(int n_s);
      void enleve_seg_discontinuite();


      int  facette_in(ElFilo<int>& f, int n_plan = 0, double_t poids = 0.);
      void facette_en(int n_f, bool continuite = false);
      void facette_en(ElFilo<int>& f_facet, bool continuite = false);
      void facette_valide(int n_f);
      Facette_3d facette(int n_f);

      void arrange_facette();

      void recherche_facette_cont_sup(int n_f, ElFilo<int>& facet_cont_sup);
      void recherche_facette_cont_inf(int n_f, ElFilo<int>& facet_cont_inf);
      void recherche_facette_cont_sup_inf(int n_f, ElFilo<int>& facet_cont_sup_inf);

      void enleve_facette_sup_inf(int n_f);
      void enleve_facette_sup(int n_f);
      void enleve_facette_inf(int n_f);

      void facette_droite_gauche(int n_f);
      bool if_facet_a_gauche_seg(int n_f, int n_seg);


      void surface_continue();

      void fusionner();


      void facette_poids(int n_f, Boite& coef_cor);
      void facette_poids(Boite& coef_cor);
      void facette_poids(ElFilo<Boite>& coef_cor_plan);
      void facette_poids(Boite& b_mne, Im2D_U_int1 masq, int decal = 1, int test_stab = 0);

      void segment_poids(int n_s, WcorVis W1, Im2D_U_int1 grad1, WcorVis W2, Im2D_U_int1 grad2);
      void segment_poids(WcorVis W1, Im2D_U_int1 grad1, WcorVis W2, Im2D_U_int1 grad2);
      void segment_poids(ElFilo<Boite>& coef_cor_plan);
      void segment_poids(Boite& b_mne, int decal = 1);

      double_t graphe_poids();


      void initialiser_flags_segments();
      void initialiser_flags_facettes();
      void initialiser_tous_flags();

      void recherche_meil_combinaison_pour_chaque_segment();
      void recherche_solutions();
      void rejete_solutions(int n_sol);
      void rejete_solutions();
      void rejete_solutions_non_compatibles();
      void difusion_continuite();

      void up_date();
      void explorer();
      double_t merite_coef(int n_sol, Boite& b_a, Boite& b_b, int s_t_f, Output);
      double_t merite_cont(int n_sol, Boite& b_a, Boite& b_b, int s_t_f, Output);
      double_t merite_cont(int n_sol);
      void arrange_solutions(Boite& b_a, Boite& b_b, int s_t_f, Output w);

                                            //methode d'affichage

      virtual void reperer();
      virtual void afficher();
      virtual void desafficher();
      virtual void interface();


      void affiche_segment(int n_seg, int color);
      void affiche_segment(ElFilo<int>& f_seg, int color);
      void affiche_facette(int n_facet, int color);
      void affiche_facette(ElFilo<int>& f_facet, int color);

      void parcour_seg_facet();
      void parcour_segment();
      void parcour_facette();
      void parcour_facette_et_cont();
      void parcour_solution(bool debut = false);


};


#endif //_ELISE_GENERAL_H_GRAPHE_H

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
