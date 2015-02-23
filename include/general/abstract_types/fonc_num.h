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


#ifndef _ELISE_GENERAL_ABSTRACT_TYPES_FONC_NUM_H
#define _ELISE_GENERAL_ABSTRACT_TYPES_FONC_NUM_H

#include "general/sys_dep.h"

#include <Pt2d>
#include <PRC0>

class cElCompileFN;
class ElGrowingSetInd;

class Fonc_Num : public  PRC0
{
   friend class Arg_FNOPB;

   public :
     REAL ValFoncGen(Pt2di) const;  
     REAL ValFoncGenR(Pt2dr) const;  
          // valable qqsoit la fonction, assez long
         // REAL ValFonc(const class PtsKD &) const; pour les fonction analytique

     std::string NameCpp();
     bool        HasNameCpp();
     void        SetNameCpp(const std::string &);

     ~Fonc_Num();
     Fonc_Num(INT);
     Fonc_Num(INT,INT);
     Fonc_Num(Pt2di);
     Fonc_Num(INT,INT,INT);
     Fonc_Num(INT,INT,INT,INT);
     Fonc_Num(REAL);
     Fonc_Num(REAL,REAL);
     Fonc_Num(Pt2dr);
     Fonc_Num(REAL,REAL,REAL);
     Fonc_Num(REAL,REAL,REAL,REAL);
     Fonc_Num(class Fonc_Num_Not_Comp *);

     void compile(cElCompileFN &);
     bool integral_fonc (bool integral_flux) const ;
     INT dimf_out() const;
     REAL ValFonc(const class PtsKD &) const;
     Fonc_Num deriv(INT kth) const;
     Fonc_Num deriv(class cVarSpec ) const;
     INT DegrePoly() const; // retourne  conventionnellement -1 si pas polynome

     void VarDerNN(ElGrowingSetInd &) const; // Remplit l'indexe des variable a derivee non nulle
	 REAL ValDeriv(const  PtsKD &  pts,INT k) const;
	 INT  NumCoord() const; // En qq sorte la fonc inverse de kth_coord, 
	                        // => Erreur si pas une fonc coord
     void show(std::ostream & os) const;
     bool is0() const;
     bool is1() const;
     bool IsCsteRealDim1(REAL & aVal) const;
     bool IsCsteRealDim1(INT  & aVal) const;

     Fonc_Num operator [] (Fonc_Num);
     
     Fonc_Num v0();     // = kth_proj(*this,0);
     Fonc_Num v1();     // = kth_proj(*this,1);
     Fonc_Num v2();     // = kth_proj(*this,2);

     Fonc_Num permut(const std::vector<int>&  kth) const;
     Fonc_Num kth_proj(INT kth) const;
     Fonc_Num shift_coord(int shift) const;


     class Fonc_Num_Computed * compute (const class  Arg_Fonc_Num_Comp &);

     Fonc_Num();

  //  private :

     static const Fonc_Num No_Fonc; // used as defualt values for some foncs,
                                    // really point to 0 !
     bool really_a_fonc() const;  // does it point to non 0


   //  Permet de comparer formellement deux expression formelle 
   //  utilise pour gerer des dictionnaire d'expression
   

       typedef enum {
                   eIsICste,
                   eIsRCste,
                   eIsFCoord,
                   eIsOpBin,
                   eIsOpUn,
                   eIsVarSpec,
		   eIsSurfIER,
                   eIsUnknown
                }  tKindOfExpr;

       INT CmpFormel(const Fonc_Num &) const;
       tKindOfExpr KindOfExpr() const;
       bool IsVarSpec() const;
       bool IsAtom() const;
       bool IsOpbin() const;
       bool IsOpUn() const;


   protected :
     class cTagCsteDer {};
     Fonc_Num (cTagCsteDer,REAL aVal,INT anInd,const std::string & );
};

#endif
