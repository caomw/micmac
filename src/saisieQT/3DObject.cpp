#include "3DObject.h"
#include "SaisieGlsl.glsl"

cObject::cObject() :
    _name(""),
    _position(Pt3dr(0.f,0.f,0.f)),
    _rotation(Pt3dr(0.f,0.f,0.f)),
    _scale(Pt3dr(1.f, 1.f,1.f)),
    _alpha(0.6f),
    _state(state_default)
{
    for (int iC = 0; iC < state_COUNT; ++iC)
        _color[iC] = QColor(255,255,255);
}

cObject::cObject(Pt3dr pos, QColor color_default) :
    _name(""),
    _position(pos),
    _rotation(Pt3dr(0.f,0.f,0.f)),
    _scale(Pt3dr(1.f, 1.f,1.f)),
    _alpha(0.6f),
    _state(state_default)
{
    for (int iC = 0; iC < state_COUNT; ++iC)
        _color[iC] = color_default;
}

cObject::~cObject(){}

QColor cObject::getColor()
{
    return _color[state()];
}

cObject& cObject::operator =(const cObject& aB)
{
    if (this != &aB)
    {
        _name      = aB._name;
        _position  = aB._position;
        _rotation  = aB._rotation;

        for (int iC = 0; iC < state_COUNT; ++iC)
            _color[iC]     = aB._color[iC];

        _alpha     = aB._alpha;
        _state     = aB._state;

        _scale     = aB._scale;
    }

    return *this;
}
object_state cObject::state() const
{
    return _state;
}

void cObject::setState(object_state state)
{
    _state = state;
}

cCircle::cCircle(Pt3d<double> pt, QColor col, float scale, float lineWidth, bool vis, int dim) :
    _dim(dim)
{
    setPosition(pt);
    cObject::setColor(col);
    setScale(Pt3dr(scale,scale,scale));
    setLineWidth(lineWidth);
    cObject::setVisible(vis);
}

//draw a unit circle in a given plane (0=YZ, 1=XZ, 2=XY)
void glDrawUnitCircle(uchar dim, float cx, float cy, float r, int steps)
{
    float theta = 2.f * PI / float(steps);
    float c = cosf(theta); //precalculate the sine and cosine
    float s = sinf(theta);
//    float t;

    float x = r; //we start at angle = 0
    float y = 0;

    uchar dimX = (dim<2 ? dim+1 : 0);
    uchar dimY = (dimX<2 ? dimX+1 : 0);

    GLfloat P[3];

    for (int i=0;i<3;++i) P[i] = 0.0f;

    glBegin(GL_LINE_LOOP);
    for(int ii = 0; ii < steps; ii++)
    {
        P[dimX] = x + cx;
        P[dimY] = y + cy;
        glVertex3fv(P);

        //apply the rotation matrix
		float t = x;
        x = c * x - s * y;
        y = s * t + c * y;
    }
    glEnd();
}

void glDrawEllipse(float cx, float cy, float rx, float ry, int steps) // TODO step Auto....
{
	const float theta = 2.f * PI / float(steps);

    glBegin(GL_LINE_LOOP);
    for(float t = 0.f; t <= 2.f * PI; t+= theta)
    {

		const float x = cx + rx*sinf(t);
		const float y = cy + ry*cosf(t);

		glVertex3f(x,y,0.f);
    }
    glEnd();
}

void glDrawEllipsed(double cx, double cy, double rx, double ry, int steps) // TODO step Auto....
{
	const double theta = 2.f * PI / double(steps);

    glBegin(GL_LINE_LOOP);
    for(double t = 0.f; t <= 2.f * PI; t+= theta)
    {
		const float x = cx + rx*std::sin(t);
		const float y = cy + ry*std::cos(t);

		glVertex3d(x,y,0.f);
    }
    glEnd();
}

void cCircle::draw()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    GLuint list = glGenLists(1);
    glNewList(list, GL_COMPILE);

    glPushAttrib(GL_LINE_BIT | GL_DEPTH_BUFFER_BIT);

    glLineWidth(_lineWidth);

    setGLColor();

    glDrawUnitCircle(_dim);

    glPopAttrib();

    glEndList();

    glTranslatef(_position.x,_position.y,_position.z);
    glScalef(_scale.x,_scale.y,_scale.z);

    glCallList(list);

    glPopMatrix();
}

cCross::cCross(Pt3d<double> pt, QColor col, float scale, float lineWidth, bool vis, int dim) :
    _dim(dim)
{
    setPosition(pt);
    cObject::setColor(col);
    setScale(Pt3dr(scale, scale, scale));
    setLineWidth(lineWidth);
    cObject::setVisible(vis);
}

void cCross::draw()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    GLuint list = glGenLists(1);
    glNewList(list, GL_COMPILE);

    glPushAttrib(GL_LINE_BIT | GL_DEPTH_BUFFER_BIT);

    glLineWidth(_lineWidth);

    setGLColor();

    float x1, x2, y1, y2, z1, z2;
    x1 = x2 = y1 = y2 = z1 = z2 = 0.f;

    if (_dim == 0)
    {
        x1 =-1.f;
        x2 = 1.f;
    }
    else if (_dim == 1)
    {
        y1 =-1.f;
        y2 = 1.f;
    }
    else if (_dim == 2)
    {
        z1 =-1.f;
        z2 = 1.f;
    }

    glBegin(GL_LINES);
    glVertex3f(x1,y1,z1);
    glVertex3f(x2,y2,z2);
    glEnd();
    glPopAttrib();

    glEndList();

    glTranslatef(_position.x,_position.y,_position.z);
    glScalef(_scale.x,_scale.y,_scale.z);

    glCallList(list);

    glPopMatrix();
}

cBall::cBall(Pt3dr pt, float scale, bool isVis, float lineWidth)
{
    cObject::setVisible(isVis);

    _cl0 = new cCircle(pt, QColor(255,0,0),   scale, lineWidth, isVis, 0);
    _cl1 = new cCircle(pt, QColor(0,255,0),   scale, lineWidth, isVis, 1);
    _cl2 = new cCircle(pt, QColor(0,178,255), scale, lineWidth, isVis, 2);

    _cr0 = new cCross(pt, QColor(255,0,0),   scale, lineWidth, isVis, 0);
    _cr1 = new cCross(pt, QColor(0,255,0),   scale, lineWidth, isVis, 1);
    _cr2 = new cCross(pt, QColor(0,178,255), scale, lineWidth, isVis, 2);
}

cBall::~cBall()
{
    delete _cl0;
    delete _cl1;
    delete _cl2;

    delete _cr0;
    delete _cr1;
    delete _cr2;
}

