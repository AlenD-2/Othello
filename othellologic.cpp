
#include "othellologic.h"

namespace Othello {

OthelloLogic::OthelloLogic()
{

}

/*
 * find the opponent Disks in the current player move to use in swap function
 * it will return a list of positions of opponent Disks
 * return an empty list if this is not a valid move */
PositionList_t OthelloLogic::findOppPos(const OthelloBoard &board, OthelloBoard::Position currentPos, const OthelloBoard::Disk &color)
{
    PositionList_t result;

    if(board.at(currentPos) != OthelloBoard::Disk::empty)
    {
        return result;
    }

    for(int dRow=-1 ; dRow<=1 ; dRow++)
    {
        for(int dCol=-1 ; dCol<=1 ; dCol++)
        {
            if((currentPos.row+dRow) < BOARD_SIZE && (currentPos.row+dRow) >= 0 && (currentPos.column+dCol) < BOARD_SIZE && (currentPos.column+dCol) >= 0)
            {
                // check at least one of Disks around position is not the same color
                if(board.at(currentPos) != color)
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


/*
 * search given Direction of Position to check is it possible
 * to swap opponent disks or not. if yes then return position
 * of the same color disk(last disk in swap direction)
 * return empty if not able swap */
OthelloBoard::Position OthelloLogic::checkDirection(const OthelloBoard &board, OthelloBoard::Position currentPos, int dRow, int dCol, const OthelloBoard::Disk &color)
{
    OthelloBoard::Position result;

    currentPos.row += dRow;
    currentPos.column += dCol;

    // check row and column first to avoid overflow in next if statement
    if(currentPos.row >= BOARD_SIZE || currentPos.row < 0 || currentPos.column >= BOARD_SIZE || currentPos.column < 0)
    {
        return result; // empty result
    }
    else if(board.at(currentPos) == OthelloBoard::Disk::empty)
    {
        return result; // empty result
    }
    else if(board.at(currentPos) == color)
    {
        result.row = currentPos.row;
        result.column = currentPos.column;
        return result;
    }
    else
    {
        // check the next disk in current direction
        return checkDirection(board, currentPos, dRow, dCol, color);
    }
}

bool OthelloLogic::isGameOver(const OthelloBoard &board)
{
    if(board.isFull() || board.getDiskCount().black == 0 || board.getDiskCount().white == 0)
    {
        return true;
    }
    return false;
}


/*
 * check all empty positions of the board to check if
 * there is at least one position that player can play
 * or not, if not then it means Pass the turn
 */
bool OthelloLogic::passTurn(const OthelloBoard &board, const OthelloBoard::Disk &color)
{
    for(int i=0 ; i<BOARD_SIZE ; i++)
    {
        for(int j=0 ; j<BOARD_SIZE ; j++)
        {
            if(board.at(OthelloBoard::Position{i,j}) == OthelloBoard::Disk::empty)
            {
                auto posList = findOppPos(board, OthelloBoard::Position{i,j}, color);
                if(!posList.empty())
                {
                    return false;
                }
            }
        }
    }

    return true;
}

OthelloBoard OthelloLogic::swapDisks(OthelloBoard &board, OthelloBoard::Position sourcePos, const OthelloBoard::Disk &color, const PositionList_t &destinationList)
{
    auto tempPos = sourcePos;
    for(const auto desPos : destinationList)
    {
        // find the directions (-1 or 0 or 1)
        int dRow = (desPos.row - sourcePos.row == 0)? 0 : (desPos.row - sourcePos.row) / abs(desPos.row - sourcePos.row);
        int dCol = (desPos.column - sourcePos.column == 0)? 0 : (desPos.column - sourcePos.column) / abs(desPos.column - sourcePos.column);

        while(sourcePos.row != desPos.row || sourcePos.column != desPos.column)
        {
            board.setPointTo(sourcePos, color);
            sourcePos.row += dRow;
            sourcePos.column += dCol;
        }

        // restore main position for next swap
        sourcePos = tempPos;
    }
    return board;
}

} // namespace Othello

