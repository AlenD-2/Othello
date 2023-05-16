
#include "OthelloBoard.h"

namespace Othello {

OthelloBoard::OthelloBoard()
{
    _board = newBoard();
}

void OthelloBoard::setPointTo(Position position, Piece piece)
{
    _board.at(position.row).at(position.column) = piece;
}

QVector<int> OthelloBoard::toQVector() const
{
    QVector<int> result;
    for(const auto& i : _board)
    {
        for(const auto& j : i)
        {
            result.append(j);
        }
    }

    return result;
}

const board_t &OthelloBoard::getBoard() const
{
    return _board;
}

void OthelloBoard::setBoard(const board_t &board)
{
    _board = board;
}

board_t OthelloBoard::newBoard() const
{
    board_t base;
    for(auto& i : base)
    {
        for(auto& j : i)
        {
            j = Piece::empty;
        }
    }
    base.at(3).at(3) = Piece::white;
    base.at(4).at(4) = Piece::white;
    base.at(3).at(4) = Piece::black;
    base.at(4).at(3) = Piece::black;

    return base;
}

}
