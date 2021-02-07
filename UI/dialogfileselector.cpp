#include "dialogfileselector.h"
#include "ui_dialogfileselector.h"

DialogFileSelector::DialogFileSelector(ModelLinearRegression *data, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogFileSelector)
{
    ui->setupUi(this);
    Data = data;


    QFile cricketfile(crickets);
    if(!cricketfile.exists()){
        ui->radioButton_crickets->setEnabled(false);
        ui->radioButton_crickets->setCheckable(false);

    }else{
        Data->setDataFile(crickets);
    }

    QFile basketballfile(basketball);
    if(!basketballfile.exists()){
        ui->radioButton_basketball->setEnabled(false);
        ui->radioButton_basketball->setCheckable(false);
    }


    QFile realestatefile(realestate);
    if(!realestatefile.exists()){
        ui->radioButton_realestate->setEnabled(false);
        ui->radioButton_realestate->setCheckable(false);
    }



}

DialogFileSelector::~DialogFileSelector()
{
    delete ui;
}

void DialogFileSelector::on_radioButton_basketball_toggled(bool checked)
{
    if(checked){
        Data->setDataFile(basketball);
    }

}

void DialogFileSelector::on_radioButton_crickets_toggled(bool checked)
{
    if(checked){
        Data->setDataFile(crickets);
    }
}

void DialogFileSelector::on_radioButton_realestate_toggled(bool checked)
{
    if(checked){
        Data->setDataFile(realestate);
    }

}

void DialogFileSelector::on_radioButton_custom_toggled(bool checked)
{
    if(checked){
        QString fileName = "";
        fileName = QFileDialog::getOpenFileName(this,
            tr("Open File"), "/home", tr("CSV Files (*.csv)"));

        if(fileName == ""){
            QMessageBox msgBox;
            msgBox.setText("No file was selected.");
            msgBox.setInformativeText("Please Select a .csv file to load");
            msgBox.exec();
            Data->setDataFile(fileName);
            ui->lineEdit_filename->setText(fileName);
            return;
        }
        Data->setDataFile(fileName);
        ui->lineEdit_filename->setText(fileName);
    }

}

