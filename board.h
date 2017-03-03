#ifndef BOARD_H
#define BOARD_H

#include <QWidget>

class QRect;
class QPainter;
class Qpen;

class Board : public QWidget
{
    Q_OBJECT

public:
    Board(QWidget *parent = 0);
    ~Board();

    QRect ecran;
    QPen *pen;

    void init();

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // BOARD_H
