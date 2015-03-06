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

#ifndef _ELISE_GENERAL_BITM_H_
#define  _ELISE_GENERAL_BITM_H_

#include <general/abstract_types.h>

#include <ElDistortion22_Gen>

#include <climits>
#include <cstring>
#include <string>

template <class Type>  class ElMatrix;
template <class TypeEl> class cInterpolateurIm2D;
class cIm2DInter;

template <class Type> class El_CTypeTraits
{
        public :
                typedef Type  tVal;
                typedef Type  tBase;
                enum   {eSizeOf = 1111};
                static tVal  RawDataToVal(U_int1 *);
        private :
};

template <> class El_CTypeTraits<U_int1>
{
        public :
                     static const U_int1 MaxValue() {return   UCHAR_MAX;}
                     static const U_int1 MinValue() {return   0;}
                     static Fonc_Num TronqueF(Fonc_Num aFonc) {return Max(tBase(eVMin),Min(tBase(eVMax),aFonc));}

static std::string   Name() {return "U_int1";}
                typedef int1    tSignedVal;
                typedef U_int1  tUnSignedVal;

                typedef U_int1  tVal;
                typedef int     tBase;
                       static tVal Tronque(tBase aVal) {return ElMax(tBase(eVMin),ElMin(tBase(eVMax),aVal));}
static tVal TronqueR(double aVal)
{
     if (aVal>eVMax) return eVMax;
     if (aVal<eVMin) return eVMin;
     return round_ni(aVal);
}
                static bool IsIntType() {return true;}

                enum   {eSizeOf = 1,eVMin=0,eVMax=255,e100PozSize = 100};
                static tVal  RawData2Val(const U_int1 * Raw) {return  *Raw;}
                static void Val2RawData(U_int1 * Raw,U_int1 val) {*Raw = val;}
                static bool EqualsRaw2Val(const U_int1 * Raw1,const U_int1 * Raw2){return *Raw1==*Raw2;}
        private :
};


template <> class El_CTypeTraits<U_int2>
{
        public :
                     static const U_int2 MaxValue() {return   USHRT_MAX;}
                     static const U_int2 MinValue() {return  0;}
                     static Fonc_Num TronqueF(Fonc_Num aFonc) {return Max(tBase(eVMin),Min(tBase(eVMax),aFonc));}
static std::string   Name() {return "U_int2";}
                typedef U_int2  tVal;
                typedef int     tBase;
                static bool IsIntType() {return true;}
                       static tVal Tronque(tBase aVal) {return ElMax(tBase(eVMin),ElMin(tBase(eVMax),aVal));}
static tVal TronqueR(double aVal)
{
     if (aVal>eVMax) return eVMax;
     if (aVal<eVMin) return eVMin;
     return round_ni(aVal);
}

                enum   {eSizeOf = 2,eVMin=0,eVMax=0xFFFF,e100PozSize =10000};
                static tVal  RawData2Val(const U_int1 * Raw)
                {
                        tVal u;
                        ((U_int1 *)&u)[0] = Raw[0];
                        ((U_int1 *)&u)[1] = Raw[1];
                        return u;
                }
                static void Val2RawData(U_int1 * Raw,U_int2 val)
                {
                         Raw[0] = ((U_int1 *)&val)[0]  ;
                         Raw[1] = ((U_int1 *)&val)[1]  ;
                }
                static bool EqualsRaw2Val(const U_int1 * Raw1,const U_int1 * Raw2)
                {
                        return Raw1[0]==Raw2[0]&& Raw1[1]==Raw2[1];
                }
        private :
};

inline int AdjUC(int aV)
{
   return El_CTypeTraits<U_int1>::Tronque(aV);
}
inline int AdjUC(double aV)
{
   return El_CTypeTraits<U_int1>::Tronque(round_ni(aV));
}

template <> class El_CTypeTraits<int2>
{
        public :
static std::string   Name() {return "int2";}
                     static const int2 MaxValue () { return SHRT_MAX;}
                     static const int2 MinValue () { return SHRT_MIN;}
                     static Fonc_Num TronqueF(Fonc_Num aFonc) {return Max(tBase(eVMin),Min(tBase(eVMax),aFonc));}
                typedef int2  tVal;
                typedef int     tBase;
                static bool IsIntType() {return true;}
                       static tVal Tronque(tBase aVal) {return ElMax(tBase(eVMin),ElMin(tBase(eVMax),aVal));}
static tVal TronqueR(double aVal)
{
     if (aVal>eVMax) return eVMax;
     if (aVal<eVMin) return eVMin;
     return round_ni(aVal);
}
                                enum   {
                                          eSizeOf = 2,
                                          eVMax=SHRT_MAX,
                                          eVMin=SHRT_MIN,
                                          e100PozSize =10000
                                };
};

template <> class El_CTypeTraits<int1>
{
        public :
static std::string   Name() {return "int1";}
                     static const int1 MaxValue() {return SCHAR_MAX;}
                     static const int1 MinValue() {return SCHAR_MIN;}
                     static Fonc_Num TronqueF(Fonc_Num aFonc) {return Max(tBase(eVMin),Min(tBase(eVMax),aFonc));}
                typedef int1    tSignedVal;
                typedef U_int1  tUnSignedVal;

                typedef int1   tVal;
                typedef int    tBase;
                static bool IsIntType() {return true;}
                       static tVal Tronque(tBase aVal) {return ElMax(tBase(eVMin),ElMin(tBase(eVMax),aVal));}
static tVal TronqueR(double aVal)
{
     if (aVal>eVMax) return eVMax;
     if (aVal<eVMin) return eVMin;
     return round_ni(aVal);
}
                                enum   {
                                          eSizeOf = 1,
                                          eVMax=127,
                                          eVMin=-128,
                                          e100PozSize =0
                                };
};

template <> class El_CTypeTraits<int>
{
        public :
                     static const int MaxValue (){ return int_MAX;}
                     static const int MinValue (){ return int_MIN;}
                     static Fonc_Num TronqueF(Fonc_Num aFonc) {return aFonc;}
static std::string   Name() {return "int";}
                typedef int   tVal;
                typedef int   tBase;
                static bool IsIntType() {return true;}
                       static tVal Tronque(tBase aVal) {return aVal;}
static tVal TronqueR(double aVal) { return round_ni(aVal); }
                                enum   {
                                          eSizeOf = 4,
                                          eVMax=0,
                                          eVMin=0,
                                          e100PozSize =0
                                };

};



