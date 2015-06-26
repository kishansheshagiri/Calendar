#include "CalendarWeek.h"

#include <QDebug>

CalendarWeek::CalendarWeek(QList<int> weekDays)
    : m_days(weekDays)
{
}

CalendarWeek::~CalendarWeek()
{
}

int CalendarWeek::GetIndex(int index)
{
    return m_days.at(index);
}
