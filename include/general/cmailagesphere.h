#ifndef _ELISE_GENERAL_GEOM_VECTEUR_CMAILAGESPHERE_H
#define _ELISE_GENERAL_GEOM_VECTEUR_CMAILAGESPHERE_H



class cMailageSphere
{
    public :
        cMailageSphere(Pt2dr,Pt2dr,Pt2dr,bool Inv);
        void SetStep(Pt2dr);
        void SetMax(Pt2dr);
        void SetMin(Pt2dr);

        Pt2dr Pix2Spherik(Pt2dr aIndTP);
        Pt2di Spherik2PixI(Pt2dr  aTetaPhi);
        Pt2dr Spherik2PixR(Pt2dr  aTetaPhi);

        Pt2di SZEnglob();
        void WriteFile(const std::string & aNameFile);
        static cMailageSphere FromFile(const std::string & aNameFile);

        Pt3dr DirMoy();
        Pt2dr DirMoyH();

    private :
        Pt2dr mStep;  // Teta ,Phi
        Pt2dr mMin;
        Pt2dr mMax;
        int   mInv;
};

#endif
