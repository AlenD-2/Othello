
#include "othellologic.h"

namespace Othello {

OthelloLogic::OthelloLogic()
{

}

/*
 * find the opponent pieces in the current player move to use in swap function
 * it will return a list of positions of opponent pieces
 * return an empty list if this is not a valid move */
PositionList_t OthelloLogic::findOppPos(const board_t &board, int row, int column, const OthelloBoard::Piece &color)
{
    PositionList_t result;

    for(int dRow=-1 ; dRow<=1 ; dRow++)
    {
        for(int dCol=-1 ; dCol<=1 ; dCol++)
        {
            // check at least one of Pieces around position is not the same color
            if(board.at(row+dRow).at(column+dCol) != color)
            {
                auto pos = checkDirection(board, row, column, dRow, dCol, color);
                if(!pos.isEmpty())
                {
                    result.push_back(pos);
                }
            }
        }
    }

    return result;
}

OthelloBoard::Position OthelloLogic::checkDirection(const board_t &board, int row, int column, int dRow, int dCol, const OthelloBoard::Piece &color)
{
    OthelloBoard::Position result;

    row += dRow;
    column += dCol;

    // check direction is not empty
    if(board.at(row).at(column) == OthelloBoard::Piece::empty || row < 8 || row >= 0 || column < 8 || column >= 0)
    {
        return result;
    }
    else if(board.at(row).at(column) == color)
    {
        result.row = row;
        result.column = column;
        return result;
    }
    else
    {
        return checkDirection(board, row, column, dRow, dCol, color);
    }
}

board_t OthelloLogic::swapPieces(board_t board, int row, int column, const OthelloBoard::Piece &color, const PositionList_t &positions)
{
    for(const auto pos : positions)
    {
        // find the directions (-1 or 1)
        int dRow = (row - pos.row) / abs(row - pos.row);
        int dCol = (column - pos.column) / abs(column - pos.column);

        while(row != pos.row || column != pos.column)
        {
            board.at(row).at(column) = color;
            row += dRow;
            column += dCol;
        }
    }

    return board;
}

} // namespace Othello

