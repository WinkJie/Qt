#include "Widget.h"
#include <qdebug.h>
#include <bits/stdc++.h>
#include <iostream>
#include <QString>
using namespace std;

const double EPSILON = 1e-6; // 零点误差

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    Do();
    Do1();
}

Widget::~Widget()
{
}

//bool Widget::dcmp(double x, double y)
//{
//    const double eps = 1e-8;
//    return fabs(x - y) < eps;
//}

bool Widget::line_intersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    double v1_x = x2 - x1;
    double v1_y = y2 - y1;
    double v2_x = x4 - x3;
    double v2_y = y4 - y3;
    double v3_x = x1 - x3;
    double v3_y = y1 - y3;

    double t1 = v1_x * v2_y - v1_y * v2_x;
    double t2 = v2_x * v3_y - v2_y * v3_x;

    if (t1 == 0.0 && t2 == 0.0) {
        // two lines are collinear
        return true;
    }

    if (t1 * t2 < 0.0) {
        // two lines intersect
        return true;
    }

    return false;
}

bool Widget::line_intersect1(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    double v1_x = x2 - x1;
    double v1_y = y2 - y1;
    double v2_x = x4 - x3;
    double v2_y = y4 - y3;
    double v3_x = x1 - x3;
    double v3_y = y1 - y3;

    double t1 = (v2_x * v3_y - v2_y * v3_x) / (v1_x * v2_y - v1_y * v2_x);
    double t2 = (v1_x * v3_y - v1_y * v3_x) / (v1_x * v2_y - v1_y * v2_x);

    if (t1 >= 0 && t1 <= 1 && t2 >= 0 && t2 <= 1) {
        return true;
    }
    else {
        return false;
    }
}

bool Widget::line_intersect2(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    double v1_x = x2 - x1;
    double v1_y = y2 - y1;
    double v2_x = x4 - x3;
    double v2_y = y4 - y3;
    double v3_x = x1 - x3;
    double v3_y = y1 - y3;

    double t1 = (v2_x * v3_y - v2_y * v3_x) / (v1_x * v2_y - v1_y * v2_x);
    double t2 = (v1_x * v3_y - v1_y * v3_x) / (v1_x * v2_y - v1_y * v2_x);

    if ((t1 >= 0 && t1 <= 1 && t2 >= 0 && t2 <= 1) ||  // 普通相交的情况
            (v1_x * v3_y == v1_y * v3_x && v2_x * v3_y == v2_y * v3_x &&  // 两条线段共线
             ((v3_x >= 0 && v3_x <= v1_x && v3_y >= 0 && v3_y <= v1_y) ||  // 公共点在第一条线段内
              (-v3_x >= 0 && -v3_x <= v2_x && -v3_y >= 0 && -v3_y <= v2_y)))) {  // 公共点在第二条线段内
        return true;
    }
    else {
        return false;
    }
}

typedef Point Vector;

//bool Widget::onSegment(const Point& p, const Point& a, const Point& b)
//{
//    return dcmp((p - a).Cross(b - a), 0) && dcmp((p - a).Dot(p - b), 0);
//}
//// 判断两条线段是否相交
//bool Widget::intersect(const Point& a1, const Point& a2, const Point& b1, const Point& b2)
//{
//    double k1 = (a2.lat - a1.lat) / (a2.lon - a1.lon);
//    double b_1 = a1.lat - k1 * a1.lon;
//    double k2 = (b2.lat - b1.lat) / (b2.lon - b1.lon);
//    double b_2 = b1.lat - k2 * b1.lon;

//    if (!dcmp(k1 - k2, 0)) { // 如果两条线段共线，则判断是否有重合部分
//        if (onSegment(a1, b1, b2) || onSegment(a2, b1, b2) ||
//                onSegment(b1, a1, a2) || onSegment(b2, a1, a2))
//            return true;
//        else
//            return false;
//    } else {
//        double x = (b_2 - b_1) / (k1 - k2); // 计算交点横坐标
//        if (x <= std::max(std::min(a1.lon, a2.lon), std::min(b1.lon, b2.lon)) ||
//                x >= std::min(std::max(a1.lon, a2.lon), std::max(b1.lon, b2.lon)))
//            return false;
//        else
//            return true;
//    }
//}


