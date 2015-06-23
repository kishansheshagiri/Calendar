#ifndef CALENDARWEEK_H
#define CALENDARWEEK_H

#include <QList>

class CalendarWeek
{
public:
    CalendarWeek() { }
    CalendarWeek(QList<int> weekDays);

private:
    QList<int> m_days;
};

#endif // CALENDARWEEK_H