void cBall::draw()
{
    if (isVisible())
    {
        _cl0->draw();
        _cl1->draw();
        _cl2->draw();

        _cr0->draw();
        _cr1->draw();
        _cr2->draw();
    }
}

void cBall::setPosition(Pt3dr const &aPt)
{
    _cl0->setPosition(aPt);
    _cl1->setPosition(aPt);
    _cl2->setPosition(aPt);

    _cr0->setPosition(aPt);
    _cr1->setPosition(aPt);
    _cr2->setPosition(aPt);
}

Pt3dr cBall::getPosition()
{
    return _cl0->getPosition();
}

void cBall::setVisible(bool aVis)
{
    cObject::setVisible(aVis);
    //_bVisible = aVis;

    _cl0->setVisible(aVis);
    _cl1->setVisible(aVis);
    _cl2->setVisible(aVis);

    _cr0->setVisible(aVis);
    _cr1->setVisible(aVis);
    _cr2->setVisible(aVis);
}

void cBall::setScale(Pt3dr aScale)
{
    _cl0->setScale(aScale);
    _cl1->setScale(aScale);
    _cl2->setScale(aScale);

    _cr0->setScale(aScale);
    _cr1->setScale(aScale);
    _cr2->setScale(aScale);
}

cAxis::cAxis(Pt3dr pt, float scale, float lineWidth)
{
    _position = pt;
    _scale    = Pt3dr(scale, scale, scale);
    setLineWidth(lineWidth);
}

void cAxis::draw()
{
    if (isVisible())
    {
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();

        GLuint dihedron = glGenLists(1);
        glNewList(dihedron, GL_COMPILE);

        glPushAttrib(GL_LINE_BIT | GL_DEPTH_BUFFER_BIT);

        glLineWidth(_lineWidth);

        glBegin(GL_LINES);
        glColor3f(1.0f,0.0f,0.0f);
        glVertex3f(0.0f,0.0f,0.0f);
        glVertex3f(0.4f,0.0f,0.0f);
        glColor3f(0.0f,1.0f,0.0f);
        glVertex3f(0.0f,0.0f,0.0f);
        glVertex3f(0.0f,0.4f,0.0f);
        glColor3f(0.0f,0.7f,1.0f);
        glVertex3f(0.0f,0.0f,0.0f);
        glVertex3f(0.0f,0.0f,0.4f);
        glEnd();

        glPopAttrib();

        glEndList();

        glTranslatef(_position.x,_position.y,_position.z);
        glScalef(_scale.x,_scale.y,_scale.z);

        glCallList(dihedron);

        glPopMatrix();
    }
}

cBBox::cBBox(Pt3dr pt, Pt3dr min, Pt3dr max, float lineWidth)
{
    _position = pt;
    _min = min;
    _max = max;

    cObject::setColor(QColor("orange"));
    setLineWidth(lineWidth);
}

void cBBox::set(Pt3dr min, Pt3dr max)
{
    _min = min;
    _max = max;
}

void cBBox::draw()
{
    if (isVisible())
    {
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();

        GLuint list = glGenLists(1);
        glNewList(list, GL_COMPILE);

        glPushAttrib(GL_LINE_BIT|GL_DEPTH_BUFFER_BIT);

        glLineWidth(_lineWidth);

        setGLColor();

        Pt3dr P1(_min);
        Pt3dr P2(_min.x, _min.y, _max.z);
        Pt3dr P3(_min.x, _max.y, _max.z);
        Pt3dr P4(_min.x, _max.y, _min.z);
        Pt3dr P5(_max.x, _min.y, _min.z);
        Pt3dr P6(_max.x, _max.y, _min.z);
        Pt3dr P7(_max);
        Pt3dr P8(_max.x, _min.y, _max.z);

        glBegin(GL_LINES);

        glVertex3d(P1.x, P1.y, P1.z);
        glVertex3d(P2.x, P2.y, P2.z);

        glVertex3d(P3.x, P3.y, P3.z);
        glVertex3d(P2.x, P2.y, P2.z);

        glVertex3d(P1.x, P1.y, P1.z);
        glVertex3d(P4.x, P4.y, P4.z);

        glVertex3d(P1.x, P1.y, P1.z);
        glVertex3d(P5.x, P5.y, P5.z);

        glVertex3d(P7.x, P7.y, P7.z);
        glVertex3d(P3.x, P3.y, P3.z);

        glVertex3d(P7.x, P7.y, P7.z);
        glVertex3d(P6.x, P6.y, P6.z);

        glVertex3d(P8.x, P8.y, P8.z);
        glVertex3d(P5.x, P5.y, P5.z);

        glVertex3d(P7.x, P7.y, P7.z);
        glVertex3d(P8.x, P8.y, P8.z);

        glVertex3d(P5.x, P5.y, P5.z);
        glVertex3d(P6.x, P6.y, P6.z);

        glVertex3d(P4.x, P4.y, P4.z);
        glVertex3d(P6.x, P6.y, P6.z);

        glVertex3d(P8.x, P8.y, P8.z);
        glVertex3d(P2.x, P2.y, P2.z);

        glVertex3d(P4.x, P4.y, P4.z);
        glVertex3d(P3.x, P3.y, P3.z);

        glEnd();

        glPopAttrib();

        glEndList();

        glCallList(list);

        glPopMatrix();
    }
}

cCam::cCam(CamStenope *pCam, float scale,  object_state state, float lineWidth) :
    _pointSize(5.f),
    _Cam(pCam)
{
    _scale = Pt3dr(scale, scale, scale);

    setState(state);
    cObject::setColor(QColor("red"));
    cObject::setColor(QColor(0.f,0.f,1.f),state_selected);
    setLineWidth(lineWidth);
}

