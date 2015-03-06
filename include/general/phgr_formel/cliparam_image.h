#ifndef _ELISE_GENERAL_PHGR_FORMEL_CLIPARAM_IMAGE_H
#define _ELISE_GENERAL_PHGR_FORMEL_CLIPARAM_IMAGE_H

#include "general/sys_dep.h"

class cLIParam_Image : public cObjFormel2Destroy
{
	public :
		friend class cSetEqFormelles;
		cRotationFormelle & Rot();
		cSetEqFormelles & Set();
		void UpdateCam();
		Im2D_double_t4 Im();
	        Pt2dr  Ray2Im(Pt3dr);
	        Pt3dr  Im2Ray(Pt2dr);

		void SetImZ(Im2D_double_t4 anIm,double_t aZ);


	private  :
		
                void Update_0F2D();
		cLIParam_Image
	        (
		    cSetEqFormelles &,
		    Im2D_double_t4   anIm,
		    double_t         aZoom,
		    CamStenope & aCam,
                    cNameSpaceEqF::eModeContrRot
		);

		CamStenope &      Cam();
		cLIParam_Image (const cLIParam_Image &); // NI
		cSetEqFormelles &    mSet;
		cRotationFormelle *  pRot;
		Im2D_double_t4           mIm;
		double_t                 mZoom;
		CamStenope &        mCam;
};

#endif
