#include "mainwindow.h"
#include "ui_mainwindow.h"


using namespace std;
//#include <QTextCodec>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setMinimumSize(450,380);

    //setStatusBar(nullptr);

    //setMenuBar(nullptr);
    //ui->mainToolBar->setStyleSheet("QToolBar{border-color:rgb(0,0,0);border:none}");
    //    QTextCodec *codec = QTextCode::codecForName("UTF-8");


    // QTextCodec *codec = QTextCodec::codecForName("UTF-8");//修改这两行

    setAutoFillBackground(true);
    QPalette pal = this->palette();
    //pal.setBrush(backgroundRole(),QPixmap(":/C:/Users/WinkJie/Pictures/Camera Roll/mygrils1.jpg"));
    pal.setBrush(backgroundRole(),QPixmap(":/new/prefix1/Iu.jpg"));
    setPalette(pal);

    //设置整体的透明度
    //setWindowOpacity(0.5);

    QWidget *widget = new QWidget(this);
    QPushButton *pushbutton = new QPushButton(widget);
    QPushButton *cancelPusht = new QPushButton(widget);
    QPushButton *btndir = new QPushButton(widget);


    QPalette pal1 = palette();
    pal1.setColor(QPalette::Background, QColor(0x00,0xff,0x00,0x00));
    //enteredit->setPalette(pal1);
    //enteredit->setStyleSheet()

    //setpal(enteredit);
    QString cmd = "ipconfig";
    QString result;
    //char one = cmd.toLatin1().data();
    //executeCMD(cmd.toLatin1(),result.toLatin1().data());
    //qDebug()<<result<<endl;

    QHBoxLayout *layout = new QHBoxLayout();
    QVBoxLayout *vlayout = new QVBoxLayout();
    QVBoxLayout *vlayout_1 = new QVBoxLayout();
    QVBoxLayout *vlayout_2 = new QVBoxLayout();
    QWidget *threesize = new QWidget(this);
    //threesize->setStyleSheet("background:yellow");


    vlayout_2->addWidget(threesize);
   // MyLineEdit * test = new MyLineEdit(widget);
    enteredit = new QTextEdit(widget);
    outedit = new QTextEdit(widget);
    outedit->setReadOnly(true);
    QLabel *label = new QLabel(widget);
    label->setText(codec->toUnicode(""));
    vlayout->addWidget(pushbutton);
    vlayout->addWidget(cancelPusht);
    vlayout->addWidget(btndir);
   // vlayout->addWidget(test);
    vlayout->addWidget(label);
    vlayout_1->addWidget(enteredit);
    vlayout_1->addWidget(outedit);


    QPalette labelpal = label->palette();
    labelpal.setColor(QPalette::Background,QColor(255,212,23,0));
    label->setAutoFillBackground(true);
    label->setPalette(labelpal);

    QPalette enterpal = enteredit->palette();
    enterpal.setColor(QPalette::Background,QColor(255,212,23,0));
    enteredit->setAutoFillBackground(true);
    enteredit->setPalette(enterpal);

    /*设置QTextEdit背景色*/
    QPalette outpal = outedit->palette();
    outpal.setBrush(QPalette::Base,QColor(255,212,23,0));
    // outedit->setAutoFillBackground(true);
    outedit->setPalette(outpal);

    QPalette enterpa = enteredit->palette();
    enterpa.setBrush(QPalette::Base,Qt::gray);
    enteredit->setPalette(enterpa);

    QPalette enterpa1 = enteredit->palette();
    enterpa1.setBrush(QPalette::Base,QColor(15,15,15,0));
    enteredit->setPalette(enterpa1);


    //    enteredit->setWindowFlags(Qt::FramelessWindowHint | enteredit->windowFlags());
    //    enteredit->setAttribute(Qt::WA_TranslucentBackground);
    //    QWidget *v = enteredit->viewport();
    //    v->setWindowFlags(Qt::FramelessWindowHint|v->windowFlags());
    //    v->setAttribute(Qt::WA_TranslucentBackground);


    //enteredit->setAttribute(Qt::WA_TranslucentBackground,true);


    cancelPusht->setText(codec->toUnicode("清除文本"));
    pushbutton->setText(codec->toUnicode("运行"));
    btndir->setText(QString::fromUtf8("目录遍历"));
    //layout->addWidget(vlayout);
    layout->addLayout(vlayout);

    //layout->addWidget(label);
    layout->addLayout(vlayout_1);
    layout->addLayout(vlayout_2);
    layout->setStretchFactor(vlayout,1);
    layout->setStretchFactor(vlayout_1,5);
    layout->setStretchFactor(vlayout_2,5);

    widget->setLayout(layout);
    this->setCentralWidget(widget);
    //this->setLayout(widget);
    connect(pushbutton,SIGNAL(clicked()),this,SLOT(clickedBtn()));
    connect(cancelPusht,SIGNAL(clicked()),this,SLOT(clearText()));
    connect(btndir,SIGNAL(clicked()),this,SLOT(displaymdl()));
    //connect(test,SIGNAL(mouseDoubleClicked()),this,SLOT(displaytest()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clearText()
{
    enteredit->clear();
    outedit->clear();
}

