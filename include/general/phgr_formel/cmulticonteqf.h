#ifndef _ELISE_GENERAL_PHGR_FORMEL_CMULTICONTEQF_H
#define _ELISE_GENERAL_PHGR_FORMEL_CMULTICONTEQF_H

#include "general/sys_dep.h"

class cMultiContEQF
{
    public :
        cMultiContEQF();
	void AddAcontrainte(cElCompiledFonc * mFCtr,double aTol);
	int NbC() const;
	const cContrainteEQF & KthC(int aKth) const;
	void Add(const cMultiContEQF &);

    private :
     // Parties univ
/*
    EN FAIT PAS UTILISE CAR :
         -1-  apres simplif, les fct cSetVar, ne coutent pas tres chers;
         -2-  si ont veut avoir des contraintes non strictes, on est
         obliges de maintenir l'ancien mecanisme, donc au final redondance ...

        void AddContrainteUniv(int aKV,double aVal,double aTol);
        int    NbUniv() const;
        int    KthIndUniv(int aK) const;
        double KthValUniv(int aK) const;
        double KthTolUniv(int aK) const;


        std::vector<int>             mKV;
        std::vector<double>          mVals;
        std::vector<double>          mTols;
*/
        std::vector<cContrainteEQF>  mContraintes;
};

#endif
