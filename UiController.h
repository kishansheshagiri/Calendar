#ifndef UICONTROLLER_H
#define UICONTROLLER_H

#include "Singleton.h"
#include "CalendarMainWindow.h"
#include "DataController.h"

#include <QPointer>

class UiController : public QObject, public Singleton<UiController>
{
    Q_OBJECT
public slots:
    void onDataReady();

public:
    UiController();
    ~UiController();

    void setDataController(DataController *dataController);

private:
    QPointer<CalendarMainWindow> m_calendar;
    DataController *m_dataController;
};

#endif // UICONTROLLER_H