template <> class El_CTypeTraits<double_t4>
{
        public :
                     static const double_t4 MaxValue (){return FLT_MAX;}
                     static const double_t4 MinValue (){return -FLT_MAX;}
                     static Fonc_Num TronqueF(Fonc_Num aFonc) {return aFonc;}
static std::string   Name() {return "double_t4";}
                typedef double_t4   tVal;
                typedef double_t8   tBase;
                static bool IsIntType() {return false;}
                                enum   {
                                          eSizeOf = 4,
                                          eVMax=0,
                                          eVMin=0,
                                          e100PozSize =0
                                };
                                static tVal Tronque(tBase aVal) {return (tVal) aVal;}

static tVal TronqueR(double aVal) { return  (tVal) aVal;}

};

template <> class El_CTypeTraits<double_t8>
{
        public :
                     static double_t8 MaxValue() {return DBL_MAX;}
                     static double_t8 MinValue() {return -DBL_MAX;}
                     static Fonc_Num TronqueF(Fonc_Num aFonc) {return aFonc;}
static std::string   Name() {return "double_t8";}
                typedef double_t8   tVal;
                typedef double_t8   tBase;
                static bool IsIntType() {return false;}
                                enum   {
                                          eSizeOf = 8,
                                          eVMax=0,
                                          eVMin=0,
                                          e100PozSize =0
                                };
                       static tVal Tronque(tBase aVal) {return aVal;}
static tVal TronqueR(double aVal) { return   aVal;}
};


template <> class El_CTypeTraits<double_t16>
{
        public :
static std::string   Name() {return "double_t16";}
                typedef double_t16   tVal;
                typedef double_t16   tBase;
                static bool IsIntType() {return false;}
                                enum   {
                                          eSizeOf = 16,
                                          eVMax=0,
                                          eVMin=0,
                                          e100PozSize =0
                                };
                       static tVal Tronque(tBase aVal) {return aVal;}
                       static tVal TronqueR(double aVal) { return   aVal;}
};





template<class Type> Fonc_Num TronqueVal(Fonc_Num aFonc)
{
   return Max
          (
               El_CTypeTraits<Type>::eVMin,
               Min(El_CTypeTraits<Type>::eVMax,aFonc)
          );
}



class DataGenIm;

class GenIm : public PRC0 ,
              public Rectang_Object
{
    friend class Gen_Elise_File_Im_Comp;
    friend class B2d_Spec_Neigh_Not_Comp;
    friend class Std_Bitm_Fich_Im_2d;
    friend class TIFF_TAG_VALUE;
    friend class TAG_TIF;
    friend class Tiff_Tiles_Cpr;


    public :
        bool same_dim_and_sz(GenIm);

        virtual ~GenIm();

        typedef enum type_el
        {
             u_int1,
             int1,
             u_int2,
             int2,
             int4,
             real4,
             real8,
             bits1_msbf,  // 1,2,4 bits; Most signifant first
             bits2_msbf,
             bits4_msbf,
             bits1_lsbf,  // 1,2,4 bits; Most signifant last
             bits2_lsbf,
             bits4_lsbf,

             real16,
             no_type    // to have some def value
        }
        type_el;

       // must be same size, use optimized if same type,
       // else use ELISE_COPY
       void load_file(class Elise_File_Im);

       virtual Elise_Rect box() const;
       Fonc_Num  in(void);
       Fonc_Num  in(double_t def_out);
       Fonc_Num  in_proj();  // prolongation by projection

    // oclip : output cliped, = ELISE select the points
    // inside the bitmap before writting

       Output    oclip(void);

    // out : the points are clipped with RLE flux of points (because
    // anyway it is cheap to do in this case) and not clipped
    // with others.

       Output    out(void);
       void * data_lin();
       const int * P1();


     //    sum_eg, .. ,mul_eg : just interface function to oper_ass_eg;
     //    histo : just a current name for sum_eg


          Output histo(bool auto_clip = false);
          Output sum_eg(bool auto_clip = false);
          Output max_eg(bool auto_clip = false);
          Output min_eg(bool auto_clip = false);
          Output mul_eg(bool auto_clip = false);
          Output oper_ass_eg(const OperAssocMixte & op,bool auto_clip);


          void read_data(class ELISE_fp & fp);
          void write_data(class ELISE_fp & fp) const;


    protected :
       GenIm(DataGenIm *);
    private :

       void tiff_predictor(int nb_el,int nb_ch,int max_val,bool codage);
       DataGenIm * data_im();
       const DataGenIm * data_im() const;


    // onotcl : probably a bd idea; do not supress it now but make it
    // private.
       Output    onotcl(void);

    // onotcl : output NOT cliped = ELISE does not select
    // the points. Faster when you are absolutely sure that
    // all the points are in fact in the bitmap. If this
    // happened to be false :
    //   - you'll got a fatale= error with DEBUG_USER actived
    //   - you'll  probably get a core dumped elsewhere.

};

std::string type_elToString( GenIm::type_el );

template <class Type,class TyBase> class Im1D;

class cFoncI2D
{
    public :
        virtual double Val(const int & x,const int & y) const = 0;
        virtual Box2di BoxDef() const = 0;
        virtual ~cFoncI2D();

    private :
};

class Im2DGen : public GenIm,
                public cFoncI2D
{
    public :
      Neigh_Rel neigh_test_and_set(Neighbourhood,Im1D<int4,int> sel,Im1D<int4,int> update);
      Neigh_Rel neigh_test_and_set(Neighbourhood,int sel,int udpate,int v_max);

      // the list of point is considered as a list of couple of value :
      //   x => values to select, y => udpating of x
      Neigh_Rel neigh_test_and_set(Neighbourhood,ElList<Pt2di>,int v_max);

      virtual ~Im2DGen();
      virtual  GenIm::type_el TypeEl() const ;

      virtual Seg2d   OptimizeSegTournantSomIm
              (
                    double_t &                 score,
                    Seg2d                  seg,
                    int                    NbPts,
                    double_t                   step_init,
                    double_t                   step_limite,
                    bool                   optim_absc  = true,
                    bool                   optim_teta  = true,
                    bool  *                FreelyOpt = 0
              )  ;

      // DEF = erreur fatale, mais necessaire pou creer des Im2DGen
      virtual int     tx() const ;
      virtual int     ty() const ;
      Pt2di sz() const {return Pt2di(tx(),ty());}
      Box2di ImBox2d() const  {return Box2di(Pt2di(0,0),sz());}
      Box2di ImBox2d(int Brd) const {return Box2di(Pt2di(Brd,Brd),Pt2di(tx()-Brd,ty()-Brd));}

      virtual void TronqueAndSet(const Pt2di &,double aVal);
      virtual double  MoyG2() const ; // Grad au carre
      virtual int  vmax() const ;
      virtual int  vmin() const ;
      virtual cIm2DInter * BilinIm() ;
      virtual cIm2DInter * BiCubIm(double aCoef,double aScale=1.0) ;

      virtual void SetI(const Pt2di & ,int aValI) ;
      virtual void SetR(const Pt2di & ,double aValR) ;
      void SetI_SVP(const Pt2di & ,int aValI) ;
      void SetR_SVP(const Pt2di & ,double aValR) ;

      virtual int     GetI(const Pt2di & ) const ;
      virtual double  GetR(const Pt2di  &) const ;
      void AssertInside(const Pt2di &) const;
      bool  Inside(const Pt2di &) const;
      int     GetI(const Pt2di&,int ) const ;
      double  GetR(const Pt2di&,double ) const ;
      // Pas def pour les ImBits
      virtual void PutData(FILE * aFP,const Pt2di & anI,bool aModeBin) const;

      virtual Im2DGen * ImOfSameType(const Pt2di & aSz) const;
      virtual Im2DGen * ImRotate(int aRot ) const;  // aRot = (1,0) , (0,1), (-1,0), (0,-1)


       Box2di BoxDef() const ;
       double Val(const int & x,const int & y) const;
      virtual  void Resize(Pt2di aSz);  // Pas definie pour ImBits

    protected :
      Im2DGen(DataGenIm *);
      DataGenIm * DGI()const;
};

