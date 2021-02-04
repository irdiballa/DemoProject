#ifndef LOADDATAWORKER_H
#define LOADDATAWORKER_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QFile>
#include <QByteArray>
#include <QStringList>
#include <iostream>

#include "Models/modellinearregression.h"

using namespace std;


class LoadDataWorker : public QObject
{
    Q_OBJECT
public:
    LoadDataWorker(QString name, ModelLinearRegression *data, QObject *parent = nullptr);

signals:
    void finished();
    void progressUpdate(int progress);

public slots:
    void    process();

private:
    QString filename;
    ModelLinearRegression *LRData;
};

#endif // LOADDATAWORKER_H
