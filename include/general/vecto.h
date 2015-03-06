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




#ifndef _ELISE_GENERAL_VECTO_H
#define _ELISE_GENERAL_VECTO_H



template <class T> class ElFifo;
template <class T> class ElFilo;
template <class T> class ElPartition;
class Seg2d;

class Br_Vect_Action : public RC_Object
{
     public :

        friend class Vector_Skel;

        virtual void action
                     (
                          const ElFifo<Pt2di> &,
                          const ElFifo<int>   *,
                          int               nb_atr
                     ) =0;

};

Fonc_Num  sk_vect( Fonc_Num f,Br_Vect_Action * act);



class Cont_Vect_Action 
{
     public :

        virtual void action
                     (
                          const ElFifo<Pt2di> &,
                          bool                ext
                     ) =0;
     virtual ~Cont_Vect_Action() {}

};            

void explore_cyle (Cont_Vect_Action  * act,ElFifo<Pt2di> & pts,Im2D_U_int1 im);
Fonc_Num  cont_vect(Fonc_Num f,Cont_Vect_Action * act,bool cx8);


class ArgAPP
{
      public :

        typedef enum
        {
            D2_droite,
	    DMaxDroite
        } ModeCout;


        typedef enum
        {
            Extre,
            MeanSquare
        } ModeSeg;


        ArgAPP
        (
                double_t prec,
                int nb_jump,
                ModeCout mcout,
                ModeSeg mseg,
                bool    freem_sup = true,
                int nb_step = 100000
         ) ;




        double_t      _prec;
        int       _nb_jump;
        ModeCout  _mcout;
        ModeSeg   _mseg;
        bool      _freem_sup;
        int       _nb_step;
	double_t      mDMax;

	bool InitWithEnvConv() const;
	void SetInitWithEnvConv();

      private :
	bool      mInitWithEnvConv;
};

void approx_poly(ElFifo<int> & res,const ElFifo<Pt2di> &,ArgAPP arg);
void approx_poly(ElFifo<int> & res,const ElFifo<Pt2dr> &,ArgAPP arg);
std::vector<int>  approx_poly(const std::vector<Pt2dr> &,bool circ,ArgAPP arg);



/************************************************************/
/*                                                          */
/*                 RASTER / VECTEUR                         */
/*                                                          */
/************************************************************/
double_t FixedSomSegDr 
     ( 
          Im2D<int1,int> im, 
          Pt2dr p1, 
          Pt2dr p2, 
          int NBPts, 
          double_t DefOut
    );


template <class Type,class TypeBase>
Seg2d   OptimizeSegTournantSomIm
        (
             double_t &                 score,
             Im2D<Type,TypeBase>    im,
             Seg2d                  seg,
             int                    NbPts,
             double_t                   step_init,
             double_t                   step_limite,
             bool                   optim_absc  = true,
             bool                   optim_teta  = true,
			 bool   *               FreelyOpt = 0
        );                                  


Pt2dr  prolongt_std_uni_dir
       (
            Im2D<int1,int>    im,
            const Seg2d   &   seg,
            double_t              step,
            double_t              vlim
       );

Seg2d  prolongt_std_bi_dir
       (
            Im2D<int1,int>    im,
            const Seg2d   &   seg,
            double_t              step,
            double_t              vlim
       );

Seg2d  retract_std_bi_dir
       (
            Im2D<int1,int>    im,
            const Seg2d   &   seg,
            double_t              step,
            double_t              vlim
       );

Seg2d  retr_prol_std_bi_dir
       (
            Im2D<int1,int>    im,
            const Seg2d   &   seg,
            double_t              step,
            double_t              vlim
       );




class  Optim2DParam
{
     public :
         virtual ~Optim2DParam() {}
         Pt2dr   param() { return _param;}
         double_t    ScOpt() {return mScOpt;}
         void  optim();
         void  optim(Pt2dr aValInit);
         double_t  def_out() {return _def_out;}


         bool  FreelyOptimized()
         {
              return mFreelyOpt;
         }
         void reset();
           


     protected :
         Optim2DParam
         (
              double_t    step_lim,
              double_t    def_out,  // Valeur tjs < ou > a la val cur
              double_t    epsilon, //  les dif < espilon sont negligee
              bool    Maxim,   
              double_t    lambda = 0.5,
              bool    optim_p1 = true,
              bool    optim_p2 = true
         );
         void set(double_t aStepInit,int aSzVInit);


     private :
         virtual double_t Op2DParam_ComputeScore(double_t,double_t) = 0;
         void  optim_step_fixed ();

         double_t       _step_lim;
         double_t       _step_cur;
         Pt2dr      _param;
         double_t       _def_out;
         double_t       _epsilon;
         bool       _Maxim;
         double_t       _lambda;
         bool       _optim_p1;
         bool       _optim_p2;

         bool       mFreelyOpt;
         double_t       mStepInit;
         int        mSzVoisInit;
         double_t       mScOpt;
};



template <class Type> class TImageFixedCorrelateurSubPix;

template <class Type> class OptimTranslationCorrelation : public Optim2DParam
{
      public :
           ~OptimTranslationCorrelation();

           OptimTranslationCorrelation
           (
                  double_t    aStepLim,
                  double_t    aStepInit,
                  int     aSzVoisInit,
                  Im2D<Type,int> aF1,
                  Im2D<Type,int> aF2,
                  double_t aSzVignette,
                  double_t aStepIm
            );
            void SetP0Im1(Pt2dr  aP0Im1);

            double_t mSc;

      private :

           double_t ScoreFonc(double_t,double_t);
//           double_t ScoreOptim(double_t,double_t);
// Modif DB
           double_t Op2DParam_ComputeScore(double_t,double_t);

           Im2D<Type,int> mIm1;
           Im2D<Type,int> mIm2;

           Pt2dr   mP0Im1;
           double_t    mSzVignette;
           double_t    mStepIm;

           TImageFixedCorrelateurSubPix<Type> & mQuickCorrel;
           bool  mCanUseICorrel;

};






#endif // _ELISE_GENERAL_VECTO_H

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
