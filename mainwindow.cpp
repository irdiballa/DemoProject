#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    LinearRegressionData = new ModelLinearRegression();

    LinearRegressionWidget = new WidgetAlgorithm("Linear Regression");
    ui->frame_algorithmContainer->layout()->addWidget(LinearRegressionWidget);

    connect(LinearRegressionWidget,&WidgetAlgorithm::loadData,this,&MainWindow::on_loadData);
    connect(LinearRegressionWidget,&WidgetAlgorithm::visualize,this,&MainWindow::on_visualize);
    connect(LinearRegressionWidget,&WidgetAlgorithm::editParameters,this,&MainWindow::on_editParameters);
    connect(LinearRegressionWidget,&WidgetAlgorithm::trainModel,this,&MainWindow::on_trainModel);
    connect(LinearRegressionWidget,&WidgetAlgorithm::saveModel,this,&MainWindow::on_saveModel);
    connect(LinearRegressionWidget,&WidgetAlgorithm::loadModel,this,&MainWindow::on_loadModel);
    connect(LinearRegressionWidget,&WidgetAlgorithm::predict,this,&MainWindow::on_predict);
    connect(LinearRegressionWidget,&WidgetAlgorithm::abort,this,&MainWindow::on_abort);

    ChartWidget = new widgetChart(this);
    ui->tab_chart->layout()->addWidget(ChartWidget);

    TableWidget = new WidgetTable(this);
    ui->tab_table->layout()->addWidget(TableWidget);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadData(){

    if(sender() == LinearRegressionWidget){

        QString fileName = "";
        fileName = QFileDialog::getOpenFileName(this,
            tr("Open File"), "/home", tr("CSV Files (*.csv)"));

        if(fileName == ""){
            QMessageBox msgBox;
            msgBox.setText("No file was selected.");
            msgBox.setInformativeText("Please Select a .csv file to load");
            msgBox.exec();
            return;
        }

        LinearRegressionWidget->setBusyLoadProgress();
        QThread *WorkThread  = new QThread();
        LoadDataWorker *massDemon   = new LoadDataWorker(fileName,LinearRegressionData);
        massDemon->moveToThread(WorkThread);

        connect(WorkThread, &QThread::started, massDemon, &LoadDataWorker::process);

        connect(massDemon, &LoadDataWorker::progressUpdate, LinearRegressionWidget, &WidgetAlgorithm::on_progressUpdated);
        connect(massDemon, &LoadDataWorker::finished, LinearRegressionWidget, &WidgetAlgorithm::on_finished);

        connect(massDemon, SIGNAL(finished()), WorkThread, SLOT(quit()));
        connect(massDemon, SIGNAL(finished()), massDemon,SLOT(deleteLater()));
        connect(WorkThread, SIGNAL(finished()), WorkThread, SLOT(deleteLater()));

        WorkThread->start();
    }else{

    }




}

void MainWindow::on_visualize(){
    if(sender() == LinearRegressionWidget){

        LinearRegressionWidget->setBusyLoadProgress(true);
        QStringList features;
        QVector<QVector<QVariant>> allData;

        for(uword i=0;i<LinearRegressionData->getFeatures().size();i++){
            features.append(QString::fromStdString(LinearRegressionData->getFeatures().at(i)));
        }

        int xaxis = 0,yaxis = 0;
        bool ok;
        QString item = QInputDialog::getItem(this,tr("Features") ,
                                             tr("Select feature for horizontal axis:"), features, 0, false, &ok);
        if (ok && !item.isEmpty()){
            xaxis = features.indexOf(item);
        }


        item = QInputDialog::getItem(this, tr("Features"),
                                             tr("Select feature for vertical axis:"), features, 0, false, &ok);
        if (ok && !item.isEmpty()){
            yaxis = features.indexOf(item);
        }


        std::vector<double> x = arma::conv_to< std::vector<double> >::from(LinearRegressionData->getData().col(xaxis));
        std::vector<double> y = arma::conv_to< std::vector<double> >::from(LinearRegressionData->getData().col(yaxis));

        QVector<double> xData=  QVector<double>(x.begin(),x.end());
        QVector<double> yData=  QVector<double>(y.begin(),y.end());

        ChartWidget->addData(LinearRegressionData->getFeatures()[xaxis],LinearRegressionData->getFeatures()[yaxis],xData,yData);
        TableWidget->addData(features,LinearRegressionData->getData());
        LinearRegressionWidget->setBusyLoadProgress(false);
    }else{

    }


}

void MainWindow::on_editParameters(){
    if(sender() == LinearRegressionWidget){

        QStringList features;

        for(uword i=0;i<LinearRegressionData->getFeatures().size();i++){
            features.append(QString::fromStdString(LinearRegressionData->getFeatures().at(i)));
        }

        int predictColumn = 0;
        bool ok;
        QString item = QInputDialog::getItem(this,tr("Features") ,
                                             tr("Select feature to predict:"), features, 0, false, &ok);
        if (ok && !item.isEmpty()){
            predictColumn = features.indexOf(item);
        }
        LinearRegressionData->setPredictColumn(predictColumn);

    }else{

    }
}

void MainWindow::on_trainModel(){
    if(sender() == LinearRegressionWidget){

        mat X = LinearRegressionData->getData();
        vec y = X.col(LinearRegressionData->getPredictColumn());
        X.shed_col(LinearRegressionData->getPredictColumn());
        vec ones = vec(LinearRegressionData->getSampleCount(),fill::ones);

        X.insert_cols(0,ones);
        vec model = pinv(X.t() * X) * (X.t() * y);
        LinearRegressionData->setModel(model);


    }else{

    }
}

void MainWindow::on_saveModel(){
    if(sender() == LinearRegressionWidget){
        QString fileName = "";
        fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                           "/home/model.csv",
                                           tr("CSV files (*.csv)"));

        if(fileName == ""){
            QMessageBox msgBox;
            msgBox.setText("No file was selected.");
            msgBox.setInformativeText("Please Select a .csv file to save");
            msgBox.exec();
            return;
        }
        LinearRegressionData->getModel().save(fileName.toStdString());

    }else{

    }
}

void MainWindow::on_loadModel(){
    if(sender() == LinearRegressionWidget){
        QString fileName = "";
        fileName = QFileDialog::getOpenFileName(this,
            tr("Open File"), "/home", tr("CSV Files (*.csv)"));

        if(fileName == ""){
            QMessageBox msgBox;
            msgBox.setText("No file was selected.");
            msgBox.setInformativeText("Please Select a .csv file to load");
            msgBox.exec();
            return;
        }

        mat model;
        model.load(fileName.toStdString());
        LinearRegressionData->setModel(model);

    }else{

    }
}

void MainWindow::on_predict(){
    if(sender() == LinearRegressionWidget){
        mat X = LinearRegressionData->getData();
        X.shed_col(LinearRegressionData->getPredictColumn());
        vec ones = vec(LinearRegressionData->getSampleCount(),fill::ones);
        X.insert_cols(0,ones);
        vec predictedValues = X * LinearRegressionData->getModel();

        LinearRegressionData->setPredictedValues(predictedValues);

        QString feature_name =QString::fromStdString(LinearRegressionData->getFeatures().at(LinearRegressionData->getPredictColumn()));
        TableWidget->addPredictedData("(P)" + feature_name,predictedValues,LinearRegressionData->getFeatureCount());


//        vec error = predictedValues - LinearRegressionData->getData().col(LinearRegressionData->getPredictColumn());
//        error = error % error;
//        int totalError = arma::sum(error);


    }else{

    }


}

void MainWindow::on_abort(){
    qDebug()<<"on_abort";
}
