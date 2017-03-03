#ifndef BOARD_H
#define BOARD_H

#include <QWidget>

class QRect;
class QPainter;
class Qpen;
class QLabel;
class QPushButton;

class Board : public QWidget
{
    Q_OBJECT

public:
    Board(QWidget *parent = 0);
    ~Board();

    QRect ecran;
    QPen *pen;
    QLabel *pot;
    QLabel *stackPlayer1;
    QLabel *stackPlayer2;
    QLabel *stackPlayer3;
    QLabel *stackPlayer4;
    QLabel *mise1;
    QLabel *mise2;
    QLabel *mise3;
    QLabel *mise4;
    QPushButton *foldButton;
    QPushButton *checkButton;
    QPushButton *betButton;

    void init();
    void handle();

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void slBet();
    void slCheck();
    void slFold();
};

#endif // BOARD_H
