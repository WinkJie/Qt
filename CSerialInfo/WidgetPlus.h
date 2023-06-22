#ifndef WIDGETPLUS_H
#define WIDGETPLUS_H
#include "Widget.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include "CCustomMessageBox.h"
#include "CustomMessage.h"

#include "PainterTest.h"


#include "CSerialInfo.h"
#include "drawDemo.h"
#include <QApplication>
#include "form.h"
#include "Widget.h"
#include "PainterTest.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //qApp->setStyleSheet("QToolTip{border: 0px solid black;background:red;border-radius: 15px 5px 25px;}");
    WidgetPlus w;


//    w.setProperty("enabled",false);
//    qDebug()<<w.isEnabled()<<endl;
//    w.setEnabled(false);
//    LoginWidget w;
//    QToolTipsNew w;
    w.show();

    return a.exec();
}


//https://zhenfanjixie.com/vodplay/385226-2-44.html
//https://zhenfanjixie.com/vodplay/386010-2-48.html
//https://blog.csdn.net/qq_38512571/article/details/127182084
//%SystemDrive%\inetpub\wwwroot 网站原始地址


//https://www.jianshu.com/p/da28457c6fbe

//网站iis设置 C:\WINDOWS\System32\inetsrv\config
//新剧类似bilibili ：https://xinju.tv/vodplay-4086-1-29.html



class WidgetPlus : public QWidget
{
public:   
    WidgetPlus();
    ~WidgetPlus();
    void setLayout1();

private:
    QPushButton *btn1;
    QLabel *lab;

};

#endif // WIDGETPLUS_H
