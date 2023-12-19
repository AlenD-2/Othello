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
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 30
        spacing: 30
        RowLayout{
            Text{
                text: "Player1: "
                font.pixelSize: 18
            }
            TextField{
                id: p1set1
                background.width: 70
                maximumLength: 4
                placeholderText: "setting1"
                text: "0"
            }
            TextField{
                id: p1set2
                background.width: 70
                maximumLength: 4
                placeholderText: "setting2"
                text: "0"
            }
            TextField{
                id: p1set3
                background.width: 70
                maximumLength: 4
                placeholderText: "setting3"
                text: "0"
            }
        }
        RowLayout{
            Text{
                text: "Player2: "
                font.pixelSize: 18
            }
            TextField{
                id: p2set1
                background.width: 70
                maximumLength: 4
                placeholderText: "setting1"
                text: "0"
            }
            TextField{
                id: p2set2
                background.width: 70
                maximumLength: 4
                placeholderText: "setting2"
                text: "0"
            }
            TextField{
                id: p2set3
                background.width: 70
                maximumLength: 4
                placeholderText: "setting3"
                text: "0"
            }
        }
    }

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
                othelloModel.setGameMode(0);
                loader.source = "Loading.qml"
            }
        }
        Button{
            text: "Human Vs Code"
            font.pointSize: btnFontSize
            font.bold: true
            Layout.preferredHeight: btnHeight
            Layout.alignment: Qt.AlignHCenter
            onClicked: {
                othelloModel.setParameters(p1set1,p1set2,p1set3, p2set1,p2set2,p2set3)
                othelloModel.setGameMode(1);
                loader.source = "Loading.qml"
            }
        }
        Button{
            text: "Code Vs Code"
            font.pointSize: btnFontSize
            font.bold: true
            Layout.preferredHeight: btnHeight
            Layout.alignment: Qt.AlignHCenter
            onClicked: {
                othelloModel.setParameters(p1set1.text,p1set2.text,p1set3.text, p2set1.text,p2set2.text,p2set3.text)
                othelloModel.setGameMode(2);
                loader.source = "Loading.qml"
            }
        }
    }
}
