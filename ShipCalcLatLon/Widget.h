#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <qdebug.h>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QPushButton>

class Point
{
    double x;
    double y;
    Point(double a,double b)
    {
        x=a;
        y=b;
    }
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

public slots :
    void open();

public:
    void CalcShip(double length, double width, double lat, double lon);

    void CalcShip1();
//    Point pointa;
//    Point pointb;
//    Point pointc;
//    Point pointd;
//    Point pointe;
//    Point pointf;

};

#endif // WIDGET_H
