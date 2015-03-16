#ifndef _ELISE_GENERAL_BITM_CCHCOCART_H
#define _ELISE_GENERAL_BITM_CCHCOCART_H



class cChCoCart
{
     public :
        // mOri + mOx*aP.x + ...
        Pt3dr FromLoc(const Pt3dr &) const;
        cChCoCart Inv() const;
        cChCoCart(const Pt3dr &aOri,const Pt3dr&,const Pt3dr&,const Pt3dr&);

        static cChCoCart Xml2El(const cRepereCartesien &);
        cRepereCartesien El2Xml() const;
     private :
        Pt3dr mOri;
        Pt3dr mOx;
        Pt3dr mOy;
        Pt3dr mOz;
};

#endif
