#pragma execution_character_set(“utf-8”)
#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QLabel>
#include <QTextEdit>
#include <QTextCodec>
#include <QPalette>
#include <QPainter>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <fstream>
#include <string>
#include <io.h>
//#include <ctime>
#include <windows.h>
#include <time.h>
#include "mylineedit.h"


#include <QtNetwork/QTcpServer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /*执行cmd命令并获取执行结果*/
    bool executeCMD(const char *cmd, char *result);


    //获取路径下的所有文件（含递归）
    void GetFolders(std::string path, std::vector<std::string>& files);
    //获取路径下的文件夹（单层）
    void signalGetFolders(std::string path, std::vector<std::string>& files);

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");

    std::string getNowTime();
    std::string getNowTime_stap();

    void setpal(QPaintEvent*);

    //QLabel *label;
    QTextEdit *enteredit;
    QTextEdit *outedit;

public slots:
    void clickedBtn();
    void clearText();

    void displaymdl();
    void displaytest();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
