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


#define NoOperatorVirgule

#if (0) // (ELISE_unix)
// Pour les quelques fichiers (b_0_45.cpp par ex) qui generent des erreurs, a cause de "," dans la STL
#ifndef NoTemplateOperatorVirgule

        //===============
        // GEOMETRIC
        //===============

            // 1-D
            // - - - 

extern Flux_Pts rectangle(INT,INT);

extern Flux_Pts border_rect(INT p1,INT p2,INT b1,INT b2);
extern Flux_Pts border_rect(INT p1,INT p2,INT b);

            // 2-D
            // - - - 

                   // surfacic

extern Flux_Pts rectangle(Pt2di p0,Pt2di p1);
extern Flux_Pts rectangle(const Box2di &);


                   // lineic

                         // lines 

extern Flux_Pts line(Pt2di p0,Pt2di p1);
extern Flux_Pts line(ElList<Pt2di>,bool ferm = false);
extern Flux_Pts line_4c(Pt2di p0,Pt2di p1);
extern Flux_Pts line_4c(ElList<Pt2di>,bool ferm = false);
extern Flux_Pts line_for_poly(ElList<Pt2di>);

extern Flux_Pts polygone(ElList<Pt2di>,bool front = true);
extern Flux_Pts quick_poly(ElList<Pt2di>);

/*  Interface pour convertir les container standard en "vielle"
    liste elise.
*/





Fonc_Num rect_kth 
         (
                    Fonc_Num  f,
                    double kth,
                    Box2di  side,
                    INT   max_vals,
                    bool CatInit = false,
                    bool aModePond = false,
                    Histo_Kieme::mode_h=Histo_Kieme::undef
         );
Fonc_Num rect_kth 
         (
                    Fonc_Num  f,
                    double kth,
                    Pt2di  side,
                    INT   max_vals,
                    bool CatInit = false,
                    bool aModePond = false,
                    Histo_Kieme::mode_h=Histo_Kieme::undef
         );
Fonc_Num rect_kth 
         (
                    Fonc_Num  f,
                    double kth,
                    INT  side,
                    INT   max_vals,
                    bool CatInit = false,
                    bool aModePond = false,
                    Histo_Kieme::mode_h=Histo_Kieme::undef
                    );

Fonc_Num rect_median 
         (
                    Fonc_Num  f,
                    Box2di  side,
                    INT   max_vals,
                    bool CatInit = false,
                    bool aModePond = false,
                    Histo_Kieme::mode_h=Histo_Kieme::undef
         );
Fonc_Num rect_median 
         (
                    Fonc_Num  f,
                    Pt2di  side,
                    INT   max_vals,
                    bool CatInit = false,
                    bool aModePond = false,
                    Histo_Kieme::mode_h=Histo_Kieme::undef
         );
Fonc_Num rect_median 
         (
                    Fonc_Num  f,
                    INT    side,
                    INT   max_vals,
                    bool CatInit = false,
                    bool aModePond = false,
                    Histo_Kieme::mode_h=Histo_Kieme::undef
         );
Fonc_Num MedianBySort(Fonc_Num f,INT NbMed);
Fonc_Num OmbrageKL(Fonc_Num Prof,Fonc_Num Masq,double aPente,int aSzV);
Fonc_Num NFoncDilatCond(Fonc_Num f2Dil,Fonc_Num fCond,bool aV4,int aNb);



Fonc_Num RectKth_Pondere
          (
               Fonc_Num    f1,
               Fonc_Num    f2,
               REAL         kth,
               INT          side,
               INT         max_vals
          );  // Non benche


// Fonc_Num  rect_kth (Fonc_Num f,INT kth,Box2di side,INT max_vals);


Fonc_Num  rect_rank(Fonc_Num f,Box2di side,INT max_vals,bool CatInit = false);
Fonc_Num  rect_egal_histo(Fonc_Num f,Box2di side,INT max_vals);


         // assoc

Fonc_Num rect_red(const OperAssocMixte &,Fonc_Num f,Box2di,bool aCatFinit = false);

Fonc_Num rect_var_som(Fonc_Num f,Fonc_Num fside,Box2di);
Fonc_Num rect_som(Fonc_Num f,Box2di,bool aCatFinit = false);
Fonc_Num rect_som(Fonc_Num f,Pt2di,bool aCatFinit = false);
Fonc_Num rect_som(Fonc_Num f,INT,bool aCatFinit = false);

