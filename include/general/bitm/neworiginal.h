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





inline int AdjUC(int aV)
{
   return El_CTypeTraits<U_INT1>::Tronque(aV);
}
inline int AdjUC(double aV)
{
   return El_CTypeTraits<U_INT1>::Tronque(round_ni(aV));
}















std::string type_elToString( GenIm::type_el );

template <class Type,class TyBase> class Im1D;



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


typedef Im2D<U_INT1,INT>  Im2D_U_INT1;
typedef Im2D<INT1,INT>    Im2D_INT1;
typedef Im2D<U_INT2,INT>  Im2D_U_INT2;
typedef Im2D<INT2,INT>    Im2D_INT2;
typedef Im2D<INT4,INT>    Im2D_INT4;

typedef Im2D<REAL4,REAL>  Im2D_REAL4;
typedef Im2D<REAL8,REAL>  Im2D_REAL8;
typedef Im2D<REAL16,REAL16> Im2D_REAL16;




typedef Im2D_Bits<1>	  Im2D_BIN;




Im2D_Bits<1> ReducCentered(Im2D_Bits<1>);
Im2D_Bits<1> MasqForInterpole(Im2D_Bits<1> aMasqInInit,eModeInterp aMode);



GenIm alloc_im1d(GenIm::type_el type_el,int tx,void * data);


typedef Im1D<U_INT1,INT>  Im1D_U_INT1;
typedef Im1D<INT1,INT>    Im1D_INT1;
typedef Im1D<U_INT2,INT>  Im1D_U_INT2;
typedef Im1D<INT2,INT>    Im1D_INT2;
typedef Im1D<INT4,INT>    Im1D_INT4;

typedef Im1D<REAL4,REAL>  Im1D_REAL4;
typedef Im1D<REAL8,REAL>  Im1D_REAL8;

class Im3D_WithDataLin{};

typedef Im3D<U_INT1,INT>  Im3D_U_INT1;
typedef Im3D<INT1,INT>    Im3D_INT1;
typedef Im3D<U_INT2,INT>  Im3D_U_INT2;
typedef Im3D<INT2,INT>    Im3D_INT2;
typedef Im3D<INT4,INT>    Im3D_INT4;

typedef Im3D<REAL4,REAL>  Im3D_REAL4;
typedef Im3D<REAL8,REAL>  Im3D_REAL8;

class Data_Liste_Pts_Gen;


template <class Type,class Type_Base> class Data_Liste_Pts;



typedef Liste_Pts<U_INT1,INT>    Liste_Pts_U_INT1;
typedef Liste_Pts<INT1,INT>      Liste_Pts_INT1;
typedef Liste_Pts<U_INT2,INT>    Liste_Pts_U_INT2;
typedef Liste_Pts<INT2,INT>      Liste_Pts_INT2;
typedef Liste_Pts<INT4,INT>      Liste_Pts_INT4;


typedef Liste_Pts<REAL4,REAL>      Liste_Pts_REAL4;
typedef Liste_Pts<REAL8,REAL>      Liste_Pts_REAL8;

extern Im1D_INT4  hongrois(Im2D_INT4 cost);

void ALGOHONGR(Im2D_INT4,Im1D_INT4);


extern void deriche_uc
     (
           Im2D_REAL4  gx,
           Im2D_REAL4  gy,
           Im2D_U_INT1 i,
           REAL4       alpha
     );




extern GenIm alloc_im1d(GenIm::type_el type_el,int tx,void * data = 0);
extern GenIm alloc_im2d(GenIm::type_el type_el,int tx,int ty);
extern GenIm alloc_im2d(GenIm::type_el type_el,int tx,int ty, void * DataLin);


extern Im2DGen D2alloc_im2d(GenIm::type_el type_el,int tx,int ty);
// La copie d'une Im2DGen perd la virtualite, d'ou ....
extern Im2DGen * Ptr_D2alloc_im2d(GenIm::type_el type_el,int tx,int ty);

extern bool  type_im_integral(GenIm::type_el type_el);

extern INT nbb_type_num(GenIm::type_el type_el);     // nb byte
extern bool msbf_type_num(GenIm::type_el type_el);   // is most signif first
extern bool signed_type_num(GenIm::type_el type_el); // is it signed int
extern GenIm::type_el type_u_int_of_nbb(INT nbb,bool msbf = true);

