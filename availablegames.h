#ifndef AVAILABLEGAMES_H
#define AVAILABLEGAMES_H

#include <QWidget>

class QLabel;
class QGridLayout;
class QListView;
class QPushButton;

class AvailableGames : public QWidget
{
    Q_OBJECT
public:
    explicit AvailableGames(QWidget *parent = 0);
    ~AvailableGames();
    QPushButton *m_joinBtn;

private:
    void init();
    void handle();
    QGridLayout *m_gridLayout;
    QListView *m_availableGamesView;
    QPushButton *m_quitBtn;
    QLabel *m_titleLabel;

signals:

public slots:
    void slonJoinGame();
    void slonGameClicked();
};

#endif // AVAILABLEGAMES_H