void cCam::draw()
{
    if (isVisible())
    {

        GLfloat oldPointSize;
        glGetFloatv(GL_POINT_SIZE,&oldPointSize);

//        glMatrixMode(GL_MODELVIEW);
//        glPushMatrix();

        GLuint list = glGenLists(1);
        glNewList(list, GL_COMPILE);

        glPushAttrib(GL_LINE_BIT|GL_DEPTH_BUFFER_BIT);

        glLineWidth(_lineWidth);

        glPointSize(_pointSize);

        Pt3dr C  = _Cam->VraiOpticalCenter();
        Pt3dr P1, P2, P3, P4;
        _Cam->Coins(P1, P2, P3, P4, _scale.z*.05f);

        glBegin(GL_LINES);
        //perspective cone
        if(!isSelected())
            glColor3f(1.f,1.f,1.f);
        else
        {
            QColor color = Qt::yellow;
            glColor3f(color.redF(),color.greenF(),color.blueF());
        }

        glVertex3d(C.x, C.y, C.z);
        glVertex3d(P1.x, P1.y, P1.z);

        glVertex3d(C.x, C.y, C.z);
        glVertex3d(P2.x, P2.y, P2.z);

        glVertex3d(C.x, C.y, C.z);
        glVertex3d(P3.x, P3.y, P3.z);

        glVertex3d(C.x, C.y, C.z);
        glVertex3d(P4.x, P4.y, P4.z);

        //Image

        setGLColor();

        glVertex3d(P1.x, P1.y, P1.z);
        glVertex3d(P2.x, P2.y, P2.z);

        glVertex3d(P4.x, P4.y, P4.z);
        glVertex3d(P2.x, P2.y, P2.z);

        glVertex3d(P3.x, P3.y, P3.z);
        glVertex3d(P1.x, P1.y, P1.z);

        glVertex3d(P4.x, P4.y, P4.z);
        glVertex3d(P3.x, P3.y, P3.z);
        glEnd();

        glBegin(GL_POINTS);
        glVertex3d(C.x, C.y, C.z);
        glEnd();

        glEndList();

        glPopAttrib();

        glCallList(list);

 //       glPopMatrix();
        glPointSize(oldPointSize);
    }
}

cPoint::cPoint(QPointF pos,
               QString name, bool showName,
               int state,
               bool isSelected,
               QColor color, QColor selectionColor,
               float diameter,
               bool highlight,
               bool drawCenter):
    QPointF(pos),
    _diameter(diameter),
    _bShowName(showName),
    _pointState(state),
    _highlight(highlight),
    _drawCenter(drawCenter),
    _bEpipolar(false)
{
    setName(name);
    cObject::setColor(color);
    cObject::setColor(selectionColor,state_selected);
    setSelected(isSelected);
}

QColor cPoint::colorPointState()
{

    QColor color = getColor();

    if (!isSelected())
    {
        switch(_pointState)
        {
        case eEPI_NonSaisi :
            color = Qt::yellow;
            break;

        case eEPI_Refute :
            color = Qt::red;
            break;

        case eEPI_Douteux :
            color = QColor(255, 127, 0, 255);
            break;

        case eEPI_Valide :
            color = Qt::green;
            break;

        case eEPI_Disparu  :
        case eEPI_NonValue :
            break;
        }
    }

    return color;
}

void cPoint::draw()
{
    if (isVisible())
    {

        QColor color = colorPointState();

        glColor4f(color.redF(),color.greenF(),color.blueF(),_alpha);

        GLdouble    mvMatrix[16];
        GLdouble    projMatrix[16];
        GLint       glViewport[4];

        glGetIntegerv(GL_VIEWPORT, glViewport);
        glMatrixMode(GL_PROJECTION);
        glGetDoublev (GL_PROJECTION_MATRIX, projMatrix);
        glPushMatrix();
        glLoadIdentity();
        glTranslatef(-1.f,-1.f,0.f);
        glScalef(2.f/(float)glViewport[2],2.f/(float)glViewport[3],1.f);
        glMatrixMode(GL_MODELVIEW);
        glGetDoublev(GL_MODELVIEW_MATRIX, mvMatrix);
        glPushMatrix();
        glLoadIdentity();

        GLdouble xp,yp,zp;

        mmProject(x(),y(),0,mvMatrix,projMatrix,glViewport,&xp,&yp,&zp);

        glDrawEllipsed(xp, yp, _diameter, _diameter,16);

        if (_drawCenter)
        {
            glBegin(GL_POINTS);
                glVertex2d(xp, yp);
            glEnd( );
        }

        if (_highlight && ((_pointState == eEPI_Valide) || (_pointState == eEPI_NonSaisi)))
        {
            if (_bEpipolar)
            {
                GLdouble x1,y1,z1,x2,y2,z2;

                mmProject(_epipolar1.x(), _epipolar1.y(),0,mvMatrix,projMatrix,glViewport,&x1,&y1,&z1);
                mmProject(_epipolar2.x(), _epipolar2.y(),0,mvMatrix,projMatrix,glViewport,&x2,&y2,&z2);

                glBegin(GL_LINES);
                    glVertex2f(x1,y1);
                    glVertex2f(x2,y2);
                glEnd();
            }
            else
                glDrawEllipse( xp, yp, 2.f*_diameter, 2.f*_diameter);
        }

        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
        glPopMatrix();
    }
}

void cPoint::setEpipolar(QPointF pt1, QPointF pt2)
{
    _epipolar1 = pt1;
    _epipolar2 = pt2;
    _bEpipolar = true;
}

void cPoint::glDraw()
{
    glVertex2f(x(),y());
}

//********************************************************************************

float cPolygon::_selectionRadius = 10.f;

cPolygon::cPolygon(int maxSz, float lineWidth, QColor lineColor, QColor pointColor, int style):
	_helper(new cPolygonHelper(this, 3, lineWidth)),
    _lineColor(lineColor),
    _idx(-1),
    _style(style),
    _pointDiameter(1.f),
    _bIsClosed(false),
    _bSelectedPoint(false),
    _bShowLines(true),
    _bShowNames(true),
    _maxSz(maxSz)
{
    setColor(pointColor);
	setLineWidth(lineWidth);
}

cPolygon::~cPolygon()
{
	if(_helper)
	{
		delete _helper;
	}
}

cPolygon::cPolygon(int maxSz, float lineWidth, QColor lineColor,  QColor pointColor, bool withHelper, int style):
    _lineColor(lineColor),
    _idx(-1),
    _style(style),
    _pointDiameter(1.f),
    _bIsClosed(false),
    _bSelectedPoint(false),
    _bShowLines(true),
    _bShowNames(true),
    _maxSz(maxSz)
{
    if (!withHelper) _helper = NULL;

    setColor(pointColor);
    setLineWidth(lineWidth);

    _dashes << 3 << 4;
}

void cPolygon::draw()
{
    for (int aK=0; aK < size();++aK)
        point(aK).draw();


    if(isVisible())
    {
        enableOptionLine();

        if (_bShowLines)
        {
            QColor color(isSelected() ? QColor(0,140,180) : _lineColor);

            glColor3f(color.redF(),color.greenF(),color.blueF());
            glLineWidth(_lineWidth);

            if(_style == LINE_STIPPLE)
            {
                glLineStipple(2, 0xAAAA);
                glEnable(GL_LINE_STIPPLE);
            }
            //draw segments
            glBegin(_bIsClosed ? GL_LINE_LOOP : GL_LINE_STRIP);
            for (int aK = 0;aK < size(); ++aK)
                point(aK).glDraw();
            glEnd();

            if(_style == LINE_STIPPLE) glDisable(GL_LINE_STIPPLE);

            glColor3f(_color[state_default].redF(),_color[state_default].greenF(),_color[state_default].blueF());
        }

        disableOptionLine();
    }


	if(helper() != NULL)
	{
		helper()->draw();
	}
}

