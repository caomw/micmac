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



#ifndef _ELISE_FONC_NUM_H
#define _ELISE_FONC_NUM_H


/************************************************************************************

      Fonc_Num_Computed :

icste : with this method, a Fonc_Num_Computed indicate id it is an integer constant
     function and, evntually, what is the value of this constant. 
     Most object will ignore
     this fact and will treat constant function like others. Only object that
     can have special optimization with constant (like X windows with not rle mode)
     will decide to use them.

*************************************************************************************/


std::vector<double> MakeVec1(const double & aD);

class Arg_Fonc_Num_Comp;

class Fonc_Num_Computed : public Mcheck
{
      public :
           virtual const Pack_Of_Pts * values(const Pack_Of_Pts *) = 0;

           virtual bool  icste( int *); // in fact int[ELise_Std_Max_Dim]

           inline int  idim_out(void) const {return _dim_out;}
           inline Pack_Of_Pts::type_pack      type_out(void) const {return _type_out;}


           bool integral () const;
          virtual ~Fonc_Num_Computed();
 
      protected :          

          Fonc_Num_Computed(const Arg_Fonc_Num_Comp &,int dim_out,Pack_Of_Pts::type_pack type_out);
          
          int                                  _dim_out;
          Pack_Of_Pts::type_pack               _type_out;
          Flux_Pts_Computed *                  _flux_of_comp;

      private :

};

class Arg_Fonc_Num_Comp
{
      public :
         
         Arg_Fonc_Num_Comp(Flux_Pts_Computed *);
         inline Flux_Pts_Computed * flux() const {return _flux;}

     private :
         Flux_Pts_Computed * _flux;
};


class  cECFN_SetString;
class  cDico_SymbFN;
class cDico_Compiled;

class cElCompiledFonc
{
      public :
	  typedef cElCompiledFonc * (* tAllocObj)();
/*
          virtual void Compute(double *) = 0;
          double_t Val()         const {return mVal;}
          double_t Deriv(int aK) const {return mDer[aK];}
          int  NbVar()       const {return mNbVar;}
*/


         std::string & NameAlloc();
          static cElCompiledFonc * AllocFromName(const std::string &);
         // Renvoie 0 si pas un des champs de la structure
	 
         virtual double * AdrVarLocFromString(const std::string &) =0;
         double * RequireAdrVarLocFromString(const std::string &);

         void SetMappingCur(const cIncListInterv &,cSetEqFormelles *);
         const cIncListInterv &  MapRef() const;
         void SetCoordCur(double * aRealCoord);

         void ComputeValAndSetIVC();

// Debug, aucune verif sur init !! Dangereux hors debug
         double_t ValBrute(int aD)         const;

         double_t Val(int aD)         const;
         double_t Deriv(int aD,int aK) const;
         double_t DerSec(int aD,int aK1,int aK2) const;
	 const std::vector<double> &   Vals() const;

        
	 void SVD_And_AddEqSysSurResol
              (
                   bool isCstr,
                   const std::vector<int> & aVInd,
                   double_t aPds,
                   double_t *       Pts,
                   cGenSysSurResol & aSys,
                   cSetEqFormelles & aSet,
                   bool EnPtsCur
              );
	 void SVD_And_AddEqSysSurResol
              (
                   bool isCstr,
                   const std::vector<int> & aVInd,
                   const std::vector<double> & aVPds,
                   double_t *       Pts,
                   cGenSysSurResol & aSys,
                   cSetEqFormelles & aSet,
                   bool EnPtsCur
              );



	 void Std_AddEqSysSurResol
              (
                   bool   isCstr,
                   double_t aPds,
                   double_t *       Pts,
                   cGenSysSurResol & aSys,
                   cSetEqFormelles & aSet,
                   bool EnPtsCur
              );
	 void Std_AddEqSysSurResol
              (
                   bool   isCstr,
                   const std::vector<double> & aVPds,
                   double_t *       Pts,
                   cGenSysSurResol & aSys,
                   cSetEqFormelles & aSet,
                   bool EnPtsCur
              );



         void AddDevLimOrd1ToSysSurRes( cGenSysSurResol &,double_t aPds,bool EnPtsCur);
         void AddContrainteToSysSurRes( cGenSysSurResol &,bool EnPtsCur);
         // Ordre 2, tjs en Pts Cur
         void AddDevLimOrd2ToSysSurRes(L2SysSurResol &,double_t aPds);


         virtual ~cElCompiledFonc();

