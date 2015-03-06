#ifndef _ELISE_GENERAL_PHOTOGRAM_CCPLEEPIP_H
#define _ELISE_GENERAL_PHOTOGRAM_CCPLEEPIP_H

#include "general/sys_dep.h"

class cCpleEpip
{
public :
    cCpleEpip
    (
            const std::string & aDir,
            double aScale,
            const CamStenope & aC1,const std::string & aName1,
            const CamStenope & aC2,const std::string & aName2,
            const std::string & PrefLeft =   "Left_",
            const std::string & PrefRight =  "Right_"
            );
    Pt2dr RatioExp() const;
    double RatioCam() const;
    const bool & Ok() const;
    const int & SzX() const;
    const int & SzY() const;

    double BSurHOfPx(bool Im1,double aPx);
    Fonc_Num BSurHOfPx(bool Im1,Fonc_Num aPx);

    std::string Dir();

    bool IsIm1(const std::string & aNameIm);  // Erreur si ni Im1 ni Im2


    std::string LocDirMatch(const std::string & Im);
    std::string LocNameImEpi(const std::string & Im,int aDeZoom=1,bool Pyram = true);
    std::string LocPxFileMatch(const std::string & Im,int aNum,int aDeZoom);
    std::string LocMasqFileMatch(const std::string & Im,int aNum);


    std::string LocDirMatch(bool Im1);
    std::string LocNameImEpi(bool Im1,int aDeZoom=1,bool Pyram=true);
    std::string LocPxFileMatch(bool Im1,int aNum,int aDeZoom);
    std::string LocMasqFileMatch(bool Im1,int aNum);



    bool IsLeft(bool Im1);
    bool IsLeft(const std::string &);


    void ImEpip(Tiff_Im aFile,const std::string & aNameOriIn,bool Im1,bool InParal=true,bool DoIm=true,const char * NameHom= 0,int aDegPloCor=-1);
    void AssertOk() const;

    void LockMess(const std::string & aMes);
    void SetNameLock(const std::string & anExt);
private :

    Box2dr   BoxCam(const CamStenope & aCam,const CamStenope & aCamOut,bool Show) const;
    inline Pt2dr TransfoEpip(const Pt2dr &,const CamStenope & aCamIn,const CamStenope & aCamOut) const;
    CamStenopeIdeale  CamOut(const CamStenope &,Pt2dr aPP,Pt2di aSz);





    double             mScale;
    std::string        mDir;
    cInterfChantierNameManipulateur  * mICNM;
    const CamStenope & mCInit1;
    std::string        mName1;
    const CamStenope & mCInit2;
    std::string        mName2;
    std::string        mNamePair;
    std::string        mPrefLeft;
    std::string        mPrefRight;
    Pt2di              mSzIn;
    double             mFoc;
    ElMatrix<double_t>     mMatM2C;
    ElMatrix<double_t>     mMatC2M;

    CamStenopeIdeale   mCamOut1;
    CamStenopeIdeale   mCamOut2;
    bool               mOk;
    bool               mFirstIsLeft;
    int                mSzX;
    int                mSzY;
    double             mPxInf;

    std::string        mFileLock;
};

#endif
