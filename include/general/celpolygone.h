#ifndef _ELISE_GENERAL_GEOM_VECTEUR_CELPOLYGONE_H
#define _ELISE_GENERAL_GEOM_VECTEUR_CELPOLYGONE_H



class cElPolygone
{
    public :
       typedef std::vector<Pt2dr> tContour;
       typedef const std::list<tContour>  tConstLC;
       typedef std::list<tContour>::const_iterator  tItConstLC;

       void AddContour(const tContour &,bool isHole);
       cElPolygone();
       cElPolygone (const gpc_polygon &);
       struct gpc_polygon ToGPC() const;

       const std::list<tContour> & Contours() const;
       const std::list<bool> &     IsHole();
       tContour  ContSMax() const;


       cElPolygone operator * (const cElPolygone & aPol)  const;
       cElPolygone operator + (const cElPolygone & aPol)  const;
       cElPolygone operator - (const cElPolygone & aPol)  const;
       cElPolygone operator ^ (const cElPolygone & aPol)  const;

       double Surf() const;
       double DiamSimple() const;  // Suppose que existe surf englob

    private  :
       cElPolygone GenOp(const cElPolygone & aPol,int)const;

       std::list<tContour>   mContours;
       std::list<bool>       mIsHole;
};

#endif
