#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Board;
class Connection;
class AvailableGames;
class QStackedWidget;

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);

private:
    Board *m_board;
    Connection *m_connection;
    AvailableGames *m_availableGames;
    QStackedWidget *m_stackedWidget;

    void init();

public slots:
    void slgoToAvailableGames();
};

#endif // WIDGET_H
