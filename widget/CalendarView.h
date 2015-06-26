#ifndef CALENDARVIEW_H
#define CALENDARVIEW_H

#include <QTableView>
#include <QToolButton>
#include <QVBoxLayout>

static const int SPINBOX_HEIGHT = 35;
static const int SPINBOX_TOUCHAREA_WIDTH = 100;
static const int VHEADER_SECTION_SIZE = 35;
static const int HHEADER_SECTION_SIZE = 50;

class CalendarView;

class MonthSpinBox : public QToolButton
{
public:
    MonthSpinBox(CalendarView *table);
    virtual ~MonthSpinBox() { }

    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    bool hitButton(const QPoint &pos) const Q_DECL_OVERRIDE;

private:

    QSize m_arrowRegionSize;
    CalendarView *m_calendarTable;
};

class CalendarView : public QTableView
{
    Q_OBJECT
public:
    CalendarView();
    virtual ~CalendarView() { }

    QLayout *getLayout();
    void setSpinboxText(QString data) { m_monthSpinBox.data()->setText(data); }

Q_SIGNALS:
    void monthNextClicked();
    void monthPreviousClicked();

private:
    void _setupLayout();

    QVBoxLayout m_layout;
    QScopedPointer<MonthSpinBox> m_monthSpinBox;
};

#endif // CALENDARTABLEVIEW_H
