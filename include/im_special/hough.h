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



#ifndef _ELISE_IM_SPECIAL_HOUGH_H_
#define _ELISE_IM_SPECIAL_HOUGH_H_



/************************************************************/
/*                                                          */
/*                 HOUGH-TRANSF                             */
/*                                                          */
/************************************************************/

class ElHough : public Mcheck
{
	public :
		typedef enum
		{
			eModeValues,
			eModeGradient
		} tModeAccum;



		// Fonction relativement couteuses car font appel a des transfo de
		// hough

		virtual double_t DynamicModeValues() = 0;
		virtual double_t DynamicModeGradient() = 0;
		double_t Dynamic(tModeAccum) ;


		static void BenchPolygoneClipBandeVert();


		Pt2di SzXY() const {return Pt2di(mNbX,mNbY);}
		Pt2di SzTR() const {return Pt2di(mNbTeta,mNbRho);}
		Pt2di SzTR_Tot() const {return Pt2di(NbTetaTot(),mNbRho);}

		int NbX() const {return mNbX;}
		int NbY() const {return mNbY;}
		int NbTeta() const {return mNbTeta;}
		int NbRho() const {return mNbRho;}
		virtual int NbRabTeta() const =0;
		virtual int NbRabRho()  const =0;
		int NbTetaTot()  const {return NbTeta()+2*NbRabTeta();}

                typedef enum
                {
                    ModeBasic,
                    ModeBasicSubPix,
                    ModeStepAdapt, // Basic + pas rho adaptatif
                    ModePixelExact
                } Mode;

            static ElHough * NewOne
                             (
                                  Pt2di Sz,     // taille en XY
                                  double_t StepRho,  // Pas en pixel
                                  double_t StepTeta, // Pas en equiv pixel pour la diag
                                  Mode,          // mode d'accum
                                  double_t RabRho,   // rab en pixel sur l'accum
                                  double_t RabTeta   // rab en radian sur l'accum
                              );
            static ElHough * NewOne(const std::string &);

            virtual Im2D_int4 PdsInit() = 0;
            virtual int NbCel() const = 0;
            virtual void write_to_file(const std::string & name) const = 0 ;


            // ON PASSE L'IMAGE de POIDS CA RETOURNE L'ACCUMULATEUR
            virtual Im2D_int4 Pds(Im2D_U_int1) =0;

            // ON PASSE L'IMAGE CA RETOURNE L'ACCUMULATEUR, CA UTILISE l'ANGLE DU GRAD, il
            // doit etre reetale entre 0 et 256
            //
            virtual Im2D_int4 PdsAng(Im2D_U_int1 aImPds,Im2D_U_int1 aImTeta,double_t Incert,bool IsGrad=true) =0;

            virtual Seg2d Grid_Hough2Euclid(Pt2dr) const = 0;
            virtual Pt2dr Grid_Euclid2Hough(Seg2d) const = 0;
            virtual  void CalcMaxLoc
                     (   
                         Im2D_int4,
                         std::vector<Pt2di> & Pts, 
                         double_t VoisRho, 
                         double_t VoisTeta, 
                         double_t Vmin
                     ) = 0;  

            virtual bool BandeConnectedVsup
                         (
                              Pt2di       p1,
                              Pt2di       p2,
                              Im2D_int4   Im,
                              int         VInf,
                              double_t        Tol
                         ) = 0;
             virtual void FiltrMaxLoc_BCVS
                          (
                                std::vector<Pt2di> & Pts,
                                Im2D_int4 Im,
                                double_t  FactInf,
                                double_t  TolGeom,
                                double_t   VoisRho,
                                double_t   VoisTeta
                          ) = 0;         

            virtual ~ElHough();


     protected :
		ElHough(Pt2di Sz,double_t StepTeta);
		void SetNbRho(int);
        double_t LongEstimTeta() const;

		double_t       mStepTetaInit;
     private :
		const int  mNbX;
		const int  mNbY;
		const int  mNbTeta;
		int        mNbRho;
		Mode       mMode;

         // Non Implem
         ElHough(const ElHough &);
         void operator = (const ElHough &);
};               


void ElSegMerge(std::vector<Seg2d> & VecInits,double_t dLong,double_t dLarg);



class EHFS_PrgDyn;

class ElHoughFiltSeg // : public ElHoughFiltSeg
{
      public :

         ElHoughFiltSeg(double_t Step,double_t Width,double_t LentghMax,Pt2di SzBox);
         virtual ~ElHoughFiltSeg();
         void SetSeg(const SegComp &);


         Pt2dr  Abs2Loc(const Pt2dr & p) const {return mP02Loc + mCS2Loc * p;}
         Pt2dr  Loc2Abs(const Pt2dr & p) const {return mP02Abs + mCS2Abs * p;}



                                                  
                                                  

          Pt2di SzMax() const;
          Pt2di SzCur() const;
          int   YCentreCur() const ; 
   
          void GenPrgDynGet(std::vector<Seg2d> &,double_t dMin);



		  // Marche pour Im2D_U_int1 et Im2D_int1, car fait appel OptimSeg ...
          Seg2d ExtendSeg(SegComp s0,double_t DeltaMin,Im2DGen & Im);

