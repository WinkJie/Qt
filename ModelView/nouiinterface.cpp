#include "nouiinterface.h"

NoUiInterface::NoUiInterface(QWidget *parent):QMainWindow(parent)
{
    this->setParent(parent);
    if(TypeInterface::NORMAL==typeInt)
        this->SetUpUi();
    else
        this->setupUi();

    //SetUpUi();
    //setupUi();
}

NoUiInterface::~NoUiInterface()
{
//    deleteLater()
}

void NoUiInterface::setupUi()
{
    this->resize(600,600);

    QPushButton *btn =new QPushButton();
    btn->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));
    m_fileMenu = new QMenu("&File(F)",this);
    //向menu中加入Action
    QAction *newFile = new QAction("&New File",this);
    newFile->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));//给action 设置快捷键
    m_fileMenu->addAction(newFile);
    QAction *openFile = new QAction("&Open File",this);
    openFile->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));//给action 设置快捷键
    m_fileMenu->addAction(openFile);
    QAction *saveFile = new QAction("&Save File",this);
    saveFile->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));//给action 设置快捷键
    m_fileMenu->addAction(saveFile);
    QAction *saveFileAs = new QAction("&Save File A",this);
    saveFileAs->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));//给action 设置快捷键
    m_fileMenu->addAction(saveFileAs);
    //向menuBar中加入Menu
    m_menuBar = menuBar();
    m_menuBar->addMenu(m_fileMenu);
    //向menuBar中直接加入Action
    m_menuBar->addAction(new QAction("Close File",this));
    connect(newFile,&QAction::triggered,this,&NoUiInterface::newFileSlot);
    connect(openFile,&QAction::triggered,this,&NoUiInterface::openFileSlot);
    connect(saveFile,&QAction::triggered,this,&NoUiInterface::saveFileSlot);
    connect(saveFileAs,&QAction::triggered,this,&NoUiInterface::saveAsSlot);
    //new一个水平布局，在水平居中加入一个textedit
    QHBoxLayout *mainHbox = new QHBoxLayout(this);
    textEdit = new QTextEdit(this);
    mainHbox->addWidget(textEdit);
    //新建一个widget
    QWidget *widget = new QWidget(this);
    //将水平布局加入到widget中
    widget->setLayout(mainHbox);
    //设置中心窗体为widget
    setCentralWidget(widget);
}

void NoUiInterface::SetUpUi()
{
    widget = new QWidget(this);
    vLayout = new QVBoxLayout;
    btn1 = new QPushButton(this);
    btn2 = new QPushButton(this);
    btn3 = new QPushButton(this);
    btn1->setText(QString("打开"));
    btn2->setText(QString("开始"));
    btn3->setText(QString("结束了，该走了"));   
    vLayout->addWidget(btn1);
    vLayout->addWidget(btn2);
    vLayout->addWidget(btn3);
    widget->setLayout(vLayout);
    this->setCentralWidget(widget);
}

void NoUiInterface::openFileSlot()
{
    QString filePath = QFileDialog::getOpenFileName(
                this, tr("Open File"), "", tr("File (*.txt)"));
    //ui->filePathLineEdit->setText(filePath);
    m_filePath=filePath;
    QFile file(filePath);
    file.open(QIODevice::ReadOnly | QIODevice::Text);//以只读方式打开文件
    QTextStream in(&file);
    //in.setCodec("UTF-8");
    QString content = in.readAll();
    textEdit->setPlainText(content);
    //设置标题
    QFileInfo fi(filePath);
    QString name=fi.fileName();
    this->setWindowTitle(tr("%1[*]").arg(name));
    file.close();
}

void NoUiInterface::saveFileSlot()
{
    QString content;
    content = textEdit->toPlainText();
    QFile file(m_filePath);
    file.open(QIODevice::WriteOnly);
    file.write(content.toLocal8Bit());
    //QTextStream writefiletext(&file);
    //content = QString::fromLocal8Bit(content);
    //writefiletext<<content.toLocal8Bit();
    file.close();
    qDebug()<<content;
}

void NoUiInterface::newFileSlot()
{
    //QTextDocument *document=textEdit->document();
    int ret=QMessageBox::question(this, "Save?",
                                  "disSave, Save",
                                  QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    switch(ret)
    {
    case QMessageBox::Cancel:
        break;
    case QMessageBox::Discard:
        textEdit->setText("");
        this->setWindowTitle(tr("%1[*]").arg(""));
        break;
    case QMessageBox::Save:
        textEdit->setText("");
        this->setWindowTitle(tr("%1[*]").arg(""));
        break;
    }
}

bool NoUiInterface::saveAsSlot()
{
    QString fileName = QFileDialog::getSaveFileName(this,"as file");
    if(fileName.isEmpty())
    {
        return false;
    }
    QString content;
    content = textEdit->toPlainText();
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    file.write(content.toLocal8Bit());
    file.close();
    return true;
}
