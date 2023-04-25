#include "WidgetPlus.h"

WidgetPlus::WidgetPlus()
{
    setLayout1();
}

WidgetPlus::~WidgetPlus()
{

}

void WidgetPlus::setLayout1()
{
//    btn1 = new QPushButton();
//    btn1->setText(tr("狄晓庆"));
//    lab = new QLabel(tr("iosioais"));
//    QVBoxLayout *layout1 = new QVBoxLayout(this);
//    layout1->addSpacing(18);
//    layout1->addWidget(btn1);
//    layout1->addWidget(lab);

//    QPushButton *btn2 = new QPushButton();
//    btn2->setText(tr("赵杰"));
//    QLabel *lab1 = new QLabel(tr("ops5456"));
//    lab->setText(tr("赵杰"));
//    lab1->setText(tr("狄晓庆"));
//    layout1->addWidget(btn2);
//    layout1->addWidget(lab1);
//    layout1->addSpacing(8);
    //setLayout(layout1);
    Widget *a = new Widget(this);
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(a);
    QPushButton *btn = new QPushButton(tr("测试"));
    layout->addWidget(btn);
    a->resize(btn->size());

    connect(btn,&QPushButton::clicked,this,[=](){
        qDebug()<<"进入成功"<<endl;
        CustomMessage msgBox(this, MsgBoxType_Error,"警告信息");
        int res = msgBox.exec();
        if(res == QDialog::Accepted)
        {
            qDebug() << "Accepted";
        }
        else if(res == QDialog::Rejected)
        {
            qDebug() << "Rejected";
        }
        else
        {
            qDebug() << "error";
        }
    });

    setLayout(layout);
}
