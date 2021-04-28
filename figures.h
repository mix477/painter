#ifndef FIGURES_H
#define FIGURES_H

#include <iostream>
#include <vector>
#include <math.h>
#include <typeinfo>


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


class Figure
{
public:
    Figure();

    virtual ~Figure();

    Figure(int size, int posX, int posY);

    virtual void setPos(int posX, int posY);

    virtual void setSize(int size);

    virtual void generatePoints(vector<Point> &vec) = 0;

    friend ostream& operator<< (ostream &os, const Figure &f);

    bool operator <(const Figure &f);

    bool operator >(const Figure &f);

    bool operator ==(const Figure &f);

    bool operator !=(const Figure &f);

    int X();

    int Y();

protected:
    int m_x, m_y;
    int m_size;

    void createLine(int x0, int y0, int x1, int y1, vector<Point> &vec);

    void createCircle(int x0, int y0, int radius, vector<Point> &vec);

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

    void generatePoints(vector<Point> &vec);
};

#endif // FIGURES_H
