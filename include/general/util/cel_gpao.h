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


#ifndef _ELISE_GENERAL_UTIL_CEL_GPAO_H
#define _ELISE_GENERAL_UTIL_CEL_GPAO_H

#include "general/sys_dep.h"

class cEl_GPAO
{
     public :
          // Interface simplifiee quand il n'y a pas de dependance entre les commandes
          static void DoComInParal(const std::list<std::string> &,std::string  FileMk = "", int   aNbProc = 0 ,bool Exe=true, bool MoinsK=false);
          static void DoComInSerie(const std::list<std::string> &);

         ~cEl_GPAO();
          cEl_GPAO();

        #ifdef __USE_EL_COMMAND__
            cElTask   & NewTask
                        (
                            const std::string &aName,
                            const cElCommand & aBuildingRule
                        ) ;

            cElTask   & GetOrCreate
                        (
                            const std::string &aName,
                            const cElCommand & aBuildingRule
                        );
        #else
            cElTask   & NewTask
                        (
                                const std::string &aName,
                                const std::string & aBuildingRule
                            ) ;

            cElTask   & GetOrCreate
                        (
                                const std::string &aName,
                                const std::string & aBuildingRule
                            ) ;
        #endif


         cElTask   &TaskOfName(const std::string &aName) ;
         void  GenerateMakeFile(const std::string & aNameFile) const ;
         void  GenerateMakeFile(const std::string & aNameFile,bool ModeAdditif) const;
         void ExeParal(std::string aFile,int aNbProc = -1,bool SuprFile=true);
         void dump( std::ostream &io_ostream=std::cout ) const;
     private :
         std::map<std::string,cElTask *>  mDico;

};

#endif