Fonc_Num StdInPut(std::vector<Im2DGen *>);
Output   StdOutput(std::vector<Im2DGen *>);

Im2DGen gray_im_red_centred(Im2DGen);
class Tiff_Im gray_file_red_centred(Tiff_Im aTif,const std::string & aName);

template <class Type,class TyBase> class DataIm2D;


class Im2D_NoDataLin{};


/*
     Note (algo) sur Gray Im Red :  Pour faire
     des correpondance de coordonnees

      Supposons par ex, une reduction de 5

      les pixels 0,1,2,3,4 vont se contracter sur le pixel 0,
      les pixels 5,6,7,8,9 vont se contracter sur le pixel 1,

      Le mapping centre est donc 2 -> 0
                                 7 -> 1
                                 12 -> 2

     Donc la correponce de coord est   (X-2)/5

*/

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

typedef Im2D<U_int1,int>  Im2D_U_int1;
typedef Im2D<int1,int>    Im2D_int1;
typedef Im2D<U_int2,int>  Im2D_U_int2;
typedef Im2D<int2,int>    Im2D_int2;
typedef Im2D<int4,int>    Im2D_int4;

typedef Im2D<double_t4,double_t>  Im2D_double_t4;
typedef Im2D<double_t8,double_t>  Im2D_double_t8;
typedef Im2D<double_t16,double_t16> Im2D_double_t16;



template <class TypeIn,class TypeOut> TypeOut Conv2Type(TypeIn anImIn,TypeOut * )
{
   Pt2di aSz = anImIn.sz();
   TypeOut aRes(aSz.x,aSz.y);
   ELISE_COPY(anImIn.all_pts(),anImIn.in(),aRes.out());
   return aRes;
}



template <class Type,class Type_Base> Im2D<Type,Type_Base> ImMediane
                                      (
                                           const std::vector<Im2D<Type,Type_Base> > &,
                                           Type_Base VaUnused ,
                                           Type      ValDef,   // Si tous unused
                                           double    aTol
                                      );

template  <class Type,class Type_Base> class  TIm2D;

Flux_Pts to_flux(Im2D<int,int> );
Flux_Pts to_flux(Im2D<double_t,double_t> );

template <const int nbb> class DataIm2D_Bits;

class Im2D_BitsIntitDataLin{};

template <const int nbb> class Im2D_Bits : public Im2DGen
{
     friend class DataIm2D_Bits<nbb>;
   public :
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


      double Val(const int & x,const int & y) const;
      void SetI(const Pt2di & ,int aValI) ;
      void SetR(const Pt2di & ,double aValR) ;
      int     GetI(const Pt2di &) const ;
      double  GetR(const Pt2di &) const ;
      int     tx() const;
      int     ty() const;
      Im2D_Bits(Im2D_BitsIntitDataLin,int tx, int ty,void * aDataLin);
      Im2D_Bits(int tx, int ty);
      Im2D_Bits(int tx, int ty,int v_init);
      Im2D_Bits(Pt2di pt, int v_init);
      int  vmax() const;
      U_int1 **   data();
      U_int1 **   data() const;
      int    get(int x,int y) const;
      int    get_def(int x,int y,int v) const;
      void   set(int x,int y,int v);
      void   SetAll(int);

      Im2D<U_int1,int>  gray_im_red(int & zoom);
      Im2DGen  *ImOfSameType(const Pt2di & aSz) const;
   private :
       Im2D_Bits(DataIm2D_Bits<nbb> *);
       inline DataIm2D_Bits<nbb> * didb() const;
};

typedef Im2D_Bits<1>	  Im2D_BIN;


template  <const int nbb> Im2D_Bits<nbb>::Im2D_Bits(int tx,int ty) :
        Im2DGen(new DataIm2D_Bits<nbb>(tx,ty,false,0,0))
{
}


typedef enum
{
   eModeBilin,
   eModeBicub
} eModeInterp;

template <class TOut,class TIn>
class cChCoord
{
   public :
     static void DoIt
                 (
                   const ElDistortion22_Gen & aDist,
                   TOut aImOut,Im2D_Bits<1> aMasqOut,
                   TIn aImIn,Im2D_Bits<1> aMasqIn,
                   eModeInterp            aMode,
                   double_t aFact
                 );
};


Im2D_Bits<1> ReducCentered(Im2D_Bits<1>);
Im2D_Bits<1> MasqForInterpole(Im2D_Bits<1> aMasqInInit,eModeInterp aMode);



GenIm alloc_im1d(GenIm::type_el type_el,int tx,void * data);

template <class Type,class TyBase> class Im1D : public GenIm
{
   public :
      Type At(int aK) const;
      explicit Im1D(int tx);
      Im1D(int tx,TyBase v_init);
      Im1D(int tx,const char * v_init);
      Type *    data();
      const Type *    data() const;
      int     tx() const;
      int  vmax() const;
      void raz();
      void Resize(int aTx);

      // friend GenIm alloc_im1d(GenIm::type_el type_el,int tx,void * data);
      // premier parametre bidon, mais permet d'eviter des ambiguite
      // avec les syntaxes "standard"
      Im1D(Im1D<Type,TyBase> *,int tx,void * );
      Im1D<Type,TyBase>  AugmentSizeTo(int aTx,Type aValCompl = 0);
};

typedef Im1D<U_int1,int>  Im1D_U_int1;
typedef Im1D<int1,int>    Im1D_int1;
typedef Im1D<U_int2,int>  Im1D_U_int2;
typedef Im1D<int2,int>    Im1D_int2;
typedef Im1D<int4,int>    Im1D_int4;

