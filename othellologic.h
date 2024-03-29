
#pragma once

#include "OthelloBoard.h"

#include <vector>

namespace Othello {

typedef std::vector<OthelloBoard::Position> PositionList_t;

class OthelloLogic
{
public:
    OthelloLogic();

    PositionList_t findOppPos(const OthelloBoard& board, OthelloBoard::Position currentPos, const OthelloBoard::Disk& color);
    OthelloBoard swapDisks(OthelloBoard &board, OthelloBoard::Position sourcePos, const OthelloBoard::Disk& color, const PositionList_t& destinationList);
    bool isGameOver(const OthelloBoard& board);
    bool passTurn(const OthelloBoard& board, const OthelloBoard::Disk& color);

private:
    OthelloBoard::Position checkDirection(const OthelloBoard& board, OthelloBoard::Position currentPos, int dRow, int dCol, const OthelloBoard::Disk& color);
};

} // namespace Othello

