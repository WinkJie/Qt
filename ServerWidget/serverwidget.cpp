#include "serverwidget.h"
#include "ui_serverwidget.h"



#define theUi (static_cast<Ui::ServerWidget*> ui)
#define theui ((Ui::ServerWidget*)(ui))
#define mini(a,b) {return a>b?b:a;}



ServerWidget::ServerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServerWidget)
{
    theui->setupUi(this);
    theUi->setupUi(this);
//    ui->setupUi(this);

    theUi->groupBox->setParent(this);

    textEditRead = new QTextEdit(this);
    textEditWrite = new QTextEdit(this);

    tcpServer = nullptr;
    tcpSocket = nullptr;

    tcpServer = new QTcpServer(this);

    tcpServer->listen(QHostAddress::Any,8888);
    setWindowTitle(QString::fromUtf8("服务器Server：8888"));

    connect(tcpServer,&QTcpServer::newConnection,
            [=]()
    {
        //取出建立好连接的套接字
        tcpSocket  = tcpServer->nextPendingConnection();
        QString ip = tcpSocket->peerAddress().toString();
        int16_t port = tcpSocket->peerPort();
         QString temp = QString("[%1:%2]:成功连接").arg(ip).arg(port);
         textEditRead->setText(temp);

         connect(tcpSocket,&QTcpSocket::readyRead,
                 [=]()
                    {
                        //从通信套接字中取出内容
                        QByteArray array = tcpSocket->readAll();
                        textEditRead->append(array);
                    }
                 );

    }

    );
}

ServerWidget::~ServerWidget()
{
    delete ui;
}

void ServerWidget::on_buttonSend_clicked()
{
    if(nullptr == tcpSocket)
    {
        return;
    }
    //获取编辑区内容
    QString str = textEditWrite->toPlainText();
    //给对方发送数据， 使用套接字是tcpSocket
    tcpSocket->write( str.toUtf8().data() );
}

void ServerWidget::on_buttonClose_clicked()
{
    if(nullptr == tcpSocket)
    {
        return;
    }

    //主动和客户端端口连接
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
    tcpSocket = nullptr;
}
