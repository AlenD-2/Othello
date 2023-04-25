
#pragma once

#include <array>

#include <QVector>

namespace Othello {

typedef std::array<std::array<int, 8>, 8> board_t;

enum Piece
{
    empty,
    white,
    black
};

class OthelloBoard
{
public:
    OthelloBoard();
    void setPointTo(int x, int y, Piece piece);
    QVector<int> toQVector()const;

private:
    board_t _board;
    board_t newBoard()const;
};

}
