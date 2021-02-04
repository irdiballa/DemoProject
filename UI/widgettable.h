#ifndef WIDGETTABLE_H
#define WIDGETTABLE_H

#include <QWidget>
#include <QTableWidget>
#include <QDebug>
#include "Models/modellinearregression.h"
#include <armadillo>

using namespace std;
using namespace arma;

namespace Ui {
class WidgetTable;
}

class WidgetTable : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetTable(QWidget *parent = nullptr);
    ~WidgetTable();

    void addData(QStringList features, mat data);
    void addPredictedData(QString name, vec data,int col_to_add);

private:
    Ui::WidgetTable *ui;
    QTableWidget *table;


    void createTable();

};

#endif // WIDGETTABLE_H
