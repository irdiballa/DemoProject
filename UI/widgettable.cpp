#include "widgettable.h"
#include "ui_widgettable.h"

WidgetTable::WidgetTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetTable)
{
    ui->setupUi(this);
    createTable();
}

WidgetTable::~WidgetTable()
{
    delete ui;
}

void WidgetTable::createTable(){

    table = new QTableWidget(this);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->frame->layout()->addWidget(table);


    table->setStyleSheet("QTableWidgetItem{"
                         "color:rgb(255,255,255);"
                         "}");

}

void WidgetTable::addData(QStringList features,mat data){

    table->setRowCount(data.n_rows);
    table->setColumnCount(data.n_cols);

    table->setHorizontalHeaderLabels(features);


    for(uword i=0;i<data.n_cols;i++){
        for(uword j=0;j<data.n_rows;j++){

            table->setItem(j,i,new QTableWidgetItem(QString::number(data(j,i))));
            table->item(j,i)->setBackground(QBrush(Qt::white));

        }
    }

}

void WidgetTable::addPredictedData(QString name, vec data,int newColIndex){
    table->setColumnCount(newColIndex +1);

    table->setHorizontalHeaderItem(newColIndex,new QTableWidgetItem(name));

    for(uword i=0;i<data.size();i++){
        table->setItem(i,newColIndex,new QTableWidgetItem(QString::number(data.at(i))));
        table->item(i,newColIndex)->setBackground(QBrush(Qt::white));
    }

}


