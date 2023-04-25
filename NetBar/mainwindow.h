#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "header_h.h"
#include "myinfo.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public:
    QTableWidget *tablewid;
    QTabWidget *tabwid;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
