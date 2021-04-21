#include "figures.h"

Figure::Figure() :
    m_x(0),
    m_y(0),
    m_size(0)
{

}

Figure::~Figure()
{
    cout << "~Figure()" << endl;
}

Figure::Figure(int size, int posX, int posY) :
    m_x(posX),
    m_y(posY),
    m_size(size)
{

}

void Figure::setPos(int posX, int posY)
{
    m_x = posX;
    m_y = posY;
}

void Figure::setSize(int size)
{
    m_size = size;
}



int Figure::X()
{
    return m_x;
}

int Figure::Y()
{
    return m_y;
}

void Figure::createLine(int x0, int y0, int x1, int y1, vector<Point> &vec)
{
    bool swp = false;
    if(abs(x0 - x1) < abs(y0 - y1)) {
        swap(x0, y0);
        swap(x1, y1);
        swp = true;
    }

    if(x0 > x1){
        swap(x0, x1);
        swap(y0, y1);
    }

    int dx = x1 - x0;
    int dy = y1 - y0;
    int derror = abs(dy)*2;
    int error = 0;
    int y = y0;
    for(int x = x0; x <= x1; x++){
        if(swp)
            vec.push_back(Point(y, x));
        else
            vec.push_back(Point(x, y));

        error += derror;
        if(error > dx){
            y += (y1 > y0 ? 1: -1);
            error -= dx*2;
        }
    }
}

void Figure::createCircle(int x0, int y0, int radius, vector<Point> &vec)
{
    int x = 0;
    int y = radius;
    int delta = 1 - 2 * radius;
    int error = 0;
    while(y >= 0) {
        vec.push_back(Point(x0 + x, y0 + y));
        vec.push_back(Point(x0 + x, y0 - y));
        vec.push_back(Point(x0 - x, y0 + y));
        vec.push_back(Point(x0 - x, y0 - y));
        error = 2 * (delta + y) - 1;
        if(delta < 0 && error <= 0) {
            ++x;
            delta += 2 * x + 1;
            continue;
        }
        error = 2 * (delta - x) - 1;
        if(delta > 0 && error > 0) {
            --y;
            delta += 1 - 2 * y;
            continue;
        }
        ++x;
        delta += 2 * (x - y);
        --y;
    }
}

Box::Box()
{

}

Box::~Box()
{
    cout << "~Box()" << endl;
}

Box::Box(int size, int posX, int posY) : Figure(size, posX, posY)
{

}

void Box::generatePoints(vector<Point> &vec)
{
    createLine(m_x, m_y, m_x + m_size, m_y, vec);
    createLine(m_x, m_y, m_x, m_y + m_size, vec);
    createLine(m_x + m_size, m_y, m_x + m_size, m_y+m_size, vec);
    createLine(m_x, m_y + m_size, m_x + m_size, m_y+m_size, vec);
}

Triangle::~Triangle()
{
    cout << "~Triangle()" << endl;
}

Triangle::Triangle(int size, int posX, int posY) : Figure(size, posX, posY)
{

}

void Triangle::generatePoints(vector<Point> &vec)
{
    createLine(m_x, m_y, m_x, m_y + m_size, vec);
    createLine(m_x, m_y + m_size, m_x + m_size, m_y + m_size, vec);
    createLine(m_x, m_y, m_x + m_size, m_y + m_size, vec);
}

Circle::Circle()
{

}

Circle::~Circle()
{

}

Circle::Circle(int size, int posX, int posY) : Figure(size, posX, posY)
{

}

void Circle::generatePoints(vector<Point> &vec)
{
    createCircle(m_x + m_size + 1, m_y + m_size, m_size, vec);
}
