#include "MyWidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
}

MyWidget::~MyWidget()
{

}

void MyWidget::mouseMoveEvent(QMouseEvent *event)
{
    // 获取鼠标当前位置
    QPoint newPos = event->pos();

    // 将当前位置与上一位置连接起来，绘制轨迹
    QPainter painter(&m_pixmap);
    painter.drawLine(m_lastPos, newPos);

    // 更新上一位置为当前位置
    m_lastPos = newPos;

    // 重绘窗口
    update();
}

void MyWidget::paintEvent(QPaintEvent *)
{
    // 在窗口中绘制 pixmap
    QPainter painter(this);
    painter.drawPixmap(0, 0, m_pixmap);
}

void MyWidget::resizeEvent(QResizeEvent *)
{
    // 窗口大小改变时重新创建 pixmap
    m_pixmap = QPixmap(size());
    m_pixmap.fill(Qt::white);
}


void MyWidgetNext::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        // 鼠标左键按下时初始化上一位置
        m_lastPos = event->pos();

        // 初始化 pixmap
        m_pixmap.fill(Qt::white);

        // 在 pixmap 上绘制起始点
        QPainter painter(&m_pixmap);
        painter.setPen(QPen(Qt::red, 2));
        painter.drawPoint(m_lastPos);

        // 更新窗口显示
        update();
    }
    else if (event->button() == Qt::RightButton)
    {
        // 鼠标右键按下时完成绘制
        m_pixmap.fill(Qt::white);
        update();
    }
}

void MyWidgetNext::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        // 获取鼠标当前位置
        QPoint newPos = event->pos();

        // 在 pixmap 上绘制当前线段，并与上一个点相连
        QPainter painter(&m_pixmap);
        painter.setPen(QPen(Qt::red, 2));
        painter.drawLine(m_lastPos, newPos);
        painter.drawLine(newPos, m_originPos);  // 连接末尾与起始点

        // 更新上一位置为当前位置
        m_lastPos = newPos;

        // 更新窗口显示
        update();
    }
}

void MyWidgetNext::paintEvent(QPaintEvent *)
{
    // 在窗口中绘制 pixmap
    QPainter painter(this);
    painter.drawPixmap(0, 0, m_pixmap);
}

MyWidgetCircle::MyWidgetCircle(QWidget *parent)
{

    // 初始化 pixmap 和 painter
    m_pixmap = QPixmap(size());
    m_pixmap.fill(Qt::white);
    m_painter.begin(&m_pixmap);
    m_painter.setRenderHint(QPainter::Antialiasing, true);

    // 设置鼠标跟踪
    setMouseTracking(true);
}

MyWidgetCircle::~MyWidgetCircle()
{
    // 结束绘制
    m_painter.end();
}

void MyWidgetCircle::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        // 左键按下，清除之前的路径记录
        m_path = QPainterPath();
        m_path.moveTo(event->pos());
        m_lastPos = event->pos();
    }
    else if (event->button() == Qt::RightButton && !m_path.isEmpty())
    {
        // 右键按下，将路径封闭并填充颜色
        m_path.closeSubpath();
        m_painter.fillPath(m_path, QBrush(Qt::blue));
        update();
    }

}

void MyWidgetCircle::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        // 左键移动，连接当前点和上一个点
        QPoint newPos = event->pos();
        m_path.lineTo(newPos);
        m_painter.drawLine(m_lastPos, newPos);
        m_lastPos = newPos;
        update();
    }
}

void MyWidgetCircle::resizeEvent(QResizeEvent *)
{
    // 窗口大小改变时重新创建 pixmap
    m_pixmap = QPixmap(size());
    m_pixmap.fill(Qt::white);
    m_painter.begin(&m_pixmap);
}

void MyWidgetCircle::paintEvent(QPaintEvent *)
{
    // 在窗口中绘制 pixmap
    QPainter painter(this);
    painter.drawPixmap(0, 0, m_pixmap);
}

MyWidget1::MyWidget1(QWidget *parent)
{
    Q_UNUSED(parent)
}

void MyWidget1::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton&&!m_close) {
        m_points.append(event->pos());
    }
}

void MyWidget1::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && !m_points.isEmpty()) {
        m_points.last() = event->pos();
        update();  // 触发实时重绘
    }
}

void MyWidget1::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_points.append(event->pos());
        // 若前后两个点相同，说明是闭合图形
        if (m_points.first() == m_points.last())
        {
            update();
        }
    }
}

