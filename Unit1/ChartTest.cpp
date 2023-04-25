#include "ChartTest.h"
#include <QChartView>

ChartTest::ChartTest(QWidget *parent)
    : QWidget(parent)
{
    m_chart = new QChart;
    graphicsView = new QChartView(this);
    QHBoxLayout *tail = new QHBoxLayout();
    QPushButton *btn0 = new QPushButton(tr("第一"));
    QPushButton *btn1 = new QPushButton(tr("12"));
    QPushButton *btn2 = new QPushButton(tr("22"));
    QPushButton *btn3 = new QPushButton(tr("32"));
    QPushButton *btn4 = new QPushButton(tr("42"));
    QPushButton *btn5 = new QPushButton(tr("52"));
    tail->addStretch(2);
    tail->addWidget(btn0);
    tail->addWidget(btn1);
    tail->addWidget(btn2);
    tail->addWidget(btn3);
    tail->addWidget(btn4);
    tail->addWidget(btn5);
    tail->addStretch(2);
    QVBoxLayout *la = new QVBoxLayout(this);
    la->addLayout(tail,1);
    la->addWidget(graphicsView,11);

    LineSeriesChart();
//    SplineSeriesChart();
//    ScatterSeriesChart();
//    PieSeriesChart();
//    BoxPlotSeriesChart();
//    AreaSeriesChart();
//    PercentBarSeriesChart();
//    StackedBarSeriesChart();
//    HorizontalStackedBarSeriesChart();
//    HorizontalPercentBarSeriesChart();
//    BarSeriesChart();
//    HorizontalBarSeries();

    setLayout(la);
    resize(800,600);
}

void ChartTest::LineSeriesChart()
{
    m_lineSeries = new QLineSeries;

    m_lineSeries->setPen(QPen(Qt::blue, 1, Qt::SolidLine));//设置曲线显示效果
    m_lineSeries->append(2, 6); //这里是添加数据的两种方式
    m_lineSeries->append(2, 4);
    m_lineSeries->append(3, 8);
    m_lineSeries->append(6, 4);
    m_lineSeries->append(8, 6);
    m_lineSeries->append(10, 5);
    m_lineSeries->setName(QStringLiteral("折线图"));
    m_chart->addSeries(m_lineSeries);
    m_chart->createDefaultAxes();

    // X坐标
    m_axisX = new QValueAxis;
    m_axisX->setRange(0, 60);           // X坐标范围
    m_axisX->setGridLineVisible(true);  // 网格线可见
    m_axisX->setTickCount(11);          // 设置大格数
    m_axisX->setMinorTickCount(5);      // 设置小格数
    m_axisX->setTitleText("X");         // 设置描述
    // Y坐标
    m_axisY = new QValueAxis;
    m_axisY->setRange(-5, 10);          // Y坐标范围
    m_axisY->setGridLineVisible(true);  // 网格线可见
    m_axisY->setTickCount(6);           // 设置大格数
    m_axisY->setMinorTickCount(2);      // 设置小格数
    m_axisY->setTitleText("Y");         // 设置描述

    m_chart->setAxisX(m_axisX);
    m_chart->setAxisY(m_axisY);

    graphicsView->setChart(m_chart);
    graphicsView->setRenderHint(QPainter::Antialiasing); // 反走样
}

void ChartTest::SplineSeriesChart()
{
    m_splineSeries = new QSplineSeries;

    m_splineSeries->setPen(QPen(Qt::blue, 1, Qt::SolidLine));//设置曲线显示效果
    m_splineSeries->append(0, 6); //这里是添加数据的两种方式
    m_splineSeries->append(2, 4);
    m_splineSeries->append(3, 8);
    m_splineSeries->append(6, 4);
    m_splineSeries->append(8, 6);
    m_splineSeries->append(10, 5);
    m_splineSeries->setName(QStringLiteral("曲线图"));
    m_chart->addSeries(m_splineSeries);
    m_chart->createDefaultAxes();

    // X坐标
    m_axisX = new QValueAxis;
    m_axisX->setRange(0, 60);           // X坐标范围
    m_axisX->setGridLineVisible(true);  // 网格线可见
    m_axisX->setTickCount(11);          // 设置大格数
    m_axisX->setMinorTickCount(5);      // 设置小格数
    m_axisX->setTitleText("X");         // 设置描述
    // Y坐标
    m_axisY = new QValueAxis;
    m_axisY->setRange(-5, 10);          // Y坐标范围
    m_axisY->setGridLineVisible(true);  // 网格线可见
    m_axisY->setTickCount(6);           // 设置大格数
    m_axisY->setMinorTickCount(2);      // 设置小格数
    m_axisY->setTitleText("Y");         // 设置描述

    m_chart->setAxisX(m_axisX);
    m_chart->setAxisY(m_axisY);

    graphicsView->setChart(m_chart);
    graphicsView->setRenderHint(QPainter::Antialiasing); // 反走样
}

