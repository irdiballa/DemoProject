#include "modellinearregression.h"

ModelLinearRegression::ModelLinearRegression(QObject *parent) : QObject(parent)
{

}

field<std::string> ModelLinearRegression::getFeatures() const
{
    return features;
}

void ModelLinearRegression::setFeatures(const field<std::string> &value)
{
    features = value;
}

mat ModelLinearRegression::getData() const
{
    return data;
}

void ModelLinearRegression::setData(const mat &value)
{
    data = value;
    sampleCount = arma::size(data).n_rows;
    featureCount = arma::size(data).n_cols;

    predictedValues = vec(sampleCount,fill::zeros);

}

int ModelLinearRegression::getSampleCount() const
{
    return sampleCount;
}

int ModelLinearRegression::getFeatureCount() const
{
    return featureCount;
}

int ModelLinearRegression::getPredictColumn() const
{
    return predictColumn;
}

void ModelLinearRegression::setPredictColumn(int value)
{
    predictColumn = value;
}

vec ModelLinearRegression::getPredictedValues() const
{
    return predictedValues;
}

mat ModelLinearRegression::getModel() const
{
    return model;
}

void ModelLinearRegression::setModel(const mat &value)
{
    model = value;


}

uword ModelLinearRegression::getXAxisIndex() const
{
    return xAxisIndex;
}

void ModelLinearRegression::setXAxisIndex(uword value)
{
    xAxisIndex = value;
}

uword ModelLinearRegression::getYAxisIndex() const
{
    return yAxisIndex;
}

void ModelLinearRegression::setYAxisIndex(uword value)
{
    yAxisIndex = value;
}

QString ModelLinearRegression::getDataFile() const
{
    return dataFile;
}

void ModelLinearRegression::setDataFile(const QString &value)
{
    dataFile = value;
}

void ModelLinearRegression::setPredictedValues(const vec &value)
{
    predictedValues = value;
}

