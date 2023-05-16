
#include "othellologic.h"

namespace Othello {

OthelloLogic::OthelloLogic()
{

}

/*
 * find the opponent pieces in the current player move to use in swap function
 * it will return a list of positions of opponent pieces
 * return an empty list if this is not a valid move */
PositionList_t OthelloLogic::findOppPos(const OthelloBoard &board, OthelloBoard::Position currentPos, const OthelloBoard::Piece &color)
{
    PositionList_t result;

    if(board.getBoard().at(currentPos.row).at(currentPos.column) != OthelloBoard::Piece::empty)
    {
        return result;
    }

    for(int dRow=-1 ; dRow<=1 ; dRow++)
    {
        for(int dCol=-1 ; dCol<=1 ; dCol++)
        {
            if((currentPos.row+dRow) < BOARD_SIZE && (currentPos.row+dRow) >= 0 && (currentPos.column+dCol) < BOARD_SIZE && (currentPos.column+dCol) >= 0)
            {
                // check at least one of Pieces around position is not the same color
                if(board.getBoard().at(currentPos.row+dRow).at(currentPos.column+dCol) != color)
                {
                    auto pos = checkDirection(board, currentPos, dRow, dCol, color);
                    if(!pos.isEmpty())
                    {
                        result.push_back(pos);
                    }
                }
            }
        }
    }

    return result;
}

OthelloBoard::Position OthelloLogic::checkDirection(const OthelloBoard &board, OthelloBoard::Position currentPos, int dRow, int dCol, const OthelloBoard::Piece &color)
{
    OthelloBoard::Position result;

    currentPos.row += dRow;
    currentPos.column += dCol;

    // check row and column first to avoid overflow in next if statement
    if(currentPos.row >= BOARD_SIZE || currentPos.row < 0 || currentPos.column >= BOARD_SIZE || currentPos.column < 0)
    {
        return result; // empty result
    }
    else if(board.getBoard().at(currentPos.row).at(currentPos.column) == OthelloBoard::Piece::empty)
    {
        return result; // empty result
    }
    else if(board.getBoard().at(currentPos.row).at(currentPos.column) == color)
    {
        result.row = currentPos.row;
        result.column = currentPos.column;
        return result;
    }
    else
    {
        return checkDirection(board, currentPos, dRow, dCol, color);
    }
}

OthelloBoard OthelloLogic::swapPieces(OthelloBoard &board, OthelloBoard::Position currentPos, const OthelloBoard::Piece &color, const PositionList_t &positions)
{
    int tempRow = currentPos.row;
    int tempCol = currentPos.column;
    for(const auto pos : positions)
    {
        // find the directions (-1 or 0 or 1)
        int dRow = (pos.row - currentPos.row == 0)? 0 : (pos.row - currentPos.row) / abs(pos.row - currentPos.row);
        int dCol = (pos.column - currentPos.column == 0)? 0 : (pos.column - currentPos.column) / abs(pos.column - currentPos.column);

        while(currentPos.row != pos.row || currentPos.column != pos.column)
        {
            board.setPointTo(currentPos, color);//board.at(row).at(column) = color;
            currentPos.row += dRow;
            currentPos.column += dCol;
        }

        // restore main position for next swap
        currentPos.row = tempRow;
        currentPos.column = tempCol;
    }

    return board;
}

} // namespace Othello

