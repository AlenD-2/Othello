
#pragma once

#include "OthelloBoard.h"

#include <vector>

namespace Othello {

typedef std::vector<OthelloBoard::Position> PositionList_t;

class OthelloLogic
{
public:
    OthelloLogic();

    PositionList_t findOppPos(const OthelloBoard& board, OthelloBoard::Position currentPos, const OthelloBoard::Piece& color);
    OthelloBoard swapPieces(OthelloBoard &board, OthelloBoard::Position currentPos, const OthelloBoard::Piece& color, const PositionList_t& positions);

private:
    OthelloBoard::Position checkDirection(const OthelloBoard& board, OthelloBoard::Position currentPos, int dRow, int dCol, const OthelloBoard::Piece& color);
};

} // namespace Othello