Fonc_Num Moy(Fonc_Num,int);
Fonc_Num Moy1(Fonc_Num aF);
Fonc_Num MoyIter(Fonc_Num aF,int aSz,int aNbIter);


Fonc_Num rect_max(Fonc_Num f,Box2di,bool aCatFinit = false);
Fonc_Num rect_max(Fonc_Num f,Pt2di,bool aCatFinit = false);
Fonc_Num rect_max(Fonc_Num f,INT,bool aCatFinit = false);


Fonc_Num rect_min(Fonc_Num f,Box2di,bool aCatFinit = false);
Fonc_Num rect_min(Fonc_Num f,Pt2di,bool aCatFinit = false);
Fonc_Num rect_min(Fonc_Num f,INT,bool aCatFinit = false);

     // Iteration de sommes
Fonc_Num FoncMoy(Fonc_Num aF,int aK);
std::vector<int>  DecompSigmaEnInt(double aSigma,int aNb);
Fonc_Num MoyByIterSquare(Fonc_Num aF,double aSigmaCible,int aNbIter);




    /*  -  -  -  -  -  -  -  -  -  -  */
    /*       "Jump" operator          */
    /*  -  -  -  -  -  -  -  -  -  -  */

Fonc_Num  clip_def(Fonc_Num,REAL,Pt2di,Pt2di);
Fonc_Num  clip_def(Fonc_Num,REAL,INT* p0,INT* p1,INT dim);


    /*  -  -  -  -  -  -  -  -  -  -  */
    /*            BINARY              */
    /*  -  -  -  -  -  -  -  -  -  -  */


    // binary associative mixte operators

extern   Fonc_Num operator + (Fonc_Num,Fonc_Num);
extern   Fonc_Num operator * (Fonc_Num,Fonc_Num);
            //  ( Max and Min, because, max and min create some tricky confusion with
            //     the functions on integral types.)

extern   Fonc_Num Max        (Fonc_Num,Fonc_Num);
extern   Fonc_Num Min        (Fonc_Num,Fonc_Num);

extern   Fonc_Num Max        (Fonc_Num,Fonc_Num,Fonc_Num);
extern   Fonc_Num Min        (Fonc_Num,Fonc_Num,Fonc_Num);
extern   Fonc_Num Max        (Fonc_Num,Fonc_Num,Fonc_Num,Fonc_Num);
extern   Fonc_Num Min        (Fonc_Num,Fonc_Num,Fonc_Num,Fonc_Num);

    // binary mixte  operators

extern   Fonc_Num operator / (Fonc_Num,Fonc_Num);
extern   Fonc_Num operator - (Fonc_Num,Fonc_Num);
extern   Fonc_Num pow(Fonc_Num,Fonc_Num);


    // binary associative integer operators

extern   Fonc_Num operator &  (Fonc_Num,Fonc_Num);
extern   Fonc_Num operator && (Fonc_Num,Fonc_Num);
extern   Fonc_Num operator |  (Fonc_Num,Fonc_Num);
extern   Fonc_Num operator || (Fonc_Num,Fonc_Num);
extern   Fonc_Num operator ^  (Fonc_Num,Fonc_Num);
extern   Fonc_Num ElXor       (Fonc_Num,Fonc_Num);
extern   Fonc_Num operator %  (Fonc_Num,Fonc_Num);
extern   Fonc_Num mod         (Fonc_Num,Fonc_Num); // as %, but the result is always >= 0
extern   Fonc_Num operator << (Fonc_Num,Fonc_Num);
extern   Fonc_Num operator >> (Fonc_Num,Fonc_Num);

    //  comparison operators

extern   Fonc_Num operator == (Fonc_Num,Fonc_Num);
extern   Fonc_Num operator != (Fonc_Num,Fonc_Num);
extern   Fonc_Num operator < (Fonc_Num,Fonc_Num);
extern   Fonc_Num operator <= (Fonc_Num,Fonc_Num);
extern   Fonc_Num operator > (Fonc_Num,Fonc_Num);
extern   Fonc_Num operator >= (Fonc_Num,Fonc_Num);

       // version without oveload (to avoid incompatibility with STL)

extern   Fonc_Num SuperiorStrict(Fonc_Num,Fonc_Num);
extern   Fonc_Num NotEqual(Fonc_Num,Fonc_Num);


// HYPER LENT POU MISE AU POINT
double GETVALPT(Fonc_Num,Pt2di);


    /*  -  -  -  -  -  -  -  -  -  -  */
    /*            UNARY               */
    /*  -  -  -  -  -  -  -  -  -  -  */


    // unary mixte  operators

