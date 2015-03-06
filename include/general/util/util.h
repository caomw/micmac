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

#ifndef _ELISE_UTIL_H
#define _ELISE_UTIL_H

#include <general/sys_dep.h>
#include <general/opt_debug.h>

#include <string>
#include <cstring>
#include <vector>
#include <istream>
#include <sstream>
#include <iostream>
#include <list>
#include <map>

class tFileOffset;

extern const  std::string  TheFileMMDIR;  // MicMacInstalDir
void AnalyseContextCom(int argc,char ** argv);
void MMD_InitArgcArgv(int argc,char ** argv,int aNbArgMin=-1);
int NbProcSys();

extern void mem_raz(void *,tFileOffset);

extern int MemoArgc;
extern char ** MemoArgv;
extern std::string SubstArgcArvGlob(int aKSubst,std::string aSubst);


std::string GetUnikId();
std::string Dir2Write();

void ElExit(int aLine,const char * aFile,int aCode,const std::string & aMessage);
#define ElEXIT(aCode,aMessage) ElExit(__LINE__,__FILE__,aCode,aMessage)
//  Il existe des exit qui n'ont pas besoin d'etres traces, par exemple sur les help
#define StdEXIT(aCode)  exit(aCode)

void AddMessErrContext(const std::string & aMes);

int mm_getpid();

#define MEM_RAZ(x,nb) mem_raz((void *)(x),(nb)*sizeof(*(x)))


void test();
// constantly redefined to perform some test;

extern double Delay_Brkp;
void SleepProcess(double);
#define BRKP \
{\
	std::cout << "BRKP at " << __LINE__ << " of " << __FILE__ << "\n";\
    if (Delay_Brkp>0)\
        getchar();\
}

/*

    This file contains miscellaneous utilitaries
    (class and functions).

*/

const int INDEX_NOT_FOUND = -1;

// FBoolA = "Fuzzy boolean" = boolean + option Fundef (ie undefined)



template <class Type> class Pt2d;


// Pour contourner le warning  [-Werror=unused-but-set-variable] de Gcc 4.6



cDecimal StdRound(const double & aD,int aNbDigit,int * aTabR,int aSizeR);
cDecimal StdRound(const double & aD);


double_t angle_mod_real(double_t a,double_t b);


double_t Pow(double_t,int);
int Pow_of_2_sup(int);
extern bool is_pow_of_2(int );
int NbBitsOfFlag(int aFlag);

double_t El_logDeux(double_t);



template <class Type> void binarise(Type *,Type,int);
template <class Type> void binarise(Type *,const Type *,Type,int);
template <class Type> void neg_binarise(Type *,const Type *,Type,int);


template <class Type> void set_fonc_id(Type *,Type v0,int);

template <class Type> bool values_positive (const Type *t,int nb);
template <class Type> bool values_positive_strict (const Type *t,int nb);




extern void NRrandom3InitOfTime();
extern int  NRrandom3 (int aN);  // 0 <= X < N
extern double_t NRrandom3 ();
extern double_t NRrandC();  // entre -1 et 1
void ResetNRrand();
void rationnal_approx(double_t,int &,int&);



double_t ElTimeOfDay();



void CmpByEnd(const char * aName1,const char * aName2,int & aK1,int &aK2);
bool N2IsEndN1(const char * aName1,const char * aName2);


// Pour avoir un nom utilisable dans les commandes meme s'il
// contient des blancs
std::string ToStrBlkCorr(const std::string &);


std::string StrToLower(const std::string & aStr);
int    IndPostfixed  (const std::string &,char = '.');
std::string StdPostfix(const std::string &,char = '.');
std::string StdPrefix (const std::string &,char = '.');
std::string StdPrefixGen (const std::string &,char = '.');
std::string NameWithoutDir(const std::string &);

std::string ExtractDigit(const std::string & aName,const std::string &  aDef);


bool IsPrefix(const char * aPref,const char *aStr);


std::string ToCommande(int argc,char ** argv);
std::string QUOTE(const std::string & aStr);
void GlobStdAdapt2Crochet(std::string & aStr);



bool SplitIn2ArroundCar
     (
         const std::string  &  a2Stplit,
         char                  aSpliCar,
         std::string  &  aBefore,
         std::string  &  aAfter,
         bool            AcceptNoCar  // Est on OK pour ne pas trouver aSpliCar
                                     // dans ce cas  aAfter est vide
     );

void  SplitInNArroundCar
      (
         const std::string  &  a2Stplit,
         char                  aSpliCar,
         std::string   &             aR0,
         std::vector<std::string>  &  aRAux
      );

void SplitIn2ArroundEq
     (
         const std::string  &  a2Stplit,
         std::string  &  aBefore,
         std::string  &  aAfter
     );

void SplitDirAndFile
     (
           std::string & aNameDir,
           std::string & aNameFile,
           const std::string & aStr
     );



