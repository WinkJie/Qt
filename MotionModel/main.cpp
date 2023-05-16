#include "MotionModel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MotionModel w;
    w.show();

    return a.exec();
}
