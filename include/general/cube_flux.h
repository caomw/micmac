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



#ifndef _ELISE_GENERAL_CUBE_FLUX_H_
#define _ELISE_GENERAL_CUBE_FLUX_H_



class cNappe2DGen
{
      public :

         int Sz() const   {return mSz;}
	 int YMin(int anX)  const {return mDataYMin[anX];}
	 int YMax(int anX)  const {return mDataYMax[anX];}
	 int NbObj () const {return mNbObj;}

	 int NbInCol(const int & anX) const 
	 {
              return YMax(anX)-YMin(anX);
	 }



         void Resize(int  aSz,Fonc_Num aYMin,Fonc_Num aYMax);
         cNappe2DGen(int  aSz,Fonc_Num aYMin,Fonc_Num aYMax);

	 bool Inside(Pt2di aPt) const
	 {
		 return (aPt.x>=0)
                    &&  (aPt.x<mSz)
                    &&  (aPt.y>=mDataYMin[aPt.x])
                    &&  (aPt.y< mDataYMax[aPt.x]);
	 }

	 int OffsetPt(Pt2di aPt) const 
	 {
              return mDataOffset[aPt.x] +aPt.y;
	 }

	 // Offset de la colone pour y=0
	 int OffsetCol(int anX) const 
	 {
              return mDataOffset[anX];
	 }

      private :


         int         mSz;
	 Im1D_int4   mIYMin;
	 int4 *      mDataYMin;
	 Im1D_int4   mIYMax;
	 int4 *      mDataYMax;
         Im1D_int4   mIOffset;
         int4  *     mDataOffset;
         int         mNbObj;
};


template <class Type> class cTplNape2D : public cNappe2DGen
{
      public :
        typedef Type  value_type;

	~cTplNape2D() {delete [] mData;}
        cTplNape2D
	(
	     int      aSz,
	     Fonc_Num aYMin,
	     Fonc_Num aYMax,
             int      aNbObjMin=0
	)  :
	 cNappe2DGen(aSz,aYMin,aYMax),
                    mNbObjMem (ElMax(NbObj(),aNbObjMin)),
	            mData (new Type[mNbObjMem])
        {
	}
	Type & El(Pt2di aPt) {return mData[OffsetPt(aPt)];}
	// Retourne l'adresse de la colonne pour y = 0
	Type * Colum(int anX) {return mData+OffsetCol(anX);}

         void Resize(int aSz,Fonc_Num aZMin,Fonc_Num aZMax)
	 {
             cNappe2DGen::Resize(aSz,aZMin,aZMax);
	     if (NbObj() > mNbObjMem)
	     {
                 mNbObjMem = NbObj();
		 delete [] mData;
	         mData =new Type[NbObj()];
	     }
	 }

      private :
	int     mNbObjMem;
        Type  * mData;
};




class cNappe3DGen
{
      public :

         Pt2di Sz() const   {return mSz;}
	 int tx()     const {return mSz.x;}
	 int ty()     const {return mSz.y;}
	 int ZMin(Pt2di aP)  const {return mDataZMin[aP.y][aP.x];}
	 int ZMax(Pt2di aP)  const {return mDataZMax[aP.y][aP.x];}
	 int NbObj () const {return mNbObj;}

	 Fonc_Num ZMin(){return mIZMin.in();}
	 Fonc_Num ZMax(){return mIZMax.in();}

         Pt3di PMin(Pt2di aP) const {return Pt3di(aP.x,aP.y,ZMin(aP));}

         void Resize(Pt2di aSz,Fonc_Num aZMin,Fonc_Num aZMax);
         cNappe3DGen(Pt2di aSz,Fonc_Num aZMin,Fonc_Num aZMax);

	 bool Inside(const Pt3di & aPt) const
	 {
		 return (aPt.x>=0)
                    &&  (aPt.y>=0)
                    &&  (aPt.x<mSz.x)
                    &&  (aPt.y<mSz.y)
                    &&  (aPt.z>=mDataZMin[aPt.y][aPt.x])
                    &&  (aPt.z< mDataZMax[aPt.y][aPt.x]);
	 }

	 bool ZInside(const Pt3di & aPt) const
	 {
                    return   (aPt.z>=mDataZMin[aPt.y][aPt.x])
                    &&  (aPt.z< mDataZMax[aPt.y][aPt.x]);
	 }

	 bool Inside(const Pt2di & aPt) const
	 {
		 return (aPt.x>=0)
                    &&  (aPt.y>=0)
                    &&  (aPt.x<mSz.x)
                    &&  (aPt.y<mSz.y);
	 }

	 int OffsetPt(const Pt3di & aPt) const 
	 {
              return mDataOffset[aPt.y][aPt.x] +aPt.z;
	 }