cPolygon & cPolygon::operator = (const cPolygon &aP)
{
    if (this != &aP)
    {
        _lineWidth        = aP._lineWidth;
        _bIsClosed        = aP._bIsClosed;
        _idx              = aP._idx;

        _points           = aP._points;
        _pointDiameter    = aP._pointDiameter;
        _selectionRadius  = aP._selectionRadius;

        _bSelectedPoint   = aP._bSelectedPoint;
        _bShowLines       = aP._bShowLines;
        _bShowNames       = aP._bShowNames;

        _dashes.clear();
        for (int iC = 0; iC < aP._dashes.size(); ++iC)
            _dashes.push_back(aP._dashes[iC]);

        _style            = aP._style;
        _defPtName        = aP._defPtName;

        _shiftStep        = aP._shiftStep;
        _maxSz            = aP._maxSz;

        _bNormalize       = aP._bNormalize;
    }

    return *this;
}

void cPolygon::close()
{
    int sz = size();

    if ((sz>1)&&(!_bIsClosed))
    {
        //remove last point if needed
        if (sz > 2) _points.resize(sz-1);

        _bIsClosed = true;
    }

    _bSelectedPoint = false;
}

void cPolygon::removeNearestOrClose(QPointF pos)
{
    if (_bIsClosed)
    {
        removeSelectedPoint();

        findNearestPoint(pos);

        if (size() < 3) _bIsClosed = false;
    }
    else // close polygon
        close();
}

void cPolygon::removeSelectedPoint()
{
    if (pointValid())

        removePoint(_idx);
}

QString cPolygon::getSelectedPointName()
{
    if (pointValid())
    {
        return point(_idx).name();
    }
    else return _defPtName;
}

int cPolygon::getSelectedPointState()
{
    if (pointValid())
    {
        return point(_idx).pointState();
    }
    else return eEPI_NonValue;
}

void cPolygon::add(cPoint &pt)
{
    if (size() < _maxSz)
    {
        pt.setDiameter(_pointDiameter);
        _points.push_back(pt);
    }
}

// TODO pourquoi les fonctions : 2 add et addPoint?
void cPolygon::add(const QPointF &pt, bool selected)
{
    if (size() < _maxSz)
    {
        cPoint cPt( pt, _defPtName, _bShowNames, eEPI_NonValue, selected, _color[state_default],Qt::blue,_pointDiameter);

        cPt.drawCenter(!isLinear());

        _points.push_back(cPt);
    }
}

void cPolygon::addPoint(const QPointF &pt)
{
    if (size() >= 1)
    {
        cPoint cPt( pt, _defPtName, _bShowNames, eEPI_NonValue, false, _color[state_default]);
        cPt.setDiameter(_pointDiameter);

        cPt.drawCenter(!isLinear());

        point(size()-1) = cPoint(cPt);
    }

    add(pt);
}

void cPolygon::clear()
{
    _points.clear();
    _idx = -1;
    _bSelectedPoint = false;
    if(_bShowLines)_bIsClosed = false;
    if(_helper!=NULL) helper()->clear();
}

void cPolygon::insertPoint(int i, const QPointF &value)
{
    if (i <= size())
    {
        cPoint pt(value);
        pt.setDiameter(point(i-1).diameter());
        _points.insert(i, pt);
        resetSelectedPoint();
    }
}

void cPolygon::insertPoint()
{
    if ((size() >=2) && _helper->size()>1 && _bIsClosed)
    {
        int idx = -1;
        QPointF Pt1 = (*_helper)[0];
        QPointF Pt2 = (*_helper)[1];

        for (int i=0;i<size();++i)
        {
            if (point(i) == Pt1) idx = i;
        }

        if (idx >=0) insertPoint(idx+1, Pt2);
    }

    _helper->clear();
}

void cPolygon::removePoint(int i)
{
    _points.remove(i);
    _idx = -1;
}

const QVector<QPointF> cPolygon::getVector()
{
    QVector <QPointF> points;

    for(int aK=0; aK < size(); ++aK)

        points.push_back(point(aK));


    return points;
}

const QVector<QPointF> cPolygon::getImgCoordVector(const cMaskedImageGL &img)
{
    float nImgWidth, nImgHeight;
    float imgHeight = (float) img._m_image->height();
    if (_bNormalize)
    {
        nImgWidth = (float) img._m_image->width();
        nImgHeight = imgHeight;
    }
    else
    {
        nImgWidth = nImgHeight = 1.f;
    }

    QVector <QPointF> points;

    for(int aK=0; aK < size(); ++aK)
    {
        points.push_back( QPointF(point(aK).x()/nImgWidth, (imgHeight - point(aK).y())/nImgHeight));
    }

    return points;
}

//transforms into terrain coordinates if FileOriMNT exists, else transforms into image coordinates
const QVector<QPointF> cPolygon::transfoTerrain(const cMaskedImageGL &img)
{
    QVector <QPointF> res = getImgCoordVector(img);

    if (img._m_FileOriMnt.NameFileMnt() != "")
    {
        for (int aK=0; aK < res.size(); ++aK)
        {
            Pt2dr ptImage(res[aK].x(), res[aK].y());

            Pt2dr ptTerrain = ToMnt(img._m_FileOriMnt, ptImage);

            res[aK]=  QPointF(ptTerrain.x, ptTerrain.y);
        }
    }

    return res;
}

void cPolygon::setVector(const QVector<QPointF> &aPts)
{
    _points.clear();
    for(int aK=0; aK < aPts.size(); ++aK)
    {
        _points.push_back(cPoint(aPts[aK]));
    }
}

void cPolygon::setHelper(cPolygonHelper* aHelper) {

	_helper = aHelper;
}

void cPolygon::setPointSelected()
{
	_bSelectedPoint = true;

	if (pointValid())
        point(_idx).setSelected(true);
}

void cPolygon::resetSelectedPoint()
{
    _bSelectedPoint = false;

    if (pointValid())
        point(_idx).setSelected(false);

    _idx = -1;
}

bool cPolygon::pointValid()
{
    return ((_idx >=0) && (_idx < size()));
}

int cPolygon::selectPoint(QString namePt)
{
    resetSelectedPoint();

    for (int i = 0; i < size(); ++i)
    {
        if(point(i).name() == namePt)
        {
            _idx = i;
            point(i).setSelected(true);
            return i;
        }
    }

    return _idx;
}

void cPolygon::selectPoint(int idx)
{
    _idx = idx;

    if (pointValid())
    {
        point(idx).setSelected(true);
        _bSelectedPoint = true;
    }
}

