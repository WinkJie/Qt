#include "test.h"

Test::Test(QWidget *parent) : QWidget(parent)
{
    Widget *wid=new Widget();
    connect(wid,&Widget::valueChanged,this,[=](){
        qDebug()<<"changed!"<<endl;
    });
    wid->m_value=6;

}
