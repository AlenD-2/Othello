
#include "OthelloModel.h"

#include <QDebug>

namespace Othello {

void OthelloModel::setPosTo(int index, OthelloBoard::Disk color)
{
    OthelloBoard::Position userPos;
    userPos.row = index/BOARD_SIZE;
    userPos.column = index%BOARD_SIZE;

    auto posList = _game.findOppPos(_board, userPos, color);
    if(!posList.empty())
    {
        auto newBoard = _game.swapDisks(_board, userPos, color, posList);
        _board = newBoard;
        emit boardChanged();
        emit whiteCountChanged();
        emit blackCountChanged();
        exchangeTurn(_whosTurn);
    }
    else
    {
        if(_game.passTurn(_board, color))
        {
            exchangeTurn(_whosTurn);
        }
    }

    if(_game.isGameOver(_board))
    {
        _winner = _board.getWinner();
        emit winnerChanged();
    }
}

OthelloModel::OthelloModel(QObject *parent)
    : QObject{parent}
{
    _winner = static_cast<OthelloBoard::Disk>(GAME_IS_NOT_OVER);
    _whosTurn = OthelloBoard::Disk::black;

    connect(&_player1, &Player::playerReady, this, &OthelloModel::onPlayerReady);
    connect(this, &OthelloModel::programFinished, &_player1, &Player::killProcess);
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
    _playersName[0] = "Human";
    _playersName[1] = _player1.getPlayerName();
    emit playersNameChanged();
}

void OthelloModel::exchangeTurn(OthelloBoard::Disk& disk)
{
    disk = (disk==OthelloBoard::Disk::black)? OthelloBoard::Disk::white : OthelloBoard::Disk::black;
}

} // namespace Othello

