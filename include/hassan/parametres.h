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
#ifndef _HASSAN_PARAMETRES_H
#define _HASSAN_PARAMETRES_H

class Parametres_reconstruction_batiment
{
     public :

        
        Parametres_reconstruction_batiment();
        ostream& operator >>(ostream& os);
        istream& operator <<(istream& is);

        void     set_mode(int m)              {_mode = m;}
        void     set_afficher(bool a)         {_afficher = a;}
        void     set_enregistrer(bool e)      {_enregistrer = e;}
        void     set_mne_noyau(bool mn)       {_mne_noyau = mn;}

        void     set_repertoir(string& rep)   {_repertoir = rep;} 
        void     set_cad_file(string& cf)     {_cad_file = cf;}
        void     set_mne_file(string& mf)     {_mne_file = mf;}
        void     set_cube_header(string& ch)  {_cube_header = ch;}
        void     set_phot_a(string& pa)       {_phot_a = pa;}
        void     set_phot_b(string& pb)       {_phot_b = pb;}
        void     set_toits_file(string& tf)   {_toits_file = tf;}
        void     set_facades_file(string& ff) {_facades_file = ff;}
        void     set_batis_file(string& bf)   {_batis_file = bf;}

        void     set_sdng(int sdng)           {_sdng = sdng;}       
        void     set_pas(double_t pxy)            {_pas = pxy;}
        void     set_pas_z(double_t pz)           {_pas_z = pz;}
        void     set_z_sol(double_t zs)           {_z_sol = zs;}

        void     set_seuil_pente(double_t sp)     {_seuil_pente = sp;}
        void     set_seuil_z_min1(double_t szm1)  {_seuil_z_min1 = szm1;} 
        void     set_seuil_z_max1(double_t szm1)  {_seuil_z_max1 = szm1;}
        void     set_seuil_z_min2(double_t szm2)  {_seuil_z_min2 = szm2;}
        void     set_seuil_z_max2(double_t szm2)  {_seuil_z_max2 = szm2;}

        void     set_long_min(double_t lm)        {_long_min = lm;}
        void     set_d_teta_min(double_t dtm)     {_d_teta_min = dtm;}

        void     set_d_teta(double_t dt)          {_d_teta = dt;}
        void     set_d_phi(double_t dp)           {_d_phi  = dp;}
        void     set_d_rho(double_t dr)           {_d_rho  = dr;}
        void     set_nb_max_loc(int nml)      {_nb_max_loc = nml;}
        void     set_phi_min(double_t pm)         {_phi_min  = pm;}
        void     set_phi_max(double_t pm)         {_phi_max  = pm;}

        void     set_angl_min(double_t am)        {_angl_min = am;}
        void     set_dist_min(double_t dm)        {_dist_min = dm;}
        void     set_decal_max(double_t dm)       {_decal_max = dm;}
        void     set_test_stab(int ts)        {_test_stab = ts;}                    
        
        void     set_nb_p_mne_min(double_t npmm)  {_nb_p_mne_min = npmm;}
        void     set_nb_p_mne_moy(double_t npmm)  {_nb_p_mne_moy = npmm;}
        void     set_nb_p_mne_max(double_t npmm)  {_nb_p_mne_max = npmm;}
        void     set_nb_p_mne_pas(double_t npmp)  {_nb_p_mne_pas = npmp;}

        void     set_nb_plans_min(int npm)    {_nb_plans_min = npm;}
        void     set_nb_plans_sup(int nps)    {_nb_plans_sup = nps;}

        void     set_decal_max_poids_facet_graphe(int dm){_decal_max_poids_facet_graphe = dm;}
        void     set_test_stab_poids_facet_graphe(int ts){_test_stab_poids_facet_graphe = ts;}