void MyWidget1::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    if (m_points.size() > 1)
    {
        for (int i = 0; i < m_points.size() - 1; ++i)
        {
            painter.drawLine(m_points.at(i), m_points.at(i + 1));
        }

        // 若图形闭合，填充颜色
        // 若图形闭合，填充颜色
        if (m_points.size() > 2 && !m_close)
        {
            if (m_points.first() == m_points.last())
            {
                QPainterPath path;
                path.addPolygon(QPolygon(m_points));
                painter.fillPath(path, QColor("#ff8888"));
                m_close = true;  // 标记图形已经闭合
            }
        }
    }
}

MyWidget2::MyWidget2(QWidget *parent)
{
    mode=NONE;
    QPushButton *btn=new QPushButton("RECT",this);
    QPushButton *btn1=new QPushButton("DELETE",this);
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(btn);
    layout->addWidget(btn1);
    connect(btn,&QPushButton::clicked,this,&MyWidget2::btnclicked);
    connect(btn1,&QPushButton::clicked,this,&MyWidget2::btn1clicked);
    setLayout(layout);
}

void MyWidget2::SetPaintMode(MyWidget2::PAINTMODE modeParam)
{
    if(modeParam>=NONE&&modeParam<=RECT)
    {
        mode=modeParam;
    }
}

void MyWidget2::btnclicked()
{
    mode=RECT;
}

void MyWidget2::btn1clicked()
{
    mode=DELETEPOINT;
}

void MyWidget2::mousePressEvent(QMouseEvent *event)
{
    switch (mode)
    {
    case NONE:
    {}break;
    case LINES:
    {
        if (event->button() == Qt::LeftButton &&m_points.size()<4)
        {
            m_points.append(event->pos());
            m_isDrawing = true;      // 开始绘制

            if(m_points.size()==1)
            {
                m_start_pointer=event->pos();
            }
            if(m_points.size()==4)
                m_end_pointer=event->pos();
            update();
        }
    }break;
    case RECT:
    {
        if (event->button() == Qt::LeftButton &&m_points.size()<4)
        {
            m_points.append(event->pos());
            m_isDrawing = true;      // 开始绘制

            if(m_points.size()==1)
            {
                m_start_pointer=event->pos();
            }
            if(m_points.size()==4)
                m_end_pointer=event->pos();
            update();
        }
    }break;
    case DELETEPOINT:
    {
        if(event->button() == Qt::LeftButton)
        {
            int num=m_points.size();
            if(m_points.size()>0)
            {
                //                m_points.erase(m_points.end());
                m_points.remove(num);
            }
            update();
        }
    }

    }

}

void MyWidget2::mouseMoveEvent(QMouseEvent *event)
{
    if (!m_isDrawing) {
        return;
    }

    // 只绘制一条线段
    if (m_points.size() == 4)
    {
        m_isDrawing = false;   // 结束绘制
    }
    update();              // 更新界面
}

void MyWidget2::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    switch (mode)
    {
    case NONE:
    {}break;
    case LINES:
    {
        if (m_points.size() > 1) {
            for (int i = 0; i < 1; ++i)
            {
                painter.drawLine(m_points.at(i), m_points.at(i + 1));
            }
        }
    }break;
    case RECT:
    {
        if (m_points.size() > 1)
        {
            for (int i = 0; i < m_points.size() - 1; ++i)
            {
                painter.drawLine(m_points.at(i), m_points.at(i + 1));
                if(m_points.size()==4)
                {
                    painter.drawLine(m_start_pointer,m_end_pointer);

                    QPainterPath path;
                    path.addPolygon(QPolygon(m_points));
                    painter.fillPath(path, QColor("#ff8888"));
                }
            }
            // 如果正在绘制，将最后一个点和第一个点连接起来，形成闭环
            if (/*m_isDrawing && */m_points.size() > 2 && m_points.last() == m_points.first())
            {
                QPainterPath path;
                path.addPolygon(QPolygon(m_points));
                painter.fillPath(path, QColor("#ff8888"));
            }
        }
    }break;
    case DELETEPOINT:
    {

    }

    }

}



void Widget::paintEvent(QPaintEvent *event)
{
    // 定义直线的系数
    double A = 1.0, B = -1.0, C = 0.0;
    // 定义点的坐标
    double x = 100.0, y = 200.0;

    // 计算点到直线的距离
    double numerator = std::abs(A*x + B*y + C);
    double denominator = std::sqrt(A*A + B*B);
    double distance = numerator / denominator;

    QPainter painter(this);
    painter.setPen(Qt::blue);

    // 画出直线
    painter.drawLine(0, 0, 400, 400);

    // 画出点和垂线
    painter.drawEllipse(x - 3, y - 3, 6, 6);
    painter.drawLine(x, y, x - (B*distance), y + (A*distance));

    // 显示距离
    painter.drawText(QPointF(x + 10, y - 10), QString::number(distance));
}
