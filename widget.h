#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Board;

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);

private:
    Board *board;

    void init();
};

#endif // WIDGET_H
