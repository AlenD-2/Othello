#pragma once

#include "othellologic.h"

#include <array>


namespace Othello {


class SwapList
{
public:
    SwapList();
    void updateList(PositionList_t posList);
    QVector<bool> toQVector()const;

private:
    std::array<bool, 64> _list;

    void resetList();
};

}
