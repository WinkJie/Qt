#include "showwidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <iostream>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
showwidget::showwidget(QWidget *parent) :
    QWidget(parent)
{
    //    imageLabel =new QLabel;   //用Qlabel展示图片
    //    imageLabel->setScaledContents(true);
    //    text =new QTextEdit;      //QTextEdit展示文本




    QVBoxLayout *mainLayout =new QVBoxLayout(this);

    QHBoxLayout *Layout1 =new QHBoxLayout(this);
    QHBoxLayout *Layout2 =new QHBoxLayout(this);
    QHBoxLayout *Layout3 =new QHBoxLayout(this);
    QHBoxLayout *Layout5 =new QHBoxLayout(this);
    QVBoxLayout *Layout4 =new QVBoxLayout(this);

    button1 = new QPushButton(this);
    button1->setText("get Kmeans.xml");
    Layout1->addWidget(button1);
    connect(button1,SIGNAL(clicked()),this,SLOT(getxml()));

    QLabel *label1 = new QLabel(this);
    label1->setText("input img1");
    QLineEdit *lineEdit1 = new QLineEdit(this);
    QPushButton *button2 = new QPushButton(this);
    button2->setText("to get target picture's name");
    Layout2->addWidget(label1);
    Layout2->addWidget(lineEdit1);
    Layout2->addWidget(button2);


    QLabel *label2 = new QLabel(this);
    label2->setText("input img2");
    QLineEdit *lineEdit2 = new QLineEdit(this);
    QPushButton *button3 = new QPushButton(this);
    button3->setText("look compared picture");
    Layout3->addWidget(label2);
    Layout3->addWidget(lineEdit2);
    Layout3->addWidget(button3);

    //    mainLayout->addWidget(imageLabel);
    //    mainLayout->addWidget(text);

    QLineEdit *lab = new QLineEdit(this);
    lab->setText(QString("赵杰"));
    QLineEdit *lab1 = new QLineEdit(this);
    lab1->setText(QString("在哪呢"));
    QSize size = QSize(50,120);
    lab1->setSizeIncrement(size);
    Layout4->addWidget(lab,1);
    Layout4->addWidget(lab1,3);

    QWidget *wid = new QWidget(this);
    //wid->setMinimumSize(QSize(50,200));
    Layout5->addWidget(wid,1);
    Layout5->addLayout(Layout4,1);

    mainLayout->addLayout(Layout1,1);
    mainLayout->addLayout(Layout2,6);
    mainLayout->addLayout(Layout3,6);
    mainLayout->addLayout(Layout5,6);
    //connect(button1,SIGNAL(clicked()),this,SLOT(getxml()));
    //在这里加不行，识别不到槽函数
}

void showwidget::getxml()
{
    qDebug() << "getxml";
}