void Widget::Do()
{

    QVector<double*> a;
    double op[4]={0};
    op[0]=0;
    op[1]=0;
    op[2]=5;
    op[2]=5;
    a.push_back(op);

    double m_Ship_head[2];
    double m_Ship_tail[2];
    double m_Ship_right_front[2];
    double m_Ship_right_middle[2];
    double m_Ship_right_tail[2];
    double m_Ship_left_front[2];
    double m_Ship_left_middle[2];
    double m_Ship_left_tail[2];

    memset(&m_Ship_head,0,sizeof (double)*2);
    memset(&m_Ship_tail,0,sizeof (double)*2);
    memset(&m_Ship_right_front,0,sizeof (double)*2);
    memset(&m_Ship_right_middle,0,sizeof (double)*2);
    memset(&m_Ship_right_tail,0,sizeof (double)*2);
    memset(&m_Ship_left_front,0,sizeof (double)*2);
    memset(&m_Ship_left_middle,0,sizeof (double)*2);
    memset(&m_Ship_left_tail,0,sizeof (double)*2);

    qDebug()<<"不交叉"<<line_intersect1(0,0,5,5,5,0,5,4);
    qDebug()<<"交叉"<<line_intersect1(0,0,5,5,5,0,5,5);
    qDebug()<<"交叉"<<line_intersect1(0,0,5,5,5,0,5,9);
    qDebug()<<"共线"<<line_intersect1(0,0,5,5,0,0,5,5);


    qDebug()<<"不交叉"<<line_intersect(0,0,5,5,5,0,5,4);
    qDebug()<<"交叉"<<line_intersect(0,0,5,5,5,0,5,5);
    qDebug()<<"交叉"<<line_intersect(0,0,5,5,5,0,5,9);
    qDebug()<<"共线"<<line_intersect(0,0,5,5,0,0,5,5);

    qDebug()<<"共线"<<line_intersect2(0,0,5,5,0,0,5,5);

}

double Widget::cross(const Point &p0, const Point &p1, const Point &p2)
{
    return (p1.lon - p0.lon) * (p2.lat - p0.lat) - (p2.lon - p0.lon) * (p1.lat - p0.lat);
}

bool Widget::isIntersect(const Point &A, const Point &B, const Point &C, const Point &D)
{
    double c1 = cross(A, B, C); // C 与 AB 的叉积
    double c2 = cross(A, B, D); // D 与 AB 的叉积
    double c3 = cross(C, D, A); // A 与 CD 的叉积
    double c4 = cross(C, D, B); // B 与 CD 的叉积

    // 判断交点是否在两条线段上
    if (((c1 > 0 && c2 < 0) || (c1 < 0 && c2 > 0)) &&
            ((c3 > 0 && c4 < 0) || (c3 < 0 && c4 > 0))) {
        return true; // 相交
    } else {
        return false; // 不相交
    }
}

Point Widget::getIntersection(const Point &A, const Point &B, const Point &C, const Point &D)
{
    double k1 = (B.lat - A.lat) / (B.lon - A.lon);
    double k2 = (D.lat - C.lat) / (D.lon - C.lon);
    double b1 = A.lat - k1 * A.lon;
    double b2 = C.lat - k2 * C.lon;

    Point p;
    p.lon = (b2 - b1) / (k1 - k2);
    p.lat = k1 * p.lon + b1;

    return p;
}

void Widget::Do1()
{
    Point A{0, 0}, B{2, 2}, C{2, 0}, D{0, 2};
    if (isIntersect(A, B, C, D)) {
        Point P = getIntersection(A, B, C, D);
        qDebug() << QString::fromLocal8Bit("线段AB和CD相交，交点坐标为：") << P.lon << ", " << P.lat << endl;
    } else {
        qDebug() << QString::fromLocal8Bit("线段AB和CD不相交") << endl;
    }
}