void cPolygon::setPointSize(float sz)
{
    _pointDiameter = sz;

    for (int i = 0; i < size(); ++i)
    {
        point(i).setDiameter(sz);
    }

    if (helper() != NULL) helper()->setPointSize(sz);
}

bool cPolygon::findNearestPoint(QPointF const &pos, float radius)
{
    if (_bIsClosed || _bShowLines)
    {
        resetSelectedPoint();

		float dist2, x, y;
        dist2 = radius*radius;
        x = pos.x();
        y = pos.y();

        for (int aK = 0; aK < size(); ++aK)
        {
			const float dx = x - point(aK).x();
			const float dy = y - point(aK).y();

			const float dist = dx * dx + dy * dy;

            if  (dist < dist2)
            {
                dist2 = dist;
                _idx = aK;
            }
        }

        if (pointValid())
        {
            point(_idx).setSelected(true);

            return true;
        }
    }

    return false;
}

void cPolygon::refreshHelper(QPointF pos, bool insertMode, float zoom, bool ptIsVisible)
{
    int nbVertex = size();

    if(!_bIsClosed)
    {
        if (nbVertex == 1)                   // add current mouse position to polygon (for dynamic display)

            add(pos);

        else if (nbVertex > 1)               // replace last point by the current one
        {
            point(nbVertex-1).setX( pos.x() );
            point(nbVertex-1).setY( pos.y() );
        }
    }
    else if(nbVertex)                        // move vertex or insert vertex (dynamic display) en cours d'operation
    {
        if ( insertMode || isPointSelected()) // insert or move polygon point
        {
            cPoint pt( pos, getSelectedPointName(), _bShowNames, getSelectedPointState(), isPointSelected(), _color[state_default]); // TODO add diameter parameter
            pt.setDiameter(_pointDiameter);


            if (!ptIsVisible) pt.setVisible(false);

            _helper->build(pt, insertMode);
        }
        else                                 // select nearest polygon point
        {
            findNearestPoint(pos, _selectionRadius / zoom);
        }
    }
}

int cPolygon::finalMovePoint()
{
    int idx = _idx;

    if ((_idx>=0) && (_helper != NULL) && _helper->size())   // after point move
    {
        int state = point(_idx).pointState();

        point(_idx) = (*_helper)[1];
        point(_idx).setColor(_color[state_default]); // reset color to polygon color
        point(_idx).setPointState(state);

        _helper->clear();

        resetSelectedPoint();
    }

    return idx;
}

void cPolygon::removeLastPoint()
{
    if (size() >= 1)
    {
        removePoint(size()-1);
        _bIsClosed = false;
    }
}

void cPolygon::showNames(bool show)
{
    _bShowNames = show;

    for (int aK=0; aK < size(); ++aK)
        point(aK).showName(_bShowNames);
}

void cPolygon::rename(QPointF pos, QString name)
{
    findNearestPoint(pos, 400000.f);

    if (pointValid())
        point(_idx).setName(name);
}

void cPolygon::showLines(bool show)
{
    _bShowLines = show;

    if (_helper != NULL) _helper->showLines(show);

    if(!show) _bIsClosed = true;

    cObject::setColor(show ? Qt::red : Qt::green);
}

void cPolygon::translate(QPointF Tr)
{
    for (int aK=0; aK < size(); ++aK)
        point(aK) += Tr;
}

cPoint cPolygon::translateSelectedPoint(QPointF Tr)
{
    if (pointValid())
    {
        point(_idx) += Tr;
        return point(_idx);
    }
    else
        return ErrPoint;
}

void cPolygon::setParams(cParameters *aParams)
{
    setRadius(aParams->getSelectionRadius());
    setPointSize(aParams->getPointDiameter());
    setLineWidth(aParams->getLineThickness());
    setShiftStep(aParams->getShiftStep());

    if (_helper != NULL)
    {
        _helper->setRadius(aParams->getSelectionRadius());
        _helper->setPointSize(aParams->getPointDiameter());
        _helper->setLineWidth(aParams->getLineThickness());
    }
}

bool cPolygon::isPointInsidePoly(const QPointF& P)
{
    int vertices=size();
    if (vertices<3)
        return false;

    bool inside = false;

    QPointF A = _points[0];
    QPointF B;

    for (int i=1;i<=vertices;++i)
    {
        B = _points[i%vertices];

        //Point Inclusion in Polygon Test (inspired from W. Randolph Franklin - WRF)
        if (((B.y() <= P.y()) && (P.y()<A.y())) ||
                ((A.y() <= P.y()) && (P.y()<B.y())))
        {
            float ABy = A.y()-B.y();
            float t = (P.x()-B.x())*ABy-(A.x()-B.x())*(P.y()-B.y());
            if (ABy<0)
                t=-t;

            if (t<0)
                inside = !inside;
        }

        A=B;
    }

    return inside;
}

//********************************************************************************

cPolygonHelper::cPolygonHelper(cPolygon* polygon, int maxSz, float lineWidth, QColor lineColor, QColor pointColor):
	cPolygon(maxSz, lineWidth, lineColor, pointColor, false),
    _polygon(polygon)
{
}

cPolygonHelper::~cPolygonHelper()
{
}

float segmentDistToPoint(QPointF segA, QPointF segB, QPointF p)
{
    QPointF p2(segB.x() - segA.x(), segB.y() - segA.y());
    float nrm = (p2.x()*p2.x() + p2.y()*p2.y());
    float u = ((p.x() - segA.x()) * p2.x() + (p.y() - segA.y()) * p2.y()) / nrm;

    if (u > 1)
        u = 1;
    else if (u < 0)
        u = 0;

    float x = segA.x() + u * p2.x();
    float y = segA.y() + u * p2.y();

    float dx = x - p.x();
    float dy = y - p.y();

    return sqrt(dx*dx + dy*dy);
}

void cPolygonHelper::build(cPoint const &pos, bool insertMode)
{
    int sz = _polygon->size();

    if (insertMode)
    {
		float dist2 = FLT_MAX;
        int idx = -1;
        for (int aK =0; aK < sz; ++aK)
        {
			const float dist = segmentDistToPoint((*_polygon)[aK], (*_polygon)[(aK + 1)%sz], pos);

            if (dist < dist2)
            {
                dist2 = dist;
                idx = aK;
            }
        }

        if (idx != -1)
            setPoints((*_polygon)[idx],pos,(*_polygon)[(idx+1)%sz]);
    }
    else //moveMode
    {
        if (sz > 1)
        {
            int idx = _polygon->getSelectedPointIndex();

            if ((idx > 0) && (idx <= sz-1))
                setPoints((*_polygon)[(idx-1)%sz],pos,(*_polygon)[(idx+1)%sz]);
            else if (idx  == 0)
                setPoints((*_polygon)[sz-1],pos,(*_polygon)[1]);
        }
        else
            setPoints(pos, pos, pos);
    }
}

