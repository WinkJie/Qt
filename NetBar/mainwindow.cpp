#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <stack>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //重置窗口
    this->resize(600,400);

    //创建菜单栏--最多只有一个
    QMenuBar * bar = menuBar();
    setMenuBar(bar);
    //创建菜单
    QMenu * file=  bar->addMenu(QString::fromStdString("文件"));
    QMenu * edit=  bar->addMenu(QString::fromStdString("编辑"));


    //创建菜单项
    QAction * newaction= file->addAction(QString::fromStdString("新建"));
    //添加分隔符
    file->addSeparator();
    QAction * editaction =  file->addAction(QString::fromStdString("打开"));

    //工具栏--可以多个
    QToolBar * tbar = new  QToolBar(this);
    addToolBar(tbar);
    // tbar ->setAllowedAreas(Qt::LeftToolBarArea|Qt::RightToolBarArea);

    //设置浮动
    tbar->setFloatable(false);

    //设置移动（总开关）
    tbar->setMovable(false);

    //工具栏添加内容
    tbar->addAction(newaction);
    //添加分割线
    tbar->addSeparator();
    tbar->addAction(editaction);

    //工具栏中添加控件
    QPushButton * btn= new QPushButton(tbar);
    btn->setText(QString::fromStdString("工具栏上的控件" ));
    tbar->addWidget(btn);

    //状态栏也是最多只能有一个
    QStatusBar * sta =  statusBar();
    setStatusBar(sta);

    //放标签控件
    QLabel * lb =new QLabel("leftremake",this);
    sta->addWidget(lb);

    //放右侧标签控件
    QLabel * lb2 =new QLabel("rightremake",this);
    sta->addPermanentWidget(lb2);

    //铆接部件（浮动窗口）可以包含多个
    QDockWidget * dw = new QDockWidget(QString::fromStdString("浮动" ),this);
    addDockWidget(Qt::BottomDockWidgetArea,dw);
    //设置停靠区域，只允许上下
    dw->setAllowedAreas(Qt::TopDockWidgetArea|Qt::BottomDockWidgetArea);


    //设置中心部件  只能有一个

    //QTextEdit * qedit= new QTextEdit(this);
    MyInfo *qedit = new MyInfo(this);
    setCentralWidget(qedit);



}

MainWindow::~MainWindow()
{
    delete ui;
}
