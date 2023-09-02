#pragma once

#include <QObject>

class PlayersModel : public QObject
{
    Q_OBJECT
public:
    explicit PlayersModel(QObject *parent = nullptr);

signals:

};

