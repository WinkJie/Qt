#ifndef POLYGON_H
#define POLYGON_H

#include <QObject>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QMouseEvent>


#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QTimer>
#include <QPainter>

#include <iostream>
#include <cmath>
#include <QPaintEvent>
#include <QPainter>
#include <QPoint>
#include <QBrush>
#include <QPen>
#include <QColor>
#include <QPointer>

using namespace std;

class MainWindow : public QMainWindow {
public:
    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent), a_x(-10), a_y(0) {
        this->setWindowTitle("Distance from a point to a line");
        this->resize(800, 600);

        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &MainWindow::updatePosition);
        timer->start(1000); // 每 50ms 更新一次点a的位置
    }

protected:
    void paintEvent(QPaintEvent* event) override
    {
        Q_UNUSED(event);
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        QPoint a(a_x * 20 + 400, -a_y * 20 + 300); // 将点a的坐标转换为窗口坐标系

        // 计算点a到直线的垂线的垂足，即交点
        QPoint point_1(1 * 20 + 400, 2 * 20 + 300);
        QPoint point_2(9 * 20 + 400, -15 * 20 + 300);

        double k = (double)(point_2.y() - point_1.y()) / (double)(point_2.x() - point_1.x());
        double b = point_1.y() - k * point_1.x();
        double x = (k * a.y() + a.x() - k * b) / (k * k + 1);
        double y = k * x + b;
        QPoint foot_point((int)x, (int)y); // 垂足的坐标

        // 画出点a和直线以及垂线
        painter.setPen(QPen(Qt::red, 5));
        painter.drawPoint(a);
        painter.setPen(QPen(Qt::black, 2));
        painter.drawLine(point_1, point_2);
        painter.drawLine(a, foot_point);
        
        painter.drawText(a + QPoint(10, -10), QString("A"));
        painter.drawText(foot_point + QPoint(-30, -10), QString("H"));
        painter.drawText((a + foot_point) / 2 + QPoint(10, 10), QString("d = %1").arg(distance(a, foot_point)));
    }

private:
    int a_x; // 点a的横坐标
    int a_y; // 点a的纵坐标
    QTimer* timer; // 更新点a位置的定时器

    // 计算两点之间的距离
    double distance(QPoint& a, QPoint& b)
    {
        return sqrt((a.x() - b.x()) * (a.x() - b.x()) + (a.y() - b.y()) * (a.y() - b.y()));
    }

    // 每次定时器更新时，计算点a的坐标
    void updatePosition() {
        if(a_x<-5)
            a_x += 1;
        else if(a_x>15)
            a_x-=1;
        a_y = sqrt(9 - a_x*a_x - 6);
        update();
//        if(a_y > 0) { // 当a_y大于0时，表示点a还在圆内
//            update(); // 通知窗口重绘
//        } else {
//            timer->stop(); // 当点a已经不在圆内时，停止更新
//        }
    }
};

class MyMotionWidget : public QWidget
{
public:
    MyMotionWidget(QWidget *parent = nullptr)
        : QWidget(parent), x_(50), y_(100), step_(2)
    {
        // 定义直线的系数
        A_ = 1.0, B_ = -1.0, C_ = 0.0;
        // 每 20 毫秒刷新一次界面
        timer_ = new QTimer(this);
        connect(timer_, &QTimer::timeout, this, [this]() { update(); });
        timer_->start(20);
    }

protected:
    void paintEvent(QPaintEvent *event) override
    {
        // 根据步长更新点的坐标
        x_ += step_;
        if (x_ > 250 || x_ < 50) { // 到达边缘时改变步长方向
            step_ = -step_;
        }
        // 计算点到直线的距离
        double numerator = std::abs(A_*x_ + B_*y_ + C_);
        double denominator = std::sqrt(A_*A_ + B_*B_);
        double distance = numerator / denominator;

        QPainter painter(this);
        painter.setPen(Qt::blue);

        // 画出直线
        //painter.drawLine(0, 0, width(), height());

        // 画出点和垂线
        painter.setPen(Qt::red);
        painter.drawEllipse(x_ - 3, y_ - 3, 6, 6);
        painter.drawLine(x_, y_, x_ - (B_*distance), y_ + (A_*distance));

        // 显示距离
        painter.drawText(QPointF(x_ + 10, y_ - 10), QString::number(distance));
    }

private:
    QTimer *timer_;
    double A_, B_, C_; // 直线的系数
    double x_, y_; // 运动的点的坐标
    int step_; // 运动的步长
};


class Polygon :public QObject
{
    Q_OBJECT
public:
    explicit Polygon(QObject *parent = nullptr) : QObject(parent) {}

    void addPoint(const QPointF &point)
    {
        m_points.append(point);
    }

    void clearPoints()
    {
        m_points.clear();
    }

    QPolygonF createPolygon() const
    {
        return QPolygonF(m_points);
    }

    QPolygonF getPolygon() const
    {
        return m_polygon;
    }

signals:
    void polygonChanged();

public slots:
     void mousePressEvent(QMouseEvent *event);

private:
    QVector<QPointF> m_points;
    QPolygonF m_polygon = QPolygonF();
};



#endif // POLYGON_H
