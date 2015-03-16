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

#ifndef _ELISE_GENERAL_FIFO_ELFIFO_H
#define _ELISE_GENERAL_FIFO_ELFIFO_H

#include <micmac_global.h>

template <class Type> class ElFifo
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
                NewTab[kk] = _tab[(kk+_begin)%_capa];

            del_tab();
           _tab = NewTab;
           _begin = 0;
           _capa *= 2;
        }


        Type * _tab;
        int  _nb;
        int   _capa;
        int   _begin;
        bool _is_circ;

        ElFifo(const ElFifo<Type>&);


     public :

        typedef Type value_type;

        int   nb   ()  const {return _nb;}
        unsigned int   size   ()  const {return _nb;}
        int   nb_interv ()  const {return _nb +_is_circ;}
        bool  empty()  const {return _nb == 0;}
        bool circ()    const {return _is_circ;}
        void set_circ(bool Circ)  {_is_circ = Circ;}
        int     capa() const {return _capa;}
        void  clear() { _nb    = 0; _begin = 0;}

        Type * tab()
        {
             ELISE_ASSERT(_begin==0,"_begin !=0 in ElFifo<Type>::tab()");
             return _tab;
        }

        ElFifo(int aCapa = 1,bool Circ = false)  :
            _tab       (new Type [aCapa]),
            _nb        (0),
            _capa      (aCapa),
            _begin     (0),
            _is_circ   (Circ)
        {
        }
        ElFifo(const std::vector<Type> & V,bool Circ)  :
            _tab       (new Type [V.size()]),
            _nb        (0),
            _capa      ((int) V.size()),
            _begin     (0),
            _is_circ   (Circ)
        {
            for (int aK=0; aK<int(V.size()) ; aK++)
                push_back(V[aK]);
        }

        std::vector<Type> ToVect()
	{
             std::vector<Type> aV;
	     for (int aK=0; aK<nb() ; aK++)
		     aV.push_back((*this)[aK]);
	     return aV;
	}

        const Type &  operator [] (int k)  const
        {

              if (_is_circ)
              {
                 ELISE_ASSERT(_nb>0,"empty  ElFifo<Type>::[]");
                 return _tab[(mod(k,_nb)+_begin)%_capa];
             }
             else
             {
                 ELISE_ASSERT((k>=0)&&(k<_nb),"out index in ElFifo<Type>::[]");
                 return _tab[(k+_begin)%_capa];
             }

        }
        Type &  operator [] (int k)
        {
              if (_is_circ)
              {
                 ELISE_ASSERT(_nb>0,"empty  ElFifo<Type>::[]");
                 return _tab[(mod(k,_nb)+_begin)%_capa];
             }
             else
             {
                 ELISE_ASSERT((k>=0)&&(k<_nb),"out index in ElFifo<Type>::[]");
                 return _tab[(k+_begin)%_capa];
             }

        }

		Type  & back()
        {
             ELISE_ASSERT(_nb!=0,"empty  ElFifo<Type>::top");
             return  _tab[(_begin+_nb-1)%_capa];
        }
        Type  & top() {return back();}
		Type & front() {return _tab[_begin];}

        const Type  & back() const
        {
             ELISE_ASSERT(_nb!=0,"empty  ElFifo<Type>::top");
             return  _tab[(_begin+_nb-1)%_capa];
        }
		const Type & front() const {return _tab[_begin];}
        const Type  & top() const {return back();}

        Type  & top(int k)
        {
              if (_is_circ)
              {
                 ELISE_ASSERT(_nb>0,"empty  ElFifo<Type>::[]");
                 return  _tab[(_begin+mod(_nb-1-k,_nb))%_capa];
             }
             else
             {
                 ELISE_ASSERT((k>=0)&&(k<_nb),"out index in ElFifo<Type>::[]");
                 return  _tab[(_begin+_nb-1-k)%_capa];
             }
        }

        const Type  & top(int k) const
        {
              if (_is_circ)
              {
                 ELISE_ASSERT(_nb>0,"empty  ElFifo<Type>::[]");
                 return  _tab[(_begin+mod(_nb-1-k,_nb))%_capa];
             }
             else
             {
                 ELISE_ASSERT((k>=0)&&(k<_nb),"out index in ElFifo<Type>::[]");
                 return  _tab[(_begin+_nb-1-k)%_capa];
             }
        }



        ~ElFifo() 
         { 
            del_tab();
         }

        Type     popfirst()
        {
             ELISE_ASSERT(_nb!=0,"empty  ElFifo<Type>::[]");
             Type res = _tab[_begin];
             _begin = (_begin+1)%_capa;
             _nb--;
             return res;
        }
		void pop_front() {_begin = (_begin+1)%_capa; _nb--;}
        Type  poplast()
        {
             ELISE_ASSERT(_nb!=0,"empty  ElFifo<Type>::[]");
             Type res = _tab[(_begin+_nb-1)%_capa];
             _nb--;
             return res;
        }
		void  pop_back() {_nb--;}

        void   push_back(const Type & p)
        {
             if (_nb == _capa) incr_capa();
             _tab[(_begin+_nb++)%_capa] = p;
        }
        void   pushlast(const Type & p){push_back(p);}


        void   push_front(const Type & p)
        {
            if (_nb == _capa) incr_capa();
            _nb ++;
            _begin--;
            if (_begin<0)
               _begin += _capa;
            _tab[_begin] = p;
        }
        void   pushfirst(const Type & p){push_front(p);}

        void   push(const Type & p,bool in_last)
        {
              if (in_last) 
                 pushlast(p);
              else
                 pushfirst(p);
        }
};

#endif
