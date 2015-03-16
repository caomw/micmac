#ifndef _ELISE_GENERAL_PHGR_FORMEL_CTFI_TRIANGLE_H
#define _ELISE_GENERAL_PHGR_FORMEL_CTFI_TRIANGLE_H



class cTFI_Triangle
{
      public :
         static cTFI_Triangle * NewOne(cTFI_AttrSom & ,cTFI_AttrSom & ,cTFI_AttrSom &);
         const cElTriangleComp & TriGeom() const;

         std::vector<double>  InterpolVals(const Pt2dr & aP) const;

          const std::vector<Fonc_Num> & Inc1() const;
          const std::vector<Fonc_Num> & Inc2() const;
          const std::vector<Fonc_Num> & Inc3() const;

	  const cIncIntervale &   IntervA1 () const;
	  const cIncIntervale &   IntervA2 () const;
	  const cIncIntervale &   IntervA3 () const;

	  const cIncIntervale &   IntervB1 () const;
	  const cIncIntervale &   IntervB2 () const;
	  const cIncIntervale &   IntervB3 () const;
	  int Dim() const;
         cSetEqFormelles &     Set();

     // Si dim=1 et les inconnue sont des Z, renvoie le plan passant par
     // les trois points
	 cElPlan3D CalcPlancCurValAsZ() const;
	 cTFI_AttrSom & S1();
	 cTFI_AttrSom & S2();
	 cTFI_AttrSom & S3();

          // Indexes de  x1 y1 x2 y2 x3 y3
          // const std::vector<int> &  VecOfIndexe() const;

      private :

         cTFI_Triangle(cTFI_AttrSom & ,cTFI_AttrSom & ,cTFI_AttrSom &);
         cTFI_Triangle(const cTFI_Triangle &) ; // Not Implemanted

         int              mDim;
	 cTFI_AttrSom &   mA1;
	 cIncIntervale    mIntervA1;
	 cIncIntervale    mIntervB1;

	 cTFI_AttrSom &   mA2;
	 cIncIntervale    mIntervA2;
	 cIncIntervale    mIntervB2;

	 cTFI_AttrSom &   mA3;
	 cIncIntervale    mIntervA3;
	 cIncIntervale    mIntervB3;


         cElTriangleComp  mTri;
         // std::vector<int>   mVIndexe;
};

#endif
