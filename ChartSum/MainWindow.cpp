#include "MainWindow.h"
#include <complex>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(1100,800);




//    setlay();
}

MainWindow::~MainWindow()
{

}

void MainWindow::setlay()
{
    btnColumn = new QPushButton(tr("柱形图"));
    btnLine = new QPushButton(tr("折线图"));
    btnFan = new QPushButton(tr("扇形图"));
    QHBoxLayout *MenuLayout = new QHBoxLayout(this);
    MenuLayout->addStretch(5);
    MenuLayout->addWidget(btnFan);
    MenuLayout->addWidget(btnColumn);
    MenuLayout->addWidget(btnLine);
    MenuLayout->addStretch(5);
    QWidget *MenuWidget = new QWidget(this);
    MenuWidget->setLayout(MenuLayout);
    setMenuWidget(MenuWidget);
//    setCentralWidget(chartView);

//    connect(btnLine,&QPushButton::clicked,[=](){
//        setCentralWidget(chartView);
//    });
//    connect(btnColumn,&QPushButton::clicked,[=](){
//        setCentralWidget(chartView);
//    });
//    connect(btnFan,&QPushButton::clicked,[=](){
//        setCentralWidget(chartView);
//    });
}

void MainWindow::createChartLine()
{
    chartView = new QChartView(this);
    QChart *chart = new QChart();
    chart->setTitle(tr("简单函数曲线"));
    chartView->setChart(chart);

    //创建折线序列
    QLineSeries *series0 = new QLineSeries();
    QLineSeries *series1 = new QLineSeries();
    series0->setName(tr("sin曲线"));
    series1->setName(tr("cos曲线"));
    chart->addSeries(series0);
    chart->addSeries(series1);

    //序列添加数值
    qreal t = 0,y1,y2,intv = 0.1;
    int cnt = 100;
    for(int i=0;i<cnt;i++)
    {
        y1=sin(t);
        series0->append(t,y1);
        y2=sin(t+20);
        series1->append(t,y2);
        t+=intv;
    }

    //创建坐标轴
    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(0,12);
    axisX->setTitleText(tr("time(secs)"));

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(-2,2);
    axisY->setTitleText(tr("value"));

    chart->setAxisX(axisX,series0);
    chart->setAxisY(axisY,series0);
    chart->setAxisX(axisX,series1);
    chart->setAxisY(axisY,series1);

}

void MainWindow::createChartColumn()
{

}

void MainWindow::createChartFan()
{

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
}
