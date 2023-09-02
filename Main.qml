import QtQuick
import QtQuick.Window
import QtQuick.Controls

import OthelloModel 1.0
import PlayerModel 1.0

Window {
    id: root
    width: 640
    height: 700
    visible: true
    title: qsTr("Othello")

    OthelloModel{
        id: othelloModel
    }

    PlayerModel{
        id: playerModel
    }

    Loader{
        id: loader
        anchors.fill: parent
        source: "MainMenu.qml"
    }
}
