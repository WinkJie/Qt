#ifndef MOTIONMODEL_H
#define MOTIONMODEL_H

#include <QWidget>
#include "MotionModelMain.h"

class MotionModel : public QWidget
{
    Q_OBJECT

public:
    MotionModel(QWidget *parent = 0);
    ~MotionModel();
};

#endif // MOTIONMODEL_H
