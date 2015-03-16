#ifndef _ELISE_GENERAL_PHGR_FORMEL_CEQREGULD1_H
#define _ELISE_GENERAL_PHGR_FORMEL_CEQREGULD1_H



class cEqRegulD1  : public cObjFormel2Destroy
{
     public :
	    friend class cSetEqFormelles;
     private :
	    std::string                    mNameType;
            cElCompiledFonc *              mFoncEq;

};

#endif
