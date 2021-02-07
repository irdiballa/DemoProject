#include "dialogaxisselector.h"
#include "ui_dialogaxisselector.h"

DialogAxisSelector::DialogAxisSelector(ModelLinearRegression *data, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAxisSelector)
{
    ui->setupUi(this);
    Data = data;


    QStringList features;
    for(uword i=0;i<Data->getFeatures().size();i++){
        features.append(QString::fromStdString(Data->getFeatures().at(i)));
    }
    ui->comboBox_xaxis->addItems(features);
    ui->comboBox_yaxis->addItems(features);

}

DialogAxisSelector::~DialogAxisSelector()
{
    delete ui;
}

void DialogAxisSelector::on_comboBox_xaxis_currentIndexChanged(int index)
{
    Data->setXAxisIndex(index);
}

void DialogAxisSelector::on_comboBox_yaxis_currentIndexChanged(int index)
{
    Data->setYAxisIndex(index);
}
