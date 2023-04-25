#include "fromone.h"
#include "ui_fromone.h"
#include <QLabel>

FromOne::FromOne(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FromOne)
{
    ui->setupUi(this);
    QPushButtonTest *btn=new QPushButtonTest(this);
    btn->SetNormalPixmap("C:\\Users\\WinkJie\\Pictures\\opsd.png");
    btn->setGeometry(50,50,60,60);
    btn->setText(QString::fromLatin1("z赵杰的按钮"));

    QPushButtonTest *btn1=new QPushButtonTest(this);
    btn1->setText(QString::fromLatin1("z赵杰的按钮5555"));
    btn1->SetNormalPixmap("C:\\Users\\WinkJie\\Pictures\\opsd.png");
    QHBoxLayout *layout = new QHBoxLayout(this);


    layout->addWidget(btn);
    layout->addWidget(btn1);


    QPushButton *btn2 = new QPushButton(this);
    btn2->setText(QString::fromLatin1("我们的按钮"));
    layout->addWidget(btn2);

    ui->pushButton->setText(QString::fromLatin1("我们的按钮在这"));
    ui->pushButton->SetNormalPixmap("C:\\Users\\WinkJie\\Pictures\\opsd.png");
    setLayout(layout);

    //ui->pushButton->setText(QString::fromLatin1("赵杰"));
    //QLabel *a = new QLabel(this);
    //a->setText(QString::fromLatin1("65656"));
}

FromOne::~FromOne()
{
    delete ui;
}