         static cElCompiledFonc * DynamicAlloc(const cIncListInterv &  aListInterv,Fonc_Num);

	 // Pour des foncteur dynamique de type Xk=Cste
         static cElCompiledFonc * FoncSetVar(cSetEqFormelles *,int Ind,bool GenCode=false);
	 static cElCompiledFonc *FoncSetValsEq
		                 (cSetEqFormelles *,int Ind1,int Ind2,bool GenCode=false);

         static const std::string NameFoncSetVar;
         double * FoncSetVarAdr();
	 
	 // Pour des foncteur dynamique de type Sigma(ak,Xk)=Cste
         static const  std::string &  NameKthAffineVar(int aNB);
         static cElCompiledFonc * FoncRappelAffine(cSetEqFormelles *,int Ind0,int NbInd);
         double * FoncAffAdrCste();
         double * FoncAffAdrKth(int aK); // A partir de 0,


         static cElCompiledFonc * FoncFixeNormEucl(cSetEqFormelles *,int Ind0,int NbInd,double_t Val,bool GenCode = false);
         static cElCompiledFonc * FoncFixeNormEuclVect(cSetEqFormelles *,int Ind0,int Ind1,int NbInd,double_t Val,bool GenCode = false);
         static cElCompiledFonc * FoncFixedScal(cSetEqFormelles *,int Ind0,int Ind1,int NbInd,double_t Val,bool GenCode = false);


	 void SetNormValFtcrFixedNormEuclid(double_t Val);

	 static cElCompiledFonc * GenFoncVarsInd
		         (cSetEqFormelles *,const std::string &aName,int aNbVar,
			  std::vector<Fonc_Num> aFonc,bool Code2Gen);
	 static cElCompiledFonc * RegulD1(cSetEqFormelles *,bool Code2Gen);
	 static cElCompiledFonc * RegulD2(cSetEqFormelles *,bool Code2Gen);



	  class cAutoAddEntry 
	  {
		public :
		  cAutoAddEntry(const std::string &,tAllocObj);
	  };
	  static void InitEntries();
          static void AddEntry(const std::string &,tAllocObj);

           void InitBloc(const cSetEqFormelles &);
      protected :


  
         void AddContrainteEqSSR(bool Contr,double_t Pds, cGenSysSurResol &,bool EnPtsCur);
	  friend class cAutoAddEntry;

	  static void AddNewEntryAlloc(const std::string &,tAllocObj);
	  static class cDico_Compiled * mDicoAlloc;
          
          cElCompiledFonc(int aDimOut);
          void AddIntRef(const cIncIntervale &);
          void Close(bool Dyn);
          void CloseIndexed();
          void AsserNotAlwaysIndexed() const;
          bool AlwaysIndexed() const;

         void SetCoord(double *); // Coordonnee non compactee
          // void SetCoordCur(double *);
         virtual void ComputeVal() = 0;
         virtual void ComputeValDeriv() = 0;
         virtual void ComputeValDerivHessian() = 0;

         virtual  void PostSetCoordCur();

	  int                     mDimOut;
          bool                    isValComputed;
          bool                    isDerComputed;
          // bool                    isHessComputed;
          bool                    isCoordSet;
          bool                    isCurMappingSet;
	  bool                    intMayOverlap;

          int                     mNbCompVar;
          // int                     mNbRealVar;
          // int                     mVarMaxComp;
          //  int                     mVarMaxReal;

      // Je pense que le mode mAlwaysIndexed devrait etre le mode
      // systematique, mais par compatibilite ...
          bool                    mAlwaysIndexed;

          std::vector<double>     mCompCoord;
          //  double *                mRealCoord;
          std::vector<int>        mMapComp2Real;
	  std::vector<std::vector<double> >    mCompDer;
	  // std::vector<std::vector<std::vector<double> > >   mCompHessian;

	  // Utile pour AddSys
	  // std::vector<std::vector<double> >    mRealDer;
          // std::vector<int>        mMapReal2Comp;

          // std::vector<int>       mListIndComp;
          // std::vector<int>       mListIndReal;

          // Pour assurer la suppression progressive de mListIndComp & co
          inline int LIC(const int &) const;

	  std::vector<double>    mVal;
         
      private :
         void SetNoInit();

         static cElCompiledFonc * FoncFixedNormScal
                   (cSetEqFormelles * aSet,int Ind0,int Ind1,int NbInd,double_t Val,bool Code2Gen,
                    cAllocNameFromInt & aNameAlloc,bool ModeNorm);

