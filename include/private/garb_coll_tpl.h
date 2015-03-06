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



#ifndef _ELISE_GAR_COLL_TPL_H
#define _ELISE_GAR_COLL_TPL_H

#include <Mcheck>

template <class Type> class Tab_Prov
                      : public Mcheck
{
    public :
          virtual ~Tab_Prov() ;
          virtual Type   *   coord() = 0;
};

template <class Type> class AllocTprov 
{
    public :
        static  Tab_Prov<Type> *   alloc_big_tprov(int sz_buf);
        static  Tab_Prov<Type *>             * alloc_small_ptr_tprov(int sz_buf);
        static  Tab_Prov<Tab_Prov<Type> *>   * alloc_small_tprov_tprov(int sz_buf);
};




typedef Tab_Prov<int>   Tprov_int;
Tprov_int * alloc_tab_prov_int_small(int sz_buf);

typedef Tab_Prov<double_t>   Tprov_double_t;
typedef Tab_Prov<char>   Tprov_char;




Tprov_char * dup_name_std(const char * name);
Tprov_int  * dup_sz_std(const int * sz,int dim);

template <class Type> class Elise_Pile;

template <class Type> class Elise_Pile
{
    // sometime qpush is defined to solve some problems with inlining template
    public  :
       int nb();
       Type * ptr();
       void  destr();
       void push(Type);
       void reset(int);
       Elise_Pile();
       Elise_Pile(int capa);

         void qpush(const Type & v){_ptr[_nb++] = v;}
    private :

       Type       * _ptr;
       int          _nb;
       int          _capa;
};



#endif /*! _ELISE_GAR_COLL_TPL_H */