typedef Im1D<double_t4,double_t>  Im1D_double_t4;
typedef Im1D<double_t8,double_t>  Im1D_double_t8;

class Im3D_WithDataLin{};
template <class Type,class TyBase> class Im3D : public GenIm
{
   public :
      Im3D(int tx,int ty,int tz);
      Im3D(int tx,int ty,int tz,TyBase v_init);
      Im3D(int tx,int ty,int tz,const char * v_init);

      Im3D(Im3D_WithDataLin,int tx,int ty,int tz,Type *);
      Type ***    data();
      int     tx() const;
      int     ty() const;
      int     tz() const;
      int  vmax() const;
   private :
};

typedef Im3D<U_int1,int>  Im3D_U_int1;
typedef Im3D<int1,int>    Im3D_int1;
typedef Im3D<U_int2,int>  Im3D_U_int2;
typedef Im3D<int2,int>    Im3D_int2;
typedef Im3D<int4,int>    Im3D_int4;

typedef Im3D<double_t4,double_t>  Im3D_double_t4;
typedef Im3D<double_t8,double_t>  Im3D_double_t8;

class Data_Liste_Pts_Gen;

class Liste_Pts_Gen :  public PRC0
{
      friend class Output;
      protected :
          Liste_Pts_Gen(Data_Liste_Pts_Gen *);
      public :
          Flux_Pts  all_pts();
          bool      empty() const;
          int       card() const;
          int       dim() const;
};

template <class Type,class Type_Base> class Data_Liste_Pts;

template <class Type,class Type_Base> class Liste_Pts : public Liste_Pts_Gen
{
     public :
        Liste_Pts(int dim);
        Liste_Pts(int dim,Type **,int nb);
        Liste_Pts(Type * x,Type * y,int nb);
        Im2D<Type,Type_Base>  image() const;
        void add_pt(Type *);
    private :
        Data_Liste_Pts<Type,Type_Base> * dlpt() const;
};


typedef Liste_Pts<U_int1,int>    Liste_Pts_U_int1;
typedef Liste_Pts<int1,int>      Liste_Pts_int1;
typedef Liste_Pts<U_int2,int>    Liste_Pts_U_int2;
typedef Liste_Pts<int2,int>      Liste_Pts_int2;
typedef Liste_Pts<int4,int>      Liste_Pts_int4;


typedef Liste_Pts<double_t4,double_t>      Liste_Pts_double_t4;
typedef Liste_Pts<double_t8,double_t>      Liste_Pts_double_t8;

extern Im1D_int4  hongrois(Im2D_int4 cost);

void ALGOHONGR(Im2D_int4,Im1D_int4);


extern void deriche_uc
     (
           Im2D_double_t4  gx,
           Im2D_double_t4  gy,
           Im2D_U_int1 i,
           double_t4       alpha
     );




extern GenIm alloc_im1d(GenIm::type_el type_el,int tx,void * data = 0);
extern GenIm alloc_im2d(GenIm::type_el type_el,int tx,int ty);
extern GenIm alloc_im2d(GenIm::type_el type_el,int tx,int ty, void * DataLin);


extern Im2DGen D2alloc_im2d(GenIm::type_el type_el,int tx,int ty);
// La copie d'une Im2DGen perd la virtualite, d'ou ....
extern Im2DGen * Ptr_D2alloc_im2d(GenIm::type_el type_el,int tx,int ty);

extern bool  type_im_integral(GenIm::type_el type_el);

extern int nbb_type_num(GenIm::type_el type_el);     // nb byte
extern bool msbf_type_num(GenIm::type_el type_el);   // is most signif first
extern bool signed_type_num(GenIm::type_el type_el); // is it signed int
extern GenIm::type_el type_u_int_of_nbb(int nbb,bool msbf = true);

extern  GenIm::type_el type_im(bool intregral,int nbb,bool Signed,bool msbf);
extern  GenIm::type_el type_im(const std::string &);

extern std::string eToString(const GenIm::type_el &);

extern std::string NamePlyOfType(GenIm::type_el);


extern void min_max_type_num(GenIm::type_el,int & v_min,int &v_max);
extern int  VCentrale_type_num(GenIm::type_el);

Fonc_Num Tronque(GenIm::type_el,Fonc_Num);


extern GenIm::type_el  type_of_ptr(const U_int1 * );
extern GenIm::type_el  type_of_ptr(const int1   * );
extern GenIm::type_el  type_of_ptr(const U_int2 * );
extern GenIm::type_el  type_of_ptr(const int2   * );
extern GenIm::type_el  type_of_ptr(const int4   * );
extern GenIm::type_el  type_of_ptr(const double_t4  * );
extern GenIm::type_el  type_of_ptr(const double_t8  * );
extern GenIm::type_el  type_of_ptr(const double_t16  * );


template <class Type>  ElMatrix<Type> gaussj(const ElMatrix<Type>  & m);
template <class Type>  void self_gaussj(ElMatrix<Type>  & m);
template <class Type>  bool self_gaussj_svp(ElMatrix<Type>  & m);

// Renvoie la liste des indices croissants de valeurs propres

std::vector<int> jacobi(const ElMatrix<double_t>& aMatSym,ElMatrix<double_t>& aValP,
            ElMatrix<double_t>& aVecP);
std::vector<int> jacobi_diag(const ElMatrix<double_t>& aMatSym,ElMatrix<double_t>& aValP,
                 ElMatrix<double_t>& aVecP);


std::vector<int> jacobi(const ElMatrix<double_t16>& aMatSym,ElMatrix<double_t16>& aValP,
            ElMatrix<double_t16>& aVecP);
std::vector<int> jacobi_diag(const ElMatrix<double_t16>& aMatSym,ElMatrix<double_t16>& aValP,
                 ElMatrix<double_t16>& aVecP);


void svdcmp ( const ElMatrix<double_t> & aMat, ElMatrix<double_t> & anU,
              ElMatrix<double_t> & aLineDiag, ElMatrix<double_t> & aV,bool direct);
void svdcmp_diag ( const ElMatrix<double_t> & aMat, ElMatrix<double_t> & anU,
              ElMatrix<double_t> & aDiag, ElMatrix<double_t> & aV,bool direct);


// L'"habituelle" decomposition QR,
std::pair<ElMatrix<double>, ElMatrix<double> > QRDecomp(const ElMatrix<double> & aM0);

// La RQ decomposition (sans doute + utile pour l'equation au 12 param)
std::pair<ElMatrix<double>, ElMatrix<double> > RQDecomp(const ElMatrix<double> & aM0);


// Renvoie la rotation la + proche, selon un algo trouve dans Golub et base sur
// la SVD
ElMatrix<double_t>  NearestRotation(const ElMatrix<double_t> &);


