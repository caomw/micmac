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
    As I do not know standards for manipulating "Images" of
   dimention "1,2,3,..." (== array), we define a simple format.
*/

//    Elis_File_Im is actually a smart pointer to Data_Elis_File_Im 
//  that realy contain  the information.

#ifndef _ELISE_FILEIM_H  // general
#define _ELISE_FILEIM_H

#include <general/bitm.h>


class ElDataGenFileIm;
class Data_GifIm;


template <class Type>  Im2D<Type,typename El_CTypeTraits<Type>::tBase> LoadFileIm(ElGenFileIm,Type * = 0);

class Elise_Tiled_File_Im_2D;
class Data_Elise_File_Im;





/*************************************************************/
/*************************************************************/
/*************************************************************/
/*************************************************************/

class Video_Win;
class Video_Display;
class Disc_Pal;
class Elise_colour;

void test_gif(char  * name, Video_Win, Video_Display);


typedef ElList<Gif_Im> L_Gif_Im;






/*************************************************************/
/*************************************************************/
/*************************************************************/
/*************************************************************/





/*************************************************************/
/*************************************************************/
/*************************************************************/
/*************************************************************/


extern void test_ps();


void MakeFileThomVide
(
        const std::string & aNameVide,
        const std::string& aNamePlein
        );

Im2D_Bits<1> MasqImThom
(
        const std::string & aNameThom,
        const std::string & aNameFileXML,
        Box2di &
        );

void ThomCorrigeCourrantObscur(Im2D_U_int2,const Box2di&);

#endif  //  _ELISE_FILEIM_H
