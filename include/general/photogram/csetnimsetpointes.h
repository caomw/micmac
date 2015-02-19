#ifndef _ELISE_GENERAL_PHOTOGRAM_CSETNIMSETPOINTES_H
#define _ELISE_GENERAL_PHOTOGRAM_CSETNIMSETPOINTES_H

#include "general/sys_dep.h"

class cSetNImSetPointes
{
public :
    cSetNImSetPointes
    (
            const cPolygoneEtal &,
            const std::string &,
            bool  SVP = false  // Si true et fichier inexistant cree set vide
            );
    typedef std::list<cSetPointes1Im> tCont;
    tCont  & Pointes() ;
    INT NbPointes();
private :
    tCont mLPointes;

};

#endif