	 int OffsetPMin(const Pt2di & aPt) const 
	 {
              return mDataOffset[aPt.y][aPt.x] +ZMin(aPt);
	 }
	 int OffsetPMax(const Pt2di & aPt) const 
	 {
              return mDataOffset[aPt.y][aPt.x] +ZMax(aPt)-1;
	 }

	 int NbInCol(const Pt2di & aPt) const 
	 {
              return ZMax(aPt)-ZMin(aPt);
	 }

      private :


         Pt2di       mSz;
	 Im2D_int2   mIZMin;
	 int2 *      mLineZMin;
	 int2 **     mDataZMin;
	 Im2D_int2   mIZMax;
	 int2 *      mLineZMax;
	 int2 **     mDataZMax;
         Im2D_int4   mIOffset;
	 int4 *      mLineOffset;
         int4 **     mDataOffset;
         int         mNbObj;
};







template <class Type> class cTplNape3D : public cNappe3DGen
{
      public :
        typedef Type  value_type;

	~cTplNape3D() {delete [] mData;}
        cTplNape3D
	(
	     Pt2di aSz,
	     Fonc_Num aZMin,
	     Fonc_Num aZMax,
             int      aNbObjMin=0
	)  :
	 cNappe3DGen(aSz,aZMin,aZMax),
                    mNbObjMem (ElMax(NbObj(),aNbObjMin)),
	            mData (new Type[mNbObjMem])
        {
	}
//      const Type& El(Pt3di aPt) const {return *(mData+OffsetPt(aPt));}
	Type & El(const Pt3di & aPt) {return mData[OffsetPt(aPt)];}
	Type & El0(const Pt2di & aPt) {return mData[OffsetPMin(aPt)];}
	Type & El1(const Pt2di & aPt) {return mData[OffsetPMax(aPt)];}
	Type & El(int  aK)   {return mData[aK];}

         void Resize(Pt2di aSz,Fonc_Num aZMin,Fonc_Num aZMax)
	 {
             cNappe3DGen::Resize(aSz,aZMin,aZMax);
	     if (NbObj() > mNbObjMem)
	     {
                 mNbObjMem = NbObj();
		 delete [] mData ;
	         mData =new Type[NbObj()];
	     }
	 }

      private :
	int     mNbObjMem;
        Type  * mData;
        cTplNape3D(const cTplNape3D&);
};

struct cCoxAlgoGenRelVois{
	 

	cCoxAlgoGenRelVois(Pt3di,bool,bool,int,bool,int);
		 Pt3di mPt;
		 bool  mVert;
		 bool  mDirect;
		 int   mNumFlow;
		 bool  mV4;
		 int   mSym;
	 } ;
class cCoxAlgoGen
{
     public :
   
         cCoxAlgoGen
         (
	     int aCostRegul,
	     int aCostV8,
             Pt2di aSz
         );

	 
 // protected :
       static const cCoxAlgoGenRelVois TheVois[10];
       void NewOrder(Pt2di aP0,Pt2di aP1);


       int    mCostV4;
       int    mCostV8;
       int    mOrder;

       int    mDx;
       int    mDy;
       int    mX0;
       int    mX1;
       int    mY0;
       int    mY1;
};



class cLineMapRect
{
     public :
         typedef std::vector<Pt2di> tContPts;

         const tContPts * Next();

         ~cLineMapRect();

         cLineMapRect(Pt2di SzMax);
         void Init(Pt2di u,Pt2di p0,Pt2di p1);

     private :

           cLineMapRect(const cLineMapRect &);  // Non Def

           class Line_Map_Rect_Comp * mPLMRP;
           tContPts             mCPts;

};


class cInterfaceCoxAlgo
{
    public :
         virtual void SetCost(Pt3di aP, int aCost) = 0;
         virtual int PccMaxFlow() =0;
         virtual int NbChem() =0;
	 virtual void Reinit() =0;
	 virtual ~cInterfaceCoxAlgo();
	 virtual Im2D_int2  Sol(int aDef) =0;

         static  cInterfaceCoxAlgo * StdNewOne        
                 (
                          Pt2di    aSz,
                          Fonc_Num aZMin,
                          Fonc_Num aZMax,
                          int      aCostRegul,
                          bool     V8 = false
                    ) ;

};


Im2D_int2  TestCoxRoy
           (
                int         aSzV,
                Im2D_U_int1 imG1,
                Im2D_U_int1 imG2,
                Pt2di       aP0,
                Pt2di       aP1,
                int         aParMin,
                int         aParMax
           );



#endif // _ELISE_GENERAL_CUBE_FLUX_H_

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
