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


#ifndef _ELISE_GENERAL_UTIL_CAPPLIBATCH_H
#define _ELISE_GENERAL_UTIL_CAPPLIBATCH_H

#include "general/sys_dep.h"

class cAppliBatch
{
    public :
       typedef enum
       {
            eExeDoNothing,
            eExeDoIfFileDontExist,
            eExeDoSys,
            eExeWriteBatch
       } eModeExecution;

       typedef enum
       {
             eNoPurge =0,
             ePurgeTmp =1,
             ePurgeAll =2
       } eNivPurge;


       void DoAll();

       //const std::string & ThisBin() const;

       cEl_GPAO &  GPAO ();
       bool        ByMKf() const;  // By Make file
       const std::string & MKf() const;
       // Parfois le plus simple est que le programme se rappelle lui - meme avec
       // des option legerement differente dans ce cas on doit etre au courant
       bool        IsRelancedByThis() const;

    protected :
        virtual ~cAppliBatch();
        cAppliBatch
    (
         int,
         char **,
         int aNbArgGlob,
         int aNbFile,
         const std::string & aPostFixWorkDir,
         const std::string & aKeyDOIDE="",
             bool  ForceByDico = false
        );

     void AddPatSauv(const std::string &);
         int ARGC();
     char ** ARGV();
     std::string ComCommune() const;
         int System(const std::string &,bool aSVP=false);
         int System(const char* FileCible,const std::string &,bool aSVP=false);
     const std::string & CurF1() const;
     const std::string & CurF2() const;
     const std::string & CurF(int aK) const;
         const std::string  & DirChantier() const;
         const std::string  & DirTmp() const;
         const std::string  & DirSauv() const;
     cInterfChantierNameManipulateur * ICNM();
     cInterfChantierNameManipulateur * ICNM() const;

     bool NivPurgeIsInit();
     void SetNivPurge(eNivPurge  );
     bool NivExeIsInit();
     void SetNivExe(eModeExecution);
         eModeExecution ModeExe() const;
         std::string ComForRelance();
    std::string protectFilename( const std::string &i_filename ) const; // according to ByMKf()

    private :
    void DoOne();
    virtual void Exec() = 0;
    void UseLFile(const std::list<std::string> &);



    // Les args non consommes

     // Partie de la ligne de commande qui revient a chaque fois


    // private :
    std::vector<char *>  mArgsNC;  //

        void DoPurge();

    cInterfChantierNameManipulateur * mICNM;

        //std::string  mThisBin;
        std::string  mDirChantier;

    std::string  mPostFixWorkDir;
    int          mNbFile;
        bool         mByNameFile;
    std::string  mDirSauv;
    std::string  mDirTmp;

        //bool         mFileByICNM;
    std::string  mPatF1;
    std::string  mPatF2;
    std::string  mCurF1;
    std::string  mCurF2;
    std::vector<std::string> mVCurF;

    std::string  mArgAdd;

        eModeExecution  mModeExe;
    bool            mExeIsInit;
    eNivPurge       mNivPurge;
    bool            mNivPurgeIsInit;
        std::string     mFileBatch;
    std::vector<std::string>  mPatSauv;

    bool                      mFileByPat;
    bool                      mByDico;
    std::list<std::string>    mListFile1ByPat;
    int  mReverse;
    int                       mDOIDE;
    std::string               mKeyDOIDE;

        std::string               mMKf;
        bool                      mModeAddMkf;
        int                       mIsRelancedByThis;
        std::string               mDebCom;
        std::string               mEndCom;
        cEl_GPAO                  mGPAO;
};

#endif
