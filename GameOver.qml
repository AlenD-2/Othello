import QtQuick

Rectangle{
    width: 340
    height: 150
    opacity: 0.85
    visible: winner !== noWinner
    border.width: 2

    property int winner: noWinner

    Text{
        id: gameOverTxt
        text: "Game Over!"
        font.pointSize: 32
        font.bold: true
        anchors{
            top: parent.top
            topMargin: 10
            horizontalCenter: parent.horizontalCenter
        }
    }
    Text{
        text: {
            if(winner === black)
                return "Black is the winner!";
            else if(winner === white)
                return "White is the winner!";
            else // winner === 0
                return "Black and White are equal!";
        }
        font.pointSize: 14
        anchors{
            top: gameOverTxt.bottom
            topMargin: 25
            horizontalCenter: gameOverTxt.horizontalCenter
        }
    }
}