        void     set_alpha(double_t a)            {_alpha = a;}
        void     set_seuil_sup(double_t ss)       {_seuil_sup = ss;}   
        void     set_seuil_inf(double_t si)       {_seuil_inf = si;}
        void     set_complexite(int c)        {_complexite = c;}
        void     set_beta1(double_t b1)           {_beta1 = b1;}
        void     set_beta2(double_t b2)           {_beta2 = b2;}
        void     set_nb_sol_gardee(int nsg)   {_nb_sol_gardee = nsg;}
        void     set_type_correlation(int tc) {_type_correlation = tc;}
        void     set_prop_file(string pf)     {_prop_file = pf;}
        void     set_resolution_image(bool ri){_resolution_image = ri;}



        int      mode()            {return _mode;}
        bool     afficher()        {return _afficher;}
        bool     enregistrer()     {return _enregistrer;}
        bool     mne_noyau()       {return _mne_noyau;}

        string   repertoir()       {return _repertoir;}
        string   cad_file()        {return _cad_file;}
        string   mne_file()        {return _mne_file;}
        string   cube_header()     {return _cube_header;}
        string   phot_a()          {return _phot_a;}
        string   phot_b()          {return _phot_b;}
        string   toits_file()      {return _toits_file;}
        string   facades_file()    {return _facades_file;}
        string   batis_file()      {return _batis_file;}

        int      sdng()            {return _sdng;}
        double_t     pas()             {return _pas;}
        double_t     pas_z()           {return _pas_z;}
        double_t     z_sol()           {return _z_sol;}
        double_t     seuil_pente()     {return _seuil_pente;}
        double_t     seuil_z_min1()    {return _seuil_z_min1;}
        double_t     seuil_z_max1()    {return _seuil_z_max1;}
        double_t     seuil_z_min2()    {return _seuil_z_min2;}
        double_t     seuil_z_max2()    {return _seuil_z_max2;}
        double_t     long_min()        {return _long_min;}
        double_t     d_teta_min()      {return _d_teta_min;}

        double_t     d_teta()          {return _d_teta;}
        double_t     d_phi()           {return _d_phi;}
        double_t     d_rho()           {return _d_rho;}
        int      nb_max_loc()      {return _nb_max_loc;}
        double_t     phi_min()         {return _phi_min;}
        double_t     phi_max()         {return _phi_max;}

        double_t     angl_min()        {return _angl_min;}
        double_t     dist_min()        {return _dist_min;}
        double_t     decal_max()       {return _decal_max;}
        int      test_stab()       {return _test_stab;}

        double_t     nb_p_mne_min()  {return _nb_p_mne_min;}
        double_t     nb_p_mne_moy()  {return _nb_p_mne_moy;}
        double_t     nb_p_mne_max()  {return _nb_p_mne_max;}
        double_t     nb_p_mne_pas()  {return _nb_p_mne_pas;}

        int      nb_plans_min()    {return _nb_plans_min;}
        int      nb_plans_sup()    {return _nb_plans_sup;}

        int      decal_max_poids_facet_graphe(){return _decal_max_poids_facet_graphe;}
        int      test_stab_poids_facet_graphe(){return _test_stab_poids_facet_graphe;}

        double_t     alpha()            {return _alpha;}
        double_t     seuil_sup()        {return _seuil_sup;}
        double_t     seuil_inf()        {return _seuil_inf;}
        int      complexite()       {return _complexite;}

        double_t     beta1()            {return _beta1;}
        double_t     beta2()            {return _beta2;}

        int      nb_sol_gardee()    {return _nb_sol_gardee;}
        int      type_correlation() {return _type_correlation;}

        string   prop_file()        {return _prop_file;}
        bool     resolution_image() {return _resolution_image;}



        int  _mode;
        bool _afficher;
        bool _enregistrer;
        bool _mne_noyau;

        string _repertoir;
        string _cad_file;
        string _mne_file;
        string _cube_header;
        string _cube_data;
        string _phot_a;
        string _phot_b;
        string _toits_file;
        string _facades_file;
        string _batis_file;

        int  _sdng;
        double_t _pas;
        double_t _pas_z;
        int  _cor_fenet;

        double_t _z_sol;           //metre

