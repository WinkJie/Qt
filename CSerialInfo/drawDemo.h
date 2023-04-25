#ifndef DRAWDEMO_H
#define DRAWDEMO_H

#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <qdebug.h>

//头文件
class DrawDemo : public QWidget
{
    Q_OBJECT

public:
    explicit DrawDemo(QWidget *parent = nullptr);
    ~DrawDemo();
    void setBackground();

    int speed = 10;

public slots:
    void flushBuff();
    void killTime();
    void startTime();
    //void startTime(int &a);
    void addSpeed();
    void decelSpeed();
protected:
    virtual void paintEvent(QPaintEvent *);

private:
    int buffer[200];
    QTimer * timer;
    const double PI = 3.1415926;
};


#endif // DrawDemo_H
