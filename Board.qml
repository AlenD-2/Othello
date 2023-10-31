import QtQuick

Rectangle{
    id: gridViewArea
    color: "#6d4848"

    GridView{
        width: parent.width-30
        height: parent.height-30
        anchors.centerIn: parent
        cellWidth: (width/8)-1 // -1 is cell border.width
        cellHeight: (height/8)-1
        interactive: false
        model: othelloModel.board
        delegate: Rectangle{
            width: gridViewArea.width/8
            height: gridViewArea.height/8
            color: (othelloModel.invalidPos === index)? "red" : "green"
            border.width: 1
            border.color: "black"
            Image{
                id: innerRect
                width: parent.width-20
                height: parent.height-20
                anchors.centerIn: parent
                source: (modelData === white)? "/img/image/white disk.png" : "/img/image/black disk.png"
                visible: modelData !== empty
                antialiasing: true
                property int whiteCount: othelloModel.whiteCount
                onWhiteCountChanged: {
                    if(othelloModel.swapList[index])
                    {
                        innerRect.visible = false
                        disk.frontCol = modelData
                        disk.doFlip = !disk.doFlip
                        disk.visible = true
                    }
                }
            }
            Disk{
                id: disk
                anchors.fill: parent
                doFlip: false
                visible: false
            }

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    othelloModel.setPosTo(index,othelloModel.whosTurn);
                }
            }
        }
    }
}
