import QtQuick
import QtQuick.Layouts

Item {
    anchors.fill: parent

    Image {
        source: "/image/background"
        smooth: false
        anchors.fill: parent
    }

    Board{
        id: board
        implicitHeight: parent.height-210
        implicitWidth: height
        anchors.centerIn: parent

        Item{
            width: 150
            height: 80
            anchors{
                left: board.right
                bottom: board.top
                bottomMargin: 15
                leftMargin: 90
            }
            Text{
                text: othelloModel.player1Time
                font.pointSize: 45
                font.bold: true
                color: "white"
                anchors.centerIn: parent
            }
        }
        Item{
            width: 150
            height: 80
            anchors{
                right: board.left
                bottom: board.top
                bottomMargin: 15
                rightMargin: 90
            }
            Text{
                text: othelloModel.player2Time
                font.pointSize: 45
                font.bold: true
                color: "white"
                anchors.centerIn: parent
            }
        }

        PlayerHearts{
            id: p1heart
            heartsSize: 50
            remainHearts: othelloModel.player1Chance
            anchors{
                verticalCenter: board.verticalCenter
                left: board.right
                leftMargin: 2
            }
        }
        PlayerHearts{
            id: p2heart
            heartsSize: 50
            remainHearts: othelloModel.player2Chance
            anchors{
                verticalCenter: board.verticalCenter
                right: board.left
                rightMargin: 2
            }
        }

        PlayerScore{
            score: othelloModel.blackCount
            diskColor: black
            anchors{
                right: board.right
                rightMargin: 20
                bottom: board.top
                bottomMargin: 15
            }
        }
        PlayerScore{
            score: othelloModel.whiteCount
            diskColor: white
            reverse: true
            anchors{
                left: board.left
                leftMargin: 20
                bottom: board.top
                bottomMargin: 15
            }
        }

        GameOver{
            anchors.centerIn: board
            winner: othelloModel.winner
            Layout.alignment: Qt.AlignCenter
        }

        TurnPass{
            anchors.centerIn: board
            passFlag: othelloModel.turnPassed
            Layout.alignment: Qt.AlignCenter
        }
    }

    PlayerName{
        name: othelloModel.playersName[0]
        txtSize: 28
        activeBorder: othelloModel.whosTurn === black
        height: 130
        anchors{
            right: parent.right
            verticalCenter: parent.verticalCenter
            left: board.right
            leftMargin: 70
        }
    }
    PlayerName{
        name: othelloModel.playersName[1]
        txtSize: 28
        activeBorder: othelloModel.whosTurn === white
        height: 130
        anchors{
            left: parent.left
            verticalCenter: parent.verticalCenter
            right: board.left
            rightMargin: 70
        }
    }
}
