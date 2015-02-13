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

#include "StdAfx.h"
#include <algorithm>



#define DEF_OFSET -12349876


int Impainting_main(int argc,char ** argv)
{
    std::string aNameIn;
    std::string aNameMasqOK;
    std::string aNameMasq2FIll;
    std::string aNameOut;


    ElInitArgMain
    (
    argc,argv,
    LArgMain()  << EAMC(aNameIn,"Name of Input image", eSAM_IsExistFile)
                    << EAMC(aNameMasqOK,"Name Of Ok Masq (0 value means OK)", eSAM_IsExistFile),
    LArgMain()  << EAM(aNameOut,"Out",true,"Name of Result", eSAM_NoInit)
                    << EAM(aNameMasq2FIll,"2Fill", true, "Masq of point 2 fill, def = all", eSAM_NoInit)
    );

    if (!MMVisualMode)
    {
        Tiff_Im aFileIm = Tiff_Im::UnivConvStd(aNameIn.c_str());
        Pt2di aSzIm = aFileIm.sz();
        int aNBC = aFileIm.nb_chan();

        std::vector<Im2D_REAL4> aVIm;
        Output anOut = Output::onul(0);
        for (int aK=0 ; aK<aNBC ; aK++)
        {
            Im2D_REAL4  anIm(aSzIm.x,aSzIm.y);
            aVIm.push_back(anIm);
            anOut = (aK==0) ? anIm.out() : Virgule(anOut,anIm.out());
        }
        ELISE_COPY(aFileIm.all_pts(),aFileIm.in(),anOut);


        Tiff_Im aFileMasq(aNameMasqOK.c_str());
        Im2D_Bits<1> aMasq(aSzIm.x,aSzIm.y,1);
        ELISE_COPY(aFileMasq.all_pts(),!aFileMasq.in_bool(),aMasq.out());


        Im2D_Bits<1> aMasq2Fill(aSzIm.x,aSzIm.y,1);
        if (EAMIsInit(&aNameMasq2FIll))
        {
            Tiff_Im aFileMasq(aNameMasq2FIll.c_str());
            ELISE_COPY(aFileMasq.all_pts(),!aFileMasq.in_bool(),aMasq2Fill.out());
        }


        Fonc_Num aFRes=0;
        for (int aK=0 ; aK<aNBC ; aK++)
        {
            aVIm[aK] = ImpaintL2(aMasq,aMasq2Fill,aVIm[aK]);
            aFRes = (aK==0) ? aVIm[aK].in() : Virgule(aFRes,aVIm[aK].in());
        }

        if (!EAMIsInit(&aNameOut))
        {
            aNameOut = StdPrefix(aNameIn) + "_Impaint.tif";
        }
        Tiff_Im aTifOut
                (
                    aNameOut.c_str(),
                    aSzIm,
                    aFileIm.type_el(),
                    Tiff_Im::No_Compr,
                    aFileIm.phot_interp()
                    );

        ELISE_COPY(aTifOut.all_pts(),aFRes,aTifOut.out());
    }
    return EXIT_SUCCESS;
}






