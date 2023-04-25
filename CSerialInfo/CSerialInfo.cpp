#include "CSerialInfo.h"
CSerialInfo::CSerialInfo(QWidget *parent)
    : QWidget(parent)
{
    //    AllLayout();
    setAllLayout();


    QString dirpath = QCoreApplication::applicationDirPath();
    dirpath += "\\StyleSheet.qss";

    QString str = ":/new/prefix1/StyleSheet.qss";

    qDebug()<<"dirpath is :"<<dirpath.toStdString().c_str()<<endl;
    qDebug()<<"dirpath is :"<<QDir::currentPath().toStdString().c_str()<<endl;
    qDebug()<<"dirpath is :"<<str.toStdString().c_str()<<endl;
    readStyleSheet(str);



    QString qss = QString(".SearchButton {background: gray; color: white; border: 1 solid gray;min-width: 40px;}")

            + QString(".SearchButton:hover {background: black; color: white; border: 1 solid black;}")

            + QString(".SearchButton:pressed {background: white;color: black;}");

    setStyleSheet(qss);

//    const QString label_style =
//        "min-width:40px;min-height:40px;max-width:40px;max-height:40px;border-radius:20px;border:1px solid black;background:red";
//    setStyleSheet(label_style);


//    e_edit->setText(str);
//    e_edit->setPlaceholderText("搜索");

    setQPushButtonstyle();
//    createListSerial();
//    createListNet();
}

CSerialInfo::~CSerialInfo()
{

    close();

}

bool CSerialInfo::readStyleSheet(const QString &s)
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

void CSerialInfo::AllLayout()
{
    int nWidth = GetSystemMetrics(SM_CXSCREEN)/2;
    int nHeight = GetSystemMetrics(SM_CYSCREEN)/2;
    this->resize(QSize(nWidth,nHeight));

    //    QScreen *screen = qApp->primaryScreen();
    //    int nWidth2 = screen->size().width();            //屏幕宽
    //    int nHeight2 = screen->size().height();

    //    QRect rect = screen->geometry();
    //    int width = rect.width();
    //    int height = rect.height();

    //    qreal realX = screen->physicalDotsPerInchX();
    //    qreal realY = screen->physicalDotsPerInchY();
    //    qreal realWidth = width / realX * 2.54;
    //    qreal realHeight = height / realY *2.54;


    l_thislayout = new QVBoxLayout(this); //列
    l_navilayout = new QHBoxLayout; //行
    l_tailLayout = new QHBoxLayout;
    l_tablelayout = new QHBoxLayout;
    l_table1layout = new QHBoxLayout;
    c_box = new QComboBox();


    t_tableview= new QTableView(this);
    t_tableview1 = new QTableView(this);
    b_add = new QPushButton("添加");
    b_reset = new QPushButton("重置");
    b_return= new QPushButton("返回");
    b_edit = new QPushButton("修改");
    b_edit->setToolTip("修改");

    l_labeltable = new QLabel("表一说明");
    l_labeltable1 = new QLabel("表二说明");
    e_edittable = new QLineEdit("串口");
    e_edittable1 = new QLineEdit("网口");
    l_tablelayout->addWidget(l_labeltable);
    l_table1layout->addWidget(l_labeltable1);
    l_tablelayout->addWidget(e_edittable);
    l_table1layout->addWidget(e_edittable1);

    l_label = new QLabel("导航栏");
    e_edit = new QLineEdit;
    //    myedit = new search_box;
    //    myedit->setStyleSheet(QString("background-color:black;"));

    e_editwidget = new QWidget;
    l_editlayout = new QHBoxLayout;
    e_pushbutton = new QPushButton(tr("测试"));
    l_editlayout->addWidget(e_edit,1);
    l_editlayout->addWidget(e_pushbutton,1);

    //添加图片
    QAction *action = new QAction(this);
    action->setIcon(QIcon(":/new/prefix1/51.png"));
    e_edit->addAction(action,QLineEdit::TrailingPosition);


    //connect(action,&QAction::trigger,e_pushbutton,&QPushButton::clicked);


    connect(e_pushbutton,&QPushButton::clicked,this,[=](){
        qDebug()<<"123456"<<endl;
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("About");
        msgBox.setTextFormat(Qt::RichText);   //this is what makes the links clickable
        msgBox.setText("QQ:895377235<br>Email:<a href='mailto:hnrayer@gmail.com'>hnrayer@gmail.com</a><br>WebSite:<a href=http://www.cnblogs.com/elesos/ >elesos</a>");
        msgBox.setIconPixmap(QPixmap(":/ico/res/ExcelReport.ico"));
        msgBox.exec();
    });


    l_navilayout->addWidget(l_label,1);
    l_navilayout->addLayout(l_editlayout,3);
    //l_navilayout->addLayout(l_editlayout,3);
    l_navilayout->addWidget(c_box,2);
    c_box->addItem(tr("加载1"));
    c_box->addItem(tr("加载2"));
    c_box->addItem(tr("加载3"));
    c_box->addItem(tr("加载4"));
    c_box->addItem(tr("加载5"));


    l_tailLayout->addWidget(b_add);
    l_tailLayout->addWidget(b_edit);
    l_tailLayout->addWidget(b_reset);
    l_tailLayout->addWidget(b_return);


    l_thislayout->addLayout(l_navilayout);
    l_thislayout->addLayout(l_tablelayout);
    l_thislayout->addWidget(t_tableview);
    l_thislayout->addLayout(l_table1layout);
    l_thislayout->addWidget(t_tableview1);
    l_thislayout->addLayout(l_tailLayout);
    setLayout(l_thislayout);
}

