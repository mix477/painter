#include "mypainter.h"

MyPainter::MyPainter()
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
    for(int i = 0; i < 100; i++)
        cout << "#";
}

void MyPainter::draw(QImage &im)
{
    vector<Point> vec;
    for(int i = 0; i < m_figs.size(); i++){
        Figure *f = m_figs.at(i);
        f->generatePoints(vec);
    }

    for(int i = 0; i < vec.size(); i++){
        im.setPixel(vec.at(i).m_x, vec.at(i).m_y, qRgb(24, 140, 56));
    }
}