std::vector<char *> ToArgMain(const std::string & aStr);



// Ajoute apres la dir et avant le .
std::string AddPrePost(const std::string & aName,const std::string & aPref,const std::string & aPost);

std::string DirOfFile(const std::string & aStr);

std::string StdWorkdDir(const std::string & aValWD,const std::string & aNameFile);

std::vector<std::string> VecStrFromFile(const std::string &);


bool GetOneModifLC
     (
         int argc,
         char ** argv,
         const std::string & aNameSymb,
         std::string &       aVal
     );

// RAJPOUTE DES /\ si necessaire
void MakeFileDirCompl(std::string &);


bool    IsPostfixed  (const std::string &,char = '.');
bool    IsPostfixedBy  (const std::string &,const std::string &);

bool IsFileDmp(const std::string &);


void EliseBRKP();

template <class Type> std::string ToString(const Type &);
std::string  ToStringNBD(int aNb,int aNbDig);








//typedef long long int tFileOffset;
typedef int64_t tLowLevelFileOffset;
typedef unsigned int  tByte4AbsFileOffset;
// typedef long long  int tLowLevelRelFileOffset;


inline std::ostream & operator << (std::ostream & ofs,const tFileOffset  &anOffs)
{
    ofs << anOffs.BasicLLO();
    return ofs;
}

typedef tFileOffset tRelFileOffset;


// typedef unsigned int tFileOffset;
/*
*/


tFileOffset RelToAbs(tRelFileOffset anOff);


/*****************************************************/
/*                                                   */
/*                  cEquiv1D                      */
/*                                                   */
/*****************************************************/

// Classe pour gerer rapidement les "classe equiv 1D"
// c'est a dire les intervalles classes d'equivalences
// d'une application croissante  de Z dans Z




template<class aType> class cVectTr;


// GPAO : Gestion de Production assistee par ordinateur. C'est
// un peu presenptueux pour l'instant il s'agit juste d'avoir des
// classes permettant de gerer du calcul distribue avec des regles
// gerable par des DAG (directed acyclique graphe)
//
//  cEl_GPAO  est la classe "manager"
//

class cEl_GPAO;
class cEl_Task;

//#include "cElCommand.h"





//  Pour executer une commande en // sur +sieur fichier, pour l'instant on fait
// basique, on ajoutera eventuellement apres des cles avec cInterfChantierNameManipulateur
/*
void MkFMapCmd
     (
          const std::string & aBefore,
          const std::vector<std::string> aSet ,
          const std::string & anAfter
     );
*/

void MkFMapCmdFileCoul8B
     (
          const std::string & aDir,
          const std::vector<std::string > &aSet
     );



//========================================================

class cInterfChantierNameManipulateur;

void RequireBin
     (
         const std::string & ThisBin,  // Le prog appelant pour evt
         const std::string & BinRequired,
     const std::string & LeMake = "Makefile"  // Si
     );

// For top call like Tapas, Malt , .. want to duplicate args in @
int TopSystem(const std::string & aComOri);

int System(const std::string & aCom,bool aSVP=false,bool AddOptGlob=false,bool UseTheNbIterProcess=false);

void  EliseVerifAndParseArgcArgv(int argc,char ** argv);




class cXmlHour;
class cXmlDate;



bool operator < (const cElDate & aD1, const cElDate & aD2);






class cElXMLTree;

extern bool TransFormArgKey
     (
         std::string & aName ,
         bool AMMNoArg,  // Accept mismatch si DirExt vide
         const std::vector<std::string> & aDirExt
     );

// Class sepeciale pour gerer les objets autre que string qui peuvent etre initialise par des #1 #2 ..
// dans les xml pour les cles parametrees, par exemple le <DeltaMin> de <ByAdjacence>


typedef TypeSubst<bool>    BoolSubst;
typedef TypeSubst<int>     IntSubst;
typedef TypeSubst<double>  DoubleSubst;

#if __cplusplus <= 199711L


void GetSubset(std::vector<std::vector<int> > & aRes,int aNb,int aMax);

bool ElGetStrSys( const std::string & i_base_cmd, std::string &o_result );

void BanniereGlobale();

// protect spaces with backslashes (for use with 'make')
std::string protect_spaces( const std::string &i_str );

int MMNbProc();

// lanch the "make" program
// do not include "-j x" flag in i_options, it is handle by i_nbJobs
// i_nbJobs = 0 means "-j" (i.e. infinite jobs, which is not recommanded)
// i_rule can be an empty string, if so, make will launch the makefile's default rule
// returns make's return code
bool launchMake( const std::string &i_makefile, const std::string &i_rule=std::string(), unsigned int i_nbJobs=MMNbProc(), const std::string &i_options=std::string(), bool i_stopCurrentProgramOnFail=true );

#endif /* ! _ELISE_UTIL_H */
