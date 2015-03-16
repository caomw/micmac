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


#ifndef _ELISE_GENERAL_UTIL_TFILEOFFSET_H
#define _ELISE_GENERAL_UTIL_TFILEOFFSET_H

#include <cstdint>

#include <cTplValGesInit>

class tFileOffset
{
    public :


         const int64_t & AbsLLO() const
         {
               int64_t aLLO = mLLO.Val();
               ELISE_ASSERT(aLLO>=0,"AbsLLO neg");
               return mLLO.Val();
         }
         unsigned int   Byte4AbsLLO() const
         {
               int64_t aLLO = mLLO.Val();
               ELISE_ASSERT((aLLO>=0) && (aLLO<=0xFFFFFFFFll),"Byt4LLO too big");
               return (unsigned int)aLLO;
         }
         const int64_t & BasicLLO() const
         {
               return mLLO.Val();
         }
         int  IntBasicLLO() const
         {
               int64_t aLLO = mLLO.Val();
               ELISE_ASSERT((aLLO>-0x7FFFFFFFll) && (aLLO<0x7FFFFFFFll),"Byt4LLO too big");
               return (int)aLLO;
         }

         tFileOffset ()
         {
             mLLO.SetNoInit();
         }
         tFileOffset (const int64_t & aLLO) :
           mLLO(aLLO)
         {
         }

         tFileOffset operator + (const tFileOffset & anO2) const
         {
               return mLLO.Val() + anO2.mLLO.Val();
         }
         tFileOffset operator - (const tFileOffset & anO2) const
         {
               return mLLO.Val() - anO2.mLLO.Val();
         }
         tFileOffset operator / (const tFileOffset & anO2) const
         {
               return mLLO.Val() / anO2.mLLO.Val();
         }
         tFileOffset operator * (const tFileOffset & anO2) const
         {
               return mLLO.Val() * anO2.mLLO.Val();
         }

         bool operator < (const tFileOffset & anO2) const
         {
               return mLLO.Val() < anO2.mLLO.Val();
         }
         bool operator > (const tFileOffset & anO2) const
         {
               return mLLO.Val() > anO2.mLLO.Val();
         }
         bool operator == (const tFileOffset & anO2) const
         {
               return mLLO.Val() == anO2.mLLO.Val();
         }
         bool operator != (const tFileOffset & anO2) const
         {
               return mLLO.Val() != anO2.mLLO.Val();
         }

         void operator ++ (int)
         {
              mLLO.SetVal(mLLO.Val()+1);
         }
         void operator +=  (const tFileOffset & anO2)
         {
              mLLO.SetVal(mLLO.Val()+anO2.mLLO.Val());
         }
         void operator -=  (const tFileOffset & anO2)
         {
              mLLO.SetVal(mLLO.Val()-anO2.mLLO.Val());
         }
         void operator *=  (const tFileOffset & anO2)
         {
              mLLO.SetVal(mLLO.Val()*anO2.mLLO.Val());
         }


/*
         void SetLLO(const int64_t & aLLO)
         {
              mLLO.SetVal(aLLO);
         }
*/
         bool IsInit() const
         {
              return mLLO.IsInit();
         }

// Deux interface bas niveaus, "tres sales", poiur assurer la communication avec le stockage
// en int des offset dans les tiffs qui est necessaire pour utiliser le service de tag generiques
         static  tFileOffset FromReinterpretInt(int anI)
         {
               unsigned int anUI;
                           std::memcpy(&anUI,&anI,sizeof(unsigned int));
               return tFileOffset(anUI);
         }
         int ToReinterpretInt() const
         {
              int aRes;
              unsigned int anOfs4 = Byte4AbsLLO();
                          std::memcpy(&aRes,&anOfs4,sizeof(unsigned int));
              return aRes;
         }
    private :
        cTplValGesInit<int64_t> mLLO;
};

#endif
