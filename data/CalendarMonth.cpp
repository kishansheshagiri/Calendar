#include "CalendarMonth.h"

#include <QDebug>

CalendarMonth::CalendarMonth()
    : m_dateInfo(QDate::currentDate())
    , m_isCurrentMonth(true)
{
    _createWeekObjects();
}

CalendarMonth::~CalendarMonth()
{
    _clearWeekObjects();
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
    int currentMonth = m_dateInfo.month();

    _clearWeekObjects();
    m_dateInfo.setDate(m_dateInfo.year(), m_dateInfo.month(), 1);

    QDate date(m_dateInfo);

    while (date.month() == currentMonth) {
        QList<int> list;
        for (int i = 1; i <= 7; i++) {
            if ((date.day() <= 7 && i < date.dayOfWeek())) {
                list.push_back(0);
                continue;
            } else if (date.month() == currentMonth) {
                list.push_back(date.day());
            } else {
                list.push_back(0);
            }

            date = date.addDays(1);
        }

        m_weekList.append(new CalendarWeek(list));
    }
}

void CalendarMonth::_clearWeekObjects()
{
    for (auto week : m_weekList) {
        if (week != nullptr) {
            delete week;
            week = nullptr;
        }
    }

    m_weekList.clear();
}
