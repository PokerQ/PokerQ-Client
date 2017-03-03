#include "connection.h"
#include <QFormLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QIntValidator>
#include <QGridLayout>
#include <QCoreApplication>

Connection::Connection(QWidget *parent) : QWidget(parent)
{
    init();
    handle();
}

Connection::~Connection()
{
    delete m_submitBtn;
    delete m_quitBtn;
    delete m_serverName;
    delete m_serverPort;
    delete m_userName;
    delete m_gridLayout;
    delete m_formLayout;

    m_submitBtn=nullptr;
    m_quitBtn=nullptr;
    m_serverName=nullptr;
    m_serverPort=nullptr;
    m_userName=nullptr;
    m_gridLayout=nullptr;
    m_formLayout=nullptr;
}

void Connection::init()
{
    m_submitBtn = new QPushButton(tr("Connect", "btn_connect"));
    m_quitBtn = new QPushButton(tr("Quit", "btn_quit"));
    m_userName = new QLineEdit;
    m_serverName = new QLineEdit;
    m_serverPort = new QLineEdit;

    m_serverPort->setValidator(new QIntValidator(1024, 65535, this));

    m_formLayout = new QFormLayout;
    m_formLayout->addRow(tr("Username:", "lbl_userName"), m_userName);
    m_formLayout->addRow(tr("Server Name:", "lbl_serverName"), m_serverName);
    m_formLayout->addRow(tr("Server Port:", "lbl_serverPort"), m_serverPort);

    m_gridLayout = new QGridLayout;
    m_gridLayout->addWidget(m_quitBtn,0,0);
    m_gridLayout->addWidget(m_submitBtn,0,1);

    m_formLayout->addRow(m_gridLayout);

    m_formLayout->setRowWrapPolicy(QFormLayout::RowWrapPolicy::DontWrapRows);
    m_formLayout->setFieldGrowthPolicy(QFormLayout::FieldGrowthPolicy::AllNonFixedFieldsGrow);
    m_formLayout->setFormAlignment(Qt::AlignHCenter | Qt::AlignTop);
    m_formLayout->setLabelAlignment(Qt::AlignRight);

    setLayout(m_formLayout);
}

void Connection::handle()
{
    connect(m_quitBtn, &QPushButton::clicked, this, &QCoreApplication::quit);
}