//  Probleme de conditionnement
void InspectPbCD(ElMatrix<double_t>);

// Calcule une rotation R tq R Antk = Imk;
//   - algo : norme les vecteur
//            les rend orthogonaux
//            calcul exact



ElMatrix<double_t> ComplemRotation
               (
                    const Pt3dr & anAnt1,
                    const Pt3dr & anAnt2,
                    const Pt3dr & anIm1,
                    const Pt3dr & anIm2
               );

// V1 et V2 sont initialise mais pas specialement unitaire ou ortho en entree
Pt3dr MakeOrthon(Pt3dr & aV1,Pt3dr & aV2);
ElMatrix<double>  MakeMatON(Pt3dr aV1,Pt3dr aV2);

// Seul V1 est initialise, sa norme est modifiee, V2 et V3 sont plus ou moins au hasard
// mais le resultat est RON
void MakeRONWith1Vect(Pt3dr & aV1,Pt3dr & aV2,Pt3dr & aV3);

// template <class Type>  ElMatrix<Type> operator * (const Type &,const ElMatrix<Type>&);



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


#if (STRICT_ANSI_FRIEND_TPL)
          // friend ElMatrix<Type> operator * <Type> (const Type &,const ElMatrix<Type>&);
#else
          // friend ElMatrix<Type> operator * <Type> (const Type &,const ElMatrix<Type>&);
#endif



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


// Suppose les N ligne du haut OK, complete avec les lignes
// du bas pour que forme au mieux une famille de vecteur libre,
// (la moins singuliere possible)
// n'utilise pour ce faire que des vecteur de la base canonique

void ComplBaseParLeHaut(ElMatrix<double_t> &,int NbLigneOk);

// FONCTION specifiques au M22, M33

ElMatrix<double_t> DiffRotEn1Pt(double_t teta01,double_t teta02,double_t teta12,Pt3dr pt);

template <class Type> Pt2d<Type> operator *
         (const ElMatrix<Type> & M,const Pt2d<Type> &);

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

typedef TplElRotation3D<double_t> ElRotation3D;

   class cRepereCartesien;


// Chgt de coord cartesien (et non euclidien, ca marche aussi si pas orthornormee)
class cChCoCart
{
     public :
        // mOri + mOx*aP.x + ...
        Pt3dr FromLoc(const Pt3dr &) const;
        cChCoCart Inv() const;
        cChCoCart(const Pt3dr &aOri,const Pt3dr&,const Pt3dr&,const Pt3dr&);

        static cChCoCart Xml2El(const cRepereCartesien &);
        cRepereCartesien El2Xml() const;
     private :
        Pt3dr mOri;
        Pt3dr mOx;
        Pt3dr mOy;
        Pt3dr mOz;
};

// La rotation etant exprimee dans un systeme 1, on la transforme en systeme 2:
ElRotation3D  ChangementSysC(const Pt3dr aP,const ElRotation3D&,const cSysCoord & aSource,const cSysCoord & aCible);

double ProfFromCam(const ElRotation3D & anOr,const Pt3dr & aP);  // anOr M->C


void SauvFile(const ElRotation3D &,const std::string &);
void XML_SauvFile(const ElRotation3D &,const std::string &,const std::string & aNameEngl,bool aModeMatr);
void XML_SauvFile(const ElRotation3D &,const std::string &,const std::string & aNameEngl,double altisol,double prof,bool aModeMatr);


ElRotation3D ReadFromFile(const ElRotation3D *,const std::string &);

template <class Type>  class ElPolynome;
//template <class Type>  ElPolynome<Type> operator * (const Type &,const ElPolynome<Type> &) ;

template <class Type>  class ElPolynome
{
     public :
          friend  ElPolynome<Type> operator *<Type> (const Type &,const ElPolynome<Type> &) ;
          ElPolynome<Type> operator * (const Type &) const;
          ElPolynome<Type> operator * (const ElPolynome<Type> &) const;
          ElPolynome<Type> operator + (const ElPolynome<Type> &) const;
          ElPolynome<Type> operator - (const ElPolynome<Type> &) const;

          void self_deriv() ;
          ElPolynome deriv() const;

          Type  operator()(const Type &) const;
          Type &  operator[](int k);
          const Type &  operator[](int k) const;
          Type   at(int k) const;  // def = 0
          int degre() const {return (int) _coeff.size()-1;}

          ElPolynome();
          ElPolynome(char *,int degre);  // Arg 1 : bidon, pour eviter
                                         // confusion avec ElPolynome(int)
          ElPolynome(const Type &);
          ElPolynome(const Type &,const Type &);
          ElPolynome(const Type &,const Type &,const Type &);

          static ElPolynome FromRoots(const std::vector < Type > &);
          static ElPolynome FromRoots(const Type&);
          static ElPolynome FromRoots(const Type&,const Type&);
          static ElPolynome FromRoots(const Type&,const Type&,const Type&);
          static ElPolynome FromRoots(const Type&,const Type&,const Type&,const Type&);
      friend void Reduce(ElPolynome<double_t> &); // Supprime les coeffs de degre haut nuls

     private :
          std::vector<Type> _coeff;
      static const Type  El0;
      static const Type  El1;
};

template <class Type> void  RealRootsOfRealPolynome
     (
         std::vector<Type> &  Sols,
         const ElPolynome<Type>  &aPol,
         Type                    tol,
         int                     ItMax
     );


void RacinesPolyneDegre2Reel
     (double_t a0,double_t a1,double_t a2,int & CAS,Pt2dr & X1,Pt2dr  & X2);
void RacineCarreesComplexe (Pt2dr X,Pt2dr &A1,Pt2dr &A2);
void RacinesPolyneDegre3Reel
     (
        double_t A0,double_t A1,double_t A2,double_t A3,
        int & CAS,
        Pt2dr & X1,Pt2dr  & X2,Pt2dr & X3
     );
void RacinesPolyneDegre4Reel
     (
        double_t A0,double_t A1,double_t A2,double_t A3, double_t A4,
        int & CAS,
        Pt2dr & X1,Pt2dr  & X2,Pt2dr & X3,Pt2dr & X4
     );



class Monome2dReal
{
     public :
         Monome2dReal (int d0X,int d0Y,double_t ampl) :
             mD0X  (d0X),
             mD0Y  (d0Y),
             mAmpl (ampl)
         {
         }


         double_t   CoeffMulNewAmpl (double_t NewAmpl) const;

         void SetAmpl(double_t);
         double_t Ampl(double_t) const;

         double_t operator () (Pt2dr aP) const;
         Pt2dr grad(Pt2dr aP) const;

         Fonc_Num FNum() const;
         int DegreX() const {return mD0X;}
         int DegreY() const {return mD0Y;}
         int DegreTot() const;

