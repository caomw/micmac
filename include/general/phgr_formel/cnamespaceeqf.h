#ifndef _ELISE_GENERAL_PHGR_FORMEL_CNAMESPACEEQF_H
#define _ELISE_GENERAL_PHGR_FORMEL_CNAMESPACEEQF_H



class cNameSpaceEqF
{
        public :

             typedef std::vector<cElCompiledFonc  *>     tContFcteur;

	     typedef enum
	     {
		     eNoAqqAppui,
		     eAqqAppuiSimple,
		     eAqqAppuiPtInc
	     } eTypeEqAppui;

	     typedef enum
	     {
		     eSysPlein,
		     eSysCreuxMap,
		     eSysCreuxFixe,
		     eSysL1Barrodale,
		     eSysL2BlocSym
	     } eTypeSysResol;

	     typedef enum
             {
                     eHomLibre,
                     eHomFigee,
                     eHomStdBloqueRot  // Bloquage en rotation en 0,0 et axe des X
             } eModeContrHom;

	     typedef enum
	     {
                  eRotLibre,
	          eRotFigee,
	          eRotBaseU,
	          eRotPseudoBaseU,
                  eRotCOptFige
	     } eModeContrRot;
	     typedef enum
	     {
                  eResiduCoplan,
	          eResiduIm1,
	          eResiduIm2
	     } eModeResidu;
	     static std::string & NameOfTyRes(eModeResidu);

             // Nom donne a partir des usages
	     typedef enum
	     {
		     eTEDD_Reformat,
		     eTEDD_Bayer,
		     eTEDD_Interp
	     } eTypeEqDisDirecre;
	 public :
	     static std::string TheNameEcCoplan;
	     static std::string TheNameResiduIm1;
	     static std::string TheNameResiduIm2;
};

#endif
