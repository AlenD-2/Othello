
#include "OthelloModel.h"

#include <QDebug>

namespace Othello {

void OthelloModel::setPosTo(int index, OthelloBoard::Disk color)
{
    if(color != _whosTurn || _earlyGameOver)
    {
        return;
    }

    OthelloBoard::Position userPos;
    userPos.row = index/BOARD_SIZE;
    userPos.column = index%BOARD_SIZE;

    auto posList = _game.findOppPos(_board, userPos, color);
    // is a valid move?
    if(!posList.empty())
    {
        _invalidPos = -1; // set as valid move
        emit invalidPosChanged();
        _player1Chance = 3;
        emit player1ChanceChanged();
        _player2Chance = 3;
        emit player2ChanceChanged();

        _board = _game.swapDisks(_board, userPos, color, posList);
        _swapList.updateList(_board.getBoard(), userPos);
        emit swapListChanged();
        emit boardChanged();
        emit whiteCountChanged();
        emit blackCountChanged();
        exchangeTurn(_whosTurn);
    }
    else
    {
        // manage invalid move
        _invalidPos = index;
        emit invalidPosChanged();
        if(color == _player1.getColor())
        {
            _player1Chance--;
            emit player1ChanceChanged();
            if(_player1Chance == 0)
            {
                _earlyGameOver = true;
                _winner = _player2.getColor();
                emit winnerChanged();
            }
        }
        else // player2
        {
            _player2Chance--;
            emit player2ChanceChanged();
            if(_player2Chance == 0)
            {
                _earlyGameOver = true;
                _winner = _player1.getColor();
                emit winnerChanged();
            }
        }
    }

    if(_game.isGameOver(_board))
    {
        _winner = _board.getWinner();
        emit winnerChanged();
        return;
    }

    if(_game.passTurn(_board, _whosTurn))
    {
        exchangeTurn(_whosTurn);
        _turnPassed = true;
        emit turnPassedChanged();
    }
    else
    {
        nextTurn();
    }
}

/*
 * note: in Human vs Human mode do nothing */
void OthelloModel::nextTurn()
{
    // this function may called when turn passed so reset it to false (fix turnPass bug)
    _turnPassed = false;
    emit turnPassedChanged();

    // if game is over earlier cause one of players is timeout or out of chance
    if(_earlyGameOver)
    {
        return;
    }

    // if it's Ai turn in Human vs Code Mode
    if(_gameMode == Mode::HvC && _whosTurn == _player1.getColor())
    {
        emit startPlayerMove(_board.toQString(), _whosTurn);
    }
    else if(_gameMode == Mode::CvC)
    {
        emit startPlayerMove(_board.toQString(), _whosTurn);
    }
}

void OthelloModel::setGameMode(int modeIndex)
{
    _gameMode = static_cast<Mode>(modeIndex);
    if(_gameMode == Mode::HvH)
    {
        _playersName.replace(0, "Human");
        _playersName.replace(1, "Human");
    }
    else if(_gameMode == Mode::HvC)
    {
        _player1.start(OthelloBoard::Disk::black);
    }
    else //Mode::CvC
    {
        _player1.start(OthelloBoard::Disk::black);
        _player2.start(OthelloBoard::Disk::white);
    }
}

void OthelloModel::setAiDelay(int miliSec)
{
    if(_gameMode == Mode::HvC)
    {
        _player1.setDelay(miliSec);
    }
    else if(_gameMode == Mode::CvC)
    {
        _player1.setDelay(miliSec);
        _player2.setDelay(miliSec);
    }
}

void OthelloModel::setParameters(int p1s1, int p1s2, int p1s3, int p2s1, int p2s2, int p2s3)
{
    std::array<int,3> p1{p1s1,p1s2,p1s3};
    _player1.setParameters(p1);
    std::array<int,3> p2{p2s1,p2s2,p2s3};
    _player2.setParameters(p2);
}

OthelloModel::OthelloModel(QObject *parent)
    : QObject{parent}
{
    _winner = static_cast<OthelloBoard::Disk>(GAME_IS_NOT_OVER);
    _whosTurn = OthelloBoard::Disk::black;

    _player1Timer = new Timer(this);
    _player2Timer = new Timer(this);

    // player 1
    connect(&_player1, &Player::playerReady, this, &OthelloModel::onPlayerReady);
    connect(this, &OthelloModel::programFinished, &_player1, &Player::killProcess);
    connect(this, &OthelloModel::startPlayerMove, &_player1, &Player::readyToMove);
    connect(&_player1, &Player::readyReadMove, this, &OthelloModel::readPlayerMove);
    connect(&_player1, &Player::playerProcessStarted, _player1Timer, &Timer::start);
    connect(&_player1, &Player::playerProcessStoped, _player1Timer, &Timer::stop);
    connect(_player1Timer, &Timer::timeChanged, this, &OthelloModel::onTimerChanged);
    // player 2
    connect(&_player2, &Player::playerReady, this, &OthelloModel::onPlayerReady);
    connect(this, &OthelloModel::programFinished, &_player2, &Player::killProcess);
    connect(this, &OthelloModel::startPlayerMove, &_player2, &Player::readyToMove);
    connect(&_player2, &Player::readyReadMove, this, &OthelloModel::readPlayerMove);
    connect(&_player2, &Player::playerProcessStarted, _player2Timer, &Timer::start);
    connect(&_player2, &Player::playerProcessStoped, _player2Timer, &Timer::stop);
    connect(_player2Timer, &Timer::timeChanged, this, &OthelloModel::onTimerChanged);
}

OthelloModel::~OthelloModel()
{
    emit programFinished(QThread::currentThread());
    // need a few delay to have enough time to kill the player process
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

QVector<int> OthelloModel::board()
{
    return _board.toQVector();
}

int OthelloModel::whiteCount()
{
    return _board.getDiskCount().white;
}

int OthelloModel::blackCount()
{
    return _board.getDiskCount().black;
}

int OthelloModel::winner()
{
    return _winner;
}

int OthelloModel::whosTurn()
{
    return _whosTurn;
}

bool OthelloModel::turnPassed()
{
    return _turnPassed;
}

QVector<bool> OthelloModel::swapList()
{
    return _swapList.toQVector();
}

int OthelloModel::invalidPos()
{
    return _invalidPos;
}

QString OthelloModel::player1Time()
{
    return _player1Timer->remainTime().toQString();
}

QString OthelloModel::player2Time()
{
    return _player2Timer->remainTime().toQString();
}

int OthelloModel::player1Chance()
{
    return _player1Chance;
}

int OthelloModel::player2Chance()
{
    return _player2Chance;
}

QStringList OthelloModel::playersName()
{
    return _playersName;
}

void OthelloModel::onPlayerReady()
{
    if(_gameMode == Mode::HvC)
    {
        _playersName.replace(0, _player1.getPlayerName());
        _playersName.replace(1, "Human");
    }
    else // Mode::CvC
    {
        _playersName.replace(0, _player1.getPlayerName());
        _playersName.replace(1, _player2.getPlayerName());
    }

    emit playersNameChanged();
}

void OthelloModel::readPlayerMove(QString move)
{
    auto obj = sender();
    if(obj == &_player1)
    {
        setPosTo(move.toInt(), _player1.getColor());
    }
    else if (obj == &_player2)
    {
        setPosTo(move.toInt(), _player2.getColor());
    }
}

/*
 * update the timer and check if the player is out of time*/
void OthelloModel::onTimerChanged()
{
    auto obj = sender();
    if(obj == _player1Timer)
    {
        if(_player1Timer->remainTime().toSeconds() == 0)
        {
            _earlyGameOver = true;
            _winner = _player2.getColor();
            emit winnerChanged();
        }
        emit player1TimeChanged();
    }
    else if(obj == _player2Timer)
    {
        if(_player2Timer->remainTime().toSeconds() == 0)
        {
            _earlyGameOver = true;
            _winner = _player1.getColor();
            emit winnerChanged();
        }
        emit player2TimeChanged();
    }
}



void OthelloModel::exchangeTurn(OthelloBoard::Disk& disk)
{
    disk = (disk==OthelloBoard::Disk::black)? OthelloBoard::Disk::white : OthelloBoard::Disk::black;
    emit whosTurnChanged();
}

} // namespace Othello

