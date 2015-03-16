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

#ifndef _ELISE_GENERAL_BITM_TPL_DATAIM3D_H
#define _ELISE_GENERAL_BITM_TPL_DATAIM3D_H

template <class Type,class TyBase> class DataIm3D : 
            public DataGenImType<Type,TyBase>
{
    public :




      virtual void out_pts_integer(Const_int_PP coord,int nb,const void *) ;
      virtual void input_pts_integer(void *,Const_int_PP coord,int nb) const;
      virtual void input_pts_reel(double_t *,Const_double_t_PP coord,int nb) const;


      DataIm3D(
                int tx,int ty,int tz,
                bool to_init,TyBase v_init,const char * =0,Type * DataLin  = 0
      );

      virtual int    dim() const;
      virtual const int  * p0()  const;
      virtual const int  * p1()  const;

      virtual void  *   calc_adr_seg(int *);
      virtual ~DataIm3D();

      Type ***  data() const;
      int tx() const ;
      int ty() const ;
      int tz() const ;

       int           _txyz[3];
       Type ***    _data;

       virtual void out_assoc
              (
                  void * out, // eventually 0
                  const OperAssocMixte &,
                  Const_int_PP coord,
                  int nb,
                  const void * values
              ) const;


     protected :

};

#endif
