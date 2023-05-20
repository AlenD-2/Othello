
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

void OthelloModel::exchangeTurn(OthelloBoard::Disk& disk)
{
    disk = (disk==OthelloBoard::Disk::black)? OthelloBoard::Disk::white : OthelloBoard::Disk::black;
}

} // namespace Othello

