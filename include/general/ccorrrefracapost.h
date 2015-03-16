#ifndef _ELISE_GENERAL_PHOTOGRAM_CCORRREFRACAPOST_H
#define _ELISE_GENERAL_PHOTOGRAM_CCORRREFRACAPOST_H



class cCorrRefracAPost
{
public :
    Pt2dr CorrM2C(const Pt2dr &) const;
    Pt2dr CorrC2M(const Pt2dr &) const;
    cCorrRefracAPost(const cCorrectionRefractionAPosteriori &);

    // Le coefficient est le ratio du coeef de refrac du milieu d'entree sur le milieu de sortie
    Pt3dr CorrectRefrac(const Pt3dr &,double aCoef) const;

    const cCorrectionRefractionAPosteriori & ToXML() const;
private :

    cCorrectionRefractionAPosteriori * mXML;
    ElCamera *  mCamEstim;
    double      mCoeffRefrac;
    bool       mIntegDist;
};

#endif
