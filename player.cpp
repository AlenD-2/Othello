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

void Player::start(OthelloBoard::Disk color)
{
    _color = color;
    this->moveToThread(&_playerThread);
    _playerThread.start();
}

QString Player::getPlayerName() const
{
    return _playerName;
}

OthelloBoard::Disk Player::getColor() const
{
    return _color;
}

void Player::setDelay(int miliSec)
{
    _delay = miliSec;
}

void Player::readPlayerName()
{
    // initialize Player process (allocate memmory and start process and sent color)
    initProcess();

    _playerProcess->waitForReadyRead();
    _playerName = _playerProcess->readAllStandardOutput();
    _playerName = _playerName.remove('\r');
    _playerName = _playerName.remove('\n');
    emit playerReady();
}

// call it before program terminated
void Player::killProcess()
{
    if(_playerProcess != nullptr)
    {
        _playerProcess->kill();
        _playerProcess->waitForFinished();
    }
}

void Player::readyToMove(QString board, OthelloBoard::Disk color)
{
    if(_color == color)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(_delay));
        _playerProcess->write(board.toUtf8()+'\n');
        emit resumeTimer();
        _playerProcess->waitForReadyRead();
        emit pauseTimer();
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
    else
    {
        // set the player color
        QString color = QString::number(_color);
        _playerProcess->write(color.toUtf8()+'\n');
    }
}

}
