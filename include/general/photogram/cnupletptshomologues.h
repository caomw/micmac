#ifndef _ELISE_GENERAL_PHOTOGRAM_CNUPLETPTSHOMOLOGUES_H
#define _ELISE_GENERAL_PHOTOGRAM_CNUPLETPTSHOMOLOGUES_H



class cNupletPtsHomologues
{
public :
    ElCplePtsHomologues & ToCple();
    const ElCplePtsHomologues & ToCple() const;

    // Uniquement en dim 2
    const Pt2dr & P1() const ;
    Pt2dr & P1() ;
    const Pt2dr & P2() const ;
    Pt2dr & P2() ;



    const double_t & Pds() const ;
    double_t & Pds() ;

    cNupletPtsHomologues(int aNb,double aPds=1.0);
    int NbPts() const;

    const Pt2dr & PK(int aK) const ;
    Pt2dr & PK(int aK) ;

    void write(class  ELISE_fp & aFile) const;
    static cNupletPtsHomologues read(ELISE_fp & aFile);

    void AddPts(const Pt2dr & aPt);

    bool IsDr(int aK) const;
    void SetDr(int aK);

private :
    void AssertD2() const;
    std::vector<Pt2dr> mPts;
    double_t  mPds;
    // Gestion super bas-niveau avec des flag de bits pour etre compatible avec la structure physique faite
    // quand on ne contenait que des points ....
    int   mFlagDr;
    void AssertIsValideFlagDr(int aK) const;
    bool IsValideFlagDr(int aK) const;

};

#endif
