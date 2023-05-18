
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
    Q_PROPERTY(int whiteCount READ whiteCount /*WRITE setwhiteCount*/ NOTIFY whiteCountChanged);
    Q_PROPERTY(int blackCount READ blackCount /*WRITE setBlackCount*/ NOTIFY blackCountChanged);

    Q_INVOKABLE void setPosTo(int index, Othello::OthelloBoard::Disk color);

public:
    explicit OthelloModel(QObject *parent = nullptr);

signals:
    void boardChanged();
    void whiteCountChanged();
    void blackCountChanged();

public slots:
    QVector<int> board();
    int whiteCount();
    int blackCount();

private:
    OthelloBoard _board;
    OthelloLogic _game;
};

} // namespace Othello

