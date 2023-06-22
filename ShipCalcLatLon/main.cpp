#include "Widget.h"
#include <QApplication>
#include "DataLogger.h"
#include "LoginWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    LoginWidget op;
    op.show();

    std::string directory = QDir::currentPath().toStdString(); // 设置存储数据的目录路径
    DataLogger logger(directory);

    QString str=QString::fromStdString("sd89测试")+"  "+QString::fromStdString("sd89测试");
    logger.logData("Hello, World!");
    logger.logData("42");
    logger.logData(str.toStdString());

    return a.exec();
}