void ChartTest::ScatterSeriesChart()
{
    m_scatterSeries = new QScatterSeries;

    m_scatterSeries->setPen(QPen(Qt::blue, 1, Qt::SolidLine));//设置曲线显示效果
    m_scatterSeries->append(2, 6); //这里是添加数据的两种方式
    m_scatterSeries->append(2, 4);
    m_scatterSeries->append(3, 6);
    m_scatterSeries->append(6, 4);
    m_scatterSeries->append(8, 6);
    m_scatterSeries->append(8, 5);
    m_scatterSeries->setName(QStringLiteral("散点图"));
    m_chart->addSeries(m_scatterSeries);
    m_chart->createDefaultAxes();

    // X坐标
    m_axisX = new QValueAxis;
    m_axisX->setRange(0, 10);           // X坐标范围
    m_axisX->setGridLineVisible(true);  // 网格线可见
    m_axisX->setTickCount(10);          // 设置大格数
    m_axisX->setMinorTickCount(0);      // 设置小格数
    m_axisX->setTitleText("X");         // 设置描述
    // Y坐标
    m_axisY = new QValueAxis;
    m_axisY->setRange(0, 10);          // Y坐标范围
    m_axisY->setGridLineVisible(true);  // 网格线可见
    m_axisY->setTickCount(10);           // 设置大格数
    m_axisY->setMinorTickCount(0);      // 设置小格数
    m_axisY->setTitleText("Y");         // 设置描述

    m_chart->setAxisX(m_axisX);
    m_chart->setAxisY(m_axisY);

    graphicsView->setChart(m_chart);
    graphicsView->setRenderHint(QPainter::Antialiasing); // 反走样
}

void ChartTest::PieSeriesChart()
{
    m_pieSeries = new QPieSeries();
    m_pieSeries->append("10%", 1);
    m_pieSeries->append("20%", 2);
    m_pieSeries->append("70%", 7);
    m_pieSeries->setLabelsVisible();

    m_pieSeries->slices().at(0)->setColor(QColor(255, 0, 0, 255));
    m_pieSeries->slices().at(1)->setColor(QColor(0, 255, 0, 255));
    m_pieSeries->slices().at(2)->setColor(QColor(0, 0, 255, 255));

    m_chart->addSeries(m_pieSeries);
    graphicsView->setChart(m_chart);
    graphicsView->setRenderHint(QPainter::Antialiasing); // 反走样
}