         void Show(bool X) const;

      private :


         int mD0X;
         int mD0Y;
         double_t mAmpl;
};



class Polynome2dReal
{
      public :
            std::vector<double> ToVect() const;
            static Polynome2dReal FromVect(const std::vector<double>&,double anAmp);


            Polynome2dReal(int aD0,double_t anAmpl); // Contient tous les monomes, avec un coeff 1.0
            void SetDegre1(double_t aV0,double_t aVX, double_t aVY,bool AnnulOthers = true);

            double_t operator () (Pt2dr aP) const;
            Pt2dr grad(Pt2dr aP) const;
            int NbMonome() const;
            const Monome2dReal &  KthMonome(int) const;
            int    DegreX(int) const;
            int    DegreY(int) const;
            int    DegreTot(int) const;


            void SetCoeff(int aNumMon,double_t aCoeff);
            double_t Coeff(int aNumMon) const;
            double_t & Coeff(int aNumMon) ;
            void Show(int aNumMon) const;
            void Show() const;

            Fonc_Num FNum() const;
            double_t  Ampl() const;
        void write(class  ELISE_fp &) const;
        static Polynome2dReal read(class  ELISE_fp &);

            // return le polynome correspondant a :
            //     P ->  aChSacle * Pol(P/aChSacle)
            Polynome2dReal MapingChScale(double_t aChSacle) const;


            Polynome2dReal operator + (const Polynome2dReal &) const;
            Polynome2dReal operator - (const Polynome2dReal &) const;
            Polynome2dReal operator * (double_t) const;
            Polynome2dReal operator / (double_t) const;
            int DMax() const;

            static  Polynome2dReal PolyDegre1(double_t aV0,double_t aVX,double_t aVY);

      private :
            Polynome2dReal
            (
                  const Polynome2dReal & aPol1,
                  double_t aCoeff1,
                  const Polynome2dReal & aPol2,
                  double_t aCoeff2
            );


            double_t   CoeffNewAmpl (int k,double_t NewAmpl) const;

            void AssertIndexeValide(int) const;

            std::vector<Monome2dReal>  mMons;
            std::vector<double_t>  mCoeff;
            double_t mAmpl;
            int mDMax;

};


            /***************************************/
            /*                                     */
            /*       FFT-FFT-FFT-FFT               */
            /*                                     */
            /***************************************/

void  ElFFT
      (
          Im2D_double_t8 aReIm,
      Im2D_double_t8 aImIm,
      bool       aDirect
      );

      // Correlation ni normalisee, ni centree
      // images circulaires
      // Remplit la correlation dans Im1
void  ElFFTCorrelCirc
      (
           Im2D_double_t8 aReIm1,
       Im2D_double_t8 aReIm2
      );

     // meme chose  mais images
     // paddee avec suffisament de 0
     // pour ne pas avoir d'effets de bord
Im2D_double_t8   ElFFTCorrelPadded
             (
                  Im2D_double_t8 aReIm1,
                  Im2D_double_t8 aReIm2
             );


     // idem, mais normalisee centree;
     // anEpsilon est utilisee pour les divisions

Im2D_double_t8   ElFFTCorrelNCPadded
             (Im2D_double_t8 aReIm1,Im2D_double_t8 aReIm2,double_t anEps,double_t aSurfMin=-1) ;

           // Quand aSurfMin est >0, et que la surface  S
           // (ou Ponderation pour ElFFTPonderedCorrelNCPadded)
           // est < a aSurfMin , le coeff de correlation C est reetalonne
           // entre -1 et C, proportionellement a S/aSurfMin


      // Avec Ponderation
Im2D_double_t8   ElFFTPonderedCorrelNCPadded
             (
                Fonc_Num   aF1,
                Fonc_Num   aF2,
                Pt2di      aSz,
                Fonc_Num   aPds1,
                Fonc_Num   aPds2,
                double_t       anEps,
                double_t       aSurfMin = -1
             );


/*
 renvoie  si I a ete calculee par ElFFTCorrelPadded
    --
    \
    /    I1(p+aDecIm1) I2(p)
    __
*/

double_t ImCorrFromNrFFT(Im2D_double_t8 anIm,Pt2di aDecIm1);

// Les Images donnees pour effectuer le calcul
// sont des images FFT
Pt2di DecIm2DecFFT(Im2D_double_t8 anImFFT,Pt2di aDecIm1);
Pt2di DecFFT2DecIm(Im2D_double_t8 anImFFT,Pt2di aP);
Pt2d<Fonc_Num> FN_DecFFT2DecIm(Im2D_double_t8 anIm);


class RImGrid
{
    public :
       RImGrid
       (
           Pt2dr      anOrigine,
           Pt2dr      aStep,
           Im2D_double_t8 anIm
       );
       RImGrid
       (
          bool  AdaptStep,  // Si true, le pas est calcule pour
                        // diviser exactement l'intervalle P0 P1
          Pt2dr aP0,
          Pt2dr aP1,
          Pt2dr  aStepGr,
      const std::string & aName = "RImGrid",
          Pt2di  aSz = Pt2di(0,0)
       );
       ~RImGrid();
       void InitGlob( Fonc_Num aFonc );

       Pt2dr ToGrid(Pt2dr aP) const;
       Pt2dr ToReal(Pt2dr aP) const;
       Pt2di SzGrid() const;
       void TranlateIn(Pt2dr);

       double_t Value(Pt2dr  aRealP) const;
       double_t ValueAndDer(Pt2dr aRealP,Pt2dr & aDer);
       void SetValueGrid(Pt2di aP,double_t aV);
       void ExtDef(); // Fait une extension "genre" ppv des pixels
                      // initialisee sur les pixels valant Def


        // aPt -> Value (aPt / aChSacle)
        // aPt -> aChSacle * Value (aPt / aChSacle)  (si ModeMapping = true)

        RImGrid *  NewChScale(double aChSacle ,bool ModeMapping);

        void write(class  ELISE_fp & aFile) const;
        static RImGrid  * read(ELISE_fp & aFile);
    const Pt2dr & Step() const;
    Pt2dr Origine() const;
        Im2D_double_t8           DataGrid();

        // Les conventions sont compatible avec le
        // le cas ou aChScale est une focale et Tr une
        //  coordonnees de point principal, en sortie : (X *aChScale + aTr)
        void SetTrChScaleOut(double_t aChScale,double_t aTr);
        void SetTrChScaleIn(double_t aChScale,Pt2dr aTr);

    const std::string & Name() const;

        const Pt2dr & P0() const;
        const Pt2dr & P1() const;
    bool  StepAdapted() const;

