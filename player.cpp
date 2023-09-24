#include "Player.h"
#include <QDir>

namespace Othello {


Player::Player()
{
    connect(&_playerThread, &QThread::started, this, &Player::readPlayerName);
}

Player::~Player()
{
    _playerThread.exit();
    _playerThread.wait();
}

void Othello::Player::start(OthelloBoard::Disk color)
{
    _color = color;
    this->moveToThread(&_playerThread);
    _playerThread.start();
}

QString Player::getPlayerName() const
{
    return _playerName;
}

void Player::readPlayerName()
{
    // initialize Player process (allocate memmory and start process)
    initProcess();

    _playerProcess->waitForReadyRead();
    _playerName = _playerProcess->readAllStandardOutput();
    emit playerReady();
}

// call it before program terminated
void Player::killProcess()
{
    _playerProcess->kill();
    _playerProcess->waitForFinished();
}

void Player::readyToMove(QString board, OthelloBoard::Disk color)
{
    if(_color == color)
    {
        _playerProcess->write(board.toUtf8()+'\n');
        _playerProcess->waitForReadyRead();
        auto input = _playerProcess->readAllStandardOutput();
        emit readyReadMove(input);
    }
}

void Player::initProcess()
{
    _playerProcess = std::make_unique<QProcess>();
    _playerProcess->setProgram(QDir::currentPath()+"/p1.exe");
    _playerProcess->start();
    if(!_playerProcess->waitForStarted())
    {
        qDebug()<<"Error: can't start the process";
    }
}

}
