import QtQuick

Item {
    width: childrenRect.width
    height: childrenRect.height

    property int score: 0
    property bool reverse: false
    property int diskColor: black

    Row{
        layoutDirection: reverse? Qt.RightToLeft : Qt.LeftToRight
        spacing: 20

        Image {
            source: diskColor==black? "/img/image/black disk":"/img/image/white disk"
            width: 60
            height: width
            anchors.verticalCenter: parent.verticalCenter
        }

        Text{
            text: score
            font.pointSize: 45
            font.bold: true
            anchors.verticalCenter: parent.verticalCenter
            color: "white"
        }
    }
}
