#include "UiController.h"

void UiController::onDataChanged()
{

}

UiController::UiController()
    : m_calendar(new CalendarMainWindow)
{
}

UiController::~UiController()
{
    m_calendar.clear();
}

void UiController::setDataController(DataController *dataController)
{
    m_dataController = dataController;

    QObject::connect(dataController, &DataController::dataChanged,
                     this, &UiController::onDataChanged);
}
