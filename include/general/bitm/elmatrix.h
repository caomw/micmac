#ifndef _ELISE_GENERAL_BITM_ELMATRIX_H
#define _ELISE_GENERAL_BITM_ELMATRIX_H

#include <Pt3d>

template <class Type>  class ElMatrix
{
      public :

          void ResizeInside(int TX,int TY);

          void GetCol(int aCol,Pt3d<Type> &) const;
          void GetLig(int aCol,Pt3d<Type> &) const;

          void GetCol(int aCol,Pt2d<Type> &) const;
          void GetLig(int aCol,Pt2d<Type> &) const;
        // Creation etc..
          ElMatrix(int,bool init_id = true);
          ElMatrix(int,int,Type v =0);
          ElMatrix(const ElMatrix<Type> & m2);
          ElMatrix<Type> & operator = (const ElMatrix<Type> &);
          ~ElMatrix();

          ElMatrix<Type> sub_mat(int aCol, int aLig, int aNbCol, int aNbLig) const;
          ElMatrix<Type> ExtensionId(int ExtAvant,int ExtApres) const;

          void set_to_size(int TX,int TY);
          void set_to_size(const ElMatrix<Type> & m2);


          // fait de la matrice une matrice de permutation de type
          // shift
          void set_shift_mat_permut(int ShiftPremierCol);
          static  ElMatrix<Type>  transposition(int aN,int aK1,int aK2);



        // Utilitaires

          Type ** data();  // Plutot pour comm avec vielle lib (genre NR)
          bool same_size (const ElMatrix<Type> &) const;
          Type & operator() (int x,int y)
          {
              ELISE_ASSERT
              (
                    (x>=0)&&(x<_tx)&&(y>=0)&&(y<_ty),
                    "Invalid Matrix Access"
              );
               return _data[y][x];
          }

          const Type & operator() (int x,int y) const
          {
              ELISE_ASSERT
              (
                    (x>=0)&&(x<_tx)&&(y>=0)&&(y<_ty),
                    "Invalid Matrix Access"
              );
               return _data[y][x];
          }



          int tx() const {return _tx;}
          int ty() const {return _ty;}
          Pt2di Sz() const {return Pt2di(_tx,_ty);}

               // Produits "scalaires"; par ex  LC = LigneColone,
          Type ProdCC(const ElMatrix<Type> &,int x1,int x2) const;
          Type ProdLL(const ElMatrix<Type> &,int y1,int y2) const;
          Type ProdLC(const ElMatrix<Type> &,int y1,int x2) const;

          void SetLine(int NL,const Type *);
          void GetLine(int NL,Type *) const;


        // Operation matricielles (algebriques)

          // mul :equiv a this = m1 * m2, + efficace
          void mul(const ElMatrix<Type> & m1,const ElMatrix<Type> & m2);
          ElMatrix<Type> operator * (const ElMatrix<Type> &) const;

          void mul(const ElMatrix<Type> & m1,const Type & v);
          ElMatrix<Type> operator * (const Type &) const;
          void  operator *= (const Type &) ;
      void operator += (const ElMatrix<Type> & );
          Type Det() const;
          Type Trace() const;


          // equiv a this = m1 + m2, + efficace
          void add(const ElMatrix<Type> & m1,const ElMatrix<Type> & m2);
          ElMatrix<Type> operator + (const ElMatrix<Type> &) const;

          void sub(const ElMatrix<Type> & m1,const ElMatrix<Type> & m2);
          ElMatrix<Type> operator - (const ElMatrix<Type> &) const;

          void transpose(const ElMatrix<Type>  &);
          void self_transpose();
    // Recopie dans la demi matric inferieure, le contenu de la demi matrice superieure
          void  SymetriseParleBas();
          ElMatrix<Type> transpose() const;

          // Instantiated only for Type=double_t



        // Operation matricielles (Euclidiennes)

          static ElMatrix<Type> Rotation3D(Type teta,int aNumAxeInv);
          static ElMatrix<Type> Rotation(int sz,Type teta,int k1,int k2);
          static ElMatrix<Type> Rotation(Type teta12,Type teta13,Type teta23);
          static ElMatrix<Type> Rotation(Pt3d<Type> aImI,Pt3d<Type> aImJ,Pt3d<Type> aImK);

          typedef Pt3d<Type> tTab3P[3];

          static void  PermRot(const std::string &,tTab3P &);  // par ex  ji-k  -i-k-j  ...
          static ElMatrix<Type> PermRot(const std::string &);  // par ex  ji-k  -i-k-j  ...
          // derivee   de rotation
          // derivee d'une rotation simple / a teta
          static ElMatrix<Type> DerRotation(int sz,Type teta,int k1,int k2);
          static ElMatrix<Type> DDteta01(Type teta12,Type teta13,Type teta23);
          static ElMatrix<Type> DDteta02(Type teta12,Type teta13,Type teta23);
          static ElMatrix<Type> DDteta12(Type teta12,Type teta13,Type teta23);

          // friend  ElMatrix<Type>

          ElMatrix<Type> ColSchmidtOrthog(int iter =1) const;
          void SetColSchmidtOrthog(int iter =1);
          Type  L2(const ElMatrix<Type> & m2) const;
          Type  scal(const ElMatrix<Type> & m2) const;
          Type  L2() const;
          Type NormC(int x) const;

      private :

          void verif_addr_diff(const ElMatrix<Type> & m1);
          void verif_addr_diff(const ElMatrix<Type> & m1,
                               const ElMatrix<Type> & m2);


          void init(int TX,int TY);
          void dup_data(const ElMatrix<Type> & m2);
          void un_init();
          int     _tx;
          int     _ty;
          Type ** _data;

    // Rajoute pour que la meme matrice puisse etre resizee inside
          int     mTMx;
          int     mTMy;

};

#endif