void ChartTest::BoxPlotSeriesChart()
{
    m_boxPlotSeries = new QBoxPlotSeries;
    m_boxPlotSeries->setName(QStringLiteral("盒状图"));
    for (int i = 0; i < 10; i++)
    {
        QString label = QString::number(i);
        int value = qrand() % 100;
        QBoxSet* boxSet = new QBoxSet(label);
        //需要设置这五个值
        boxSet->setValue(QBoxSet::LowerExtreme, value * 0.2);
        boxSet->setValue(QBoxSet::UpperExtreme, value);
        boxSet->setValue(QBoxSet::Median, value * 0.5);
        boxSet->setValue(QBoxSet::LowerQuartile, value * 0.25);
        boxSet->setValue(QBoxSet::UpperQuartile, value * 0.75);
        m_boxPlotSeries->append(boxSet);
    }

    m_chart->addSeries(m_boxPlotSeries);
    m_chart->createDefaultAxes();

    // X坐标
    m_axisX = new QValueAxis;
    m_axisX->setRange(0, 60);           // X坐标范围
    m_axisX->setGridLineVisible(true);  // 网格线可见
    m_axisX->setTickCount(11);          // 设置大格数
    m_axisX->setMinorTickCount(5);      // 设置小格数
    m_axisX->setTitleText("X");         // 设置描述
    // Y坐标
    m_axisY = new QValueAxis;
    m_axisY->setRange(-5, 10);          // Y坐标范围
    m_axisY->setGridLineVisible(true);  // 网格线可见
    m_axisY->setTickCount(6);           // 设置大格数
    m_axisY->setMinorTickCount(2);      // 设置小格数
    m_axisY->setTitleText("Y");         // 设置描述

    m_chart->setAxisX(m_axisX);
    m_chart->setAxisY(m_axisY);

    graphicsView->setChart(m_chart);
    graphicsView->setRenderHint(QPainter::Antialiasing); // 反走样
}

void ChartTest::AreaSeriesChart()
{
    //创建折线序列
    QLineSeries* up = new QLineSeries;
    QLineSeries* down = new QLineSeries;
    up->setName(QStringLiteral("上"));
    down->setName(QStringLiteral("下"));
    up->append(0, 0);
    up->append(5, 5);
    up->append(10, 10);
    up->append(15, 15);
    down->append(0, 0);
    down->append(5, 10);
    down->append(10, 20);
    down->append(15, 30);

    m_areaSeries = new QAreaSeries(up, down);
    m_areaSeries->setName(QStringLiteral("面积图"));
    m_chart->addSeries(m_areaSeries);
    m_chart->createDefaultAxes();

    // X坐标
    m_axisX = new QValueAxis;
    m_axisX->setRange(0, 60);           // X坐标范围
    m_axisX->setGridLineVisible(true);  // 网格线可见
    m_axisX->setTickCount(11);          // 设置大格数
    m_axisX->setMinorTickCount(5);      // 设置小格数
    m_axisX->setTitleText("X");         // 设置描述
    // Y坐标
    m_axisY = new QValueAxis;
    m_axisY->setRange(0, 10);          // Y坐标范围
    m_axisY->setGridLineVisible(true);  // 网格线可见
    m_axisY->setTickCount(6);           // 设置大格数
    m_axisY->setMinorTickCount(2);      // 设置小格数
    m_axisY->setTitleText("Y");         // 设置描述

    m_chart->setAxisX(m_axisX);
    m_chart->setAxisY(m_axisY);

    graphicsView->setChart(m_chart);
    graphicsView->setRenderHint(QPainter::Antialiasing); // 反走样
}

void ChartTest::PercentBarSeriesChart()
{
    m_percentBarSeries = new QPercentBarSeries();
    QBarSet* set1 = new QBarSet("rng");
    set1->append(10);
    set1->append(20);
    QBarSet* set2 = new QBarSet("ig");
    set2->append(5);
    m_percentBarSeries->append(set1);
    m_percentBarSeries->append(set2);

    m_percentBarSeries->setLabelsVisible();
    m_chart->addSeries(m_percentBarSeries);
    m_percentBarSeries->setBarWidth(0.1);
    m_chart->createDefaultAxes();

    // X坐标
    m_axisX = new QValueAxis;
    m_axisX->setRange(0, 10);           // X坐标范围
    m_axisX->setGridLineVisible(true);  // 网格线可见
    m_axisX->setTickCount(10);          // 设置大格数
    m_axisX->setMinorTickCount(5);      // 设置小格数
    m_axisX->setTitleText("X");         // 设置描述
    // Y坐标
    m_axisY = new QValueAxis;
    m_axisY->setRange(0, 10);          // Y坐标范围
    m_axisY->setGridLineVisible(true);  // 网格线可见
    m_axisY->setTickCount(6);           // 设置大格数
    m_axisY->setMinorTickCount(2);      // 设置小格数
    m_axisY->setTitleText("Y");         // 设置描述

    m_chart->setAxisX(m_axisX);
    m_chart->setAxisY(m_axisY);

    graphicsView->setChart(m_chart);
    graphicsView->setRenderHint(QPainter::Antialiasing); // 反走样
}

