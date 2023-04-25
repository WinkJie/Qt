#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),numpic(0),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setMouseTracking(true);

    setStyleSheet("QToolTip{border: 0px solid black;background:red;}");
    connect(ui->tableWidget,SIGNAL(cellEntered(int,int)),this,SLOT(cellShow(int,int)));
    setLayoutAnd();
    setData();
}

Form::~Form()
{
    delete ui;
}

void Form::setData()
{
    this->setWindowTitle("Ruku");
    ui->tableWidget->clear();

    QString PaperName,KeyWord,PaperBrief;


    PaperName = "1";
    KeyWord = "2";
    PaperBrief ="3335689878745464651231215546512";

    ui->tableWidget->setColumnCount(7);//只设置列数，行数动态中增加
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<QString::fromUtf8("篇名")
                                               <<QString::fromUtf8("关键字")<<QString::fromUtf8("简介"));
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中的方式
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止修改
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//可以选中单个
    ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);

    int RowCont;
    RowCont=ui->tableWidget->rowCount();
    for(int i=0;i<100;i++)
    {
        RowCont=i;
        ui->tableWidget->insertRow(RowCont);//增加一行

        //插入元素
        ui->tableWidget->setItem(RowCont,0,new QTableWidgetItem(PaperName));
        ui->tableWidget->setItem(RowCont,1,new QTableWidgetItem(KeyWord));
        ui->tableWidget->setItem(RowCont,2,new QTableWidgetItem(PaperBrief));
        ui->tableWidget->setItem(RowCont,3,new QTableWidgetItem(PaperName));
        ui->tableWidget->setItem(RowCont,4,new QTableWidgetItem(KeyWord));
        ui->tableWidget->setItem(RowCont,5,new QTableWidgetItem(PaperBrief));
        ui->tableWidget->setItem(RowCont,6,new QTableWidgetItem(PaperBrief));

    }



}

void Form::setLayoutAnd()
{
    resize(800,800);
    setWindowIcon(QIcon(":/new/prefix1/6.jpg"));//窗口头图标设计
    setWindowTitle(tr("登录界面"));

    list = GetQrcListName();
    ui->label_3->setScaledContents(false);
    QPalette pal3;
    pal3.setBrush(QPalette::Background,QBrush(QPixmap(list[0])));
    ui->label_3->setPalette(pal3);
    ui->label_3->setText(tr(""));
    setBackgroundLabel3();

    ui->lineEdit->setPlaceholderText(tr("账号"));
    ui->lineEdit_2->setPlaceholderText(tr("密码"));
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->label->resize(40,40);
    ui->label->setScaledContents(true);
    ui->label->setPixmap(QPixmap(":/new/prefix1/51.png"));

    ui->label_2->resize(40,40);
    ui->label_2->setScaledContents(true);
    ui->label_2->setPixmap(QPixmap(":/new/prefix1/51.png"));
    connect(ui->pushButton_4,&QPushButton::clicked,this,[=](){
        if(numpic<list.size()-1)
        {
            numpic++;
            setBackgroundLabel3();
        }
        else
        {
            QMessageBox bo;
            bo.warning(this,tr("提示"),tr("已经是最后一张了"));
            Sleep(50);
            bo.exec();

            //            QMessageBox *box=new QMessageBox(this);
            //            QTimer::singleShot(5000, box, SLOT(accept()));
            //            QTimer::singleShot(2000, box, [box]()
            //            {
            //                int tt=1,t=2;
            //                QDateTime MAspaceTime=QDateTime::currentDateTime();
            //                bool SendTWeb;
            //                do{
            //                    SendTWeb=(MAspaceTime.secsTo(QDateTime::currentDateTime())>2);
            //                    if (MAspaceTime.secsTo(QDateTime::currentDateTime())>=tt){
            //                        tt++;
            //                        box->setWindowTitle(tr("%1").sprintf("%d秒后自动关闭",t--));
            //                        qDebug()<<MAspaceTime.secsTo(QDateTime::currentDateTime());
            //                        if (box->isHidden()) break;
            //                    }
            //                    QApplication::processEvents();
            //                }while(!SendTWeb);
            //            }
            //            );
            //            box->setAttribute(Qt::WA_DeleteOnClose);
            //            box->setIcon(QMessageBox::Information);
            //            box->setWindowTitle(tr("2秒后自动关闭"));
            //            box->setText(tr("已经是最后一张了"));
            //            box->exec();


            //             QMessageBox *box = new QMessageBox(this);
            //             box->warning(nullptr,tr("提示"),tr("已经是最后一张了"));
            //             Sleep(2000);
            //            box->close();
            //            box->exec();
        }
    });
    connect(ui->pushButton_3,&QPushButton::clicked,this,[=](){
        if(numpic>0)
        {
            numpic--;
            setBackgroundLabel3();
        }
        else
            QMessageBox::warning(nullptr,tr("提示"),tr("已经是第一张了"));

    });
    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
        qDebug()<<"登录"<<endl;
        QString account = ui->lineEdit->text();
        QString password = ui->lineEdit_2->text();
        qDebug()<<"wer"<<account<<"password"<<password<<endl;
    });
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        qDebug()<<"取消"<<endl;
        ui->lineEdit->setText(tr(""));
        ui->lineEdit_2->setText(tr(""));
        //         this->close();
        //         this->setAttribute(Qt::WA_DeleteOnClose);
    });
    //     connect(ui->label_3,&QLabel::setMovie,this,[=](){
    //         qDebug()<<" "<<endl;
    //     });
}


QVector<QString> Form::GetQrcListName()
{
    QVector<QString> nameList;
    foreach (const QString &imageName, QDir(":/new/prefix1").entryList())
    {
        if(ConfirmPic(imageName))
        {
            nameList.push_back(imageName);
        }
        qDebug()<<imageName<<endl;
    }
    return nameList;
}


bool Form::ConfirmPic(const QString &strName)
{
    bool flag = false;
    int pos = strName.lastIndexOf(".");  //废弃
    Q_UNUSED(pos);
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


void Form::cellShow(int row, int colum)
{
    QTableWidgetItem *item = ui->tableWidget->item(row, colum);
    if(item!=nullptr)
    {
        //        item->text() = "<b style=\"background:white;color:black;\">%1</b>";
        QToolTip::showText(QCursor::pos(),item->text());
        // QMessageBox::information(this, "information", "single clicked text is "+item->text());
    }
}

bool Form::setBackgroundLabel3()
{
    QString tempstyle = ui->label_3->styleSheet();
    if(tempstyle.isEmpty())
    {
        tempstyle = "border-image:url(:/new/prefix1/10.jpg)";
    }
    else
    {
        int pos = tempstyle.lastIndexOf(":");
        tempstyle = tempstyle.left(pos+1);
        QString i = "\"";
        qDebug()<<i<<endl;
        tempstyle.append("/new/prefix1/");
        tempstyle.append(list[numpic]);
        tempstyle.append(")");
    }
    ui->label_3->setStyleSheet(tempstyle);
    return 0;
}