extern   Fonc_Num operator -(Fonc_Num);
extern   Fonc_Num Abs(Fonc_Num);
extern   Fonc_Num Square(Fonc_Num);
extern   Fonc_Num Cube(Fonc_Num);
Fonc_Num PowI(Fonc_Num f,INT aDegre);


extern   double Square(double);

    // Operateur utile au devt en four des fonction radiale

double CosRx(double);  // cos sqrt x
Fonc_Num CosRx(Fonc_Num);  // cos sqrt x
double SinCardRx(double);  // cos sqrt x
Fonc_Num SinCardRx(Fonc_Num);  // cos sqrt x



    // Operateur utile a la fonction de conversion des Fish Eye Linear

double AtRxSRx(double x);      // Atan(sqrt(x)) / sqrt(x)
Fonc_Num AtRxSRx(Fonc_Num x);     
double DerAtRxSRx(double x);   // Derivee de  AtRxSRx
Fonc_Num DerAtRxSRx(Fonc_Num x); 
double At2Rx(double x);        // Atan ^2 (sqrt(x)) 
Fonc_Num At2Rx(Fonc_Num x);       
double DerAt2Rx(double x);     // Derivee At2Rx
Fonc_Num DerAt2Rx(Fonc_Num x);    

// Predicteur d'inversion
double TgRxSRx(double x);      // Tang(sqrt(x)) / sqrt(x)
Fonc_Num TgRxSRx(Fonc_Num x);      // Tang(sqrt(x)) / sqrt(x)

    // Operateur utile a la fonction de conversion des Fish Eye equisolid
    //
    //  2 sin (At(X)/2)
    //
double Dl_f2SAtRxS2SRx(double x);
double Std_f2SAtRxS2SRx(double x);
double  f2SAtRxS2SRx(double); // 2 sin(Atan(sqrt(x))/2) / sqrt(x)
Fonc_Num  f2SAtRxS2SRx(Fonc_Num); 

double Dl_Der2SAtRxS2SRx(double x);   
double Std_Der2SAtRxS2SRx(double x);   
double Der2SAtRxS2SRx(double x);   // Der f2SAtRxS2SRx


    // Operateur utile a la fonction de conversion des Fish Eye Linear

double AtRxSRx(double x);      // Atan(sqrt(x)) / sqrt(x)
Fonc_Num AtRxSRx(Fonc_Num x);     
double DerAtRxSRx(double x);   // Derivee de  AtRxSRx
Fonc_Num DerAtRxSRx(Fonc_Num x); 
double At2Rx(double x);        // Atan ^2 (sqrt(x)) 
Fonc_Num At2Rx(Fonc_Num x);       
double DerAt2Rx(double x);     // Derivee At2Rx
Fonc_Num DerAt2Rx(Fonc_Num x);    

// Predicteur d'inversion
double TgRxSRx(double x);      // Tang(sqrt(x)) / sqrt(x)
Fonc_Num TgRxSRx(Fonc_Num x);      // Tang(sqrt(x)) / sqrt(x)

    // Operateur utile a la fonction de conversion des Fish Eye equisolid
    //
    //  2 sin (At(X)/2)
    //
double Dl_f2SAtRxS2SRx(double x);
double Std_f2SAtRxS2SRx(double x);
double  f2SAtRxS2SRx(double); // 2 sin(Atan(sqrt(x))/2) / sqrt(x)
Fonc_Num  f2SAtRxS2SRx(Fonc_Num); 

double Dl_Der2SAtRxS2SRx(double x);   
double Std_Der2SAtRxS2SRx(double x);   
double Der2SAtRxS2SRx(double x);   // Der f2SAtRxS2SRx
Fonc_Num Der2SAtRxS2SRx(Fonc_Num x);
double f4S2AtRxS2(double);    ;  // 4 sin^2(Atan(sqrt(x))/2))
Fonc_Num f4S2AtRxS2(Fonc_Num);    ;  

double  Dl_Der4S2AtRxS2(double);
double  Std_Der4S2AtRxS2(double);
double Der4S2AtRxS2(double);    ;  // Der f4S2AtRxS2
Fonc_Num Der4S2AtRxS2(Fonc_Num);    ;  // Der f4S2AtRxS2

// Predicteur d'inversion

