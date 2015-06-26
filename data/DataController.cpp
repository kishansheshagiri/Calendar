#include "DataController.h"

DataController::DataController()
    : m_calendarData(new CalendarMonth)
{
}

void DataController::start()
{
    QObject::connect(m_calendarData.data(), SIGNAL(monthChanged(CalendarMonth*)),
                     this, SIGNAL(dataChanged(CalendarMonth*)));

    QObject::connect(this, SIGNAL(monthNextClicked()),
                     m_calendarData.data(), SLOT(gotoNextMonth()));
    QObject::connect(this, SIGNAL(monthPreviousClicked()),
                     m_calendarData.data(), SLOT(gotoPreviousMonth()));

    m_calendarData.data()->initialize();
}
