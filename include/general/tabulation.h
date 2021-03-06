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

#ifndef __TABULATION__
#define __TABULATION__


extern int  PdsGaussl9NEIGH[9];


extern Pt2dr TAB_CornerPix[4];     // pts[i] = pts[i+8]

extern Pt2di TAB_8_NEIGH[16];     // pts[i] = pts[i+8]
extern Pt2di TAB_4_NEIGH[8];     // pts[i] = pts[i+4]
extern Pt2di TAB_9_NEIGH[9];     // pts[8] = 0,0
extern Pt2di TAB_5_NEIGH[5];     // pts[5] = 0,0


extern Pt2di VOIS_9[9];  // dans l'ordre de parcourt "video"


extern int TAB_8_FREEM_SUCC_TRIG[8];
extern int TAB_4_FREEM_SUCC_TRIG[4];

extern int TAB_8_FREEM_PREC_TRIG[8];
extern int TAB_4_FREEM_PREC_TRIG[4];

extern int TAB_8_FREEM_SYM[8];
extern int TAB_4_FREEM_SYM[4];

typedef int MAT_CODE_FREEM[3][3];

extern U_int1 FLAG_FRONT_8_TRIGO[512];
extern U_int1 FLAG_FRONT_4_TRIGO[512];

extern MAT_CODE_FREEM MAT_CODE_4_FREEM;
extern MAT_CODE_FREEM MAT_CODE_8_FREEM;

extern int compute_freem_code
           (
                 //const  JYCAR
				 MAT_CODE_FREEM &,
                 Pt2di                p
           );

// freeman code of points  for 8-neighboor; -2 if out, -1 if (0,0)

extern int freeman_code(Pt2di);




class Elise_tabulation
{
      public :
          static inline void init() 
          {
                if (_deja) return;
                _deja = true;
                _init();
          }
    
      private :
            static bool _deja;
            static void _init();
};

template <class Type> class File_Tabulated
{
       public :
            File_Tabulated(const char * name);
            const Type * ptr();
       private :
            Type * _ptr;
            const char * _name;
};


class Config_Freeman_Or
{
   public :
      Config_Freeman_Or(bool v8,bool trigo);

      inline Pt2di kth_p(int k) const   { return _pts[k];}
      inline int    succ(int k) const   { return _succ[k];}
      inline int    prec(int k) const   { return _prec[k];}
      inline int     sym(int k) const   { return _sym[k];}
      inline int    nb_pts()    const   { return _nb_pts;}

      inline int  num_pts(Pt2di p)  const
                  {return compute_freem_code(*_mat_code,p);}

   private :
      Pt2di           *  _pts ;
      int                _nb_pts;
      int             * _succ ;
      int             * _prec ;
      int             * _sym ;
      MAT_CODE_FREEM  * _mat_code;
};


#endif

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
