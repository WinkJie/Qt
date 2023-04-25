#include "Widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPixmap pixmap;
    pixmap.load(":/new/prefix1/123.png");

    //背景透明，没设置这个的话会有毛边，如上面gif图
    setAttribute(Qt::WA_TranslucentBackground);
//    resize(100,100);
    resize(pixmap.size());
    setMask(pixmap.mask());
}

Widget::~Widget()
{

}

//void Widget::resize(const QSize &e)
//{
//    QBitmap bmp(size());
//    bmp.fill();
//    QPainter p(&bmp);
//    p.setRenderHint(QPainter::Antialiasing);
//    //p.drawRoundedRect(bmp.rect(), 20, 20); //四个角都是圆弧
//    //只要上边角圆弧
//    int arcR = 10; //圆弧大小
//    QRect rect = this->rect().adjusted(0, 0, 0, 0);
//    QPainterPath path;
//    //逆时针
//    path.moveTo(arcR, 0);
//    //左上角
//    path.arcTo(0, 0, arcR * 2, arcR * 2, 90.0f, 90.0f);
//    path.lineTo(0, rect.height()-arcR);
//    //左下角
//    path.arcTo(0, rect.height() - arcR * 2 , arcR * 2, arcR * 2, 180.0f, 90.0f);
//    path.lineTo(rect.width(), rect.height());
//    //右下角
//    path.arcTo(rect.width() - arcR * 2, rect.height() - arcR * 2 , arcR * 2, arcR * 2, 270.0f, 90.0f);
//    path.lineTo(rect.width(), arcR);
//    //右上角
//    path.arcTo(rect.width() - arcR * 2, 0, arcR * 2, arcR * 2, 0.0f, 90.0f);
//    path.lineTo(arcR, 0);
//    p.drawPath(path);
//    //此行代码必须添加，不然无法达到正常的显示
//    p.fillPath(path, QBrush(Qt::red));
//    setMask(bmp);
//    return resizeEvent(e);

////    return QDialog::resizeEvent(e);

//}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        dragPosition = event->globalPos() - frameGeometry().topLeft();
    }else if(event->button() == Qt::RightButton){
        close();
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton){
        move(event->globalPos() - dragPosition);
    }
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter p(this);
    p.drawPixmap(0,0,QPixmap(":/new/prefix1/123.png"));

//  画出不规则图形
//    {
//        //创建画笔
//        QPainter painter(this);

//        //创建画刷
//        QBrush brush(QColor(0, 0, 255), Qt::SolidPattern);
//        //使用画刷
//        painter.setBrush(brush);

//        //定义四个点
//        static const QPointF points[4] = {
//            QPointF(270.0, 80.0),
//            QPointF(290.0, 10.0),
//            QPointF(350.0, 30.0),
//            QPointF(390.0, 70.0)
//        };
//        //使用四个点绘制多边形
//        painter.drawPolygon(points, 4);
//    }
}