double Dl_Tg2AsRxS2SRx(double x);      // 2 (Tang (Asin (sqrt(x))/2) / sqrt(x)
double Std_Tg2AsRxS2SRx(double x);      // 2 (Tang (Asin (sqrt(x))/2) / sqrt(x)
double Tg2AsRxS2SRx(double x);      //  (Tang 2 (Asin (sqrt(x)/2))) / sqrt(x)
Fonc_Num Tg2AsRxS2SRx(Fonc_Num x);      //  (Tang 2 (Asin (sqrt(x)/2))) / sqrt(x)




     // mathematical operator 

extern   Fonc_Num sqrt(Fonc_Num);
extern   Fonc_Num cos (Fonc_Num);
extern   Fonc_Num sin (Fonc_Num);
extern   Fonc_Num tan (Fonc_Num);
extern   Fonc_Num atan (Fonc_Num);
extern   Fonc_Num erfcc (Fonc_Num);
extern   Fonc_Num log (Fonc_Num);
extern   Fonc_Num log2 (Fonc_Num);
extern   Fonc_Num exp (Fonc_Num);

extern   Fonc_Num  AtanXY(Fonc_Num,Fonc_Num);
extern   double    AtanXY(double,double);

// Renvoie 255 * erfc ((f-s1)/sqrt(s2))
extern Fonc_Num FoncNormalisee_S1S2 (Flux_Pts aFl,Fonc_Num aFPds,Fonc_Num aF);
extern Fonc_Num FoncNormalisee_S1S2 (Flux_Pts aFl,Fonc_Num aF); // FPds=1.0

#if ( ELISE_windows & !ELISE_MinGW & _MSC_VER < 1800 )
inline double log2(const double & aD)
{
       return log(aD) / log(2.0);
}
#endif


     // convertion functions 

                // convert f to a real function

extern Fonc_Num Rconv(Fonc_Num f);

                 // convert f to an integer function
                 // Iconv : faster but use  C standard-convertion
                 // round_up : smallest integer >= to
                 // round_down : highest integer <= to
                 // round_ni : closest  integer; i+0.5 => i+1
                 // round_ni_inf : closest  integer; i+0.5 => i

                 // you can use Iconv if you accept a rudimentary
                 // convertion with machine-dependance results (the only
                 // waranty is that |r-i| < 1.0; if you have precise
                 // requirement use others

extern Fonc_Num Iconv(Fonc_Num f);   
extern Fonc_Num round_up(Fonc_Num f);   
extern Fonc_Num round_down(Fonc_Num f);   
extern Fonc_Num round_ni(Fonc_Num f);   
extern Fonc_Num round_ni_inf(Fonc_Num f);   
extern Fonc_Num signed_frac(Fonc_Num f);   
extern Fonc_Num ecart_frac(Fonc_Num f);   
          

     // integer  

extern   Fonc_Num operator ! (Fonc_Num);
extern   Fonc_Num operator ~ (Fonc_Num);


    /*  -  -  -  -  -  -  -  -  -  -  */
    /*            COMPLEX             */
    /*  -  -  -  -  -  -  -  -  -  -  */

         // binary 

Fonc_Num mulc(Fonc_Num f1,Fonc_Num f2);  // multiplication
extern   Fonc_Num divc(Fonc_Num,Fonc_Num);   // 1/f

         // unary 

extern   Fonc_Num squarec(Fonc_Num);      // f * f
extern   Fonc_Num squarec_divN(Fonc_Num);      // f * f / |f|
extern   Fonc_Num polar(Fonc_Num);       // x,y => rho, teta
// Implementee  a partir d'Elise
extern    Fonc_Num  Hypot(Fonc_Num Fx,Fonc_Num Fy);
extern    Fonc_Num  Hypot(Fonc_Num Fxyz);  // Autant de dim qu'on veut
extern    Fonc_Num TronkUC(Fonc_Num);  // Tronque 0 - 256
extern    Fonc_Num Scal(Fonc_Num F1,Fonc_Num F2);
         //  specifies the value of teta when x,y = 0
extern   Fonc_Num polar(Fonc_Num,REAL rh0); 
extern   Fonc_Num divc(Fonc_Num);   // 1/f


    /*  -  -  -  -  -  -  -  -  -  -  -  -  -  - */
    /*  N-DIMENBTIONALL OPERATOR                 */
    /*  -  -  -  -  -  -  -  -  -  - -  -  -  -  */

         //  UNARY

Fonc_Num diag_m2_sym(Fonc_Num f);



    /*  -  -  -  -  -  -  -  -  -  -  -  -  -  - */
    /*  COMPOSITION/ CHANG OF COORDINATE         */
    /*  -  -  -  -  -  -  -  -  -  - -  -  -  -  */


