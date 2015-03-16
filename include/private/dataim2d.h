/*Header-MicMac-eLiSe-25/06/2007

    MicMac : Multi Image Correspondances par Methodes Automatiques de Correlation
    eLiSe  : ELements of an Image Software Environnement

    www.micmac.ign.fr


    Copyright : Institut Geographique National
    Author : Marc Pierrot Deseilligny
    Contributors : Gregoire Maillet, Didier Boldo.
    Refactoring: Helio Chissini de Castro <helio@kde.org>

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

#ifndef _ELISE_GENERAL_BITM_TPL_DATAIM2D_H
#define _ELISE_GENERAL_BITM_TPL_DATAIM2D_H

#include <DataGenImType>
#include <DataIm2DGen>

template <class Type,class TyBase> class DataIm2D : 
             public  DataGenImType<Type,TyBase> ,
             public  DataIm2DGen
{
    public :


      double Get(const Pt2dr & aP ,const cInterpolateurIm2D<Type> &,double aDef);

      virtual void out_pts_integer(Const_INT_PP coord,int nb,const void *) ;
      virtual void input_pts_integer(void *,Const_INT_PP coord,int nb) const;
      virtual void input_pts_reel(double_t *,Const_REAL_PP coord,int nb) const;

      virtual void  *   calc_adr_seg(int *);
      virtual ~DataIm2D();
	  void raz(Pt2di p0,Pt2di p1);

      Type **  data() const; 
      Type *  data_lin() const; 

      double_t  som_rect(Pt2dr p0,Pt2dr p1,double_t def =0.0) const;
      double_t  moy_rect(Pt2dr p0,Pt2dr p1,double_t def =0.0) const;          
	  void set_brd(Pt2di sz,Type val); 

      virtual int    dim() const;
      virtual const int  * p0()  const;
      virtual const int  * p1()  const;

      Type **     _data;
      bool        _to_free2;

      virtual void q_dilate
                   (  Std_Pack_Of_Pts<int> * set_dilated,
                      char **                is_neigh,
                      const Std_Pack_Of_Pts<int> * set_to_dilate,
                      int **,
                      int   nb_v,
                      Image_Lut_1D_Compile   func_selection,
                      Image_Lut_1D_Compile   func_update
                   );

      DataIm2D
      (
           int tx, 
           int ty,
           bool to_init,
           TyBase v_init,
           const char * =0,
           Type *      dlin = 0,
           Type **     d2 = 0,
           int         tx_phys = -1,
		   bool        NoDataLin = false
      );

      virtual void out_assoc
              (
                  void * out, // eventually 0
                  const OperAssocMixte &,
                  Const_INT_PP coord,
                  int nb,
                  const void * values
              ) const;

          void Resize(Pt2di aSz);
};

#endif