extern  GenIm::type_el type_im(bool intregral,INT nbb,bool Signed,bool msbf);
extern  GenIm::type_el type_im(const std::string &);

extern std::string eToString(const GenIm::type_el &);

extern std::string NamePlyOfType(GenIm::type_el);


extern void min_max_type_num(GenIm::type_el,INT & v_min,INT &v_max);
extern int  VCentrale_type_num(GenIm::type_el);

Fonc_Num Tronque(GenIm::type_el,Fonc_Num);


extern GenIm::type_el  type_of_ptr(const U_INT1 * );
extern GenIm::type_el  type_of_ptr(const INT1   * );
extern GenIm::type_el  type_of_ptr(const U_INT2 * );
extern GenIm::type_el  type_of_ptr(const INT2   * );
extern GenIm::type_el  type_of_ptr(const INT4   * );
extern GenIm::type_el  type_of_ptr(const REAL4  * );
extern GenIm::type_el  type_of_ptr(const REAL8  * );
extern GenIm::type_el  type_of_ptr(const REAL16  * );


template <class Type>  ElMatrix<Type> gaussj(const ElMatrix<Type>  & m);
template <class Type>  void self_gaussj(ElMatrix<Type>  & m);
template <class Type>  bool self_gaussj_svp(ElMatrix<Type>  & m);

// Renvoie la liste des indices croissants de valeurs propres

std::vector<int> jacobi(const ElMatrix<REAL>& aMatSym,ElMatrix<REAL>& aValP,
            ElMatrix<REAL>& aVecP);
std::vector<int> jacobi_diag(const ElMatrix<REAL>& aMatSym,ElMatrix<REAL>& aValP,
                 ElMatrix<REAL>& aVecP);


std::vector<int> jacobi(const ElMatrix<REAL16>& aMatSym,ElMatrix<REAL16>& aValP,
            ElMatrix<REAL16>& aVecP);
std::vector<int> jacobi_diag(const ElMatrix<REAL16>& aMatSym,ElMatrix<REAL16>& aValP,
                 ElMatrix<REAL16>& aVecP);


void svdcmp ( const ElMatrix<REAL> & aMat, ElMatrix<REAL> & anU,
              ElMatrix<REAL> & aLineDiag, ElMatrix<REAL> & aV,bool direct);
void svdcmp_diag ( const ElMatrix<REAL> & aMat, ElMatrix<REAL> & anU,
              ElMatrix<REAL> & aDiag, ElMatrix<REAL> & aV,bool direct);


// L'"habituelle" decomposition QR,
std::pair<ElMatrix<double>, ElMatrix<double> > QRDecomp(const ElMatrix<double> & aM0);

// La RQ decomposition (sans doute + utile pour l'equation au 12 param)
std::pair<ElMatrix<double>, ElMatrix<double> > RQDecomp(const ElMatrix<double> & aM0);


// Renvoie la rotation la + proche, selon un algo trouve dans Golub et base sur
// la SVD
ElMatrix<REAL>  NearestRotation(const ElMatrix<REAL> &);


//  Probleme de conditionnement
void InspectPbCD(ElMatrix<REAL>);

// Calcule une rotation R tq R Antk = Imk;
//   - algo : norme les vecteur
//            les rend orthogonaux
//            calcul exact



ElMatrix<REAL> ComplemRotation
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





// Suppose les N ligne du haut OK, complete avec les lignes
// du bas pour que forme au mieux une famille de vecteur libre,
// (la moins singuliere possible)
// n'utilise pour ce faire que des vecteur de la base canonique

void ComplBaseParLeHaut(ElMatrix<REAL> &,INT NbLigneOk);

// FONCTION specifiques au M22, M33

ElMatrix<REAL> DiffRotEn1Pt(REAL teta01,REAL teta02,REAL teta12,Pt3dr pt);


typedef TplElRotation3D<REAL> ElRotation3D;

   class cRepereCartesien;


// Chgt de coord cartesien (et non euclidien, ca marche aussi si pas orthornormee)

// La rotation etant exprimee dans un systeme 1, on la transforme en systeme 2:
ElRotation3D  ChangementSysC(const Pt3dr aP,const ElRotation3D&,const cSysCoord & aSource,const cSysCoord & aCible);

double ProfFromCam(const ElRotation3D & anOr,const Pt3dr & aP);  // anOr M->C


