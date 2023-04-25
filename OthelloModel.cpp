
#include "OthelloModel.h"

namespace Othello {

OthelloModel::OthelloModel(QObject *parent)
    : QObject{parent}
{

}

QVector<int> OthelloModel::board()
{
    return _board.toQVector();
}

} // namespace Othello

