#include "LoginWidget.h"
#include "ui_LoginWidget.h"

LoginWidget::LoginWidget(QWidget *parent) :
    QWidget(parent),numpic(0),
    ui(new Ui::LoginWidget)
{
    ui->setupUi(this);

    //    QString str = ":/new/StyleSheet.qss";
    //    if(!readStyleSheet(str))
    //        qDebug()<<tr("����ʧ��")<<endl;

    resize(800,800);
    setWindowIcon(QIcon(":/new/15.jpg"));//����ͷͼ�����
    setWindowTitle(tr("��¼����"));

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

    ui->lineEdit->setPlaceholderText(tr("�˺�"));
    ui->lineEdit_2->setPlaceholderText(tr("����"));
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);

    ui->pushButton_3->setText(tr("��һ��"));
    ui->pushButton_4->setText(tr("��һ��"));
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
            QMessageBox::warning(this,"��ʾ","û����һ���ˣ�");
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
            QMessageBox::warning(0,"��ʾ","���Ѿ��ǵ�һ���ˣ�");
        }
    });


    setStyleSheet("QLineEdit    {                                                            \
                  background-color:rgb(240,240,240);/*����ɫ*/                                            \
            min-height:30px; /*��С�߶�*/                                                            \
    min-width:180px; /*��С���*/                                                            \
    border-style:solid;/*�߿���ʽ solidʵ�� none�ޱ߿� inset/outset 3D�߿�*/                        \
    border-width:4px; /*�߿�������*/                                                         \
    border-radius:10px;/*�߿�Բ�ǰ뾶����*/                                                      \
    border-color:rgba(205,205,205);/*�߿���ɫ*/                                              \
    font-size:12pt;/*���� �����С*/                                                           \
color: black;/*������ɫ*/                                                                \
padding:6px;/*���*/                                                                   \
}                   \
QPushButton                                                                               \
{                                                                                         \
    background-color:rgba(198,198,198);/*����ɫ*/                                            \
    min-height:30px; /*��С�߶�*/                                                             \
    min-width:180px; /*��С���*/                                                             \
    border-style:solid;/*�߿���ʽ solidʵ�� none�ޱ߿� inset/outset 3D�߿�*/                         \
    border-width:4px; /*�߿�������*/                                                          \
    border-radius:10px;/*�߿�Բ�ǰ뾶����*/                                                       \
    border-color:rgba(205,205,205);/*�߿���ɫ*/                                               \
    font-size:12pt;/*���� �����С*/                                                            \
color: black;/*������ɫ*/                                                                 \
padding:6px; /*���*/                                                                   \
}                                                                                         \
/*��갴��״̬*/                                                                                \
QPushButton:pressed                                                                       \
{                                                                                         \
    background-color:rgba(198,198,220);/*����ɫ*/                                            \
    border-color:rgba(205,205,205);/*�߿���ɫ*/                                               \
    border-style:solid;/*�߿���ʽ solidʵ�� none�ޱ߿� inset/outset 3D�߿�*/                         \
color: black;/*������ɫ*/                                                                 \
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
    int pos = strName.lastIndexOf(".");  //����
    QString standard1 = "png";
    QString standard2 = "jpg";
    QString standard3 = "PNG";
    QString standard4 = "JPG";
    QString type = strName.right(3);   //ֱ�ӽ�ȡβ׵�ĸ���ĸ
    qDebug()<<type<<endl;
    if(type == standard1||type == standard2||type == standard3||type == standard4)
        flag = true;
    return flag;
}

void LoginWidget::emiso()
{

}
