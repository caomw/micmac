#ifndef _ELISE_GENERAL_BITM_CFONCI2D_H
#define _ELISE_GENERAL_BITM_CFONCI2D_H

class cFoncI2D
{
    public :
        virtual double Val(const int & x,const int & y) const = 0;
        virtual Box2di BoxDef() const = 0;
        virtual ~cFoncI2D();

    private :
};

#endif
