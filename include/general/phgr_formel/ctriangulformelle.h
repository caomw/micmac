#ifndef _ELISE_GENERAL_PHGR_FORMEL_CTRIANGULFORMELLE_H
#define _ELISE_GENERAL_PHGR_FORMEL_CTRIANGULFORMELLE_H

#include "general/sys_dep.h"

class cTriangulFormelle : public ElDistortion22_Gen,
	                  public cElemEqFormelle,
                          public cObjFormel2Destroy
{
      public :
        virtual void SetAllPtCur(const ElDistortion22_Gen &) =0;
        virtual ~cTriangulFormelle() ;
        std::vector<double> ValsOfPt(const Pt2dr &  aP) const;  // Direct
	Pt2dr Direct(Pt2dr  aP) const;  // En dim 2 pour heriter de ElDistortion22_Gen,

	static void Test();
	virtual cTFI_Triangle & GetTriFromP(const Pt2dr & aP) const = 0;
	virtual void TestOneTri() = 0;
	// Renvoie un point  dans la tri, + ou - au centre, a priori
	// le barry mais sans garantie
	virtual Pt2dr APointInTri() const =0;
	virtual void Show() =0;
	virtual void Show(ElPackHomologue) =0;

	// Renvoie un sommet central, le plus proche de la  BBbox
	// virtual cTFI_AttrSom  & SomCentral() =0;
	// Renvoie un sommet aS2 tq (aS1 aS2) soit horizontal et assez grand
	// virtual cTFI_AttrSom  & SomVecHorz(cTFI_AttrSom & aS1) =0;
	// 
	// int 

          cSetEqFormelles & Set();
	  // Contraintes pour bloquer un mouvement de rotation
          cMultiContEQF      ContraintesRot() ;
	  // Contraintes pour bloquer tous les sommets
          cMultiContEQF      ContraintesAll() ;
	  virtual void SetTolMax(double_t) =0;
          const  std::vector<cTFI_Triangle *> & VTri() const;

	  void AssertD2() const;
      protected :
          cTriangulFormelle(int aDim,cSetEqFormelles & aSet);

	  cSetEqFormelles & mSet;
          std::vector<cTFI_Triangle *> mVTri;
	  const int     mDim;
      private :
	  virtual cTFI_AttrSom * SomCentral() = 0;
	  virtual cTFI_AttrSom * VecHorz() = 0;
	  void  Diff(ElMatrix<double_t> &,Pt2dr) const ; // Non implantee

	  double  mTrianFTol;
};

#endif
