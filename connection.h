#ifndef CONNECTION_H
#define CONNECTION_H

#include <QWidget>

class QPushButton;
class QFormLayout;
class QLineEdit;
class QGridLayout;

class Connection : public QWidget
{
    Q_OBJECT
public:
    explicit Connection(QWidget *parent = 0);
    ~Connection();
    QPushButton *m_submitBtn;

private:
    void init();
    void handle();
    QPushButton *m_quitBtn;
    QFormLayout *m_formLayout;
    QGridLayout *m_gridLayout;
    QLineEdit *m_serverName;
    QLineEdit *m_serverPort;
    QLineEdit *m_userName;

signals:

public slots:

};

#endif // CONNECTION_H
