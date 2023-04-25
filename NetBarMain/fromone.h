#ifndef FROMONE_H
#define FROMONE_H

#include <QWidget>
#include <QHBoxLayout>
#include "qpushbuttontest.h"

namespace Ui {
class FromOne;
}

class FromOne : public QWidget
{
    Q_OBJECT

public:
    explicit FromOne(QWidget *parent = nullptr);
    ~FromOne();




private:
    Ui::FromOne *ui;
};

#endif // FROMONE_H
