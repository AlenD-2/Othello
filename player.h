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

public slots:
    void readPlayerName();
    void killProcess();

private:

    QThread _playerThread;
    std::unique_ptr<QProcess> _playerProcess;
    QString _name;

    //functions
    void initProcess();
};

