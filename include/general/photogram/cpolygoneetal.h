#ifndef _ELISE_GENERAL_PHOTOGRAM_CPOLYGONEETAL_H
#define _ELISE_GENERAL_PHOTOGRAM_CPOLYGONEETAL_H



class cPolygoneEtal
{
public :
    virtual void AddCible(const cCiblePolygoneEtal &) =0;
    virtual const cCiblePolygoneEtal & Cible(cCiblePolygoneEtal::tInd) const = 0;
    virtual ~cPolygoneEtal();
    static cPolygoneEtal * IGN();
    static cPolygoneEtal * FromName
    (
            const std::string &,
            const cComplParamEtalPoly * aParam
            );

    typedef std::list<const cCiblePolygoneEtal *>  tContCible;

    const  tContCible  & ListeCible() const;
    cPolygoneCalib * PC() const;
    void SetPC(cPolygoneCalib *);
protected :
    void LocAddCible(const cCiblePolygoneEtal *);
    cPolygoneEtal();
    void PostProcess();
private :
    tContCible mListeCible;
    cPolygoneCalib * mPC;
};

#endif
