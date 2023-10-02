#include "SwapList.h"
#include "qdebug.h"

#include <algorithm>

namespace Othello {


SwapList::SwapList()
{
    resetList();
}

void SwapList::updateList(const board_t &board, const OthelloBoard::Position &userPos)
{
    auto ignoreIndex = (userPos.row*BOARD_SIZE)+userPos.column;
    for(int i=0 ; i<BOARD_SIZE ; i++)
    {
        for(int j=0 ; j<BOARD_SIZE ; j++)
        {
            if(((i*BOARD_SIZE)+j) == ignoreIndex)
            {
                continue;
            }
            _list.at((i*BOARD_SIZE)+j) = _oldBoard.getBoard().at(i).at(j) != board.at(i).at(j);
        }
    }
    _oldBoard.setBoard(board);
}

QVector<bool> SwapList::toQVector() const
{
    QVector<bool> result;
    for(const auto& i : _list)
    {
        result.append(i);
    }
    return result;
}

void SwapList::resetList()
{
    std::fill(_list.begin(), _list.end(), false);
}

}
