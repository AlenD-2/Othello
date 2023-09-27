
#include "OthelloModel.h"

#include <QDebug>

namespace Othello {

void OthelloModel::setPosTo(int index, OthelloBoard::Disk color)
{
    OthelloBoard::Position userPos;
    userPos.row = index/BOARD_SIZE;
    userPos.column = index%BOARD_SIZE;

    auto posList = _game.findOppPos(_board, userPos, color);
    // is a valid move?
    if(!posList.empty())
    {
        _board = _game.swapDisks(_board, userPos, color, posList);
        emit boardChanged();
        emit whiteCountChanged();
        emit blackCountChanged();
        exchangeTurn(_whosTurn);
    }
    else
    {
        // manage invalid move
    }

    if(_game.passTurn(_board, color))
    {
        exchangeTurn(_whosTurn);
    }

    if(_game.isGameOver(_board))
    {
        _winner = _board.getWinner();
        emit winnerChanged();
    }

    // if it's Ai turn in Human vs Code Mode
    if(_gameMode == Mode::HvC && _whosTurn == OthelloBoard::Disk::white)
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
    if(_gameMode == Mode::HvC)
    {
        _player1.start(OthelloBoard::Disk::white);
    }
    else if(_gameMode == Mode::CvC)
    {
        _player1.start(OthelloBoard::Disk::white);
        _player2.start(OthelloBoard::Disk::black);
    }
}

OthelloModel::OthelloModel(QObject *parent)
    : QObject{parent}
{
    _winner = static_cast<OthelloBoard::Disk>(GAME_IS_NOT_OVER);
    _whosTurn = OthelloBoard::Disk::black;

    // player 1
    connect(&_player1, &Player::playerReady, this, &OthelloModel::onPlayerReady);
    connect(this, &OthelloModel::programFinished, &_player1, &Player::killProcess);
    connect(this, &OthelloModel::startPlayerMove, &_player1, &Player::readyToMove);
    connect(&_player1, &Player::readyReadMove, this, &OthelloModel::readPlayerMove);
    // player 2
    connect(&_player2, &Player::playerReady, this, &OthelloModel::onPlayerReady);
    connect(this, &OthelloModel::programFinished, &_player2, &Player::killProcess);
    connect(this, &OthelloModel::startPlayerMove, &_player2, &Player::readyToMove);
    connect(&_player2, &Player::readyReadMove, this, &OthelloModel::readPlayerMove);
}

OthelloModel::~OthelloModel()
{
    emit programFinished();
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

QStringList OthelloModel::playersName()
{
    return _playersName;
}

void OthelloModel::onPlayerReady()
{
    if(_gameMode == Mode::HvH)
    {
        _playersName.replace(0, "Human");
        _playersName.replace(1, "Human");
    }
    else if(_gameMode == Mode::HvC)
    {
        _playersName.replace(0, _player1.getPlayerName());
        _playersName.replace(1, "Human");
    }
    else
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
        setPosTo(move.toInt(), OthelloBoard::Disk::white);
    }
    else if (obj == &_player2)
    {
        setPosTo(move.toInt(), OthelloBoard::Disk::black);
    }
}

void OthelloModel::exchangeTurn(OthelloBoard::Disk& disk)
{
    disk = (disk==OthelloBoard::Disk::black)? OthelloBoard::Disk::white : OthelloBoard::Disk::black;
}

} // namespace Othello

