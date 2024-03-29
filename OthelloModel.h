
#pragma once

#include "OthelloBoard.h"
#include "OthelloLogic.h"
#include "Player.h"
#include "SwapList.h"
#include "Timer.h"

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

    //players property
    Q_PROPERTY(QStringList playersName READ playersName /*WRITE setPlayersName*/ NOTIFY playersNameChanged FINAL);
    Q_PROPERTY(QString player1Time READ player1Time /*WRITE setPlayer1Time*/ NOTIFY player1TimeChanged FINAL);
    Q_PROPERTY(QString player2Time READ player2Time /*WRITE setPlayer2Time*/ NOTIFY player2TimeChanged FINAL);
    Q_PROPERTY(int player1Chance READ player1Chance /*WRITE setPlayer1Chance*/ NOTIFY player1ChanceChanged FINAL);
    Q_PROPERTY(int player2Chance READ player2Chance /*WRITE setPlayer2Chance*/ NOTIFY player2ChanceChanged FINAL);

    Q_INVOKABLE void setPosTo(int index, Othello::OthelloBoard::Disk color);
    Q_INVOKABLE void nextTurn();
    Q_INVOKABLE void setGameMode(int modeIndex);
    Q_INVOKABLE void setAiDelay(int miliSec);
    Q_INVOKABLE void setParameters(int p1s1, int p1s2, int p1s3, int p2s1, int p2s2, int p2s3);

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

    void playersNameChanged();
    void programFinished(QThread* mainThread);
    void startPlayerMove(QString, OthelloBoard::Disk);
    void player1TimeChanged();
    void player2TimeChanged();
    void player1ChanceChanged();
    void player2ChanceChanged();

public slots:
    QVector<int> board();
    int whiteCount();
    int blackCount();
    int winner();
    int whosTurn();
    bool turnPassed();
    QVector<bool> swapList();
    int invalidPos();

    QStringList playersName();
    void onPlayerReady();
    void readPlayerMove(QString move);
    void onTimerChanged();
    QString player1Time();
    QString player2Time();
    int player1Chance();
    int player2Chance();

private:
    OthelloBoard _board;
    OthelloLogic _game;
    OthelloBoard::Disk _winner;
    OthelloBoard::Disk _whosTurn;
    Mode _gameMode;
    bool _turnPassed{false};
    SwapList _swapList;
    int _invalidPos{-1};
    bool _earlyGameOver{false};

    Player _player1;
    Player _player2;
    QStringList _playersName{"",""};
    Timer* _player1Timer;
    Timer* _player2Timer;
    int _player1Chance{3};
    int _player2Chance{3};

    void exchangeTurn(OthelloBoard::Disk &disk);
};

} // namespace Othello

