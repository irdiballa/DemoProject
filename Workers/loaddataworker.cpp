#include "loaddataworker.h"

LoadDataWorker::LoadDataWorker(QString name, ModelLinearRegression *data, QObject *parent) :
    QObject(parent),
    filename(name)
{
    LRData = data;
}

void LoadDataWorker::process()
{

    emit progressUpdate(0);
    field<std::string> header;
    mat A;
    A.load( csv_name(filename.toStdString(), header) );

    LRData->setData(A);
    LRData->setFeatures(header);

    emit finished();
}

