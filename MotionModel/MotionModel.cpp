#include "MotionModel.h"
#include <qdebug.h>

MotionModel::MotionModel(QWidget *parent)
    : QWidget(parent)
{
    MotionModelMain model(0.0, 0.0, 10.0, 5.0);

    // 模拟运动过程，每个时间步长为1秒
    for (int i = 0; i < 10; ++i)
    {
        qDebug() << "Time: " << i << ", Position: ("
                 << model.getX() << ", " << model.getY() << ")\n";
        model.update(1.0);
    }

}

MotionModel::~MotionModel()
{

}
