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



#ifndef _ELISE_GENERAL_MORPHO_H
#define _ELISE_GENERAL_MORPHO_H

class Chamfer
{
      public :


        inline const int *   pds ()      const { return _pds;}
        inline const Pt2di * neigh ()    const { return _neigh;}
        inline int           nbv ()      const { return _nbv;}

        //  sub-neigh y >= 0
        inline const int *   pds_yp ()   const { return _pds_yp;}
        inline const Pt2di * neigh_yp () const { return _neigh_yp;}
        inline int           nbv_yp ()   const { return _nbv_yp;}

        //  sub-neigh y <= 0
        inline const int *   pds_yn ()   const { return _pds_yn;}
        inline const Pt2di * neigh_yn () const { return _neigh_yn;}
        inline int           nbv_yn ()   const { return _nbv_yn;}

        //  p_0_1 must return pds for x =0, y =1;  default
        // is return  _p[0];
        // ex :  p_0_1 for d4,d8; p_0_1 =2 for d32, p_0_1 = 5 for d5711

        virtual int  p_0_1 () const;

        //  radius  maxim of (|xi|,|yi|)
        //  2 for d5711, 1 for d4,d8,d32
        virtual int  radius () const =0;



        void im_dist(Im2D<U_int1,int>) const;
        void dilate_label(Im2D<U_int1,int> im_dist,Im2D<int,int> label,int dmax) const;
	virtual ~Chamfer() {}

        static const Chamfer & d4;
        static const Chamfer & d8;
        static const Chamfer & d32;
        static const Chamfer & d5711;
     protected :

        // only valuable for d4,d8 d32
        Chamfer(const Pt2di *,int,const int *,int * v_lin);

      private :

          const Pt2di *   _neigh;
          int             _nbv;
          const int *     _pds;

          const Pt2di *   _neigh_yp;
          int             _nbv_yp;
          const int *     _pds_yp;

          const Pt2di *   _neigh_yn;
          int             _nbv_yn;
          const int *     _pds_yn;
          int *           _v_lin;

};



class ArgSkeleton : public PRC0
{
      public :
          static const ElList<ArgSkeleton> L_empty;
          class Modif_Arg_Skel * das() const
                {return SAFE_DYNC(class Modif_Arg_Skel *,_ptr);}
      protected :
         ArgSkeleton (class Modif_Arg_Skel *);
      private :
};

typedef ElList<ArgSkeleton> L_ArgSkeleton;
L_ArgSkeleton NewLArgSkel(ArgSkeleton);

class AngSkel : public ArgSkeleton
{
     public :
        AngSkel(double_t);
};

class SurfSkel : public ArgSkeleton
{
     public :
        SurfSkel(int);
};

class SkelOfDisk : public ArgSkeleton
{
     public :
        SkelOfDisk(bool);
};

class ProlgtSkel : public ArgSkeleton
{
     public :
        ProlgtSkel(bool);
};

class ResultSkel : public ArgSkeleton
{
     public :
        ResultSkel(bool);
};


class Cx8Skel : public ArgSkeleton
{
     public :
        Cx8Skel(bool);
};

class TmpSkel : public ArgSkeleton
{
     public :
        TmpSkel(Im2D_U_int2);
};

extern const Pt2di ElSzDefSkel;

Liste_Pts_U_int2  Skeleton
(
     Im2D_U_int1  skel,
     Im2D_U_int1  image,
     L_ArgSkeleton  = ArgSkeleton::L_empty,
     Pt2di          SZ = ElSzDefSkel
);

Im1D_U_int1 NbBits(int nbb);

Fonc_Num skeleton
         (
             Fonc_Num f,
             int max_d = 256,
             L_ArgSkeleton = ArgSkeleton::L_empty
         );

Fonc_Num skeleton_and_dist
         (
             Fonc_Num f,
             int max_d = 256,
             L_ArgSkeleton = ArgSkeleton::L_empty
         );



/**********************************************/
/*                                            */
/*            ParamConcOpb                    */
/*                                            */
/**********************************************/
class EliseRle
{
    public :
       typedef  ElFifo<EliseRle> tContainer;
       typedef int            tIm;

       EliseRle(int x0,int x1,int y) : mX0(x0),mX1(x1),mY(y) {}
       EliseRle() : mX0(0),mX1(0),mY(0){}

       inline int X0() const {return mX0;}
       inline int X1() const {return mX1;}
       inline int Y0() const {return mY ;}
       inline int Y1() const {return mY+1 ;}
       inline int NB() const {return mX1-mX0;}

       Pt2di P0() {return Pt2di(X0(),Y0());}
       Pt2di P1() {return Pt2di(X1(),Y1());}

       static Box2di  ConcIfInBox
				      (
						Pt2di  pInit,
						tContainer & V,
						tIm ** im,
						tIm vTest,
						tIm vSet,
						bool   v8    ,
						Pt2di  SzBox
					);

	    static void SetIm(tContainer & V,tIm ** anIm,tIm vSet);


	private :
		friend class EliseSurfRle;
		inline void UpdateBox(Pt2di & p0,Pt2di & p1) const;

	    inline EliseRle(int x0,int y,tIm ** im,tIm vTest,tIm vSet);
	    inline void AddRleVois(tContainer & V,tIm ** im,
	    tIm vTest,tIm vSet,bool v8) const;
	    inline void SetIm(tIm ** anIm,tIm vSet);
	    int mX0,mX1,mY;
};


