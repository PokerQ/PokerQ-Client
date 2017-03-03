#include "board.h"
#include <QRect>
#include <QApplication>
#include <QPainter>
#include <QDesktopWidget>
#include <QPen>

Board::Board(QWidget *parent)
    : QWidget(parent)
{
    init();
}

Board::~Board()
{

}

void Board::init(){

    ecran = QApplication::desktop()->screenGeometry();
    setFixedSize(ecran.width(),ecran.height());
}

void Board::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.save();

    pen = new QPen();

    pen->setWidth(5);
    painter.setPen(*pen);
    painter.setBrush(QBrush(QColor(39,174,96)));
    painter.drawEllipse(width()*0.15,height()*0.2,width()*0.7,height()*0.6);

    painter.restore();
}
