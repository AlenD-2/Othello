#include "Timer.h"

namespace Othello {


Timer::Timer(QObject *parent) : QObject{parent}
{
    _timer = new QTimer(parent);
    connect(_timer, &QTimer::timeout, this, &Timer::updateTime);
}

Timer::~Timer()
{
    _timer->stop();
}

void Timer::start()
{
    _timer->start(1000);
}

void Timer::stop()
{
    _remainTime.DecRemainTime(_timer->remainingTime());
    emit timeChanged();
    _timer->stop();
}

RemainTime Timer::remainTime() const
{
    return _remainTime;
}

void Timer::updateTime()
{
    _remainTime--;
    emit timeChanged();
}



//////// RemainTime Class /////////


RemainTime::RemainTime()
{

}

void RemainTime::initTime(int miliSec)
{
    _remainMiliSec = miliSec;
}

// convert to QString in clock format M:S
QString RemainTime::toQString() const
{
    int remainSeconds = toSeconds();
    return QString::number(remainSeconds/60)+":"+QString::number(remainSeconds%60);
}

int RemainTime::toSeconds() const
{
    if(_remainMiliSec < 0)
    {
        return 0;
    }
    return _remainMiliSec/1000;
}

// decrease the remain miliseconds of timer
void RemainTime::DecRemainTime(int miliSec)
{
    _remainMiliSec = _remainMiliSec-(1000-miliSec);
}

// decrease one second
RemainTime RemainTime::operator--()
{
    _remainMiliSec-=1000;
    return *this;
}

// decrease one second
RemainTime RemainTime::operator--(int)
{
    _remainMiliSec-=1000;
    return *this;
}

} // namespace Othello
