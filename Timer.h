#pragma once

#include <QObject>
#include <QTimer>

namespace Othello {

class RemainTime
{
public:
    RemainTime();
    void initTime(int seconds);
    QString toQString()const;
    int toSeconds()const;
    RemainTime operator--();
    RemainTime operator--(int);

private:
    int _remainSeconds{1000};
};

class Timer : QObject
{
public:
    Timer();

    void start();
    void stop();
    RemainTime remainTime()const;

public slots:
    void updateTime();

signals:
    void timeChanged();

private:
    QTimer* _timer;
    RemainTime _remainTime;
};

} // namespace Othello
