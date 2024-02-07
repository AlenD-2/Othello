import QtQuick

Rectangle{
    id: gridViewArea
    color: "transparent"//"#282828"
//    border.color: "#52983d"

//    Image {
//        source: "/image/board border.png"
//        anchors.fill: parent
//    }

    GridView{
        id: gridView
        anchors.centerIn: parent
        width: parent.width//-35
        height: parent.height//-35
        cellWidth: (width/8)//-1 // -1 is cell border.width
        cellHeight: (height/8)//-1
        interactive: false
        model: othelloModel.board
        delegate: Rectangle{
            width: gridView.width/8
            height: gridView.height/8
            color: (othelloModel.invalidPos === index)? "red" : "green"
            border.width: 1
            border.color: "#1c1b1a"
//            Image{
//                anchors.fill: parent
//                source: "/image/cell.png"
//            }

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
