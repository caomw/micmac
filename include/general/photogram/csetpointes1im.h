#ifndef _ELISE_GENERAL_PHOTOGRAM_CSETPOINTES1IM_H
#define _ELISE_GENERAL_PHOTOGRAM_CSETPOINTES1IM_H

#include "general/sys_dep.h"

class cSetPointes1Im
{
public :
    friend class cSetNImSetPointes;
    cSetPointes1Im
    (
            const cPolygoneEtal &,
            const std::string &,
            bool  SVP = false  // Si true et fichier inexistant cree set vide
            );
    typedef std::list<cPointeEtalonage> tCont;
    tCont  & Pointes() ;
    cPointeEtalonage & PointeOfId(cCiblePolygoneEtal::tInd);
    cPointeEtalonage * PointeOfIdSvp(cCiblePolygoneEtal::tInd);
    void RemoveCibles(const std::vector<INT> & IndToRemove);
    bool  InitFromFile(const cPolygoneEtal &,ELISE_fp & aFp,bool InPK1);
private :
    tCont mPointes;
    cSetPointes1Im();
};

#endif
