#ifndef MYINFO_H
#define MYINFO_H

#include "header_h.h"

namespace Ui {
class MyInfo;
}

//class PushButton:public

class MyInfo : public QWidget
{
    Q_OBJECT

public:
    explicit MyInfo(QWidget *parent = nullptr);
    ~MyInfo();

    void swap(std::string str);

public:
    QPushButton *pause;
    QTextEdit *editcin;
    QTextEdit *editcoutl;

public slots:
    void clickedBtn();
    void clickedpush1();

private:
    Ui::MyInfo *ui;
};

#endif // MYINFO_H
