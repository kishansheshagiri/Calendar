#include "UiController.h"

void UiController::onDataReady()
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

    QObject::connect(dataController, &DataController::dataReady,
                     this, &UiController::onDataReady);
}
