#ifndef WIDGETALGORITHM_H
#define WIDGETALGORITHM_H

#include <QWidget>

namespace Ui {
class WidgetAlgorithm;
}

class WidgetAlgorithm : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetAlgorithm(QString name, QWidget *parent = nullptr);
    ~WidgetAlgorithm();
    void setBusyLoadProgress(bool status = true);

signals:
    void loadData();
    void visualize();
    void editParameters();
    void trainModel();
    void saveModel();
    void loadModel();
    void predict();
    void abort();

public slots:
    void on_progressUpdated(int progress);
    void on_finished();

private slots:

    void on_toolButton_loadData_clicked();
    void on_toolButton_visual_clicked();
    void on_toolButton_editParams_clicked();
    void on_toolButton_trainModel_clicked();
    void on_toolButton_saveModel_clicked();
    void on_toolButton_loadModel_clicked();
    void on_toolButton_Predict_clicked();
    void on_toolButton_abort_clicked();

private:
    Ui::WidgetAlgorithm *ui;




};

#endif // WIDGETALGORITHM_H