void SauvFile(const ElRotation3D &,const std::string &);
void XML_SauvFile(const ElRotation3D &,const std::string &,const std::string & aNameEngl,bool aModeMatr);
void XML_SauvFile(const ElRotation3D &,const std::string &,const std::string & aNameEngl,double altisol,double prof,bool aModeMatr);


ElRotation3D ReadFromFile(const ElRotation3D *,const std::string &);

template <class Type>  class ElPolynome;
//template <class Type>  ElPolynome<Type> operator * (const Type &,const ElPolynome<Type> &) ;







            /***************************************/
            /*                                     */
            /*       FFT-FFT-FFT-FFT               */
            /*                                     */
            /***************************************/

void  ElFFT
      (
          Im2D_REAL8 aReIm,
      Im2D_REAL8 aImIm,
      bool       aDirect
      );

      // Correlation ni normalisee, ni centree
      // images circulaires
      // Remplit la correlation dans Im1
void  ElFFTCorrelCirc
      (
           Im2D_REAL8 aReIm1,
       Im2D_REAL8 aReIm2
      );

     // meme chose  mais images
     // paddee avec suffisament de 0
     // pour ne pas avoir d'effets de bord
Im2D_REAL8   ElFFTCorrelPadded
             (
                  Im2D_REAL8 aReIm1,
                  Im2D_REAL8 aReIm2
             );


     // idem, mais normalisee centree;
     // anEpsilon est utilisee pour les divisions

Im2D_REAL8   ElFFTCorrelNCPadded
             (Im2D_REAL8 aReIm1,Im2D_REAL8 aReIm2,REAL anEps,REAL aSurfMin=-1) ;

           // Quand aSurfMin est >0, et que la surface  S
           // (ou Ponderation pour ElFFTPonderedCorrelNCPadded)
           // est < a aSurfMin , le coeff de correlation C est reetalonne
           // entre -1 et C, proportionellement a S/aSurfMin


      // Avec Ponderation
Im2D_REAL8   ElFFTPonderedCorrelNCPadded
             (
                Fonc_Num   aF1,
                Fonc_Num   aF2,
                Pt2di      aSz,
                Fonc_Num   aPds1,
                Fonc_Num   aPds2,
                REAL       anEps,
                REAL       aSurfMin = -1
             );


/*
 renvoie  si I a ete calculee par ElFFTCorrelPadded
    --
    \
    /    I1(p+aDecIm1) I2(p)
    __
*/

REAL ImCorrFromNrFFT(Im2D_REAL8 anIm,Pt2di aDecIm1);

// Les Images donnees pour effectuer le calcul
// sont des images FFT
Pt2di DecIm2DecFFT(Im2D_REAL8 anImFFT,Pt2di aDecIm1);
Pt2di DecFFT2DecIm(Im2D_REAL8 anImFFT,Pt2di aP);
Pt2d<Fonc_Num> FN_DecFFT2DecIm(Im2D_REAL8 anIm);





/*
   REMPLACE PAR cDbleGrid  dans "general/photogram.h"
*/

void ShowMatr(const char * mes, ElMatrix<REAL> aMatr)  ;


/*******************************************************/
/*                                                     */
/*       NOYAU INTERPOLATEUR 1D                        */
/*                                                     */
/*******************************************************/


/*
    REDEFINITION DES INTERPOLATEURS,  moins optimises mais plus
    generaux;

    cKernelInterpol  : Classe d'interface
    cCubicInterpKernel  : noyau cubique elementaire
    cScaledKernelInterpol : Noyau dilate, a partir d'un noyau existant

*/





// Sinus Cardinal appodise avec fentre de Tukey  = Diriclet au debut
// et cosinus qui assure le raccord derivale en 0






      //========================================






/*
*/








// Variante "pure" de l'interpolateur bicubique, c.a.d
// sans approximation permettant de gagner du temps (genre
// arrondis)


typedef cTplCIKTabul<U_INT1,INT>  cCIKTabul;

void FiltrageImage3D
     (
           INT StepX,INT StepY, INT StepZ,
       double *  Data,
           INT    Tx, INT    Ty, INT    Tz
     );

void NoyauxFiltrageImage3D
     (
           INT StepX,INT StepY, INT StepZ,
       double *  Data,
           INT    Tx, INT    Ty, INT    Tz
     );

Im2D_U_INT1  Shading
             (
                  Pt2di    aSz,
                  Fonc_Num aFMnt,
                  INT      aNbDir,
                  REAL Anisotropie
             );






#endif //   _ELISE_GENERAL_BITM_H_

