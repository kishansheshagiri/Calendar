#include "UiController.h"

#include <QDebug>

UiController::UiController()
    : m_calendarWindow(new CalendarMainWindow)
    , m_calendarWidget(new CalendarView())
{
    m_calendarWindow->centralWidget()->setLayout(m_calendarWidget->getLayout());
}

void UiController::setDataController(DataController *dataController)
{
    m_dataController = dataController;

    QObject::connect(dataController, SIGNAL(dataChanged(CalendarMonth*)),
                     this, SLOT(onDataChanged(CalendarMonth*)));

    QObject::connect(m_calendarWidget.data(), SIGNAL(monthNextClicked()),
                     dataController, SIGNAL(monthNextClicked()));
    QObject::connect(m_calendarWidget.data(), SIGNAL(monthPreviousClicked()),
                     dataController, SIGNAL(monthPreviousClicked()));
}

void UiController::onDataChanged(CalendarMonth *model)
{
    _setupMonthSpinBox(model->monthInfo());
    _setupTable(model);
    m_calendarWindow->show();
}

void UiController::_setupMonthSpinBox(QString&& data)
{
    m_calendarWidget->setSpinboxText(data);
}

void UiController::_setupTable(CalendarMonth *model)
{
    m_calendarWidget->setModel(model);
}