          cIncListInterv                   mMapRef;
          std::vector<cSsBloc>     mBlocs;
          std::string              mNameAlloc;
          // std::vector<double>     mBufLin;
           
};

class cElCompileFN
{
	public :

	     cElCompileFN &  operator << (const std::string &);
	     cElCompileFN &  operator << (const char *);
	     cElCompileFN &  operator << (const int &);
	     cElCompileFN &  operator << (const double &);
	     cElCompileFN &  operator << (Fonc_Num &);

	     void  PutVarNum(int aK);
	     void  PutVarLoc(cVarSpec);

             static void DoEverything
                         (
                            const std::string           &   aDir,
                            const std::string           &   aNameCl,
                            Fonc_Num                        aVar,
                            const cIncListInterv &          aList

                         );
             static void DoEverything
                         (
                            const std::string           &   aDir,
                            const std::string           &   aNameCl,
			    std::vector<Fonc_Num>           aVar,
                            const cIncListInterv &          aList

                         );

             friend class cNexisteQuePourFairePlaisiraGcc;


            static cElCompiledFonc * DynamicAlloc
                                     (
                                          const cIncListInterv &  aListInterv,
                                          Fonc_Num
                                     );

	    void AddToDict(Fonc_Num);
	    bool SqueezComp(Fonc_Num);
	private :

             ~cElCompileFN();
             cElCompileFN
             (
                 const std::string &              aNamDir,
                 const std::string &              aNameCl,
                 const cIncListInterv &           aListInterv
             );
             

             void SetFile(const std::string & aPostFixe,const char * incl);
             void CloseFile();
	     std::string  NameVarLoc(const std::string &);
             void MakeFileCpp(std::vector<Fonc_Num> );
             void MakeFonc(std::vector<Fonc_Num> f,int DegDeriv);
             void MakeFileH();

             cElCompileFN(const cElCompileFN &);      // Unimplemanted
             void operator = (const cElCompileFN &);  // Unimplemanted

 
             FILE * mFile;
             cECFN_SetString * mNamesLoc;
	     cDico_SymbFN   *  mDicSymb;
             int               mNVMax;
	     std::string       mNameVarNum;
             std::string       mPrefVarLoc;

             std::string       mNameDir;
             std::string       mNameClass;
             
             const cIncListInterv &          mListInterv;

             std::string       mNameFile;
             std::string       mNameTagInclude;
};

class Fonc_Num_Not_Comp : public RC_Object
{
      public :
         virtual  Fonc_Num_Computed * compute(const Arg_Fonc_Num_Comp &) = 0;
         virtual bool integral_fonc(bool integral_flux) const = 0;
         virtual int dimf_out() const = 0;

         virtual bool  is0() const;
         virtual bool  is1() const;
         virtual bool  IsCsteRealDim1(double_t &) const;

	 virtual void compile (cElCompileFN &);
         virtual Fonc_Num deriv(int k) const ;
         virtual void  show(std::ostream &) const ;
         virtual double_t  ValFonc(const  PtsKD &  pts) const ;
         virtual double_t  ValDeriv(const  PtsKD &  pts,int k) const ;
	 virtual int  NumCoord() const;
         virtual void VarDerNN(ElGrowingSetInd &) const = 0;
         virtual int DegrePoly() const;


         virtual Fonc_Num::tKindOfExpr  KindOfExpr();
         virtual int CmpFormelIfSameKind(Fonc_Num_Not_Comp *);
	 Fonc_Num_Not_Comp();
	 ~Fonc_Num_Not_Comp();

         std::string NameCpp();
         bool        HasNameCpp();
         void        SetNameCpp(const std::string &);

   private :
	 std::string * mNameCPP;
        // void VarDerNN(ElGrowingSetInd &)const {ELISE_ASSERT(false,"No VarDerNN");}
};


class Op_Bin_Not_Comp : public Fonc_Num_Not_Comp
{
      public :
         typedef double   (* TyVal)  (double,double);
         typedef Fonc_Num (* TyDeriv)(Fonc_Num,Fonc_Num,int k);
         typedef double   (* TyValDeriv)(Fonc_Num,Fonc_Num,const  PtsKD &,int k);

