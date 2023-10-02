#pragma once

#include "othellologic.h"

#include <array>


namespace Othello {


class SwapList
{
public:
    SwapList();
    void updateList(board_t board);
    QVector<bool> toQVector()const;

private:
    std::array<bool, 64> _list;
    OthelloBoard _oldBoard;

    void resetList();
};

}
