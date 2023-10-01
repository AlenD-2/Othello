#include "SwapList.h"

#include <algorithm>

namespace Othello {


SwapList::SwapList()
{
    resetList();
}

void SwapList::updateList(PositionList_t posList)
{
    for(const auto& pos : posList)
    {
        _list.at((pos.row*BOARD_SIZE)+(pos.column)) = true;
    }
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
    std::generate(_list.begin(), _list.end(), false);
}

}
