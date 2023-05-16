
#pragma once

#include "OthelloBoard.h"

#include <vector>

namespace Othello {

typedef std::vector<OthelloBoard::Position> PositionList_t;

class OthelloLogic
{
public:
    OthelloLogic();

    PositionList_t findOppPos(const board_t& board, int row, int column, const OthelloBoard::Piece& color);
    board_t swapPieces(board_t board, int row, int column, const OthelloBoard::Piece& color, const PositionList_t& positions);

private:
    OthelloBoard::Position checkDirection(const board_t& board, int row, int column, int dRow, int dCol, const OthelloBoard::Piece& color);
};

} // namespace Othello

