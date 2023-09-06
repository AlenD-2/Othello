#pragma once

#include <QObject>
#include <QThread>
#include <QProcess>

#include <memory>

class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player();
    ~Player();

signals:
<<<<<<< HEAD
    void playerReady();
    void readyReadMove(QString move);
=======
    void playerReady(QString name);
    void readyRead(int index);
>>>>>>> parent of 3b4a7d8 (Add & Fix: add PlayerModel to QML & Fix kill process on application finished)

public slots:
    void readPlayerName();
    void killProcess();
    void writeBoard(QString board);

private:
    QThread _playerThread;
    std::unique_ptr<QProcess> _playerProcess;

    //functions
    void initProcess();
};

