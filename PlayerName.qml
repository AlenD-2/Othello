import QtQuick

Item {
    property string name: ""
    property bool activeBorder: false
    property int txtSize: 31

    Image {
        width: parent.width
        height: parent.height
        source: activeBorder? "/img/image/player border active.png" : "/img/image/player border deactive.png"
        Text{
            anchors.centerIn: parent
            text: name
            font.pointSize: txtSize
            color: "white"
        }
    }
}
