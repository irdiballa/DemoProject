#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFileDialog>
#include <QThread>
#include <QMessageBox>
#include <QVector>

#include "UI/widgetalgorithm.h"
#include "UI/widgetchart.h"
#include "UI/widgettable.h"
#include "Models/modellinearregression.h"
#include "Workers/loaddataworker.h"
#include "UI/widgettable.h"


#include <iostream>
#include <armadillo>


using namespace std;
using namespace arma;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loadData();
    void on_visualize();
    void on_editParameters();
    void on_trainModel();
    void on_saveModel();
    void on_loadModel();
    void on_predict();
    void on_abort();

private:
    Ui::MainWindow *ui;
    WidgetAlgorithm *LinearRegressionWidget;
    ModelLinearRegression *LinearRegressionData;
    widgetChart *ChartWidget;
    WidgetTable *TableWidget;


};
#endif // MAINWINDOW_H
