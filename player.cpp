#include "Player.h"
#include <QDir>

namespace Othello {


Player::Player()
{
    connect(&_playerThread, &QThread::started, this, &Player::readPlayerName);
}

Player::~Player()
{
    // a few delay to revert process to main thread
    std::this_thread::sleep_for(std::chrono::seconds(2));
    if(_playerProcess != nullptr && _playerProcess->state() == QProcess::Running)
    {
        _playerProcess->kill();
        _playerProcess->waitForFinished();
    }
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

void Othello::Player::setParameters(const std::array<int, 3> &params)
{
    _parameters = params;
}

void Player::readPlayerName()
{
    if(_isFunctional)
    {
        _playerName = _funcPlayerName();
        emit playerReady();
        return;
    }
    // initialize Player process (allocate memmory and start process and sent color)
    initProcess();

    _playerProcess->waitForReadyRead();
    _playerName = _playerProcess->readAllStandardOutput();
    _playerName = _playerName.remove('\r');
    _playerName = _playerName.remove('\n');
    emit playerReady();
}

// call it before program terminated
void Player::killProcess(QThread *mainThread)
{
    _playerProcess->moveToThread(mainThread);
}

void Player::readyToMove(QString board, OthelloBoard::Disk color)
{
    if(_color == color)
    {
        QString result{};
        // wait until disk swap finished
        std::this_thread::sleep_for(std::chrono::milliseconds(_delay));

        emit playerProcessStarted();
        if(_isFunctional)
        {
            result = _playerFunc(board, color);
        }
        else
        {
            _playerProcess->write(board.toUtf8()+'\n');
            _playerProcess->waitForReadyRead();
            result = _playerProcess->readAllStandardOutput();
        }
        emit playerProcessStoped();
        emit readyReadMove(result);
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
        // set parameters
        for(const auto& par : _parameters)
        {
            _playerProcess->write(QString::number(par).toUtf8()+'\n');
            _playerProcess->waitForBytesWritten();
        }
        // set the player color
        QString color = QString::number(_color);
        _playerProcess->write(color.toUtf8()+'\n');
    }
}

/*
 * this function is for name of the players who use function instead of process
 */
QString Othello::Player::_funcPlayerName() const
{
    return "PlayerName";
}

/*
 * this function is for code of the players who use function instead of process
 */
QString Player::_playerFunc(const QString &board, int color)
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return "26";
}

}
