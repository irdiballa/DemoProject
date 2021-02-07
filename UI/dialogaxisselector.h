#ifndef DIALOGAXISSELECTOR_H
#define DIALOGAXISSELECTOR_H

#include <QDialog>
#include "Models/modellinearregression.h"

namespace Ui {
class DialogAxisSelector;
}

class DialogAxisSelector : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAxisSelector(ModelLinearRegression *data,QWidget *parent = nullptr);
    ~DialogAxisSelector();

private slots:
    void on_comboBox_xaxis_currentIndexChanged(int index);

    void on_comboBox_yaxis_currentIndexChanged(int index);

private:
    Ui::DialogAxisSelector *ui;
    ModelLinearRegression *Data;
};

#endif // DIALOGAXISSELECTOR_H
