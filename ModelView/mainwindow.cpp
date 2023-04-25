#include "mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
//#include <QPrintDialog>
//#include <QPrinter>
#include <QPainter>
#include <QColorDialog>
#include <QColor>
#include <QTextList>
#include <QSplitter>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("myexe"));
#if 1
    myshowwidget = new showwidget(this);
    setCentralWidget(myshowwidget);
#endif
#if 0
     myshowwidget = new showwidget(this);
     //setCentralWidget(myshowwidget);
     showwidget *btn = new showwidget(this);
     QGridLayout *layout= new QGridLayout(this);
     layout->addWidget(myshowwidget,0,0);
     layout->addWidget(btn,0,1);
     setLayout(layout);

#endif





    createActions();
    createMenus();
    createToolBars();
//    if(img.load("1.jpg"))
//    {
//        myshowwidget->imageLabel->setPixmap(QPixmap::fromImage(img));
//    }
}
MainWindow::~MainWindow()
{
}
void MainWindow::createActions()
{
}
void MainWindow::createMenus()
{
}
void MainWindow::createToolBars()
{
}