void ChartTest::StackedBarSeriesChart()
{
    m_stackedBarSeries = new QStackedBarSeries();
    QBarSet* set1 = new QBarSet("rng");
    set1->append(10);
    set1->append(20);
    QBarSet* set2 = new QBarSet("ig");
    set2->append(5);
    m_stackedBarSeries->append(set1);
    m_stackedBarSeries->append(set2);

    m_stackedBarSeries->setLabelsVisible();
    m_chart->addSeries(m_stackedBarSeries);
    m_stackedBarSeries->setBarWidth(0.1);
    m_chart->createDefaultAxes();

    // X坐标
    m_axisX = new QValueAxis;
    m_axisX->setRange(0, 10);           // X坐标范围
    m_axisX->setGridLineVisible(true);  // 网格线可见
    m_axisX->setTickCount(10);          // 设置大格数
    m_axisX->setMinorTickCount(5);      // 设置小格数
    m_axisX->setTitleText("X");         // 设置描述
    // Y坐标
    m_axisY = new QValueAxis;
    m_axisY->setRange(0, 10);          // Y坐标范围
    m_axisY->setGridLineVisible(true);  // 网格线可见
    m_axisY->setTickCount(6);           // 设置大格数
    m_axisY->setMinorTickCount(2);      // 设置小格数
    m_axisY->setTitleText("Y");         // 设置描述

    m_chart->setAxisX(m_axisX);
    m_chart->setAxisY(m_axisY);

    graphicsView->setChart(m_chart);
    graphicsView->setRenderHint(QPainter::Antialiasing); // 反走样
}

void ChartTest::HorizontalStackedBarSeriesChart()
{
    m_horizontalStackedBarSeries = new QHorizontalStackedBarSeries();
    QBarSet* set1 = new QBarSet("rng");
    set1->append(10);
    set1->append(20);
    QBarSet* set2 = new QBarSet("ig");
    set2->append(5);
    m_horizontalStackedBarSeries->append(set1);
    m_horizontalStackedBarSeries->append(set2);

    m_horizontalStackedBarSeries->setLabelsVisible();
    m_chart->addSeries(m_horizontalStackedBarSeries);
    m_horizontalStackedBarSeries->setBarWidth(0.1);
    m_chart->createDefaultAxes();

    // X坐标
    m_axisX = new QValueAxis;
    m_axisX->setRange(0, 10);           // X坐标范围
    m_axisX->setGridLineVisible(true);  // 网格线可见
    m_axisX->setTickCount(10);          // 设置大格数
    m_axisX->setMinorTickCount(5);      // 设置小格数
    m_axisX->setTitleText("X");         // 设置描述
    // Y坐标
    m_axisY = new QValueAxis;
    m_axisY->setRange(0, 10);          // Y坐标范围
    m_axisY->setGridLineVisible(true);  // 网格线可见
    m_axisY->setTickCount(6);           // 设置大格数
    m_axisY->setMinorTickCount(2);      // 设置小格数
    m_axisY->setTitleText("Y");         // 设置描述

    m_chart->setAxisX(m_axisX);
    m_chart->setAxisY(m_axisY);

    graphicsView->setChart(m_chart);
    graphicsView->setRenderHint(QPainter::Antialiasing); // 反走样
}

