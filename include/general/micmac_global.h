/*Header-MicMac-eLiSe-25/06/2007

    MicMac : Multi Image Correspondances par Methodes Automatiques de Correlation
    eLiSe  : ELements of an Image Software Environnement

    www.micmac.ign.fr


    Copyright : Institut Geographique National
    Author : Marc Pierrot Deseilligny
    Contributors : Gregoire Maillet, Didier Boldo.
    Refactoring: Helio Chissini de Castro <helio@kde.org>

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

#ifndef _ELISE_MICMAC_GLOBAL_H
#define _ELISE_MICMAC_GLOBAL_H

#include <cstdio>
#include <cmath>
#include <iostream>

#include <Fonc_Num>

class Flux_Pts;

template<class Type> class ElMatrix;

// Error assert
extern void elise_fatal_error(const char * mes,const char * file,int line);
#define ELISE_ASSERT(expr,mes) { if (! (expr)) elise_fatal_error(mes,__FILE__,__LINE__); }
#define ASSERT_INTERNAL(expr,mes) ((void) 0)

// ********************************
// round_ni
template <typename t>
int round_ni( t value ) {
    return static_cast<int>(floor( value + 0.5 ));
}

// ********************************
// self_gauss
template <class Type>
void self_gaussj(ElMatrix<Type>  & m);

// ********************************
// mod
int mod(int a,int b)
{
    int r = a%b;
    return (r <0) ? (r+b) : r;
}



// ********************************
// random
void NRrandom3InitOfTime();
int  NRrandom3 (int aN);  // 0 <= X < N
double_t NRrandom3 ();
double_t NRrandC();  // entre -1 et 1
void ResetNRrand();
void rationnal_approx(double_t, int &, int&);

// ********************************
// Copy ?
void ElCopy(Flux_Pts, Fonc_Num, Output, int, const char *);
#define  ELISE_COPY(a,b,c) ElCopy((a),(b),(c),__LINE__,__FILE__)

// ********************************
// externs ??
extern bool TestPermutVar;
extern bool ShowPermutVar;
extern bool ShowCholesky;

// ********************************
// defines
typedef const int * const *  Const_INT_PP;
typedef const float * const *  Const_REAL_PP;

#define Elise_Std_Max_Dim 20


// unary mixte  operators

extern   Fonc_Num operator -(Fonc_Num);
extern   Fonc_Num Abs(Fonc_Num);
extern   Fonc_Num Square(Fonc_Num);
extern   Fonc_Num Cube(Fonc_Num);
Fonc_Num PowI(Fonc_Num f,int aDegre);

extern   double_t Square(double);

#endif
