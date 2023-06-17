#include "CanVas.h"
#include "ui_CanVas.h"

CanVas::CanVas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CanVas)
{
    ui->setupUi(this);
    InitSum();
}

CanVas::~CanVas()
{
    delete ui;
}

void CanVas::InitSum()
{
    InitListView();
    InitTreeView();
    InitTableView();
}

void CanVas::InitListView()
{
    // 创建数据模型并设置给 QListView
    QStringListModel* model = new QStringListModel();
    QStringList dataList;

    // 添加多行多列的数据
    for (int row = 0; row < 5; row++)
    {
        QString rowData;
        for (int column = 0; column < 9; column++)
        {
            rowData += QString("Item %1-%2").arg(row).arg(column);
            if (column != 2)
                rowData += "\t";  // 制表符分隔列
        }
        dataList << rowData;
    }

    model->setStringList(dataList);
    ui->listView->setModel(model);

}

void CanVas::InitTreeView()
{
    // 创建数据模型并设置给 QTreeView
    QStandardItemModel* model = new QStandardItemModel();

    // 添加根节点
    QStandardItem* rootItem = model->invisibleRootItem();

    // 添加多个子项
    for (int i = 0; i < 5; ++i) {
        QString itemName = QString("Item %1").arg(i);
        QStandardItem* item = new QStandardItem(itemName);

        // 添加子项
        for (int j = 0; j < 3; ++j) {
            QString childItemName = QString("Child Item %1-%2").arg(i).arg(j);
            QStandardItem* childItem = new QStandardItem(childItemName);
            item->appendRow(childItem);
        }

        rootItem->appendRow(item);
    }
    ui->treeView->setModel(model);
}

void CanVas::InitTableView()
{
    // 创建数据模型并设置给 QTreeView
    QStandardItemModel* model = new QStandardItemModel();

    // 添加根节点
    QStandardItem* rootItem = model->invisibleRootItem();

    // 添加多个子项
    for (int i = 0; i < 5; ++i) {
        QString itemName = QString("Item %1").arg(i);
        QStandardItem* item = new QStandardItem(itemName);

        // 添加子项
        for (int j = 0; j < 3; ++j) {
            QString childItemName = QString("Child Item %1-%2").arg(i).arg(j);
            QStandardItem* childItem = new QStandardItem(childItemName);
            item->appendRow(childItem);
        }

        rootItem->appendRow(item);
    }
    ui->tableView->setModel(model);
}
