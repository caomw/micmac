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

#define IGN 1



class Cub3DTer 
{
    public :
         Cub3DTer
         (
               Pt3dr pz0,
               Pt3dr pz1,
               double_t pas_z,
               double_t pas_xy,
               const char *data_dir,
               bool        RVB
         );

         bool  rgb() { return _rvb;}


         static Cub3DTer  Amiens0;
         static Cub3DTer  Amiens1;
         static Cub3DTer  CubColombe1;
         static Cub3DTer  CubColombe2;

         static Cub3DTer  CubColombeFF0;

         static Cub3DTer  CubLM0;
         static Cub3DTer  CubColombe0;
         static Cub3DTer  Altk_0;

         static Cub3DTer  MiniLeman0;

         static Cub3DTer  MiniColombe0;

         Tiff_Im std_tif(char *name_phot);
         Elise_File_Im std_pnm(char *name_phot,char * name_file = "image");
         Elise_File_Im std_red(char *name);
         Elise_File_Im std_green(char *name);
         Elise_File_Im std_blue(char *name);

         Fonc_Num std_rgb_in(char *name);


         Ori3D_Std     std_or (char *name);

         Flux_Pts r2d();
         int sz_ixy() const { return ElMax(_sz_im.x,_sz_im.y);}
         int sz_ix() const  { return _sz_im.x;}
         int sz_iy() const  { return _sz_im.y;}
         int sz_iz() const  { return _sz_im.z;}
         Pt3di sz_image() const  { return _sz_im;}

         Pt3dr pz0() const  { return _pz0;}
         Pt3dr pz1() const  { return _pz1;}

         double_t  pas_z() const { return _pas_z;}
         double_t  pas_xy() const{ return _pas_xy;}

         double_t x0() const { return _pz0.x;}
         double_t y0() const { return _pz0.y;}
         double_t z0() const { return _pz0.z;}

         Im3D<U_int1,int>  cub_ui1();
         Im3D<U_int1,int>  cub_ui1(char * name);
         Im2D_double_t4        plan_r4();


         Im2D_U_int1  proj_min_max(Im3D<U_int1,int>,bool mode_min);
         Im2D_U_int1  proj_min_max(char *,bool mode_min);

         Im2D_U_int2  z_proj(Im3D<U_int1,int>,Im2D_U_int1);
         Im2D_U_int2  z_proj_min_max(Im3D<U_int1,int>,bool mode_min);
         Im2D_U_int2  z_proj_min_max(char *,bool mode_min);

         const char * data_dir() { return _ddir;}

         bool     exist_file(const char * name);
         Elise_File_Im   fcub(const char * name,bool create = false);
         Elise_File_Im   fcar(const char * name,GenIm::type_el,bool create = false);
         Im1D_int4       histo(char * name);
         Im1D_U_int1     lut_eg_dyn(char * name);

    private :
         Pt3dr _pz0;
         Pt3dr _pz1;
         double_t  _pas_z;
         double_t  _pas_xy;
         const char * _ddir;

         Pt3di    _sz_im;
         bool     _rvb;
};







Fonc_Num auc(Fonc_Num f);


class Wcor
{
     public :

          virtual ~Wcor();
          Wcor (Cub3DTer,char * name);

          virtual Pt2di clik();

          void load_z(double_t z);
          Fonc_Num load_grad_polar_z(double_t z,double_t def,double_t fact_norm);
          void lissage_can(double_t fact);

          virtual Output vgray();
          virtual Output vbicol();
          virtual Output vdisc();
          virtual Output vrgb();

          Flux_Pts  rphoto();
          Flux_Pts  rterrain();

     //  protected :

          Im2D_U_int1 iphot();
          Im2D_U_int1 ipred();
          Im2D_U_int1 ipgreen();
          Im2D_U_int1 ipblue();

          Im2D_U_int1 itred();
          Im2D_U_int1 itgreen();
          Im2D_U_int1 itblue();

          Im2D_U_int1 iter();
          Im2D_int1   igx();
          Im2D_int1   igy();

          Im2D_U_int1   ngrad();
          Im2D_U_int1   agrad();

          Ori3D_Std      _o3;
          Cub3DTer      _c3d;

          Pt2di          _p0;
          Pt2di          _sz;
          Pt2di          _szt;

          Fonc_Num ter_loc_to_phot_loc
                   (Fonc_Num fx,Fonc_Num fy,Fonc_Num fz);
          Fonc_Num phot_loc_et_z_to_photo_loc
                   (Wcor cible,Fonc_Num fx,Fonc_Num fy,Fonc_Num fz);

          Fonc_Num ortho_image(Fonc_Num mne);

          Pt2dr ter_loc_to_phot_loc(Pt3dr);
          Pt2dr ter_to_phot_loc(Pt3dr);
          Pt2dr carte_to_phot_loc(Pt3dr);
          double_t  resolution(){return _o3.resolution();} //HJ

          ElList<Facette_2D> select_inside_phot(ElList<Facette_2D>,double_t z0,double_t z1,double_t rab);
          bool      inside_phot(Pt2dr, double_t rab);

          bool   rgb(){return _c3d.rgb();}


          private : 
              void assert_gray();
              void assert_rgb();

