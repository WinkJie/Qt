#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <cmath>

struct Point {
    double lat;
    double lon;
    Point(double x = 0, double y = 0) : lon(x), lat(y) {}
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


    bool line_intersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);

    bool line_intersect1(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
    //共线
    bool line_intersect2(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);



    void Do();

    double cross(const Point& p0, const Point& p1, const Point& p2);
    bool isIntersect(const Point& A, const Point& B, const Point& C, const Point& D);
    Point getIntersection(const Point& A, const Point& B, const Point& C, const Point& D);
    void Do1();
    //    bool intersect(const Point& a1, const Point& a2, const Point& b1, const Point& b2);
    //    bool dcmp(double x, double y);
    //    bool onSegment(const Point& p, const Point& a, const Point& b);



    double distance(Point p1, Point p2);

    double point_to_line_distance(Point p, Point a, Point b);


    bool will_collide(Point boat_center, double boat_width, double boat_length, Point coast_point1, Point coast_point2);

    bool will_collide1(Point boat_center, double boat_width, double boat_length, Point coast_point1, Point coast_point2);

    void calculate_boat_points(Point center, double width, double length, Point* points);


    void dataTest();

    double m_Ship_head[2];
    double m_Ship_tail[2];
    double m_Ship_right_front[2];
    double m_Ship_right_middle[2];
    double m_Ship_right_tail[2];
    double m_Ship_left_front[2];
    double m_Ship_left_middle[2];
    double m_Ship_left_tail[2];


};
#endif // WIDGET_H




/*

    计算机考研408初试考试要求以及考试科目主要有：
计算机学科专业基础综合（408）试卷满分150分；考试时间180分钟；
试卷内容结构：
数据结构45分，计算机组成原理45分，操作系统35分，计算机网络25分；

    试卷题型结构：单项选择题，80分（40小题，每小题2分）；综合题，70分；

    计算机专业考研复习资料：
数据结构：《数据结构C语言版》《数据结构精讲和习题讲解》严蔚敏；
计算机组成原理：《计算机组成原理（第2版）》《计算机组成原理-学习指导与习题解答》
操作系统：《计算机操作系统（第四版）》
《计算机操作系统（第四版）学习指导与题解》 汤小丹
计算机网络《计算机网络（第7版）》《计算机网络释疑与习题解答》谢希仁

    数据结构部分包括：线性表，栈、队列和数组，树与二叉树，图，查找，排序。这一部分复习的重点在于理解数据结构的三要素：逻辑结构，存储结构及在其上定义的各种基本操作;
难点在于对各个内容的算法实现和灵活运用。把握重点和难点的最主要的一条就是多动手，勤于思考。因此，同学们在复习中要注意掌握数据结构的三要素，认真领会大纲中对考查要点的阐述，
联系书上的典型例题深入理解各知识点之间的联系与区别，多动手练习写各种基本操作的算法，勤于动脑认真总结，定能对到达这一科目的复习要求，做到得心应手灵活运用。

    计算机组成原理部分包括：计算机系统概述，数据的表示和运算，存储器层次结构，指令系统，中央处理器(CPU)，总线，输入输出(I/O)系统。这一部分的复习重点在于单处理机计算机系统中
各个部件的组成结构和基本工作原理。复习时要根据考纲要求准确理解基本概念原理，把握要点，把概念与原理联系起来形成一个完整的系统，在头脑中形成清晰的认识，并随着复习的进行不断加
深认知。建议同学们在复习每一章节时，结合复习的内容自己动手在笔记本上尝试列出这一部分的知识结构框图，明晰知识点之间的内在关系。

    操作系统部分包括：操作系统概述，进程管理，内存管理，文件管理，输入/输出(I/O)管理。这一部分的复习重点在于基本概念和基本原理的掌握，包括一些常用的算法。难点在于运用操作系统
的基本原理来分析和解决具体问题。大家复习时可将教材中的内容与大纲中的相关内容结合起来配合理解，将理论上的东西理解透彻，融会贯通;然后通过做题切实提高自己分析、解决实际问题的能力。

    计算机网络部分包括：计算机网络体系结构，物理层，数据链路层，网络层，传输层，应用层。这一部分的复习重点在于计算机网络的分层的概念。同学们复习这一部分需特别注意按层进行知识点的复
习总结。重点把握每一层的协议有哪些、引入这些协议的原因、涉及到哪些重要算法、算法的内容、每一层和上下层之间的关系、每一层用到的硬件设备及作用等，用系统的方法将具体的知识点串连在一起。

一、计算机科学与技术学科的初试科目调整后为4门，即政治理论、外国语、数学一和计算机学科专业基础综合，卷面满分值分别为100分、100分、150分和150分。
二、计算机学科专业基础综合的考试内容包括：数据结构、计算机组成原理、操作系统和计算机网络，重点考查考生掌握相关基础知识、基本理论和分析问题解决问题的能力。考试内容及试卷结构在考试大纲中确定。
三、计算机学科专业基础综合科目实行联合命题，命题工作由全国学位与研究生教育学会工科委员会在教育部考试中心指导下组织实施，阅卷工作由省级招生考试机构统一组织，有关考务工作要求另行通知。
四、对于授理学学位的招生单位，第三单元考试科目可选数学一，也可自命题；第四单元考试科目必须采用联考的计算机学科专业基础综合。
五、相关招生单位均应根据初试科目内容、要求的变化和《教育部关于加强硕士研究生招生复试工作的指导意见》（教学〔2006〕4号）的要求，及时对该学科复试内容、办法和其他相关工作作
出相应调整。 六、有关招生单位可充分利用接收推免生的方式招收跨学科专业的生源，对此招生部门应主动做好与培养、推荐部门的衔接工作。

*/
