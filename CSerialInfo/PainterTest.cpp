#include "PainterTest.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QRect>
//#include <iostream>
#include <qdebug.h>
#include "Widget.h"

PainterTest::PainterTest(QWidget *parent) : QWidget(parent)
{


}

void PainterTest::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;
    pen.setColor(Qt::red) ;
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(4) ;
    painter.setPen(pen);
    QBrush brush;
    brush.setColor(Qt::gray) ;
//    painter.setBrush(QBrush(Qt::blue));
    qDebug()<<brush.color()<<endl;
    painter.setBrush(brush);
    qDebug()<<painter.brush().color()<<endl;
    qDebug()<<painter.pen().color()<<endl;

    QRect rect = painter.viewport();
    int radis = 100;
    int x = rect.width()/2 - radis;
    int y = rect.height()/2 - radis;
    painter.drawEllipse(x,y,radis*2, radis*2) ;
    painter.end();

    /*

    QPainter painter1(this);
    if (!painter1.begin(this)) {
        qWarning("Failed to start painting.");
        return;
    }

    QBrush brush1;
    brush1.setColor(Qt::gray) ;

    QPen pen1;
    pen1.setColor(Qt::red) ;
    pen1.setStyle(Qt::SolidLine);
    pen1.setWidth(4) ;
    painter1.setPen(pen1);

    painter1.setBrush(brush1);
    QRect rect1 = painter1.viewport();
    int radis1 = 100;
    int x1 = rect1.width()/2 - radis1;
    int y1 = rect1.height()/2 - radis1;
    painter1.drawEllipse(x1,y1,radis1*2, radis1*2) ;

    painter1.end();
*/
}
