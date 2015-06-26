#ifndef CALENDARWEEK_H
#define CALENDARWEEK_H

#include <QList>

class CalendarWeek
{
public:
    CalendarWeek(QList<int> weekDays);
    ~CalendarWeek();

    int GetIndex(int index);

private:
    QList<int> m_days;
};

#endif // CALENDARWEEK_H
