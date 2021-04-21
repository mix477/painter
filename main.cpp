#include <iostream>
#include <QImage>
#include "mypainter.h"

using namespace std;

int main()
{
    int h(512), w(512);
    QImage im = QImage(h, w, QImage::Format_RGB888);

    MyPainter mp;
    mp.addBox(10, 0, 0);
    mp.addBox(30, 20, 20);
    mp.addBox(80, 50, 34);
    mp.addTriangle(200, 15, 180);
    mp.draw(im);
    im.save("qqq.bmp");

    return 0;
}

