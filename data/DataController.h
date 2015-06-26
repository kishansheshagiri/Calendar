#ifndef DATACONTROLLER_H
#define DATACONTROLLER_H

#include "Singleton.h"
#include "CalendarMonth.h"

#include <QObject>
#include <QScopedPointer>

class DataController : public QObject, public Singleton<DataController>
{
    Q_OBJECT

public:
    DataController();

    void start();

Q_SIGNALS:
    void dataChanged(CalendarMonth *model);
    void monthNextClicked();
    void monthPreviousClicked();

private:
    QScopedPointer<CalendarMonth> m_calendarData;
};

#endif // DATACONTROLLER_H
