#ifndef DIALOGFILESELECTOR_H
#define DIALOGFILESELECTOR_H

#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include "Models/modellinearregression.h"

namespace Ui {
class DialogFileSelector;
}

class DialogFileSelector : public QDialog
{
    Q_OBJECT

public:
    explicit DialogFileSelector(ModelLinearRegression *data, QWidget *parent = nullptr);
    ~DialogFileSelector();

private slots:
    void on_radioButton_basketball_toggled(bool checked);

    void on_radioButton_crickets_toggled(bool checked);

    void on_radioButton_custom_toggled(bool checked);

    void on_radioButton_realestate_toggled(bool checked);

private:
    Ui::DialogFileSelector *ui;
    ModelLinearRegression *Data;
    QString basketball ="Examples/basketball.csv";
    QString crickets ="Examples/crickets.csv";
    QString realestate ="Examples/RealEstate.csv";

};

#endif // DIALOGFILESELECTOR_H