        private :
           RImGrid(const RImGrid &) ; // NImpl
           Pt2dr                mP0;
           Pt2dr                mP1;
           Pt2dr                mStepGr;
           Pt2di                mSzGrid;
           double_t                 mDef;
           Im2D_double_t8           mGrid;
           TIm2D<double_t,double_t>*    mTim;
       std::string          mName;
       bool                 mStepAdapted;

};

class PtImGrid
{
    public :
       PtImGrid (bool AdaptStep, Pt2dr aP0, Pt2dr aP1, Pt2dr  aStepGr,const std::string & = "PtImGrid");
       // ToGrid et ToReal : transfo lineaire, conversion
       // entre le monde reel et les coordonnes d'entree de la grille
       Pt2dr ToGrid(Pt2dr aP) const;
       Pt2dr ToReal(Pt2dr aP) const;
       Pt2di SzGrid() const;

       Pt2dr  Value(Pt2dr aRealP);
      // aGradX : grad de la valeur en X / a x ET y
       Pt2dr ValueAndDer(Pt2dr aRealP,Pt2dr & aGradX,Pt2dr & aGradY);
       void SetValueGrid(Pt2di aP,Pt2dr  aV);

        void write(class  ELISE_fp & aFile) const;
        static PtImGrid  * read(ELISE_fp & aFile);
       ~PtImGrid();
    const Pt2dr & Step() const;
    Pt2dr Origine() const;

        Im2D_double_t8           DataGridX();
        Im2D_double_t8           DataGridY();
    const std::string & Name() const ;
    const std::string & NameX() const ;
    const std::string & NameY() const ;

       PtImGrid (RImGrid *,RImGrid * GY,const std::string &);
       void SetTrChScaleOut(double_t aChScale,Pt2dr aTr);
       void SetTrChScaleIn(double_t aChScale,Pt2dr aTr);

       const Pt2dr & P0() const;
       const Pt2dr & P1() const;
       bool  StepAdapted() const;
    private :
    PtImGrid (ELISE_fp & aFile);
        RImGrid   *mGX;
        RImGrid   *mGY;
    std::string          mName;
};


/*
   REMPLACE PAR cDbleGrid  dans "general/photogram.h"
*/

void ShowMatr(const char * mes, ElMatrix<double_t> aMatr)  ;


/*******************************************************/
/*                                                     */
/*       NOYAU intERPOLATEUR 1D                        */
/*                                                     */
/*******************************************************/


/*
    REDEFINITION DES intERPOLATEURS,  moins optimises mais plus
    generaux;

    cKernelInterpol  : Classe d'interface
    cCubicInterpKernel  : noyau cubique elementaire
    cScaledKernelInterpol : Noyau dilate, a partir d'un noyau existant

*/

class cKernelInterpol1D
{
      public :
       //  Interpolateur "standard" de changement  de coordonnees, un bicubique
       // dilate  et tabule, le parametre du bicub est calcule selon la regle du
       // ChScale ( 0 si > 1.5, -0.5  si < 1.0, interpole entre les 2)
        static cKernelInterpol1D  * StdInterpCHC(double aScale,int aNbTab=100);

        double Interpole(const cFoncI2D &,const double & x,const double & y);

        virtual double  Value(double x) const = 0;
        inline const double &  SzKernel() const{return mSzKernel;}

       virtual ~cKernelInterpol1D();
       cKernelInterpol1D (double mSzKernel);
      protected :
        double mSzKernel;
        std::vector<double> mVecPX;
        double *            mDataPX;
        std::vector<double> mVecPY;
        double *            mDataPY;
};



class cCubicInterpKernel : public cKernelInterpol1D
{
     public :
         double  Value(double x) const ;
         // double  SzKernel() const;
         double_t Derivee(double_t x) const;
         void ValAndDerivee(double_t x,double_t &V,double_t &D) const;
         // aA = valeur de la derivee en 0
         // si vaut -0.5, reconstitue parfaitement une droite
         // doit etre comprise en 0 et -3
         cCubicInterpKernel(double_t aA);
     private :
         double_t mA;
};

// Sinus Cardinal appodise avec fentre de Tukey  = Diriclet au debut
// et cosinus qui assure le raccord derivale en 0
class cSinCardApodInterpol1D : public cKernelInterpol1D
{
      public :
         typedef  enum
         {
            eTukeyApod,
            eModePorte
         }  eModeApod;
         double  Value(double x) const ;
         cSinCardApodInterpol1D
         (
                eModeApod,
                double aSzK,
                double aSzApod,
                double aEpsilon=1e-3,
                bool   OnlyApod = false
         );
      private :
         eModeApod mModeApod;
         bool      mOnlyApod;
         double    mSzApod;
         double    mEpsilon;

};

class cScaledKernelInterpol :  public cKernelInterpol1D

{
      public :
         double  Value(double x) const ;
         cScaledKernelInterpol(const cKernelInterpol1D *,double ascale);
         ~cScaledKernelInterpol();
      private :
         const cKernelInterpol1D * mKer0;  // Adopte
         double                  mScale;
         double                  m1SurS;
};

class cTabulKernelInterpol : public cKernelInterpol1D
{
    public :
        cTabulKernelInterpol(const cKernelInterpol1D *, int NbDisc1,bool mPrecBil);
        ~cTabulKernelInterpol();
        double  Value(double x) const ;
        double  ValueDer(double x) const ;
        inline const double *   AdrDisc2Real(double  aX) const;
        inline const double *   DerAdrDisc2Real(double  aX) const;
        inline int NbDisc1() const {return mNbDisc1;}
    private :
        inline double   Disc2Real(double  aX) const;
        inline int   Real2Disc(double  aX) const;
        //  const cKernelInterpol1D  * mKer0; // Adopte
        int                        mNbDisc1;
        int                        mNbValPos;
        int                        mSzTab;
        Im1D_double_t8                 mImTab;
        double *                   mTab;
        Im1D_double_t8                 mImDer;
        double *                   mDer;
};




      //========================================

template <class TypeEl>
class cInterpolateurIm2D
{
     public :
         virtual double GetVal(TypeEl ** aTab,const Pt2dr &  aP) const = 0;

//   version qui calcule le gradient par simple diff

          Pt3dr GetValAndQuickGrad(TypeEl ** aTab,const Pt2dr &  aP) const;
         virtual Pt3dr GetValDer(TypeEl ** aTab,const Pt2dr &  aP) const ;

         virtual void  GetVals(TypeEl ** aTab,const Pt2dr *  aP,double *,int Nb) const;
         // SzKernel, a partir de l'arrondi inferieur, de combien
         // faut il dilater x, typiquement 1 pour bilin, 2 pour bicub
         //  1 pour PPV (car fait a partir de round_ni)
         virtual int  SzKernel() const=0;
         virtual ~cInterpolateurIm2D();
   private :
};


