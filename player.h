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
    void playerReady(QString name);
    void readyRead(int index);

public slots:
    void readPlayerName();
    void killProcess();

private:

    QThread _playerThread;
    std::unique_ptr<QProcess> _playerProcess;

    //functions
    void initProcess();
};

