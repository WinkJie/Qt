#include "splitest.h"


#if 0
SpliTest::SpliTest(QWidget *parent):
    QSplitter(parent)
{
    // this->setParent(parent);
    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    //QWidget *widget = new QWidget();
    QSplitter *splitter = new QSplitter(this);
#if 1
    QDirModel *model = new QDirModel;
    //从缺省目录创建数据
    QTreeView *tree = new QTreeView(splitter);
    tree->setModel(model);
    QString str=QString("E")+QString("://")+QString::fromLocal8Bit("英雄时刻//55");
    QString str1 = QString("E://英雄时刻//55");
    tree->setRootIndex(model->index(str));

    QListView *list = new QListView(splitter);
    list->setModel(model);
    list->setRootIndex(model->index(QDir::rootPath()));

    QTreeView *tree1=new QTreeView(splitter);
    tree1->setModel(model);
    tree1->setRootIndex(model->index(QDir::rootPath()));
#endif
#if 0
    NoUiInterface *Ui = new NoUiInterface(splitter);
    Ui->typeInt=NoUiInterface::NORMAL;
    qDebug()<<Ui->typeInt<<endl;


    NoUiInterface *Ui1 = new NoUiInterface(splitter);
    Ui1->typeInt=NoUiInterface::HOVER;
    qDebug()<<Ui1->typeInt<<endl;

    //    Ui->SetUpUi();
    //    Ui1->SetUpUi();
    //    Ui->show();
    //    Ui1->show();
#endif


    //list->setRootIndex(model->index(QDir::currentPath()));
    //配置一个view去显示model中的数据，只需要简单地调用setModel(),并把目录model作为参数传递
    //setRootIndex()告诉views显示哪个目录的信息，这需要提供一个model index,然后用这个
    //model index去model中去获取数据
    //index()这个函数是QDirModel特有的，通过把一个目录做为参数，得到了需要的model index
    //其他的代码只是窗口show出来,进入程序的事件循环就好了
    splitter->setWindowTitle("Two views onto the same directory model");
    splitter->show();
    //widget->show();
    ///setCentralWidget(splitter);

}

#endif

SpliTest::SpliTest()
{
    // this->setParent(parent);
    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    //QWidget *widget = new QWidget();
    QSplitter *splitter = new QSplitter(this);
#if 1
    QDirModel *model = new QDirModel;
    //从缺省目录创建数据
    QTreeView *tree = new QTreeView(splitter);
    tree->setModel(model);
    QString str=QString("E")+QString("://")+QString::fromLocal8Bit("英雄时刻//55");
    QString str1 = QString("E://英雄时刻//55");
    tree->setRootIndex(model->index(str));

    QListView *list = new QListView(splitter);
    list->setModel(model);
    list->setRootIndex(model->index(QDir::rootPath()));

    QTreeView *tree1=new QTreeView(splitter);
    tree1->setModel(model);
    tree1->setRootIndex(model->index(QDir::rootPath()));
#endif
#if 0
    NoUiInterface *Ui = new NoUiInterface(splitter);
    Ui->typeInt=NoUiInterface::NORMAL;
    qDebug()<<Ui->typeInt<<endl;


    NoUiInterface *Ui1 = new NoUiInterface(splitter);
    Ui1->typeInt=NoUiInterface::HOVER;
    qDebug()<<Ui1->typeInt<<endl;

    //    Ui->SetUpUi();
    //    Ui1->SetUpUi();
    //    Ui->show();
    //    Ui1->show();
#endif


    //list->setRootIndex(model->index(QDir::currentPath()));
    //配置一个view去显示model中的数据，只需要简单地调用setModel(),并把目录model作为参数传递
    //setRootIndex()告诉views显示哪个目录的信息，这需要提供一个model index,然后用这个
    //model index去model中去获取数据
    //index()这个函数是QDirModel特有的，通过把一个目录做为参数，得到了需要的model index
    //其他的代码只是窗口show出来,进入程序的事件循环就好了
    splitter->setWindowTitle("Two views onto the same directory model");
    splitter->show();
    //widget->show();
    ///setCentralWidget(splitter);


}

void SpliTest::ops()
{
    qDebug()<<"test sueecss!"<<endl;
}
