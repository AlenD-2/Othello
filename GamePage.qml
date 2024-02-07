import QtQuick
import QtQuick.Layouts

Item {
    anchors.fill: parent

    Image {
        source: "/image/background"
        smooth: false
        anchors.fill: parent
    }

//    Board{
////        id: board
//        height: parent.height-190
//        width: height
////        Layout.leftMargin: 35
//        anchors.centerIn: parent
//        GameOver{
//            anchors.centerIn: board
//            winner: othelloModel.winner
//            Layout.alignment: Qt.AlignCenter
//        }

//        TurnPass{
//            anchors.centerIn: board
//            passFlag: othelloModel.turnPassed
//            Layout.alignment: Qt.AlignCenter
//        }
//    }


//    RowLayout{
//        visible: false
//        anchors.fill: parent
        Board{
            id: board
            implicitHeight: parent.height-210
            implicitWidth: height
//            Layout.leftMargin: 35
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
        ColumnLayout{
//            spacing: 50
//            Layout.fillHeight: true
//            PlayersNameItem{
//                Layout.fillWidth: true
//                Layout.leftMargin: 100
//                Layout.rightMargin: 100
//                Layout.topMargin: 100
//                nameTxtSize: 35
//                vsTxtSize: 60
//                diskSize: 70
//                scoreTxtSize: 25
//                player1Name: othelloModel.playersName[0]
//                player2Name: othelloModel.playersName[1]
//                whiteCount: othelloModel.whiteCount
//                blackCount: othelloModel.blackCount
//            }

//            PlayersTimerRect{
//                Layout.fillWidth: true
//                Layout.fillHeight: true
//                Layout.leftMargin: 80
//                Layout.rightMargin: 80
//                Layout.bottomMargin: 50
//                txtSize: 35
//                player1Name: othelloModel.playersName[0]
//                player2Name: othelloModel.playersName[1]
//                player1Time: othelloModel.player1Time
//                player2Time: othelloModel.player2Time
//            }
        }
//    }

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
