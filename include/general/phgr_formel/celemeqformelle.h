#ifndef _ELISE_GENERAL_PHGR_FORMEL_CELEMEQFORMELLE_H
#define _ELISE_GENERAL_PHGR_FORMEL_CELEMEQFORMELLE_H



class  cElemEqFormelle :  public cNameSpaceEqF
{
        public :
            // virtual tContFcteur & Foncteurs() = 0;
            virtual ~cElemEqFormelle ();
            cElemEqFormelle (cSetEqFormelles &,bool isTmp);

            cSetEqFormelles * Set();
            bool IsTmp() const;
            const  cIncIntervale & IncInterv() const;
            cIncIntervale & IncInterv() ;
            tContFcteur & AllFonct();
	    void  AddFoncRappInit(cMultiContEQF &,int i0,int i1,double aTol);
            double_t AddRappViscosite
                 (
                      const std::string  & aContexte,
                      bool OnCur,
                      int aK,
                      double   aTol,
                      bool     AdEq
                 );


            // void AddFoncRappOnCur(cMultiContEQF &,int i0,int i1,double * aTol );

            void AssertClosed();
            void AssertUnClosed();
            void AssertSameSet(const cElemEqFormelle &);

	    virtual void SetValAndInit(double_t,int IndGlob);
	    // Les contraintes se referent au valeur init,
	    // d'ou l'interet eventuel de les remettre sur 
	    // sur les valeur courantes si c'est elles que l'on
	    // veut figer
	    virtual void SetValInitOnValCur();
	    int NbInc();


        protected :

	    void AddFoncteurEEF(cElCompiledFonc *);
            void CloseEEF(bool asIntervBlock = true);
            // Au cas ou des inconnues ont ete modifiee,
            // remet a jour mSet.Alloc()
            void ReinitOnCur();
            tContFcteur  FoncRapp(int i0,int i1,const double * vals);
            tContFcteur  FoncRappInit(int i0,int i1);

            cSetEqFormelles & mSet;
            // Foncteur de Rappel sur Valeur Init
            int                    mNumInc0;
            cIncIntervale          mIncInterv;
            int                    mNumIncN;

            tContFcteur                mFoncRap;
            tContFcteur                mAllFonct;
            std::vector<double *>      mAdrFR;
            std::vector<double  >      mValsInit;
            bool                       mClosed;
       private :
	    cElemEqFormelle (const cElemEqFormelle &) ; // Prohib
	    void operator =  (const cElemEqFormelle &) ; // Prohib
};

#endif
