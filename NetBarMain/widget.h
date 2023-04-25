#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "fromone.h"
#include "formtwo.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();



     FromOne *fromOne;


     FormTwo *fromTwo;




private slots:
     void on_pushButton_clicked();

     void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
