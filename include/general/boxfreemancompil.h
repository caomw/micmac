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


#ifndef _ELISE_GENERAL_UTIL_BOXFREEMANCOMPIL_H
#define _ELISE_GENERAL_UTIL_BOXFREEMANCOMPIL_H



/*
      Ce qui suit n'est surement pas du tout dans le style Objet.
    Comme c'est plutot complique, j'importe le + directement  possible
    de clisp (en evitant surtout d'avoir a comprendre comment ca marche).

      De toute facon c'est totalement encapsule.
*/

template <class Type> class BoxFreemanCompil
{
    public :
 
       enum {ElBIDON = -1000000000};

       enum
       {
             intER_TOUJ,      /* un en 8 ou 0-4 ou 2-6 */
                              /* positions, sans jamais d'intersection */
             CFF_00,
             CFF_11,
             CFF_13,
             CFF_01,
                              /* positions, avec parfois des intersection */
             CFF_02,
             CFF_03,
             CFF_15
       };

       int TAB_CONF_CPLE_FREEM[9][9];
       int TAB_IND_QX[9][9];  /* tableau des indices x des "Q-Vois" dans Freem */
       int TAB_IND_QY[9][9];  /* tableau des indices y des "Q-Vois" dans Freem */
       int TAB_IND_Q2X[9][9];  /* idem, quand y'a deux points */
       int TAB_IND_Q2Y[9][9];  /* idem, quand y'a deux points */
       int TAB_TRIGO_CF[8][8];

       BoxFreemanCompil(int);

       void symetrise_tab_cfr(int tab [][9]);
       void init_tab_cfr(int tab [][9]);

       double_t  D2BoxSeg(const Box2d<Type> & b,const SegComp & s);

       inline Pt2dr PQ1(const Box2d<Type> & b,int c1,int c2)
       {
             return Pt2dr
                    (  
                        b.x(TAB_IND_QX[c1][c2]),
                        b.y(TAB_IND_QY[c1][c2])
                    );
       }
       inline Pt2dr  PQ2(const Box2d<Type> & b,int c1,int c2)
       {
             return Pt2dr
                    (  
                        b.x(TAB_IND_Q2X[c1][c2]),
                        b.y(TAB_IND_Q2Y[c1][c2])
                    );
       }
       static BoxFreemanCompil<Type>  TheBFC;
};


template <> BoxFreemanCompil<int> BoxFreemanCompil<int>::TheBFC(4);
template <> BoxFreemanCompil<double_t> BoxFreemanCompil<double_t>::TheBFC(4);
template <> BoxFreemanCompil<long double> BoxFreemanCompil<long double>::TheBFC(4);

//template <> BoxFreemanCompil<int> BoxFreemanCompil<int>::TheBFC=BoxFreemanCompil<int>();
//template <> BoxFreemanCompil<double_t> BoxFreemanCompil<double_t>::TheBFC=BoxFreemanCompil<double_t>();



#endif
