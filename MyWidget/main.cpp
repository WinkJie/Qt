#include "MyWidget.h"
#include "MyObject.h"
#include <QApplication>

#include <QMdiArea>
#include "Polygon.h"
#include "CanVas.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MyWidget2 w;
//    w.SetPaintMode(MyWidget2::RECT);
//    w.show();
    CanVas w;
    w.show();


    return a.exec();
}
/*
 *
 *  新建目标船
 *  m_isRunTask 是否在运行
 *  m_timer2定时器停止
 *
 *
 *
*/
