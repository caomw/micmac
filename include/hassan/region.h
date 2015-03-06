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
#ifndef _HASSAN_REGION_H
#define _HASSAN_REGION_H


///////////////////////////////////////////////////////////////////////////////
/************* isolement des regions **************/

class Isol_region
{
    public:
      Im2D_U_int1   im_src;
      Im2D<int,int> im_reg;
      
      Isol_region(
                   Im2D_U_int1   Im_src,
                   Im2D<int,int> Im_reg,
                   int           Nb_min_reg,
                   double_t4         Param_der,
                   double_t4         S_grad_min,
                   double_t4         S_grad_max,
                   double_t4         sbas,
                   double_t4         shaut,
		   Output        wgr,
		   int           nb_colour=8,
                   bool          hyst=true,
                   int           Nb_min_cont = 10
                 );
                 
      Isol_region(
                   Im2D_U_int1   Im_src,
                   double_t4         Param_der,
                   double_t4         sbas,
                   double_t4         shaut,
		   Output        wgr,
		   int           nb_colour=8,
                   bool          hyst=true,
                   int           Nb_min_cont = 10
                 );

       void xhyster(double_t4 sbas=10, double_t4 shaut=20);
       Im2D_double_t4  get_norm(){return norm;}
       Im2D_double_t4  get_teta(){return teta;}
       Im2D_U_int1 get_cont(){return cont;}
       ElList<Pt2di> get_list_region(){return l;}

    private:
       Im2D_double_t4    gradx;
       Im2D_double_t4    grady;
       Im2D_double_t4    norm;
       Im2D_double_t4    teta;
       Im2D_U_int1   m_loc;
       Im2D_U_int1   cont;
       Output        _wgr;
       ElList<Pt2di>   l;
       double_t4         param_der;
       double_t4         s_grad_min;
       double_t4         s_grad_max;
       double_t4         s_grad; 
       int           nb_min_reg;
       int           nb_reg;
       int           nb_pt_reg;
       int           no_reg;
       int           nc;
       int           nl;
       int           levmax;
       ElList<Pt2di>   lqueu;
       int           nb_min_cont;
       
       void dilate_reg();
       Liste_Pts_int2  dilate_reg(Flux_Pts flx);

       void max_loc();
       void hyster(double_t4,double_t4);
       void cal_teta();
       void extract_reg();   
       void parcour(int x, int y);
       void deparcour(int x, int y);   
};

///////////////////////////////////////////////////////////////////////////////////////////////////

class Hregion;
class Data_reg:public RC_Object
{
     friend class Hregion;
     
     public:
     private:
    
          Data_reg(Liste_Pts_U_int2 reg, int etiq, int nr);
          virtual ~Data_reg(){}

         Liste_Pts_U_int2  _reg;
         int               _etiq;
         int               _nr;
         double_t              _w; 
         ElList<Hregion>      _lr;
         double_t *            _coef;
         int               _nb;
         int               _capa;
         int               _z;
         double_t              _zl0;
         double_t              _dz;
         bool              _visite;
         void              set_capa(int nb);
         void              push(double_t);
         void              push(Hregion);
};

/////////////////////////////////////////////////////////////////////////////////////////////
class Hregion : public  PRC0
{
     public :
     
           Hregion ():PRC0(0){}
           Hregion (Liste_Pts_U_int2 reg, int etiq, int nr);

//           Hregion* ptr();

           int   capa();
           int   z();  
           bool  visite();
           int   etiq();
           double_t  zl0();
           double_t  dz();
           ElList<Hregion> lrv();
           void  push(double_t);
           void  push(Hregion);
           void  set_v(bool);
           void  set_z(int);
           void  set_zl0(double_t);
           void  set_dz(double_t);
           void  set_capa(int);
           double_t  & operator [](int i);
           int   nr();
           double_t  poid();
           void  cal_poid();
           Liste_Pts_U_int2  rg();
           double_t  cout(int, double_t);

    private :
     
        inline Data_reg* dtd(){ return (Data_reg*) _ptr;}
};


#endif // _HASSAN_REGION_H

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
