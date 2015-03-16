#ifndef _ELISE_GENERAL_BITM_TYPEEL>_H
#define _ELISE_GENERAL_BITM_TYPEEL>_H



template <class TypeEl>
#ifndef _ELISE_GENERAL_BITM_CintERPOLSINUSCARDINAL_H
#define _ELISE_GENERAL_BITM_CintERPOLSINUSCARDINAL_H



class cInterpolSinusCardinal : public cInterpolateurIm2D<TypeEl>
{
    public :
        cInterpolSinusCardinal(int sizeOfWindow, bool apodise = false);
        virtual ~cInterpolSinusCardinal();
        virtual double GetVal(TypeEl ** aTab,const Pt2dr &  aP) const ;
        virtual int  SzKernel() const;
    private :
        bool m_apodise;
        int m_sizeOfWindow;
        double_t *m_tabX, *m_tabY, *m_tabTemp;
};

#endif
