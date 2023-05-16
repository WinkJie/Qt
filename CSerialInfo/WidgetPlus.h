#ifndef WIDGETPLUS_H
#define WIDGETPLUS_H
#include "Widget.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include "CCustomMessageBox.h"
#include "CustomMessage.h"

#include "PainterTest.h"

class WidgetPlus : public QWidget
{
public:   
    WidgetPlus();
    ~WidgetPlus();
    void setLayout1();

private:
    QPushButton *btn1;
    QLabel *lab;

};

#endif // WIDGETPLUS_H
