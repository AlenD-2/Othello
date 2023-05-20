
#pragma once

#include "OthelloBoard.h"
#include "OthelloLogic.h"

#include <QObject>
#include <QVector>


namespace Othello {

constexpr int GAME_IS_NOT_OVER = -1;

class OthelloModel : public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(QVector<int> board READ board /*WRITE setBoard*/ NOTIFY boardChanged);
    Q_PROPERTY(int whiteCount READ whiteCount /*WRITE setwhiteCount*/ NOTIFY whiteCountChanged);
    Q_PROPERTY(int blackCount READ blackCount /*WRITE setBlackCount*/ NOTIFY blackCountChanged);
    Q_PROPERTY(int winner READ winner /*WRITE setWinner*/ NOTIFY winnerChanged);
    Q_PROPERTY(int whosTurn READ whosTurn /*WRITE setWhosTurn*/ NOTIFY whosTurnChanged);

    Q_INVOKABLE void setPosTo(int index, Othello::OthelloBoard::Disk color);

public:
    explicit OthelloModel(QObject *parent = nullptr);

signals:
    void boardChanged();
    void whiteCountChanged();
    void blackCountChanged();
    void winnerChanged();
    void whosTurnChanged();

public slots:
    QVector<int> board();
    int whiteCount();
    int blackCount();
    int winner();
    int whosTurn();

private:
    OthelloBoard _board;
    OthelloLogic _game;
    OthelloBoard::Disk _winner;
    OthelloBoard::Disk _whosTurn;

    void exchangeTurn(OthelloBoard::Disk &disk);
};

} // namespace Othello

