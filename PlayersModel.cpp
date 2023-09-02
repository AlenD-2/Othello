#include "PlayersModel.h"
#include "qdebug.h"

void PlayersModel::sendBoardToPlayer1(QVector<int> board)
{
    QString strBoard{""};
    for(const auto& i : board)
    {
        strBoard += QString::number(i);
    }
    emit player1ReadyToMove(strBoard);
}

PlayersModel::PlayersModel(QObject *parent)
    : QObject{parent}
{
    connect(this, &PlayersModel::programFinished, &_player1, &Player::killProcess);
    connect(&_player1, &Player::playerReady, this, &PlayersModel::onPlayer1Ready);
    connect(this, &PlayersModel::player1ReadyToMove, &_player1, &Player::writeBoard);
    connect(&_player1, &Player::readyReadMove, this, &PlayersModel::onPlayer1NewMove);
}

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

void PlayersModel::onPlayer1NewMove(QString move)
{
    _player1LastMove = move.toInt();
    emit player1MoveChanged();
}

QString PlayersModel::player1Name()
{
    return _player1.getName();
}

int PlayersModel::player1Move()
{
    return _player1LastMove;
}
