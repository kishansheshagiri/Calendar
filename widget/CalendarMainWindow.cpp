#include "CalendarMainWindow.h"

#include <QApplication>
#include <qdebug.h>

CalendarMainWindow::CalendarMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_menuBar(new QMenuBar(this))
    , m_centralWidget(new QWidget(this))
{
    _setupMainWindowParams();
    _setupUi();
}

void CalendarMainWindow::_setupMainWindowParams()
{
    if (objectName().isEmpty())
        setObjectName(QStringLiteral("calendarMainWindow"));

    m_menuBar.data()->setObjectName(QStringLiteral("menuBar"));
    setMenuBar(m_menuBar.data());

    m_centralWidget.data()->setObjectName(QStringLiteral("centralWidget"));
    setCentralWidget(m_centralWidget.data());

    QMetaObject::connectSlotsByName(this);
    setWindowTitle(QApplication::translate("Calendar", "Calendar", 0));
}

void CalendarMainWindow::_setupUi()
{
//    show();
}
