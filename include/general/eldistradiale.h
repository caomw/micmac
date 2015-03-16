#ifndef _ELISE_GENERAL_PHOTOGRAM_ELDISTRADIALE_H
#define _ELISE_GENERAL_PHOTOGRAM_ELDISTRADIALE_H



class ElDistRadiale : public ElDistortion22_Gen
{
public :


    Pt2dr  & Centre();
    const Pt2dr  & Centre() const;
    virtual bool OwnInverse(Pt2dr &) const ;    //  return false
    virtual Pt2dr Direct(Pt2dr) const ;

    virtual void  Diff(ElMatrix<double_t> &,Pt2dr) const;  // differentielle

    // rho -> K0 *rho * (1 + DistDirecte(rho))
    virtual double_t K0() const; // def : return 1
    virtual double_t DistDirecte(double_t R) const = 0;
    virtual double_t DistDirecteR2(double_t R) const = 0;

    // doit renvoyer la derivee de DistDirecte, divisee par rho
    virtual double_t  DerSurRho(double_t R) const = 0; // en delta / a 1

    virtual double_t DistInverse(double_t R)  const;
    // Par defaut les distortion sont
    // supposees faibles et la fontion inverse est
    // - la fonction directe

protected  :

    ElDistRadiale(Pt2dr Centre);

private  :
    Pt2dr _centre;
};

#endif
