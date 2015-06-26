#ifndef UICONTROLLER_H
#define UICONTROLLER_H

#include "Singleton.h"
#include "CalendarMainWindow.h"
#include "DataController.h"
#include "CalendarView.h"

#include <QScopedPointer>

class UiController : public QObject, public Singleton<UiController>
{
    Q_OBJECT
public:
    UiController();
    ~UiController() { }

    void setDataController(DataController *dataController);

public slots:
    void onDataChanged(CalendarMonth *model);

private:
    void _setupMonthSpinBox(QString&& data);
    void _setupTable(CalendarMonth *model);

    DataController *m_dataController;

    QScopedPointer<CalendarMainWindow> m_calendarWindow;
    QScopedPointer<CalendarView> m_calendarWidget;
};

#endif // UICONTROLLER_H
