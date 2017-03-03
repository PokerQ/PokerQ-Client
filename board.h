#ifndef BOARD_H
#define BOARD_H

#include <QWidget>

class Board : public QWidget
{
    Q_OBJECT

public:
    Board(QWidget *parent = 0);
    ~Board();
};

#endif // BOARD_H
