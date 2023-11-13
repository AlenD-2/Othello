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
    OthelloBoard::Disk getColor()const;
    void setDelay(int miliSec);

signals:
    void playerReady();
    void readyReadMove(QString move);
    void playerProcessStarted();
    void playerProcessStoped();

public slots:
    void readPlayerName();
    void killProcess();
    void readyToMove(QString board, OthelloBoard::Disk color);

private:
    QThread _playerThread;
    std::unique_ptr<QProcess> _playerProcess;
    QString _playerName;
    OthelloBoard::Disk _color;
    int _delay{1000};
    bool _isFunctional{false};

    //functions
    void initProcess();
    QString _funcPlayerName()const;
    QString _playerFunc(const QString& board, int color);
};

}
