#include "UiController.h"
#include "DataController.h"
#include "data/CalendarMonth.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DataController *dataController = DataController::Create();
    UiController *uiController = UiController::Create();

    uiController->setDataController(dataController);
    dataController->Start();

    CalendarMonth m;
    int success = a.exec();

    uiController->Destroy();
    dataController->Destroy();

    return success;
}
