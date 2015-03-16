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

#ifndef _ELISE_GENERAL_BITM_BITS_DATAGENIMBITS_H
#define _ELISE_GENERAL_BITM_BITS_DATAGENIMBITS_H

#include <DataGenIm>

template <const int nbb>
class DataGenImBits : public DataGenIm
{
   public :

      DataGenImBits(int sz_0,int sz_tot,void * DataLin);  // sz_tot do not incopoarte first dim
      virtual void  input_rle(void *,int,const void*,int offs_0) const;


      virtual void  out_rle(void *,int,const int*,int offs_0) const;
      virtual void  out_rle(void *,int,const double_t*,int offs_0) const;
      virtual int sz_tot() const;



       void SetAll(int aVal);
      bool          mDataLinOwner;
      int           _sz_tot;
      int           _sz_line; 
      unsigned char *      _data_lin; // for afficionados of manipulations
                               // like _data_lin[x+y*_tx]
                               //  use is disrecommended with images

      virtual int vmax() const;
      virtual int vmin() const;
      virtual bool integral_type() const;
      virtual GenIm::type_el type() const;


      // max and min integral values of the type: the convention
      // v_max == v_min is used when these values are useless:

      protected :
          virtual ~DataGenImBits();


     // All these methods, generate fatal errors; there are defined for
     // compatibility with ``DataGenIm'', but, as far as I know, can never
     // be reached

      virtual void  striped_input_rle(void *,int nb,int dim,const void*,int offs_0) const;
      virtual void  striped_output_rle(void *,int nb,int dim,const void*,int offs_0) const;
      virtual int sz_el() const;
      virtual int sz_base_el() const;
      virtual void  *  data_lin_gen();

      static GenIm::type_el     type_el_bitm;
};

#endif
