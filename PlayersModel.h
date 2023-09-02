#pragma once

#include "Player.h"

#include <QObject>

class PlayersModel : public QObject
{
    Q_OBJECT

public:
    Q_PROPERTY(QString player1Name READ player1Name /*WRITE setPlayer1Name*/ NOTIFY player1NameChanged FINAL);
    Q_PROPERTY(int player1Move READ player1Move WRITE setPlayer1Move NOTIFY player1MoveChanged FINAL);

    Q_INVOKABLE void sendBoardToPlayer1(QVector<int> board);

public:
    explicit PlayersModel(QObject *parent = nullptr);
    ~PlayersModel();

signals:
    void programFinished();
    void player1ReadyToMove(QString board);

    void player1NameChanged();
    void player1MoveChanged();

public slots:
    void onPlayer1Ready();
    void onPlayer1NewMove(QString move);

    QString player1Name();
    int player1Move();

private:
    Player _player1;
    int _player1LastMove;

};

