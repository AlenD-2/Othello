
#include "OthelloModel.h"

#include <QDebug>

namespace Othello {

void OthelloModel::setPosTo(int index, OthelloBoard::Piece color)
{
    int row = index/BOARD_SIZE;
    int column = index%BOARD_SIZE;

    qDebug()<<row << " , " << column << " : " << color;

    auto posList = _game.findOppPos(_board.getBoard(), row, column, color);
    if(!posList.empty())
    {
        auto newBoard = _game.swapPieces(_board.getBoard(), row, column, color, posList);
        _board.setBoard(newBoard);
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

