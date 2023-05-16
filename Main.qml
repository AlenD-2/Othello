import QtQuick
import QtQuick.Window
import QtQuick.Controls

import OthelloModel 1.0

Window {
    id: root
    width: 640
    height: 640
    visible: true
    title: qsTr("Othello")

    property int empty: 0
    property int white: 1
    property int black: 2

    property int playerCounter: 1

    OthelloModel{
        id: othelloModel
    }

    GridView{
        anchors.fill: parent
        cellWidth: root.width/8
        cellHeight: root.height/8
        interactive: false
        model: othelloModel.board
        delegate: Rectangle{
            width: root.width/8
            height: root.height/8
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
                    console.log("Clicked: "+index)
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
