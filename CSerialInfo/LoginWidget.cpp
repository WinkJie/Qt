#include "LoginWidget.h"
#include "ui_LoginWidget.h"

LoginWidget::LoginWidget(QWidget *parent) :
    QWidget(parent),numpic(0),
    ui(new Ui::LoginWidget)
{
    ui->setupUi(this);

    //    QString str = ":/new/StyleSheet.qss";
    //    if(!readStyleSheet(str))
    //        qDebug()<<tr("载入失败")<<endl;

    resize(800,800);
    setWindowIcon(QIcon(":/new/15.jpg"));//窗口头图标设计
    setWindowTitle(tr("登录界面"));

    ui->gridLayout->setContentsMargins(0,0,0,0);

    QPalette pal;
    pal.setBrush(QPalette::Background,QBrush(QPixmap(":/new/10.jpg")));
    setPalette(pal);

    list = GetQrcListName();
    ui->label_3->setScaledContents(false);
    QPalette pal3;
    pal3.setBrush(QPalette::Background,QBrush(QPixmap(list[0])));
    ui->label_3->setPalette(pal3);
    ui->label_3->setText(tr(""));
//    ui->label_3->setStyleSheet("border-image:url(:/new/13.jpg)");

    setBackgroundLabel3();

    ui->label->resize(40,40);
    ui->label->setScaledContents(true);
    ui->label->setPixmap(QPixmap(":/new/17.JPG"));

    ui->label_2->resize(40,40);
    ui->label_2->setScaledContents(true);
    ui->label_2->setPixmap(QPixmap(":/new/18.JPG"));

    ui->lineEdit->setPlaceholderText(tr("账号"));
    ui->lineEdit_2->setPlaceholderText(tr("密码"));
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);

    ui->pushButton_3->setText(tr("下一张"));
    ui->pushButton_4->setText(tr("上一张"));
    ui->pushButton->setIcon(QIcon(":/new/15.jpg"));
    ui->pushButton_2->setIcon(QIcon(":/new/16.jpg"));

    connect(ui->pushButton,&QPushButton::clicked,[=](){
        emit slo();
    });
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        this->close();
    });

    connect(ui->pushButton_3,&QPushButton::clicked,[=](){
        if(numpic+1<list.size())
        {
            numpic++;
            setBackgroundLabel3();
        }
        else
        {
            QMessageBox::warning(this,"提示","没有下一张了！");
        }
    });
    connect(ui->pushButton_4,&QPushButton::clicked,[=](){
        if(numpic>0)
        {
            numpic--;
            setBackgroundLabel3();
        }
        else
        {
            QMessageBox::warning(0,"提示","这已经是第一张了！");
        }
    });


    setStyleSheet("QLineEdit    {                                                            \
                  background-color:rgb(240,240,240);/*背景色*/                                            \
            min-height:30px; /*最小高度*/                                                            \
    min-width:180px; /*最小宽度*/                                                            \
    border-style:solid;/*边框样式 solid实线 none无边框 inset/outset 3D边框*/                        \
    border-width:4px; /*边框宽度像素*/                                                         \
    border-radius:10px;/*边框圆角半径像素*/                                                      \
    border-color:rgba(205,205,205);/*边框颜色*/                                              \
    font-size:12pt;/*字体 字体大小*/                                                           \
color: black;/*字体颜色*/                                                                \
padding:6px;/*填衬*/                                                                   \
}                   \
QPushButton                                                                               \
{                                                                                         \
    background-color:rgba(198,198,198);/*背景色*/                                            \
    min-height:30px; /*最小高度*/                                                             \
    min-width:180px; /*最小宽度*/                                                             \
    border-style:solid;/*边框样式 solid实线 none无边框 inset/outset 3D边框*/                         \
    border-width:4px; /*边框宽度像素*/                                                          \
    border-radius:10px;/*边框圆角半径像素*/                                                       \
    border-color:rgba(205,205,205);/*边框颜色*/                                               \
    font-size:12pt;/*字体 字体大小*/                                                            \
color: black;/*字体颜色*/                                                                 \
padding:6px; /*填衬*/                                                                   \
}                                                                                         \
/*鼠标按下状态*/                                                                                \
QPushButton:pressed                                                                       \
{                                                                                         \
    background-color:rgba(198,198,220);/*背景色*/                                            \
    border-color:rgba(205,205,205);/*边框颜色*/                                               \
    border-style:solid;/*边框样式 solid实线 none无边框 inset/outset 3D边框*/                         \
color: black;/*字体颜色*/                                                                 \
}"
);

}

LoginWidget::~LoginWidget()
{
    delete ui;
}

bool LoginWidget::readStyleSheet(const QString &s)
{
    QFile file(s);
    file.open(QFile::ReadOnly);
    if(file.isOpen())
    {
        setStyleSheet(file.readAll());
        file.close();
        return true;
    }
    else
        return false;
}

bool LoginWidget::setBackgroundLabel3()
{
    QString tempstyle = ui->label_3->styleSheet();
    if(tempstyle.isEmpty())
    {
        tempstyle = "border-image:url(:/new/13.jpg)";
    }
    else
    {
        int pos = tempstyle.lastIndexOf(":");
        tempstyle = tempstyle.left(pos+1);
        QString i = "\"";
        qDebug()<<i<<endl;
        tempstyle.append("/new/");
        tempstyle.append(list[numpic]);
        tempstyle.append(")");
    }
    ui->label_3->setStyleSheet(tempstyle);
}

QVector<QString> LoginWidget::GetQrcListName()
{
    QVector<QString> nameList;
    foreach (const QString &imageName, QDir(":/new").entryList())
    {
        if(ConfirmPic(imageName))
        {
            nameList.push_back(imageName);
        }
        qDebug()<<imageName<<endl;
    }
    return nameList;
}

bool LoginWidget::ConfirmPic(const QString &strName)
{
    bool flag = false;
    int pos = strName.lastIndexOf(".");  //废弃
    QString standard1 = "png";
    QString standard2 = "jpg";
    QString standard3 = "PNG";
    QString standard4 = "JPG";
    QString type = strName.right(3);   //直接截取尾椎四个字母
    qDebug()<<type<<endl;
    if(type == standard1||type == standard2||type == standard3||type == standard4)
        flag = true;
    return flag;
}

void LoginWidget::emiso()
{

}
