#ifndef _ELISE_GENERAL_OPTIM_ELGROWINGSETIND_H
#define _ELISE_GENERAL_OPTIM_ELGROWINGSETIND_H

#include "general/sys_dep.h"

class ElGrowingSetInd 
{
     public :
         // Partie typedef

            typedef INT key_type;
            typedef INT value_type;
            typedef std::vector<INT>::const_iterator const_iterator;

         // "Big Three"
            ElGrowingSetInd
            (
                 INT aCapa, 
                 REAL aRatioEncombr = 0.1 // Pour dimensionner mIndexes, Pas Fondamental.
            );
            ~ElGrowingSetInd();
            /// ElGrowingSetInd(const ElGrowingSetInd &); => en private, non implante

         // Pour parcourir un ElGrowingSetInd
            const_iterator begin() const  {return mIndexes.begin();}
            const_iterator end()   const  {return mIndexes.end();}



         // Partie set classique
            void clear();
            void insert(const INT&) ;
            int size() const;


         /*
             >,>=, == , != : peuvent etre fait rapidement
         */

     private :
         inline void AssertValideIndexe(INT anIndexe) const;
         inline bool PrivMember(INT anIndexe) const;
         inline void PrivSet(INT anIndexe,bool) ;
         ElGrowingSetInd(const ElGrowingSetInd &);  // Non implante

         INT         mCapa;
         std::vector<INT>  mIndexes;
         Im2D_Bits<1>      mBuzyIndexes;

         // void erase(const INT&);  a definir dans une classe derivee, "non growing"
};

#endif
