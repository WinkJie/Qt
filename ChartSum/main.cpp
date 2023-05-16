#include "MainWindow.h"
#include "ChartTest.h"
#include "ChartsView.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChartTest w;
    w.show();

    return a.exec();
}
