/*Header-MicMac-eLiSe-25/06/2007

    MicMac : Multi Image Correspondances par Methodes Automatiques de Correlation
    eLiSe  : ELements of an Image Software Environnement

    www.micmac.ign.fr


    Copyright : Institut Geographique National
    Author : Marc Pierrot Deseilligny
    Contributors : Gregoire Maillet, Didier Boldo.
    Refactoring: Helio Chissini de Castro <helio@kde.org>

[1] M. Pierrot-Deseilligny, N. Paparoditis.
    "A multiresolution and optimization-based image matching approach:
    An application to surface reconstruction from SPOT5-HRS stereo imagery."
    In IAPRS vol XXXVI-1/W41 in ISPRS Workshop On Topographic Mapping From Space
    (With Special Emphasis on Small Satellites), Ankara, Turquie, 02-2006.

[2] M. Pierrot-Deseilligny, "MicMac, un lociel de mise en correspondance
    d'images, adapte au contexte geograhique" to appears in
    Bulletin d'information de l'Institut Geographique National, 2007.

Francais :

   MicMac est un logiciel de mise en correspondance d'image adapte
   au contexte de recherche en information geographique. Il s'appuie sur
   la bibliotheque de manipulation d'image eLiSe. Il est distibue sous la
   licences Cecill-B.  Voir en bas de fichier et  http://www.cecill.info.


English :

    MicMac is an open source software specialized in image matching
    for research in geographic information. MicMac is built on the
    eLiSe image library. MicMac is governed by the  "Cecill-B licence".
    See below and http://www.cecill.info.

Header-MicMac-eLiSe-25/06/2007*/

#ifndef _ELISE_GENERAL_FIFO_ELFILO_H
#define _ELISE_GENERAL_FIFO_ELFILO_H

template <class Type> class ElFilo
{
     protected :

        void del_tab()
        {
             for (int kk=0; kk<_capa; kk++) _tab[kk] = Type();
             delete [] _tab;
        }

        void incr_capa()
        {
           Type * NewTab = new Type [2*_capa];
           for (int kk=0; kk<_nb ; kk++)
                NewTab[kk] = _tab[kk];

            del_tab();
           _tab = NewTab;
           _capa *= 2;
        }


        Type * _tab;
        int  _nb;
        int   _capa;

        ElFilo(const ElFilo<Type>&);


     public :

        typedef Type value_type;

        int   nb   ()  const {return _nb;}
        int   size   ()  const {return _nb;}
        bool  empty()  const {return _nb == 0;}
        int     capa() const {return _capa;}
        void  clear() { _nb    = 0;}

        void set_nb(int Nb)
        {
             ELISE_ASSERT(Nb<=_capa,"ElFilo::set_nb"); // HJMPD,  < devient <=
             _nb = Nb;
        }

        void set_capa(int new_capa)
        {
             while (_capa<new_capa)
             {
                 incr_capa();
             }
        }

        ElFilo(int aCapa = 10)  :
            _tab       (new Type [aCapa]),
            _nb        (0),
            _capa      (aCapa)
        {
        }
        const Type &  operator [] (int KK)  const
        {
             ELISE_ASSERT((KK>=0)&&(KK<_nb),"out index in ElFilo<Type>::[]");
             return _tab[KK];
        }
        Type &  operator [] (int K)
        {
             ELISE_ASSERT((K>=0)&&(K<_nb),"out index in ElFilo<Type>::[]");
             return _tab[K];
        }

        Type  & top()
        {
             ELISE_ASSERT(_nb!=0,"empty  ElFilo<Type>::top");
             return  _tab[_nb-1];
        }
        Type  & back() { return  top();}
        Type  & front() 
	{
             ELISE_ASSERT(_nb!=0,"empty  ElFilo<Type>::top");
             return  _tab[0];
	}


        const Type  & top() const
        {
             ELISE_ASSERT(_nb!=0,"empty  ElFilo<Type>::top");
             return  _tab[_nb-1];
        }

        Type  & top(int k)
        {
              ELISE_ASSERT((k>=0)&&(k<_nb),"out index in ElFifo<Type>::[]");
              return  _tab[_nb-1-k];
        }

        const Type  & top(int k) const
        {
              ELISE_ASSERT((k>=0)&&(k<_nb),"out index in ElFifo<Type>::[]");
              return  _tab[_nb-1-k];
        }



        ~ElFilo() 
        { 
             del_tab();
        }

        Type  poplast()
        {
             ELISE_ASSERT(_nb!=0,"empty  ElFilo<Type>::[]");
             return _tab[--_nb];
        }

        void   pushlast(const Type & p)
        {
             if (_nb == _capa) incr_capa();
#if Compiler_Visual_6_0  
             _tab[_nb++] = (Type) p;
#else
	     _tab[_nb++] =  p;
#endif
        }

        Type * tab() {return _tab;}

     
        Type * first() {return _tab;}
        Type * end()  {return _tab+_nb;}
        const Type * first() const {return _tab;}
        const Type * end()  const {return _tab+_nb;}
        typedef Type * iterator;
        typedef const Type * const_iterator;
};

#endif
