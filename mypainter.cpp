#include "mypainter.h"
#include <iomanip>

MyPainter::MyPainter() :
    m_w(86),
    m_h(20)

{


}

MyPainter::~MyPainter()
{
    for(auto p : m_figs)
        delete p;

    m_figs.clear();
}

void MyPainter::addBox()
{
    Box *b = new Box();
    m_figs.push_back(b);
}

void MyPainter::addBox(int size, int posX, int posY)
{
    Box *b = new Box(size, posX, posY);
    m_figs.push_back(b);
}

void MyPainter::addTriangle(int size, int posX, int posY)
{
    Triangle *t = new Triangle(size, posX, posY);
    m_figs.push_back(t);
}

void MyPainter::addCircle(int size, int posX, int posY)
{
    Circle *c = new Circle(size, posX, posY);
    m_figs.push_back(c);
}

void MyPainter::drawToConsole()
{
    vector<string> buff(m_h, string(m_w, 0));

    vector<Point> vec;

    vector<Figure*>::const_iterator f;
    for(f = m_figs.begin(); f != m_figs.end(); ++f){
        (*f)->generatePoints(vec);
    }

    vector<Point>::const_iterator i;
    int x, y;
    char ch1 = 'X';
    char ch2 = ' ';
    for(unsigned int i = 0; i < m_h; i++){
        for(unsigned int j = 0; j < m_w; j++){
            buff[i][j] = ch2;
        }
    }

    for(i = vec.begin(); i != vec.end(); ++i){
        x = (*i).m_x;
        y = (*i).m_y;
        if( (x >= 0) && (x <= m_w/2-1) && (y >= 0) && (y <= m_h - 1)){
            buff[y][x*2] = ch1;
            buff[y][(x*2) + 1] = ch2;
        }
    }

    vector<string>::const_iterator s;
    for(s = buff.begin(); s != buff.end(); ++s)
        cout << *s << endl;

}

void MyPainter::draw(QImage &im)
{
    vector<Point> vec;
    for(unsigned int i = 0; i < m_figs.size(); i++){
        Figure *f = m_figs.at(i);
        f->generatePoints(vec);
    }

    for(unsigned int i = 0; i < vec.size(); i++){
        im.setPixel(vec.at(i).m_x, vec.at(i).m_y, qRgb(24, 140, 56));
    }
}

void MyPainter::setHeight(unsigned int h)
{
    m_h = h;
}

void MyPainter::setWidth(unsigned int w)
{
    m_w = w;
}

int MyPainter::getHeight()
{
    return m_h;
}

int MyPainter::getWidth()
{
    return m_w;
}

