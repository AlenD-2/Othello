
#pragma once

#include "OthelloBoard.h"
#include "OthelloLogic.h"
#include "Player.h"
#include "SwapList.h"

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
    Q_PROPERTY(bool turnPassed READ turnPassed /*WRITE setTurnPassed*/ NOTIFY turnPassedChanged FINAL);
    Q_PROPERTY(QVector<bool> swapList READ swapList /*WRITE setSwapList*/ NOTIFY swapListChanged FINAL);
    Q_PROPERTY(int invalidPos READ invalidPos /*WRITE setInvalidPos*/ NOTIFY invalidPosChanged FINAL);
    Q_PROPERTY(bool player1TimerPaused READ player1TimerPaused /*WRITE setPlayer1TimerPaused*/ NOTIFY player1TimerPausedChanged FINAL);
    Q_PROPERTY(bool player2TimerPaused READ player2TimerPaused /*WRITE setPlayer2TimerPaused*/ NOTIFY player2TimerPausedChanged FINAL);

    //players property
    Q_PROPERTY(QStringList playersName READ playersName /*WRITE setPlayersName*/ NOTIFY playersNameChanged FINAL);

    Q_INVOKABLE void setPosTo(int index, Othello::OthelloBoard::Disk color);
    Q_INVOKABLE void nextTurn();
    Q_INVOKABLE void setGameMode(int modeIndex);
    Q_INVOKABLE void setAiDelay(int miliSec);

public:
    explicit OthelloModel(QObject *parent = nullptr);
    ~OthelloModel();

signals:
    void boardChanged();
    void whiteCountChanged();
    void blackCountChanged();
    void winnerChanged();
    void whosTurnChanged();
    void turnPassedChanged();
    void swapListChanged();
    void invalidPosChanged();
    void player1TimerPausedChanged();
    void player2TimerPausedChanged();

    void playersNameChanged();
    void programFinished();
    void startPlayerMove(QString, OthelloBoard::Disk);

public slots:
    QVector<int> board();
    int whiteCount();
    int blackCount();
    int winner();
    int whosTurn();
    bool turnPassed();
    QVector<bool> swapList();
    int invalidPos();
    bool player1TimerPaused();
    bool player2TimerPaused();

    QStringList playersName();
    void onPlayerReady();
    void readPlayerMove(QString move);
    void onTimerResumed();
    void onTimerPaused();

private:
    OthelloBoard _board;
    OthelloLogic _game;
    OthelloBoard::Disk _winner;
    OthelloBoard::Disk _whosTurn;
    Mode _gameMode;
    bool _turnPassed{false};
    SwapList _swapList;
    int _invalidPos{-1};
    bool _player1TimerPaused{true};
    bool _player2TimerPaused{true};

    Player _player1;
    Player _player2;
    QStringList _playersName{"",""};

    void exchangeTurn(OthelloBoard::Disk &disk);
};

} // namespace Othello

