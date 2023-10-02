#pragma once

#include "othellologic.h"

#include <array>


namespace Othello {


class SwapList
{
public:
    SwapList();
    void updateList(const board_t& board, const OthelloBoard::Position& userPos);
    QVector<bool> toQVector()const;

private:
    std::array<bool, 64> _list;
    OthelloBoard _oldBoard;

    void resetList();
};

}
