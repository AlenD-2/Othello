import QtQuick
import QtQuick.Layouts

Rectangle {
    color: "lightBlue"
    radius: 10

    property string player1Name: ""
    property string player2Name: ""
    property string player1Time: "0:00"
    property string player2Time: "0:00"

    property int txtSize: 20

    ColumnLayout{
        anchors.fill: parent
        anchors.margins: 20

        ColumnLayout{
            spacing: 20
            RowLayout{
                Text{
                    text: player1Name
                    Layout.fillWidth: true
                    font.pointSize: txtSize
                }
                Text{
                    text: player1Time
                    font.pointSize: txtSize
                }
            }
            Rectangle{
                height: 20
                Layout.fillWidth: true
                radius: 10
            }
        }
        ColumnLayout{
            spacing: 20
            RowLayout{
                Layout.fillWidth: true
                Text{
                    text: player2Name
                    Layout.fillWidth: true
                    font.pointSize: txtSize
                }
                Text{
                    text: player2Time
                    font.pointSize: txtSize
                }
            }
            Rectangle{
                height: 20
                Layout.fillWidth: true
                radius: 10
            }
        }
    }
}
