#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>
#include <QtGui>
#include <QtCore>

class MyObject : public QObject
{
    Q_OBJECT
public:
    explicit MyObject(QObject *parent = nullptr);

signals:

public slots:

    void mousePressEvent(QMouseEvent *event);
private:
    QVector<QPoint> m_points;

};

#endif // MYOBJECT_H
