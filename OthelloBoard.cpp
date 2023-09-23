
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
    for(const auto& row : _board)
    {
        for(const auto& disk : row)
        {
            result.append(disk);
        }
    }

    return result;
}

QString OthelloBoard::toQString() const
{
    QString result;
    for(const auto& row : _board)
    {
        for(const auto& disk : row)
        {
            result.append(QString::number(disk));
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

/*
 * calculate and return number of white and black */
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

/*
 * return empty if black and white are equal */
OthelloBoard::Disk OthelloBoard::getWinner() const
{
    auto dc = getDiskCount();
    if(dc.black > dc.white)
    {
        return Disk::black;
    }
    else if(dc.white > dc.black)
    {
        return Disk::white;
    }
    else
    {
        // black == white
        return Disk::empty;
    }
}

bool OthelloBoard::isFull() const
{
    for(const auto& row : _board)
    {
        for(const auto& disk : row)
        {
            if(disk == Disk::empty)
            {
                return false;
            }
        }
    }
    return true;
}

OthelloBoard::Disk OthelloBoard::at(const Position &pos) const
{
    return static_cast<Disk>(_board.at(pos.row).at(pos.column));
}

/*
 * return empty board with 4 disk in center */
board_t OthelloBoard::newBoard() const
{
    board_t base;
    for(auto& row : base)
    {
        std::fill(row.begin(), row.end(), Disk::empty);
    }
    base.at(3).at(3) = Disk::white;
    base.at(4).at(4) = Disk::white;
    base.at(3).at(4) = Disk::black;
    base.at(4).at(3) = Disk::black;

    return base;
}

}
