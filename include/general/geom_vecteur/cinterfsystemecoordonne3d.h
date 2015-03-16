#ifndef _ELISE_GENERAL_GEOM_VECTEUR_CintERFSYSTEMECOORDONNE3D_H
#define _ELISE_GENERAL_GEOM_VECTEUR_CintERFSYSTEMECOORDONNE3D_H



class cInterfSystemeCoordonne3D
{
     public :

         virtual Pt3dr ToEuclid(const Pt3dr & aP) const = 0;
         virtual Pt3dr FromEuclid(const Pt3dr & aP) const = 0;
     public :
};

#endif