void CSerialInfo::setAllLayout()
{
    //    QLineEdit *edit = new QLineEdit;
    //    edit->setPlaceholderText(tr("请在此处搜索"));
    //    QPushButton *btn = new QPushButton;
    //    btn->setText(tr("搜索"));
    //    QHBoxLayout *layout = new QHBoxLayout(this);

//    QLineEdit *m_pSearchLineEdit = new QLineEdit(this);
//    QPushButton *pSearchButton = new QPushButton(tr("456"));
//    pSearchButton->setCursor(Qt::PointingHandCursor);
//    pSearchButton->setFixedSize(22, 22);
//    pSearchButton->setToolTip(QStringLiteral("搜索"));
//    pSearchButton->setStyleSheet("QPushButton{border-image:url(:/images/icon_search_normal); background:transparent;} QPushButton:hover{border-image:url(:/images/icon_search_hover)} QPushButton:pressed{border-image:url(:/images/icon_search_press)}");

//    QMargins margins = m_pSearchLineEdit->textMargins();
//    m_pSearchLineEdit->setTextMargins(margins.left(), margins.top(), pSearchButton->width(), margins.bottom());
//    m_pSearchLineEdit->setPlaceholderText(QStringLiteral("请输入搜索内容"));
//    QHBoxLayout *pSearchLayout = new QHBoxLayout();
//    pSearchLayout->addStretch();
//    pSearchLayout->addWidget(pSearchButton);
//    pSearchLayout->setSpacing(0);
//    pSearchLayout->setContentsMargins(0, 0, 0, 0);
//    m_pSearchLineEdit->setLayout(pSearchLayout);

//    QGridLayout *layout = new QGridLayout(this);
//    layout->addWidget(m_pSearchLineEdit);
//    setLayout(layout);
//    connect(pSearchButton,&QPushButton::clicked,this,[=](){});

//    resize(800,900);
    showFullScreen();

//    setWindowFlag(Qt::FramelessWindowHint);
    QLabel *forward_path = new QLabel();
    QLineEdit *forward_line_edit = new QLineEdit();
    QLineEdit *search_line_edit = new QLineEdit();
    QToolButton *forward_button = new QToolButton(this);
    QToolButton *search_button = new QToolButton(this);

    forward_button->setToolTip(tr("forward"));
    search_button->setToolTip(tr("search"));
    forward_line_edit->setPlaceholderText(tr("computer"));
    search_line_edit->setPlaceholderText(tr("search"));
    QSizePolicy opsas(QSizePolicy::Minimum,QSizePolicy::Fixed);
    forward_line_edit->setSizePolicy(opsas);


    forward_path->setPixmap(QPixmap(":/new/prefix1/10.jpg"));
    forward_path->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QIcon forward_icon = QIcon(":/new/prefix1/10.jpg");
    forward_button->setFixedSize(25, 24);
    forward_button->setIcon(forward_icon );
    forward_button->setIconSize(QSize(16, 16));
    forward_button->setAutoRaise(true);
    forward_button->setCursor(Qt::ArrowCursor);
    forward_button->setStyleSheet("background:transparent;");

    QIcon search_icon = QIcon(":/new/prefix1/51.png");
    search_button ->setFixedSize(25, 24);
    search_button ->setIcon(search_icon );
    search_button ->setIconSize(QSize(16, 16));
    search_button ->setAutoRaise(true);
    search_button ->setCursor(Qt::ArrowCursor);
    search_button ->setStyleSheet("background:transparent;");

    forward_path->setFixedSize(20, 24);
    forward_line_edit->setMinimumSize(100, 25);
    search_line_edit->setMinimumSize(50, 25);

    QSplitter *search_splitter = new QSplitter(this);
    search_splitter->setFrameShape(QFrame::NoFrame);
    search_splitter->setHandleWidth(1);

    QHBoxLayout *forward_layout = new QHBoxLayout();
    forward_layout->addWidget(forward_path);
    forward_layout->addStretch();
    forward_layout->addWidget(forward_button);
    forward_layout->setSpacing(0);
    forward_layout->setContentsMargins(0, 0, 0, 0);
    forward_line_edit->setLayout(forward_layout);
    forward_line_edit->setTextMargins(forward_path->width(), 0, forward_button->width(), 0);     //防止文本框输入内容位于按钮之下

    QHBoxLayout *search_layout = new QHBoxLayout();
    search_layout->addStretch();
    search_layout->addWidget(search_button);
    search_layout->setSpacing(0);
    search_layout->setContentsMargins(0, 0, 0, 0);
    search_line_edit->setLayout(search_layout);
    search_line_edit->setTextMargins(0, 0, search_button->width(), 0);

    search_splitter->addWidget(forward_line_edit);
    search_splitter->addWidget(search_line_edit);
    search_splitter->setStretchFactor(0, 2);
    search_splitter->setStretchFactor(1, 2);
    search_splitter->setChildrenCollapsible(false);
    //setMinimumSize(QSize(600,180));
    QVBoxLayout *grid = new QVBoxLayout(this);

    QWidget *wid = new QWidget;
    DrawDemo *demo = new DrawDemo;
    const QString label_style =
        "min-width:40px;min-height:40px;max-width:40px;max-height:40px;border-radius:20px;border:1px solid black;background:red";
    wid->setStyleSheet(label_style);

    QPushButton *btn = new QPushButton("关闭");
    QHBoxLayout *tailLayout = new QHBoxLayout;
    QPushButton *btn1 = new QPushButton(tr("显示"));
    tailLayout->addStretch(6);
    tailLayout->addWidget(btn);
    tailLayout->addStretch(1);
    tailLayout->addWidget(btn1);
    tailLayout->addStretch(2);
    grid->addWidget(search_splitter,1);
    grid->addWidget(wid,1);
    grid->addWidget(demo,1);
    Form *forms = new Form;
    grid->addWidget(forms,15);
    grid->addLayout(tailLayout);
//    grid->addWidget(btn,1);

    setLayout(grid);

    s=new WidgetPlus;
    connect(btn1,&QPushButton::clicked,this,[=](){

        s->show();
    });
    connect(btn,&QPushButton::clicked,this,[=]()
    {
        s->close();
        this->close();

//        this->destroy();
    });

    forward_line_edit->setStyleSheet("QLineEdit{border-style:outset; border-top-width:1px; border-left-width:1px; border-bottom-width:1px;border-top-color:gray; border-left-color:gray; border-bottom-color:gray; background:white;}");
    search_line_edit->setStyleSheet("QLineEdit{border-style:outset; border-top-width:1px; border-right-width:1px; border-bottom-width:1px;border-top-color:gray; border-right-color:gray; border-bottom-color:gray; background:white;}");
    search_splitter->setStyleSheet("QSplitter::handle{background:lightgray;}");
}

