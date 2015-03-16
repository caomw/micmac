/*Header-MicMac-eLiSe-25/06/2007

    MicMac : Multi Image Correspondances par Methodes Automatiques de Correlation
    eLiSe  : ELements of an Image Software Environnement

    www.micmac.ign.fr

   
    Copyright : Institut Geographique National
    Author : Marc Pierrot Deseilligny
    Contributors : Gregoire Maillet, Didier Boldo.
	Refactoring : Helio Chissini de Castro <helio@kde.org>

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



#ifndef _ELISE_GENERAL_COMPR_IM_ELIMSCROLLER_H
#define _ELISE_GENERAL_COMPR_IM_ELIMSCROLLER_H

#include "general/sys_dep.h"

class ElImScroller
{
     public :
              virtual bool CanReinitTif();
              virtual void ReInitTifFile(Tiff_Im aTif);


               void  SetAlwaysQuick(bool aVal);

               void  SetAlwaysQuickInZoom();
               void  SetAlwaysQuick();


               bool AlwaysQuick() const;

		virtual Output out(); //  Output::onul();
		virtual Fonc_Num in(); // 0
                virtual double_t  GetValPtsR(Pt2dr aP);  // Def Erreur Fatale

                virtual void Sauv(const std::string & aName);
                virtual void SetPoly(Fonc_Num ,std::vector<Pt2dr>);
                virtual void ApplyLutOnPoly(Fonc_Num ,std::vector<Pt2dr>);

                 Flux_Pts ContVect2RasFlux(std::vector<Pt2dr> VPts);

		// DEBUG-OPTIM-MAP ;
		virtual double_t TimeLoadXIm() const; // 0.0
		virtual double_t TimeUnCompr() const; // 0.0
		virtual double_t TimeReformat() const; // 0.0



		// Si EchAcc = 0, ou si EchAcc->size() =0, alors aucune selection n'est
		// faite
	    static ElPyramScroller * StdPyramide
				     (
					Visu_ElImScr &Visu,
					const std::string &,
					std::vector<int> * EchAcc =0,
					bool Adapt =false,
					bool ForceGray =false
			);

	    friend class ElPyramScroller;

        virtual ~ElImScroller();

        void LoadAndVisuIm(bool quick = false);
        void LoadAndVisuIm(Pt2di aPW0,Pt2di aPW1,bool quick = false);
        void LoadIm(bool quick = false);
        void VisuIm(bool Quick);
        void VisuIm(Pt2di PW0,Pt2di PW1,bool Quick);

        void set(Pt2dr tr,double_t sc,bool quick = false);
        void set_max(bool quick = false);
        void set_max_init();
        void SetSameGeom(const ElImScroller &);
        void SetGeomTranslated(const ElImScroller &,Pt2dr tr);

		ModelBoxSubstr SetDTrW(Pt2di tr);
        void SetTrU(Pt2dr tr);
		void SetScArroundPW(Pt2dr PinvW,double_t sc,bool quick = false);

        Pt2dr to_win(Pt2dr p)  const {return  (p-_tr) *_sc;}
        Pt2dr to_user(Pt2dr p) const
		{
				return _tr + p/_sc;
		}



         ElSimilitude to_user () const {return ElSimilitude(_tr,Pt2dr(1/_sc,0.0));}
         ElSimilitude to_win () const  {return to_user ().inv();}

         // transforme une similitude WW en une similitude UU
         ElSimilitude WW2UU (ElSimilitude aSim) const
         {
              return to_user () * aSim * to_win ();
         }



        Pt2di           SzW()  const {return  _SzW;}
        Pt2di           SzU()  const {return  _SzU;}
        // TCompl
        Pt2di           SzUIm()  const {return  Pt2di(Pt2dr(_SzU) / _sc_im);}


        void LoadXImageInVisu(Visu_ElImDest &,Pt2di p0W,Pt2di p1W,bool quick);
        void LoadXImageInVisu(Visu_ElImDest &,Pt2di p0W,Pt2di p1W,bool quick,Pt2dr tr,double_t sc);

	// Plutot utilisee pour la mise au point
        Pt2dr tr() const {return _tr;}
        double_t sc() const {return _sc;}
        double_t sc_abs() const {return _sc * _sc_im;}
        double_t sc_im() const {return  _sc_im;}

		int DimOut() const {return mDimOut;}
        Visu_ElImScr &  VisuStd () { return mVisuStd;}

		Pt2dr TrOfScArroundPW(Pt2dr aPinvW,double_t aNewSc);
     protected :

        ElImScroller
        (
            Visu_ElImScr &Visu,
		    int  aDimOut,
            Pt2di SzU,
            double_t  sc_im = 1.0
        );

        double_t ScMax() const;

        virtual void no_use();

        Pt2di           _SzW;
        Pt2di           _SzU;
        void write_image(int x0src,Pt2di p0dest,int nb,int ** data)
		{
				mVisuCur->write_image(x0src,p0dest,nb,data);
		}
		void SetVisuCur(Visu_ElImDest *);
		double_t mTimeLoadXIm;
		double_t mTimeReformat;




     public :

	    static ElImScroller * StdScrollIfExist(Visu_ElImScr &Visu,const std::string &,double_t scale,bool Adapt,bool ForceGray);
     private :
	    static ElImScroller * StdFileGenerique(Visu_ElImScr &Visu,const std::string &,int  InvScale,bool Adapt,bool ForceGray);




		virtual void ReflexSetVisuCur(Visu_ElImDest *);

        virtual void LoadXImage(Pt2di p0W,Pt2di p1W,bool quick) =0;
        void LoadAndVerifXImage(Pt2di p0W,Pt2di p1W,bool quick) ;

        Visu_ElImScr &  mVisuStd; // celui par defaut
        Visu_ElImDest *  mVisuCur; // celui utilise dans  LoadXImage(Visu_ElImScr &,..)


		int                     mDimOut;
        Pt2dr                       _tr;
        double_t                        _sc;
		const double_t               _sc_im;

        bool mAlwaysQuickInZoom;
        bool mAlwaysQuick;
        bool mSetInit;

        void set_geom(Pt2dr tr,double_t sc);
		bool  image_full_in() ;
		Pt2di PrefXim();
        void GetIntervUpdate(int dx,int tx,int &x0,int & x1);
        enum
        {
            RabUpdate = 2
        };
		ElImScroller(const ElImScroller &);
};

#endif
