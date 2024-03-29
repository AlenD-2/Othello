#pragma once

#include <QObject>
#include <QTimer>

namespace Othello {

class RemainTime
{
public:
    RemainTime();
    void initTime(int miliSec);
    QString toQString()const;
    int toSeconds()const;
    void DecRemainTime(int miliSec);
    RemainTime operator--();
    RemainTime operator--(int);

private:
    int _remainMiliSec{90'000};
};

class Timer : public QObject
{
    Q_OBJECT
public:
    explicit Timer(QObject *parent = nullptr);
    ~Timer();

    RemainTime remainTime()const;

public slots:
    void updateTime();
    void start();
    void stop();

signals:
    void timeChanged();

private:
    QTimer* _timer;
    RemainTime _remainTime;
};

} // namespace Othello
