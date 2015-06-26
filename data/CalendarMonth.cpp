#include "CalendarMonth.h"

#include <QDebug>
#include <QColor>

CalendarMonth::CalendarMonth()
    : QAbstractTableModel()
    , m_dateInfo(QDate::currentDate())
    , m_isCurrentMonth(true)
{
}

CalendarMonth::~CalendarMonth()
{
    _clearWeekObjects();
}

void CalendarMonth::initialize()
{
    _createWeekObjects();
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

QString CalendarMonth::monthInfo()
{
    return QDate::longMonthName(m_dateInfo.month()) + ", " + QString::number(m_dateInfo.year());
}

int CalendarMonth::rowCount(const QModelIndex& /*parent*/) const
{
    return m_weekList.length();
}

int CalendarMonth::columnCount(const QModelIndex& /*parent*/) const
{
    return 7;
}

QVariant CalendarMonth::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::TextAlignmentRole)
        return Qt::AlignCenter;
    else if (role != Qt::DisplayRole)
        return QVariant();

    int date = m_weekList.at(index.row())->GetIndex(index.column());

    return date == 0 ? QVariant() : QVariant(date);
}

QVariant CalendarMonth::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::TextColorRole)
        return QVariant(QColor("Red"));

    if (orientation == Qt::Horizontal
            && role == Qt::DisplayRole) {
        return QVariant(QDate::shortDayName(section + 1));
    }

    return QVariant();
}

void CalendarMonth::_createWeekObjects()
{
    int currentMonth = m_dateInfo.month();

    _clearWeekObjects();
    m_dateInfo.setDate(m_dateInfo.year(), m_dateInfo.month(), 1);

    QDate date(m_dateInfo);

    while (date.month() == currentMonth || m_weekList.size() < 6) {
        QList<int> list;
        for (int i = 1; i <= 7; i++) {
            if ((date.day() <= 7 && i < date.dayOfWeek())) {
                list << 0;
                continue;
            } else if (date.month() == currentMonth) {
                list << date.day();
            } else {
                list << 0;
            }

            date = date.addDays(1);
        }

        m_weekList.append(new CalendarWeek(list));
    }

    Q_EMIT monthChanged(this);
    Q_EMIT layoutChanged();
}

void CalendarMonth::_clearWeekObjects()
{
    qDeleteAll(m_weekList);
    m_weekList.clear();
}

//#include "moc_CalendarMonth.h"
