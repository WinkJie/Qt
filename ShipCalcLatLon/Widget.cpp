#include "Widget.h"
#include <math.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(800,600);
    CalcShip(125,70,23,56);

    QPushButton *btn=new QPushButton(this);
    btn->setText("s45");
    connect(btn,&QPushButton::clicked,this,&Widget::open);
}

Widget::~Widget()
{

}

void Widget::open()
{
    QString str="C://QT";
    QString fileName = QFileDialog::getOpenFileName(this, "选择文件", str, "文本文件 (*.txt)");
        if (!fileName.isEmpty()) {
          QFile file(fileName);
          if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QString content = in.readAll();
            file.close();
            qDebug() << "File content:";
            qDebug().noquote() << content;
          } else {
           qDebug()<<"错误"<<"无法打开文件";
          }
        } else {
          qDebug()<<"提示"<<"未选择文件";
        }

}

void Widget::CalcShip(double length, double width, double lat, double lon)
{
    double side_length = length * 5.0 / 4.0; // 边长
    double half_side_length = side_length / 2.0; // 半个边长
    double half_width = width / 2.0; // 半个宽度
    double angle = atan2(width / 2, half_side_length); // 左侧边夹角
    double sin_angle = sin(angle);
    double cos_angle = cos(angle);

    // 计算船头和船尾两个点的坐标
    double front_lat = lat + half_width * cos(angle);
    double front_lon = lon + half_width * sin(angle);
    double back_lat = lat - half_width * cos(angle);
    double back_lon = lon - half_width * sin(angle);

    // 计算左右两边的其它四个点的坐标
    double left_front_lat = lat + half_width * cos_angle + half_side_length * sin_angle;
    double left_front_lon = lon + half_width * sin_angle - half_side_length * cos_angle;
    double left_middle_lat = lat + half_side_length * cos_angle;
    double left_middle_lon = lon - half_side_length * sin_angle;

    double left_back_lat = lat - half_width * cos_angle + half_side_length * sin(angle);
    double left_back_lon = lon + half_width * sin(angle) - half_side_length * cos(angle);

    double right_front_lat = lat + half_width * cos(angle) - half_side_length * sin(angle);
    double right_front_lon = lon + half_width * sin(angle) + half_side_length * cos(angle);
    double right_middle_lat = lat - half_side_length * cos(angle);
    double right_middle_lon = lon + half_side_length * sin(angle);
    double right_back_lat = lat - half_width * cos(angle) - half_side_length * sin(angle);
    double right_back_lon = lon + half_width * sin(angle) + half_side_length * cos(angle);

    // 输出左右两边的四个点的坐标
    qDebug() << left_front_lat << " " << left_front_lon << endl;
    qDebug() << left_middle_lat << " " << left_middle_lon << endl;
    qDebug() << left_back_lat << " " << left_back_lon << endl;
    qDebug() << right_front_lat << " " << right_front_lon << endl;
    qDebug() << right_middle_lat << " " << right_middle_lon << endl;
    qDebug() << right_back_lat << " " << right_back_lon << endl;


}

void Widget::CalcShip1()
{
    double lat, lon; // 中心点的经纬度
    double length, width; // 船长和船宽
    double left_side, right_side; // 左右两侧边的长度


    // 计算左右两侧边上的四个点的经纬度
    double angle = atan2(width / 2, left_side); // 左侧边夹角
    double sin_angle = sin(angle);
    double cos_angle = cos(angle);
    double left_front_lat = lat + sin_angle * length / 2; // 左前点纬度
    double left_front_lon = lon + cos_angle * length / 2; // 左前点经度
    double left_back_lat = lat - sin_angle * length / 2; // 左后点纬度
    double left_back_lon = lon - cos_angle * length / 2; // 左后点经度
    angle = atan2(width / 2, right_side); // 右侧边夹角
    sin_angle = sin(angle);
    cos_angle = cos(angle);
    double right_front_lat = lat + sin_angle * length / 2; // 右前点纬度
    double right_front_lon = lon - cos_angle * length / 2; // 右前点经度
    double right_back_lat = lat - sin_angle * length / 2; // 右后点纬度
    double right_back_lon = lon + cos_angle * length / 2; // 右后点经度



//    double k = -(C.longitude - B.longitude) / (C.latitude - B.latitude);
//    double x = (k * (A.latitude - B.latitude) + (C.latitude - B.latitude) / (C.longitude - B.longitude) * B.longitude - A.longitude) / (k + (C.latitude - B.latitude) / (C.longitude - B.longitude));
//    double y = k * (x - A.longitude) + A.latitude;

//    Point D = {y, x};

}
