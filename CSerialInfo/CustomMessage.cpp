#include "CustomMessage.h"

CustomMessage::CustomMessage(QWidget *parent, MsgBoxType type, QString text) : QDialog(parent)
{
    initState();

    if(type == MsgBoxType_Info)
    {
        initInfo(text);
    }
    else if(type == MsgBoxType_Warn)
    {
        initWarn(text);
    }
    else
    {
        initError(text);
    }

}

void CustomMessage::initState()
{
    this->resize(240,160);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

    this->setStyleSheet("background-color:rgb(46,47,48)");

    labPic = new QLabel(this);
    labNote = new QLabel(this);
    btnSure = new QPushButton("确认",this);
    btnCancle = new QPushButton("取消",this);

    connect(btnSure,&QPushButton::clicked,this,&CustomMessage::dealbtnSureClicked);
    connect(btnCancle,&QPushButton::clicked,this,&CustomMessage::dealbtnCancelClicked);
}

void CustomMessage::initWarn(const QString &text)
{
    int width = this->width();

    labPic->setStyleSheet("image:url(:/new/prefix1/7.jpg)");
    labPic->setGeometry(width*0.5-20,10,40,40);

    labNote->setStyleSheet("color:white");
    labNote->setAlignment(Qt::AlignCenter);
    labNote->setGeometry(0,70,width,20);
    labNote->setText(text);

    btnSure->setGeometry(width*0.2-15,110,80,30);
    btnSure->setStyleSheet("QPushButton{color:white; border-radius: 5px; background-color:rgb(43,34,45)}"
                           "QPushButton:hover{background-color:blue}"
                           "QPushButton:pressed{background-color:blue}");

    btnCancle->setGeometry(width*0.6,110,80,30);
    btnCancle->setStyleSheet("QPushButton{color:white; border-radius: 5px; background-color:rgb(43,34,45)}"
                             "QPushButton:hover{background-color:blue}"
                             "QPushButton:pressed{background-color:blue}");

}

void CustomMessage::initError(const QString &text)
{
    int width = this->width();

    labPic->setStyleSheet("image:url(:/new/prefix1/8.jpg)");
    labPic->setGeometry(width*0.5-20,10,40,40);

    labNote->setStyleSheet("color:white");
    labNote->setAlignment(Qt::AlignCenter);
    labNote->setGeometry(0,70,width,20);
    labNote->setText(text);

    btnSure->setGeometry(width*0.5-40,110,80,30);
    btnSure->setStyleSheet("QPushButton{color:white; border-radius: 5px; background-color:rgb(43,34,45)}"
                           "QPushButton:hover{background-color:blue}"
                           "QPushButton:pressed{background-color:blue}");

    btnCancle->hide();
}

void CustomMessage::initInfo(const QString &text)
{
    int width = this->width();

    labPic->setStyleSheet("image:url(:/new/prefix1/51.png)");
    labPic->setGeometry(width*0.5-20,10,40,40);

    labNote->setStyleSheet("color:white");
    labNote->setAlignment(Qt::AlignCenter);
    labNote->setGeometry(0,70,width,20);
    labNote->setText(text);

    btnSure->setGeometry(width*0.5-40,110,80,30);
    btnSure->setStyleSheet("QPushButton{color:white; border-radius: 5px; background-color:rgb(43,34,45)}"
                           "QPushButton:hover{background-color:blue}"
                           "QPushButton:pressed{background-color:blue}");

    btnCancle->hide();
}

void CustomMessage::dealbtnSureClicked()
{
    this->accept();
}

void CustomMessage::dealbtnCancelClicked()
{
    this->reject();
}
