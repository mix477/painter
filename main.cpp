#include <iostream>
#include <QImage>
#include "mypainter.h"

using namespace std;

int main()
{
    int h(512), w(512);
    QImage im = QImage(h, w, QImage::Format_RGB888);

    MyPainter mp;
    mp.addBox(40, 0, 0);
    mp.addCircle(40, 0, 0);
    mp.addTriangle(40, 0, 0);
    mp.draw(im);
    mp.drawToConsole();
    im.save("qqq.bmp");

    return 0;
}

