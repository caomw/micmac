#ifndef _ELISE_GENERAL_BITM_IM2D_H
#define _ELISE_GENERAL_BITM_IM2D_H

#include "general/sys_dep.h"

template <class Type,class TyBase> class Im2D : public Im2DGen
{
   public :

      ElMatrix<double_t>  ToMatrix() const;
      typedef Type   tElem;
      typedef TyBase tBase;
      Fonc_Num FoncEtalDyn();

      double Get(const Pt2dr & aP,const cInterpolateurIm2D<Type> &,double aDef);
      double Val(const int & x,const int & y) const;

      virtual ~Im2D();
  /*
      Pt2di sz() const {return Pt2di(tx(),ty());}
      Box2di ImBox2d() const  {return Box2di(Pt2di(0,0),sz());}
      Box2di ImBox2d(int Brd) const {return Box2di(Pt2di(Brd,Brd),Pt2di(tx()-Brd,ty()-Brd));}
  */

      int     tx() const;
      int     ty() const;
      virtual void TronqueAndSet(const Pt2di &,double aVal);

      virtual cIm2DInter * BilinIm() ;
      virtual cIm2DInter * BiCubIm(double aCoef,double aScale=1.0) ;

      static void   ReadAndPushTif
                    (
                        std::vector<Im2D<Type,TyBase> > & aV,
                        Tiff_Im               aFile
                    );

      static Im2D<Type,TyBase> FromFileStd(const std::string &);  // From File
      static Im2D<Type,TyBase> FromFileBasic(const std::string &);  // From File
      static Im2D<Type,TyBase> FromFileOrFonc
                               (const std::string &,Pt2di aSz,Fonc_Num);

      Im2D(); //  !! Dangereux, mais necessaire vs xml generation
      Im2D(int tx, int ty);
      Im2D(int tx, int ty,TyBase v_init);
      Im2D(int tx, int ty,const char * v_inits);
      Im2D(Type*,Type**,int tx, int ty,int tx_phys =-1);

      Im2D(Im2D_NoDataLin,int tx, int ty);


      Fonc_Num ImGridReech(Fonc_Num aFX,Fonc_Num aFY,int szGr,double_t def);
      Fonc_Num ImGridReech(Fonc_Num aFX,Fonc_Num aFY,int szGr,Pt2di aP0,Pt2di aP1,double_t def);

      void PutData(FILE * aFP,const Pt2di & anI,bool aModeBin) const;
      void SetI(const Pt2di & ,int aValI) ;
      void SetR(const Pt2di & ,double aValR) ;
      int     GetI(const Pt2di &) const ;
      double  GetR(const Pt2di &) const ;
      Im2DGen  *ImOfSameType(const Pt2di & aSz) const;
      Im2DGen * ImRotate(int aRot ) const;
      Type **   data();
      Type **   data() const;
      Type *    data_lin();
      const Type *    data_lin() const;
      int  vmax() const;
      int  vmin() const;
      double  MoyG2() const ;
      virtual  GenIm::type_el TypeEl() const ;
      void raz();
      void dup (Im2D<Type,TyBase> to_dup);
      Im2D<Type,TyBase> dup ();
      double_t  som_rect();
      double_t  som_rect(Pt2dr p0,Pt2dr p1,double_t def=0.0);
      double_t  moy_rect(Pt2dr p0,Pt2dr p1,double_t def=0.0);
      Im2D<Type,TyBase>  ToSom1();

          Im2D<Type,TyBase> Reech(double_t aZoom);



      void set_brd(Pt2di sz,Type val);
      void auto_translate(Pt2di);
      void raz(Pt2di p0,Pt2di p1);

          void SetLine(int x0,int y,int nb,int val);

      Seg2d   OptimizeSegTournantSomIm
              (
                    double_t &                 score,
                    Seg2d                  seg,
                    int                    NbPts,
                    double_t                   step_init,
                    double_t                   step_limite,
                    bool                   optim_absc  = true,
                    bool                   optim_teta  = true,
                    bool  *                FreelyOpt = 0
              );


          // Eventuellement renvoie l'image elle meme, conserve les donnees
          // ne cherche pas a presever le champs data lin, ne modifie pas
          // le contenue de l'image et OK pour ceux qui pointaient sur elle
      Im2D<Type,TyBase> AugmentSizeTo(Pt2di aSz,Type aValCompl = 0);

          //  Toujours en place, modifie eventuellement le contenu de l'image,
          // peur avoir des effets desagreables pour ceux qui la referencaient (si
          // ils ne sont pas au courant du changement)
          void Resize(Pt2di aSz);

          Im2D<Type,TyBase> gray_im_red(int zoom);

      void MulVect(Im1D<Type,TyBase> aRes,Im1D<Type,TyBase> aMat);

   private :
      DataIm2D<Type,TyBase> * di2d(){return (DataIm2D<Type,TyBase> *) (_ptr);}
};

#endif
