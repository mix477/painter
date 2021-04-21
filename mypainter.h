#ifndef MYPAINTER_H
#define MYPAINTER_H

#include <QImage>
#include "figures.h"

class MyPainter
{
public:
    MyPainter();

    ~MyPainter();

    void addBox();

    void addBox(int size, int posX = 0, int posY = 0);

    void addTriangle(int size, int posX = 0, int posY = 0);

    void addCircle(int size, int posX = 0, int posY = 0);

    void drawToConsole();

    void draw(QImage &im);

private:
    vector<Figure*> m_figs;
};

#endif // MYPAINTER_H
