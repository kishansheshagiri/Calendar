#include "CalendarWeek.h"

#include <QDebug>

CalendarWeek::CalendarWeek(QList<int> weekDays)
    : m_days(weekDays)
{
    qDebug() << "Days: " << m_days;
}
