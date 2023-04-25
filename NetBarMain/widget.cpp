#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    fromOne = new FromOne;
    fromTwo = new FormTwo;
    ui->stackedWidget->addWidget(fromOne);
    ui->stackedWidget->addWidget(fromTwo);



}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Widget::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
