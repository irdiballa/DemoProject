#include "widgetalgorithm.h"
#include "ui_widgetalgorithm.h"

WidgetAlgorithm::WidgetAlgorithm(QString name,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetAlgorithm)
{
    ui->setupUi(this);
    ui->label_name->setText(name);
}

WidgetAlgorithm::~WidgetAlgorithm()
{
    delete ui;
}


void WidgetAlgorithm::on_toolButton_loadData_clicked()
{
    emit loadData();
}

void WidgetAlgorithm::on_toolButton_visual_clicked()
{
    emit visualize();
}

void WidgetAlgorithm::on_toolButton_editParams_clicked()
{
    emit editParameters();
}

void WidgetAlgorithm::on_toolButton_trainModel_clicked()
{
    emit trainModel();
}

void WidgetAlgorithm::on_toolButton_saveModel_clicked()
{
    emit saveModel();
}

void WidgetAlgorithm::on_toolButton_loadModel_clicked()
{
    emit loadModel();
}

void WidgetAlgorithm::on_toolButton_Predict_clicked()
{
    emit predict();
}

void WidgetAlgorithm::on_toolButton_abort_clicked()
{
    emit abort();
}

void WidgetAlgorithm::setBusyLoadProgress(bool status){

    if(status){
        ui->progressBar_progress->setMinimum(0);
        ui->progressBar_progress->setMaximum(0);
         ui->progressBar_progress->setValue(0);
    }
    else{
        ui->progressBar_progress->setMinimum(100);
        ui->progressBar_progress->setMaximum(100);
         ui->progressBar_progress->setValue(0);
    }
}

void WidgetAlgorithm::on_progressUpdated(int progress){
    ui->progressBar_progress->setValue(progress);
}

void WidgetAlgorithm::on_finished(){

    ui->progressBar_progress->setMaximum(100);
    ui->progressBar_progress->setValue(100);
}


