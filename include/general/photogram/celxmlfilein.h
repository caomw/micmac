#ifndef _ELISE_GENERAL_PHOTOGRAM_CDBLEGRID_H
#define _ELISE_GENERAL_PHOTOGRAM_CDBLEGRID_H



class cDbleGrid : public ElDistortion22_Gen
{
public :

    // Dans le cas ou il s'agit d'une grille photogram
    // le PP est l'image reciproque de (0,0),
    // la Focale est calculee par differnce finie,
    // en X, avec un pas de 1 Pixel
    double_t Focale();
    Pt2dr PP() ;
    const Pt2dr & P0_Dir() const;
    const Pt2dr & P1_Dir() const;
    const Pt2dr  & Step_Dir() const;

    static cDbleGrid *  StdGridPhotogram(const std::string & aName,int aSzDisc=30);



    cDbleGrid
    (
            bool AdaptStep,
            Pt2dr aP0,Pt2dr aP1,
            Pt2dr               aStep,
            ElDistortion22_Gen &,
            const std::string & aName = "DbleGrid",
            bool  doDir = true,
            bool  doInv = true
            );
    const std::string & Name() const;

    static cDbleGrid * read(const  std::string &);
    static cDbleGrid * read(ELISE_fp & aFile);

    void write(const  std::string &);
    void write(ELISE_fp & aFile);
    ~cDbleGrid();
    Pt2dr ValueAndDer(Pt2dr aRealP,Pt2dr & aGradX,Pt2dr & aGradY);
    virtual Pt2dr Direct(Pt2dr) const  ;    //
    const PtImGrid & GrDir() const ;
    const PtImGrid & GrInv() const ;
    PtImGrid & GrDir() ;
    PtImGrid & GrInv() ;

    // Applique un chgt d'echelle sur les image direct
    // typiquement si ChScale=Focale() Tr= PP() ; alors
    // on une correction de distorsion assez classique
    void SetTrChScaleDir(double_t aChScale,Pt2dr aTr);
    void SetTrChScaleInv(double_t aChScale,Pt2dr aTr);

#ifndef _ELISE_GENERAL_PHOTOGRAM_CXMLMODE_H
#define _ELISE_GENERAL_PHOTOGRAM_CXMLMODE_H



    class cXMLMode {
    public :
        cXMLMode(bool toSwapDirInv = false);
        bool    toSwapDirInv;
    };
    cDbleGrid(cXMLMode,const std::string & aDir,const std::string & aXML);


    cDbleGrid(const cGridDirecteEtInverse &);

    void PutXMWithData
    (
#ifndef _ELISE_GENERAL_PHOTOGRAM_CELXMLFILEIN_H
#define _ELISE_GENERAL_PHOTOGRAM_CELXMLFILEIN_H



            class cElXMLFileIn &       aFileXML,
            const std::string &  aNameDir
            );
    bool StepAdapted() const;

    // Nouveau format avec Image incluse
    void SaveXML(const std::string &);


private :

    void SauvDataGrid
    (
            const std::string &  aNameDir,
            Im2D_double_t8 anIm,
            const std::string & aName
            );

    virtual bool OwnInverse(Pt2dr &) const ;    //  return true
    virtual void  Diff(ElMatrix<double_t> &,Pt2dr) const ;  //  differentielle
    cDbleGrid(PtImGrid*,PtImGrid*);



    PtImGrid * pGrDir;
    PtImGrid * pGrInv;
    std::string mName;
};

#endif
