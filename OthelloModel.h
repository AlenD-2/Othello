
#pragma once

#include "OthelloBoard.h"
#include "OthelloLogic.h"

#include <QObject>
#include <QVector>


namespace Othello {

class OthelloModel : public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(QVector<int> board READ board /*WRITE setBoard*/ NOTIFY boardChanged);

    Q_INVOKABLE void setPosTo(int index, Othello::OthelloBoard::Piece color);

public:
    explicit OthelloModel(QObject *parent = nullptr);

signals:
    void boardChanged();

public slots:
    QVector<int> board();

private:
    OthelloBoard _board;
    OthelloLogic _game;
};

} // namespace Othello

