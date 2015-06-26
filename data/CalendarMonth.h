#ifndef CALENDARMONTH_H
#define CALENDARMONTH_H

#include "CalendarWeek.h"

#include <memory>
#include <QDate>
#include <QList>
#include <QAbstractTableModel>

class CalendarMonth : public QAbstractTableModel
{
    Q_OBJECT
public:
    CalendarMonth();
    ~CalendarMonth();

    void initialize();
    QString monthInfo();

    int rowCount(const QModelIndex& parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex& parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex& index, int role) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation = Qt::Horizontal, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

Q_SIGNALS:
    void monthChanged(CalendarMonth *model);

public Q_SLOTS:
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
