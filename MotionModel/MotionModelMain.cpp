#include "MotionModelMain.h"


MotionModelMain::MotionModelMain(double x, double y, double vx, double vy)
    : m_x(x), m_y(y), m_vx(vx), m_vy(vy)
{
//    time=new QTimer();
//    time->start(1000);
}

MotionModelMain::~MotionModelMain()
{

}

void MotionModelMain::update(double dt)
{

    m_x += m_vx * dt;
    m_y += m_vy * dt;

}

