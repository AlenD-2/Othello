#pragma once

#include "Player.h"

#include <QObject>

class PlayersModel : public QObject
{
    Q_OBJECT

public:
    Q_PROPERTY(QString player1Name READ player1Name /*WRITE setPlayer1Name*/ NOTIFY player1NameChanged FINAL);

public:
    explicit PlayersModel(QObject *parent = nullptr);
    ~PlayersModel();

signals:
    void player1NameChanged();
    void programFinished();

public slots:
    void onPlayer1Ready();

    QString player1Name();

private:
    Player _player1;

};