template <class Type> void RleDescOfBinaryImage(Im2D<Type,int>,EliseRle::tContainer &);

class ParamConcOpb : public Mcheck
{
    public :

       virtual bool ToDelete(); // Vrai par defaut
       virtual int ColBig();    // 2 par defaut
       virtual int ColSmall(const EliseRle::tContainer &,const Box2di &,int ColInit); // 3 par def
       virtual ~ParamConcOpb    () {}

	   static int  DefColBig();
	   static int  DefColSmall();

    private  :
};

Fonc_Num  BoxedConc(Fonc_Num f,Pt2di SzBox,bool V8,ParamConcOpb * param,bool aCatInit = false);
Fonc_Num  BoxedConc(Fonc_Num f,Pt2di SzBox,bool V8,bool aCatInit = false);

//  Not to use, only for bench purpose
Fonc_Num  BoxedConc(Fonc_Num f,Pt2di SzBox,bool V8,ParamConcOpb * param,int per_reaf,bool aCatInit = false);



/*******************************************************/
/*                                                     */
/*              ElImplemDequantifier                   */
/*                                                     */
/*******************************************************/

class ElImplemDequantifier
{
     public :
         // Anncienne interface, anEquid est un parametre idiot !
         // void Dequant(Pt2di aSzIm,Fonc_Num f2Deq,int anEquid);


         // aVerifI verifie que l'image est entiere
         void DoDequantif(Pt2di aSzIm,Fonc_Num f2Deq,bool  aVerifI= false);

         ElImplemDequantifier (Pt2di aSz);

         Fonc_Num ImDeqReelle();
         Fonc_Num PartieFrac(int ampl);
         Im2D_U_int2   DistPlus();
         Im2D_U_int2   DistMoins();

         void SetTraitSpecialCuv(bool);

     private :
         friend void TEST_DEQ();

         void Test();
         void OnePasse
              (
                  int aP0,int aStepP, int aPend,
                  int aNbV,int * mV,int * mP
              );
         void OnePasseVideo();
         void OnePasseInverseVideo();
	 void TraitCuv(U_int2* aDA,U_int2* aDB);

         void SetSize(Pt2di aSz);
         void SetChamfer(const Chamfer & aChamf);
         void QuickSetDist(int aNbStep);

         Pt2di mSzReel;
         int   mNbPts;


         int     mNbVYp;
         int     mVYp[20];
         int     mPdsYp[20];

         int     mNbVYm;
         int     mVYm[20];
         int     mPdsYm[20];

         int     mNbVYT;
         int     mVYT[20];
         int     mPdsYT[20];

         typedef int2  tQuant;
         typedef U_int2  tDist;


         enum
         {
                eValOut =  El_CTypeTraits<tQuant>::eVMin,
		eMaxDist = El_CTypeTraits<tQuant>::eVMax
         };

	 bool          mTraitCuv;
         Im2D_int2     mImQuant;
         int2 *        lDQ;
         Im2D_U_int2   mDistPlus;
         U_int2 *      mDPL;
         Im2D_U_int2   mDistMoins;
         U_int2 *      mDM;
         Im2D_double_t4    mImDeq;

};

// Projette sur un ensemble au sens de la distance 32
class cResProj32
{
    public :
        // La distance est "cadeau" au sens ou de toute facon
        // il est necessaire de la calculer

        cResProj32(Im2D_U_int2 aD,Im2D_U_int2 aPX,Im2D_U_int2 aPY,bool aIsInit,bool aIsFull);

        bool        IsInit() const;
        bool        IsFull() const;
        Im2D_U_int2 Dist() const;
        Im2D_U_int2 PX() const;
        Im2D_U_int2 PY() const;
   private :
        void AssertIsInit() const;

        bool        mIsInit;
        bool        mIsFull;
        Im2D_U_int2 mDist;
        Im2D_U_int2 mPX;
        Im2D_U_int2 mPY;
};

cResProj32 Projection32(Fonc_Num aF,Pt2di aSz);

//  Filtrage divers adapte aux carte de profondeur :

class cParamFiltreDepthByPrgDyn;
Im2D_Bits<1>    FiltrageDepthByProgDyn(Im2D_double_t4 aImDepth,Im2D_U_int1 aImLab,const cParamFiltreDepthByPrgDyn & aParam);

class cParamFiltreDetecRegulProf;
extern Im2D_Bits<1>  FiltreDetecRegulProf(Im2D_double_t4 aImProf,Im2D_Bits<1> aIMasq,const cParamFiltreDetecRegulProf & aParam);

Im2D_double_t4 ReduceImageProf(double aDifStd,Im2D_Bits<1> aIMasq,Im2D_double_t4 aImProf, const Box2dr &aBox,double aScale,Im2D_double_t4 aImPds,std::vector<Im2DGen*>  aVNew,std::vector<Im2DGen*> aVOld);
Im2D_double_t4 ReduceImageProf(double aDifStd,Im2D_Bits<1> aIMasq,Im2D_int2 aImProf, const Box2dr &aBox,double aScale,Im2D_double_t4 aImPds,std::vector<Im2DGen*>  aVNew,std::vector<Im2DGen*> aVOld);



#endif // _ELISE_GENERAL_MORPHO_H

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
