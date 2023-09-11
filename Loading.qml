import QtQuick
import QtQuick.Controls

Rectangle {
    anchors.fill: parent
    color: "green"

    Row{
        anchors.centerIn: parent
        spacing: 100

        Item{
            width: childrenRect.width
            height: childrenRect.height
            Text{
                id: txt1
                text: ""
                visible: text !== ""
                anchors.centerIn: parent
            }

            BusyIndicator{
                id: busy1
                width: 100
                height: width
                visible: txt1.text === ""
            }
        }

        Item{
            width: childrenRect.width
            height: childrenRect.height
            Text{
                id: txt2
                text: ""
                visible: text !== ""
                anchors.centerIn: parent
                font.pointSize: 32
            }
            BusyIndicator{
                id: busy2
                width: 100
                height: width
                visible: txt2.text === ""
            }
        }
    }
}
