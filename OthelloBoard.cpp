
#include "OthelloBoard.h"

namespace Othello {

OthelloBoard::OthelloBoard()
{
    _board = newBoard();
}

void OthelloBoard::setPointTo(Position position, Disk disk)
{
    _board.at(position.row).at(position.column) = disk;
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

OthelloBoard::DiskCount OthelloBoard::getDiskCount() const
{
    DiskCount result;

    for(const auto& row : _board)
    {
        for(const auto& disk : row)
        {
            if(disk != Disk::empty)
            {
                disk == Disk::white ? result.white++ : result.black++;
            }
        }
    }
    return result;
}

board_t OthelloBoard::newBoard() const
{
    board_t base;
    for(auto& i : base)
    {
        for(auto& j : i)
        {
            j = Disk::empty;
        }
    }
    base.at(3).at(3) = Disk::white;
    base.at(4).at(4) = Disk::white;
    base.at(3).at(4) = Disk::black;
    base.at(4).at(3) = Disk::black;

    return base;
}

}
