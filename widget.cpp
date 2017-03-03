#include "widget.h"
#include <board.h>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    init();
}

void Widget::init(){
    board = new Board(this);

}
