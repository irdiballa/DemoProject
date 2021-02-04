#include "widgetchart.h"
#include "ui_widgetchart.h"

widgetChart::widgetChart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widgetChart)
{
    ui->setupUi(this);

    createChart();

    QColor color = Qt::red;

    ui->toolButton_color->setStyleSheet("QToolButton{background-color:"+color.name() + ";}");
    scatterSeries->setColor(color);
    scatterSeries->setMarkerSize(ui->doubleSpinBox_pointSize->value());
}

widgetChart::~widgetChart()
{
    delete ui;
}

void widgetChart::createChart(){
    chart = new QChart();
    chart->setTheme(QChart::ChartThemeBlueCerulean);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->frame_chart->layout()->addWidget(chartView);

    axisX = new QValueAxis();
    axisX->setRange(ui->doubleSpinBox_minX->value(),ui->doubleSpinBox_maxX->value());
    axisX->setTickCount(11);

    axisY = new QValueAxis();
    axisY->setRange(ui->doubleSpinBox_minY->value(),ui->doubleSpinBox_maxY->value());
    axisY->setTickCount(11);

    chart->addAxis(axisX,Qt::AlignBottom);
    chart->addAxis(axisY,Qt::AlignLeft);

    scatterSeries =  new QScatterSeries();
    //scatterSeries->setUseOpenGL(true);

    chart->addSeries(scatterSeries);
    scatterSeries->attachAxis(axisX);
    scatterSeries->attachAxis(axisY);


}

void widgetChart::on_doubleSpinBox_minX_editingFinished()
{
    if(ui->doubleSpinBox_minX->value() >= ui->doubleSpinBox_maxX->value()){
        ui->doubleSpinBox_maxX->setValue(ui->doubleSpinBox_minX->value() + 0.01);
        axisX->setRange(ui->doubleSpinBox_minX->value(),ui->doubleSpinBox_maxX->value());
    }else{
        axisX->setRange(ui->doubleSpinBox_minX->value(),ui->doubleSpinBox_maxX->value());
    }
}

void widgetChart::on_doubleSpinBox_maxX_editingFinished()
{
    if(ui->doubleSpinBox_minX->value() >= ui->doubleSpinBox_maxX->value()){
        ui->doubleSpinBox_minX->setValue(ui->doubleSpinBox_maxX->value() - 0.01);
        axisX->setRange(ui->doubleSpinBox_minX->value(),ui->doubleSpinBox_maxX->value());
    }else{
       axisX->setRange(ui->doubleSpinBox_minX->value(),ui->doubleSpinBox_maxX->value());
    }
}

void widgetChart::on_doubleSpinBox_minY_editingFinished()
{
    if(ui->doubleSpinBox_minY->value() >= ui->doubleSpinBox_maxY->value()){
        ui->doubleSpinBox_maxY->setValue(ui->doubleSpinBox_minY->value() + 0.01);
        axisY->setRange(ui->doubleSpinBox_minY->value(),ui->doubleSpinBox_maxY->value());
    }else{
        axisY->setRange(ui->doubleSpinBox_minY->value(),ui->doubleSpinBox_maxY->value());
    }
}

void widgetChart::on_doubleSpinBox_maxY_editingFinished()
{
    if(ui->doubleSpinBox_minY->value() >= ui->doubleSpinBox_maxY->value()){
        ui->doubleSpinBox_minY->setValue(ui->doubleSpinBox_maxY->value() - 0.01);
        axisY->setRange(ui->doubleSpinBox_minY->value(),ui->doubleSpinBox_maxY->value());
    }else{
       axisY->setRange(ui->doubleSpinBox_minY->value(),ui->doubleSpinBox_maxY->value());
    }
}

void widgetChart::addData(std::string xName, std::string yName, QVector<double> xData, QVector<double> yData){
    int size = 0;

    if(xData.count() <= yData.count()){
        size = xData.count();
    }else{
        size = yData.count();
    }

    QVector<QPointF> points;
    for(int i=0;i<size;i++){
        points.append(QPointF(xData[i],yData[i]));
    }
    scatterSeries->replace(points);

    axisX->setTitleText(QString::fromStdString(xName));
    axisY->setTitleText(QString::fromStdString(yName));

    QPolygonF pol = QPolygonF(points);
    ui->doubleSpinBox_minX->setValue(pol.boundingRect().left());
    ui->doubleSpinBox_maxX->setValue(pol.boundingRect().right());
    ui->doubleSpinBox_minY->setValue(pol.boundingRect().top());
    ui->doubleSpinBox_maxY->setValue(pol.boundingRect().bottom());

    axisX->setRange(ui->doubleSpinBox_minX->value(),ui->doubleSpinBox_maxX->value());
    axisY->setRange(ui->doubleSpinBox_minY->value(),ui->doubleSpinBox_maxY->value());
}



void widgetChart::on_toolButton_color_clicked()
{

    const QColor color = QColorDialog::getColor(Qt::red, this, "Select Color");

    if (color.isValid()) {
        ui->toolButton_color->setStyleSheet("QToolButton{background-color:"+color.name() + ";}");
        scatterSeries->setColor(color);
    }

}

void widgetChart::on_doubleSpinBox_pointSize_valueChanged(double arg1)
{
    scatterSeries->setMarkerSize(arg1);
}