template <class TypeEl> class cTabIM2D_FromIm2D : public cInterpolateurIm2D<TypeEl>
{
     public :
         virtual double GetVal(TypeEl ** aTab,const Pt2dr &  aP) const ;
         virtual Pt3dr GetValDer(TypeEl ** aTab,const Pt2dr &  aP) const ;
         // SzKernel, a partir de l'arrondi inferieur, de combien
         // faut il dilater x, typiquement 1 pour bilin, 2 pour bicub
         //  1 pour PPV (car fait a partir de round_ni)
         virtual int  SzKernel() const;
         virtual ~cTabIM2D_FromIm2D();

          cTabIM2D_FromIm2D(const cKernelInterpol1D * ,int aNbDisc,bool aByBil);
   private :


          const cKernelInterpol1D*    mK0; // Debug
          cTabulKernelInterpol  mK1;
          int                   mSzK;



};



/*
template <class TypeEl>
class cGenTabulatedInterpolateur
{
     public :
         virtual double GetVal(TypeEl ** aTab,const Pt2dr &  aP) const = 0;
         virtual void  GetVals(TypeEl ** aTab,const Pt2dr *  aP,double *,int Nb) const;
         // SzKernel, a partir de l'arrondi inferieur, de combien
         // faut il dilater x, typiquement 1 pour bilin, 2 pour bicub
         //  1 pour PPV (car fait a partir de round_ni)
         virtual int  SzKernel() const=0;
         virtual ~cGenTabulatedInterpolateur();
   private :
};
*/



template <class TypeEl>
class cInterpolPPV : public cInterpolateurIm2D<TypeEl>
{
     public :
         virtual double GetVal(TypeEl ** aTab,const Pt2dr &  aP) const ;
         inline double  IL_GetVal(TypeEl ** aTab,const Pt2dr &  aP) const ;
         virtual int  SzKernel() const;
         void  GetVals(TypeEl ** aTab,const Pt2dr *  aP,double *,int Nb) const;
   private :
};


template <class TypeEl>
class cInterpolBilineaire : public cInterpolateurIm2D<TypeEl>
{
     public :
         inline double  IL_GetVal(TypeEl ** aTab,const Pt2dr &  aP) const ;
         double GetVal(TypeEl ** aTab,const Pt2dr &  aP) const ;
         virtual int  SzKernel() const;
         virtual void  GetVals(TypeEl ** aTab,const Pt2dr *  aP,double *,int Nb) const;
   private :
};



// Variante "pure" de l'interpolateur bicubique, c.a.d
// sans approximation permettant de gagner du temps (genre
// arrondis)
template <class TypeEl>
class cInterpolBicubique : public cInterpolateurIm2D<TypeEl>
{
     public :
         virtual double GetVal(TypeEl ** aTab,const Pt2dr &  aP) const ;
         virtual int  SzKernel() const;
         cInterpolBicubique(double_t aVal);  // -0.5 val par def (droite->droite)
   private :
        cCubicInterpKernel mCIK;
};

template <class TypeEl>
class cInterpolSinusCardinal : public cInterpolateurIm2D<TypeEl>
{
    public :
        cInterpolSinusCardinal(int sizeOfWindow, bool apodise = false);
        virtual ~cInterpolSinusCardinal();
        virtual double GetVal(TypeEl ** aTab,const Pt2dr &  aP) const ;
        virtual int  SzKernel() const;
    private :
        bool m_apodise;
        int m_sizeOfWindow;
        double_t *m_tabX, *m_tabY, *m_tabTemp;
};

template <class Type>
Pt3dr BicubicInterpol
      (const cCubicInterpKernel & aCIK,Type ** data,Pt2dr aP);
template <class Type>
double_t  BicubicInterpolVal
      (const cCubicInterpKernel & aCIK,Type ** data,Pt2dr aP);



// EN FAIT cTplCIKTabul sert a tabuler d'autre interp que bicub
//

typedef enum
{
   eTabulBicub,
   eTabulMPD_EcartMoyen,
   eTabulMPD_EcartType,
   eTabul_Bilin
}
eModeInterTabul;


template <class TypeEl,class tTabulCIK>
class  cTplCIKTabul  : public cInterpolateurIm2D<TypeEl>
{
       public :
           // typedef typename El_CTypeTraits<TypeEl>::tBase tTabulCIK;
           // Nombre de bits pour le codage des valeurs et de la resol


          cTplCIKTabul(int aNBBVal,int aNBBResol,double_t aVal,eModeInterTabul = eTabulBicub);


          double_t     XofInd(int Ind) {return Ind/double_t(mNbResol);}

          inline tTabulCIK     InterpolateVal(TypeEl *,int Frac) const ;
          inline tTabulCIK     InterpolateDer(TypeEl *,int Frac) const ;

          double_t     BicubValue(TypeEl ** aTab,const Pt2dr &  aP) const ;
          Pt3dr    BicubValueAndDer(TypeEl ** aTab,const Pt2dr &  aP) const ;

      bool OkForInterp(Pt2di aSz,Pt2dr aP) const;

          double GetVal(TypeEl ** aTab,const Pt2dr &  aP) const;
          int SzKernel() const;

       private :
          int            mNbResol;
          int            mNbVal;
          double_t           mNbVal2;
          Im2D<tTabulCIK,tTabulCIK>  mTV;
          tTabulCIK **       mDV;
          Im2D<tTabulCIK,tTabulCIK>  mTD;
          tTabulCIK **       mDD;
};
typedef cTplCIKTabul<U_int1,int>  cCIKTabul;

void FiltrageImage3D
     (
           int StepX,int StepY, int StepZ,
       double *  Data,
           int    Tx, int    Ty, int    Tz
     );

void NoyauxFiltrageImage3D
     (
           int StepX,int StepY, int StepZ,
       double *  Data,
           int    Tx, int    Ty, int    Tz
     );

Im2D_U_int1  Shading
             (
                  Pt2di    aSz,
                  Fonc_Num aFMnt,
                  int      aNbDir,
                  double_t Anisotropie
             );


template <class Type> class cTestTPL
{
      public :
          static Type  theTab[4];
      private :
};

class cElBitmFont
{
    public :
       static  cElBitmFont & BasicFont_10x8();
       virtual Im2D_Bits<1> ImChar(char) = 0;
       virtual ~cElBitmFont();
    private :
      static class cElImplemBitmFont * theFont_10x8;
};


class cIm2DInter
{
    public :
       virtual double Get(const Pt2dr &)= 0;
       virtual double GetDef(const Pt2dr &,double)= 0;
       virtual int  SzKernel() const = 0;
       virtual ~cIm2DInter(){}
};

#endif //   _ELISE_GENERAL_BITM_H_

