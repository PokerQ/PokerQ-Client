#include "board.h"
#include <QRect>
#include <QApplication>
#include <QPainter>
#include <QDesktopWidget>
#include <QPen>
#include <QLabel>
#include <QPushButton>
#include <QImage>
#include <QPoint>

Board::Board(QWidget *parent)
    : QWidget(parent)
{
    init();
    handle();
}

Board::~Board()
{

}

void Board::init(){
    ecran = QApplication::desktop()->screenGeometry();
    setFixedSize(ecran.width(),ecran.height());
    //Construction du label du pot
    pot = new QLabel(this);
    pot->setText("POT : XXX");
    pot->setStyleSheet("font: 25pt;");
    pot->setGeometry(width()*0.45,height()*0.35,200,200);

    //Construction du label du Joueur 1
    stackPlayer1 = new QLabel(this);
    stackPlayer1->setText("XXX");
    stackPlayer1->setStyleSheet("font: 25pt;");
    stackPlayer1->setGeometry(width()*0.1,height()*0.38,50,50);

    //Construction du label du Joueur 2
    stackPlayer2 = new QLabel(this);
    stackPlayer2->setText("XXX");
    stackPlayer2->setStyleSheet("font: 25pt;");
    stackPlayer2->setGeometry(width()*0.485,height()*0.05,50,50);

    //Construction du label du Joueur 3
    stackPlayer3 = new QLabel(this);
    stackPlayer3->setText("XXX");
    stackPlayer3->setStyleSheet("font: 25pt;");
    stackPlayer3->setGeometry(width()*0.87,height()*0.38,50,50);

    //Construction du label du Joueur 4
    stackPlayer4 = new QLabel(this);
    stackPlayer4->setText("XXX");
    stackPlayer4->setStyleSheet("font: 25pt;");
    stackPlayer4->setGeometry(width()*0.485,height()*0.83,50,50);

    //Construction du label mise du Joueur 1
    mise1 = new QLabel(this);
    mise1->setText("XXX");
    mise1->setStyleSheet("font: 25pt;");
    mise1->setGeometry(width()*0.18,height()*0.38,50,50);

    //Construction du label mise du Joueur 2
    mise2 = new QLabel(this);
    mise2->setText("XXX");
    mise2->setStyleSheet("font: 25pt;");
    mise2->setGeometry(width()*0.485,height()*0.1,50,50);

    //Construction du label mise du Joueur 3
    mise3 = new QLabel(this);
    mise3->setText("XXX");
    mise3->setStyleSheet("font: 25pt;");
    mise3->setGeometry(width()*0.80,height()*0.38,50,50);

    //Construction du label mise du Joueur 4
    mise4 = new QLabel(this);
    mise4->setText("XXX");
    mise4->setStyleSheet("font: 25pt;");
    mise4->setGeometry(width()*0.485,height()*0.65,50,50);

    //Construction du bouton Fold
    foldButton = new QPushButton(this);
    foldButton->setText("Fold");
    foldButton->setGeometry(width()*0.425,height()*0.87,75,75);

    //Construction du bouton Check
    checkButton = new QPushButton(this);
    checkButton->setText("Check");
    checkButton->setGeometry(width()*0.475,height()*0.87,75,75);

    //Construction du bouton Bet
    betButton = new QPushButton(this);
    betButton->setText("Bet");
    betButton->setGeometry(width()*0.525,height()*0.87,75,75);

    flop1 = new QPoint(width()*0.38,height()*0.30);
    flop2 = new QPoint(width()*0.43,height()*0.30);
    flop3 = new QPoint(width()*0.48,height()*0.30);
    turn = new QPoint(width()*0.53,height()*0.30);
    river = new QPoint(width()*0.58,height()*0.30);
    card1Player = new QPoint(width()*0.45,height()*0.72);
    card2Player = new QPoint(width()*0.51,height()*0.72);

    stringFlop1 = new QString(":/cards/cards/dos.jpeg");
    stringFlop2 = new QString(":/cards/cards/dos.jpeg");
    stringFlop3 = new QString(":/cards/cards/dos.jpeg");
    stringTurn = new QString(":/cards/cards/dos.jpeg");
    stringRiver = new QString(":/cards/cards/dos.jpeg");
    stringCard1 = new QString(":/cards/cards/dos.jpeg");
    stringCard2 = new QString(":/cards/cards/dos.jpeg");

}

void Board::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.save();

    pen = new QPen();

    pen->setWidth(5);
    painter.setPen(*pen);
    painter.setBrush(QBrush(QColor(39,174,96)));
    painter.drawEllipse(width()*0.15,height()*0.1,width()*0.7,height()*0.6);

    //Player 1
    painter.drawImage(*card1Player, QImage(*stringCard1));
    painter.drawImage(*card2Player, QImage(*stringCard2));

    //5 cartes
    painter.drawImage(*flop1, QImage(*stringFlop1));
    painter.drawImage(*flop2, QImage(*stringFlop2));
    painter.drawImage(*flop3, QImage(*stringFlop3));
    painter.drawImage(*turn, QImage(*stringTurn));
    painter.drawImage(*river, QImage(*stringRiver));

    painter.restore();
}

void Board::handle(){
    QObject::connect(foldButton,&QPushButton::clicked,this, &Board::slFold);
    QObject::connect(checkButton,&QPushButton::clicked,this,&Board::slCheck);
    QObject::connect(betButton,&QPushButton::clicked,this,&Board::slBet);
}

void Board::slBet(){

}

void Board::slCheck(){

}

void Board::slFold(){

}

void Board::drawCard(){

}
