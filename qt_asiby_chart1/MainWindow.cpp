#include "MainWindow.h"

//my imports
//#include <QtCharts>

#include <QChartView>
#include <QLineSeries>
#include <QtMath>
#include <QValueAxis>

QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	//创建了图表
	QChartView * chartView = new QChartView(this);
	QChart * chart = new QChart();
	chart->setTitle("a simple function curve");

	chartView->setChart(chart);
	setCentralWidget(chartView);

	//create a spline series
	QLineSeries *series0 = new QLineSeries;
	QLineSeries *series1 = new QLineSeries;
	series0->setName("sin curve");
	series1->setName("cos curve");
	chart->addSeries(series0);
	chart->addSeries(series1);

	//add datas to the series
	qreal y0, y1, t = 0, intv = 0.1;
	int cnt = 100;
	for (int i = 0; i < cnt; i++)
	{
		y0 = qSin(t);
		series0->append(t, y0);
		y1 = qCos(t);
		series1->append(t, y1);
		t += intv;
	}

	//create axis X
	QValueAxis *axisX = new QValueAxis;
	axisX->setRange(0, 10);
	chart->setAxisX(axisX, series0);
	chart->setAxisX(axisX, series1);

	//create axis Y
	QValueAxis *axisY = new QValueAxis;
	axisY->setRange(-1, 1);
	chart->setAxisY(axisY, series0);
	chart->setAxisY(axisY, series1);

}
