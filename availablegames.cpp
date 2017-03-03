#include "availablegames.h"
#include <QGridLayout>
#include <QPushButton>
#include <QListView>
#include <QLabel>
#include <QCoreApplication>
#include <QStringListModel>
#include <QAbstractItemView>

AvailableGames::AvailableGames(QWidget *parent) : QWidget(parent)
{
    init();
    handle();
}

AvailableGames::~AvailableGames()
{
    delete m_availableGamesView;
    delete m_quitBtn;
    delete m_joinBtn;
    delete m_gridLayout;

    m_availableGamesView=nullptr;
    m_quitBtn=nullptr;
    m_joinBtn=nullptr;
    m_gridLayout=nullptr;
}

void AvailableGames::init()
{
    m_joinBtn = new QPushButton(tr("Join", "btn_join"));
    m_joinBtn->setEnabled(false);

    m_quitBtn = new QPushButton(tr("Quit", "btn_quit"));

    m_titleLabel = new QLabel(tr("Availables Games","lbl_titleAvailableGames"));
    m_titleLabel->setAlignment(Qt::AlignCenter);

    m_availableGamesView = new QListView;
    QStringListModel *model = new QStringListModel;
    QStringList list;

    list.append("Partie 1");
    list.append("Partie 2");
    list.append("Partie 3");

    model->setStringList(list);

    m_availableGamesView->setModel(model);
    m_availableGamesView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    m_gridLayout = new QGridLayout;

    m_gridLayout->addWidget(m_titleLabel,0,0,1,2);
    m_gridLayout->addWidget(m_availableGamesView,1,0,1,2);
    m_gridLayout->addWidget(m_quitBtn,2,0,1,1);
    m_gridLayout->addWidget(m_joinBtn,2,1,1,1);

    setLayout(m_gridLayout);
}

void AvailableGames::handle()
{
    connect(m_quitBtn, &QPushButton::clicked, this, &QCoreApplication::quit);
    connect(m_availableGamesView, &QListView::clicked, this, &AvailableGames::slonGameClicked);
}

void AvailableGames::slonJoinGame()
{

}

void AvailableGames::slonGameClicked()
{
    m_joinBtn->setEnabled(true);
}
