#include "Timer.h"

namespace Othello {


Timer::Timer(QObject *parent)
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

void RemainTime::initTime(int seconds)
{
    _remainSeconds = seconds;
}

QString RemainTime::toQString() const
{
    return QString::number(_remainSeconds/60)+":"+QString::number(_remainSeconds%60);
}

int RemainTime::toSeconds() const
{
    return _remainSeconds;
}

RemainTime RemainTime::operator--()
{
    _remainSeconds--;
    return *this;
}

RemainTime RemainTime::operator--(int)
{
    _remainSeconds--;
    return *this;
}

} // namespace Othello
