
#pragma once

#include "OthelloBoard.h"
#include "OthelloLogic.h"
#include "Player.h"

#include <QObject>
#include <QVector>


namespace Othello {

constexpr int GAME_IS_NOT_OVER = -1;

enum Mode{HvH, HvC, CvC};

class OthelloModel : public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(QVector<int> board READ board /*WRITE setBoard*/ NOTIFY boardChanged);
    Q_PROPERTY(int whiteCount READ whiteCount /*WRITE setwhiteCount*/ NOTIFY whiteCountChanged);
    Q_PROPERTY(int blackCount READ blackCount /*WRITE setBlackCount*/ NOTIFY blackCountChanged);
    Q_PROPERTY(int winner READ winner /*WRITE setWinner*/ NOTIFY winnerChanged);
    Q_PROPERTY(int whosTurn READ whosTurn /*WRITE setWhosTurn*/ NOTIFY whosTurnChanged);

    //players property
    Q_PROPERTY(QStringList playersName READ playersName /*WRITE setPlayersName*/ NOTIFY playersNameChanged FINAL);

    Q_INVOKABLE void setPosTo(int index, Othello::OthelloBoard::Disk color);
    Q_INVOKABLE void setGameMode(int modeIndex);

public:
    explicit OthelloModel(QObject *parent = nullptr);
    ~OthelloModel();

signals:
    void boardChanged();
    void whiteCountChanged();
    void blackCountChanged();
    void winnerChanged();
    void whosTurnChanged();

    void playersNameChanged();
    void programFinished();
    void player1Move(QString);

public slots:
    QVector<int> board();
    int whiteCount();
    int blackCount();
    int winner();
    int whosTurn();

    QStringList playersName();
    void onPlayerReady();
    void readPlayer1Move(QString move);

private:
    OthelloBoard _board;
    OthelloLogic _game;
    OthelloBoard::Disk _winner;
    OthelloBoard::Disk _whosTurn;
    Mode _gameMode;

    Player _player1;
    QStringList _playersName{"",""};

    void exchangeTurn(OthelloBoard::Disk &disk);
};

} // namespace Othello