void MainWindow::displaymdl()
{

    ofstream of("D:\\Qt_test.txt",ios::app);

    std::string path = enteredit->toPlainText().toStdString();
    std::vector<std::string> files;
    signalGetFolders(path,files);
    //GetFolders(path,files);
    std::string file_sum = "";
    if(files.size()>0)
    {
        for(size_t i = 0;i < files.size();i++)
        {
            file_sum = file_sum + files[i].c_str()+"\n";
        }
    }
    outedit->setText(QString::fromUtf8(file_sum.c_str()));

    //time_t time_now = time(NULL);
    of<<getNowTime()<<" "<<endl<<endl;
    of<<file_sum.c_str()<<endl;
}

void MainWindow::displaytest()
{
    qDebug()<<"我在测试"<<endl;
}


void MainWindow::clickedBtn()
{
    FILE* file;
    std::string result;
    std::string tmps = enteredit->toPlainText().toStdString();
    //char *cmd = tmps.c_str();

    ofstream of("D:\\Qt_test.txt",ios::app);


    char ptr[1024] = { 0 };

    char tmp[1024] = { 0 };

    strcat_s(ptr, tmps.c_str());

    //std::string result = "";

    if ((file = _popen(ptr, "r")) != nullptr)

    {

        while (fgets(tmp, 1024, file) != nullptr) {

            result = result + tmp;

        }

        _pclose(file);

    }
    // outedit->setText(QString::fromUtf8(result.c_str()));
    outedit->setText(QString::fromUtf8(result.c_str()));
    //enteredit->setText(QString::fromUtf8(result));
    qDebug()<<result.c_str()<<endl;
    // time_t time_now = time(NULL);
    of<<getNowTime()<<" "<<endl<<endl;
    of<<result.c_str()<<endl;
    qDebug()<<"test"<<endl;
    of.close();

}

bool MainWindow::executeCMD(const char *cmd, char *result)
{
    char buf_ps[1024];
    char ps[1024]={0};
    FILE *ptr;
    strcpy(ps, cmd);
    if((ptr=popen(ps, "r"))!=NULL)
    {
        while(fgets(buf_ps, 1024, ptr)!=NULL)
        {
            strcat(result, buf_ps);
            if(strlen(result)>1024)
                break;
        }
        pclose(ptr);
        ptr = NULL;
    }
    else
    {
        printf("popen %s error\n", ps);
        return 1;
    }
    return 0;
}

void MainWindow::setpal(QPaintEvent*)
{
    QPainter p(this);
    p.setCompositionMode( QPainter::CompositionMode_Clear );
    p.fillRect( 10, 10, 300, 300, Qt::SolidPattern );
}

void MainWindow::GetFolders(std::string path, std::vector<std::string>& files)
{
    //文件句柄
    long hFile = 0;
    //文件信息
    struct _finddata_t fileinfo;
    std::string p;
    if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1) {
        do {
            if ((fileinfo.attrib & _A_SUBDIR)) {
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0) {
                    files.push_back(fileinfo.name);
                    //files.push_back(p.assign(path).append("\\").append(fileinfo.name));
                }
            }
        } while (_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
    }
}

void MainWindow::signalGetFolders(std::string path, std::vector<std::string>& files)
{
    //文件句柄
    long hFile = 0;
    //文件信息
    struct _finddata_t fileinfo;
    std::string p;
    if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1) {
        do {
            if ((fileinfo.attrib & _A_SUBDIR)) {
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0) {
                    files.push_back(fileinfo.name);
                    //files.push_back(p.assign(path).append("\\").append(fileinfo.name));
                }
            }
        } while (_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
    }
}

string MainWindow::getNowTime()
{
    SYSTEMTIME sys;
    GetLocalTime( &sys );
    char tmpbuff[64];

    sprintf( tmpbuff, "%4d/%02d/%02d %02d:%02d:%02d \n",sys.wYear,sys.wMonth,sys.wDay,sys.wHour,
             sys.wMinute, sys.wSecond);
    //    WORD time_sum = NULL;
    //    time_sum = time_sum + sys.wYear + sys.wMonth+sys.wDay+sys.wHour+sys.wMinute+sys.wSecond;
    //    sprintf(tmpbuff,"%d",time_sum);
    std::string tmp = tmpbuff;

    qDebug()<<sys.wDayOfWeek<<endl;
    qDebug()<<tmpbuff<<endl;
    //qDebug()<<"test"<<endl;

    return tmpbuff;

}

string MainWindow::getNowTime_stap()
{
    time_t t = time(NULL);
    struct tm* stime=localtime(&t);
    char tmp[32]={NULL};
    sprintf(tmp, "%04d-%02d-%02d %02d:%02d:%02d",1900+stime->tm_year,1+stime->tm_mon,
            stime->tm_mday, stime->tm_hour,
            stime->tm_min,stime->tm_sec);
    qDebug()<<tmp<<endl;

    return tmp;

}


