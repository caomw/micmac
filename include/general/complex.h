#ifndef _ELISE_INCLUDE_GENERAL_COMPLEX_H_
#define _ELISE_INCLUDE_GENERAL_COMPLEX_H_

#include "StdAfx.h"

/*===================================*/
/*         polar-def                 */
/*===================================*/

class Polar_Def_Opun : public Simple_OP_UN<double_t>
{

public :
	Polar_Def_Opun(double_t teta_def) : _teta_def (teta_def) {}

	static Fonc_Num polar(Fonc_Num f,double_t teta0);

private  :
	virtual void calc_buf
		(
		double_t **,
		double_t**,
		int,
		const Arg_Comp_Simple_OP_UN  &
		);
	double_t _teta_def;

};

#endif //_ELISE_INCLUDE_GENERAL_COMPLEX_H_