         virtual  Fonc_Num_Computed * compute(const Arg_Fonc_Num_Comp &);
         virtual  Fonc_Num_Computed * op_bin_comp
                                      (const Arg_Fonc_Num_Comp &,
                                       Fonc_Num_Computed       * f1,
                                       Fonc_Num_Computed       * f2
                                      ) = 0;
         Op_Bin_Not_Comp
         (
                Fonc_Num,
                Fonc_Num, 
		bool  isInfixe,
                const char *,
                TyVal,
                TyDeriv,
		TyValDeriv
         );
         virtual int dimf_out() const;
	 virtual void compile (cElCompileFN &);
         virtual Fonc_Num::tKindOfExpr  KindOfExpr();
         virtual int CmpFormelIfSameKind(Fonc_Num_Not_Comp *);
	 void  PutFoncPar
	       (
			Fonc_Num f,
			cElCompileFN & anEnv,
			const char * mSimpl
	       );



      protected :
         Fonc_Num       _f0; 
         Fonc_Num       _f1; 
	 bool           mIsInfixe;
         const char *   _name;
         TyVal          _OpBinVal;
         TyDeriv        _OpBinDeriv;
		 TyValDeriv      mOpBinValDeriv;

         virtual void VarDerNN(ElGrowingSetInd &) const;
         virtual Fonc_Num deriv(int k) const ;
		 virtual void  show(std::ostream &) const ;
         virtual double_t  ValFonc(const  PtsKD &  pts) const;
		 double_t ValDeriv(const  PtsKD &  pts,int k) const;
};


class Op_Un_Not_Comp : public Fonc_Num_Not_Comp
{
      public :
         virtual  Fonc_Num_Computed * compute(const Arg_Fonc_Num_Comp &);
         virtual  Fonc_Num_Computed * op_un_comp
                                      (const Arg_Fonc_Num_Comp &,
                                       Fonc_Num_Computed       * f
                                      ) = 0;

          typedef double   (* TyVal)  (double);
          typedef Fonc_Num (* TyDeriv)(Fonc_Num,int k);
          typedef double_t (* TyValDeriv)(Fonc_Num,const  PtsKD &,int k);


         Op_Un_Not_Comp(Fonc_Num,const char *,TyVal,TyDeriv,TyValDeriv);

      protected :
         Fonc_Num           _f; 
         const char *       _name;
         TyVal              _OpUnVal;
         TyDeriv            _OpUnDeriv;
		 TyValDeriv         mOpUnValDeriv;

         virtual int        dimf_out() const;
         virtual void VarDerNN(ElGrowingSetInd &) const;
         virtual Fonc_Num deriv(int k) const ;
		 virtual void  show(std::ostream &) const ;
         virtual double_t  ValFonc(const  PtsKD &  pts) const;
		 double_t ValDeriv(const  PtsKD &  pts,int k) const;
	 virtual void compile (cElCompileFN &);
         virtual Fonc_Num::tKindOfExpr  KindOfExpr();
         virtual int CmpFormelIfSameKind(Fonc_Num_Not_Comp *);
};


        /**************************************************/
        /*                                                */
        /*         Utilitaries                            */
        /*                                                */
        /**************************************************/

      
      // convertion 

extern  Fonc_Num_Computed * convert_fonc_num
        (       const Arg_Fonc_Num_Comp & arg,
                Fonc_Num_Computed * f,
                Flux_Pts_Computed * flx,
                Pack_Of_Pts::type_pack type_wished
        );


/*
    If one of the tf is double_t, all will be converted to double_t.
*/


extern Pack_Of_Pts::type_pack  convert_fonc_num_to_com_type
       (
          const Arg_Fonc_Num_Comp & arg,
          Fonc_Num_Computed * * tf,
          Flux_Pts_Computed * flx,
          int nb
       );


extern  Fonc_Num_Computed * clip_fonc_num_def_val
        (       const Arg_Fonc_Num_Comp & arg,
                Fonc_Num_Computed * f,
                Flux_Pts_Computed * flux,
                const int * _p0,
                const int * _p1,
                double_t        def_val,
                double_t        rab_p0 = 0.0,
                double_t        rab_p1 = 0.0,
                bool        flush_flx  = false
        );


Fonc_Num r2d_adapt_filtr_lin(Fonc_Num f,const char *);


Fonc_Num nflag_open_sym_id(Fonc_Num);
class cAllocNameFromInt
{
      public :
          const  std::string &  NameKth(int aNB);

          cAllocNameFromInt(const std::string & aRac);

      private :
          std::vector<std::string> mNAMES;
          std::string              mRac;
};


#endif  /* _ELISE_FONC_NUM_H */
