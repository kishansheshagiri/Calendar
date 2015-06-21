#ifndef CALENDARMONTH_H
#define CALENDARMONTH_H

#include "CalendarWeek.h"

#include <QDate>

class CalendarMonth
{
public:
    CalendarMonth();
    CalendarMonth(int month, int year);

    void gotoNextMonth();
    void gotoPreviousMonth();
private:
    void _createWeekObjects();

    QDate m_dateInfo;
    bool m_isCurrentMonth;
    std::vector<CalendarWeek *> m_weekList;
};

#endif // CALENDARMONTH_H
