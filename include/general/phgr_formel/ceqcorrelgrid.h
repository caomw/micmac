#ifndef _ELISE_GENERAL_PHGR_FORMEL_CEQCORRELGRID_H
#define _ELISE_GENERAL_PHGR_FORMEL_CEQCORRELGRID_H

#include "general/sys_dep.h"

class cEqCorrelGrid  : public cObjFormel2Destroy
{
	public :
            friend class cSetEqFormelles;
	    static std::string NameType(INT aNbPix,bool Im2MoyVar);
	    cElemEqCorrelGrid & KthElem(INT aK);
            cElCompiledFonc * Fctr();
	private :
	    cEqCorrelGrid(const cEqCorrelGrid &); // Not Impl
	    cEqCorrelGrid
            (
	        cSetEqFormelles & aSet,
	        INT aNbPix,
		bool Im2MoyVar,
		bool GenCode
            );
	    cSetEqFormelles &              mSet;
            cIncListInterv                 mLInterv;
	    INT                            mNbPix;
	    std::vector<cElemEqCorrelGrid> mVPix;
	    bool                           mIm2MoyVar;
	    bool                           mGenCode;
	    std::string                    mNameType;
            cElCompiledFonc *              mFoncEq;
};

#endif
