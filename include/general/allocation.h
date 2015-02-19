/*Header-MicMac-eLiSe-25/06/2007

    MicMac : Multi Image Correspondances par Methodes Automatiques de Correlation
    eLiSe  : ELements of an Image Software Environnement

    www.micmac.ign.fr


    Copyright : Institut Geographique National
    Author : Marc Pierrot Deseilligny
    Contributors : Gregoire Maillet, Didier Boldo.

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

#ifndef _ELISE_ALLOCATION_H
#define _ELISE_ALLOCATION_H

#include <general/sys_dep.h>

#include <cstddef>
#include <cstdlib>
#include <list>

class  Mcheck
{
public :
    void * operator new    (std::size_t sz);
    void operator delete   (void * ptr) ;

private :

    // to avoid use
    void * operator new []  (std::size_t sz);
    void operator delete [] (void * ptr) ;
};

    template <const INT NBB> class  ElListAlloc
    {
        public :
        void * get()
        {
            if (_l.empty())
                _l.push_back(std::malloc(NBB));
            void * res = _l.front();
            _l.pop_front();
            return res;
        }
        void  put(void * v)
        {
            _l.push_front(v);
        }
        void purge()
        {
            while (! _l.empty())
            {
                free(_l.front());
                _l.pop_front();
            }
        }

        private :
        std::list<void *> _l;
    };


    /*******************************************************************/
    /*                                                                 */
    /*        Classes for garbage collection                           */
    /*                                                                 */
    /*******************************************************************/

    /*
    Class RC_Object :

         References Counting Object
*/


    class RC_Object : public Mcheck
    {

        friend void decr_ref(class Object_cptref * oc);
        friend class PRC0;


    protected :

        RC_Object();
        virtual ~RC_Object();

        //---- data ----
        union
        {
            int            cpt_ref;
            RC_Object * next;
        }    _d;

    private :



        // declared as static so that they can be called with 0

        static void decr_ref(RC_Object *);
    public :
        static void incr_ref(RC_Object *);

    };

    /*
    Class PRC0 :

         Pointer to References Counting Object
*/

    class PRC0
    {

    public :


        // big three :

        PRC0 (const PRC0&);
        ~PRC0(void) ;
        void operator=(const PRC0 &p2);



        void * ptr(){return _ptr;}
        PRC0 (RC_Object *) ;

    protected :

        inline PRC0(){_ptr=0;};

        //-------- data ----------

        RC_Object     * _ptr;

    private :
        static  void decr_ref(RC_Object * oc);

        // just to avoid use  :
        // PRC0 * operator &();
    };




#endif //  ! _ELISE_ALLOCATION_H 
