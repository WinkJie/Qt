#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "structmain.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    StructMain()<<"sjklkjrdfhiuyghj";
    QString str = QString::fromLatin1("我们的世界");
    StructMain()<<str<<endl;

}

MainWindow::~MainWindow()
{
    delete ui;
}
