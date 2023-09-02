#include "Player.h"
#include <QDir>

Player::Player()
{
    this->moveToThread(&_playerThread);
    connect(&_playerThread, &QThread::started, this, &Player::readPlayerName);
    _playerThread.start();
}

Player::~Player()
{
    _playerThread.exit();
}

void Player::readPlayerName()
{
    // initialize Player process (allocate memmory and start process
    initProcess();

    _playerProcess->waitForReadyRead();
    auto name = _playerProcess->readAllStandardOutput();
    qDebug()<<"player name = " << name;
    emit playerReady(name);
}

void Player::killProcess()
{
    _playerProcess->kill();
    _playerProcess->waitForFinished(10000);
    qDebug()<<_playerProcess->isOpen();
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
