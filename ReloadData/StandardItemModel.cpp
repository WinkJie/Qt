#include "StandardItemModel.h"
#include <QFile>
#include <QElapsedTimer>
#include <qdebug.h>

StandardItemModel::StandardItemModel(QObject *parent) : QStandardItemModel(parent)
{
    this->setColumnCount(15);
    for(int i=0;i<15;i++)
    {
        this->setHeaderData(i, Qt::Horizontal, QString::fromLocal8Bit(DefQSReceiverInfoTableSize[i][0]));
    }
}

StandardItemModel::~StandardItemModel()
{

}
//这里用于动态加载数据
void StandardItemModel::CreateData(QString &i_path)
{
    QFile file(i_path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"打开文件数据失败！"<<endl;
        return;
    }

    int i=0;
    while (!file.atEnd()) {
        QString strLine=file.readLine();
        QStringList strList=strLine.split("&");
        this->setItem(i,0,new QStandardItem(strList[0]));
        this->setItem(i,1,new QStandardItem(strList[1]));
        this->setItem(i,2,new QStandardItem(strList[2]));
        this->setItem(i,3,new QStandardItem(strList[3]));
        this->setItem(i,4,new QStandardItem(strList[4]));
        this->setItem(i,5,new QStandardItem(strList[5]));
        this->setItem(i,6,new QStandardItem(strList[6]));
        this->setItem(i,7,new QStandardItem(strList[7]));
        this->setItem(i,8,new QStandardItem(strList[8]));
        this->setItem(i,9,new QStandardItem(strList[9]));
        this->setItem(i,10,new QStandardItem(strList[10]));
        i=i+1;
    }
    qDebug()<<"i::"<<i;

    qDebug()<<"this:::"<<this->rowCount();
}

void StandardItemModel::CreateDatas()
{
    QString path = "D:/QT/WorkSpace/ReloadData/ReceiverTableData.txt";//D:\QT\WorkSpace\ReloadData
    CreateData(path);
}


