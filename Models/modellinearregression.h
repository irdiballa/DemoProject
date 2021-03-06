#ifndef MODELLINEARREGRESSION_H
#define MODELLINEARREGRESSION_H

#include <QObject>
#include <armadillo>

using namespace arma;

class ModelLinearRegression : public QObject
{
    Q_OBJECT
public:
    explicit ModelLinearRegression(QObject *parent = nullptr);

    field<std::string> getFeatures() const;
    void setFeatures(const field<std::string> &value);

    mat getData() const;
    void setData(const mat &value);


    int getSampleCount() const;
    int getFeatureCount() const;

    int getPredictColumn() const;
    void setPredictColumn(int value);

    vec getPredictedValues() const;
    void setPredictedValues(const vec &value);

    mat getModel() const;
    void setModel(const mat &value);


    uword getXAxisIndex() const;
    void setXAxisIndex(uword value);

    uword getYAxisIndex() const;
    void setYAxisIndex(uword value);

    QString getDataFile() const;
    void setDataFile(const QString &value);

private:
    field<std::string> features;
    mat data;
    vec predictedValues;
    int sampleCount;
    int featureCount;
    int predictColumn;
    mat model;
    uword xAxisIndex;
    uword yAxisIndex;
    QString dataFile;

};

#endif // MODELLINEARREGRESSION_H
