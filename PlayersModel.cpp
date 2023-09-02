#include "PlayersModel.h"
#include "qdebug.h"

PlayersModel::PlayersModel(QObject *parent)
    : QObject{parent}
{
    connect(this, &PlayersModel::programFinished, &_player1, &Player::killProcess);
    connect(&_player1, &Player::playerReady, this, &PlayersModel::onPlayer1Ready);
}

PlayersModel::~PlayersModel()
{
    emit programFinished();
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void PlayersModel::onPlayer1Ready()
{
    emit player1NameChanged();
}

QString PlayersModel::player1Name()
{
    return _player1.getName();
}
