
#include "OthelloModel.h"

#include <QDebug>

namespace Othello {

void OthelloModel::setPosTo(int index, OthelloBoard::Piece color)
{
    OthelloBoard::Position userPos;
    userPos.row = index/BOARD_SIZE;
    userPos.column = index%BOARD_SIZE;

    auto posList = _game.findOppPos(_board, userPos, color);
    if(!posList.empty())
    {
        auto newBoard = _game.swapPieces(_board, userPos, color, posList);
        _board = newBoard;
        emit boardChanged();
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

} // namespace Othello

