import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Rectangle {
    id: mainMenu
    anchors.fill: parent
    color: "green"

    property int btnWidth: 120
    property int btnHeight: 40
    property int btnFontSize: 12

    ColumnLayout{
        anchors.centerIn: parent
        width: childrenRect.width
        spacing: 15
        Button{
            text: "Human Vs Human"
            font.pointSize: btnFontSize
            font.bold: true
            Layout.preferredHeight: btnHeight
            Layout.alignment: Qt.AlignHCenter
            onClicked:{
                loader.source = "Board.qml"
            }
        }
        Button{
            text: "Human Vs Code"
            font.pointSize: btnFontSize
            font.bold: true
            Layout.preferredHeight: btnHeight
            Layout.alignment: Qt.AlignHCenter
            onClicked: {
                loader.source = "Loading.qml"
            }
        }
        Button{
            text: "Code Vs Code"
            font.pointSize: btnFontSize
            font.bold: true
            Layout.preferredHeight: btnHeight
            Layout.alignment: Qt.AlignHCenter
            enabled: false
        }
    }
}
