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



/*
    This file contains the macro and type definitions necessary
    for portability.
*/

#ifndef _ELISE_SYS_DEP_H
#define _ELISE_SYS_DEP_H

#include <cmath>
#include <cfloat>
#include <cstdint>

#include "GpGpu/GpGpu_BuildOptions.h"

#ifndef NO_X11
	#ifndef ELISE_X11
		#define ELISE_X11  (ELISE_unix | ELISE_MacOs)
	#endif 
#endif

#define ELISE_NO_VIDEO  (! ELISE_X11)

#define ElUseNameSpace      1

#if ELISE_unix
	#define SYS_MV "mv"
	#define SYS_RM "\\rm"   // MODID MPD CAR rm ne fonctionne pas si il a ete redefini par alias !!
	#define SYS_CP "cp"
	#define SYS_CAT "cat"
	#define ELISE_CAR_DIR  '/' 
	#define ELISE_Current_DIR  "./"
    #define ELISE_STR_DIR "/"
	// the character separating directories in PATH environment variable
    #define ELISE_CAR_ENV ':'
#endif

#if ELISE_MacOs
	#define SYS_MV "mv"
	#define SYS_RM "rm"
	#define SYS_CP "cp"
	#define SYS_CAT "cat"
	#define ELISE_CAR_DIR  '/' 
	#define ELISE_Current_DIR  "./"
    #define ELISE_STR_DIR "/"
    #define ELISE_CAR_ENV ':'
#endif

#if ELISE_windows
	#define SYS_MV "move"
	#define SYS_RM "del"
	#define SYS_CP "copy"
	#define SYS_CAT "type"
	#define ELISE_CAR_DIR  '/' 
	#define ELISE_Current_DIR  "./"

    #define ELISE_STR_DIR "/"
	// the character separating directories in PATH environment variable
    #define ELISE_CAR_ENV ';'
    #define isinf(x) (!_finite(x))
#endif

template <class Type> bool BadNumber(const Type & aVal) {return (std::isnan(aVal)||std::isinf(aVal));}

#define std_unique_ptr std::unique_ptr
#define NULLPTR nullptr
#define CPPX11
#ifndef __CUDACC__
	#define    NOCUDA_X11
#endif

#define ElTemplateInstantiation 1

#if (SUN_WS5)
	#define ElMemberTpl 0
#else
	#define ElMemberTpl 1
#endif


/*******************************************/
/*  [1]                                    */
/*  Definition of portable numerical types */
/*                                         */
/*******************************************/

#define U_INT  unsigned int
#define U_INT4 unsigned  int
#define INT    int
#define INT4   int
#define U_INT8 unsigned long long int
#define _INT8   long long int // INT8 is already defined by windows.h and means "char"
#define U_INT2 unsigned short
#define INT2   signed short
#define U_INT1 unsigned char
#define INT1   signed char

#define REAL    double
#define REAL4   float
#define REAL8   double
#define REAL16  long double

#define INTByte8  long long int


extern int TheIntFuckingReturnValue;
extern char * TheCharPtrFuckingReturnValue;
int trace_system( const char *cmd );		 // print cmd and execute ::system (helps with debugging)
extern int (*system_call)( const char*cmd ); // equals ::system unless __TRACE_SYSTEM__ is defined (see all.cpp)
#if (!ELISE_windows)
// same thing as system but with popen
//FILE * trace_popen( const char *cmd, const char *acces );
//extern FILE * (*popen_call)( const char *cmd, const char *acces );
#endif

#define  VoidFscanf TheIntFuckingReturnValue=::fscanf
#define  VoidScanf TheIntFuckingReturnValue=::scanf
#define  VoidSystem TheIntFuckingReturnValue=::system_call
#define  VoidFgets TheCharPtrFuckingReturnValue=::fgets


typedef const INT * const *  Const_INT_PP ;
typedef const REAL * const *  Const_REAL_PP ;

extern bool MSBF_PROCESSOR();


#if (ELISE_windows)
#define ElIsBlank ISBLANK
#else
#define ElIsBlank isblank
#endif

typedef REAL8  tSysCho ;

#endif /* ! _ELISE_SYS_DEP_H */
