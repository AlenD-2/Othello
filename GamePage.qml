import QtQuick
import QtQuick.Layouts

Item {
    anchors.fill: parent

    RowLayout{
        anchors.fill: parent
        Board{
            id: board
            implicitHeight: parent.height-70
            implicitWidth: height
            Layout.leftMargin: 35
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
        ColumnLayout{
            spacing: 50
            Layout.fillHeight: true
            PlayersNameItem{
                Layout.fillWidth: true
                Layout.leftMargin: 100
                Layout.rightMargin: 100
                Layout.topMargin: 100
                nameTxtSize: 35
                vsTxtSize: 60
                diskSize: 70
                scoreTxtSize: 25
                player1Name: othelloModel.playersName[0]
                player2Name: othelloModel.playersName[1]
                whiteCount: othelloModel.whiteCount
                blackCount: othelloModel.blackCount
            }

            PlayersTimerRect{
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.leftMargin: 80
                Layout.rightMargin: 80
                Layout.bottomMargin: 50
                txtSize: 35
                player1Name: othelloModel.playersName[0]
                player2Name: othelloModel.playersName[1]
                player1Time: othelloModel.player1Time
                player2Time: othelloModel.player2Time
            }
        }
    }
}
