#ifndef _ELISE_GENERAL_BITM_TYPE>_H
#define _ELISE_GENERAL_BITM_TYPE>_H



template <class Type> Pt2d<Type> operator *
         (const ElMatrix<Type> & M,const Pt2d<Type> &);

#ifndef _ELISE_GENERAL_BITM_TYPE>_H
#define _ELISE_GENERAL_BITM_TYPE>_H



template <class Type> Pt3d<Type> operator *
         (const ElMatrix<Type> & M,const Pt3d<Type> &);

template <class Type> Pt2d<Type> mul32(const ElMatrix<Type>&,const Pt3d<Type> & p);

template <class Type> void SetCol (ElMatrix<Type> & M,int col,Pt3d<Type>);
template <class Type> void SetLig (ElMatrix<Type> & M,int Lig,Pt3d<Type>);

template <class Type> void SetCol (ElMatrix<Type> & M,int col,Pt2d<Type>);
template <class Type> void SetLig (ElMatrix<Type> & M,int Lig,Pt2d<Type>);

template <class Type>  ElMatrix<Type> MatFromCol(Pt3d<Type>,Pt3d<Type>,Pt3d<Type>);
template <class Type>  ElMatrix<Type> MatFromCol(Pt2d<Type>,Pt2d<Type>);
ElMatrix<double_t> MatFromImageBase (
                                     Pt3d<double_t> C0,Pt3d<double_t> C1,Pt3d<double_t> C2,
                                     Pt3d<double_t> ImC0,Pt3d<double_t>,Pt3d<double_t>
                                );

double_t EcartInv(const ElMatrix<double_t>& m1,const ElMatrix<double_t>& m2);



template <class Type> ElMatrix<Fonc_Num>  ToMatForm(const  ElMatrix<Type> &);



void AngleFromRot(const ElMatrix<double_t> & m,double_t & a,double_t & b,double_t & c);


/*
   Comme le besoin de templatiser la classe ElRotation3D
   est apparu a posteriori, pour rester compatible avec le code
   appelant, il a ete decide :

       [1] d'appeler TplElRotation3D la classe template
       [2] d'appeler ElRotation3D son instantiation au type double_t
*/


#ifndef _ELISE_GENERAL_BITM_TPLELROTATION3D_H
#define _ELISE_GENERAL_BITM_TPLELROTATION3D_H



template <class Type> class TplElRotation3D
{
      public :

         TplElRotation3D<Type>  inv() const;
         TplElRotation3D<Type>  operator *(const TplElRotation3D<Type> &) const;

         static const TplElRotation3D<Type> Id;
         TplElRotation3D(Pt3d<Type> tr,const ElMatrix<Type> &,bool aTrueRot);
         TplElRotation3D(Pt3d<Type> tr,Type teta01,Type teta02,Type teta12);

         Pt3d<Type> ImAff(Pt3d<Type>) const; //return _tr + _Mat * p;

         Pt3d<Type> ImRecAff(Pt3d<Type>) const;
         Pt3d<Type> ImVect(Pt3d<Type>) const;
         Pt3d<Type> IRecVect(Pt3d<Type>) const;

         ElMatrix<Type> DiffParamEn1pt(Pt3dr) const;

         const ElMatrix<Type> & Mat() const {return _Mat;}
         const Pt3d<Type> &  tr() const {return _tr;}
         Pt3d<Type> &  tr() {return _tr;}
         const Type &   teta01() const {AssertTrueRot(); return _teta01;}
         const Type &   teta02() const {AssertTrueRot(); return _teta02;}
         const Type &   teta12() const {AssertTrueRot(); return _teta12;}

         TplElRotation3D<Type> & operator = (const TplElRotation3D<Type> &);

         bool IsTrueRot() const;

      private  :
         void AssertTrueRot() const;

         Pt3d<Type>        _tr;
         ElMatrix<Type>    _Mat;
         ElMatrix<Type>    _InvM;
         Type              _teta01;
         Type              _teta02;
         Type              _teta12;
         bool              mTrueRot;
};

#endif
