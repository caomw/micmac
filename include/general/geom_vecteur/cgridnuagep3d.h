#ifndef _ELISE_GENERAL_GEOM_VECTEUR_CGRIDNUAGEP3D_H
#define _ELISE_GENERAL_GEOM_VECTEUR_CGRIDNUAGEP3D_H

#include "general/sys_dep.h"

class cGridNuageP3D
{
    public :
            cGridNuageP3D
        (
             const std::string &,
         Pt2di aSz = Pt2di(-1,-1), // Def => Tiff.sz()
         Pt2di aP0 = Pt2di(0,0)
            );
        Pt2di Sz() const;
        INT   Cpt(Pt2di) const;
        Pt3dr P3D(Pt2di) const;

        std::string NameShade() const;
        Im2D_U_INT1   ImShade();
        Im2D_INT1     ImCpt();

        // Profondeur dans la direction moyenne
        Fonc_Num FProfDMoyH();

        Tiff_Im   TifFile(const std::string & aShortName);
    private :
        static const std::string theNameShade;
        void Init(Im2DGen,const std::string &);

        std::string   mName;
        Pt2di         mSz;
        Pt2di         mP0;

        Im2D_REAL4    mImX;
        REAL4 **      mDX;
        Im2D_REAL4    mImY;
        REAL4 **      mDY;
        Im2D_REAL4    mImZ;
        REAL4 **      mDZ;
        Im2D_INT1     mImCpt;
        Im2D_U_INT1   mImShade;
        cMailageSphere  mMSph;
};

#endif
