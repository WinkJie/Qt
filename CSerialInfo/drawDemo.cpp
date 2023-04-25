#include "drawDemo.h"
#include <QFile>

DrawDemo::DrawDemo(QWidget *parent) :
    QWidget(parent)
{
    this->setWindowTitle(tr("3D展示"));
    this->setStyleSheet("background-color:black;");
    this->setGeometry(QRect(40,40,402,252));
    for(int i = 0;i<200;i++)
    {
        buffer[i] = static_cast<int>((sin((i*PI)/100)*100));
    }
    timer = new QTimer();
    connect(timer,&QTimer::timeout,this,&DrawDemo::flushBuff);
    timer->start(speed);
    QFile file(":/new/prefix/pic/StyleSheet.qss");
    file.open(QFile::ReadOnly);
    if(file.isOpen())
    {
        setStyleSheet(file.readAll());
        file.close();
        return ;
    }
    resize(QSize(600,800));
}

DrawDemo::~DrawDemo()
{
}

void DrawDemo::setBackground()
{
    this->setStyleSheet("background-color:black;");
}

void DrawDemo::flushBuff()
{
    int temp = buffer[0];
    for(int i = 0;i<200;i++)
    {
        buffer[i]=buffer[i+1];
        buffer[199]=temp;

    }
    // buffer[199]=temp;
    update();
}

void DrawDemo::killTime()
{
    timer->stop();
    qDebug()<<" 收到了父窗口的信号了"<<endl;
}

void DrawDemo::startTime()
{
    timer->start(5);
    qDebug()<<" 收到了父窗口的信号了,重新开始定时器！"<<endl;
}

//void drawDemo::startTime(int &a)
//{
//    timer->start(a);
//    qDebug()<<" 收到了父窗口的信号了,重新开始定时器！"<<endl;
//}

void DrawDemo::decelSpeed()
{
    if(speed>5)
    {
        speed+=10;
        timer->start(speed);
    }
}

void DrawDemo::addSpeed()
{
    if(speed>0)
    {
        speed = speed/5*4;
        timer->start(speed);
    }
}

void DrawDemo::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    QPoint beginPoint;
    QPoint endPoint;
    for(int i = 0;i<199;i++)
    {
        beginPoint.setX(2*i);
        beginPoint.setY(buffer[i]+125);
        endPoint.setX(2*i+i);
        endPoint.setY(buffer[i+1]+125);
        painter.setPen(Qt::blue);
        painter.drawLine(beginPoint,endPoint);

        beginPoint.setX(3*i+9);
        beginPoint.setY(buffer[i]+250);
        endPoint.setX(3*i+20);
        endPoint.setY(buffer[i+1]+250);
        painter.setPen(Qt::red);
        painter.drawPoint(beginPoint);
        painter.drawPoint(endPoint);

        painter.setPen(Qt::yellow);
        painter.drawRoundedRect(i,i*2,i,i*2,(qreal)5,(qreal)5);
    }
}
