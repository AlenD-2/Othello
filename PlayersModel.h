#pragma once

#include <QObject>

class PlayersModel : public QObject
{
    Q_OBJECT
<<<<<<< HEAD

public:
    Q_PROPERTY(QString player1Name READ player1Name /*WRITE setPlayer1Name*/ NOTIFY player1NameChanged FINAL);
<<<<<<< HEAD
<<<<<<< HEAD
    Q_PROPERTY(int player1Move READ player1Move /*WRITE setPlayer1Move*/ NOTIFY player1MoveChanged FINAL);
=======
    Q_PROPERTY(int player1Move READ player1Move WRITE setPlayer1Move NOTIFY player1MoveChanged FINAL);
>>>>>>> parent of 1abb9f4 (i hate programming)

    Q_INVOKABLE void sendBoardToPlayer1(QVector<int> board);
=======
>>>>>>> parent of fcc4a06 (Add: PlayersModel class connected to Player class for first test)

=======
>>>>>>> parent of 3b4a7d8 (Add & Fix: add PlayerModel to QML & Fix kill process on application finished)
public:
    explicit PlayersModel(QObject *parent = nullptr);

signals:
<<<<<<< HEAD
    void player1NameChanged();
    void programFinished();

public slots:
    void onPlayer1Ready();

    QString player1Name();

private:
    Player _player1;
<<<<<<< HEAD
<<<<<<< HEAD
    int _player1LastMove=0;
=======
>>>>>>> parent of fcc4a06 (Add: PlayersModel class connected to Player class for first test)
=======
    int _player1LastMove;
>>>>>>> parent of 1abb9f4 (i hate programming)
=======
>>>>>>> parent of 3b4a7d8 (Add & Fix: add PlayerModel to QML & Fix kill process on application finished)

};