void ChartTest::HorizontalPercentBarSeriesChart()
{
    m_horizontalPercentBarSeries = new QHorizontalPercentBarSeries();
    QBarSet* set1 = new QBarSet("rng");
    set1->append(10);
    set1->append(20);
    QBarSet* set2 = new QBarSet("ig");
    set2->append(5);
    m_horizontalPercentBarSeries->append(set1);
    m_horizontalPercentBarSeries->append(set2);

    m_horizontalPercentBarSeries->setLabelsVisible();
    m_chart->addSeries(m_horizontalPercentBarSeries);
    m_horizontalPercentBarSeries->setBarWidth(0.1);
    m_chart->createDefaultAxes();

    // X坐标
    m_axisX = new QValueAxis;
    m_axisX->setRange(0, 10);           // X坐标范围
    m_axisX->setGridLineVisible(true);  // 网格线可见
    m_axisX->setTickCount(10);          // 设置大格数
    m_axisX->setMinorTickCount(5);      // 设置小格数
    m_axisX->setTitleText("X");         // 设置描述
    // Y坐标
    m_axisY = new QValueAxis;
    m_axisY->setRange(0, 10);          // Y坐标范围
    m_axisY->setGridLineVisible(true);  // 网格线可见
    m_axisY->setTickCount(6);           // 设置大格数
    m_axisY->setMinorTickCount(2);      // 设置小格数
    m_axisY->setTitleText("Y");         // 设置描述

    m_chart->setAxisX(m_axisX);
    m_chart->setAxisY(m_axisY);

    graphicsView->setChart(m_chart);
    graphicsView->setRenderHint(QPainter::Antialiasing); // 反走样
}

void ChartTest::BarSeriesChart()
{
    m_barSeries = new QBarSeries();
    QBarSet* set1 = new QBarSet("rng");
    set1->append(10);
    set1->append(20);
    QBarSet* set2 = new QBarSet("ig");
    set2->append(5);
    m_barSeries->append(set1);
    m_barSeries->append(set2);

    m_barSeries->setLabelsVisible();
    m_chart->addSeries(m_barSeries);
    m_barSeries->setBarWidth(0.1);
    m_chart->createDefaultAxes();

    // X坐标
    m_axisX = new QValueAxis;
    m_axisX->setRange(0, 10);           // X坐标范围
    m_axisX->setGridLineVisible(true);  // 网格线可见
    m_axisX->setTickCount(10);          // 设置大格数
    m_axisX->setMinorTickCount(5);      // 设置小格数
    m_axisX->setTitleText("X");         // 设置描述
    // Y坐标
    m_axisY = new QValueAxis;
    m_axisY->setRange(0, 10);          // Y坐标范围
    m_axisY->setGridLineVisible(true);  // 网格线可见
    m_axisY->setTickCount(6);           // 设置大格数
    m_axisY->setMinorTickCount(2);      // 设置小格数
    m_axisY->setTitleText("Y");         // 设置描述

    m_chart->setAxisX(m_axisX);
    m_chart->setAxisY(m_axisY);

    graphicsView->setChart(m_chart);
    graphicsView->setRenderHint(QPainter::Antialiasing); // 反走样
}

void ChartTest::HorizontalBarSeries()
{
    m_horizontalBarSeries = new QHorizontalBarSeries();
    QBarSet* set1 = new QBarSet("rng");
    set1->append(10);
    set1->append(20);
    QBarSet* set2 = new QBarSet("ig");
    set2->append(5);
    m_horizontalBarSeries->append(set1);
    m_horizontalBarSeries->append(set2);

    m_horizontalBarSeries->setLabelsVisible();
    m_chart->addSeries(m_horizontalBarSeries);
    m_horizontalBarSeries->setBarWidth(0.1);
    m_chart->createDefaultAxes();

    // X坐标
    m_axisX = new QValueAxis;
    m_axisX->setRange(0, 10);           // X坐标范围
    m_axisX->setGridLineVisible(true);  // 网格线可见
    m_axisX->setTickCount(10);          // 设置大格数
    m_axisX->setMinorTickCount(5);      // 设置小格数
    m_axisX->setTitleText("X");         // 设置描述
    // Y坐标
    m_axisY = new QValueAxis;
    m_axisY->setRange(0, 10);          // Y坐标范围
    m_axisY->setGridLineVisible(true);  // 网格线可见
    m_axisY->setTickCount(6);           // 设置大格数
    m_axisY->setMinorTickCount(2);      // 设置小格数
    m_axisY->setTitleText("Y");         // 设置描述

    m_chart->setAxisX(m_axisX);
    m_chart->setAxisY(m_axisY);

    graphicsView->setChart(m_chart);
    graphicsView->setRenderHint(QPainter::Antialiasing); // 反走样
}
