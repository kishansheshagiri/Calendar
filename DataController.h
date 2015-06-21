#ifndef DATACONTROLLER_H
#define DATACONTROLLER_H

#include "Singleton.h"

#include <QObject>

class DataController : public QObject, public Singleton<DataController>
{
    Q_OBJECT
signals:
    void dataReady();
public:
    DataController();

    void Start();
};

#endif // DATACONTROLLER_H
