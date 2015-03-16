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


#ifndef _ELISE_GENERAL_OPERATOR_OPERASSOCMIXTE_H
#define _ELISE_GENERAL_OPERATOR_OPERASSOCMIXTE_H

#include <Fonc_Num>
#include <OperBinMixte>
#include <micmac_global.h>

class OperAssocMixte : public OperBinMixte 
{

   public :

     typedef enum
     {
         Sum,
         Max,
         Min,
         Mul
     } Id;
     inline Id id() const  { return _id;}

   protected :
     OperAssocMixte(Id);
   public :

     virtual double_t opel(double_t,double_t) const;
     virtual int  opel(int ,int ) const =0;

     virtual Fonc_Num opf(Fonc_Num,Fonc_Num) const = 0;

     virtual int  red_tab(const int  *,int nb,int     v_init) const =0;
     virtual int   ineutre(void) const =0;
     inline int red_tab (const int  * vals,int nb) const
     {
             return red_tab(vals,nb,ineutre());
     }
     inline void  set_neutre(int & v) const {v = ineutre();}
    
     virtual double red_tab(const double *,int nb,double    v_init) const =0;
     virtual double  rneutre(void) const =0;
     inline double red_tab (const double  * vals,int nb) const
     {
             return red_tab(vals,nb,rneutre());
     }


     long double red_tab (const long double  * /*vals*/,int /*nb*/) const
     {
         ELISE_ASSERT(false,"No Red Tab Long Double");
         return 0;
     }


     inline void  set_neutre(double& v) const {v = rneutre();}

      virtual void integral(int *out,const int * in,int nb) const = 0;
      virtual void integral(double *out,const double * in,int nb) const = 0;

      virtual void reduce_seg
           ( int * out, const int * in, int * buf_av, int * buf_ar,
             int   x_min, int   x_max, int  dx0, int   dx1) const = 0;

      virtual void reduce_seg
           ( double * out, const double * in, double * buf_av, double * buf_ar,
             int   x_min, int   x_max, int  dx0, int   dx1) const = 0;

     virtual bool grp_oper() const;

     virtual void t0_eg_t1_opinv_t2(int  * t0,const int  * t1,const int  *t2,int nb) const;
     virtual void t0_eg_t1_opinv_t2(double  * t0,const double  * t1,const double  *t2,int nb) const;


     virtual void t0_opinveg_t1(int  * t0,const int  * t1,int nb) const;  // -=
     virtual void t0_opinveg_t1(double  * t0,const double  * t1,int nb) const;

     virtual void t0_opeg_t1(int  * t0,const int  * t1,int nb)  const;     // +=
     virtual void t0_opeg_t1(double  * t0,const double  * t1,int nb)  const;

     virtual const char * name () const = 0;
     virtual ~OperAssocMixte() {}

   private :

     Id _id ;
};

#endif
