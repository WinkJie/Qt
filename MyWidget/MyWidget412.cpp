#include "MyWidget412.h"
#include <QApplication>

MyWidget412::MyWidget412(QWidget *parent) : QWidget(parent)
{

}

void MyWidget412::mousePressEvent(QMouseEvent *event)
{
    QCoreApplication::sendEvent(this->parent(), event);
}


