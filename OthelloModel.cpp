
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
    }
}

OthelloModel::OthelloModel(QObject *parent)
    : QObject{parent}
{

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

} // namespace Othello

