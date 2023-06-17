#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QtGui>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include "Polygon.h"

class Widget : public QWidget {
public:
    void paintEvent(QPaintEvent *event) override ;
};


class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = 0);
    ~MyWidget();
    void mouseMoveEvent(QMouseEvent *event) override ;
       void paintEvent(QPaintEvent *) override;
       void resizeEvent(QResizeEvent *) override;
   private:
       QPoint m_lastPos;   // 上一次鼠标位置
       QPixmap m_pixmap;   // 绘制轨迹的 pixmap
};



class MyWidgetNext:public QWidget
{
    Q_OBJECT
public:
    void mousePressEvent(QMouseEvent *event) override;
      void mouseMoveEvent(QMouseEvent *event) override;
      void paintEvent(QPaintEvent *) override;
  private:
      QPoint m_originPos; // 起始点位置
      QPoint m_lastPos;   // 上一次鼠标位置
      QPixmap m_pixmap{800, 600}; // 绘制轨迹的 pixmap，可以放到类变量声明处

};


class MyWidgetCircle:public QWidget
{
    Q_OBJECT
public:

    MyWidgetCircle(QWidget *parent = nullptr) ;
       ~MyWidgetCircle() override;

   protected:
       void mousePressEvent(QMouseEvent *event) override;
       void mouseMoveEvent(QMouseEvent *event) override;
       void resizeEvent(QResizeEvent *) override;
       void paintEvent(QPaintEvent *) override;

   private:
       QPoint m_lastPos;           // 上一次鼠标位置
       QPixmap m_pixmap;           // 绘制轨迹的 pixmap
       QPainter m_painter;         // 用于在 pixmap 上绘制
       QPainterPath m_path;        // 记录路径

};


class MyWidget1 : public QWidget
{
    Q_OBJECT

public:
    MyWidget1(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    QVector<QPoint> m_points;   // 记录所有鼠标点击位置的容器
    QPainterPath m_path;        // 记录路径

    bool m_close=false;
    QPoint m_lastPoint = QPoint(); // 记录上一个点的位置

};


class MyWidget2 : public QWidget
{
    Q_OBJECT

public:

    enum PAINTMODE
    {
        NONE,
        LINES,
        RECT,
        DELETEPOINT
    };
    MyWidget2(QWidget *parent = nullptr);

    PAINTMODE mode;
    void SetPaintMode(PAINTMODE modeParam);
public slots:
    void btnclicked();
    void btn1clicked();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    QVector<QPoint> m_points;          // 记录所有鼠标点击位置的容器
    bool m_isDrawing = false;          // 标记是否正在绘制
    QPoint m_start_pointer,m_end_pointer;
};


#endif // MYWIDGET_H