              Im2D_U_int1  init_im_ui1(Im2D_U_int1 &,int szx,int szy);
              Im2D_int1    init_im_i1(Im2D_int1 &,int szx,int szy);

              Im2D_U_int1 _iphot;
              Im2D_U_int1 _ipred;
              Im2D_U_int1 _ipgreen;
              Im2D_U_int1 _ipblue;


              Im2D_U_int1 _iter;
              Im2D_U_int1 _itred;
              Im2D_U_int1 _itgreen;
              Im2D_U_int1 _itblue;



              Im2D_U_int1 _agrad;
              Im2D_U_int1 _ngrad;
              Im2D_int1 _igx;
              Im2D_int1 _igy;
};





class WcorVis : public Wcor
{
     public :

          WcorVis   
          (    Cub3DTer,
               char * name,
               Video_Display,
               Elise_Set_Of_Palette,
               int  zoom = 1
          );

          WcorVis
          (    Cub3DTer,
               char * name,
               Video_Win  W
          );


          virtual Pt2di clik();

          void draw_seg_ter(Pt3dr,Pt3dr,Col_Pal);
          void draw_plan_vert
               (
                    Pt2dr, Pt2dr, // Points terrains
                    Col_Pal
               );

          void draw_point_ter(Pt3dr centre,double_t radius,Col_Pal);
          virtual Output vgray();
          virtual Output vrgb();
          virtual Output vbicol();
          virtual Output vdisc();

          Im2D_U_int1 shading(Im2D_U_int2 mnt,double_t Pglob);
          void persp(Im2D_U_int2 mnt,Pt2di dir,double_t tgt);


//       private :
          Video_Win  _W;
};


class COST_dz
{
     public :
          virtual double_t cost
                       (
                            double_t dz_ter,
                            int idz,
                            double_t pente,
                            double_t  corr_moy
                       )  = 0 ;

          COST_dz   (double_t cdz)  : _cout_dz(cdz) {}
          double_t   _cout_dz;
};

class Arg_Prg_Dyn
{
     public :

         // _ic3 will be linarly converted so that :
         //  correlation > threhsolds => 255
         //  cout_dz  : prorptionnal to a tangeance
         //  


         Arg_Prg_Dyn
         (
              Pt2di                    p_thresh,
              double_t                 fact_mul_cts,
              Cub3DTer                      c3d,
              char  *                      name,
              COST_dz *               calc_cost,
              double_t                   max_dz_ter,
              int2  **                    zcont,
              Im2D_int2                      zc

         );

         // donne leur valeur a  _max_dz et _cost_dz 
         // en supposant que l'on va balayer selon des lignes
         // de direction dir

         void init_cost(Pt2dr dir);

         void compute_cost(Video_Display,Elise_Set_Of_Palette,char *);
         void compute_cost(char *);


     private :
         void compute_cost(class CUTS& cuts_av,class CUTS& cuts_ar,char *);
         void compute_cost
             (
                  class CUTS& cuts_av,
                  class CUTS& cuts_ar,
                  Pt2di       p1,
                  Pt2di       p2
             );



         Cub3DTer               _c3d;
         Im3D<U_int1,int>      _ic3;
         Im1D_U_int1           _lut_thr;
         Im2D_int4             _cost;


        // arguments donnes en coord terrain, converti en coordonnees cube
        // _fact_mul_cts : permet de garder une cerraine precision apres
        // la convertion a 5 valeur des prg dyn



         double_t       _fact_mul_cts;
         COST_dz    *_calc_cost;
         double_t        _max_dz_ter;

    public :
 
         double_t                _pas_z;
         double_t               _pas_xy;
         int                _max_dz;
         int  *            _cost_dz;
         int2 **            _z_cont;
         Im2D_int2              _zc;  // to conserve ref on _z_cont
         double_t             _corr_moy;
};



class CUTS
{
     public :
        virtual ~CUTS();

        CUTS (Cub3DTer,char * name);

        void set_im3(Im3D<U_int1,int>);
        void set_cut(Pt2di p1,Pt2di p2,int2 ** z_cont);
        void load_cut(int2 ** z_cont);
        void use_cont(int2 ** z_cont,int);
        void set_cut_rev(CUTS &,int2 **);
        Pt3dr clik_to_ter(Pt2di cl);

        virtual Output vgray();
        virtual Output vdisc();

        void compute_prg(int * cost,int zmax);

        Flux_Pts r2d();

        char *           _name;
        Cub3DTer          _c3d;
        Im3D<U_int1,int>  _ic3;
        int             _sz_xy;
        int             _nb_xy;
        int               _nbz;
        Im1D_int2           _x;
        Im1D_int2           _y;
        Im2D_int4         _cor;
        Im2D_int4    _cost_prg;
        bool              _init;
        bool          _init_cub;
};


class CUTS_Vis : public CUTS
{
     public :

        CUTS_Vis
        (
            Cub3DTer                      ,
            int                       zoom,
            Video_Display                 ,
            Elise_Set_Of_Palette          ,
            char  *                   name,
            char  *                  title
        );

        virtual Output vgray();
        virtual Output vdisc();

        int               _z;
        Video_Win         _W;
};



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
