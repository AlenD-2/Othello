
#pragma once

#include "OthelloBoard.h"

#include <QObject>
#include <QVector>


namespace Othello {

class OthelloModel : public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(QVector<int> board READ board /*WRITE setBoard*/ NOTIFY boardChanged);

public:
    explicit OthelloModel(QObject *parent = nullptr);

signals:
    void boardChanged();

public slots:
    QVector<int> board();

private:
    OthelloBoard _board;
};

} // namespace Othello

