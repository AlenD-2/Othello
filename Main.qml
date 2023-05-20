import QtQuick
import QtQuick.Window
import QtQuick.Controls

import OthelloModel 1.0

Window {
    id: root
    width: 640
    height: 700
    visible: true
    title: qsTr("Othello")

    property int empty: 0
    property int white: 1
    property int black: 2
    property int noWinner: -1

    property int playerCounter: 1

    OthelloModel{
        id: othelloModel
    }


    Rectangle{
        id: countBoard
        width: root.width/4
        height: root.height/14
        anchors.horizontalCenter: parent.horizontalCenter
        color: "transparent"
        border.color: "black"
        Row{
            anchors.centerIn: parent
            spacing: 20
            Text{
                text: "White: "+othelloModel.whiteCount
                font.pointSize: 12
            }
            Text{
                text: "Black: "+othelloModel.blackCount
                font.pointSize: 12
            }
        }
    }

    Item{
        id: gridViewArea
        width: root.width
        height: width
        anchors.bottom: parent.bottom
        GridView{
            anchors.fill: parent
            cellWidth: gridViewArea.width/8
            cellHeight: gridViewArea.height/8
            interactive: false
            model: othelloModel.board
            delegate: Rectangle{
                width: gridViewArea.width/8
                height: gridViewArea.height/8
                color: "green"
                border.width: 2
                border.color: "black"
                Rectangle{
                    id: innerRect
                    width: parent.width-20
                    height: parent.height-20
                    anchors.centerIn: parent
                    color: (modelData === white)? "white" : "black"
                    radius: width/2
                    visible: modelData !== empty
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        if(parent.modelData === empty)
                            return
                        else
                        {
                            var color = (playerCounter%2 == 0)? 1 : 2
                            playerCounter++;
                            othelloModel.setPosTo(index,color);
                        }
                    }
                }
            }
        }
    }

    Rectangle{
        width: 340
        height: 150
        opacity: 0.85
        anchors.centerIn: parent
        visible: othelloModel.winner !== noWinner
        border.width: 2
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
                if(othelloModel.winner === black)
                    return "Black is the winner!";
                else if(othelloModel.winner === white)
                    return "White is the winner!";
                else
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
}
