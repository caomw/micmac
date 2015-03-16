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


#ifndef _ELISE_GENERAL_PTXD_PT2D_H
#define _ELISE_GENERAL_PTXD_PT2D_H

#include <cmath>

#include <ElStdTypeScal>
#include <TCompl>
#include <Output>
#include <TypeSubst>

template <class Type> class Pt2d : public  ElStdTypeScal<Type>
{
public :

    //typedef typename TCompl<Type>::TypeCompl  tCompl;
    typedef Pt2d<double>  TypeReel;
    typedef Type        TypeScal;
    typedef Pt2d<Type>  TypeEff;
    static Pt2d  El0 () {return Pt2d(0,0);}

    typedef Pt2d<typename ElStdTypeScal<Type>::TypeVarProvReel> TypeProvPtScalR;

    typedef Type (& t2)[2] ;
    Type   x;
    Type   y;


    // Constructeur

    Pt2d<Type>()  : x (0), y (0) {}
    Pt2d<Type>(Type X,Type Y) : x (X), y (Y) {}

    Pt2d<Type>(const Pt2d<Type>& p) : x (p.x), y (p.y) {}
//    explicit Pt2d<Type>(const Pt2d<TCompl>& p) :
//        x( TCompl<Type>::FromC( p.x)),
//        y( TCompl<Type>::FromC( p.y))
//    {
//    }

    static  Pt2d<Type> IP2ToThisT(const Pt2d<int> & aP){return Pt2d<Type>(Type(aP.x),Type(aP.y));}
    static  Pt2d<Type> RP2ToThisT(const Pt2d<double> & aP){return Pt2d<Type>(Type(aP.x),Type(aP.y));}
    static  Pt2d<Type> FP2ToThisT(const Pt2d<float> & aP){return Pt2d<Type>(Type(aP.x),Type(aP.y));}

    /*

     Pt2d<Type>(const Pt2d<int>& p) : x (p.x), y (p.y) {};
     Pt2d<Type>(const Pt2d<double>& p): x (Pt2d<Type>::RtoT(p.x)), y (Pt2d<Type>::RtoT(p.y)) {};
*/


    static  Pt2d<Type>  FromPolar(double rho,double teta)
    {
        return   Pt2d<Type>(ElStdTypeScal<Type>::RtoT(std::cos(teta)*rho),ElStdTypeScal<Type>::RtoT(std::sin(teta)*rho));
    }

    static Pt2d<double> polar(const Pt2d<double> & p,double AngDef);

    // Operateurs

    // unaires,  Pt => Pt

    TypeProvPtScalR  ToPtProvR() const
    {
        return TypeProvPtScalR (this->T2R(x),this->T2R(y));
    }

    Pt2d<Type> operator - () const { return Pt2d<Type>(-x,-y); }
    Pt2d<Type> yx() const { return Pt2d(y,x);}
    Pt2d<Type> conj() const { return Pt2d(x,-y);}
    Pt2d<typename ElStdTypeScal<Type>::TypeScalReel> inv() const
    {
        typename ElStdTypeScal<Type>::TypeVarProvReel  n= this->T2R(x)*x+y*y;
        return Pt2d<typename ElStdTypeScal<Type>::TypeScalReel>(x/n,-y/n);
    };
    Pt2d<Type> Square() const;
    Type XtY() const {return x * y;}


    // binaires,  PtxPt => Pt

    Pt2d<Type> operator + (const Pt2d<Type> & p2) const
    {return Pt2d<Type>(x+p2.x,y+p2.y);}
    Pt2d<Type> operator * (const Pt2d<Type> & p2) const
    {return Pt2d<Type>(x*p2.x-y*p2.y,x*p2.y+y*p2.x);}

    // TCompl
    Pt2d<Type> operator / (const Pt2d<Type> & p2) const
    {
        TypeProvPtScalR aRes = this->ToPtProvR() * p2.inv().ToPtProvR();
        return Pt2d<Type> ((Type)aRes.x,(Type)aRes.y);
    }

    Pt2d<Type> operator - (const Pt2d<Type> & p2) const
    {return Pt2d<Type>(x-p2.x,y-p2.y);}
    Pt2d<Type> mcbyc(const Pt2d<Type> & p2) const
    {return Pt2d(x*p2.x,y*p2.y);}
    Pt2d<Type> dcbyc(const Pt2d<Type> & p2) const
    {return Pt2d(x/p2.x,y/p2.y);}


    void SetSup(const Pt2d<Type> & p){std::max(x,p.x); std::max(y,p.y);}
    void SetInf(const Pt2d<Type> & p){std::min(x,p.x); std::min(y,p.y);}

    // RatioMin :  return Min ( x/(TypeScalReel)p.x, y/(TypeScalReel)p.y);
    typename Pt2d<Type>::TypeScalReel RatioMin(const Pt2d<Type> & p) const;

    // binnaire, affectation composee

    Pt2d<Type> & operator += (const Pt2d<Type> & p2)
    { x += p2.x; y += p2.y; return * this;}
    Pt2d<Type> & operator -= (const Pt2d<Type> & p2)
    { x -= p2.x; y -= p2.y; return * this;}

    Pt2d<Type>  &  operator = (const Pt2d<Type> & p2)
    {
        x = p2.x;
        y = p2.y;
        return * this;
    }

    // binaire,  PtxPt => bool
    typename ElStdTypeScal<Type>::TypeBool  operator == (const Pt2d<Type> & p2) const {return (x==p2.x) && (y==p2.y);}
    typename ElStdTypeScal<Type>::TypeBool  operator != (const Pt2d<Type> & p2) const {return (x!=p2.x) || (y!=p2.y);}
    // p1 < p2 , utile par ex ds les map<Pt2di,Machin>
    typename ElStdTypeScal<Type>::TypeBool  operator <  (const Pt2d<Type> & p2) const {return (x<p2.x) || ((x==p2.x)&&(y<p2.y));}

    typename ElStdTypeScal<Type>::TypeBool   xety_inf_ou_egal (const Pt2d<Type> & p2) const
    {return (x<=p2.x) && (y<=p2.y);}

    // binaires,  PtxScalaire => Pt

    Pt2d<Type> operator * (int  lambda) const { return Pt2d<Type>(x*lambda,y*lambda);}


    Pt2d<typename ElStdTypeScal<Type>::TypeScalReel> operator * (double lambda) const { return Pt2d<typename ElStdTypeScal<Type>::TypeScalReel>(x*lambda,y*lambda);}

    Pt2d<Type> operator / (int  lambda) const { return Pt2d<Type>(x/lambda,y/lambda);}
    Pt2d<typename ElStdTypeScal<Type>::TypeScalReel> operator / (double lambda) const { return Pt2d<typename ElStdTypeScal<Type>::TypeScalReel>(x/lambda,y/lambda);}


    // operator * est deja surcharge
    Pt2d<Type> mul (const Type & aL) const { return Pt2d<Type>(x*aL,y*aL);}


    // binaires,  PtxPt => scalaire

    Type  operator ^ (const Pt2d<Type> & p2) const{return x*p2.y-y*p2.x;}


    // lies a une distance
    //friend Type  dist4(const Pt2d<Type> & p){return ElAbs(p.x)+  ElAbs(p.y);}
    //friend Type  dist8(const Pt2d<Type> & p){return ElMax(ElAbs(p.x),ElAbs(p.y));}

    typename ElStdTypeScal<Type>::TypeBool in_box(const Pt2d<Type> & p0, const Pt2d<Type> & p1)
    {
        return (x>=p0.x)&&(y>=p0.y)&&(x< p1.x)&&(y<p1.y);
    }

    //friend void pt_set_min_max<>(Pt2d<Type> & p0,Pt2d<Type> & p1);

    // tertiaire

    // in_sect_angulaire :  est que le pt est dans le secteur partant de p1
    // et defini par un parcourt trigo jusqu'a p2
    bool in_sect_angulaire(const Pt2d<Type> & p1,const Pt2d<Type> & p2) const;

    // Ceux-ci n'ont aucun interet a etre iniline


    void to_tab(Type (& t)[2] ) const;
    static Pt2d<Type> FromTab(const Type *);
    static Pt2d<Type> FromTab(const std::vector<Type> &);
    Output sigma();
    Output VMax();
    Output VMin();
    Output WhichMax();
    Output WhichMin();


private :
    void Verif_adr_xy();

};

typedef Pt2d<int> Pt2di;
typedef Pt2d<double> Pt2dr;
typedef Pt2d<long double> Pt2dlr;

typedef TypeSubst<Pt2di>   Pt2diSubst;
typedef TypeSubst<Pt2dr>   Pt2drSubst;

#endif
