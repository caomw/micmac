#ifndef _ELISE_GENERAL_PHGR_FORMEL_CINCLISTintERV_H
#define _ELISE_GENERAL_PHGR_FORMEL_CINCLISTintERV_H



class  cIncListInterv
{
    public :

       cIncListInterv();
       bool Equal(const cIncListInterv&) const;
       cIncListInterv(bool isTmp,const cIncIntervale::tId & anId,int anI0,int anI1);

       ~cIncListInterv();
       void AddInterv(const cIncIntervale &,bool CanOverlap=false);
       void ResetInterv(const cIncIntervale &);
       bool IsConnexe0N() const;

       int I0Min() const;
       int I1Max() const;
       int Surf()  const;
       const cIncIntervale & FindEquiv(const cIncIntervale &) const;

       const cMapIncInterv &Map() const;
       bool  MayOverlap() const;

       void Init();
    private :

       // cIncListInterv  (const cIncListInterv &) ; // Un imlemanted
       void operator = (const cIncListInterv &) ; // Un imlemanted

       int          mI0Min;
       int          mI1Max;
       int          mSurf;
       cMapIncInterv mMap;
       bool          mMayOverlap;  // Est-ce que l'overlap est possible
};

#endif
