#include "widget.h"
#include <board.h>
#include <connection.h>
#include <availablegames.h>
#include <QStackedWidget>
#include <QRect>
#include <QApplication>
#include <QPushButton>
#include <QDesktopWidget>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    resize(280,175);

    init();
}

void Widget::init()
{
    m_board = new Board();
    m_connection = new Connection();
    m_availableGames = new AvailableGames();

    m_stackedWidget = new QStackedWidget(this);
    m_stackedWidget->addWidget(m_connection);
    m_stackedWidget->addWidget(m_availableGames);
    m_stackedWidget->addWidget(m_board);

    m_stackedWidget->setCurrentIndex(0);

    connect(m_connection->m_submitBtn, &QPushButton::clicked, this, &Widget::slgoToAvailableGames);
    connect(m_availableGames->m_joiBtn, &QPushButton::clicked, this, &Widget::slgoToBoard);
}

void Widget::slgoToAvailableGames()
{
    m_stackedWidget->setCurrentIndex(1);
    resize(280,300);
}

void Widget::slgoToBoard()
{
    m_stackedWidget->setCurrentIndex(2);
}