double Widget::distance(Point p1, Point p2)
{
    const double R = 6371000; // 地球半径，单位为m
    double lat1 = p1.lat * M_PI / 180.0;
    double lat2 = p2.lat * M_PI / 180.0;
    double dlat = (p2.lat - p1.lat) * M_PI / 180.0;
    double dlon = (p2.lon - p1.lon) * M_PI / 180.0;
    double a = sin(dlat/2) * sin(dlat/2) +
            cos(lat1) * cos(lat2) *
            sin(dlon/2) * sin(dlon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    return R * c;
}

double Widget::point_to_line_distance(Point p, Point a, Point b)
{
    double A = distance(p, b);
    double B = distance(p, a);
    double C = distance(a, b);
    double s = (A + B + C) / 2;
    double area = sqrt(s * (s - A) * (s - B) * (s - C));
    return 2 * area / C;
}

bool Widget::will_collide(Point boat_center, double boat_width, double boat_length, Point coast_point1, Point coast_point2)
{
    const double HALF_PI = M_PI / 2;
    double boat_half_width = boat_width / 2;
    double boat_half_length = boat_length / 2;
    Point boat_points[6];

    for (int i = 0; i < 6; i++) {
        double angle = HALF_PI + i * M_PI / 3;
        double lat = boat_center.lat + cos(angle) * boat_half_length / 111111;
        double lon = boat_center.lon + sin(angle) * boat_half_width / abs(cos(boat_center.lat * M_PI / 180.0)) / 111111;
        boat_points[i] = {lat, lon};
    }

    double min_distance = INFINITY;
    for (int i = 0; i < 6; i++) {
        Point a = boat_points[i];
        Point b = boat_points[(i+1) % 6];
        double d = point_to_line_distance(boat_center, a, b);
        if (d < min_distance) {
            min_distance = d;
        }
    }

    double distance1 = point_to_line_distance(boat_center, coast_point1, coast_point2);
    double distance2 = min_distance;

    return distance1 < distance2;
}

bool Widget::will_collide1(Point boat_center, double boat_width, double boat_length, Point coast_point1, Point coast_point2)
{
    Point boat_points[6];
    calculate_boat_points(boat_center, boat_width, boat_length, boat_points);

    double min_distance = INFINITY;
    for (int i = 0; i < 6; i++) {
        Point a = boat_points[i];
        Point b = boat_points[(i+1) % 6];
        double d = point_to_line_distance(boat_center, a, b);
        if (d < min_distance) {
            min_distance = d;
        }
    }

    double distance1 = point_to_line_distance(boat_center, coast_point1, coast_point2);
    double distance2 = min_distance;

    return distance1 < distance2;
}

void Widget::calculate_boat_points(Point center, double width, double length, Point *points)
{
    const double HALF_PI = M_PI / 2;
    double half_width = width / 2;
    double half_length = length / 2;

    // 计算顶点相对于船头方向的角度
    double angles[] = {0.0, M_PI/3, 2*M_PI/3, M_PI, 4*M_PI/3, 5*M_PI/3};

    for (int i = 0; i < 6; i++) {
        double angle = HALF_PI + angles[i];
        double lat = center.lat + cos(angle) * half_length / 111111;
        double lon = center.lon + sin(angle) * half_width / abs(cos(center.lat * M_PI / 180.0)) / 111111;
        points[i] = {lat, lon};
    }
}



void Widget::dataTest()
{
    Point boat_center = {31.23, 121.47}; // 小船中心点经纬度
    double boat_width = 4.5; // 小船宽度，单位为m
    double boat_length = 8.0; // 小船长度，单位为m
    Point coast_point1 = {31.25, 121.45}; // 海岸线上一点经纬度
    Point coast_point2 = {31.26, 121.48}; // 海岸线上另一点经纬度

    bool will_collides = will_collide(boat_center, boat_width, boat_length, coast_point1, coast_point2);

    if (will_collides)
    {
        qDebug() << "The boat will collide with the coast!" << endl;
    }
    else
    {
        qDebug() << "The boat will not collide with the coast." << endl;
    }
}



int calca()
{
    qDebug() << "请输入船的长和宽：";
    double ship_length, ship_width;

    qDebug() << "请输入船中心点的经纬度坐标：";
    double ship_longitude, ship_latitude;

    // 定义方向和长度关系
    int length1, length2, length3, length4, length5, length6;
    int front_dir;
    qDebug() << "请输入船头/船尾方向（0为朝东，1为东南，依次类推）：";


    // 计算左上角和右下角顶点坐标
    double topleft_longitude = ship_longitude - (2.0 / 5) * ship_length;
    double topleft_latitude = ship_latitude + ship_width / 2;
    double bottomright_longitude = ship_longitude + (3.0 / 5) * ship_length;
    double bottomright_latitude = ship_latitude - ship_width / 2;

    // 计算各个端点经纬度坐标
    double point1_longitude, point1_latitude;
    double point2_longitude, point2_latitude;
    double point3_longitude, point3_latitude;
    double point4_longitude, point4_latitude;
    double point5_longitude, point5_latitude;
    double point6_longitude, point6_latitude;

    double north_distance = sqrt(ship_width * ship_width + (length1 - length2) * (length1 - length2));
    double north_direction = atan2(ship_width, length1 - length2);
    point1_longitude = ship_longitude + sin(M_PI / 2 - north_direction) * north_distance;
    point1_latitude = ship_latitude + cos(M_PI / 2 - north_direction) * north_distance;
    point6_longitude = ship_longitude - sin(M_PI / 2 - north_direction) * north_distance;
    point6_latitude = ship_latitude - cos(M_PI / 2 - north_direction) * north_distance;

    double northeast_distance = sqrt(ship_width * ship_width + (length2 - length3) * (length2 - length3));
    double northeast_direction = atan2(ship_width, length2 - length3);
    point2_longitude = ship_longitude + sin(M_PI / 2 - northeast_direction) * northeast_distance;
    point2_latitude = ship_latitude + cos(M_PI / 2 - northeast_direction) * northeast_distance;
    point5_longitude = ship_longitude - sin(M_PI / 2 - northeast_direction) * northeast_distance;
    point5_latitude = ship_latitude - cos(M_PI / 2 - northeast_direction) * northeast_distance;

    double east_distance = sqrt(ship_length * ship_length + (length3 - length4) * (length3 - length4));
    double east_direction = atan2(length3 - length4, ship_length);
    point3_longitude = ship_longitude + cos(east_direction) * east_distance;
    point3_latitude = ship_latitude + sin(east_direction) * east_distance;
    point4_longitude = ship_longitude - cos(east_direction) * east_distance;
    point4_latitude = ship_latitude - sin(east_direction) * east_distance;

    // 输出结果
    qDebug() << "船的顶点经纬度坐标为：" << endl;
    qDebug() << "(" << point1_longitude << ", " << point1_latitude << ")" << endl;
    qDebug() << "(" << point2_longitude << ", " << point2_latitude << ")" << endl;
    qDebug() << "(" << point3_longitude << ", " << point3_latitude << ")" << endl;
    qDebug() << "(" << point4_longitude << ", " << point4_latitude << ")" << endl;
    qDebug() << "(" << point5_longitude << ", " << point5_latitude << ")" << endl;
    qDebug() << "(" << point6_longitude << ", " << point6_latitude << ")" << endl;

    return 0;
}







//// 向量结构体
//struct Vector {
//  double x, y;
//  Vector(double _x=0, double _y=0): x(_x), y(_y) {}
//  // 向量加法
//  Vector operator + (const Vector& rhs) const {
//    return Vector(x + rhs.x, y + rhs.y);
//  }
//  // 向量减法
//  Vector operator - (const Vector& rhs) const {
//    return Vector(x - rhs.x, y - rhs.y);
//  }
//  // 向量数量积
//  double operator * (const Vector& rhs) const {
//    return x * rhs.x + y * rhs.y;
//  }
//  // 向量叉积
//  double operator ^ (const Vector& rhs) const {
//    return x * rhs.y - y * rhs.x;
//  }
//};

//// 判断点 C 是否在线段 AB 上
//bool onSegment(const Vector& A, const Vector& B, const Vector& C) {
//  Vector AB = B - A, AC = C - A;
//  if (fabs((AB ^ AC)) >= EPSILON) { // C 不在 AB 所在直线上
//    return false;
//  }
//  double u = AB * AC / (AB * AB);
//  return u >= 0 && u <= 1;
//}

//// 计算两条直线之间的交点，如果平行则返回 empty
//Vector getIntersection(const Vector& A, const Vector& B,
//                        const Vector& C, const Vector& D) {
//  Vector AB = B - A, CD = D - C;
//  double k = (AB ^ CD);
//  if (fabs(k) < EPSILON) { // 平行或重合
//    return Vector();
//  }
//  Vector AC = C - A;
//  double t = (CD ^ AC) / k;
//  return A + AB * t;
//}

//// 判断线段 AB 和 CD 是否相交，如果相交返回 true，否则返回 false
//bool intersected(const Vector& A, const Vector& B,
//                 const Vector& C, const Vector& D) {
//  if (onSegment(A, B, C) || onSegment(A, B, D) ||
//      onSegment(C, D, A) || onSegment(C, D, B)) { // 端点自身在对方的线段上
//    return true;
//  }
//  Vector AB = B - A, AC = C - A, AD = D - A;
//  Vector CD = D - C, CA = A - C, CB = B - C;
//  // 判断线段相交的两个区间在对方上的投影是否存在交集
//  return (AB ^ AC) * (AB ^ AD) <= 0 && (CD ^ CA) * (CD ^ CB) <= 0;
//}

//int main() {
//  // 假设有六个点和一条线段，其中每个点都有其对应的经度和纬度，这里用数组存储
//  double points[6][2] = {{lat1, lng1}, {lat2, lng2}, ..., {lat6, lng6}};
//  double line[2][2] = {{latA, lngA}, {latB, lngB}};

//  // 计算每条边与线之间的关系
//  bool collide = false;;
//  for (int i = 0; i < 6; ++i) {
//    Vector A(points[i][1], points[i][0]);
//    Vector B(points[(i + 1) % 6][1], points[(i + 1) % 6][0]);
//    if (intersected(A, B, Vector(line[0][1], line[0][0]),
//                      Vector(line[1][1], line[1][0]))) {
//      collide = true;
//      break;
//    }
//  }

//  // 根据计算结果输出不同的信息
//  if (collide) {
//    cout << "线段穿过了六边形" << endl;
//  } else {
//    cout << "线段没有穿过六边形" << endl;
//  }

//  return 0;
//}

//// 计算两点间距离（单位：米）
//double calcDist(double lat1, double lng1, double lat2, double lng2) {
//    double earthRadius = 6371000.0; // 地球半径，单位：米

//    double dLat = (lat2 - lat1) * M_PI / 180.0;
//    double dLng = (lng2 - lng1) * M_PI / 180.0;

//    double a = sin(dLat/2) * sin(dLat/2) + cos(lat1 * M_PI / 180.0) * cos(lat2 * M_PI / 180.0)
//           * sin(dLng/2) * sin(dLng/2);
//    double c = 2 * atan2(sqrt(a), sqrt(1-a));

//    return earthRadius * c;
//}

//// 判断两个线段是否有交点
//bool haveIntersection(double lat1, double lng1, double lat2, double lng2,
//                      double lat3, double lng3, double lat4, double lng4) {
//    // 计算每个线段的长度和方向
//    double len1 = calcDist(lat1, lng1, lat2, lng2);
//    double len2 = calcDist(lat3, lng3, lat4, lng4);
//    double dir1 = atan2((lat2 - lat1) * M_PI / 180.0, (lng2 - lng1) * M_PI / 180.0);
//    double dir2 = atan2((lat4 - lat3) * M_PI / 180.0, (lng4 - lng3) * M_PI / 180.0);

//    // 如果两条线段平行，则没有交点
//    if (dir1 == dir2) return false;

//    // 计算交点坐标
//    double x1 = lng1 * M_PI / 180.0; double y1 = lat1 * M_PI / 180.0;
//    double x2 = lng2 * M_PI / 180.0; double y2 = lat2 * M_PI / 180.0;
//    double x3 = lng3 * M_PI / 180.0; double y3 = lat3 * M_PI / 180.0;
//    double x4 = lng4 * M_PI / 180.0; double y4 = lat4 * M_PI / 180.0;
//    double a1 = (y2-y1)/(x2-x1); double b1 = y1-a1*x1;
//    double a2 = (y4-y3)/(x4-x3); double b2 = y3-a2*x3;
//    double inter_x = (b2-b1)/(a1-a2);
//    double inter_y = a1*inter_x+b1;

//    // 判断交点是否在两个线段上
//    double len3 = calcDist(lat1, lng1, inter_y/M_PI*180.0, inter_x/M_PI*180.0);
//    double len4 = calcDist(lat2, lng2, inter_y/M_PI*180.0, inter_x/M_PI*180.0);
//    double len5 = calcDist(lat3, lng3, inter_y/M_PI*180.0, inter_x/M_PI*180.0);
//    double len6 = calcDist(lat4, lng4, inter_y/M_PI*180.0, inter_x/M_PI*180.0);
//    if(len3 + len4 > len1 + 0.00001 || len5 + len6 > len2 + 0.00001) return false; // 用小偏差防止浮点数精度误差

//    return true;
//}

//int main() {
//    double lat1, lng1, lat2, lng2, lat3, lng3, lat4, lng4;
//    // 输入六个点和两个线段的经纬度
//    cin >> lat1 >> lng1 >> lat2 >> lng2 >> lat3 >> lng3 >> lat4 >> lng4;

//    // 判断两个线段是否有交点
//    bool intersection = haveIntersection(lat1, lng1, lat2, lng2, lat3, lng3, lat4, lng4);

//    // 根据计算结果输出不同信息
//    if (intersection) {
//        cout << "两个线段有交点" << endl;
//    } else {
//        cout << "两个线段无交点" << endl;
//    }

//    return 0;
//}



//typedef Point Vector;

//// 判断两个浮点数是否相等（这里的误差可根据具体情况进行调整）
//bool dcmp(double x, double y) {
//    const double eps = 1e-8;
//    return fabs(x - y) < eps;
//}

//// 判断 p 是否在线段 l 上
//bool onSegment(const Point& p, const Point& a, const Point& b) {
//    return dcmp((p - a).Cross(b - a), 0) && dcmp((p - a).Dot(p - b), 0);
//}

//// 判断两条线段是否相交
//bool intersect(const Point& a1, const Point& a2, const Point& b1, const Point& b2) {
//    Vector u = a2 - a1;
//    Vector v = b2 - b1;
//    Vector w = a1 - b1;

//    double cross1 = u.Cross(v); // 计算向量叉积
//    double cross2 = u.Cross(w);
//    double cross3 = v.Cross(w);
//    if (dcmp(cross1, 0)) { // 如果两条线段共线，则判断是否有重合部分
//        if (onSegment(a1, b1, b2) || onSegment(a2, b1, b2) ||
//            onSegment(b1, a1, a2) || onSegment(b2, a1, a2))
//            return true;
//        else
//            return false;
//    } else {
//        return dcmp(cross2 * cross3, -1) && dcmp(cross2 + cross3, 0);
//    }
//}