                                       //parameteres de construir une boite

        double_t _seuil_pente;
        double_t _seuil_z_min1;
        double_t _seuil_z_max1;
        double_t _seuil_z_min2;
        double_t _seuil_z_max2;


        double_t _long_min;               //chercher des directions prinicipales
        double_t _d_teta_min;             //chercher des directions prinicipales 



        double_t _d_teta;                 //transforme de hough
        double_t _d_phi;                  //transforme de hough
        double_t _d_rho;                  //transforme de hough
        int  _nb_max_loc;             //transforme de hough
        double_t _phi_min;                //transforme de hough
        double_t _phi_max;                //transforme de hough


                                 //filtrage de plans




        double_t _angl_min;               //degree
        double_t _dist_min;               //metre
        double_t _decal_max;              //distance maximale entre un plan et un point de mne
        int  _test_stab;              //taille d'element de fermeture



        double_t _nb_p_mne_min;           //en sqr metre
        double_t _nb_p_mne_moy;           //en sqr metre
        double_t _nb_p_mne_max;           //en sqr metre
        double_t _nb_p_mne_pas;           //en sqr metre

        int _nb_plans_min;
        int _nb_plans_sup;



                                      //pour calculer les poids a partir de MNE


        int _decal_max_poids_facet_graphe;
        int _test_stab_poids_facet_graphe;


        double_t _alpha;                    //optimisation noyaux et relaxation
        double_t _seuil_sup;                //le poids minimal no risque
        double_t _seuil_inf;                //le poids minimal no risque
        int _complexite;                // > 60 temp de calcul est expo

        double_t _beta1;                     //crit�re geo ( fenet horisntale )
        double_t _beta2;                     //crit�re geo ( fenet adaptative )
        int _nb_sol_gardee;              // n premieres solutions ( fenet hor )
        int _type_correlation;           //type de correlation : 
                                             //  1 : fenet adap(cent et norm)
                                             //  2 : fenet adap(no cent et norm)
                                             //  3 : corr model(cent et norm)
                                             //  4 : corr model(no cent et norm)
        string _prop_file;
        bool _resolution_image;
};

#endif // _HASSAN_PARAMETRES_H

/*Footer-MicMac-eLiSe-25/06/2007

Ce logiciel est un programme informatique servant à la mise en
correspondances d'images pour la reconstruction du relief.

Ce logiciel est régi par la licence CeCILL-B soumise au droit français et
respectant les principes de diffusion des logiciels libres. Vous pouvez
utiliser, modifier et/ou redistribuer ce programme sous les conditions
de la licence CeCILL-B telle que diffusée par le CEA, le CNRS et l'INRIA 
sur le site "http://www.cecill.info".

En contrepartie de l'accessibilité au code source et des droits de copie,
de modification et de redistribution accordés par cette licence, il n'est
offert aux utilisateurs qu'une garantie limitée.  Pour les mêmes raisons,
seule une responsabilité restreinte pèse sur l'auteur du programme,  le
titulaire des droits patrimoniaux et les concédants successifs.

A cet égard  l'attention de l'utilisateur est attirée sur les risques
associés au chargement,  à l'utilisation,  à la modification et/ou au
développement et à la reproduction du logiciel par l'utilisateur étant 
donné sa spécificité de logiciel libre, qui peut le rendre complexe à 
manipuler et qui le réserve donc à des développeurs et des professionnels
avertis possédant  des  connaissances  informatiques approfondies.  Les
utilisateurs sont donc invités à charger  et  tester  l'adéquation  du
logiciel à leurs besoins dans des conditions permettant d'assurer la
sécurité de leurs systèmes et ou de leurs données et, plus généralement, 
à l'utiliser et l'exploiter dans les mêmes conditions de sécurité. 

Le fait que vous puissiez accéder à cet en-tête signifie que vous avez 
pris connaissance de la licence CeCILL-B, et que vous en avez accepté les
termes.
Footer-MicMac-eLiSe-25/06/2007*/
