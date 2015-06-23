#ifndef CALENDARMONTH_H
#define CALENDARMONTH_H

#include "CalendarWeek.h"

#include <memory>
#include <QDate>
#include <QList>

class CalendarMonth
{
public:
    CalendarMonth();
    virtual ~CalendarMonth();

    void gotoNextMonth();
    void gotoPreviousMonth();
private:
    void _createWeekObjects();
    void _clearWeekObjects();

    QDate m_dateInfo;
    bool m_isCurrentMonth;
    QList<CalendarWeek *> m_weekList;
};

#endif // CALENDARMONTH_H
