#include "PlayersModel.h"

PlayersModel::PlayersModel(QObject *parent)
    : QObject{parent}
{

<<<<<<< HEAD
PlayersModel::~PlayersModel()
{
    emit programFinished();
    // need an interrupt to allow the process enough time to be terminated
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void PlayersModel::onPlayer1Ready()
{
    emit player1NameChanged();
}

QString PlayersModel::player1Name()
{
    return _player1.getName();
=======
>>>>>>> parent of 3b4a7d8 (Add & Fix: add PlayerModel to QML & Fix kill process on application finished)
}
