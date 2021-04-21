#ifndef FIGURES_H
#define FIGURES_H

#include <iostream>
#include <vector>
#include <math.h>


using namespace std;

struct Point{
    int m_x;
    int m_y;
    Point() :
        m_x(0),
        m_y(0)
    {
    }

    Point(int x, int y) :
        m_x(x),
        m_y(y)
    {
    }
};

struct Line{
    Point m_p1, m_p2;
    Line() :
        m_p1(Point()),
        m_p2(Point())
    {
    }
    Line(Point p1, Point p2):
        m_p1(p1),
        m_p2(p2)
    {}
};

class Figure
{
public:
    Figure();

    virtual ~Figure();

    Figure(int size, int posX, int posY);

    virtual void setPos(int posX, int posY);

    virtual void setSize(int size);

    virtual void generatePoints(vector<Point> &vec) = 0;

    int X();

    int Y();

protected:
    int m_x, m_y;
    int m_size;

    void createLine(int x0, int y0, int x1, int y1, vector<Point> &vec);

};

class Box : public Figure
{
public:
    Box();

    ~Box();

    Box(int size, int posX = 0, int posY = 0);

    void generatePoints(vector<Point> &vec);

};

class Triangle : public Figure
{
public:
    Triangle();

    ~Triangle();

    Triangle(int size, int posX = 0, int posY = 0);

    void generatePoints(vector<Point> &vec);
};

class Circle : public Figure
{
public:
    Circle();

    ~Circle();

    Circle(int size, int posX = 0, int posY = 0);
};

#endif // FIGURES_H
