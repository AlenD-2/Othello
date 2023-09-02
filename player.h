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

    QString getName();

signals:
    void playerReady();
    void readyReadMove(QString move);

public slots:
    void readPlayerName();
    void killProcess();
    void writeBoard(QString board);

private:
    QThread _playerThread;
    std::unique_ptr<QProcess> _playerProcess;
    QString _name;

    //functions
    void initProcess();
};

