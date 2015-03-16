#ifndef _ELISE_GENERAL_PHOTOGRAM_CPACKNUPLETSHOM_H
#define _ELISE_GENERAL_PHOTOGRAM_CPACKNUPLETSHOM_H



class cPackNupletsHom
{
public :
    typedef std::list<cNupletPtsHomologues>   tCont;
    typedef tCont::iterator                  tIter;
    typedef tCont::const_iterator            tCstIter;
    cPackNupletsHom(int aDim);

    void write(class  ELISE_fp & aFile) const;
    static cPackNupletsHom read(ELISE_fp & aFile);
    typedef tCont::iterator         iterator;
    typedef tCont::const_iterator   const_iterator;

    cNupletPtsHomologues & back();
    const cNupletPtsHomologues & back() const;

    iterator       begin();
    const_iterator begin() const;
    iterator       end();
    const_iterator end() const;
    int size() const ;
    void clear();

    void AddNuplet(const cNupletPtsHomologues &);

    const cNupletPtsHomologues * Nuple_Nearest(Pt2dr aP,int aK) const;
    void  Nuple_RemoveNearest(Pt2dr aP,int aK) ;

    const ElPackHomologue & ToPckCple() const;

protected :
    tCont::iterator  NearestIter(Pt2dr aP,int aK);
private :
    tCont mCont;
    int   mDim;
};

#endif