void cPolygonHelper::setPoints(cPoint p1, cPoint p2, cPoint p3)
{
    clear();
    add(p1);
    add(p2);
    add(p3);
}

//********************************************************************************

cRectangle::cRectangle(int maxSz, float lineWidth, QColor lineColor, int style) :
    cPolygon(maxSz, lineWidth, lineColor, Qt::red, style)
{}

void cRectangle::addPoint(const QPointF &pt)
{
    if (size() == 0)
    {
        for (int aK=0; aK < getMaxSize(); aK++)
            add(pt);

        selectPoint(2); //
    }
}

void cRectangle::refreshHelper(QPointF pos, bool insertMode, float zoom, bool ptIsVisible)
{
    if (size())
    {
        if(isPointSelected())
        {
            showLines(true);
            setClosed(true);

            point(_idx).setX(pos.x());
            point(_idx).setY(pos.y());

            if (_idx == 2)
            {
                _points[1].setX(pos.x());

                _points[3].setY(pos.y());
            }
            else if(_idx == 1)
            {
                _points[0].setY(pos.y());

                _points[2].setX(pos.x());
            }
            else if(_idx == 0)
            {
                _points[3].setX(pos.x());

                _points[1].setY(pos.y());
            }
            else if(_idx == 3)
            {
                _points[2].setY(pos.y());

                _points[0].setX(pos.x());
            }
        }
        else
        {
            cPolygon::refreshHelper(pos, false, zoom, false);
        }
    }
}

void cRectangle::draw()
{
    for (int aK= 0; aK < size(); ++aK)
        _points[aK].setVisible(false);

    cPolygon::draw();
}

//********************************************************************************

//invalid GL list index
const GLuint GL_INVALID_LIST_ID = (~0);

cImageGL::cImageGL(float gamma) :
    _texture(GL_INVALID_LIST_ID),
    _gamma(gamma)
{
    setPosition(Pt3dr(0,0,0));

    _program.addShaderFromSourceCode(QGLShader::Vertex,vertexShader);
    _program.addShaderFromSourceCode(QGLShader::Fragment,fragmentGamma);
    _program.link();

    _texLocation   = _program.uniformLocation("tex");
    _gammaLocation = _program.uniformLocation("gamma");
}

cImageGL::~cImageGL()
{
    if (_texture != GL_INVALID_LIST_ID)
    {
        glDeleteLists(_texture,1);
        _texture = GL_INVALID_LIST_ID;
    }
}

void cImageGL::drawQuad(QColor color)
{
    drawQuad(getPosition().x, getPosition().y, width(), height(), color);
}

void cImageGL::drawQuad(GLfloat originX, GLfloat originY, GLfloat glw,  GLfloat glh, QColor color)
{
    glColor4f(color.redF(),color.greenF(),color.blueF(),color.alphaF());
    glBegin(GL_QUADS);
    {

        glTexCoord2f(0.0f, 0.0f);
        glVertex2f(originX, originY);
        glTexCoord2f(1.0f, 0.0f);
        glVertex2f(originX+glw, originY);
        glTexCoord2f(1.0f, 1.0f);
        glVertex2f(originX+glw, originY+glh);
        glTexCoord2f(0.0f, 1.0f);
        glVertex2f(originX, originY+glh);

    }
    glEnd();
}

void cImageGL::draw()
{
    glEnable(GL_TEXTURE_2D);

	if(_texture != GL_INVALID_LIST_ID)
	{
		glBindTexture( GL_TEXTURE_2D, _texture );

		if(_gamma != 1.0f)
		{
			_program.bind();
			_program.setUniformValue(_texLocation, GLint(0));
			_program.setUniformValue(_gammaLocation, GLfloat(1.0f/_gamma));
		}

	}

    drawQuad(Qt::white);

    if(_gamma != 1.0f) _program.release();

    glBindTexture( GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
}


void cImageGL::setSize(QSize size)
{
    _size = size;
}

void cImageGL::draw(QColor color)
{
    if(isVisible())
        drawQuad(color);
}

bool cImageGL::isPtInside(const QPointF &pt)
{
    return (pt.x()>=0.f)&&(pt.y()>=0.f)&&(pt.x()<width())&&(pt.y()<height());
}

void cImageGL::createTexture(QImage * pImg)
{

	if(!pImg || pImg->isNull())
		return;

    glGenTextures(1, getTexture() );	

    ImageToTexture(pImg);
}

void cImageGL::ImageToTexture(QImage *pImg)
{

    glEnable(GL_TEXTURE_2D);

    glBindTexture( GL_TEXTURE_2D, _texture );
    if (pImg->format() == QImage::Format_Indexed8)
        glTexImage2D( GL_TEXTURE_2D, 0, 3, pImg->width(), pImg->height(), 0, GL_RGB, GL_UNSIGNED_BYTE, pImg->bits());
    else
        glTexImage2D( GL_TEXTURE_2D, 0, 4, pImg->width(), pImg->height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, pImg->bits());


    /*GLenum glErrorT = glGetError();
    if(glErrorT == GL_OUT_OF_MEMORY)
    {
        setGlError(glErrorT);
        printf("GL_OUT_OF_MEMORY \n");
    }*/
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glBindTexture( GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
}

void cImageGL::deleteTexture()
{

	if(_texture != GL_INVALID_LIST_ID)
        glDeleteTextures(1,&_texture);
	_texture = GL_INVALID_LIST_ID;

}

void cImageGL::drawGradientBackground(int w, int h, QColor c1, QColor c2)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE,GL_ZERO);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    w = (w>>1)+1;
    h = (h>>1)+1;

    glOrtho(-w,w,-h,h,-2.f, 2.f);

    const uchar BkgColor[3] = {(uchar) c1.red(),(uchar) c1.green(), (uchar) c1.blue()};
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //Gradient "texture" drawing
    glBegin(GL_QUADS);
    //user-defined background color for gradient start
    glColor3ubv(BkgColor);
    glVertex2f(-w,h);
    glVertex2f(w,h);
    //and the inverse of points color for gradient end
    glColor3ub(c2.red(),c2.green(),c2.blue());
    glVertex2f(w,-h);
    glVertex2f(-w,-h);
    glEnd();

    glDisable(GL_BLEND);
}


//********************************************************************************

