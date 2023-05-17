
#pragma once

#include <array>

#include <QVector>

namespace Othello {

constexpr int BOARD_SIZE = 8;
typedef std::array<std::array<int, BOARD_SIZE>, BOARD_SIZE> board_t;


class OthelloBoard
{
public:
    enum Piece{empty, white, black};
    struct Position
    {
        int row = -1;
        int column = -1;
        bool isEmpty()
        {
            return (row == -1 || column == -1);
        }
    };
    struct PieceCount
    {
        int black=0;
        int white=0;
    };

public:
    OthelloBoard();
    void setPointTo(Position position, Piece piece);
    QVector<int> toQVector()const;
    const board_t& getBoard()const;
    void setBoard(const board_t& board);
    PieceCount getPieceCount()const;

private:
    board_t _board;
    board_t newBoard()const;
};

}
