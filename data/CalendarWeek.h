#ifndef CALENDARWEEK_H
#define CALENDARWEEK_H

#include <vector>

class CalendarWeek
{
public:
    CalendarWeek(std::initializer_list<int> days);

private:
    std::vector<int> m_days;
};

#endif // CALENDARWEEK_H
