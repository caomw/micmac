#ifndef _ELISE_GENERAL_PHOTOGRAM_CRESOLVAMBIBASE_H
#define _ELISE_GENERAL_PHOTOGRAM_CRESOLVAMBIBASE_H



class cResolvAmbiBase
{
public :
    // Les orientations sont des orientations tq R.ImAff(0) est le centre optique, Cam->Monde
    cResolvAmbiBase
    (
            const ElRotation3D &  aR0,   // Orientation connue completement
            const ElRotation3D &  aR1   // Orientation connue a un facteur d'echelle pres sur la base
            );

    void AddHom(const ElPackHomologue & aH12,const ElRotation3D & aR2);
    double SolveBase();
    ElRotation3D SolOrient(double & aLambda);


private :

    Pt3dr mC0;
    Pt3dr mV01;
    ElRotation3D &mR1;
    std::vector<double> mLambdas;
};

#endif
