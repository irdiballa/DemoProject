#ifndef WIDGETCHART_H
#define WIDGETCHART_H

#include <QWidget>
#include <QtCharts/QtCharts>

namespace Ui {
class widgetChart;
}

class widgetChart : public QWidget
{
    Q_OBJECT

public:
    explicit widgetChart(QWidget *parent = nullptr);
    ~widgetChart();

    void addData(std::string xName, std::string yName, QVector<double> xData, QVector<double> yData);


private slots:

    void on_doubleSpinBox_minX_editingFinished();

    void on_doubleSpinBox_maxX_editingFinished();

    void on_doubleSpinBox_minY_editingFinished();

    void on_doubleSpinBox_maxY_editingFinished();

    void on_toolButton_color_clicked();

    void on_doubleSpinBox_pointSize_valueChanged(double arg1);

private:
    Ui::widgetChart *ui;
    QChart *chart;
    QScatterSeries *scatterSeries;
    QValueAxis *axisX, *axisY;

    void createChart();
};

#endif // WIDGETCHART_H
