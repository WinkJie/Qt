#include "Widget.h"
#include <QStandardItemModel>
#include <QFile>
#include <QVBoxLayout>
#include <QElapsedTimer>
#include <QDebug>
#include <QScrollBar>
#include <QHeaderView>
#include "StandardItemModel.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(800,500);
    QFont textFont;
    textFont.setPointSize(12);
    textFont.setFamily("Microsoft YaHei");



    m_pTestView = new QTableView(this);
    //------------------------thread
    StandardItemModel *model = new StandardItemModel();
    model->moveToThread(&m_thread);
    qDebug()<<"xinhao"<<endl;
    connect(this,SIGNAL(startRunnings()),model,SLOT(CreateDatas()));
    //connect(this,&Widget::startRunning,model,&StandardItemModel::CreateData);
    connect(&m_thread,&QThread::finished,model,&QObject::deleteLater);
    qDebug()<<"xinhao jieshu "<<endl;
    m_thread.start();
    //-----------------------

    m_pTestView->setFont(textFont);

    Start();
    m_pTestView->setModel(model);

    QVBoxLayout *mainLayout=new QVBoxLayout(this);
    mainLayout->addWidget(m_pTestView);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
    this->setLayout(mainLayout);

    //    QFile file("C:/Users/dujia/Desktop/ReceiverTableData.txt");
    //    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    //        return;

    //    int i=0;
    //    while (!file.atEnd()) {
    //        QString strLine=file.readLine();
    //        QStringList strList=strLine.split("&");
    //        model->setItem(i,0,new QStandardItem(strList[0]));
    //        model->setItem(i,1,new QStandardItem(strList[1]));
    //        model->setItem(i,2,new QStandardItem(strList[2]));
    //        model->setItem(i,3,new QStandardItem(strList[3]));
    //        model->setItem(i,4,new QStandardItem(strList[4]));
    //        model->setItem(i,5,new QStandardItem(strList[5]));
    //        model->setItem(i,6,new QStandardItem(strList[6]));
    //        model->setItem(i,7,new QStandardItem(strList[7]));
    //        model->setItem(i,8,new QStandardItem(strList[8]));
    //        model->setItem(i,9,new QStandardItem(strList[9]));
    //        model->setItem(i,10,new QStandardItem(strList[10]));
    //        i=i+1;
    //    }
}

Widget::~Widget()
{
    m_thread.quit();
    m_thread.wait();
}

void Widget::Start()
{
    QString path = "D:/QT/WorkSpace/CSerialInfo/ReceiverTableData.txt";
    emit startRunning(path);
    emit startRunnings();
    qDebug()<<"发送信号了"<<endl;
}
