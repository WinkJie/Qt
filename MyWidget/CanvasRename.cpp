#include "CanvasRename.h"
#include "ui_CanvasRename.h"

CanvasRename::CanvasRename(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CanvasRename)
{
    ui->setupUi(this);
    InitSum();
}

CanvasRename::~CanvasRename()
{
    delete ui;
}

void CanvasRename::InitSum()
{
    InitListView();
}

void CanvasRename::InitListView()
{
    // 创建数据模型并设置给 QListView
    QStringListModel* model = new QStringListModel();
    QStringList dataList;

    // 添加多行多列的数据
    for (int row = 0; row < 5; row++)
    {
        QString rowData;
        for (int column = 0; column < 3; column++)
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
