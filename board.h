#ifndef BOARD_H
#define BOARD_H

#include <QWidget>

class QRect;
class QPainter;
class Qpen;
class QLabel;
class QPushButton;
class QImage;
class QPoint;

class Board : public QWidget
{
    Q_OBJECT

public:
    Board(QWidget *parent = 0);
    ~Board();

private:
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
    QPoint *flop1;
    QPoint *flop2;
    QPoint *flop3;
    QPoint *turn;
    QPoint *river;
    QPoint *card1Player;
    QPoint *card2Player;
    QString *stringFlop1;
    QString *stringFlop2;
    QString *stringFlop3;
    QString *stringTurn;
    QString *stringRiver;
    QString *stringCard1;
    QString *stringCard2;


    void init();
    void handle();
    void drawCard();

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void slBet();
    void slCheck();
    void slFold();
};

#endif // BOARD_H
