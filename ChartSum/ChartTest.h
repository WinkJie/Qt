#pragma once

#include <QtWidgets/QWidget>
#include <QtCharts>
#include <QLineSeries>
#include <QValueAxis>
#include <QSplineSeries>
#include <QScatterSeries>
#include <QPieSeries>
#include <QBoxPlotSeries>
#include <QAreaSeries>
#include <QPercentBarSeries>
#include <QStackedBarSeries>
#include <QHorizontalStackedBarSeries>
#include <QHorizontalPercentBarSeries>
#include <QBarSeries>
#include <QHorizontalBarSeries>

#include <QMainWindow>
#include <QtCharts/QChart>
#include <QtCharts/qchartview.h>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class ChartTest : public QWidget
{
    Q_OBJECT

public:
    ChartTest(QWidget *parent = Q_NULLPTR);

    void LineSeriesChart(); // 折线图
    void SplineSeriesChart();   // 曲线图
    void ScatterSeriesChart();  // 散点图
    void PieSeriesChart();      // 饼状图
    void BoxPlotSeriesChart();  // 盒状图
    void AreaSeriesChart();     // 面积图
    void PercentBarSeriesChart();// 百分比柱状图
    void StackedBarSeriesChart();// 堆叠图柱状图
    void HorizontalStackedBarSeriesChart();// 横向堆叠图柱状图
    void HorizontalPercentBarSeriesChart();// 横向百分比柱状图
    void BarSeriesChart();  // 柱状图
    void HorizontalBarSeries(); // 横向柱状图
private:
    QChart* m_chart;
    QLineSeries* m_lineSeries;
    QSplineSeries* m_splineSeries;
    QScatterSeries* m_scatterSeries;
    QPieSeries* m_pieSeries;
    QBoxPlotSeries* m_boxPlotSeries;
    QAreaSeries* m_areaSeries;
    QPercentBarSeries* m_percentBarSeries;
    QStackedBarSeries* m_stackedBarSeries;
    QHorizontalStackedBarSeries* m_horizontalStackedBarSeries;
    QHorizontalPercentBarSeries* m_horizontalPercentBarSeries;
    QBarSeries* m_barSeries;
    QHorizontalBarSeries* m_horizontalBarSeries;
    QChartView *graphicsView;

    QValueAxis* m_axisX;
    QValueAxis* m_axisY;
};
