#include "CalendarMonth.h"

#include <QDebug>

CalendarMonth::CalendarMonth()
    : m_dateInfo(QDate::currentDate())
    , m_isCurrentMonth(true)
{
    m_dateInfo.setDate(m_dateInfo.year(), m_dateInfo.month(), 1);
    _createWeekObjects();

    gotoNextMonth();
    gotoPreviousMonth();
}

void CalendarMonth::gotoNextMonth()
{
    m_dateInfo = m_dateInfo.addMonths(1);

    _createWeekObjects();
}

void CalendarMonth::gotoPreviousMonth()
{
    m_dateInfo = m_dateInfo.addMonths(-1);

    _createWeekObjects();
}

void CalendarMonth::_createWeekObjects()
{
}
