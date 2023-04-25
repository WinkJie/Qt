#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QChart>
#include <QtCharts/qchartview.h>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QPushButton>
#include <QHBoxLayout>


using namespace QtCharts;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();


    void setlay();
    //折线图
    void createChartLine();
    //柱形图
    void createChartColumn();
    //扇形图
    void createChartFan();

protected:
    void paintEvent(QPaintEvent *event);

private:
    QPushButton *btnLine;
    QPushButton *btnColumn;
    QPushButton *btnFan;
     QChartView *chartView;
};

#endif // MAINWINDOW_H
