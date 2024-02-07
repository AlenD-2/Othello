import QtQuick
import QtQuick.Layouts

Item {
    height: childrenRect.height

    property int whiteCount: 0
    property int blackCount: 0
    property string player1Name: "Human"
    property string player2Name: "Human"

    property int rowSpacing: 10
    property int nameTxtSize: 20
    property int vsTxtSize: 50
    property int diskSize: 50
    property int scoreTxtSize: 15

    ColumnLayout{
        width: parent.width
        RowLayout{
            spacing: rowSpacing
            Layout.alignment: Qt.AlignLeft
            Text {
                id: p1name
                text: player1Name
                font.pointSize: nameTxtSize
                color: "white"
            }
            Image{
                sourceSize: Qt.size(diskSize,diskSize)
                source: "/img/image/black disk"
                antialiasing: true
                Text{
                    text: blackCount
                    anchors.centerIn: parent
                    font.pointSize: scoreTxtSize
                    color: "white"
                }
            }
        }
        Text{
            text: "Vs"
            Layout.alignment: Qt.AlignCenter
            font.pointSize: vsTxtSize
            color: "white"
        }
        RowLayout{
            spacing: rowSpacing
            Layout.alignment: Qt.AlignRight
            Image{
                sourceSize: Qt.size(diskSize,diskSize)
                source: "/img/image/white disk"
                antialiasing: true
                Text{
                    text: whiteCount
                    anchors.centerIn: parent
                    font.pointSize: scoreTxtSize
                }
            }
            Text{
                text: player2Name
                font.pointSize: nameTxtSize
                color: "white"
            }
        }
    }
}