//TODO: un seul constructeur ?
cMaskedImageGL::cMaskedImageGL(cMaskedImage<QImage> *qMaskedImage):
    _qMaskedImage(qMaskedImage)
{
    _loadedImageRescaleFactor = qMaskedImage->_loadedImageRescaleFactor;
    _m_mask     = new cImageGL();
    _m_image    = new cImageGL(qMaskedImage->_gamma);
    _m_newMask  = qMaskedImage->_m_newMask;

    _m_FileOriMnt = qMaskedImage->_m_FileOriMnt;

    cObjectGL::setName(qMaskedImage->name());
}

cMaskedImageGL::cMaskedImageGL(const QRectF &aRect):
    _qMaskedImage(NULL)
{
    _m_image = new cImageGL();
    _m_mask  = new cImageGL();

    _m_image->setVisible(false);
    _m_mask->setVisible(false);

    Pt3dr pos(aRect.topLeft().x(), aRect.topLeft().y(), 0.f);

    QSize size((int) aRect.width(), (int) aRect.height());

    _m_image->setPosition(pos);
    _m_image->setSize(size);
    _m_mask->setPosition(pos);
	_m_mask->setSize(size);
}

cMaskedImageGL::~cMaskedImageGL()
{
	_mutex.unlock();
}

void cMaskedImageGL::draw()
{
    glEnable(GL_BLEND);
    glDisable(GL_ALPHA_TEST);
    glDisable(GL_DEPTH_TEST);

	if(glImage()->isVisible())
	{
		glBlendFunc(GL_ONE,GL_ZERO);		
		glImage()->draw();
	}

	if(glMask() != NULL && glMask()->isVisible())
	{

#if (ELISE_QT_VERSION == 5)
		QOpenGLContext* context = QOpenGLContext::currentContext();
		QOpenGLFunctions* glFunctions = context->functions();
		glFunctions->glBlendColor(1.f, 0.1f, 1.f, 1.0f);
		glFunctions->glBlendEquation(GL_FUNC_REVERSE_SUBTRACT);
		glBlendFunc(GL_CONSTANT_COLOR,GL_ONE);
		glMask()->draw();

		glFunctions->glBlendEquation(GL_FUNC_ADD);
		glFunctions->glBlendColor(0.f, 0.2f, 0.f, 1.0f);
		glBlendFunc(GL_CONSTANT_COLOR,GL_ONE);
		glMask()->draw(); 
#elif (ELISE_QT_VERSION == 4)

		glBlendColor(1.f, 0.1f, 1.f, 1.0f);
		glBlendEquation(GL_FUNC_REVERSE_SUBTRACT);
		glBlendFunc(GL_CONSTANT_COLOR, GL_ONE);
		glMask()->draw();
		glBlendEquation(GL_FUNC_ADD);
		glBlendColor(0.f, 0.2f, 0.f, 1.0f);
		glBlendFunc(GL_CONSTANT_COLOR, GL_ONE);
		glMask()->draw();
#endif
	}

    glDisable(GL_BLEND);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_ALPHA_TEST);
}

/*void cMaskedImageGL::drawMaskTiles()
{
    for (unsigned int aK=0; aK <_vTiles.size();++aK)
    {
        if (_vTiles[aK].getMaskTile()->isVisible())
            _vTiles[aK].getMaskTile()->draw();
    }
}

void cMaskedImageGL::drawImgTiles()
{
    for (unsigned int aK=0; aK <_vTiles.size();++aK)
    {
        if (_vTiles[aK].getImgTile()->isVisible())
        {
            if(*(_vTiles[aK].getImgTile()->getTexture() )==  GL_INVALID_LIST_ID)
                _vTiles[aK].getImgTile()->draw(Qt::red);
            else
            {
                _vTiles[aK].getImgTile()->draw();
            }
        }
    }
}*/

/*void cMaskedImageGL::drawTiles(cImageGL* tiles)
{
    for (int aK = 0; aK < 4; ++aK)
    {
        if (tiles[aK].isVisible())
        {
            if(*(tiles[aK].getTexture() )==  GL_INVALID_LIST_ID)
                tiles[aK].draw(Qt::red);
            else
                tiles[aK].draw();
        }
    }

//    {
//        tiles[0].draw(Qt::red);
//        tiles[1].draw(Qt::blue);
//        tiles[2].draw(Qt::green);
//        tiles[3].draw(Qt::yellow);
//    }
}*/



void cMaskedImageGL::createTextures()
{
	_mutex.tryLock();
	if( _qMaskedImage)
	{
		if( glMask() && glMask()->isVisible() )
		{

			glMask()->createTexture( _qMaskedImage->_m_rescaled_mask );

			if(!_qMaskedImage->_fullSize.isNull())
			{
				glMask()->setSize( _qMaskedImage->_fullSize);
			}
			else
				glMask()->setSize( _qMaskedImage->_m_mask->size() );
		}
		if(glImage() && glImage()->isVisible())
		{
			if(getLoadedImageRescaleFactor() < 1.f)
				glImage()->createTexture( _qMaskedImage->_m_rescaled_image );
			else
				glImage()->createTexture( _qMaskedImage->_m_image );

			if(!_qMaskedImage->_fullSize.isNull())
			{
				glImage()->setSize( _qMaskedImage->_fullSize );
			}
			else
				glImage()->setSize( _qMaskedImage->_m_image->size() );

		}
	}
	_mutex.unlock();
}

void cMaskedImageGL::createFullImageTexture()
{
	if(glImage() && glImage()->isVisible())
	{
		_mutex.tryLock();
		if(_qMaskedImage)
		{
			glImage()->createTexture( _qMaskedImage->_m_image );
			delete _qMaskedImage;
			_qMaskedImage = NULL;
		}
		_mutex.unlock();
	}

}

void cMaskedImageGL::copyImage(QMaskedImage* image, QRect& rect)
{
	_mutex.tryLock();
	if(!_qMaskedImage)
		_qMaskedImage = new QMaskedImage();

	_qMaskedImage->_m_image = new QImage(rect.size(),QImage::Format_Mono);

	QImage* tImage = getMaskedImage()->_m_image;

	QImage* sourceImage = image->_m_image;

	*(tImage) = sourceImage->copy(rect);

	_mutex.unlock();
}

QSize cMaskedImageGL::fullSize()
{

	_mutex.tryLock();
	if(getMaskedImage() && !getMaskedImage()->_fullSize.isNull())
	{
		QSize lfullSize	= _qMaskedImage->_fullSize;
		return lfullSize;
	}
	else
		return glImage()->getSize();

	_mutex.unlock();
}

void cMaskedImageGL::deleteTextures()
{
	if(glMask())
		glMask()->deleteTexture(); //TODO segfault (undo)
    if(glImage())
        glImage()->deleteTexture();
}

//********************************************************************************

cObjectGL::cObjectGL():
_glError(0)
{}

