#ifndef _ELISE_GENERAL_GEOM_VECTEUR_CELNUAGELASER_H
#define _ELISE_GENERAL_GEOM_VECTEUR_CELNUAGELASER_H

#include "general/sys_dep.h"

class cElNuageLaser
{
     public  :

       typedef enum
       {
            eConvId,
            eConvCarto2Terr,
            eConvCarto2TerIm
       } eModeConvGeom;
       cElNuageLaser
       (
              const std::string & aNameFile,
              const char *  aNameOri = NULL,
              const char *  aNameGeomCible = NULL,  // GeomCarto GeomTerrain GeomTerIm1
              const char *  aNameGeomInit = "GeomCarto"
       );
       const std::vector<Pt3dr> & VPts() const;
       void SauvCur(const std::string &);
       void Debug(const std::string & aName);


       REAL   ZMin () const;
       REAL   ZMax () const;
       Box2dr Box() const;

       void  AddQt(INT aNbObjMaxParFeuille,REAL aDistPave);

       void ParseNuage(cResReqNuageLaser & aResParse,Box2dr aBox);

     private :
       cElNuageLaser(const cElNuageLaser &);  // Non Implemente

       std::vector<Pt3dr>  mVPts;

       REAL                mZMax;
       REAL                mZMin;
       Pt2dr               mPInf;
       Pt2dr               mPSup;
       cQtcElNuageLaser *  mQt;
};

#endif