void CSerialInfo::setQPushButtonstyle()
{
    setStyleSheet("QPushButton{ \
                  border: 0px solid;\
            background-color:#F65345;\
outline: 1px solid #0000ff;\
    background-color: #cccccc;\
color: #ff0000;\
    border-radius: 4px;\
padding: 2px;\
}\
QPushButton:disabled{\
    background-color:#DCDCDC;\
    border-radius:20px;\
color:#FFFFFF;    \
}\
QPushButton:hover{\
border: 0px solid;\
    background-color:#f67469;\
    border-radius:20px;\
color:#FFFFFF;\
opacity:0.2;\
}\
QPushButton:pressed{\
    background-color:#c44237;\
    border-radius:20px;\
color:#FFFFFF;    \
}");
}

void CSerialInfo::createListSerial()
{
    m_model = new QStandardItemModel();
    QStringList header;
    header<<"Name"<<"ip"<<"A"<<"B"<<"C"<<"D";
    m_model->setHorizontalHeaderLabels(header);
    t_tableview->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //t_tableview->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive || QHeaderView::Stretch);
    //t_tableview->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    //t_tableview->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
    t_tableview->horizontalHeader()->setStretchLastSection(true);

    t_tableview->setModel(m_model);
    t_tableview->horizontalHeader()->setStyleSheet(
                "QHeaderView::section{background-color:rgb(225,225,225);"
                "color: black;};");

    /*t_tableview->horizontalHeader()->setStyleSheet("QHeaderView::section, QTableCornerButton::section {padding: 1px;"
                                                   "border: none;border-bottom: 1px solid rgb(75, 120, 154);"
                                                   "border-right: 1px solid rgb(75, 120, 154);"
                                                   "border-bottom: 1px solid gray;"
                                                   "background-color:rgba(75, 120, 154, 1);"
                                                   "color:rgba(126,206,244,1);}");
                                                   */
    t_tableview->verticalHeader()->setHidden(true);
    t_tableview->setStyleSheet("selection-background-color:pink");

    t_tableview->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStandardItem *a = new QStandardItem();
    for(int i=0;i<6;i++)
    {
        a = new QStandardItem(QString("%1").arg(i));
        m_model->setItem(i,0,a);
        a = new QStandardItem(QString("s"));
        m_model->setItem(i,1,a);
        m_model->setItem(i,2,new QStandardItem("56"));
        m_model->setItem(i,3,new QStandardItem("89"));
        m_model->setItem(i,4,new QStandardItem("23"));
        m_model->setItem(i,5,new QStandardItem("12"));
        m_model->setItem(i,6,new QStandardItem("5645"));

        for(int j=0;j<7;j++)
        {
            m_model->item(i,j)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        }
    }
}

void CSerialInfo::createListNet()
{
    m_model1 = new QStandardItemModel();
    QStringList header;
    header<<"Name"<<"ip"<<"A"<<"B"<<"C"<<"D";
    m_model1->setHorizontalHeaderLabels(header);
    t_tableview1->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    t_tableview1->setModel(m_model1);
    t_tableview1->horizontalHeader()->setStyleSheet(
                "QHeaderView::section{background-color:rgb(225,225,225);"
                "color: black;};");
}

/*
void CSerialInfo::newAnalogData()
{
    int dataSum = 30;
    reSerialData *serialData = nullptr;
    for(int i=0;i<dataSum;i++)
    {
        serialData->s_name = QString("%1名字").arg(i);
        serialData->s_ip   = QString("192.168.1.%1").arg(i);
        serialData->s_a    = QString("192.168.1.%1").arg(i);
        serialData->s_b    = QString("192.168.1.%1").arg(i);
        serialData->s_c    = QString("192.168.1.%1").arg(i);
        serialData->s_d    = QString("192.168.1.%1").arg(i);
        data.push_back(serialData);
        //data->push_back(a);
        qDebug()<<data[i]->s_name<<endl;
    }
}
*/