          double_t Step() const {return mStep;}

          virtual double_t CostState(bool IsSeg,int Abcisse) = 0;
          virtual double_t CostChange ( bool IsSeg, int Abcisse, int Abcisse2); 
          virtual double_t AverageCostChange () = 0; 
          virtual bool ExtrFree(); // return false
          virtual double_t CostNeutre() ;  // 0.5


		  void ExtendImage_proj(Im2D_U_int1,int Delta = (1<<30));
      protected  :

          Seg2d OneExtendSeg (bool& Ok,SegComp s0,Im2DGen & Im);
          void MakeIm(Im2D_U_int1 Res,Im2D_U_int1 InPut,U_int1 def);
          void MakeIm(Im2D_int1 Res,Im2D_int1 InPut,int1 def);
		  virtual void UpdateSeg() = 0;

      // private :

         void VerifSize(Im2D_U_int1 anIm);
         void VerifSize(Im2D_int1 anIm);
         void VerifSize(Im1D_U_int1 anIm);

/*          static const int  NbBits = 8; */
	 enum { NbBits = 8 };
         
         double_t                    mStep;
         double_t                    mWidthMax;
         double_t                    mLengthMax;
         int                     mNbXMax;
         int                     mNbYMax;

         double_t                    mLength;
         int                     mNbX;

         Pt2dr                        mInvTgtSeg;
         Pt2dr                        mCS2Loc;
         Pt2dr                        mP02Loc;
         Pt2dr                        mCS2Abs;
         Pt2dr                        mP02Abs;
         EHFS_PrgDyn *                mPrgDyn;
         std::vector<std::pair<int,int> >  mVPairI;
         std::vector<Seg2d>           mVSegsExt;
		 Box2di                       mBox;

};



class EHFS_ScoreIm : public ElHoughFiltSeg
{
      public :

          EHFS_ScoreIm
		  (
		       double_t         Step,
			   double_t         Width,
			   double_t         LentghMax,
			   Im2D_U_int1  ImGlob,
			   double_t         CostChg,
			   double_t         VMinRadiom = 255.0
		  );

          Im2D_U_int1  ImLoc();
		  void ExtendImage_proj(int Delta = (1<<30));

	  private :

          virtual double_t CostState(bool IsSeg,int Abcisse);
          virtual double_t AverageCostChange ();

		  void UpdateSeg();

          Im2D_U_int1             mImLoc;
		  U_int1 *                mGainIfSeg;
          Im2D_U_int1             mImGlob;
          double_t                    mCostChg;      
		  double_t                    mVminRadiom;
};





class EHFS_ScoreGrad : public ElHoughFiltSeg
{
      public :

          EHFS_ScoreGrad
		  (
		       double_t         Step,
			   double_t         Width,
			   double_t         LentghMax,
			   Im2D_int1    ImGlobGX,
			   Im2D_int1    ImGlobGY,
			   double_t         CostChg,
			   double_t         EcarTeta,
			   double_t         EcarMaxLoc,
			   double_t         SeuilGrad
		  );

          Im2D_U_int1 ImLocGRho();
          Im2D_U_int1 ImLocGTeta();
          Im1D_U_int1 ImMaxLoc();

		  void TestGain(int x);

      private  :

          void MakeImGradXY ( Im2D_int1 OutGx, Im2D_int1 OutGy,
                              Im2D_int1 InPutGx, Im2D_int1 InPutGy,
                              int1 def
                            );

          void MakeImGradRhoTeta
                            ( Im2D_U_int1 OutRho, Im2D_U_int1 OutTeta,
                              Im2D_int1 InPutGx, Im2D_int1 InPutGy,
                              int1 def
                            );

          void   MakeImMaxLoc(Im1D_U_int1 ImMaxLoc,Im2D_U_int1 InRho);

		  void MakeGainIfSeg();

         virtual double_t CostState(bool IsSeg,int Abcisse);
         virtual double_t AverageCostChange();

		 void UpdateSeg();

         Im2D_int1        mImLocGX;
         Im2D_int1        mImLocGY;
         Im2D_U_int1      mImLocGRho;
		 U_int1 **        mDataLocRho;
         Im2D_U_int1      mImLocGTeta;
		 U_int1 **        mDataLocTeta;
         Im1D_U_int1      mImYMaxLoc;
	     U_int1 *         mDataYMaxLoc;

         Im2D_int1        mImGlobGX;
         Im2D_int1        mImGlobGY;

		 double_t             mCostChgt;

		 //double_t             mEcarTeta;
         Im1D_double_t8       mPdsTeta;
         double_t8 *          mDataPdsTeta;

		 //double_t8            mEcarMaxLoc;
         Im1D_double_t8       mPdsMaxLoc;
         double_t8 *          mDataPdsMaxLoc;

		 //double_t8            mSeuilGrad;
         Im1D_double_t8       mPdsRho;
         double_t8 *          mDataPdsRho;    

         Im1D_double_t8       mGainIfSeg;
		 double_t8 *          mDataGainIfSeg;
};



#endif // _ELISE_IM_SPECIAL_HOUGH_H_


















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
