#ifndef _ELISE_GENERAL_GEOM_VECTEUR_MAT_INERTIE_H
#define _ELISE_GENERAL_GEOM_VECTEUR_MAT_INERTIE_H



template <class Type> class Mat_Inertie
{
     public  :

       Mat_Inertie();
       Mat_Inertie
       (
               typename Type::TypeScal S,
               typename Type::TypeEff  S1,
               typename Type::TypeEff  S2,
               typename Type::TypeScal S11,
               typename Type::TypeScal S12,
               typename Type::TypeScal S22
       )
          :
               _s     (S),
               _s1    (S1),
               _s2    (S2),
               _s11   (S11),
               _s12   (S12),
               _s22   (S22)
       {
       }

       void add_pt_en_place( typename Type::TypeEff v1,  typename Type::TypeEff v2)
       {
            _s   += 1;
            _s1  += v1;
            _s2  += v2;
            _s11 += scal(v1,v1);
            _s12 += scal(v1,v2);
            _s22 += scal(v2,v2);
       }

       void add_pt_en_place
           (
                typename Type::TypeEff v1,
                typename Type::TypeEff v2,
                typename Type::TypeScal pds
            )
       {
            _s   += pds;
            _s1  += v1 *pds;
            _s2  += v2 *pds;
            _s11 += scal(v1,v1) *pds;
            _s12 += scal(v1,v2) *pds;
            _s22 += scal(v2,v2) *pds;
       }


        typename Type::TypeScal    s()    const {return _s;}
        typename Type::TypeEff     s1()   const {return _s1;}
        typename Type::TypeEff     s2()   const {return _s2;}
        typename Type::TypeScal    s11()  const {return _s11;}
        typename Type::TypeScal    s12()  const {return _s12;}
        typename Type::TypeScal    s22()  const {return _s22;}


       Mat_Inertie  plus_cple
                    (
                       typename Type::TypeEff v1,
                       typename Type::TypeEff v2,
                       typename Type::TypeScal pds =1
                    ) const
       {
            return Mat_Inertie
                   (
                       _s   + pds,
                       _s1  +  v1 * pds,
                       _s2  +  v2 * pds,
                       _s11 +  scal(v1,v1) * pds,
                       _s12 +  scal(v1,v2) * pds,
                       _s22 +  scal(v2,v2) * pds
                   );
       }

       Mat_Inertie operator - (const Mat_Inertie &) const;
       void operator += (const Mat_Inertie &);


            // renvoie la droite au moinde carre, point initial = cdg;
            // second point (indertermine a pi pres) situe a dun distance norm


       Mat_Inertie< typename Type::TypeReel>  normalize() const
       {
             ELISE_ASSERT
             (
                  _s != 0,
                  "som pds = 0 in Mat_Inertie::normalize"
             );

              typename Type::TypeReel::TypeEff  S1 =  _s1 / (double_t) _s;
              typename Type::TypeReel::TypeEff  S2 =  _s2 / (double_t) _s;


#if ( ELISE_windows & ELISE_MinGW )
    return Mat_Inertie<typename Type::TypeReel>
#else
    return Mat_Inertie<typename Type::TypeReel>
#endif
                    (
                         _s,
                         S1,
                         S2,
                         _s11/(double_t)_s  -scal(S1,S1),
                         _s12/(double_t)_s  -scal(S1,S2),
                         _s22/(double_t)_s  -scal(S2,S2)
                    );
       }

       double_t  correlation(double_t epsilon = 1e-14)
       {
           #if ( ELISE_windows & ELISE_MinGW )
             Mat_Inertie<typename  Type::TypeReel> m =  normalize();
           #else
             Mat_Inertie<typename  Type::TypeReel> m =  normalize();
           #endif
             return m.s12() / sqrt(ElMax(epsilon,m.s11()*m.s22()));
       }

       double_t  correlation_with_def(double_t aDef)
       {
            #if ( ELISE_windows & ELISE_MinGW )
              Mat_Inertie<typename  Type::TypeReel> m =  normalize();
            #else
              Mat_Inertie<typename  Type::TypeReel> m =  normalize();
            #endif
         if ((m.s11()<=0) || (m.s22() <=0)) return aDef;
             return m.s12() / sqrt(m.s11()*m.s22());
       }



       typename Type::TypeScal S0() const {return _s;}
       typename Type::TypeReel::TypeEff  V2toV1(const typename Type::TypeReel::TypeEff & aV2,double_t epsilon = 1e-14);
       typename Type::TypeReel::TypeEff  V1toV2(const typename Type::TypeReel::TypeEff & aV2,double_t epsilon = 1e-14);


    private :


           typename Type::TypeScal         _s;
           typename Type::TypeEff          _s1;
           typename Type::TypeEff          _s2;
           typename Type::TypeScal         _s11;
           typename Type::TypeScal         _s12;
           typename Type::TypeScal         _s22;
};

#endif
