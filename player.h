#pragma once

#include "OthelloBoard.h"

#include <QObject>
#include <QThread>
#include <QProcess>

#include <memory>

namespace Othello {


class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player();
    ~Player();

    void start(OthelloBoard::Disk color);
    QString getPlayerName()const;

signals:
    void playerReady();
    void readyReadMove(QString move);

public slots:
    void readPlayerName();
    void killProcess();
    void readyToMove(QString board);

private:
    QThread _playerThread;
    std::unique_ptr<QProcess> _playerProcess;
    QString _playerName;
    OthelloBoard::Disk _color;

    //functions
    void initProcess();
};

}
