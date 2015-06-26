#include "CalendarView.h"

#include <QDebug>
#include <QHeaderView>
#include <QPaintEvent>
#include <QStylePainter>
#include <QStyleOption>

CalendarView::CalendarView()
    : m_monthSpinBox(new MonthSpinBox(this))
{
    _setupLayout();
}

QLayout *CalendarView::getLayout()
{
    return &m_layout;
}

void CalendarView::_setupLayout()
{
    QHeaderView *vHeader = verticalHeader();
    vHeader->setMaximumWidth(0);
    vHeader->sectionResizeMode(QHeaderView::Fixed);
    vHeader->setDefaultSectionSize(VHEADER_SECTION_SIZE);

    QHeaderView *hHeader = horizontalHeader();
    hHeader->sectionResizeMode(QHeaderView::Fixed);
    hHeader->setDefaultSectionSize(HHEADER_SECTION_SIZE);

    setObjectName("calendarDateTable");
    setShowGrid(false);
    setFocusPolicy(Qt::ClickFocus);
    setSizeAdjustPolicy(AdjustToContents);
    setSelectionMode(QAbstractItemView::SingleSelection);
    setStyleSheet("QTableView::item::hover {background: #BBBBBB; color: #FFFFFF}");

    m_layout.addWidget(m_monthSpinBox.data());
    m_layout.addWidget(this);
    m_layout.setSizeConstraint(QLayout::SetFixedSize);
}

MonthSpinBox::MonthSpinBox(CalendarView *table)
    : m_calendarTable(table)
    , m_arrowRegionSize(QSize(SPINBOX_TOUCHAREA_WIDTH, SPINBOX_HEIGHT))
{
    setMinimumHeight(SPINBOX_HEIGHT);
    setFocusPolicy(Qt::NoFocus);
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
}

void MonthSpinBox::paintEvent(QPaintEvent *event)
{
    QToolButton::paintEvent(event);

    QStylePainter p(this);
    QStyleOption option;

    option.initFrom(this);

    option.rect = QRect(QPoint(), m_arrowRegionSize);
    p.drawPrimitive(QStyle::PE_IndicatorArrowLeft, option);

    option.rect = QRect(QPoint(width() - m_arrowRegionSize.width(), 0), m_arrowRegionSize);
    p.drawPrimitive(QStyle::PE_IndicatorArrowRight, option);
}

bool MonthSpinBox::hitButton(const QPoint &pos) const
{
    QRect leftButton = QRect(QPoint(), m_arrowRegionSize);
    QRect rightButton = QRect(QPoint(width() - m_arrowRegionSize.width(), 0), m_arrowRegionSize);

    if (leftButton.contains(pos))
        Q_EMIT m_calendarTable->monthPreviousClicked();
    else if (rightButton.contains(pos))
        Q_EMIT m_calendarTable->monthNextClicked();

    return false;
}
