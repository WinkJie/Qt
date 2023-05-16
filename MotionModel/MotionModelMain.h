#ifndef MOTIONMODELMAIN_H
#define MOTIONMODELMAIN_H
#include <QTimer>
#include <QObject>
#include "AbstrctMotionModel.h"

class MotionModelMain:public AbstrctMotionModel
{
    Q_OBJECT
public:
    MotionModelMain(double x, double y, double vx, double vy);
    ~MotionModelMain();
    void update(double dt);

    double getX() const { return m_x; }
    double getY() const { return m_y; }
    double getVX() const { return m_vx; }
    double getVY() const { return m_vy; }

private:
    double m_x, m_y;   // 物体当前位置
    double m_vx, m_vy; // 物体当前速度
    //    QTimer *time;
};

#endif // MOTIONMODELMAIN_H
