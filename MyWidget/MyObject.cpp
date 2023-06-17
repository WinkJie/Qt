#include "MyObject.h"

MyObject::MyObject(QObject *parent) : QObject(parent)
{

}

void MyObject::mousePressEvent(QMouseEvent *event)
{
    if (m_points.size() < 4)
    {
        QPoint point(event->pos());
        m_points.append(point);

        if (m_points.size() == 4)
        {
            qDebug() << "四边形的四个点为：" << m_points;
        }
    }
}


