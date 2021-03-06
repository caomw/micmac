#ifndef _ELISE_GENERAL_PHOTOGRAM_CDISTSTDFROMCAM_H
#define _ELISE_GENERAL_PHOTOGRAM_CDISTSTDFROMCAM_H



class cDistStdFromCam : public ElDistortion22_Gen
{
public :
    cDistStdFromCam(ElCamera & Cam);
    Pt2dr Direct(Pt2dr) const ;
    void  Diff(ElMatrix<double_t> &,Pt2dr) const;

private :
    ElCamera & mCam;
};

#endif
