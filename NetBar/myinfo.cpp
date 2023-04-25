#include "myinfo.h"
#include "ui_myinfo.h"

MyInfo::MyInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyInfo)
{
    ui->setupUi(this);

    QHBoxLayout *hlayout = new QHBoxLayout();
    QVBoxLayout *pushlayout = new QVBoxLayout();
    editcin = new QTextEdit(this);
    QPushButton *push1 = new QPushButton(this);
    push1->setText(QString::fromStdString("默认"));
    QPushButton *push = new QPushButton(this);
    push->setText(QString::fromStdString("转换"));
    pushlayout->addWidget(push1);
    pushlayout->addWidget(push);
    editcoutl = new QTextEdit(this);
    hlayout->addWidget(editcin);
//    hlayout->addWidget(pushlayout);
    hlayout->addLayout(pushlayout);
    hlayout->addWidget(editcoutl);
    setLayout(hlayout);


    editcin->setText(QString::fromStdString("test ssom"));
    editcoutl->setText(QString::fromStdString("4"));

    connect(push,SIGNAL(clicked()),this,SLOT(clickedBtn()));
    connect(push1,SIGNAL(clicked()),this,SLOT(clickedpush1()));
}

MyInfo::~MyInfo()
{
    delete ui;
}

void MyInfo::swap(std::string str)
{
    std::string str1;
    for(auto i=str.size()-1;i>=0;i--)
        str1 += str[i];
    str = "";
    for(auto ch:str1)
        str += ch;

    QVector<QVector<int>> dp(str.size(),QVector<int>(str.size(),0));
    //str = str1;
    //QString::toint
}

void MyInfo::clickedBtn()
{
    std::string tmps = editcin->toPlainText().toStdString();
    int count = 0;
    std::string tmp="";
//    swap(tmps);
    std::string xc;
    for(int i = int(tmps.size()-1);i>=0;i--)
    {
        if(tmp[i] == ' ')
            break;
        count++;
        xc+=tmps[i];
    }
    //for(auto ch:xc)
    //{
    //    if(ch == ' ')
    //        break;
    //    count++;
    //
    //    tmp=ch;
    //}
    //editcoutl->setText(QString::fromStdString(tmp.c_str() + count));
    editcoutl->setText(QString::fromStdString("inins"));






}

void MyInfo::clickedpush1()
{
    editcin->setText(QString::fromStdString("test ssom"));
    editcoutl->setText(QString::fromStdString("4"));
}