void cObjectGL::setGLColor()
{
    QColor color = getColor();
    glColor4f(color.redF(),color.greenF(),color.blueF(),_alpha);
}

void cObjectGL::enableOptionLine()
{
   // glDisable(GL_DEPTH_TEST);
    glEnable(GL_DEPTH_TEST);
    glEnable (GL_LINE_SMOOTH);
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glHint (GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
}

void cObjectGL::disableOptionLine()
{
	glDisable(GL_BLEND);
    glDisable(GL_LINE_SMOOTH);
    //glEnable(GL_DEPTH_TEST);
}

float cObjectGL::getHalfViewPort()
{
    GLint       glViewport[4];
    glGetIntegerv(GL_VIEWPORT, glViewport);

    return (float)glViewport[2]/2.f;
}

//********************************************************************************

void cMessages2DGL::draw(){

    if (drawMessages())
    {
        int ll_curHeight, lr_curHeight, lc_curHeight; //lower left, lower right and lower center y position
        ll_curHeight = lr_curHeight = lc_curHeight = h - (m_font.pointSize())*(m_messagesToDisplay.size()-1) ;
        int uc_curHeight = m_font.pointSize();            //upper center

        std::list<MessageToDisplay>::iterator it = m_messagesToDisplay.begin();
        while (it != m_messagesToDisplay.end())
        {
            QRect rect = QFontMetrics(m_font).boundingRect(it->message);
            switch(it->position)
            {
            case LOWER_LEFT_MESSAGE:
                ll_curHeight -= renderTextLine(*it, m_font.pointSize(), ll_curHeight,m_font.pointSize());
                break;
            case LOWER_RIGHT_MESSAGE:
                lr_curHeight -= renderTextLine(*it, w - 120, lr_curHeight);
                break;
            case LOWER_CENTER_MESSAGE:
                lc_curHeight -= renderTextLine(*it,(w-rect.width())/2, lc_curHeight);
                break;
            case UPPER_CENTER_MESSAGE:
                uc_curHeight += renderTextLine(*it,(w-rect.width())/2, uc_curHeight+rect.height());
                break;
            case SCREEN_CENTER_MESSAGE:
                renderTextLine(*it,(w-rect.width())/2, (h-rect.height())/2,12);
            }
            ++it;
        }
    }
}

int cMessages2DGL::renderTextLine(MessageToDisplay messageTD, int x, int y, int sizeFont)
{
    m_font.setPointSize(sizeFont);

    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glwid->qglColor(messageTD.color);
    glwid->renderText(x, y, messageTD.message,m_font);
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_LIGHTING);

    return (QFontMetrics(m_font).boundingRect(messageTD.message).height()*5)/4;
}

void cMessages2DGL::displayNewMessage(const QString &message, MessagePosition pos, QColor color)
{
    if (message.isEmpty())
    {
        m_messagesToDisplay.clear();

        return;
    }

    MessageToDisplay mess;
    mess.message = message;
    mess.position = pos;
    mess.color = color;
    m_messagesToDisplay.push_back(mess);
}

void cMessages2DGL::constructMessagesList(bool show, int mode, bool m_bDisplayMode2D, bool dataloaded, float zoom)
{
    _bDrawMessages = show;

    displayNewMessage(QString());

    if (show)
    {
        if(dataloaded)
        {
            if(m_bDisplayMode2D)
            {
                displayNewMessage(QString(" "),LOWER_RIGHT_MESSAGE, Qt::lightGray);
                displayNewMessage(QString::number(zoom*100,'f',1) + "%", LOWER_LEFT_MESSAGE, QColor("#ffa02f"));
            }
            else
            {
                if (mode == TRANSFORM_CAMERA)
                {
                    displayNewMessage(QObject::tr("Move mode"),UPPER_CENTER_MESSAGE);
                    displayNewMessage(QObject::tr("Left click: rotate viewpoint / Middle click: translate viewpoint"),LOWER_CENTER_MESSAGE);
                }
                else if (mode == SELECTION)
                {
                    displayNewMessage(QObject::tr("Selection mode"),UPPER_CENTER_MESSAGE);
                    displayNewMessage(QObject::tr("Left click: add contour point / Right click: close"),LOWER_CENTER_MESSAGE);
                    displayNewMessage(QObject::tr("Space: add / Suppr: delete"),LOWER_CENTER_MESSAGE);
                }

                displayNewMessage(QString("0 Fps"), LOWER_LEFT_MESSAGE, Qt::lightGray);
            }
        }
        else
            displayNewMessage(QObject::tr("Drag & drop files"));
    }
}

std::list<MessageToDisplay>::iterator cMessages2DGL::GetLastMessage()
{
    std::list<MessageToDisplay>::iterator it = --m_messagesToDisplay.end();

    return it;
}

std::list<MessageToDisplay>::iterator cMessages2DGL::GetPenultimateMessage()
{
    return --GetLastMessage();
}

MessageToDisplay &cMessages2DGL::LastMessage()
{
    return m_messagesToDisplay.back();
}

void cMessages2DGL::glRenderText(QString text, QPointF pt, QColor color)
{
    glColor3f(color.redF(),color.greenF(),color.blueF());

    glwid->renderText ( pt.x(), pt.y(), text);
}

cGrid::cGrid(Pt3dr pt, Pt3dr scale)
{
    _position = pt;
    _scale    = scale;
}

void cGrid::draw()
{
    if (isVisible())
    {
        //TODO: adapter a la forme de la BBox
        int nbGridX = 10;
        int nbGridZ = 10;

        float scaleX = getScale().x / nbGridX;
        float scaleZ = getScale().z / nbGridZ;

        Pt3dr pt;

        pt.x = getPosition().x - ((float)nbGridX * 0.5f) * scaleX;
        pt.y = getPosition().y ;
        pt.z = getPosition().z - ((float)nbGridZ * 0.5f) * scaleZ;

        glBegin(GL_LINES);
        glColor3f(.25,.25,.25);
        for(int i=0;i<=nbGridX;i++)
        {
            //if (i==0) { glColor3f(.6,.3,.3); } else { glColor3f(.25,.25,.25); };
            glVertex3f((float)i * scaleX + pt.x,pt.y,pt.z);
            glVertex3f((float)i * scaleX + pt.x,pt.y,(float)nbGridZ * scaleZ+ pt.z);
        }

        for(int i=0;i<=nbGridZ;i++)
        {
            //if (i==0) { glColor3f(.3,.3,.6); } else { glColor3f(.25,.25,.25); };
            glVertex3f( pt.x,pt.y,(float)i * scaleZ + pt.z);
            glVertex3f((float)nbGridX* scaleX+pt.x,pt.y,(float)i * scaleZ + pt.z);
        };
        glEnd();
    }
}

