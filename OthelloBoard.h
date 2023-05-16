
#pragma once

#include <array>

#include <QVector>

namespace Othello {

const uint16_t BOARD_SIZE = 8;
typedef std::array<std::array<int, BOARD_SIZE>, BOARD_SIZE> board_t;


class OthelloBoard
{
public:
    enum Piece
    {
        empty,
        white,
        black
    };
    struct Position
    {
        int row = -1;
        int column = -1;
        bool isEmpty()
        {
            return (row == -1 || column == -1);
        }
    };

public:
    OthelloBoard();
    void setPointTo(int x, int y, Piece piece);
    QVector<int> toQVector()const;

private:
    board_t _board;
    board_t newBoard()const;
};

}
