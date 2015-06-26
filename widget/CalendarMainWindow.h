#ifndef CALENDARMAINWINDOW_H
#define CALENDARMAINWINDOW_H

#include <QMainWindow>
#include <QScopedPointer>
#include <QMenuBar>

class CalendarMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CalendarMainWindow(QWidget *parent = 0);
    ~CalendarMainWindow() { }

private:
    void _setupMainWindowParams();
    void _setupUi();

    QScopedPointer<QMenuBar> m_menuBar;
    QScopedPointer<QWidget> m_centralWidget;
};

#endif // CALENDARMAINWINDOW_H