// Fonc_Num operator [] (Fonc_Num);  => member function of class Fonc_Num

        // translation 

extern Fonc_Num trans(Fonc_Num,const INT*,INT);
extern Fonc_Num trans(Fonc_Num,Pt2di);
extern Fonc_Num trans(Fonc_Num,Pt3di);
extern Fonc_Num trans(Fonc_Num,INT);


    /*  -  -  -  -  -  -  -  -  -  -  -  -  -  - */
    /*  SPECIAL PURPOSE - AD HOC operator        */
    /*  -  -  -  -  -  -  -  -  -  - -  -  -  -  */



    /*----------------------------------------*/
    /*                                        */
    /*          Output                        */
    /*                                        */
    /*----------------------------------------*/


         // operator on output

#ifndef NoOperatorVirgule
extern   Output operator , (Output,Output);
#endif
extern   Output Virgule(Output,Output);
extern   Output Virgule(Output,Output,Output);
extern   Output Virgule(Output,Output,Output,Output);
extern   Output Virgule(Output,Output,Output,Output,Output);
extern   Output Virgule(Output,Output,Output,Output,Output,Output);

extern   Output operator | (Output,Output);

         // operator mixing output and function

extern   Output operator << (Output,Fonc_Num);

extern Output Filtre_Out_RedBin   (Output anOut);
extern Output Filtre_Out_RedBin_X (Output anOut);
extern Output Filtre_Out_RedBin_Y (Output anOut);
extern Output Filtre_Out_RedBin_Gen(Output anOut,bool aRedX,bool aRedY);

         //  REDUCTION 



template <class Type>    Output  reduc(const OperAssocMixte &,Type &);
template <class Type>    Output  reduc(const OperAssocMixte &,Type *,INT nb);

//  The sigma function is just a syntactic shugar that is rewriten as follow :
//     sigma(v) ==> reduc(OpSum,v)
// 

template <class Type>    Output  sigma(Type &);
template <class Type>    Output  sigma(Type *,INT nb);

template <class Type>    Output  VMax(Type &);
template <class Type>    Output  VMax(Type *,INT nb);

template <class Type>    Output  VMin(Type &);
template <class Type>    Output  VMin(Type *,INT nb);


template <class Type>    Output  WhichMax(Type &);
template <class Type>    Output  WhichMax(Type *,INT nb);

template <class Type>    Output  WhichMin(Type &);
template <class Type>    Output  WhichMin(Type *,INT nb);


    /*----------------------------------------*/
    /*                                        */
    /*      Neighbooring relations            */
    /*                                        */
    /*----------------------------------------*/

template <class Type,class TyBase> class Im2D;




         // 

Neigh_Rel sel_func(Neigh_Rel,Fonc_Num);
Neigh_Rel sel_flag(Neigh_Rel n,Fonc_Num f);


        //  operaror with Flux of point

          //  see upper : extern Flux_Pts dilate(Flux_Pts flx,Neigh_Rel fonc); 
          //  see upper : extern Flux_Pts conc(Flux_Pts flx,Neigh_Rel fonc); 


    /*----------------------------------------*/
    /*                                        */
    /*          Operator (arithmetic)         */
    /*                                        */
    /*----------------------------------------*/

extern const OperAssocMixte & OpSum;
extern const OperAssocMixte & OpMax;
extern const OperAssocMixte & OpMin;
extern const OperAssocMixte & OpMul;

    /*----------------------------------------*/
    /*                                        */
    /*          Symb_FNum                     */
    /*                                        */
    /*----------------------------------------*/


    /*----------------------------------------*/
    /*                                        */
    /*          top level                     */
    /*                                        */
    /*----------------------------------------*/

extern bool DebugCopy;
extern bool DebugInProj;

void ElCopy(Flux_Pts,Fonc_Num,Output,INT,const char *);
#define  ELISE_COPY(a,b,c) ElCopy((a),(b),(c),__LINE__,__FILE__)

    /*----------------------------------------*/
    /*                                        */
    /*          Rectang_Object                 */
    /* (== window, bitmaps, file image ...)   */
    /*                                        */
    /*----------------------------------------*/








/*
    Voir aussi (liste totalement non exhaustive) :


    BoxedConc  : Pour analyser des conpmosantes connexe incluse dans une boxe

    fonc_a_trou : definir explicitement des valeurs en des points particuliers

    gauss_noise_4 unif_noise_4  ....
        
*/




#endif  /* !_ELISE_ABSTRACT_TYPE_H */

