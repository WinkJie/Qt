#include "maillist.h"

MailList::MailList(QWidget *parent)
    : QWidget(parent)
{
    setLayout();
    CreateList();
}

MailList::~MailList()
{

}

void MailList::setLayout()
{
    QSize size(300,700);
    this->resize(size);
    this->setStyleSheet("QFrame{background-image:url(:/image/6565.webp)}");
    //tableWidget->setStyleSheet("border-image: url(C:\\Users\\WinkJie\\Pictures\\Camera Roll\\background.jpg)");
    //this->setStyleSheet("border-image: url(C:\\Users\\WinkJie\\Pictures\\Camera Roll\\background.jpg)");
    tableWidget = new QTableWidget();
    btn1 = new QPushButton("添加");
    btn2 = new QPushButton("删除");
    btn3 = new QPushButton("查看信息");
    btn4 = new QPushButton("返回主页");
    layHBox = new QHBoxLayout();
    layVBox = new QVBoxLayout();
    naviLayout = new QHBoxLayout();
    layGriBox = new QGridLayout(this);
    label = new QLabel("搜索");
    label->setStyleSheet("QLabel{"
                         "border-image:url(:/image/background.jpg) 4 4 4 4 stretch stretch;"
                         "}");
    editSearch = new QLineEdit("");
    Searchbtn = new QPushButton("搜索");
    CancelSearchbtn = new QPushButton("取消搜索");
    naviLayout->addWidget(label,1);
    naviLayout->addWidget(editSearch,3);
    naviLayout->addWidget(Searchbtn,1);
    naviLayout->addWidget(CancelSearchbtn,1);
    layHBox->addWidget(btn1);
    layHBox->addWidget(btn2);
    layHBox->addWidget(btn3);
    layHBox->addWidget(btn4);
    layGriBox->addLayout(naviLayout,0,0);
    layGriBox->addWidget(tableWidget);
    layGriBox->addLayout(layHBox,2,0);


    connect(editSearch,&QLineEdit::textChanged,this,&MailList::TextChanged);


}

void MailList::CreateList()
{
    tableWidget->setColumnCount(3);
    tableWidget->setRowCount(30);
    tableWidget->setWindowTitle("QTableWidget");
    QStringList list;
    list<<tr("联系人")<<QString("查看")<<tr("编辑");
    tableWidget->setHorizontalHeaderLabels(list);
    tableWidget->verticalHeader()->setHidden(true);
    // tableWidget->item(0,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //    tableWidget->verticalHeader()->setVisible(true);
    tableWidget->setShowGrid(false);
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget->setStyleSheet("selection-background-color:pink");
    tableWidget->horizontalHeader()->setStyleSheet(
                "QHeaderView::section{background-color:rgb(225,225,225);"
                "color: black;};");

    //tableWidget->setStyleSheet("border-image: url(C:\\Users\\WinkJie\\Pictures\\Camera Roll\\background.jpg)");

    InsertDataList();

}

void MailList::InsertDataList()
{
    readDataFromText();
    for(int i=0;i<30;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(j==0)
            {
                tableWidget->setItem(i,j,new QTableWidgetItem("wisos"));
                tableWidget->item(i,j)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            }
            else if(j==1)
            {


                QPushButton *button = new QPushButton("查看");
                QHBoxLayout *vLayout = new QHBoxLayout();
                QWidget *Widget_btn = new QWidget;
                button->setStyleSheet("QPushButton{color:white;background-color:rgb(51,204,255);font-family:黑体;border-radius: 18px;}"
                                      "QPushButton:pressed{background-color:rgb(51,129,172)}");
                vLayout->addWidget(button);
                Widget_btn->setLayout(vLayout);
                Widget_btn->setStyleSheet("QWidget{ border: 0px }");

                tableWidget->setCellWidget(i,j,Widget_btn);


                connect(button,SIGNAL(clicked()),this,SLOT(GetPosXY()));
            }
            else
            {
                QString str = "退出" ;//+ QString::number(rowIndex+1);
                QString str2 = "编辑" ;//+ QString::number(rowIndex+1);
                QPushButton *btn_edit = new QPushButton();
                QPushButton *btn_exit = new QPushButton();
                btn_edit->setText(str2);
                btn_exit->setText(str);
                btn_edit->setFixedSize(60,20);
                btn_exit->setFixedSize(60,20);
                btn_edit->setStyleSheet("QPushButton{color:white;background-color:rgb(51,204,255);font-family:黑体;border-radius: 35px;}"
                                        "QPushButton:pressed{background-color:rgb(51,129,172)}");
                btn_exit->setStyleSheet("QPushButton{color:white;background-color:rgb(51,204,255);font-family:黑体;border-radius: 15px;}"
                                        "QPushButton:pressed{background-color:rgb(51,129,172)}");


                QHBoxLayout *vLayout = new QHBoxLayout();
                QWidget *Widget_btn = new QWidget;
                vLayout->addWidget(btn_edit);
                //vLayout->addSpacing(10);
                //vLayout->addWidget(btn_exit);
                Widget_btn->setLayout(vLayout);
                Widget_btn->setStyleSheet("QWidget{ border: 0px }");
                tableWidget->setCellWidget(i,j,Widget_btn);
                tableWidget->verticalHeader()->setHidden(true);

            }
        }
    }
}

void MailList::readDataFromText()
{
    QDir* dir = new QDir;
    QString dirs = dir->currentPath() + "/Log";
    qDebug()<<dir->currentPath()<<endl;
    if(!dir->exists(dirs))
        if(!dir->mkdir(dirs))
            QMessageBox::warning(this,tr("创建文件夹"),tr("创建失败！"));
    QString log = dirs+"/log.txt";
    qDebug()<<log<<endl;
    QFile file(log);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream txtInput(&file);
        QString lineStr;
        while(!txtInput.atEnd())
        {
            lineStr = txtInput.readLine();
        }
        file.close();
    }
}

void MailList::GetPosXY()
{
    QPushButton *btn = (QPushButton*)sender();
    QWidget *w_parent = (QWidget*)btn->parent();
    int x = w_parent->mapToParent(QPoint(0,0)).x();
    int y = w_parent->mapToParent(QPoint(0,0)).y();
    QModelIndex index = tableWidget->indexAt(QPoint(x,y));
    qDebug()<<index.row()<<","<<index.column()<<endl;
}

void MailList::TextChanged(const QString &s)
{
    qDebug()<<s<<endl;
    if(s.contains("56"))
        layGriBox->destroyed(this);
    else
        setLayout();
}
