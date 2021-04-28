#include <iostream>
#include <QImage>
#include "mypainter.h"

using namespace std;

void showDemo(MyPainter &p){
    p.addBox(5, 6, 3);
    p.addBox(5, 13, 3);
    p.addCircle(11);
    p.addTriangle(3, 11, 10);
    p.addBox(2, 9, 15);
    p.addBox(2, 11, 15);
    p.addBox(2, 13, 15);
    p.drawToConsole();
}

int main(int argc, char *argv[])
{
//    int h(512), w(512);

//    QImage im = QImage(h, w, QImage::Format_RGB888);
    for(int i = 0; i < argc; i++){
        cout << argv[i] << endl;
    }
//    MyPainter mp;
    showDemo(mp);


    return 0;
}

